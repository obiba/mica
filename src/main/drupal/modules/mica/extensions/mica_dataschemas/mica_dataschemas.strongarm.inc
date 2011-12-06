<?php
/**
 * @file
 * mica_dataschemas.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function mica_dataschemas_strongarm() {
  $export = array();

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'collapsiblock_default_state';
  $strongarm->value = '1';
  $export['collapsiblock_default_state'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'collapsiblock_settings';
  $strongarm->value = array(
    'block-search-api-facets-dataschema-variables-field-dim-3' => '3',
    'block-search-api-facets-dataschema-variables-field-dim-2' => '3',
    'block-search-api-facets-dataschema-variables-field-dim-4' => '3',
    'block-search-api-facets-dataschema-variables-field-dim-s' => '3',
    'block-search-api-facets-dataschema-variables-field-dim-p' => '3',
    'block-search-api-facets-dataschema-variables-field-dim-m' => '3',
    'block-search-api-facets-dataschema-variables-field-dim-f' => '3',
    'block-search-api-facets-dataschema-variables-field-dim-d' => '3',
    'block-search-api-facets-dataschema-variables-field-dim-c' => '3',
    'block-search-api-facets-dataschema-variables-field-dim-t' => '3',
    'block-search-api-facets-dataschema-variables-field-dim-l' => '2',
    'block-search-api-facets-dataschema-variables-field-datas' => '2',
    'block-search-api-facets-dataschema-variables-field-dim-6' => '2',
    'block-search-api-facets-dataschema-variables-field-dim-h' => '2',
    'block-search-api-facets-dataschema-variables-field-dim-1' => '3',
    'block-search-api-facets-dataschema-variables-field-di-10' => '3',
    'block-search-api-facets-dataschema-variables-field-dim-9' => '3',
    'block-search-api-facets-dataschema-variables-field-dim-8' => '3',
    'block-search-api-facets-dataschema-variables-field-dim-7' => '3',
    'block-search-api-facets-dataschema-variables-field-dim-5' => '3',
    'block-search-api-facets-dataschema-variables-field-dim-b' => '3',
    'block-node-reference-block-related-content' => '1',
  );
  $export['collapsiblock_settings'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'collapsiblock_slide_speed';
  $strongarm->value = '200';
  $export['collapsiblock_slide_speed'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'collapsiblock_slide_type';
  $strongarm->value = '2';
  $export['collapsiblock_slide_type'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_anonymous_dataschema';
  $strongarm->value = 0;
  $export['comment_anonymous_dataschema'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_anonymous_dataschema_category';
  $strongarm->value = 0;
  $export['comment_anonymous_dataschema_category'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_anonymous_dataschema_variable';
  $strongarm->value = 0;
  $export['comment_anonymous_dataschema_variable'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_anonymous_pairing';
  $strongarm->value = 0;
  $export['comment_anonymous_pairing'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_dataschema';
  $strongarm->value = '1';
  $export['comment_dataschema'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_dataschema_category';
  $strongarm->value = '1';
  $export['comment_dataschema_category'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_dataschema_variable';
  $strongarm->value = '1';
  $export['comment_dataschema_variable'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_mode_dataschema';
  $strongarm->value = 1;
  $export['comment_default_mode_dataschema'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_mode_dataschema_category';
  $strongarm->value = 1;
  $export['comment_default_mode_dataschema_category'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_mode_dataschema_variable';
  $strongarm->value = 1;
  $export['comment_default_mode_dataschema_variable'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_mode_pairing';
  $strongarm->value = 1;
  $export['comment_default_mode_pairing'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_per_page_dataschema';
  $strongarm->value = '50';
  $export['comment_default_per_page_dataschema'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_per_page_dataschema_category';
  $strongarm->value = '50';
  $export['comment_default_per_page_dataschema_category'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_per_page_dataschema_variable';
  $strongarm->value = '50';
  $export['comment_default_per_page_dataschema_variable'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_per_page_pairing';
  $strongarm->value = '50';
  $export['comment_default_per_page_pairing'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_form_location_dataschema';
  $strongarm->value = 1;
  $export['comment_form_location_dataschema'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_form_location_dataschema_category';
  $strongarm->value = 1;
  $export['comment_form_location_dataschema_category'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_form_location_dataschema_variable';
  $strongarm->value = 1;
  $export['comment_form_location_dataschema_variable'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_form_location_pairing';
  $strongarm->value = 1;
  $export['comment_form_location_pairing'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_pairing';
  $strongarm->value = '1';
  $export['comment_pairing'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_preview_dataschema';
  $strongarm->value = '1';
  $export['comment_preview_dataschema'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_preview_dataschema_category';
  $strongarm->value = '1';
  $export['comment_preview_dataschema_category'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_preview_dataschema_variable';
  $strongarm->value = '1';
  $export['comment_preview_dataschema_variable'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_preview_pairing';
  $strongarm->value = '1';
  $export['comment_preview_pairing'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_subject_field_dataschema';
  $strongarm->value = 1;
  $export['comment_subject_field_dataschema'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_subject_field_dataschema_category';
  $strongarm->value = 1;
  $export['comment_subject_field_dataschema_category'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_subject_field_dataschema_variable';
  $strongarm->value = 1;
  $export['comment_subject_field_dataschema_variable'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_subject_field_pairing';
  $strongarm->value = 1;
  $export['comment_subject_field_pairing'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_dataschema';
  $strongarm->value = array(
    0 => 'main-menu',
  );
  $export['menu_options_dataschema'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_dataschema_category';
  $strongarm->value = array(
    0 => 'main-menu',
  );
  $export['menu_options_dataschema_category'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_dataschema_variable';
  $strongarm->value = array(
    0 => 'main-menu',
  );
  $export['menu_options_dataschema_variable'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_pairing';
  $strongarm->value = array(
    0 => 'main-menu',
  );
  $export['menu_options_pairing'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_dataschema_variable';
  $strongarm->value = 'main-menu:446';
  $export['menu_parent_dataschema_variable'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_pairing';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_pairing'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_dataschema';
  $strongarm->value = array(
    0 => 'status',
  );
  $export['node_options_dataschema'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_dataschema_category';
  $strongarm->value = array(
    0 => 'status',
  );
  $export['node_options_dataschema_category'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_dataschema_variable';
  $strongarm->value = array(
    0 => 'status',
  );
  $export['node_options_dataschema_variable'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_pairing';
  $strongarm->value = array(
    0 => 'status',
  );
  $export['node_options_pairing'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_dataschema';
  $strongarm->value = '1';
  $export['node_preview_dataschema'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_dataschema_category';
  $strongarm->value = '1';
  $export['node_preview_dataschema_category'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_dataschema_variable';
  $strongarm->value = '1';
  $export['node_preview_dataschema_variable'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_pairing';
  $strongarm->value = '1';
  $export['node_preview_pairing'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_dataschema';
  $strongarm->value = 0;
  $export['node_submitted_dataschema'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_dataschema_category';
  $strongarm->value = 0;
  $export['node_submitted_dataschema_category'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_dataschema_variable';
  $strongarm->value = 0;
  $export['node_submitted_dataschema_variable'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_pairing';
  $strongarm->value = 0;
  $export['node_submitted_pairing'] = $strongarm;

  return $export;
}
