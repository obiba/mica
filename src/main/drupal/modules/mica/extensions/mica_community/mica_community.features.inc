<?php
/**
 * @file
 * mica_community.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function mica_community_ctools_plugin_api($module = NULL, $api = NULL) {
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
function mica_community_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function mica_community_node_info() {
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
