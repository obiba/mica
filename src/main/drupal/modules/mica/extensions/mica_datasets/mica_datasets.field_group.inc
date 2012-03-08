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
  $field_group->identifier = 'group_areas_of_information|node|variable|form';
  $field_group->group_name = 'group_areas_of_information';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'variable';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_dimensions';
  $field_group->data = array(
    'label' => 'Areas of Information',
    'weight' => '40',
    'children' => array(
      0 => 'field_anthropometric_structures',
      1 => 'field_body_functions',
      2 => 'field_body_structures',
      3 => 'field_disease_history',
      4 => 'field_life_habits_behaviours',
      5 => 'field_medical_health_interv',
      6 => 'field_medication',
      7 => 'field_early_life',
      8 => 'field_perception_of_health',
      9 => 'field_physical_environment',
      10 => 'field_reproductive_history',
      11 => 'field_social_environment',
      12 => 'field_sociodemographic_charact',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_areas_of_information|node|variable|form'] = $field_group;

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
  $field_group->identifier = 'group_datasets|node|study|center_area';
  $field_group->group_name = 'group_datasets';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'study';
  $field_group->mode = 'center_area';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Datasets',
    'weight' => '16',
    'children' => array(
      0 => 'mica_dataset',
      1 => 'mica_opal',
    ),
    'format_type' => 'hidden',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
      ),
    ),
  );
  $export['group_datasets|node|study|center_area'] = $field_group;

  $field_group = new stdClass;
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_datasets|node|study|default';
  $field_group->group_name = 'group_datasets';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'study';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_tabs';
  $field_group->data = array(
    'label' => 'Datasets',
    'weight' => '94',
    'children' => array(
      0 => 'mica_dataset',
      1 => 'mica_opal',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
      ),
    ),
  );
  $export['group_datasets|node|study|default'] = $field_group;

  $field_group = new stdClass;
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_datasets|node|study|footer_area';
  $field_group->group_name = 'group_datasets';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'study';
  $field_group->mode = 'footer_area';
  $field_group->parent_name = 'group_tabs';
  $field_group->data = array(
    'label' => 'Datasets',
    'weight' => '93',
    'children' => array(
      0 => 'mica_dataset',
      1 => 'mica_opal',
    ),
    'format_type' => 'hidden',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
      ),
    ),
  );
  $export['group_datasets|node|study|footer_area'] = $field_group;

  $field_group = new stdClass;
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_datasets|node|study|form';
  $field_group->group_name = 'group_datasets';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'study';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_tabs';
  $field_group->data = array(
    'label' => 'Datasets',
    'weight' => '14',
    'children' => array(
      0 => 'mica_dataset',
      1 => 'mica_opal',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Datasets',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => 'Datasets available to the research community.',
      ),
      'formatter' => 'collapsible',
    ),
  );
  $export['group_datasets|node|study|form'] = $field_group;

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
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Dimensions',
    'weight' => '33',
    'children' => array(
      0 => 'group_areas_of_information',
      1 => 'group_source_of_information',
      2 => 'group_specifications',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
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
      3 => 'field_class',
      4 => 'field_data_source',
      5 => 'field_disease_history',
      6 => 'field_early_life',
      7 => 'field_format',
      8 => 'field_life_habits_behaviours',
      9 => 'field_medical_health_interv',
      10 => 'field_medication',
      11 => 'field_perception_of_health',
      12 => 'field_period',
      13 => 'field_physical_environment',
      14 => 'field_reproductive_history',
      15 => 'field_response_unit',
      16 => 'field_social_environment',
      17 => 'field_sociodemographic_charact',
      18 => 'field_target',
      19 => 'field_target_gender',
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
  $field_group->identifier = 'group_source_of_information|node|variable|form';
  $field_group->group_name = 'group_source_of_information';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'variable';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_dimensions';
  $field_group->data = array(
    'label' => 'Source of Information',
    'weight' => '41',
    'children' => array(
      0 => 'field_data_source',
      1 => 'field_response_unit',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_source_of_information|node|variable|form'] = $field_group;

  $field_group = new stdClass;
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_specifications|node|variable|form';
  $field_group->group_name = 'group_specifications';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'variable';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_dimensions';
  $field_group->data = array(
    'label' => 'Specifications of the Variable',
    'weight' => '42',
    'children' => array(
      0 => 'field_class',
      1 => 'field_format',
      2 => 'field_period',
      3 => 'field_target',
      4 => 'field_target_gender',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_specifications|node|variable|form'] = $field_group;

  $field_group = new stdClass;
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_tabs|node|study|default';
  $field_group->group_name = 'group_tabs';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'study';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Tabs',
    'weight' => '0',
    'children' => array(
      0 => 'group_access',
      1 => 'group_authorization',
      2 => 'group_datasets',
      3 => 'group_general_info',
      4 => 'group_marker_paper',
      5 => 'group_methods',
      6 => 'group_status',
      7 => 'group_supp_info',
    ),
    'format_type' => 'htabs',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'classes' => '',
      ),
    ),
  );
  $export['group_tabs|node|study|default'] = $field_group;

  $field_group = new stdClass;
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_tabs|node|study|footer_area';
  $field_group->group_name = 'group_tabs';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'study';
  $field_group->mode = 'footer_area';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Tabs',
    'weight' => '1',
    'children' => array(
      0 => 'group_access',
      1 => 'group_authorizations',
      2 => 'group_authorization',
      3 => 'group_datasets',
      4 => 'group_documents',
      5 => 'group_general_info',
      6 => 'group_marker_paper',
      7 => 'group_methods',
      8 => 'group_status',
    ),
    'format_type' => 'hidden',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'classes' => '',
      ),
    ),
  );
  $export['group_tabs|node|study|footer_area'] = $field_group;

  $field_group = new stdClass;
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_tabs|node|study|form';
  $field_group->group_name = 'group_tabs';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'study';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Tabs',
    'weight' => '0',
    'children' => array(
      0 => 'group_access',
      1 => 'group_authorization',
      2 => 'group_datasets',
      3 => 'group_documents',
      4 => 'group_general_info',
      5 => 'group_marker_paper',
      6 => 'group_methods',
      7 => 'group_status',
      8 => 'group_supp_info',
    ),
    'format_type' => 'htabs',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'classes' => '',
      ),
    ),
  );
  $export['group_tabs|node|study|form'] = $field_group;

  return $export;
}
