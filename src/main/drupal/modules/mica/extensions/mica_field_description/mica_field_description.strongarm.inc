<?php
/**
 * @file
 * mica_field_description.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function mica_field_description_strongarm() {
  $export = array();

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'additional_settings__active_tab_field_description';
  $strongarm->value = 'edit-menu';
  $export['additional_settings__active_tab_field_description'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_field_description';
  $strongarm->value = array();
  $export['menu_options_field_description'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_field_description';
  $strongarm->value = '';
  $export['menu_parent_field_description'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_field_description';
  $strongarm->value = array(
    0 => 'status',
  );
  $export['node_options_field_description'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_field_description';
  $strongarm->value = '1';
  $export['node_preview_field_description'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_field_description';
  $strongarm->value = 0;
  $export['node_submitted_field_description'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'parent_bundle_field_description';
  $strongarm->value = '';
  $export['parent_bundle_field_description'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_field_description_pattern';
  $strongarm->value = 'content/[node:field_original_field_name]';
  $export['pathauto_node_field_description_pattern'] = $strongarm;

  return $export;
}
