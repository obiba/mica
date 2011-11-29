<?php
/**
 * @file
 * mica_dataschemas.field_group.inc
 */

/**
 * Implementation of hook_field_group_info().
 */
function mica_dataschemas_field_group_info() {
  $export = array();

  $field_group = new stdClass;
  $field_group->api_version = 1;
  $field_group->identifier = 'group_dimension|node|ds_variable|form';
  $field_group->group_name = 'group_dimension';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'ds_variable';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Dimensions',
    'weight' => '7',
    'children' => array(
      0 => 'field_dim_class',
      1 => 'field_dim_collection_mode',
      2 => 'field_dim_disease',
      3 => 'field_dim_format',
      4 => 'field_dim_med_health_interv',
      5 => 'field_dim_period',
      6 => 'field_dim_sample',
      7 => 'field_dim_source_of_info',
      8 => 'field_dim_target',
      9 => 'field_dim_target_gender',
      10 => 'field_dim_type',
      11 => 'field_dim_body_functions',
      12 => 'field_dim_body_structure',
      13 => 'field_dim_disease_history',
      14 => 'field_dim_health_information',
      15 => 'field_dim_life_habits_behaviours',
      16 => 'field_dim_physical_env',
      17 => 'field_dim_social_env',
      18 => 'field_dim_sociodemo_charact',
      19 => 'field_dim_socioeco',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Dimensions',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => 'Terms used to describe the different characteristics of a variable.',
      ),
      'formatter' => 'collapsible',
    ),
  );
  $export['group_dimension|node|ds_variable|form'] = $field_group;

  return $export;
}
