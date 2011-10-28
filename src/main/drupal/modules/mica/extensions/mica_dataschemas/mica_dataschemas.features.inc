<?php
/**
 * @file
 * mica_dataschemas.features.inc
 */

/**
 * Implementation of hook_ctools_plugin_api().
 */
function mica_dataschemas_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "feeds" && $api == "feeds_importer_default") {
    return array("version" => "1");
  }
  list($module, $api) = func_get_args();
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implementation of hook_node_info().
 */
function mica_dataschemas_node_info() {
  $items = array(
    'dataschema' => array(
      'name' => t('DataSchema'),
      'base' => 'node_content',
      'description' => t('Identifies and describes a thematic set of core variables that are of particular value in a specified scientific setting.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'ds_domain' => array(
      'name' => t('Domain'),
      'base' => 'node_content',
      'description' => t('A domain is a risk factor or an outcome of interest, subsuming a number of variables.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'ds_module' => array(
      'name' => t('Module'),
      'base' => 'node_content',
      'description' => t('A module is a grouping based on variables main unit of interest, assessment modes or type of element measured or collected. '),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'ds_theme' => array(
      'name' => t('Theme'),
      'base' => 'node_content',
      'description' => t('A theme is a general area of interest.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'ds_variable' => array(
      'name' => t('Variable'),
      'base' => 'node_content',
      'description' => t('DataSchema variable'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
