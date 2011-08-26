<?php
/**
 * @file
 * mica_data_access.field_group.inc
 */

/**
 * Implementation of hook_field_group_info().
 */
function mica_data_access_field_group_info() {
  $export = array();

  $field_group = new stdClass;
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

  return $export;
}
