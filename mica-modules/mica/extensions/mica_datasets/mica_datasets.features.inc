<?php
/**
 * @file
 * mica_datasets.features.inc
 */

/**
 * Implementation of hook_ctools_plugin_api().
 */
function mica_datasets_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => 1);
  }
}

/**
 * Implementation of hook_views_api().
 */
function mica_datasets_views_api() {
  list($module, $api) = func_get_args();
  if ($module == "views" && $api == "views_default") {
    return array("version" => 3.0);
  }
}

/**
 * Implementation of hook_node_info().
 */
function mica_datasets_node_info() {
  $items = array(
    'dataset' => array(
      'name' => t('Dataset'),
      'base' => 'node_content',
      'description' => t('Dataset resource.'),
      'has_title' => '1',
      'title_label' => t('Name'),
      'help' => '',
    ),
    'participant_variable' => array(
      'name' => t('Participant Variable'),
      'base' => 'node_content',
      'description' => 'Description of participant data.',
      'has_title' => '1',
      'title_label' => t('Name'),
      'help' => '',
    ),
  );
  return $items;
}
