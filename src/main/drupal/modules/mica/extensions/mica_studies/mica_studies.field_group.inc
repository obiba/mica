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

  $field_group = new stdClass;
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_details|node|study|default';
  $field_group->group_name = 'group_details';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'study';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Details',
    'weight' => '3',
    'children' => array(
      0 => 'mica_study_information',
      1 => 'mica_study_documents',
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
  $export['group_details|node|study|default'] = $field_group;

  $field_group = new stdClass;
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_general_info|node|study|default';
  $field_group->group_name = 'group_general_info';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'study';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'General Information',
    'weight' => '2',
    'children' => array(
      0 => 'field_full_name',
      1 => 'field_website',
      2 => 'field_investigator',
      3 => 'field_contact',
      4 => 'field_target_number_participants',
      5 => 'field_target_number_biosamples',
      6 => 'field_p3g_observatory_link',
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
  $export['group_general_info|node|study|default'] = $field_group;

  $field_group = new stdClass;
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_general_info|node|study|form';
  $field_group->group_name = 'group_general_info';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'study';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'General Information',
    'weight' => '2',
    'children' => array(
      0 => 'field_full_name',
      1 => 'field_website',
      2 => 'field_investigator',
      3 => 'field_contact',
      4 => 'field_target_number_participants',
      5 => 'field_target_number_biosamples',
      6 => 'field_p3g_observatory_link',
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
  $export['group_general_info|node|study|form'] = $field_group;

  $field_group = new stdClass;
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_governance|node|study_information|default';
  $field_group->group_name = 'group_governance';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'study_information';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Governance',
    'weight' => '2',
    'children' => array(
      0 => 'field_access',
      1 => 'field_access_other',
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
  $export['group_governance|node|study_information|default'] = $field_group;

  $field_group = new stdClass;
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_governance|node|study_information|form';
  $field_group->group_name = 'group_governance';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'study_information';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Governance',
    'weight' => '2',
    'children' => array(
      0 => 'field_access',
      1 => 'field_access_other',
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
  $export['group_governance|node|study_information|form'] = $field_group;

  $field_group = new stdClass;
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_method|node|study_information|default';
  $field_group->group_name = 'group_method';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'study_information';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Method',
    'weight' => '1',
    'children' => array(
      0 => 'field_design',
      1 => 'field_design_other',
      2 => 'field_design_target',
      3 => 'field_target_other',
      4 => 'field_selection_criteria',
      5 => 'field_study_country',
      6 => 'field_gender',
      7 => 'field_age_min',
      8 => 'field_age_max',
      9 => 'field_biosamples_collected',
      10 => 'field_biosamples_collected_other',
      11 => 'field_biosamples_tissues',
      12 => 'field_gwas_analysis',
      13 => 'field_gwas_number',
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
  $export['group_method|node|study_information|default'] = $field_group;

  $field_group = new stdClass;
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_method|node|study_information|form';
  $field_group->group_name = 'group_method';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'study_information';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Method',
    'weight' => '1',
    'children' => array(
      0 => 'field_design',
      1 => 'field_design_other',
      2 => 'field_design_target',
      3 => 'field_target_other',
      4 => 'field_selection_criteria',
      5 => 'field_study_country',
      6 => 'field_gender',
      7 => 'field_age_min',
      8 => 'field_age_max',
      9 => 'field_biosamples_collected',
      10 => 'field_biosamples_collected_other',
      11 => 'field_biosamples_tissues',
      12 => 'field_gwas_analysis',
      13 => 'field_gwas_number',
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
  $export['group_method|node|study_information|form'] = $field_group;

  $field_group = new stdClass;
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_status|node|study_information|default';
  $field_group->group_name = 'group_status';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'study_information';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Status',
    'weight' => '3',
    'children' => array(
      0 => 'field_status_start',
      1 => 'field_status_end',
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
  $export['group_status|node|study_information|default'] = $field_group;

  $field_group = new stdClass;
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_status|node|study_information|form';
  $field_group->group_name = 'group_status';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'study_information';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Status',
    'weight' => '3',
    'children' => array(
      0 => 'field_status_start',
      1 => 'field_status_end',
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
  $export['group_status|node|study_information|form'] = $field_group;

  return $export;
}
