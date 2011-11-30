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
      0 => 'field_dim_body_functions',
      1 => 'field_dim_body_structure',
      2 => 'field_dim_class',
      3 => 'field_dim_collection_mode',
      4 => 'field_dim_disease',
      5 => 'field_dim_disease_history',
      6 => 'field_dim_format',
      7 => 'field_dim_health_information',
      8 => 'field_dim_life_habits_behaviours',
      9 => 'field_dim_med_health_interv',
      10 => 'field_dim_period',
      11 => 'field_dim_physical_env',
      12 => 'field_dim_sample',
      13 => 'field_dim_social_env',
      14 => 'field_dim_sociodemo_charact',
      15 => 'field_dim_socioeco',
      16 => 'field_dim_source_of_info',
      17 => 'field_dim_target',
      18 => 'field_dim_target_gender',
      19 => 'field_dim_type',
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
