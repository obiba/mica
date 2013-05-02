<?php

function _mica_studies_dce_link($dce) {
  // create a reference in population when a dce is create
  $dce_wrapper = entity_metadata_wrapper('node', $dce);
  $population = $dce_wrapper->field_dce_population->value();
  if ($population != null) {
    $population_wrapper = entity_metadata_wrapper('node', $population);
    $population_dce = $population_wrapper->field_pop_dce->value();
    $nb_dce = count($population_dce);
    $population->field_pop_dce[LANGUAGE_NONE][$nb_dce]['nid'][$dce->nid] = $dce->nid;
    node_save($population);
  }
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

function _mica_studies_dce_view(&$node, $view_mode, $langcode) {
  _mica_studies_dce_view_data_sources($node);
  _mica_studies_dce_view_samples($node);

// Breadcrumbs part
  // recuperation of the population of the dce
  $wrapper = entity_metadata_wrapper('node', $node);
  $pop_id = $wrapper->field_dce_population->nid->value();

  //recuperation of the study of the population
  $wrapper = entity_metadata_wrapper('node', node_load($pop_id));
  $study_id = $wrapper->field_pop_study->nid->value();
  $pop_link = l($wrapper->title->value(), 'node/' . $wrapper->nid->value());

  // generate specific breadcrumbs for dce pages
  $breadcrumbs = array();
  $breadcrumbs[] = l('Home', '');
  $breadcrumb = _mica_studies_menu_generate_breadcrumbs('node/' . $study_id);
  for ($i = 0; $i < count($breadcrumb); $i++) {
    $breadcrumbs[] = l($breadcrumb[$i]['link_title'], $breadcrumb[$i]['link_path']);
  }
  $breadcrumbs[] = $pop_link;

  drupal_set_breadcrumb($breadcrumbs);

}

function _mica_studies_dce_view_data_sources(&$node) {

  $wrapper = entity_metadata_wrapper('node', $node);

  if (!isset($node->content['field_dce_data_sources'])) {
    // create empty field_dce_data_sources if it has no values
    mica_core_create_empty_field($node, 'field_dce_data_sources');
  }

  $data_sources = $wrapper->field_dce_data_sources->value();

  $db_index = array_search('administratives_databases', $data_sources);
  if ($db_index !== FALSE) {
    $field_dce_data_sources_admin_db = $wrapper->field_dce_data_sources_admin_db->value();
    if (!empty($field_dce_data_sources_admin_db)) {
      $nb_items = count($field_dce_data_sources_admin_db);
      $content = array();
      for ($i = 0; $i < $nb_items; $i++) {
        $content[] = $node->content['field_dce_data_sources_admin_db'][$i]['#markup'];
      }
      $node->content['field_dce_data_sources'][$db_index]['#markup'] .= ': ' . implode(', ', $content);
      $node->content['field_dce_data_sources_admin_db']['#access'] = FALSE;
    }
  }

  $other_index = array_search('others', $data_sources);
  if ($other_index !== FALSE) {
    $field_dce_data_sources_sp = $wrapper->field_dce_data_sources_sp->value();
    if (!empty($field_dce_data_sources_sp)) {
      $node->content['field_dce_data_sources'][$other_index]['#markup'] = $node->content['field_dce_data_sources_sp'][0]['#markup'];
      $node->content['field_dce_data_sources_sp']['#access'] = FALSE;
    }
  }

  if (strlen($node->content['field_dce_data_sources'][0]['#markup']) === 0) {
    $node->content['field_dce_data_sources']['#access'] = FALSE;
  }

}

function _mica_studies_dce_view_samples(&$node) {

  $wrapper = entity_metadata_wrapper('node', $node);

  if (!isset($node->content['field_dce_bio_samples_management'])) {
    // create empty field_dce_data_sources if it has no values
    mica_core_create_empty_field($node, 'field_dce_bio_samples_management');
  }

  $samples = $wrapper->field_dce_bio_samples_management->value();

  $tissues_index = array_search('tissues', $samples);
  if ($tissues_index !== FALSE) {
    $field_dce_tissues_sp = $wrapper->field_dce_tissues_sp->value();
    if (!empty($field_dce_tissues_sp)) {
      $node->content['field_dce_data_sources'][$tissues_index]['#markup'] .= ': ' . $node->content['field_dce_tissues_sp'][0]['#markup'];
      ;
      $node->content['field_dce_tissues_sp']['#access'] = FALSE;
    }
  }

  $other_index = array_search('others', $samples);
  if ($other_index !== FALSE) {
    $field_dce_samples_man_other_sp = $wrapper->field_dce_samples_man_other_sp->value();
    if (!empty($field_dce_samples_man_other_sp)) {
      $node->content['field_dce_bio_samples_management'][$other_index]['#markup'] = $node->content['field_dce_samples_man_other_sp'][0]['#markup'];
      $node->content['field_dce_samples_man_other_sp']['#access'] = FALSE;
    }
  }

  if (strlen($node->content['field_dce_bio_samples_management'][0]['#markup']) === 0) {
    $node->content['field_dce_bio_samples_management']['#access'] = FALSE;
  }

}
