<?php

function _mica_studies_dce_link($dce) {

  $dce_wrapper = entity_metadata_wrapper('node', $dce);
  $population = $dce_wrapper->field_dce_population->value();

  $population_wrapper = entity_metadata_wrapper('node', $population);
  $population_dce = $population_wrapper->field_pop_dce->value();
  $nb_dce = count($population_dce);

  $population->field_pop_dce[LANGUAGE_NONE][$nb_dce]['nid'][$dce->nid] = $dce->nid;

  node_save($population);
}

function _mica_studies_dce_delete($dce) {
  $population_wrapper = entity_metadata_wrapper('node', $dce);
  $population_id = $population_wrapper->nid->value();

  // supress dce link in populations
  $query = new EntityFieldQuery;
  $entities = $query->entityCondition('entity_type', 'node')
    ->entityCondition('bundle', 'population')
    ->execute();
  if (!empty($entities)) {
    $nodes = node_load_multiple(array_keys($entities['node']));
    foreach ($nodes as $node) {
      $population_dce = $node->field_pop_dce;
      if (isset ($population_dce[LANGUAGE_NONE])) {
        $nb_dce = count($population_dce[LANGUAGE_NONE]);
        $value = array();
        $count = 0;
        for ($i = 0; $i < $nb_dce; $i++) {
          if ($population_dce[LANGUAGE_NONE][$i]['nid'] != $population_id) {
            $value[$count] = $population_dce[LANGUAGE_NONE][$i];
            $count++;
          }
        }
        $node->field_pop_dce[LANGUAGE_NONE] = $value;
        node_save($node);
      }
    }
  }
}