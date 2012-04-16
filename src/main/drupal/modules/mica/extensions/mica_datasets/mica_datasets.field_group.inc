<?php
/**
 * @file
 * mica_datasets.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function mica_datasets_field_group_info() {
  $export = array();

  $field_group = new stdClass;
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_categories|node|variable|default';
  $field_group->group_name = 'group_categories';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'variable';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Categories',
    'weight' => '9',
    'children' => array(
      0 => 'field_variable_categories',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
      ),
    ),
  );
  $export['group_categories|node|variable|default'] = $field_group;

  $field_group = new stdClass;
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_categories|node|variable|left_area';
  $field_group->group_name = 'group_categories';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'variable';
  $field_group->mode = 'left_area';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Categories',
    'weight' => '29',
    'children' => array(
      0 => 'field_variable_categories',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
      ),
    ),
  );
  $export['group_categories|node|variable|left_area'] = $field_group;

  $field_group = new stdClass;
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_description|node|variable|default';
  $field_group->group_name = 'group_description';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'variable';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Description',
    'weight' => '1',
    'children' => array(
      0 => 'body',
      1 => 'field_dataset',
      2 => 'field_label',
      3 => 'field_repeatable',
      4 => 'field_value_type',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_description|node|variable|default'] = $field_group;

  $field_group = new stdClass;
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_description|node|variable|left_area';
  $field_group->group_name = 'group_description';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'variable';
  $field_group->mode = 'left_area';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Description',
    'weight' => '0',
    'children' => array(
      0 => 'field_dataset',
      1 => 'field_label',
      2 => 'field_repeatable',
      3 => 'field_value_type',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
      ),
    ),
  );
  $export['group_description|node|variable|left_area'] = $field_group;

  $field_group = new stdClass;
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_dimensions|node|variable|form';
  $field_group->group_name = 'group_dimensions';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'variable';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_tabs';
  $field_group->data = array(
    'label' => 'Dimensions',
    'weight' => '2',
    'children' => array(
      0 => 'field_anthropometric_structures',
      1 => 'field_body_functions',
      2 => 'field_body_structures',
      3 => 'field_data_source',
      4 => 'field_disease_history',
      5 => 'field_early_life',
      6 => 'field_essence',
      7 => 'field_life_habits_behaviours',
      8 => 'field_measure',
      9 => 'field_medical_health_interv',
      10 => 'field_medication',
      11 => 'field_perception_of_health',
      12 => 'field_period',
      13 => 'field_physical_environment',
      14 => 'field_reproductive_history',
      15 => 'field_social_environment',
      16 => 'field_sociodemographic_charact',
      17 => 'field_target',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'label' => 'Dimensions',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_dimensions|node|variable|form'] = $field_group;

  $field_group = new stdClass;
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_dimensions|node|variable|right_area';
  $field_group->group_name = 'group_dimensions';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'variable';
  $field_group->mode = 'right_area';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Dimensions',
    'weight' => '0',
    'children' => array(
      0 => 'field_anthropometric_structures',
      1 => 'field_body_functions',
      2 => 'field_body_structures',
      3 => 'field_data_source',
      4 => 'field_disease_history',
      5 => 'field_early_life',
      6 => 'field_essence',
      7 => 'field_life_habits_behaviours',
      8 => 'field_measure',
      9 => 'field_medical_health_interv',
      10 => 'field_medication',
      11 => 'field_perception_of_health',
      12 => 'field_period',
      13 => 'field_physical_environment',
      14 => 'field_reproductive_history',
      15 => 'field_social_environment',
      16 => 'field_sociodemographic_charact',
      17 => 'field_target',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
      ),
    ),
  );
  $export['group_dimensions|node|variable|right_area'] = $field_group;

  $field_group = new stdClass;
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_general_info|node|variable|form';
  $field_group->group_name = 'group_general_info';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'variable';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_tabs';
  $field_group->data = array(
    'label' => 'General Information',
    'weight' => '1',
    'children' => array(
      0 => 'body',
      1 => 'field_dataset',
      2 => 'field_label',
      3 => 'field_repeatable',
      4 => 'field_value_type',
      5 => 'field_variable_categories',
      6 => 'title',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'label' => 'General Information',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_general_info|node|variable|form'] = $field_group;
  return $export;
}
