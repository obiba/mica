<?php
/**
 * @file
 * Mica Datasets menu
 */

function _mica_datasets_create_dataset_menu($node) {

  $split = variable_get('mica_datasets_split_dataset', FALSE);

  $parent_path = NULL;
  $wrapper = entity_metadata_wrapper('node', $node);
  switch ($wrapper->field_dataset_type->value()) {
    case 'study':
      $parent_path = $split ? 'study-datasets' : 'datasets';
      break;
    case 'harmonization':
      $parent_path = $split ? 'harmonization-datasets' : 'datasets';
      break;
  }
  mica_core_create_node_menu($node, TRUE, FALSE, 0, $parent_path);
}

function _mica_datasets_create_variable_menu($node) {
  $wrapper = entity_metadata_wrapper('node', $node->nid);
  mica_core_create_node_menu($node, TRUE, FALSE, 0, 'node/' . $wrapper->field_dataset->nid->value());
}

function _mica_datasets_regenerate_menus() {

  $nb_dataset_menus = 0;
  $query = new EntityFieldQuery;
  $entities = $query->entityCondition('entity_type', 'node')
    ->entityCondition('bundle', 'dataset')
    ->execute();
  if (!empty($entities)) {
    $nodes = node_load_multiple(array_keys($entities['node']));
    foreach ($nodes as $node) {
      menu_link_delete(NULL, 'node/' . $node->nid);
      _mica_datasets_create_dataset_menu($node);
      $nb_dataset_menus++;
    }
  }

  $nb_variable_menus = 0;
  $query = new EntityFieldQuery;
  $entities = $query->entityCondition('entity_type', 'node')
    ->entityCondition('bundle', 'variable')
    ->execute();
  if (!empty($entities)) {
    $nodes = node_load_multiple(array_keys($entities['node']));
    foreach ($nodes as $node) {
      menu_link_delete(NULL, 'node/' . $node->nid);
      _mica_datasets_create_variable_menu($node);
      $nb_variable_menus++;
    }
  }

  drupal_set_message(t('Menus regenerated for %datasets datasets and %variables variables.',
    array('%datasets' => $nb_dataset_menus, '%variables' => $nb_variable_menus)));
}

function _mica_datasets_variables_reset_menus() {

  $nb_variable_menus = 0;
  $query = new EntityFieldQuery;
  $entities = $query->entityCondition('entity_type', 'node')
    ->entityCondition('bundle', 'variable')
    ->execute();
  if (!empty($entities)) {
    $nodes = node_load_multiple(array_keys($entities['node']));
    foreach ($nodes as $node) {
      menu_link_delete(NULL, 'node/' . $node->nid);
      $nb_variable_menus++;
    }
  }

  drupal_set_message(t('%nb variable menus have been successfully deleted.', array('%nb' => $nb_variable_menus)));
}