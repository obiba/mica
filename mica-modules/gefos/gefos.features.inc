<?php
/**
 * @file
 * gefos.features.inc
 */

/**
 * Implementation of hook_ctools_plugin_api().
 */
function gefos_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => 1);
  }
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => 1);
  }
}

/**
 * Implementation of hook_node_info().
 */
function gefos_node_info() {
  $items = array(
    'fractures' => array(
      'name' => t('Fractures'),
      'base' => 'node_content',
      'description' => t('Genomos Survey - Fracture data information'),
      'has_title' => '1',
      'title_label' => t('Name'),
      'help' => '',
    ),
  );
  return $items;
}
