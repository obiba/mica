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
  $dataset = node_load($dataset_nid);
  $dataset_wrapper = entity_metadata_wrapper('node', $dataset);
  foreach ($dataset_wrapper->field_dataset_variables->value() as $variable) {
    if (mica_datasets_is_variable_categorical($variable->nid)) {
      $variables[] = $variable;
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
  $variable = node_load($variable_nid);
  $variable_wrapper = entity_metadata_wrapper('node', $variable);
  foreach ($variable_wrapper->field_variable_categories->value() as $category) {
    if ($category['missing'] == 0) {
      return TRUE;
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
  $x_pos = entity_metadata_wrapper('node', $x)->field_position->value();
  $y_pos = entity_metadata_wrapper('node', $y)->field_position->value();
  if ($x_pos === $y_pos) {
    return 0;
  }
  return $x_pos < $y_pos ? -1 : 1;
}