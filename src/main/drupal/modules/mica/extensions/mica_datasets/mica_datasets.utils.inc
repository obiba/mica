<?php

/**
 * @file
 * Utilities methods for Mica Datasets module.
 */

/**
 * @param $dataset_nid
 * @return array of variables
 */
function mica_datasets_find_categorical_variables($dataset_nid) {
  $variables = array();
  $dataset_wrapper = entity_metadata_wrapper('node', $dataset_nid);
  foreach ($dataset_wrapper->field_dataset_variables->getIterator() as $variable) {
    if (mica_datasets_is_variable_categorical($variable->getIdentifier())) {
      $variable_node = node_load($variable->getIdentifier());
      $variables[] = $variable_node;
    }
  }
  uasort($variables, 'mica_datasets_sort_by_title');
  return $variables;
}

/**
 * @param $variable_nid
 * @return TRUE if variable has at least one non missing category
 */
function mica_datasets_is_variable_categorical($variable_nid) {
  $variable_wrapper = entity_metadata_wrapper('node', $variable_nid);
  if (!empty($variable_wrapper->field_variable_categories)) {
    foreach ($variable_wrapper->field_variable_categories->getIterator() as $category) {
      return $category->missing->value() == 0;
    }
  }
  return FALSE;
}

function mica_datasets_sort_by_title($x, $y) {
  $x_pos = entity_metadata_wrapper('node', $x)->title->value();
  $y_pos = entity_metadata_wrapper('node', $y)->title->value();
  if ($x_pos === $y_pos) {
    return 0;
  }
  return $x_pos < $y_pos ? -1 : 1;
}

function mica_datasets_sort_by_position($x, $y) {
  $var_x__to_sort_wrapper = entity_metadata_wrapper('node', $x);

  $x_pos = !empty($var_x__to_sort_wrapper->field_position) ? $var_x__to_sort_wrapper->field_position->value() : NULL;
  $var_y__to_sort_wrapper = entity_metadata_wrapper('node', $y);
  $y_pos = !empty($var_y__to_sort_wrapper->field_position) ? $var_y__to_sort_wrapper->field_position->value() : NULL;
  if ($x_pos === $y_pos) {
    return 0;
  }
  return $x_pos < $y_pos ? -1 : 1;
}