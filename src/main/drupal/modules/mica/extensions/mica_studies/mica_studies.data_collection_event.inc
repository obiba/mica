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

function _mica_studies_dce_view($node, $view_mode, $langcode) {

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
  $breadcrumb = _mica_studies_menu_generate_breadcrumbs_dce('node/' . $study_id);
  for ($i = 0; $i < count($breadcrumb); $i++) {
    $breadcrumbs[] = l($breadcrumb[$i]['link_title'], $breadcrumb[$i]['link_path']);
  }
  $breadcrumbs[] = $pop_link;

  drupal_set_breadcrumb($breadcrumbs);

}

function _mica_studies_menu_generate_breadcrumbs_dce($path) {
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