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

  return $export;
}
