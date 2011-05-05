<?php
/**
 * @file
 * mica_addons.features.inc
 */

/**
 * Implementation of hook_ctools_plugin_api().
 */
function mica_addons_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => 1);
  }
}

/**
 * Implementation of hook_views_api().
 */
function mica_addons_views_api() {
  list($module, $api) = func_get_args();
  if ($module == "views" && $api == "views_default") {
    return array("version" => 3.0);
  }
}

/**
 * Implementation of hook_node_info().
 */
function mica_addons_node_info() {
  $items = array(
    'event' => array(
      'name' => t('Event'),
      'base' => 'node_content',
      'description' => t('Event description'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'publication' => array(
      'name' => t('Publication'),
      'base' => 'node_content',
      'description' => t('Scientific publications references and announcement.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
