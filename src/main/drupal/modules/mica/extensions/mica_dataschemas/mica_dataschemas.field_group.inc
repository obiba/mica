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
      2 => 'field_dim_disease_history',
      3 => 'field_dim_format',
      4 => 'field_dim_health_information',
      5 => 'field_dim_life_habits_behaviours',
      6 => 'field_dim_medication',
      7 => 'field_dim_period',
      8 => 'field_dim_reproductive_history',
      9 => 'field_dim_sample',
      10 => 'field_dim_sociodemo_charact',
      11 => 'field_dim_source_of_info',
      12 => 'field_dim_target',
      13 => 'field_dim_target_gender',
      14 => 'field_dim_therapeutic_inter',
      15 => 'field_dim_type',
      16 => 'field_dim_biochemical_measures',
      17 => 'field_dim_body_functions_meas',
      18 => 'field_dim_environmental_exp',
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
