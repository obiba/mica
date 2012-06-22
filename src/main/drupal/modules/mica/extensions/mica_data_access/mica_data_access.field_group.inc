<?php
/**
 * @file
 * mica_data_access.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function mica_data_access_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_institution|node|data_access_request|default';
  $field_group->group_name = 'group_institution';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'data_access_request';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Institution',
    'weight' => '4',
    'children' => array(
      0 => 'field_city',
      1 => 'field_country_text',
      2 => 'field_institution_name',
      3 => 'field_postal_code',
      4 => 'field_street',
      5 => 'field_state',
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
  $export['group_institution|node|data_access_request|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_institution|node|data_access_request|form';
  $field_group->group_name = 'group_institution';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'data_access_request';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Institution',
    'weight' => '4',
    'children' => array(
      0 => 'field_city',
      1 => 'field_country_text',
      2 => 'field_institution_name',
      3 => 'field_postal_code',
      4 => 'field_street',
      5 => 'field_state',
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
  $export['group_institution|node|data_access_request|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_investigators|node|data_access_request|default';
  $field_group->group_name = 'group_investigators';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'data_access_request';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Investigators',
    'weight' => '3',
    'children' => array(
      0 => 'field_collaborator',
      1 => 'field_rep_email',
      2 => 'field_representative',
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
  $export['group_investigators|node|data_access_request|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_investigators|node|data_access_request|form';
  $field_group->group_name = 'group_investigators';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'data_access_request';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Investigators',
    'weight' => '3',
    'children' => array(
      0 => 'field_collaborator',
      1 => 'field_rep_email',
      2 => 'field_representative',
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
  $export['group_investigators|node|data_access_request|form'] = $field_group;

  return $export;
}
