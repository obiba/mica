<?php

function _mica_studies_population_link($population) {
  // create a reference in study when a population is create for this study
  $population_wrapper = entity_metadata_wrapper('node', $population);
  $study = $population_wrapper->field_pop_study->value();
  //$study = node_load($study->nid);
  if (!empty($study)) {
    $study_wrapper = entity_metadata_wrapper('node', $study);
    $study_populations = $study_wrapper->field_study_populations->value();
    $nb_populations = count($study_populations);
    $study_wrapper->value()->field_study_populations[LANGUAGE_NONE][$nb_populations]['nid'][$population->nid] = $population->nid;
    $study_wrapper->save();
  }
}

function _mica_studies_population_delete($population) {

  $population_wrapper = entity_metadata_wrapper('node', $population);
  $population_id = $population_wrapper->nid->value();

  // suppress link in studies
  $query = new EntityFieldQuery;
  $entities = $query->entityCondition('entity_type', 'node')
    ->entityCondition('bundle', 'study')
    ->execute();
  if (!empty($entities)) {
    $nodes = node_load_multiple(array_keys($entities['node']));
    foreach ($nodes as $node) {
      $study_populations = $node->field_study_populations;
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

function _mica_studies_population_view($node, $view_mode, $langcode) {

  // Breadcrumbs part
  // recuperation of the study of the population
  $wrapper = entity_metadata_wrapper('node', $node);
  $study_id = $wrapper->field_pop_study->nid->value();
  $breadcrumb = _mica_studies_menu_generate_breadcrumbs_pop('node/' . $study_id);

  // generate specific breadcrumbs for population pages pages
  $breadcrumbs = array();
  $breadcrumbs[] = l('Home', '');
  for ($i = 0; $i < count($breadcrumb); $i++) {
    $breadcrumbs[] = l($breadcrumb[$i]['link_title'], $breadcrumb[$i]['link_path']);
  }
  $breadcrumbs[] = l($wrapper->title->value(), 'node/' . $wrapper->nid->value());
  drupal_set_breadcrumb($breadcrumbs);

}

function _mica_studies_menu_generate_breadcrumbs_pop($path) {
  $result = db_query("SELECT * FROM {menu_links} WHERE link_path = :link_path", array(':link_path' => $path));
  $list = array();
  foreach ($result as $link) {
    $list[] = $link;
  }
  $list = $list[0];

  if (is_object($list)) {
    $list = get_object_vars($list);
  }
  // Check all parent link possible
  if ($list['p9'] != 0) {
    $i = 9;
  }
  else if ($list['p8'] != 0) {
    $i = 8;
  }
  else if ($list['p7'] != 0) {
    $i = 7;
  }
  else if ($list['p6'] != 0) {
    $i = 6;
  }
  else if ($list['p5'] != 0) {
    $i = 5;
  }
  else if ($list['p4'] != 0) {
    $i = 4;
  }
  else if ($list['p3'] != 0) {
    $i = 3;
  }
  else if ($list['p2'] != 0) {
    $i = 2;
  }
  else if ($list['p1'] != 0) {
    $i = 1;
  }

  $breadcrumbs = array();
  for ($i; $i > 0; $i--) {
    $temp = menu_link_load($list['p' . $i]);
    // add breadcrumbs if link_path is correct
    if (!preg_match('/<firstchild>/', $temp['link_path'])) {
      $breadcrumbs[] = menu_link_load($list['p' . $i]);
    }
  }
  $breadcrumbs = array_reverse($breadcrumbs);
  return $breadcrumbs;
}