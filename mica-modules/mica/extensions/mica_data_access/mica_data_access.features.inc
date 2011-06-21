<?php
/**
 * @file
 * mica_data_access.features.inc
 */

/**
 * Implementation of hook_ctools_plugin_api().
 */
function mica_data_access_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => 1);
  }
}

/**
 * Implementation of hook_views_api().
 */
function mica_data_access_views_api() {
  list($module, $api) = func_get_args();
  if ($module == "views" && $api == "views_default") {
    return array("version" => 3.0);
  }
}

/**
 * Implementation of hook_node_info().
 */
function mica_data_access_node_info() {
  $items = array(
    'data_access_request' => array(
      'name' => t('Data Access Request'),
      'base' => 'mica_data_access',
      'description' => t('Form to be filled in for accessing study data.'),
      'has_title' => '1',
      'title_label' => t('Project Title'),
      'help' => '',
    ),
    'data_access_review' => array(
      'name' => t('Data Access Review'),
      'base' => 'mica_data_access',
      'description' => t('Describes the status of the data access form review.'),
      'has_title' => '1',
      'title_label' => t('Project Title'),
      'help' => '',
    ),
  );
  return $items;
}
