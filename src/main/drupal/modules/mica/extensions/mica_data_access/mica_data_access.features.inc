<?php
/**
 * @file
 * mica_data_access.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function mica_data_access_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function mica_data_access_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function mica_data_access_node_info() {
  $items = array(
    'data_access_request' => array(
      'name' => t('Data Access Request'),
      'base' => 'node_content',
      'description' => t('Form to be filled in for accessing study data.'),
      'has_title' => '1',
      'title_label' => t('Project Title'),
      'help' => '',
    ),
    'data_access_review' => array(
      'name' => t('Data Access Review'),
      'base' => 'node_content',
      'description' => t('Describes the status of the data access form review.'),
      'has_title' => '1',
      'title_label' => t('Project Title'),
      'help' => '',
    ),
  );
  return $items;
}
