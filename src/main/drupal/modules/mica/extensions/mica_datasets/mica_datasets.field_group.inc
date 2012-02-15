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
  $field_group->identifier = 'group_datasets|node|study|default';
  $field_group->group_name = 'group_datasets';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'study';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Datasets',
    'weight' => '4',
    'children' => array(
      0 => 'mica_dataset',
      1 => 'mica_opal',
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
  $export['group_datasets|node|study|default'] = $field_group;

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
  $field_group->identifier = 'group_description|node|participant_variable|default';
  $field_group->group_name = 'group_description';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'participant_variable';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Description',
    'weight' => '0',
    'children' => array(
      0 => 'body',
      1 => 'field_categories',
      2 => 'field_dataset',
      3 => 'field_label',
      4 => 'field_repeatable',
      5 => 'field_value_type',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'classes' => '',
      ),
    ),
  );
  $export['group_description|node|participant_variable|default'] = $field_group;

  $field_group = new stdClass;
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_participant_variable|node|participant_variable|default';
  $field_group->group_name = 'group_participant_variable';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'participant_variable';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Description',
    'weight' => '1',
    'children' => array(
      0 => 'field_label',
      1 => 'body',
      2 => 'field_value_type',
      3 => 'field_repeatable',
      4 => 'field_categories',
      5 => 'field_dataset',
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
  $export['group_participant_variable|node|participant_variable|default'] = $field_group;

  $field_group = new stdClass;
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_participant_variable|node|participant_variable|form';
  $field_group->group_name = 'group_participant_variable';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'participant_variable';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Description',
    'weight' => '1',
    'children' => array(
      0 => 'field_label',
      1 => 'body',
      2 => 'field_value_type',
      3 => 'field_repeatable',
      4 => 'field_categories',
      5 => 'field_dataset',
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
  $export['group_participant_variable|node|participant_variable|form'] = $field_group;

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
      0 => 'group_datasets',
      1 => 'group_access',
      2 => 'group_authorization',
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
