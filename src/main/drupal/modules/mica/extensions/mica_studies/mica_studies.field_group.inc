<?php
/**
 * @file
 * mica_studies.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function mica_studies_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_access_description|node|study|center_area';
  $field_group->group_name = 'group_access_description';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'study';
  $field_group->mode = 'center_area';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Study allows external researchers access to',
    'weight' => '11',
    'children' => array(),
    'format_type' => 'hidden',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(),
    ),
  );
  $export['group_access_description|node|study|center_area'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_access_description|node|study|default';
  $field_group->group_name = 'group_access_description';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'study';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_access';
  $field_group->data = array(
    'label' => 'Study allows external researchers access to',
    'weight' => '44',
    'children' => array(
      0 => 'field_access_biosamples',
      1 => 'field_access_data',
      2 => 'field_access_other',
      3 => 'field_access_other_sp',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Study allows external researchers access to',
      'instance_settings' => array(
        'classes' => '',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h2',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_access_description|node|study|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_access_description|node|study|footer_area';
  $field_group->group_name = 'group_access_description';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'study';
  $field_group->mode = 'footer_area';
  $field_group->parent_name = 'group_access';
  $field_group->data = array(
    'label' => 'Study allows external researchers access to',
    'weight' => '44',
    'children' => array(
      0 => 'field_access_biosamples',
      1 => 'field_access_data',
      2 => 'field_access_other',
      3 => 'field_access_other_sp',
    ),
    'format_type' => 'hidden',
    'format_settings' => array(
      'label' => 'Study allows external researchers access to',
      'instance_settings' => array(
        'classes' => '',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h2',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_access_description|node|study|footer_area'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_access_description|node|study|left_area';
  $field_group->group_name = 'group_access_description';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'study';
  $field_group->mode = 'left_area';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Study allows external researchers access to',
    'weight' => '21',
    'children' => array(),
    'format_type' => 'hidden',
    'format_settings' => array(
      'label' => 'Study allows external researchers access to',
      'instance_settings' => array(
        'classes' => '',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h2',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_access_description|node|study|left_area'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_access_description|node|study|right_area';
  $field_group->group_name = 'group_access_description';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'study';
  $field_group->mode = 'right_area';
  $field_group->parent_name = 'group_access';
  $field_group->data = array(
    'label' => 'Study allows external researchers access to',
    'weight' => '44',
    'children' => array(
      0 => 'field_access_biosamples',
      1 => 'field_access_data',
      2 => 'field_access_other',
      3 => 'field_access_other_sp',
    ),
    'format_type' => 'hidden',
    'format_settings' => array(
      'label' => 'Study allows external researchers access to',
      'instance_settings' => array(
        'classes' => '',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h2',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_access_description|node|study|right_area'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_access|node|study|center_area';
  $field_group->group_name = 'group_access';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'study';
  $field_group->mode = 'center_area';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Access',
    'weight' => '1',
    'children' => array(
      0 => 'field_access_biosamples',
      1 => 'field_access_data',
      2 => 'field_access_other',
      3 => 'field_access_other_sp',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Access',
      'instance_settings' => array(
        'classes' => '',
        'description' => 'Access to external researchers or third parties provided or foreseen for',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_access|node|study|center_area'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_access|node|study|default';
  $field_group->group_name = 'group_access';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'study';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_tabs';
  $field_group->data = array(
    'label' => 'Access',
    'weight' => '88',
    'children' => array(
      0 => 'group_access_description',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'label' => 'Access',
      'instance_settings' => array(
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'closed',
    ),
  );
  $export['group_access|node|study|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_access|node|study|footer_area';
  $field_group->group_name = 'group_access';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'study';
  $field_group->mode = 'footer_area';
  $field_group->parent_name = 'group_tabs';
  $field_group->data = array(
    'label' => 'Access',
    'weight' => '88',
    'children' => array(
      0 => 'group_access_description',
    ),
    'format_type' => 'hidden',
    'format_settings' => array(
      'label' => 'Access',
      'instance_settings' => array(
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'closed',
    ),
  );
  $export['group_access|node|study|footer_area'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_access|node|study|form';
  $field_group->group_name = 'group_access';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'study';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_tabs';
  $field_group->data = array(
    'label' => 'Access',
    'weight' => '9',
    'children' => array(
      0 => 'field_access_biosamples',
      1 => 'field_access_data',
      2 => 'field_access_other',
      3 => 'field_access_other_sp',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'label' => 'Access',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => 'Is access to the following study features by external researchers or third parties provided or foreseen?',
      ),
      'formatter' => 'closed',
    ),
  );
  $export['group_access|node|study|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_access|node|study|left_area';
  $field_group->group_name = 'group_access';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'study';
  $field_group->mode = 'left_area';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Access',
    'weight' => '14',
    'children' => array(
      0 => 'field_access_biosamples',
      1 => 'field_access_data',
      2 => 'field_access_other',
      3 => 'field_access_other_sp',
    ),
    'format_type' => 'hidden',
    'format_settings' => array(
      'label' => 'Access',
      'instance_settings' => array(
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'closed',
    ),
  );
  $export['group_access|node|study|left_area'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_access|node|study|right_area';
  $field_group->group_name = 'group_access';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'study';
  $field_group->mode = 'right_area';
  $field_group->parent_name = 'group_tabs';
  $field_group->data = array(
    'label' => 'Access',
    'weight' => '88',
    'children' => array(
      0 => 'group_access_description',
    ),
    'format_type' => 'hidden',
    'format_settings' => array(
      'label' => 'Access',
      'instance_settings' => array(
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'closed',
    ),
  );
  $export['group_access|node|study|right_area'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_age_range|node|study|center_area';
  $field_group->group_name = 'group_age_range';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'study';
  $field_group->mode = 'center_area';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Please specify age range',
    'weight' => '32',
    'children' => array(),
    'format_type' => 'hidden',
    'format_settings' => array(
      'formatter' => 'open',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_age_range|node|study|center_area'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_age_range|node|study|default';
  $field_group->group_name = 'group_age_range';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'study';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_participants_selection';
  $field_group->data = array(
    'label' => 'Please specify age range',
    'weight' => '47',
    'children' => array(),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'open',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_age_range|node|study|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_age_range|node|study|footer_area';
  $field_group->group_name = 'group_age_range';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'study';
  $field_group->mode = 'footer_area';
  $field_group->parent_name = 'group_participants_selection';
  $field_group->data = array(
    'label' => 'Please specify age range',
    'weight' => '47',
    'children' => array(),
    'format_type' => 'hidden',
    'format_settings' => array(
      'formatter' => 'open',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_age_range|node|study|footer_area'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_age_range|node|study|right_area';
  $field_group->group_name = 'group_age_range';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'study';
  $field_group->mode = 'right_area';
  $field_group->parent_name = 'group_participants_selection';
  $field_group->data = array(
    'label' => 'Please specify age range',
    'weight' => '47',
    'children' => array(),
    'format_type' => 'hidden',
    'format_settings' => array(
      'formatter' => 'open',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_age_range|node|study|right_area'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_authorising_person_m|node|study|center_area';
  $field_group->group_name = 'group_authorising_person_m';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'study';
  $field_group->mode = 'center_area';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Authorization Details',
    'weight' => '5',
    'children' => array(),
    'format_type' => 'hidden',
    'format_settings' => array(
      'label' => 'Authorization Details',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_authorising_person_m|node|study|center_area'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_authorising_person_m|node|study|default';
  $field_group->group_name = 'group_authorising_person_m';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'study';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_authorization_maelstrom';
  $field_group->data = array(
    'label' => 'Authorization Details',
    'weight' => '22',
    'children' => array(),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Authorization Details',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_authorising_person_m|node|study|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_authorising_person_m|node|study|footer_area';
  $field_group->group_name = 'group_authorising_person_m';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'study';
  $field_group->mode = 'footer_area';
  $field_group->parent_name = 'group_authorization_maelstrom';
  $field_group->data = array(
    'label' => 'Authorization Details',
    'weight' => '22',
    'children' => array(),
    'format_type' => 'hidden',
    'format_settings' => array(
      'label' => 'Authorization Details',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_authorising_person_m|node|study|footer_area'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_authorising_person_m|node|study|form';
  $field_group->group_name = 'group_authorising_person_m';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'study';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_authorization_maelstrom';
  $field_group->data = array(
    'label' => 'Authorization Details',
    'weight' => '20',
    'children' => array(),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Authorization Details',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_authorising_person_m|node|study|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_authorising_person_m|node|study|left_area';
  $field_group->group_name = 'group_authorising_person_m';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'study';
  $field_group->mode = 'left_area';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Authorization Details',
    'weight' => '18',
    'children' => array(),
    'format_type' => 'hidden',
    'format_settings' => array(
      'label' => 'Authorization Details',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_authorising_person_m|node|study|left_area'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_authorising_person_m|node|study|right_area';
  $field_group->group_name = 'group_authorising_person_m';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'study';
  $field_group->mode = 'right_area';
  $field_group->parent_name = 'group_authorization_maelstrom';
  $field_group->data = array(
    'label' => 'Authorization Details',
    'weight' => '22',
    'children' => array(),
    'format_type' => 'hidden',
    'format_settings' => array(
      'label' => 'Authorization Details',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_authorising_person_m|node|study|right_area'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_authorising_person|node|study|center_area';
  $field_group->group_name = 'group_authorising_person';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'study';
  $field_group->mode = 'center_area';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Authorization Details',
    'weight' => '4',
    'children' => array(),
    'format_type' => 'hidden',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'classes' => '',
      ),
    ),
  );
  $export['group_authorising_person|node|study|center_area'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_authorising_person|node|study|default';
  $field_group->group_name = 'group_authorising_person';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'study';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_authorization_specific';
  $field_group->data = array(
    'label' => 'Authorization Details',
    'weight' => '19',
    'children' => array(),
    'format_type' => 'accordion-item',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'classes' => '',
      ),
    ),
  );
  $export['group_authorising_person|node|study|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_authorising_person|node|study|footer_area';
  $field_group->group_name = 'group_authorising_person';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'study';
  $field_group->mode = 'footer_area';
  $field_group->parent_name = 'group_authorization_specific';
  $field_group->data = array(
    'label' => 'Authorization Details',
    'weight' => '19',
    'children' => array(),
    'format_type' => 'hidden',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'classes' => '',
      ),
    ),
  );
  $export['group_authorising_person|node|study|footer_area'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_authorising_person|node|study|form';
  $field_group->group_name = 'group_authorising_person';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'study';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_authorization_specific';
  $field_group->data = array(
    'label' => 'Authorization Details',
    'weight' => '18',
    'children' => array(),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Authorization Details',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_authorising_person|node|study|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_authorising_person|node|study|left_area';
  $field_group->group_name = 'group_authorising_person';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'study';
  $field_group->mode = 'left_area';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Authorization Details',
    'weight' => '15',
    'children' => array(),
    'format_type' => 'hidden',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(),
    ),
  );
  $export['group_authorising_person|node|study|left_area'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_authorising_person|node|study|right_area';
  $field_group->group_name = 'group_authorising_person';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'study';
  $field_group->mode = 'right_area';
  $field_group->parent_name = 'group_authorization_specific';
  $field_group->data = array(
    'label' => 'Authorization Details',
    'weight' => '19',
    'children' => array(),
    'format_type' => 'hidden',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'classes' => '',
      ),
    ),
  );
  $export['group_authorising_person|node|study|right_area'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_authorization_maelstrom|node|study|center_area';
  $field_group->group_name = 'group_authorization_maelstrom';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'study';
  $field_group->mode = 'center_area';
  $field_group->parent_name = 'group_authorization';
  $field_group->data = array(
    'label' => 'Authorization from contributors to the Maelstrom catalogues',
    'weight' => '17',
    'children' => array(
      0 => 'field_authorising_date_m',
      1 => 'field_authorising_person_name_m',
      2 => 'field_authorization_maelstrom',
    ),
    'format_type' => 'hidden',
    'format_settings' => array(
      'label' => 'Authorization from contributors to the Maelstrom catalogues',
      'instance_settings' => array(
        'classes' => '',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h2',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_authorization_maelstrom|node|study|center_area'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_authorization_maelstrom|node|study|default';
  $field_group->group_name = 'group_authorization_maelstrom';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'study';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_authorization';
  $field_group->data = array(
    'label' => 'Authorization from contributors to the Maelstrom catalogues',
    'weight' => '17',
    'children' => array(
      0 => 'field_authorising_date_m',
      1 => 'field_authorising_person_name_m',
      2 => 'field_authorization_maelstrom',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Authorization from contributors to the Maelstrom catalogues',
      'instance_settings' => array(
        'classes' => '',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h2',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_authorization_maelstrom|node|study|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_authorization_maelstrom|node|study|footer_area';
  $field_group->group_name = 'group_authorization_maelstrom';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'study';
  $field_group->mode = 'footer_area';
  $field_group->parent_name = 'group_authorization';
  $field_group->data = array(
    'label' => 'Authorization from contributors to the Maelstrom catalogues',
    'weight' => '17',
    'children' => array(
      0 => 'group_authorising_person_m',
    ),
    'format_type' => 'hidden',
    'format_settings' => array(
      'label' => 'Authorization from contributors to the Maelstrom catalogues',
      'instance_settings' => array(
        'classes' => '',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h2',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_authorization_maelstrom|node|study|footer_area'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_authorization_maelstrom|node|study|form';
  $field_group->group_name = 'group_authorization_maelstrom';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'study';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_authorization';
  $field_group->data = array(
    'label' => 'Authorization from contributors to the Maelstrom catalogues',
    'weight' => '17',
    'children' => array(
      0 => 'field_authorising_date_m',
      1 => 'field_authorising_person_name_m',
      2 => 'field_authorization_maelstrom',
      3 => 'group_authorising_person_m',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Authorization from contributors to the Maelstrom catalogues',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => 'I agree and understand that the information collected in this form will be displayed on the Maelstrom Research website upon reception in agreement with “Authorization from contributors to the Maelstrom Research Catalogues”.',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_authorization_maelstrom|node|study|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_authorization_maelstrom|node|study|left_area';
  $field_group->group_name = 'group_authorization_maelstrom';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'study';
  $field_group->mode = 'left_area';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Authorization from contributors to the Maelstrom catalogues',
    'weight' => '6',
    'children' => array(),
    'format_type' => 'hidden',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(),
    ),
  );
  $export['group_authorization_maelstrom|node|study|left_area'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_authorization_maelstrom|node|study|right_area';
  $field_group->group_name = 'group_authorization_maelstrom';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'study';
  $field_group->mode = 'right_area';
  $field_group->parent_name = 'group_authorization';
  $field_group->data = array(
    'label' => 'Authorization from contributors to the Maelstrom catalogues',
    'weight' => '17',
    'children' => array(
      0 => 'field_authorising_date_m',
      1 => 'field_authorising_person_name_m',
      2 => 'field_authorization_maelstrom',
      3 => 'group_authorising_person_m',
    ),
    'format_type' => 'hidden',
    'format_settings' => array(
      'label' => 'Authorization from contributors to the Maelstrom catalogues',
      'instance_settings' => array(
        'classes' => '',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h2',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_authorization_maelstrom|node|study|right_area'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_authorization_specific|node|study|center_area';
  $field_group->group_name = 'group_authorization_specific';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'study';
  $field_group->mode = 'center_area';
  $field_group->parent_name = 'group_authorization';
  $field_group->data = array(
    'label' => 'Authorization from contributors to the [specific network] catalogues',
    'weight' => '16',
    'children' => array(
      0 => 'field_authorising_date',
      1 => 'field_authorising_person_name',
      2 => 'field_authorization_specific',
    ),
    'format_type' => 'hidden',
    'format_settings' => array(
      'label' => 'Authorization from contributors to the [specific network] catalogues',
      'instance_settings' => array(
        'classes' => '',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h2',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_authorization_specific|node|study|center_area'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_authorization_specific|node|study|default';
  $field_group->group_name = 'group_authorization_specific';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'study';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_authorization';
  $field_group->data = array(
    'label' => 'Authorization from contributors to the [specific network] catalogues',
    'weight' => '16',
    'children' => array(
      0 => 'field_authorising_date',
      1 => 'field_authorising_person_name',
      2 => 'field_authorization_specific',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Authorization from contributors to the [specific network] catalogues',
      'instance_settings' => array(
        'classes' => '',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h2',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_authorization_specific|node|study|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_authorization_specific|node|study|footer_area';
  $field_group->group_name = 'group_authorization_specific';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'study';
  $field_group->mode = 'footer_area';
  $field_group->parent_name = 'group_authorization';
  $field_group->data = array(
    'label' => 'Authorization from contributors to the [specific network] catalogues',
    'weight' => '16',
    'children' => array(
      0 => 'group_authorising_person',
    ),
    'format_type' => 'hidden',
    'format_settings' => array(
      'label' => 'Authorization from contributors to the [specific network] catalogues',
      'instance_settings' => array(
        'classes' => '',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h2',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_authorization_specific|node|study|footer_area'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_authorization_specific|node|study|form';
  $field_group->group_name = 'group_authorization_specific';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'study';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_authorization';
  $field_group->data = array(
    'label' => 'Authorization from contributors to the [specific network] catalogues',
    'weight' => '16',
    'children' => array(
      0 => 'field_authorising_date',
      1 => 'field_authorising_person_name',
      2 => 'field_authorization_specific',
      3 => 'group_authorising_person',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Authorization from contributors to the [specific network] catalogues',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => 'I agree and understand that the information collected in this form will be displayed on the [SPECIFIC NETWORK] website upon reception.',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_authorization_specific|node|study|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_authorization_specific|node|study|left_area';
  $field_group->group_name = 'group_authorization_specific';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'study';
  $field_group->mode = 'left_area';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Authorization from contributors to the [specific network] catalogues',
    'weight' => '5',
    'children' => array(),
    'format_type' => 'hidden',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(),
    ),
  );
  $export['group_authorization_specific|node|study|left_area'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_authorization_specific|node|study|right_area';
  $field_group->group_name = 'group_authorization_specific';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'study';
  $field_group->mode = 'right_area';
  $field_group->parent_name = 'group_authorization';
  $field_group->data = array(
    'label' => 'Authorization from contributors to the [specific network] catalogues',
    'weight' => '16',
    'children' => array(
      0 => 'field_authorising_date',
      1 => 'field_authorising_person_name',
      2 => 'field_authorization_specific',
      3 => 'group_authorising_person',
    ),
    'format_type' => 'hidden',
    'format_settings' => array(
      'label' => 'Authorization from contributors to the [specific network] catalogues',
      'instance_settings' => array(
        'classes' => '',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h2',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_authorization_specific|node|study|right_area'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_authorizations|node|study|footer_area';
  $field_group->group_name = 'group_authorizations';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'study';
  $field_group->mode = 'footer_area';
  $field_group->parent_name = 'group_tabs';
  $field_group->data = array(
    'label' => 'Authorizations',
    'weight' => '0',
    'children' => array(
      0 => 'field_authorising_date',
      1 => 'field_authorising_date_m',
      2 => 'field_authorising_person_name',
      3 => 'field_authorising_person_name_m',
      4 => 'field_authorization_maelstrom',
      5 => 'field_authorization_specific',
    ),
    'format_type' => 'hidden',
    'format_settings' => array(
      'formatter' => 'open',
      'instance_settings' => array(
        'description' => '',
        'show_label' => 1,
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
        'classes' => '',
      ),
    ),
  );
  $export['group_authorizations|node|study|footer_area'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_authorization|node|study|center_area';
  $field_group->group_name = 'group_authorization';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'study';
  $field_group->mode = 'center_area';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Authorization',
    'weight' => '15',
    'children' => array(
      0 => 'group_authorization_maelstrom',
      1 => 'group_authorization_specific',
    ),
    'format_type' => 'hidden',
    'format_settings' => array(
      'formatter' => 'open',
      'instance_settings' => array(
        'description' => '',
        'show_label' => 1,
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
        'classes' => '',
      ),
    ),
  );
  $export['group_authorization|node|study|center_area'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_authorization|node|study|default';
  $field_group->group_name = 'group_authorization';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'study';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_tabs';
  $field_group->data = array(
    'label' => 'Authorization',
    'weight' => '86',
    'children' => array(
      0 => 'group_authorization_maelstrom',
      1 => 'group_authorization_specific',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'label' => 'Authorization',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'closed',
    ),
  );
  $export['group_authorization|node|study|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_authorization|node|study|footer_area';
  $field_group->group_name = 'group_authorization';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'study';
  $field_group->mode = 'footer_area';
  $field_group->parent_name = 'group_tabs';
  $field_group->data = array(
    'label' => 'Authorization',
    'weight' => '86',
    'children' => array(
      0 => 'group_authorization_maelstrom',
      1 => 'group_authorization_specific',
    ),
    'format_type' => 'hidden',
    'format_settings' => array(
      'label' => 'Authorization',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'closed',
    ),
  );
  $export['group_authorization|node|study|footer_area'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_authorization|node|study|form';
  $field_group->group_name = 'group_authorization';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'study';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_tabs';
  $field_group->data = array(
    'label' => 'Authorization',
    'weight' => '7',
    'children' => array(
      0 => 'group_authorization_maelstrom',
      1 => 'group_authorization_specific',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'label' => 'Authorization',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'closed',
    ),
  );
  $export['group_authorization|node|study|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_authorization|node|study|left_area';
  $field_group->group_name = 'group_authorization';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'study';
  $field_group->mode = 'left_area';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Authorization',
    'weight' => '4',
    'children' => array(
      0 => 'field_authorising_date',
      1 => 'field_authorising_date_m',
      2 => 'field_authorising_person_name',
      3 => 'field_authorising_person_name_m',
      4 => 'field_authorization_maelstrom',
      5 => 'field_authorization_specific',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'open',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
      ),
    ),
  );
  $export['group_authorization|node|study|left_area'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_authorization|node|study|right_area';
  $field_group->group_name = 'group_authorization';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'study';
  $field_group->mode = 'right_area';
  $field_group->parent_name = 'group_tabs';
  $field_group->data = array(
    'label' => 'Authorization',
    'weight' => '86',
    'children' => array(
      0 => 'group_authorization_maelstrom',
      1 => 'group_authorization_specific',
    ),
    'format_type' => 'hidden',
    'format_settings' => array(
      'label' => 'Authorization',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'closed',
    ),
  );
  $export['group_authorization|node|study|right_area'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_baseline_phase|node|study|center_area';
  $field_group->group_name = 'group_baseline_phase';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'study';
  $field_group->mode = 'center_area';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Baseline recruitment / initial data collection',
    'weight' => '7',
    'children' => array(),
    'format_type' => 'hidden',
    'format_settings' => array(
      'formatter' => 'open',
      'instance_settings' => array(
        'description' => '',
        'show_label' => 1,
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
        'classes' => '',
      ),
    ),
  );
  $export['group_baseline_phase|node|study|center_area'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_baseline_phase|node|study|default';
  $field_group->group_name = 'group_baseline_phase';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'study';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_status';
  $field_group->data = array(
    'label' => 'Baseline recruitment / initial data collection',
    'weight' => '50',
    'children' => array(
      0 => 'field_baseline_end_year',
      1 => 'field_baseline_start_year',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'formatter' => 'open',
      'instance_settings' => array(
        'description' => '',
        'show_label' => 1,
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
        'classes' => '',
      ),
    ),
  );
  $export['group_baseline_phase|node|study|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_baseline_phase|node|study|footer_area';
  $field_group->group_name = 'group_baseline_phase';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'study';
  $field_group->mode = 'footer_area';
  $field_group->parent_name = 'group_status';
  $field_group->data = array(
    'label' => 'Baseline recruitment / initial data collection',
    'weight' => '50',
    'children' => array(
      0 => 'field_baseline_end_year',
      1 => 'field_baseline_start_year',
    ),
    'format_type' => 'hidden',
    'format_settings' => array(
      'formatter' => 'open',
      'instance_settings' => array(
        'description' => '',
        'show_label' => 1,
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
        'classes' => '',
      ),
    ),
  );
  $export['group_baseline_phase|node|study|footer_area'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_baseline_phase|node|study|form';
  $field_group->group_name = 'group_baseline_phase';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'study';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_current_status';
  $field_group->data = array(
    'label' => 'Baseline recruitment / initial data collection',
    'weight' => '57',
    'children' => array(
      0 => 'field_baseline_end_year',
      1 => 'field_baseline_start_year',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Baseline recruitment / initial data collection',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_baseline_phase|node|study|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_baseline_phase|node|study|left_area';
  $field_group->group_name = 'group_baseline_phase';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'study';
  $field_group->mode = 'left_area';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Baseline recruitment / initial data collection',
    'weight' => '23',
    'children' => array(),
    'format_type' => 'hidden',
    'format_settings' => array(
      'formatter' => 'open',
      'instance_settings' => array(
        'description' => '',
        'show_label' => 1,
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
        'classes' => '',
      ),
    ),
  );
  $export['group_baseline_phase|node|study|left_area'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_baseline_phase|node|study|right_area';
  $field_group->group_name = 'group_baseline_phase';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'study';
  $field_group->mode = 'right_area';
  $field_group->parent_name = 'group_status';
  $field_group->data = array(
    'label' => 'Baseline recruitment / initial data collection',
    'weight' => '50',
    'children' => array(
      0 => 'field_baseline_end_year',
      1 => 'field_baseline_start_year',
    ),
    'format_type' => 'hidden',
    'format_settings' => array(
      'formatter' => 'open',
      'instance_settings' => array(
        'description' => '',
        'show_label' => 1,
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
        'classes' => '',
      ),
    ),
  );
  $export['group_baseline_phase|node|study|right_area'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_countries|node|study|center_area';
  $field_group->group_name = 'group_countries';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'study';
  $field_group->mode = 'center_area';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Please specify countries of residence',
    'weight' => '33',
    'children' => array(),
    'format_type' => 'hidden',
    'format_settings' => array(
      'formatter' => 'open',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_countries|node|study|center_area'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_countries|node|study|default';
  $field_group->group_name = 'group_countries';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'study';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_participants_selection';
  $field_group->data = array(
    'label' => 'Please specify countries of residence',
    'weight' => '48',
    'children' => array(),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'open',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_countries|node|study|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_countries|node|study|footer_area';
  $field_group->group_name = 'group_countries';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'study';
  $field_group->mode = 'footer_area';
  $field_group->parent_name = 'group_participants_selection';
  $field_group->data = array(
    'label' => 'Please specify countries of residence',
    'weight' => '48',
    'children' => array(),
    'format_type' => 'hidden',
    'format_settings' => array(
      'formatter' => 'open',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_countries|node|study|footer_area'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_countries|node|study|form';
  $field_group->group_name = 'group_countries';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'study';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_selection_criteria';
  $field_group->data = array(
    'label' => 'Please specify countries of residence',
    'weight' => '72',
    'children' => array(
      0 => 'field_country',
      1 => 'field_territory',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'open',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_countries|node|study|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_countries|node|study|right_area';
  $field_group->group_name = 'group_countries';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'study';
  $field_group->mode = 'right_area';
  $field_group->parent_name = 'group_participants_selection';
  $field_group->data = array(
    'label' => 'Please specify countries of residence',
    'weight' => '48',
    'children' => array(),
    'format_type' => 'hidden',
    'format_settings' => array(
      'formatter' => 'open',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_countries|node|study|right_area'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_current_number_samples|node|study|center_area';
  $field_group->group_name = 'group_current_number_samples';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'study';
  $field_group->mode = 'center_area';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Current number of collected biological samples from which DNA could be extracted',
    'weight' => '31',
    'children' => array(),
    'format_type' => 'hidden',
    'format_settings' => array(
      'formatter' => 'open',
      'instance_settings' => array(
        'description' => '',
        'show_label' => 1,
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
        'classes' => '',
      ),
    ),
  );
  $export['group_current_number_samples|node|study|center_area'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_current_number_samples|node|study|default';
  $field_group->group_name = 'group_current_number_samples';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'study';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_general_design';
  $field_group->data = array(
    'label' => 'Current number of collected biological samples from which DNA could be extracted',
    'weight' => '47',
    'children' => array(),
    'format_type' => 'div',
    'format_settings' => array(
      'formatter' => 'open',
      'instance_settings' => array(
        'description' => '',
        'show_label' => 1,
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
        'classes' => '',
      ),
    ),
  );
  $export['group_current_number_samples|node|study|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_current_number_samples|node|study|footer_area';
  $field_group->group_name = 'group_current_number_samples';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'study';
  $field_group->mode = 'footer_area';
  $field_group->parent_name = 'group_general_design';
  $field_group->data = array(
    'label' => 'Current number of collected biological samples from which DNA could be extracted',
    'weight' => '47',
    'children' => array(),
    'format_type' => 'hidden',
    'format_settings' => array(
      'formatter' => 'open',
      'instance_settings' => array(
        'description' => '',
        'show_label' => 1,
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
        'classes' => '',
      ),
    ),
  );
  $export['group_current_number_samples|node|study|footer_area'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_current_number_samples|node|study|form';
  $field_group->group_name = 'group_current_number_samples';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'study';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_general_design';
  $field_group->data = array(
    'label' => 'Current number of collected biological samples from which DNA could be extracted',
    'weight' => '13',
    'children' => array(
      0 => 'field_current_sam_supp_info',
      1 => 'field_current_samples_date',
      2 => 'field_current_samples_nb',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'open',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_current_number_samples|node|study|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_current_number_samples|node|study|right_area';
  $field_group->group_name = 'group_current_number_samples';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'study';
  $field_group->mode = 'right_area';
  $field_group->parent_name = 'group_general_design';
  $field_group->data = array(
    'label' => 'Current number of collected biological samples from which DNA could be extracted',
    'weight' => '47',
    'children' => array(),
    'format_type' => 'hidden',
    'format_settings' => array(
      'formatter' => 'open',
      'instance_settings' => array(
        'description' => '',
        'show_label' => 1,
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
        'classes' => '',
      ),
    ),
  );
  $export['group_current_number_samples|node|study|right_area'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_current_number|node|study|center_area';
  $field_group->group_name = 'group_current_number';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'study';
  $field_group->mode = 'center_area';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Current number of participants recruited at baseline',
    'weight' => '30',
    'children' => array(),
    'format_type' => 'hidden',
    'format_settings' => array(
      'formatter' => 'open',
      'instance_settings' => array(
        'description' => '',
        'show_label' => 1,
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
        'classes' => '',
      ),
    ),
  );
  $export['group_current_number|node|study|center_area'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_current_number|node|study|default';
  $field_group->group_name = 'group_current_number';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'study';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_general_design';
  $field_group->data = array(
    'label' => 'Current number of participants recruited at baseline',
    'weight' => '46',
    'children' => array(),
    'format_type' => 'div',
    'format_settings' => array(
      'formatter' => 'open',
      'instance_settings' => array(
        'description' => '',
        'show_label' => 1,
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
        'classes' => '',
      ),
    ),
  );
  $export['group_current_number|node|study|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_current_number|node|study|footer_area';
  $field_group->group_name = 'group_current_number';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'study';
  $field_group->mode = 'footer_area';
  $field_group->parent_name = 'group_general_design';
  $field_group->data = array(
    'label' => 'Current number of participants recruited at baseline',
    'weight' => '46',
    'children' => array(),
    'format_type' => 'hidden',
    'format_settings' => array(
      'formatter' => 'open',
      'instance_settings' => array(
        'description' => '',
        'show_label' => 1,
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
        'classes' => '',
      ),
    ),
  );
  $export['group_current_number|node|study|footer_area'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_current_number|node|study|form';
  $field_group->group_name = 'group_current_number';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'study';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_general_design';
  $field_group->data = array(
    'label' => 'Current number of participants recruited at baseline',
    'weight' => '12',
    'children' => array(
      0 => 'field_current_part_nb_date',
      1 => 'field_current_participants_nb',
      2 => 'field_current_supp_info',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'open',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_current_number|node|study|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_current_number|node|study|right_area';
  $field_group->group_name = 'group_current_number';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'study';
  $field_group->mode = 'right_area';
  $field_group->parent_name = 'group_general_design';
  $field_group->data = array(
    'label' => 'Current number of participants recruited at baseline',
    'weight' => '46',
    'children' => array(),
    'format_type' => 'hidden',
    'format_settings' => array(
      'formatter' => 'open',
      'instance_settings' => array(
        'description' => '',
        'show_label' => 1,
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
        'classes' => '',
      ),
    ),
  );
  $export['group_current_number|node|study|right_area'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_current_status|node|study|center_area';
  $field_group->group_name = 'group_current_status';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'study';
  $field_group->mode = 'center_area';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Current Status',
    'weight' => '10',
    'children' => array(),
    'format_type' => 'hidden',
    'format_settings' => array(
      'label' => 'Current Status',
      'instance_settings' => array(
        'classes' => '',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h2',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_current_status|node|study|center_area'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_current_status|node|study|default';
  $field_group->group_name = 'group_current_status';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'study';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_status';
  $field_group->data = array(
    'label' => 'Current Status',
    'weight' => '55',
    'children' => array(),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Current Status',
      'instance_settings' => array(
        'classes' => '',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h2',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_current_status|node|study|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_current_status|node|study|footer_area';
  $field_group->group_name = 'group_current_status';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'study';
  $field_group->mode = 'footer_area';
  $field_group->parent_name = 'group_status';
  $field_group->data = array(
    'label' => 'Current Status',
    'weight' => '55',
    'children' => array(),
    'format_type' => 'hidden',
    'format_settings' => array(
      'label' => 'Current Status',
      'instance_settings' => array(
        'classes' => '',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h2',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_current_status|node|study|footer_area'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_current_status|node|study|form';
  $field_group->group_name = 'group_current_status';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'study';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_status';
  $field_group->data = array(
    'label' => 'Current Status',
    'weight' => '87',
    'children' => array(
      0 => 'field_status_supp_info',
      1 => 'group_baseline_phase',
      2 => 'group_ended_phase',
      3 => 'group_followup_phase',
      4 => 'group_preparation_phase',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Current Status',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => 'What are the stages and timelines of the study?',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_current_status|node|study|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_current_status|node|study|left_area';
  $field_group->group_name = 'group_current_status';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'study';
  $field_group->mode = 'left_area';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Current Status',
    'weight' => '26',
    'children' => array(),
    'format_type' => 'hidden',
    'format_settings' => array(
      'label' => 'Current Status',
      'instance_settings' => array(
        'classes' => '',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h2',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_current_status|node|study|left_area'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_current_status|node|study|right_area';
  $field_group->group_name = 'group_current_status';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'study';
  $field_group->mode = 'right_area';
  $field_group->parent_name = 'group_status';
  $field_group->data = array(
    'label' => 'Current Status',
    'weight' => '55',
    'children' => array(),
    'format_type' => 'hidden',
    'format_settings' => array(
      'label' => 'Current Status',
      'instance_settings' => array(
        'classes' => '',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h2',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_current_status|node|study|right_area'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_data_collection|node|study|center_area';
  $field_group->group_name = 'group_data_collection';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'study';
  $field_group->mode = 'center_area';
  $field_group->parent_name = 'group_methods';
  $field_group->data = array(
    'label' => 'Data Collection',
    'weight' => '68',
    'children' => array(
      0 => 'field_data_sources',
      1 => 'field_data_sources_sp',
    ),
    'format_type' => 'hidden',
    'format_settings' => array(
      'label' => 'Data Collection',
      'instance_settings' => array(
        'classes' => '',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h2',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_data_collection|node|study|center_area'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_data_collection|node|study|default';
  $field_group->group_name = 'group_data_collection';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'study';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_methods';
  $field_group->data = array(
    'label' => 'Data Collection',
    'weight' => '68',
    'children' => array(
      0 => 'field_data_sources',
      1 => 'field_data_sources_sp',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Data Collection',
      'instance_settings' => array(
        'classes' => '',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h2',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_data_collection|node|study|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_data_collection|node|study|footer_area';
  $field_group->group_name = 'group_data_collection';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'study';
  $field_group->mode = 'footer_area';
  $field_group->parent_name = 'group_methods';
  $field_group->data = array(
    'label' => 'Data Collection',
    'weight' => '68',
    'children' => array(
      0 => 'field_data_sources',
      1 => 'field_data_sources_sp',
    ),
    'format_type' => 'hidden',
    'format_settings' => array(
      'label' => 'Data Collection',
      'instance_settings' => array(
        'classes' => '',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h2',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_data_collection|node|study|footer_area'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_data_collection|node|study|form';
  $field_group->group_name = 'group_data_collection';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'study';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_methods';
  $field_group->data = array(
    'label' => 'Data Collection',
    'weight' => '69',
    'children' => array(
      0 => 'field_data_sources',
      1 => 'field_data_sources_sp',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Data Collection',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_data_collection|node|study|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_data_collection|node|study|left_area';
  $field_group->group_name = 'group_data_collection';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'study';
  $field_group->mode = 'left_area';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Data Collection',
    'weight' => '1',
    'children' => array(
      0 => 'field_data_sources',
      1 => 'field_data_sources_sp',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'open',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
      ),
    ),
  );
  $export['group_data_collection|node|study|left_area'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_data_collection|node|study|right_area';
  $field_group->group_name = 'group_data_collection';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'study';
  $field_group->mode = 'right_area';
  $field_group->parent_name = 'group_methods';
  $field_group->data = array(
    'label' => 'Data Collection',
    'weight' => '68',
    'children' => array(
      0 => 'field_data_sources',
      1 => 'field_data_sources_sp',
    ),
    'format_type' => 'hidden',
    'format_settings' => array(
      'label' => 'Data Collection',
      'instance_settings' => array(
        'classes' => '',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h2',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_data_collection|node|study|right_area'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_documents|node|study|center_area';
  $field_group->group_name = 'group_documents';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'study';
  $field_group->mode = 'center_area';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Documents',
    'weight' => '3',
    'children' => array(
      0 => 'field_documents',
    ),
    'format_type' => 'hidden',
    'format_settings' => array(
      'formatter' => 'open',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
      ),
    ),
  );
  $export['group_documents|node|study|center_area'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_documents|node|study|default';
  $field_group->group_name = 'group_documents';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'study';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_tabs';
  $field_group->data = array(
    'label' => 'Documents',
    'weight' => '91',
    'children' => array(
      0 => 'field_documents',
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
  $export['group_documents|node|study|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_documents|node|study|footer_area';
  $field_group->group_name = 'group_documents';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'study';
  $field_group->mode = 'footer_area';
  $field_group->parent_name = 'group_tabs';
  $field_group->data = array(
    'label' => 'Documents',
    'weight' => '91',
    'children' => array(
      0 => 'field_documents',
    ),
    'format_type' => 'hidden',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
      ),
    ),
  );
  $export['group_documents|node|study|footer_area'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_documents|node|study|form';
  $field_group->group_name = 'group_documents';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'study';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_tabs';
  $field_group->data = array(
    'label' => 'Documents',
    'weight' => '13',
    'children' => array(
      0 => 'field_documents',
      1 => 'field_logo',
      2 => 'field_questionnaires',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_documents|node|study|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_documents|node|study|left_area';
  $field_group->group_name = 'group_documents';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'study';
  $field_group->mode = 'left_area';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Documents',
    'weight' => '19',
    'children' => array(),
    'format_type' => 'hidden',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
      ),
    ),
  );
  $export['group_documents|node|study|left_area'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_documents|node|study|right_area';
  $field_group->group_name = 'group_documents';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'study';
  $field_group->mode = 'right_area';
  $field_group->parent_name = 'group_tabs';
  $field_group->data = array(
    'label' => 'Documents',
    'weight' => '91',
    'children' => array(),
    'format_type' => 'hidden',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
      ),
    ),
  );
  $export['group_documents|node|study|right_area'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_ended_phase|node|study|center_area';
  $field_group->group_name = 'group_ended_phase';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'study';
  $field_group->mode = 'center_area';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Study ended',
    'weight' => '9',
    'children' => array(),
    'format_type' => 'hidden',
    'format_settings' => array(
      'formatter' => 'open',
      'instance_settings' => array(
        'description' => '',
        'show_label' => 1,
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
        'classes' => '',
      ),
    ),
  );
  $export['group_ended_phase|node|study|center_area'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_ended_phase|node|study|default';
  $field_group->group_name = 'group_ended_phase';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'study';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_status';
  $field_group->data = array(
    'label' => 'Study ended',
    'weight' => '53',
    'children' => array(
      0 => 'field_ended_end_year',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'formatter' => 'open',
      'instance_settings' => array(
        'description' => '',
        'show_label' => 1,
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
        'classes' => '',
      ),
    ),
  );
  $export['group_ended_phase|node|study|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_ended_phase|node|study|footer_area';
  $field_group->group_name = 'group_ended_phase';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'study';
  $field_group->mode = 'footer_area';
  $field_group->parent_name = 'group_status';
  $field_group->data = array(
    'label' => 'Study ended',
    'weight' => '53',
    'children' => array(
      0 => 'field_ended_end_year',
    ),
    'format_type' => 'hidden',
    'format_settings' => array(
      'formatter' => 'open',
      'instance_settings' => array(
        'description' => '',
        'show_label' => 1,
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
        'classes' => '',
      ),
    ),
  );
  $export['group_ended_phase|node|study|footer_area'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_ended_phase|node|study|form';
  $field_group->group_name = 'group_ended_phase';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'study';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_current_status';
  $field_group->data = array(
    'label' => 'Study ended',
    'weight' => '59',
    'children' => array(
      0 => 'field_ended_end_year',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Study ended',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_ended_phase|node|study|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_ended_phase|node|study|left_area';
  $field_group->group_name = 'group_ended_phase';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'study';
  $field_group->mode = 'left_area';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Study ended',
    'weight' => '25',
    'children' => array(),
    'format_type' => 'hidden',
    'format_settings' => array(
      'formatter' => 'open',
      'instance_settings' => array(
        'description' => '',
        'show_label' => 1,
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
        'classes' => '',
      ),
    ),
  );
  $export['group_ended_phase|node|study|left_area'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_ended_phase|node|study|right_area';
  $field_group->group_name = 'group_ended_phase';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'study';
  $field_group->mode = 'right_area';
  $field_group->parent_name = 'group_status';
  $field_group->data = array(
    'label' => 'Study ended',
    'weight' => '53',
    'children' => array(
      0 => 'field_ended_end_year',
    ),
    'format_type' => 'hidden',
    'format_settings' => array(
      'formatter' => 'open',
      'instance_settings' => array(
        'description' => '',
        'show_label' => 1,
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
        'classes' => '',
      ),
    ),
  );
  $export['group_ended_phase|node|study|right_area'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_ethnic_origin|node|study|center_area';
  $field_group->group_name = 'group_ethnic_origin';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'study';
  $field_group->mode = 'center_area';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Please specify ethnic origin',
    'weight' => '34',
    'children' => array(),
    'format_type' => 'hidden',
    'format_settings' => array(
      'formatter' => 'open',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_ethnic_origin|node|study|center_area'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_ethnic_origin|node|study|default';
  $field_group->group_name = 'group_ethnic_origin';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'study';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_participants_selection';
  $field_group->data = array(
    'label' => 'Please specify ethnic origin',
    'weight' => '49',
    'children' => array(),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'open',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_ethnic_origin|node|study|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_ethnic_origin|node|study|footer_area';
  $field_group->group_name = 'group_ethnic_origin';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'study';
  $field_group->mode = 'footer_area';
  $field_group->parent_name = 'group_participants_selection';
  $field_group->data = array(
    'label' => 'Please specify ethnic origin',
    'weight' => '49',
    'children' => array(),
    'format_type' => 'hidden',
    'format_settings' => array(
      'formatter' => 'open',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_ethnic_origin|node|study|footer_area'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_ethnic_origin|node|study|right_area';
  $field_group->group_name = 'group_ethnic_origin';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'study';
  $field_group->mode = 'right_area';
  $field_group->parent_name = 'group_participants_selection';
  $field_group->data = array(
    'label' => 'Please specify ethnic origin',
    'weight' => '49',
    'children' => array(),
    'format_type' => 'hidden',
    'format_settings' => array(
      'formatter' => 'open',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_ethnic_origin|node|study|right_area'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_followup_phase|node|study|center_area';
  $field_group->group_name = 'group_followup_phase';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'study';
  $field_group->mode = 'center_area';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'If applicable, Follow-up of participants',
    'weight' => '8',
    'children' => array(),
    'format_type' => 'hidden',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(),
    ),
  );
  $export['group_followup_phase|node|study|center_area'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_followup_phase|node|study|default';
  $field_group->group_name = 'group_followup_phase';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'study';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_status';
  $field_group->data = array(
    'label' => 'If applicable, Follow-up of participants',
    'weight' => '51',
    'children' => array(
      0 => 'field_followup_end_year',
      1 => 'field_followup_start_year',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'formatter' => 'open',
      'instance_settings' => array(
        'description' => '',
        'show_label' => 1,
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
        'classes' => '',
      ),
    ),
  );
  $export['group_followup_phase|node|study|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_followup_phase|node|study|footer_area';
  $field_group->group_name = 'group_followup_phase';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'study';
  $field_group->mode = 'footer_area';
  $field_group->parent_name = 'group_status';
  $field_group->data = array(
    'label' => 'If applicable, Follow-up of participants',
    'weight' => '51',
    'children' => array(
      0 => 'field_followup_end_year',
      1 => 'field_followup_start_year',
    ),
    'format_type' => 'hidden',
    'format_settings' => array(
      'formatter' => 'open',
      'instance_settings' => array(
        'description' => '',
        'show_label' => 1,
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
        'classes' => '',
      ),
    ),
  );
  $export['group_followup_phase|node|study|footer_area'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_followup_phase|node|study|form';
  $field_group->group_name = 'group_followup_phase';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'study';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_current_status';
  $field_group->data = array(
    'label' => 'If applicable, Follow-up of participants',
    'weight' => '58',
    'children' => array(
      0 => 'field_followup_end_year',
      1 => 'field_followup_start_year',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'If applicable, Follow-up of participants',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_followup_phase|node|study|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_followup_phase|node|study|left_area';
  $field_group->group_name = 'group_followup_phase';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'study';
  $field_group->mode = 'left_area';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'If applicable, Follow-up of participants',
    'weight' => '24',
    'children' => array(),
    'format_type' => 'hidden',
    'format_settings' => array(
      'formatter' => 'open',
      'instance_settings' => array(
        'description' => '',
        'show_label' => 1,
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
        'classes' => '',
      ),
    ),
  );
  $export['group_followup_phase|node|study|left_area'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_followup_phase|node|study|right_area';
  $field_group->group_name = 'group_followup_phase';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'study';
  $field_group->mode = 'right_area';
  $field_group->parent_name = 'group_status';
  $field_group->data = array(
    'label' => 'If applicable, Follow-up of participants',
    'weight' => '51',
    'children' => array(
      0 => 'field_followup_end_year',
      1 => 'field_followup_start_year',
    ),
    'format_type' => 'hidden',
    'format_settings' => array(
      'formatter' => 'open',
      'instance_settings' => array(
        'description' => '',
        'show_label' => 1,
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
        'classes' => '',
      ),
    ),
  );
  $export['group_followup_phase|node|study|right_area'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_general_design|node|study|center_area';
  $field_group->group_name = 'group_general_design';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'study';
  $field_group->mode = 'center_area';
  $field_group->parent_name = 'group_methods';
  $field_group->data = array(
    'label' => 'General Design',
    'weight' => '66',
    'children' => array(
      0 => 'field_design',
      1 => 'field_design_other_sp',
      2 => 'field_no_limits_participants',
      3 => 'field_no_limits_samples',
      4 => 'field_recruitment',
      5 => 'field_recruitment_other_sp',
      6 => 'field_recruitment_supp_info',
      7 => 'field_samples_supp_info',
      8 => 'field_target_nb_supp_info',
      9 => 'field_target_number_biosamples',
      10 => 'field_target_number_participants',
    ),
    'format_type' => 'hidden',
    'format_settings' => array(
      'label' => 'General Design',
      'instance_settings' => array(
        'classes' => '',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h2',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_general_design|node|study|center_area'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_general_design|node|study|default';
  $field_group->group_name = 'group_general_design';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'study';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_methods';
  $field_group->data = array(
    'label' => 'General Design',
    'weight' => '66',
    'children' => array(
      0 => 'field_design',
      1 => 'field_design_other_sp',
      2 => 'field_no_limits_participants',
      3 => 'field_no_limits_samples',
      4 => 'field_recruitment',
      5 => 'field_recruitment_other_sp',
      6 => 'field_recruitment_supp_info',
      7 => 'field_samples_supp_info',
      8 => 'field_target_nb_supp_info',
      9 => 'field_target_number_biosamples',
      10 => 'field_target_number_participants',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'General Design',
      'instance_settings' => array(
        'classes' => '',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h2',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_general_design|node|study|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_general_design|node|study|footer_area';
  $field_group->group_name = 'group_general_design';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'study';
  $field_group->mode = 'footer_area';
  $field_group->parent_name = 'group_methods';
  $field_group->data = array(
    'label' => 'General Design',
    'weight' => '66',
    'children' => array(
      0 => 'field_current_part_nb_date',
      1 => 'field_current_participants_nb',
      2 => 'field_current_sam_supp_info',
      3 => 'field_current_samples_date',
      4 => 'field_current_samples_nb',
      5 => 'field_current_supp_info',
      6 => 'field_design',
      7 => 'field_design_other_sp',
      8 => 'field_no_limits_participants',
      9 => 'field_no_limits_samples',
      10 => 'field_recruitment',
      11 => 'field_recruitment_other_sp',
      12 => 'field_recruitment_supp_info',
      13 => 'field_samples_supp_info',
      14 => 'field_target_nb_supp_info',
      15 => 'field_target_number_biosamples',
      16 => 'field_target_number_participants',
      17 => 'group_current_number_samples',
      18 => 'group_current_number',
      19 => 'group_study_design',
      20 => 'group_target_nb_participants',
      21 => 'group_target_nb_samples',
    ),
    'format_type' => 'hidden',
    'format_settings' => array(
      'label' => 'General Design',
      'instance_settings' => array(
        'classes' => '',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h2',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_general_design|node|study|footer_area'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_general_design|node|study|form';
  $field_group->group_name = 'group_general_design';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'study';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_methods';
  $field_group->data = array(
    'label' => 'General Design',
    'weight' => '66',
    'children' => array(
      0 => 'group_current_number_samples',
      1 => 'group_current_number',
      2 => 'group_study_design',
      3 => 'group_target_nb_participants',
      4 => 'group_target_nb_samples',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'open',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_general_design|node|study|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_general_design|node|study|left_area';
  $field_group->group_name = 'group_general_design';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'study';
  $field_group->mode = 'left_area';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'General Design',
    'weight' => '0',
    'children' => array(
      0 => 'field_design',
      1 => 'field_design_other_sp',
      2 => 'field_no_limits_participants',
      3 => 'field_no_limits_samples',
      4 => 'field_recruitment',
      5 => 'field_recruitment_other_sp',
      6 => 'field_target_number_biosamples',
      7 => 'field_target_number_participants',
      8 => 'group_more_design',
      9 => 'group_more_target_participant',
      10 => 'group_more_target_samples',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'open',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
      ),
    ),
  );
  $export['group_general_design|node|study|left_area'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_general_design|node|study|right_area';
  $field_group->group_name = 'group_general_design';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'study';
  $field_group->mode = 'right_area';
  $field_group->parent_name = 'group_methods';
  $field_group->data = array(
    'label' => 'General Design',
    'weight' => '66',
    'children' => array(
      0 => 'field_current_part_nb_date',
      1 => 'field_current_participants_nb',
      2 => 'field_current_sam_supp_info',
      3 => 'field_current_samples_date',
      4 => 'field_current_samples_nb',
      5 => 'field_current_supp_info',
      6 => 'field_design',
      7 => 'field_design_other_sp',
      8 => 'field_no_limits_participants',
      9 => 'field_no_limits_samples',
      10 => 'field_recruitment',
      11 => 'field_recruitment_other_sp',
      12 => 'field_recruitment_supp_info',
      13 => 'field_samples_supp_info',
      14 => 'field_target_nb_supp_info',
      15 => 'field_target_number_biosamples',
      16 => 'field_target_number_participants',
      17 => 'group_current_number_samples',
      18 => 'group_current_number',
      19 => 'group_study_design',
      20 => 'group_target_nb_participants',
      21 => 'group_target_nb_samples',
    ),
    'format_type' => 'hidden',
    'format_settings' => array(
      'label' => 'General Design',
      'instance_settings' => array(
        'classes' => '',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h2',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_general_design|node|study|right_area'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_general_design|node|study|summary_left_area';
  $field_group->group_name = 'group_general_design';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'study';
  $field_group->mode = 'summary_left_area';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'General Design',
    'weight' => '0',
    'children' => array(
      0 => 'field_design',
      1 => 'field_design_other_sp',
      2 => 'field_no_limits_participants',
      3 => 'field_no_limits_samples',
      4 => 'field_target_number_biosamples',
      5 => 'field_target_number_participants',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'open',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
      ),
    ),
  );
  $export['group_general_design|node|study|summary_left_area'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_general_info|node|study|center_area';
  $field_group->group_name = 'group_general_info';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'study';
  $field_group->mode = 'center_area';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'General Information',
    'weight' => '17',
    'children' => array(),
    'format_type' => 'hidden',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(),
    ),
  );
  $export['group_general_info|node|study|center_area'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_general_info|node|study|default';
  $field_group->group_name = 'group_general_info';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'study';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_tabs';
  $field_group->data = array(
    'label' => 'General Information',
    'weight' => '85',
    'children' => array(
      0 => 'body',
      1 => 'field_acroym',
      2 => 'field_contacts_ref',
      3 => 'field_investigators',
      4 => 'field_logo',
      5 => 'field_website',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'open',
      'instance_settings' => array(
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_general_info|node|study|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_general_info|node|study|footer_area';
  $field_group->group_name = 'group_general_info';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'study';
  $field_group->mode = 'footer_area';
  $field_group->parent_name = 'group_tabs';
  $field_group->data = array(
    'label' => 'General Information',
    'weight' => '85',
    'children' => array(
      0 => 'body',
      1 => 'field_acroym',
      2 => 'field_contacts_ref',
      3 => 'field_investigators',
      4 => 'field_logo',
      5 => 'field_website',
    ),
    'format_type' => 'hidden',
    'format_settings' => array(
      'formatter' => 'open',
      'instance_settings' => array(
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_general_info|node|study|footer_area'] = $field_group;

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
      4 => 'group_study_name',
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
  $field_group->identifier = 'group_general_info|node|study|left_area';
  $field_group->group_name = 'group_general_info';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'study';
  $field_group->mode = 'left_area';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'General Information',
    'weight' => '9',
    'children' => array(
      0 => 'body',
      1 => 'field_acroym',
      2 => 'field_logo',
      3 => 'field_website',
    ),
    'format_type' => 'hidden',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(),
    ),
  );
  $export['group_general_info|node|study|left_area'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_general_info|node|study|right_area';
  $field_group->group_name = 'group_general_info';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'study';
  $field_group->mode = 'right_area';
  $field_group->parent_name = 'group_tabs';
  $field_group->data = array(
    'label' => 'General Information',
    'weight' => '85',
    'children' => array(
      0 => 'body',
      1 => 'field_logo',
    ),
    'format_type' => 'hidden',
    'format_settings' => array(
      'formatter' => 'open',
      'instance_settings' => array(
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_general_info|node|study|right_area'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_health_status|node|study|center_area';
  $field_group->group_name = 'group_health_status';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'study';
  $field_group->mode = 'center_area';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Please specify health status',
    'weight' => '35',
    'children' => array(),
    'format_type' => 'hidden',
    'format_settings' => array(
      'formatter' => 'open',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_health_status|node|study|center_area'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_health_status|node|study|default';
  $field_group->group_name = 'group_health_status';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'study';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_participants_selection';
  $field_group->data = array(
    'label' => 'Please specify health status',
    'weight' => '50',
    'children' => array(),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'open',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_health_status|node|study|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_health_status|node|study|footer_area';
  $field_group->group_name = 'group_health_status';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'study';
  $field_group->mode = 'footer_area';
  $field_group->parent_name = 'group_participants_selection';
  $field_group->data = array(
    'label' => 'Please specify health status',
    'weight' => '50',
    'children' => array(),
    'format_type' => 'hidden',
    'format_settings' => array(
      'formatter' => 'open',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_health_status|node|study|footer_area'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_health_status|node|study|right_area';
  $field_group->group_name = 'group_health_status';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'study';
  $field_group->mode = 'right_area';
  $field_group->parent_name = 'group_participants_selection';
  $field_group->data = array(
    'label' => 'Please specify health status',
    'weight' => '50',
    'children' => array(),
    'format_type' => 'hidden',
    'format_settings' => array(
      'formatter' => 'open',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_health_status|node|study|right_area'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_institution|node|contact|default';
  $field_group->group_name = 'group_institution';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'contact';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Institution',
    'weight' => '6',
    'children' => array(
      0 => 'field_city',
      1 => 'field_contact_country',
      2 => 'field_department_unit',
      3 => 'field_institution_name',
      4 => 'field_postal_code',
      5 => 'field_state',
    ),
    'format_type' => 'hidden',
    'format_settings' => array(
      'formatter' => 'open',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_institution|node|contact|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_institution|node|contact|form';
  $field_group->group_name = 'group_institution';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'contact';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Institution',
    'weight' => '6',
    'children' => array(
      0 => 'field_institution_name',
      1 => 'field_department_unit',
      2 => 'field_address',
      3 => 'field_city',
      4 => 'field_postal_code',
      5 => 'field_state',
      6 => 'field_contact_country',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'open',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_institution|node|contact|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_marker_paper|node|study|center_area';
  $field_group->group_name = 'group_marker_paper';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'study';
  $field_group->mode = 'center_area';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Marker Paper',
    'weight' => '13',
    'children' => array(
      0 => 'field_marker_paper',
      1 => 'field_pubmedid',
    ),
    'format_type' => 'hidden',
    'format_settings' => array(
      'formatter' => 'open',
      'instance_settings' => array(
        'description' => '',
        'show_label' => 1,
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
        'classes' => '',
      ),
    ),
  );
  $export['group_marker_paper|node|study|center_area'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_marker_paper|node|study|default';
  $field_group->group_name = 'group_marker_paper';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'study';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_tabs';
  $field_group->data = array(
    'label' => 'Marker Paper / Documents',
    'weight' => '91',
    'children' => array(
      0 => 'field_documents',
      1 => 'field_marker_paper',
      2 => 'field_pubmedid',
      3 => 'field_questionnaires',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'label' => 'Marker Paper / Documents',
      'instance_settings' => array(
        'classes' => '',
        'description' => 'Bibliographic citations which should be used to refer to this study and study documents.',
      ),
      'formatter' => 'closed',
    ),
  );
  $export['group_marker_paper|node|study|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_marker_paper|node|study|footer_area';
  $field_group->group_name = 'group_marker_paper';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'study';
  $field_group->mode = 'footer_area';
  $field_group->parent_name = 'group_tabs';
  $field_group->data = array(
    'label' => 'Marker Paper',
    'weight' => '0',
    'children' => array(
      0 => 'field_marker_paper',
      1 => 'field_pubmedid',
    ),
    'format_type' => 'hidden',
    'format_settings' => array(
      'formatter' => 'open',
      'instance_settings' => array(
        'description' => '',
        'show_label' => 1,
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
        'classes' => '',
      ),
    ),
  );
  $export['group_marker_paper|node|study|footer_area'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_marker_paper|node|study|form';
  $field_group->group_name = 'group_marker_paper';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'study';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_tabs';
  $field_group->data = array(
    'label' => 'Marker Paper',
    'weight' => '11',
    'children' => array(
      0 => 'field_marker_paper',
      1 => 'field_pubmedid',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'label' => 'Marker Paper',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => 'If relevant, please provide the bibliographic citations (i.e. published sources such as journal article, web site, or report) which should be used to refer to your study.',
      ),
      'formatter' => 'closed',
    ),
  );
  $export['group_marker_paper|node|study|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_marker_paper|node|study|left_area';
  $field_group->group_name = 'group_marker_paper';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'study';
  $field_group->mode = 'left_area';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Marker Paper',
    'weight' => '3',
    'children' => array(
      0 => 'field_marker_paper',
      1 => 'field_pubmedid',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'open',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
      ),
    ),
  );
  $export['group_marker_paper|node|study|left_area'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_marker_paper|node|study|right_area';
  $field_group->group_name = 'group_marker_paper';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'study';
  $field_group->mode = 'right_area';
  $field_group->parent_name = 'group_tabs';
  $field_group->data = array(
    'label' => 'Marker Paper',
    'weight' => '90',
    'children' => array(
      0 => 'field_marker_paper',
      1 => 'field_pubmedid',
    ),
    'format_type' => 'hidden',
    'format_settings' => array(
      'label' => 'Marker Paper',
      'instance_settings' => array(
        'classes' => '',
        'description' => 'Bibliographic citations which should be used to refer to this study.',
      ),
      'formatter' => 'closed',
    ),
  );
  $export['group_marker_paper|node|study|right_area'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_methods|node|study|center_area';
  $field_group->group_name = 'group_methods';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'study';
  $field_group->mode = 'center_area';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Methods',
    'weight' => '21',
    'children' => array(
      0 => 'group_data_collection',
      1 => 'group_general_design',
      2 => 'group_sample_management',
    ),
    'format_type' => 'hidden',
    'format_settings' => array(
      'formatter' => 'open',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
      ),
    ),
  );
  $export['group_methods|node|study|center_area'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_methods|node|study|default';
  $field_group->group_name = 'group_methods';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'study';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_tabs';
  $field_group->data = array(
    'label' => 'Methods',
    'weight' => '87',
    'children' => array(
      0 => 'group_data_collection',
      1 => 'group_general_design',
      2 => 'group_participants_selection',
      3 => 'group_sample_management',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_methods|node|study|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_methods|node|study|footer_area';
  $field_group->group_name = 'group_methods';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'study';
  $field_group->mode = 'footer_area';
  $field_group->parent_name = 'group_tabs';
  $field_group->data = array(
    'label' => 'Methods',
    'weight' => '87',
    'children' => array(
      0 => 'group_data_collection',
      1 => 'group_general_design',
      2 => 'group_participants_selection',
      3 => 'group_sample_management',
    ),
    'format_type' => 'hidden',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_methods|node|study|footer_area'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_methods|node|study|form';
  $field_group->group_name = 'group_methods';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'study';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_tabs';
  $field_group->data = array(
    'label' => 'Methods',
    'weight' => '8',
    'children' => array(
      0 => 'group_data_collection',
      1 => 'group_general_design',
      2 => 'group_participants_selection',
      3 => 'group_sample_management',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_methods|node|study|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_methods|node|study|right_area';
  $field_group->group_name = 'group_methods';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'study';
  $field_group->mode = 'right_area';
  $field_group->parent_name = 'group_tabs';
  $field_group->data = array(
    'label' => 'Methods',
    'weight' => '87',
    'children' => array(
      0 => 'group_data_collection',
      1 => 'group_general_design',
      2 => 'group_participants_selection',
      3 => 'group_sample_management',
    ),
    'format_type' => 'hidden',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_methods|node|study|right_area'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_more_current_participants|node|study|center_area';
  $field_group->group_name = 'group_more_current_participants';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'study';
  $field_group->mode = 'center_area';
  $field_group->parent_name = 'group_status';
  $field_group->data = array(
    'label' => 'Details',
    'weight' => '65',
    'children' => array(
      0 => 'field_current_supp_info',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Details',
      'instance_settings' => array(
        'classes' => 'field-group-more field-group-indent',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $export['group_more_current_participants|node|study|center_area'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_more_current_samples|node|study|center_area';
  $field_group->group_name = 'group_more_current_samples';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'study';
  $field_group->mode = 'center_area';
  $field_group->parent_name = 'group_status';
  $field_group->data = array(
    'label' => 'Details',
    'weight' => '68',
    'children' => array(
      0 => 'field_current_sam_supp_info',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Details',
      'instance_settings' => array(
        'classes' => 'field-group-more field-group-indent',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $export['group_more_current_samples|node|study|center_area'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_more_design|node|study|left_area';
  $field_group->group_name = 'group_more_design';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'study';
  $field_group->mode = 'left_area';
  $field_group->parent_name = 'group_general_design';
  $field_group->data = array(
    'label' => 'Details',
    'weight' => '28',
    'children' => array(
      0 => 'field_recruitment_supp_info',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Details',
      'instance_settings' => array(
        'classes' => 'field-group-more field-group-indent',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $export['group_more_design|node|study|left_area'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_more_recruitment_proc|node|study|center_area';
  $field_group->group_name = 'group_more_recruitment_proc';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'study';
  $field_group->mode = 'center_area';
  $field_group->parent_name = 'group_participants_selection';
  $field_group->data = array(
    'label' => 'Details',
    'weight' => '49',
    'children' => array(
      0 => 'field_recruitement_supp_info',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Details',
      'instance_settings' => array(
        'classes' => 'field-group-more field-group-indent',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $export['group_more_recruitment_proc|node|study|center_area'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_more_recruitment_proc|node|study|left_area';
  $field_group->group_name = 'group_more_recruitment_proc';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'study';
  $field_group->mode = 'left_area';
  $field_group->parent_name = 'group_recruitment_procedures';
  $field_group->data = array(
    'label' => '...',
    'weight' => '41',
    'children' => array(
      0 => 'field_recruitement_supp_info',
    ),
    'format_type' => 'hidden',
    'format_settings' => array(
      'label' => '...',
      'instance_settings' => array(
        'classes' => 'field-group-more',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $export['group_more_recruitment_proc|node|study|left_area'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_more_selection|node|study|center_area';
  $field_group->group_name = 'group_more_selection';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'study';
  $field_group->mode = 'center_area';
  $field_group->parent_name = 'group_participants_selection';
  $field_group->data = array(
    'label' => 'Details',
    'weight' => '45',
    'children' => array(
      0 => 'field_partcipant_sel_supp_info',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Details',
      'instance_settings' => array(
        'classes' => 'field-group-more field-group-indent',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $export['group_more_selection|node|study|center_area'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_more_selection|node|study|left_area';
  $field_group->group_name = 'group_more_selection';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'study';
  $field_group->mode = 'left_area';
  $field_group->parent_name = 'group_selection_criteria';
  $field_group->data = array(
    'label' => '...',
    'weight' => '45',
    'children' => array(
      0 => 'field_partcipant_sel_supp_info',
    ),
    'format_type' => 'hidden',
    'format_settings' => array(
      'label' => '...',
      'instance_settings' => array(
        'classes' => 'field-group-more',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $export['group_more_selection|node|study|left_area'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_more_status|node|study|center_area';
  $field_group->group_name = 'group_more_status';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'study';
  $field_group->mode = 'center_area';
  $field_group->parent_name = 'group_status';
  $field_group->data = array(
    'label' => 'Status Details',
    'weight' => '69',
    'children' => array(
      0 => 'field_status_supp_info',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Status Details',
      'instance_settings' => array(
        'classes' => 'field-group-more',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $export['group_more_status|node|study|center_area'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_more_target_participant|node|study|left_area';
  $field_group->group_name = 'group_more_target_participant';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'study';
  $field_group->mode = 'left_area';
  $field_group->parent_name = 'group_general_design';
  $field_group->data = array(
    'label' => 'Details',
    'weight' => '33',
    'children' => array(
      0 => 'field_target_nb_supp_info',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Details',
      'instance_settings' => array(
        'classes' => 'field-group-more field-group-indent',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $export['group_more_target_participant|node|study|left_area'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_more_target_samples|node|study|left_area';
  $field_group->group_name = 'group_more_target_samples';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'study';
  $field_group->mode = 'left_area';
  $field_group->parent_name = 'group_general_design';
  $field_group->data = array(
    'label' => 'Details',
    'weight' => '36',
    'children' => array(
      0 => 'field_samples_supp_info',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Details',
      'instance_settings' => array(
        'classes' => 'field-group-more field-group-indent',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $export['group_more_target_samples|node|study|left_area'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_participants_selection|node|study|center_area';
  $field_group->group_name = 'group_participants_selection';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'study';
  $field_group->mode = 'center_area';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Participants Selection',
    'weight' => '0',
    'children' => array(
      0 => 'field_age_max',
      1 => 'field_age_min',
      2 => 'field_country',
      3 => 'field_ethnic_origin',
      4 => 'field_gender',
      5 => 'field_health_status',
      6 => 'field_recruitment_other',
      7 => 'field_recruitment_procedures',
      8 => 'field_recruitment_sources',
      9 => 'field_select_criteria',
      10 => 'field_selection_others_sp',
      11 => 'field_territory',
      12 => 'group_more_recruitment_proc',
      13 => 'group_more_selection',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Participants Selection',
      'instance_settings' => array(
        'classes' => '',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h2',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_participants_selection|node|study|center_area'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_participants_selection|node|study|default';
  $field_group->group_name = 'group_participants_selection';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'study';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_methods';
  $field_group->data = array(
    'label' => 'Participants Selection',
    'weight' => '67',
    'children' => array(
      0 => 'field_age_max',
      1 => 'field_age_min',
      2 => 'field_country',
      3 => 'field_ethnic_origin',
      4 => 'field_gender',
      5 => 'field_health_status',
      6 => 'field_partcipant_sel_supp_info',
      7 => 'field_recruitement_supp_info',
      8 => 'field_recruitment_other',
      9 => 'field_recruitment_procedures',
      10 => 'field_recruitment_sources',
      11 => 'field_select_criteria',
      12 => 'field_selection_others_sp',
      13 => 'field_territory',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Participants Selection',
      'instance_settings' => array(
        'classes' => '',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h2',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_participants_selection|node|study|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_participants_selection|node|study|footer_area';
  $field_group->group_name = 'group_participants_selection';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'study';
  $field_group->mode = 'footer_area';
  $field_group->parent_name = 'group_methods';
  $field_group->data = array(
    'label' => 'Participants Selection',
    'weight' => '67',
    'children' => array(
      0 => 'field_age_max',
      1 => 'field_age_min',
      2 => 'field_country',
      3 => 'field_ethnic_origin',
      4 => 'field_health_status',
      5 => 'field_partcipant_sel_supp_info',
      6 => 'field_recruitement_supp_info',
      7 => 'field_recruitment_other',
      8 => 'field_recruitment_procedures',
      9 => 'field_select_criteria',
      10 => 'field_selection_others_sp',
      11 => 'field_territory',
      12 => 'group_age_range',
      13 => 'group_countries',
      14 => 'group_ethnic_origin',
      15 => 'group_health_status',
      16 => 'group_recruitment_procedures',
      17 => 'group_selection_criteria',
      18 => 'group_specify_gender',
    ),
    'format_type' => 'hidden',
    'format_settings' => array(
      'label' => 'Participants Selection',
      'instance_settings' => array(
        'classes' => '',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h2',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_participants_selection|node|study|footer_area'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_participants_selection|node|study|form';
  $field_group->group_name = 'group_participants_selection';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'study';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_methods';
  $field_group->data = array(
    'label' => 'Participants Selection',
    'weight' => '67',
    'children' => array(
      0 => 'group_recruitment_procedures',
      1 => 'group_selection_criteria',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Participants Selection',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_participants_selection|node|study|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_participants_selection|node|study|right_area';
  $field_group->group_name = 'group_participants_selection';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'study';
  $field_group->mode = 'right_area';
  $field_group->parent_name = 'group_methods';
  $field_group->data = array(
    'label' => 'Participants Selection',
    'weight' => '67',
    'children' => array(
      0 => 'field_age_max',
      1 => 'field_age_min',
      2 => 'field_country',
      3 => 'field_ethnic_origin',
      4 => 'field_health_status',
      5 => 'field_partcipant_sel_supp_info',
      6 => 'field_recruitement_supp_info',
      7 => 'field_recruitment_other',
      8 => 'field_recruitment_procedures',
      9 => 'field_select_criteria',
      10 => 'field_selection_others_sp',
      11 => 'field_territory',
      12 => 'group_age_range',
      13 => 'group_countries',
      14 => 'group_ethnic_origin',
      15 => 'group_health_status',
      16 => 'group_recruitment_procedures',
      17 => 'group_selection_criteria',
      18 => 'group_specify_gender',
    ),
    'format_type' => 'hidden',
    'format_settings' => array(
      'label' => 'Participants Selection',
      'instance_settings' => array(
        'classes' => '',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h2',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_participants_selection|node|study|right_area'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_participants_selection|node|study|summary_right_area';
  $field_group->group_name = 'group_participants_selection';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'study';
  $field_group->mode = 'summary_right_area';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Participants Selection',
    'weight' => '0',
    'children' => array(
      0 => 'field_age_max',
      1 => 'field_age_min',
      2 => 'field_country',
      3 => 'field_ethnic_origin',
      4 => 'field_gender',
      5 => 'field_health_status',
      6 => 'field_select_criteria',
      7 => 'field_selection_others_sp',
      8 => 'field_territory',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'open',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
      ),
    ),
  );
  $export['group_participants_selection|node|study|summary_right_area'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_preparation_phase|node|study|center_area';
  $field_group->group_name = 'group_preparation_phase';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'study';
  $field_group->mode = 'center_area';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Preparation phase / Pilot',
    'weight' => '6',
    'children' => array(),
    'format_type' => 'hidden',
    'format_settings' => array(
      'formatter' => 'open',
      'instance_settings' => array(
        'description' => '',
        'show_label' => 1,
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
        'classes' => '',
      ),
    ),
  );
  $export['group_preparation_phase|node|study|center_area'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_preparation_phase|node|study|default';
  $field_group->group_name = 'group_preparation_phase';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'study';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_status';
  $field_group->data = array(
    'label' => 'Preparation phase / Pilot',
    'weight' => '49',
    'children' => array(
      0 => 'field_preparation_end_year',
      1 => 'field_preparation_start_year',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'formatter' => 'open',
      'instance_settings' => array(
        'description' => '',
        'show_label' => 1,
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
        'classes' => '',
      ),
    ),
  );
  $export['group_preparation_phase|node|study|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_preparation_phase|node|study|footer_area';
  $field_group->group_name = 'group_preparation_phase';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'study';
  $field_group->mode = 'footer_area';
  $field_group->parent_name = 'group_status';
  $field_group->data = array(
    'label' => 'Preparation phase / Pilot',
    'weight' => '49',
    'children' => array(
      0 => 'field_preparation_end_year',
      1 => 'field_preparation_start_year',
    ),
    'format_type' => 'hidden',
    'format_settings' => array(
      'formatter' => 'open',
      'instance_settings' => array(
        'description' => '',
        'show_label' => 1,
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
        'classes' => '',
      ),
    ),
  );
  $export['group_preparation_phase|node|study|footer_area'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_preparation_phase|node|study|form';
  $field_group->group_name = 'group_preparation_phase';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'study';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_current_status';
  $field_group->data = array(
    'label' => 'Preparation phase / Pilot',
    'weight' => '56',
    'children' => array(
      0 => 'field_preparation_end_year',
      1 => 'field_preparation_start_year',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Preparation phase / Pilot',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_preparation_phase|node|study|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_preparation_phase|node|study|left_area';
  $field_group->group_name = 'group_preparation_phase';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'study';
  $field_group->mode = 'left_area';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Preparation phase / Pilot',
    'weight' => '22',
    'children' => array(),
    'format_type' => 'hidden',
    'format_settings' => array(
      'formatter' => 'open',
      'instance_settings' => array(
        'description' => '',
        'show_label' => 1,
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
        'classes' => '',
      ),
    ),
  );
  $export['group_preparation_phase|node|study|left_area'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_preparation_phase|node|study|right_area';
  $field_group->group_name = 'group_preparation_phase';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'study';
  $field_group->mode = 'right_area';
  $field_group->parent_name = 'group_status';
  $field_group->data = array(
    'label' => 'Preparation phase / Pilot',
    'weight' => '49',
    'children' => array(
      0 => 'field_preparation_end_year',
      1 => 'field_preparation_start_year',
    ),
    'format_type' => 'hidden',
    'format_settings' => array(
      'formatter' => 'open',
      'instance_settings' => array(
        'description' => '',
        'show_label' => 1,
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
        'classes' => '',
      ),
    ),
  );
  $export['group_preparation_phase|node|study|right_area'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_recruitment_procedures|node|study|center_area';
  $field_group->group_name = 'group_recruitment_procedures';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'study';
  $field_group->mode = 'center_area';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Recruitment procedures',
    'weight' => '37',
    'children' => array(),
    'format_type' => 'hidden',
    'format_settings' => array(
      'label' => 'Recruitment procedures',
      'instance_settings' => array(
        'classes' => '',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_recruitment_procedures|node|study|center_area'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_recruitment_procedures|node|study|default';
  $field_group->group_name = 'group_recruitment_procedures';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'study';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_participants_selection';
  $field_group->data = array(
    'label' => 'Recruitment procedures',
    'weight' => '55',
    'children' => array(),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Recruitment procedures',
      'instance_settings' => array(
        'classes' => '',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_recruitment_procedures|node|study|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_recruitment_procedures|node|study|footer_area';
  $field_group->group_name = 'group_recruitment_procedures';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'study';
  $field_group->mode = 'footer_area';
  $field_group->parent_name = 'group_participants_selection';
  $field_group->data = array(
    'label' => 'Recruitment procedures',
    'weight' => '55',
    'children' => array(),
    'format_type' => 'hidden',
    'format_settings' => array(
      'label' => 'Recruitment procedures',
      'instance_settings' => array(
        'classes' => '',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_recruitment_procedures|node|study|footer_area'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_recruitment_procedures|node|study|form';
  $field_group->group_name = 'group_recruitment_procedures';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'study';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_participants_selection';
  $field_group->data = array(
    'label' => 'Recruitment procedures',
    'weight' => '67',
    'children' => array(
      0 => 'field_recruitement_supp_info',
      1 => 'field_recruitment_other',
      2 => 'field_recruitment_sources',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'open',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_recruitment_procedures|node|study|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_recruitment_procedures|node|study|left_area';
  $field_group->group_name = 'group_recruitment_procedures';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'study';
  $field_group->mode = 'left_area';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Recruitment procedures',
    'weight' => '11',
    'children' => array(
      0 => 'field_recruitment_other',
      1 => 'field_recruitment_procedures',
      2 => 'group_more_recruitment_proc',
    ),
    'format_type' => 'hidden',
    'format_settings' => array(
      'label' => 'Recruitment procedures',
      'instance_settings' => array(
        'classes' => '',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $export['group_recruitment_procedures|node|study|left_area'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_recruitment_procedures|node|study|right_area';
  $field_group->group_name = 'group_recruitment_procedures';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'study';
  $field_group->mode = 'right_area';
  $field_group->parent_name = 'group_participants_selection';
  $field_group->data = array(
    'label' => 'Recruitment procedures',
    'weight' => '55',
    'children' => array(),
    'format_type' => 'hidden',
    'format_settings' => array(
      'label' => 'Recruitment procedures',
      'instance_settings' => array(
        'classes' => '',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_recruitment_procedures|node|study|right_area'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_sample_management|node|study|center_area';
  $field_group->group_name = 'group_sample_management';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'study';
  $field_group->mode = 'center_area';
  $field_group->parent_name = 'group_methods';
  $field_group->data = array(
    'label' => 'Sample Collection',
    'weight' => '69',
    'children' => array(
      0 => 'field_bio_samples_management',
      1 => 'field_samples_man_other_sp',
      2 => 'field_tissues_sp',
    ),
    'format_type' => 'hidden',
    'format_settings' => array(
      'label' => 'Sample Collection',
      'instance_settings' => array(
        'classes' => '',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h2',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_sample_management|node|study|center_area'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_sample_management|node|study|default';
  $field_group->group_name = 'group_sample_management';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'study';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_methods';
  $field_group->data = array(
    'label' => 'Sample Collection',
    'weight' => '70',
    'children' => array(
      0 => 'field_bio_samples_management',
      1 => 'field_samples_man_other_sp',
      2 => 'field_tissues_sp',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Sample Collection',
      'instance_settings' => array(
        'classes' => '',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h2',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_sample_management|node|study|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_sample_management|node|study|footer_area';
  $field_group->group_name = 'group_sample_management';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'study';
  $field_group->mode = 'footer_area';
  $field_group->parent_name = 'group_methods';
  $field_group->data = array(
    'label' => 'Sample Collection',
    'weight' => '69',
    'children' => array(
      0 => 'field_bio_samples_management',
      1 => 'field_samples_man_other_sp',
      2 => 'field_tissues_sp',
    ),
    'format_type' => 'hidden',
    'format_settings' => array(
      'label' => 'Sample Collection',
      'instance_settings' => array(
        'classes' => '',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h2',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_sample_management|node|study|footer_area'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_sample_management|node|study|form';
  $field_group->group_name = 'group_sample_management';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'study';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_methods';
  $field_group->data = array(
    'label' => 'Sample Collection',
    'weight' => '70',
    'children' => array(
      0 => 'field_bio_samples_management',
      1 => 'field_samples_man_other_sp',
      2 => 'field_tissues_sp',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Sample Collection',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_sample_management|node|study|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_sample_management|node|study|left_area';
  $field_group->group_name = 'group_sample_management';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'study';
  $field_group->mode = 'left_area';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Sample Collection',
    'weight' => '2',
    'children' => array(
      0 => 'field_bio_samples_management',
      1 => 'field_samples_man_other_sp',
      2 => 'field_tissues_sp',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'open',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
      ),
    ),
  );
  $export['group_sample_management|node|study|left_area'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_sample_management|node|study|right_area';
  $field_group->group_name = 'group_sample_management';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'study';
  $field_group->mode = 'right_area';
  $field_group->parent_name = 'group_methods';
  $field_group->data = array(
    'label' => 'Sample Collection',
    'weight' => '69',
    'children' => array(
      0 => 'field_bio_samples_management',
      1 => 'field_samples_man_other_sp',
      2 => 'field_tissues_sp',
    ),
    'format_type' => 'hidden',
    'format_settings' => array(
      'label' => 'Sample Collection',
      'instance_settings' => array(
        'classes' => '',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h2',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_sample_management|node|study|right_area'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_selection_criteria|node|study|center_area';
  $field_group->group_name = 'group_selection_criteria';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'study';
  $field_group->mode = 'center_area';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Selection Criteria / Characteristics of the population',
    'weight' => '36',
    'children' => array(),
    'format_type' => 'hidden',
    'format_settings' => array(
      'formatter' => 'open',
      'instance_settings' => array(
        'description' => '',
        'show_label' => 1,
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
        'classes' => '',
      ),
    ),
  );
  $export['group_selection_criteria|node|study|center_area'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_selection_criteria|node|study|default';
  $field_group->group_name = 'group_selection_criteria';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'study';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_participants_selection';
  $field_group->data = array(
    'label' => 'Selection Criteria / Characteristics of the population',
    'weight' => '54',
    'children' => array(),
    'format_type' => 'div',
    'format_settings' => array(
      'formatter' => 'open',
      'instance_settings' => array(
        'description' => '',
        'show_label' => 1,
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
        'classes' => '',
      ),
    ),
  );
  $export['group_selection_criteria|node|study|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_selection_criteria|node|study|footer_area';
  $field_group->group_name = 'group_selection_criteria';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'study';
  $field_group->mode = 'footer_area';
  $field_group->parent_name = 'group_participants_selection';
  $field_group->data = array(
    'label' => 'Selection Criteria / Characteristics of the population',
    'weight' => '54',
    'children' => array(),
    'format_type' => 'hidden',
    'format_settings' => array(
      'formatter' => 'open',
      'instance_settings' => array(
        'description' => '',
        'show_label' => 1,
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
        'classes' => '',
      ),
    ),
  );
  $export['group_selection_criteria|node|study|footer_area'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_selection_criteria|node|study|form';
  $field_group->group_name = 'group_selection_criteria';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'study';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_participants_selection';
  $field_group->data = array(
    'label' => 'Selection Criteria / Characteristics of the population',
    'weight' => '66',
    'children' => array(
      0 => 'field_age_max',
      1 => 'field_age_min',
      2 => 'field_ethnic_origin',
      3 => 'field_gender',
      4 => 'field_health_status',
      5 => 'field_partcipant_sel_supp_info',
      6 => 'field_select_criteria',
      7 => 'field_selection_others_sp',
      8 => 'group_countries',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'open',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_selection_criteria|node|study|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_selection_criteria|node|study|left_area';
  $field_group->group_name = 'group_selection_criteria';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'study';
  $field_group->mode = 'left_area';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Selection Criteria',
    'weight' => '10',
    'children' => array(
      0 => 'field_age_max',
      1 => 'field_age_min',
      2 => 'field_country',
      3 => 'field_ethnic_origin',
      4 => 'field_gender',
      5 => 'field_health_status',
      6 => 'field_select_criteria',
      7 => 'field_selection_others_sp',
      8 => 'field_territory',
      9 => 'group_more_selection',
    ),
    'format_type' => 'hidden',
    'format_settings' => array(
      'label' => 'Selection Criteria',
      'instance_settings' => array(
        'classes' => '',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_selection_criteria|node|study|left_area'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_selection_criteria|node|study|right_area';
  $field_group->group_name = 'group_selection_criteria';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'study';
  $field_group->mode = 'right_area';
  $field_group->parent_name = 'group_participants_selection';
  $field_group->data = array(
    'label' => 'Selection Criteria / Characteristics of the population',
    'weight' => '54',
    'children' => array(),
    'format_type' => 'hidden',
    'format_settings' => array(
      'formatter' => 'open',
      'instance_settings' => array(
        'description' => '',
        'show_label' => 1,
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
        'classes' => '',
      ),
    ),
  );
  $export['group_selection_criteria|node|study|right_area'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_specify_gender|node|study|center_area';
  $field_group->group_name = 'group_specify_gender';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'study';
  $field_group->mode = 'center_area';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Please specify gender',
    'weight' => '29',
    'children' => array(),
    'format_type' => 'hidden',
    'format_settings' => array(
      'formatter' => 'open',
      'instance_settings' => array(
        'description' => '',
        'show_label' => 1,
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
        'classes' => '',
      ),
    ),
  );
  $export['group_specify_gender|node|study|center_area'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_specify_gender|node|study|default';
  $field_group->group_name = 'group_specify_gender';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'study';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_participants_selection';
  $field_group->data = array(
    'label' => 'Please specify gender',
    'weight' => '46',
    'children' => array(),
    'format_type' => 'div',
    'format_settings' => array(
      'formatter' => 'open',
      'instance_settings' => array(
        'description' => '',
        'show_label' => 1,
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
        'classes' => '',
      ),
    ),
  );
  $export['group_specify_gender|node|study|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_specify_gender|node|study|footer_area';
  $field_group->group_name = 'group_specify_gender';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'study';
  $field_group->mode = 'footer_area';
  $field_group->parent_name = 'group_participants_selection';
  $field_group->data = array(
    'label' => 'Please specify gender',
    'weight' => '46',
    'children' => array(),
    'format_type' => 'hidden',
    'format_settings' => array(
      'formatter' => 'open',
      'instance_settings' => array(
        'description' => '',
        'show_label' => 1,
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
        'classes' => '',
      ),
    ),
  );
  $export['group_specify_gender|node|study|footer_area'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_specify_gender|node|study|right_area';
  $field_group->group_name = 'group_specify_gender';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'study';
  $field_group->mode = 'right_area';
  $field_group->parent_name = 'group_participants_selection';
  $field_group->data = array(
    'label' => 'Please specify gender',
    'weight' => '46',
    'children' => array(),
    'format_type' => 'hidden',
    'format_settings' => array(
      'formatter' => 'open',
      'instance_settings' => array(
        'description' => '',
        'show_label' => 1,
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
        'classes' => '',
      ),
    ),
  );
  $export['group_specify_gender|node|study|right_area'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_status|node|study|center_area';
  $field_group->group_name = 'group_status';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'study';
  $field_group->mode = 'center_area';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Status',
    'weight' => '2',
    'children' => array(
      0 => 'field_baseline_end_year',
      1 => 'field_baseline_start_year',
      2 => 'field_current_part_nb_date',
      3 => 'field_current_participants_nb',
      4 => 'field_current_samples_date',
      5 => 'field_current_samples_nb',
      6 => 'field_ended_end_year',
      7 => 'field_followup_end_year',
      8 => 'field_followup_start_year',
      9 => 'field_preparation_end_year',
      10 => 'field_preparation_start_year',
      11 => 'group_more_current_participants',
      12 => 'group_more_current_samples',
      13 => 'group_more_status',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'open',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
      ),
    ),
  );
  $export['group_status|node|study|center_area'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_status|node|study|default';
  $field_group->group_name = 'group_status';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'study';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_tabs';
  $field_group->data = array(
    'label' => 'Status',
    'weight' => '90',
    'children' => array(
      0 => 'field_baseline_end_year',
      1 => 'field_baseline_start_year',
      2 => 'field_current_part_nb_date',
      3 => 'field_current_participants_nb',
      4 => 'field_current_sam_supp_info',
      5 => 'field_current_samples_date',
      6 => 'field_current_samples_nb',
      7 => 'field_current_supp_info',
      8 => 'field_ended_end_year',
      9 => 'field_followup_end_year',
      10 => 'field_followup_start_year',
      11 => 'field_preparation_end_year',
      12 => 'field_preparation_start_year',
      13 => 'field_status_supp_info',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'label' => 'Status',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'closed',
    ),
  );
  $export['group_status|node|study|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_status|node|study|footer_area';
  $field_group->group_name = 'group_status';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'study';
  $field_group->mode = 'footer_area';
  $field_group->parent_name = 'group_tabs';
  $field_group->data = array(
    'label' => 'Status',
    'weight' => '89',
    'children' => array(
      0 => 'field_status_supp_info',
      1 => 'group_baseline_phase',
      2 => 'group_current_status',
      3 => 'group_ended_phase',
      4 => 'group_followup_phase',
      5 => 'group_preparation_phase',
    ),
    'format_type' => 'hidden',
    'format_settings' => array(
      'label' => 'Status',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'closed',
    ),
  );
  $export['group_status|node|study|footer_area'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_status|node|study|form';
  $field_group->group_name = 'group_status';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'study';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_tabs';
  $field_group->data = array(
    'label' => 'Status',
    'weight' => '10',
    'children' => array(
      0 => 'group_current_status',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'label' => 'Status',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'closed',
    ),
  );
  $export['group_status|node|study|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_status|node|study|left_area';
  $field_group->group_name = 'group_status';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'study';
  $field_group->mode = 'left_area';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Status',
    'weight' => '16',
    'children' => array(
      0 => 'field_baseline_end_year',
      1 => 'field_baseline_start_year',
      2 => 'field_current_part_nb_date',
      3 => 'field_current_participants_nb',
      4 => 'field_current_sam_supp_info',
      5 => 'field_current_samples_date',
      6 => 'field_current_samples_nb',
      7 => 'field_current_supp_info',
      8 => 'field_ended_end_year',
      9 => 'field_followup_end_year',
      10 => 'field_followup_start_year',
      11 => 'field_preparation_end_year',
      12 => 'field_preparation_start_year',
      13 => 'field_status_supp_info',
    ),
    'format_type' => 'hidden',
    'format_settings' => array(
      'label' => 'Status',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'closed',
    ),
  );
  $export['group_status|node|study|left_area'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_status|node|study|right_area';
  $field_group->group_name = 'group_status';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'study';
  $field_group->mode = 'right_area';
  $field_group->parent_name = 'group_tabs';
  $field_group->data = array(
    'label' => 'Status',
    'weight' => '89',
    'children' => array(
      0 => 'field_status_supp_info',
      1 => 'group_baseline_phase',
      2 => 'group_current_status',
      3 => 'group_ended_phase',
      4 => 'group_followup_phase',
      5 => 'group_preparation_phase',
    ),
    'format_type' => 'hidden',
    'format_settings' => array(
      'label' => 'Status',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'closed',
    ),
  );
  $export['group_status|node|study|right_area'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_study_design|node|study|center_area';
  $field_group->group_name = 'group_study_design';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'study';
  $field_group->mode = 'center_area';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Study/Registry Design',
    'weight' => '26',
    'children' => array(),
    'format_type' => 'hidden',
    'format_settings' => array(
      'label' => 'Study/Registry Design',
      'instance_settings' => array(
        'classes' => '',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_study_design|node|study|center_area'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_study_design|node|study|default';
  $field_group->group_name = 'group_study_design';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'study';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_general_design';
  $field_group->data = array(
    'label' => 'Study/Registry Design',
    'weight' => '43',
    'children' => array(),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Study/Registry Design',
      'instance_settings' => array(
        'classes' => '',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_study_design|node|study|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_study_design|node|study|footer_area';
  $field_group->group_name = 'group_study_design';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'study';
  $field_group->mode = 'footer_area';
  $field_group->parent_name = 'group_general_design';
  $field_group->data = array(
    'label' => 'Study/Registry Design',
    'weight' => '43',
    'children' => array(),
    'format_type' => 'hidden',
    'format_settings' => array(
      'label' => 'Study/Registry Design',
      'instance_settings' => array(
        'classes' => '',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_study_design|node|study|footer_area'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_study_design|node|study|form';
  $field_group->group_name = 'group_study_design';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'study';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_general_design';
  $field_group->data = array(
    'label' => 'Study/Registry Design',
    'weight' => '6',
    'children' => array(
      0 => 'field_design',
      1 => 'field_design_other_sp',
      2 => 'field_recruitment',
      3 => 'field_recruitment_other_sp',
      4 => 'field_recruitment_supp_info',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'open',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_study_design|node|study|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_study_design|node|study|right_area';
  $field_group->group_name = 'group_study_design';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'study';
  $field_group->mode = 'right_area';
  $field_group->parent_name = 'group_general_design';
  $field_group->data = array(
    'label' => 'Study/Registry Design',
    'weight' => '43',
    'children' => array(),
    'format_type' => 'hidden',
    'format_settings' => array(
      'label' => 'Study/Registry Design',
      'instance_settings' => array(
        'classes' => '',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_study_design|node|study|right_area'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_study_name|node|study|form';
  $field_group->group_name = 'group_study_name';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'study';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_general_info';
  $field_group->data = array(
    'label' => 'Name of the study',
    'weight' => '1',
    'children' => array(
      0 => 'field_acroym',
      1 => 'title_field',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Name of the study',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => 'What is the complete name of the study?',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_study_name|node|study|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_supp_info|node|study|center_area';
  $field_group->group_name = 'group_supp_info';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'study';
  $field_group->mode = 'center_area';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Supplementary information',
    'weight' => '14',
    'children' => array(
      0 => 'field_supp_infos',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'open',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
      ),
    ),
  );
  $export['group_supp_info|node|study|center_area'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_supp_info|node|study|default';
  $field_group->group_name = 'group_supp_info';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'study';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_tabs';
  $field_group->data = array(
    'label' => 'Supplementary information',
    'weight' => '92',
    'children' => array(
      0 => 'field_supp_infos',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'label' => 'Supplementary information',
      'instance_settings' => array(
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'closed',
    ),
  );
  $export['group_supp_info|node|study|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_supp_info|node|study|footer_area';
  $field_group->group_name = 'group_supp_info';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'study';
  $field_group->mode = 'footer_area';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Supplementary information',
    'weight' => '0',
    'children' => array(
      0 => 'field_supp_infos',
    ),
    'format_type' => 'hidden',
    'format_settings' => array(
      'formatter' => 'open',
      'instance_settings' => array(
        'description' => '',
        'show_label' => 1,
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
        'classes' => '',
      ),
    ),
  );
  $export['group_supp_info|node|study|footer_area'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_supp_info|node|study|form';
  $field_group->group_name = 'group_supp_info';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'study';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_tabs';
  $field_group->data = array(
    'label' => 'Supplementary information',
    'weight' => '14',
    'children' => array(
      0 => 'field_supp_infos',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'label' => 'Supplementary information',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'closed',
    ),
  );
  $export['group_supp_info|node|study|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_supp_info|node|study|left_area';
  $field_group->group_name = 'group_supp_info';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'study';
  $field_group->mode = 'left_area';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Supplementary information',
    'weight' => '17',
    'children' => array(
      0 => 'field_supp_infos',
    ),
    'format_type' => 'hidden',
    'format_settings' => array(
      'label' => 'Supplementary information',
      'instance_settings' => array(
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'closed',
    ),
  );
  $export['group_supp_info|node|study|left_area'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_supp_info|node|study|right_area';
  $field_group->group_name = 'group_supp_info';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'study';
  $field_group->mode = 'right_area';
  $field_group->parent_name = 'group_tabs';
  $field_group->data = array(
    'label' => 'Supplementary information',
    'weight' => '92',
    'children' => array(
      0 => 'field_supp_infos',
    ),
    'format_type' => 'hidden',
    'format_settings' => array(
      'label' => 'Supplementary information',
      'instance_settings' => array(
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'closed',
    ),
  );
  $export['group_supp_info|node|study|right_area'] = $field_group;

  $field_group = new stdClass();
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
      0 => 'group_datasets',
      1 => 'group_access',
      2 => 'group_authorization',
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

  $field_group = new stdClass();
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

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_tabs|node|study|right_area';
  $field_group->group_name = 'group_tabs';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'study';
  $field_group->mode = 'right_area';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Tabs',
    'weight' => '9',
    'children' => array(
      0 => 'group_access',
      1 => 'group_authorization',
      2 => 'group_documents',
      3 => 'group_general_info',
      4 => 'group_marker_paper',
      5 => 'group_methods',
      6 => 'group_status',
      7 => 'group_supp_info',
    ),
    'format_type' => 'hidden',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'classes' => '',
      ),
    ),
  );
  $export['group_tabs|node|study|right_area'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_target_nb_participants|node|study|center_area';
  $field_group->group_name = 'group_target_nb_participants';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'study';
  $field_group->mode = 'center_area';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Target Number of Participants',
    'weight' => '27',
    'children' => array(),
    'format_type' => 'hidden',
    'format_settings' => array(
      'label' => 'Target Number of Participants',
      'instance_settings' => array(
        'classes' => '',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_target_nb_participants|node|study|center_area'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_target_nb_participants|node|study|default';
  $field_group->group_name = 'group_target_nb_participants';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'study';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_general_design';
  $field_group->data = array(
    'label' => 'Target Number of Participants',
    'weight' => '44',
    'children' => array(),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Target Number of Participants',
      'instance_settings' => array(
        'classes' => '',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_target_nb_participants|node|study|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_target_nb_participants|node|study|footer_area';
  $field_group->group_name = 'group_target_nb_participants';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'study';
  $field_group->mode = 'footer_area';
  $field_group->parent_name = 'group_general_design';
  $field_group->data = array(
    'label' => 'Target Number of Participants',
    'weight' => '44',
    'children' => array(),
    'format_type' => 'hidden',
    'format_settings' => array(
      'label' => 'Target Number of Participants',
      'instance_settings' => array(
        'classes' => '',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_target_nb_participants|node|study|footer_area'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_target_nb_participants|node|study|form';
  $field_group->group_name = 'group_target_nb_participants';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'study';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_general_design';
  $field_group->data = array(
    'label' => 'Target Number of Participants',
    'weight' => '10',
    'children' => array(
      0 => 'field_no_limits_participants',
      1 => 'field_target_nb_supp_info',
      2 => 'field_target_number_participants',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'open',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_target_nb_participants|node|study|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_target_nb_participants|node|study|right_area';
  $field_group->group_name = 'group_target_nb_participants';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'study';
  $field_group->mode = 'right_area';
  $field_group->parent_name = 'group_general_design';
  $field_group->data = array(
    'label' => 'Target Number of Participants',
    'weight' => '44',
    'children' => array(),
    'format_type' => 'hidden',
    'format_settings' => array(
      'label' => 'Target Number of Participants',
      'instance_settings' => array(
        'classes' => '',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_target_nb_participants|node|study|right_area'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_target_nb_samples|node|study|center_area';
  $field_group->group_name = 'group_target_nb_samples';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'study';
  $field_group->mode = 'center_area';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Target Number of Biological Samples',
    'weight' => '28',
    'children' => array(),
    'format_type' => 'hidden',
    'format_settings' => array(
      'label' => 'Target Number of Biological Samples',
      'instance_settings' => array(
        'classes' => '',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_target_nb_samples|node|study|center_area'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_target_nb_samples|node|study|default';
  $field_group->group_name = 'group_target_nb_samples';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'study';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_general_design';
  $field_group->data = array(
    'label' => 'Target Number of Biological Samples',
    'weight' => '45',
    'children' => array(),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Target Number of Biological Samples',
      'instance_settings' => array(
        'classes' => '',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_target_nb_samples|node|study|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_target_nb_samples|node|study|footer_area';
  $field_group->group_name = 'group_target_nb_samples';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'study';
  $field_group->mode = 'footer_area';
  $field_group->parent_name = 'group_general_design';
  $field_group->data = array(
    'label' => 'Target Number of Biological Samples',
    'weight' => '45',
    'children' => array(),
    'format_type' => 'hidden',
    'format_settings' => array(
      'label' => 'Target Number of Biological Samples',
      'instance_settings' => array(
        'classes' => '',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_target_nb_samples|node|study|footer_area'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_target_nb_samples|node|study|form';
  $field_group->group_name = 'group_target_nb_samples';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'study';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_general_design';
  $field_group->data = array(
    'label' => 'Target Number of Biological Samples',
    'weight' => '11',
    'children' => array(
      0 => 'field_no_limits_samples',
      1 => 'field_samples_supp_info',
      2 => 'field_target_number_biosamples',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'open',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_target_nb_samples|node|study|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_target_nb_samples|node|study|right_area';
  $field_group->group_name = 'group_target_nb_samples';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'study';
  $field_group->mode = 'right_area';
  $field_group->parent_name = 'group_general_design';
  $field_group->data = array(
    'label' => 'Target Number of Biological Samples',
    'weight' => '45',
    'children' => array(),
    'format_type' => 'hidden',
    'format_settings' => array(
      'label' => 'Target Number of Biological Samples',
      'instance_settings' => array(
        'classes' => '',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_target_nb_samples|node|study|right_area'] = $field_group;

  return $export;
}
