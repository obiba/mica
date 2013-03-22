<?php
function _mica_studies_study_delete($study) {

  $study_wrapper = entity_metadata_wrapper('node', $study);
  $study_id = $study_wrapper->nid->value();

  $query = new EntityFieldQuery;
  $entities = $query->entityCondition('entity_type', 'node')
    ->entityCondition('bundle', 'population')
    ->execute();
  if (!empty($entities)) {
    $nodes = node_load_multiple(array_keys($entities['node']));
    foreach ($nodes as $node) {
      $pop_wrapper = entity_metadata_wrapper('node', $node);
      $pop_study = $pop_wrapper->field_pop_study->value();
      dpm($pop_study, '$dce_pop');
      $pop_study_id = $pop_study->nid;
      dpm($pop_study_id);
      if ($study_id == $pop_study_id) {
        node_delete($pop_wrapper->nid->value());
      }
    }
  }
}