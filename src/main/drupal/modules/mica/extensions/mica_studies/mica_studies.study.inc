<?php
function _mica_studies_study_delete($study) {
  // suppress all population associate to a study when the study is deleted
  $study_wrapper = entity_metadata_wrapper('node', $study);
  $study_id = $study_wrapper->nid->value();

  $query = new EntityFieldQuery;
  $entities = $query->entityCondition('entity_type', 'node')
    ->entityCondition('bundle', 'population')
    ->execute();
  if (!empty($entities)) {
    foreach (array_keys($entities['node']) as $nid) {
      $pop_wrapper = entity_metadata_wrapper('node', $nid);
      $pop_study = $pop_wrapper->field_pop_study->value();
      if (isset($pop_study)) {
        if ($study_id == $pop_study->nid) {
          $pop_wrapper . delete();
        }
      }
    }
  }
}