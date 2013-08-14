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
  $field_group->identifier = 'group_datasets|node|data_collection_event|form';
  $field_group->group_name = 'group_datasets';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'data_collection_event';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Datasets',
    'weight' => '4',
    'children' => array(
      0 => 'field_dce_dataset',
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
  $export['group_datasets|node|data_collection_event|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_dce_data_collection|node|data_collection_event|form';
  $field_group->group_name = 'group_dce_data_collection';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'data_collection_event';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Data Collection',
    'weight' => '1',
    'children' => array(
      0 => 'field_dce_bio_samples_management',
      1 => 'field_dce_data_sources',
      2 => 'field_dce_data_sources_admin_db',
      3 => 'field_dce_data_sources_sp',
      4 => 'field_dce_samples_man_other_sp',
      5 => 'field_dce_tissues_sp',
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
  $export['group_dce_data_collection|node|data_collection_event|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_dce_documents|node|data_collection_event|default';
  $field_group->group_name = 'group_dce_documents';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'data_collection_event';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Documents',
    'weight' => '12',
    'children' => array(
      0 => 'field_dce_data_dictionaries',
      1 => 'field_dce_others',
      2 => 'field_dce_questionnaires',
      3 => 'field_dce_sops',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Documents',
      'instance_settings' => array(
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_dce_documents|node|data_collection_event|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_dce_documents|node|data_collection_event|form';
  $field_group->group_name = 'group_dce_documents';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'data_collection_event';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Documents',
    'weight' => '3',
    'children' => array(
      0 => 'field_dce_data_dictionaries',
      1 => 'field_dce_others',
      2 => 'field_dce_questionnaires',
      3 => 'field_dce_sops',
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
  $export['group_dce_documents|node|data_collection_event|form'] = $field_group;

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
      0 => 'group_nb_participants',
      1 => 'group_study_design',
      2 => 'group_study_timeline',
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
  $field_group->identifier = 'group_general_info|node|data_collection_event|form';
  $field_group->group_name = 'group_general_info';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'data_collection_event';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'General Information',
    'weight' => '0',
    'children' => array(
      0 => 'body',
      1 => 'field_dce_end_year',
      2 => 'field_dce_population',
      3 => 'field_dce_start_year',
      4 => 'field_dce_start_month',
      5 => 'field_dce_end_month',
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
  $export['group_general_info|node|data_collection_event|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_general_info|node|population|form';
  $field_group->group_name = 'group_general_info';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'population';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'General Information',
    'weight' => '0',
    'children' => array(
      0 => 'body',
      1 => 'field_pop_dce',
      2 => 'field_pop_study',
      3 => 'title',
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
  $export['group_general_info|node|population|form'] = $field_group;

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
  $field_group->identifier = 'group_marker_paper|node|study|form';
  $field_group->group_name = 'group_marker_paper';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'study';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_tabs';
  $field_group->data = array(
    'label' => 'Marker Paper',
    'weight' => '12',
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
        'description' => '',
      ),
      'formatter' => 'closed',
    ),
  );
  $export['group_marker_paper|node|study|form'] = $field_group;

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
      0 => 'group_nb_participants',
      1 => 'group_study_design',
      2 => 'group_study_timeline',
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
  $field_group->identifier = 'group_nb_participants|node|study|form';
  $field_group->group_name = 'group_nb_participants';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'study';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_methods';
  $field_group->data = array(
    'label' => 'Number of participants',
    'weight' => '7',
    'children' => array(
      0 => 'field_target_nb_supp_info',
      1 => 'group_target_nb_participants',
      2 => 'group_target_nb_samples',
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
  $export['group_nb_participants|node|study|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_pop_age|node|population|form';
  $field_group->group_name = 'group_pop_age';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'population';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_pop_selection_criteria';
  $field_group->data = array(
    'label' => 'Age',
    'weight' => '6',
    'children' => array(
      0 => 'field_pop_age_max',
      1 => 'field_pop_age_min',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Age',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_pop_age|node|population|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_pop_countries|node|population|form';
  $field_group->group_name = 'group_pop_countries';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'population';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_pop_selection_criteria';
  $field_group->data = array(
    'label' => 'Residence',
    'weight' => '7',
    'children' => array(
      0 => 'field_pop_country',
      1 => 'field_pop_territory',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Residence',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_pop_countries|node|population|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_pop_participants_number|node|population|form';
  $field_group->group_name = 'group_pop_participants_number';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'population';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Participants Number',
    'weight' => '3',
    'children' => array(
      0 => 'field_pop_no_lim_participants_s',
      1 => 'field_pop_no_limits_participants',
      2 => 'field_pop_participants_nb',
      3 => 'field_pop_participants_nb_s',
      4 => 'field_pop_participants_nb_supp_i',
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
  $export['group_pop_participants_number|node|population|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_pop_recruitment_procedures|node|population|form';
  $field_group->group_name = 'group_pop_recruitment_procedures';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'population';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Recruitment procedures',
    'weight' => '1',
    'children' => array(
      0 => 'field_pop_exist_study_part',
      1 => 'field_pop_general_pop_recruit',
      2 => 'field_pop_recruit_supp_info',
      3 => 'field_pop_recruitment_other',
      4 => 'field_pop_specific_pop',
      5 => 'field_pop_specific_pop_other_sp',
      6 => 'field_pop_src_recruit',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Recruitment procedures',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'collapsible',
    ),
  );
  $export['group_pop_recruitment_procedures|node|population|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_pop_selection_criteria|node|population|form';
  $field_group->group_name = 'group_pop_selection_criteria';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'population';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Selection Criteria / Characteristics of the population',
    'weight' => '2',
    'children' => array(
      0 => 'field_pop_ethnic_origin',
      1 => 'field_pop_gender',
      2 => 'field_pop_health_status',
      3 => 'field_pop_partcipant_sel_supp_in',
      4 => 'field_pop_select_criteria',
      5 => 'field_pop_selection_others_sp',
      6 => 'group_pop_age',
      7 => 'group_pop_countries',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Selection Criteria / Characteristics of the population',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'collapsible',
    ),
  );
  $export['group_pop_selection_criteria|node|population|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_pop_supp_info|node|population|form';
  $field_group->group_name = 'group_pop_supp_info';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'population';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Supplementary Information',
    'weight' => '5',
    'children' => array(
      0 => 'field_pop_supp_infos',
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
  $export['group_pop_supp_info|node|population|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_study_design|node|study|form';
  $field_group->group_name = 'group_study_design';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'study';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_methods';
  $field_group->data = array(
    'label' => 'Study Design',
    'weight' => '6',
    'children' => array(
      0 => 'field_design',
      1 => 'field_design_other_sp',
      2 => 'field_info_design_follow_up',
      3 => 'field_recruitment',
      4 => 'field_recruitment_other_sp',
      5 => 'field_recruitment_supp_info',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Study Design',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'collapsible',
    ),
  );
  $export['group_study_design|node|study|form'] = $field_group;

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
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_study_name|node|study|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_study_timeline|node|study|form';
  $field_group->group_name = 'group_study_timeline';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'study';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_methods';
  $field_group->data = array(
    'label' => 'Study Timeline',
    'weight' => '8',
    'children' => array(
      0 => 'field_study_end_year',
      1 => 'field_study_start_year',
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
  $export['group_study_timeline|node|study|form'] = $field_group;

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
  $export['group_tabs|node|study|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_target_nb_participants|node|study|form';
  $field_group->group_name = 'group_target_nb_participants';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'study';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_nb_participants';
  $field_group->data = array(
    'label' => 'Target Number of Participants',
    'weight' => '8',
    'children' => array(
      0 => 'field_no_limits_participants',
      1 => 'field_target_number_participants',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Target Number of Participants',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_target_nb_participants|node|study|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_target_nb_samples|node|study|form';
  $field_group->group_name = 'group_target_nb_samples';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'study';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_nb_participants';
  $field_group->data = array(
    'label' => 'Target Number of Biological Samples',
    'weight' => '9',
    'children' => array(
      0 => 'field_no_limits_samples',
      1 => 'field_target_number_biosamples',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Target Number of Biological Samples',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_target_nb_samples|node|study|form'] = $field_group;

  return $export;
}
