<?php
/**
 * @file
 * mica_projects.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function mica_projects_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function mica_projects_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function mica_projects_node_info() {
  $items = array(
    'project' => array(
      'name' => t('Project'),
      'base' => 'node_content',
      'description' => t('Research activities with a specific scientific question or target'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'teleconference' => array(
      'name' => t('Teleconference'),
      'base' => 'node_content',
      'description' => t('Teleconference event and details'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
