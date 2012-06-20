<?php
/**
 * @file
 * mica_networks.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function mica_networks_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_authorization|node|network|form';
  $field_group->group_name = 'group_authorization';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'network';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Authorization from contributors to the Maelstrom Research website',
    'weight' => '9',
    'children' => array(
      0 => 'field_authorising_date_m',
      1 => 'field_authorising_person_name_m',
      2 => 'field_authorization_maelstrom',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Authorization from contributors to the Maelstrom Research website',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => 'I agree and understand that the information collected in this form will be displayed on Maelstrom Research website (http://www.maelstrom-research.org). ',
      ),
      'formatter' => 'collapsible',
    ),
  );
  $export['group_authorization|node|network|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_general_info|node|study|form';
  $field_group->group_name = 'group_general_info';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'study';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_tabs';
  $field_group->data = array(
    'label' => 'General Information',
    'weight' => '6',
    'children' => array(
      0 => 'body',
      1 => 'field_contacts_ref',
      2 => 'field_investigators',
      3 => 'field_website',
      4 => 'field_networks',
      5 => 'group_study_name',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'label' => 'General Information',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'closed',
    ),
  );
  $export['group_general_info|node|study|form'] = $field_group;

  $field_group = new stdClass();
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
