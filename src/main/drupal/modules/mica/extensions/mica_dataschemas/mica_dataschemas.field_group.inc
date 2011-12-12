<?php
/**
 * @file
 * mica_dataschemas.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function mica_dataschemas_field_group_info() {
  $export = array();

  $field_group = new stdClass;
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_dimension|node|dataschema_variable|form';
  $field_group->group_name = 'group_dimension';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'dataschema_variable';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Dimensions',
    'weight' => '5',
    'children' => array(
      0 => 'field_dim_biochemical_measures',
      1 => 'field_dim_body_functions_meas',
      2 => 'field_dim_class',
      3 => 'field_dim_collection_mode',
      4 => 'field_dim_disease_history',
      5 => 'field_dim_environmental_exp',
      6 => 'field_dim_format',
      7 => 'field_dim_life_habits_behaviours',
      8 => 'field_dim_medication',
      9 => 'field_dim_period',
      10 => 'field_dim_reproductive_history',
      11 => 'field_dim_sample',
      12 => 'field_dim_sociodemo_charact',
      13 => 'field_dim_source_of_info',
      14 => 'field_dim_target',
      15 => 'field_dim_target_gender',
      16 => 'field_dim_therapeutic_inter',
      17 => 'field_dim_type',
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
  $export['group_dimension|node|dataschema_variable|form'] = $field_group;

  return $export;
}
