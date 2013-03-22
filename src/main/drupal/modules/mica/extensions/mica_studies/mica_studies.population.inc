<?php

function _mica_studies_population_link($population) {

  $population_wrapper = entity_metadata_wrapper('node', $population);
  $study = $population_wrapper->field_pop_study->value();
  $study_wrapper = entity_metadata_wrapper('node', $study);
  $study_populations = $study_wrapper->field_study_populations->value();
  $nb_populations = count($study_populations);

  $study->field_study_populations[LANGUAGE_NONE][$nb_populations]['nid'][$population->nid] = $population->nid;
  node_save($study);

}

function _mica_studies_population_delete($population) {

  $population_wrapper = entity_metadata_wrapper('node', $population);
  $population_id = $population_wrapper->nid->value();

  // supress link in studies
  $query = new EntityFieldQuery;
  $entities = $query->entityCondition('entity_type', 'node')
    ->entityCondition('bundle', 'study')
    ->execute();
  if (!empty($entities)) {
    $nodes = node_load_multiple(array_keys($entities['node']));
    foreach ($nodes as $node) {
      $study_populations = $node->field_study_populations;
      dpm($node->field_study_populations);
      if (isset ($study_populations[LANGUAGE_NONE])) {
        $nb_populations = count($study_populations[LANGUAGE_NONE]);
        $value = array();
        $count = 0;
        for ($i = 0; $i < $nb_populations; $i++) {
          if ($study_populations[LANGUAGE_NONE][$i]['nid'] != $population_id) {

            $value[$count] = $study_populations[LANGUAGE_NONE][$i];
            $count++;
          }
        }
        if ($count != 0) {
          $node->field_study_populations[LANGUAGE_NONE] = $value;
          node_save($node);
        }
      }
    }
  }

  //suppress all data collection event associate to the population
  $query = new EntityFieldQuery;
  $entities = $query->entityCondition('entity_type', 'node')
    ->entityCondition('bundle', 'data_collection_event')
    ->execute();
  if (!empty($entities)) {
    $nodes = node_load_multiple(array_keys($entities['node']));
    foreach ($nodes as $node) {
      $dce_wrapper = entity_metadata_wrapper('node', $node);
      $dce_pop = $dce_wrapper->field_dce_population->value();
      $dce_pop_id = $dce_pop->nid;
      if ($population_id == $dce_pop_id) {
        node_delete($dce_wrapper->nid->value());
      }
    }
  }

}