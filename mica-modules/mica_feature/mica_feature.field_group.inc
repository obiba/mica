<?php
/**
 * @file
 * mica_feature.field_group.inc
 */

/**
 * Implementation of hook_field_group_info().
 */
function mica_feature_field_group_info() {
  $export = array();

  $field_group = new stdClass;
  $field_group->api_version = 1;
  $field_group->identifier = 'group_general_info|node|study_information|form';
  $field_group->group_name = 'group_general_info';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'study_information';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'General Information',
    'weight' => '0',
    'children' => array(
      0 => 'field_contact',
      1 => 'field_design',
      2 => 'field_design_other',
      3 => 'field_design_target',
      4 => 'field_full_name',
      5 => 'field_investigator',
      6 => 'title',
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
  $export['group_general_info|node|study_information|form'] = $field_group;

  return $export;
}
