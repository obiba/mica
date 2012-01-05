<?php
/**
 * @file
 * mica_dataschemas.features.field.inc
 */

/**
 * Implements hook_field_default_fields().
 */
function mica_dataschemas_field_default_fields() {
  $fields = array();

  // Exported field: 'node-dataschema-body'
  $fields['node-dataschema-body'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(
        0 => 'node',
      ),
      'field_name' => 'body',
      'foreign keys' => array(
        'format' => array(
          'columns' => array(
            'format' => 'format',
          ),
          'table' => 'filter_format',
        ),
      ),
      'indexes' => array(
        'format' => array(
          0 => 'format',
        ),
      ),
      'module' => 'text',
      'settings' => array(
        'field_description_infos' => array(
          'field_description' => 0,
          'field_description_body' => '',
          'field_description_value_type' => 'TEXT',
        ),
        'field_permissions' => array(
          'create' => 0,
          'edit' => 0,
          'edit own' => 0,
          'view' => 0,
          'view own' => 0,
        ),
        'variable_infos' => array(
          'variable' => 1,
          'variable_body' => '',
          'variable_value_type' => 'TEXT',
        ),
      ),
      'translatable' => '1',
      'type' => 'text_with_summary',
    ),
    'field_instance' => array(
      'bundle' => 'dataschema',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'custom_dimensions' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'custom_page' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'custom_variable' => array(
          'label' => 'hidden',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_plain',
          'weight' => '0',
        ),
        'default' => array(
          'label' => 'hidden',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => '0',
        ),
        'search_index' => array(
          'label' => 'hidden',
          'module' => 'text',
          'settings' => array(
            'trim_length' => '200',
          ),
          'type' => 'text_summary_or_trimmed',
          'weight' => '0',
        ),
        'search_result' => array(
          'label' => 'hidden',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => '0',
        ),
        'teaser' => array(
          'label' => 'hidden',
          'module' => 'text',
          'settings' => array(
            'trim_length' => '150',
          ),
          'type' => 'text_summary_or_trimmed',
          'weight' => '0',
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'body',
      'label' => 'Body',
      'required' => FALSE,
      'settings' => array(
        'display_summary' => TRUE,
        'text_processing' => 1,
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'module' => 'text',
        'settings' => array(
          'rows' => 20,
          'summary_rows' => 5,
        ),
        'type' => 'text_textarea_with_summary',
        'weight' => '1',
      ),
    ),
  );

  // Exported field: 'node-dataschema-field_variables'
  $fields['node-dataschema-field_variables'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_variables',
      'field_permissions' => array(
        'type' => '1',
      ),
      'foreign keys' => array(),
      'indexes' => array(
        'view_id' => array(
          0 => 'view_id',
        ),
      ),
      'module' => 'viewreference',
      'settings' => array(
        'append_id' => 0,
        'arguments' => array(
          'delimiter' => '/',
          'dsv_arguments' => 1,
          'label' => '!field_label arguments',
          'php_arguments' => 0,
          'rows' => '1',
        ),
        'field_description_infos' => array(
          'field_description' => 0,
          'field_description_body' => '',
          'field_description_value_type' => '',
        ),
        'field_permissions' => array(
          'create' => 0,
          'edit' => 0,
          'edit own' => 0,
          'view' => 0,
          'view own' => 0,
        ),
        'referenceable_views' => array(
          'archive:block' => 0,
          'archive:page' => 0,
          'backlinks:block' => 0,
          'backlinks:page' => 0,
          'calendar:block_1' => 0,
          'calendar:block_2' => 0,
          'calendar:page' => 0,
          'calendar:page_1' => 0,
          'calendar:page_2' => 0,
          'calendar:page_3' => 0,
          'comments_recent:block' => 0,
          'comments_recent:page' => 0,
          'community:page' => 0,
          'csv_contact_export:views_data_export_1' => 0,
          'csv_field_description_export:views_data_export_1' => 0,
          'csv_institution_export:views_data_export_1' => 0,
          'csv_study_export:views_data_export_1' => 0,
          'csv_study_information_export:views_data_export_1' => 0,
          'data_access:page' => 0,
          'data_access_admin:page' => 0,
          'data_access_committee:page' => 0,
          'dataschema_variables:page' => 'dataschema_variables:page',
          'dataschemas:page' => 0,
          'dataset_participant_variables:page' => 0,
          'dataset_studies:page' => 0,
          'datasets:feed' => 0,
          'datasets:page' => 0,
          'documents:page' => 0,
          'events:feed' => 0,
          'events:page' => 0,
          'events_calendar:block_1' => 0,
          'events_calendar:block_2' => 0,
          'events_calendar:page' => 0,
          'events_calendar:page_1' => 0,
          'events_calendar:page_2' => 0,
          'events_calendar:page_3' => 0,
          'feeds_log:page_1' => 0,
          'feeds_log:page_2' => 0,
          'feeds_log:page_3' => 0,
          'fields_description_search:page' => 0,
          'frontpage:feed' => 0,
          'frontpage:page' => 0,
          'glossary:attachment' => 0,
          'glossary:page' => 0,
          'my_data_access_requests:page' => 0,
          'news:page' => 0,
          'participant_variable_search:page' => 0,
          'project_dataschema:block' => 0,
          'project_pairings:page' => 0,
          'project_studies:block' => 0,
          'projects:page' => 0,
          'publications:page' => 0,
          'studies:page' => 0,
          'studies_search:page' => 0,
          'taxonomy_term:feed' => 0,
          'taxonomy_term:page' => 0,
          'teleconferences:page' => 0,
          'tracker:page' => 0,
          'variable_categories:block' => 0,
          'variable_dataschemas:block' => 0,
          'variable_missing_categories:block' => 0,
        ),
      ),
      'translatable' => '0',
      'type' => 'viewreference',
    ),
    'field_instance' => array(
      'bundle' => 'dataschema',
      'default_value' => array(
        0 => array(
          'view_id' => 'dataschema_variables:page',
          'arguments' => '',
        ),
      ),
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'custom_dimensions' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'custom_page' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'custom_variable' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '1',
        ),
        'default' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '1',
        ),
        'search_index' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '1',
        ),
        'search_result' => array(
          'label' => 'above',
          'module' => 'viewreference',
          'settings' => array(),
          'type' => 'viewreference_default',
          'weight' => '1',
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '0',
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_variables',
      'label' => 'Variables',
      'required' => 1,
      'settings' => array(
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 0,
        'module' => 'viewreference',
        'settings' => array(),
        'type' => 'viewreference_select',
        'weight' => '31',
      ),
    ),
  );

  // Exported field: 'node-dataschema_category-body'
  $fields['node-dataschema_category-body'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(
        0 => 'node',
      ),
      'field_name' => 'body',
      'foreign keys' => array(
        'format' => array(
          'columns' => array(
            'format' => 'format',
          ),
          'table' => 'filter_format',
        ),
      ),
      'indexes' => array(
        'format' => array(
          0 => 'format',
        ),
      ),
      'module' => 'text',
      'settings' => array(
        'field_description_infos' => array(
          'field_description' => 0,
          'field_description_body' => '',
          'field_description_value_type' => 'TEXT',
        ),
        'field_permissions' => array(
          'create' => 0,
          'edit' => 0,
          'edit own' => 0,
          'view' => 0,
          'view own' => 0,
        ),
        'variable_infos' => array(
          'variable' => 1,
          'variable_body' => '',
          'variable_value_type' => 'TEXT',
        ),
      ),
      'translatable' => '1',
      'type' => 'text_with_summary',
    ),
    'field_instance' => array(
      'bundle' => 'dataschema_category',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'custom_dimensions' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'custom_page' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'custom_variable' => array(
          'label' => 'hidden',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '2',
        ),
        'default' => array(
          'label' => 'hidden',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => '0',
        ),
        'teaser' => array(
          'label' => 'hidden',
          'module' => 'text',
          'settings' => array(
            'trim_length' => 600,
          ),
          'type' => 'text_summary_or_trimmed',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'body',
      'label' => 'Body',
      'required' => FALSE,
      'settings' => array(
        'display_summary' => TRUE,
        'text_processing' => 1,
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'module' => 'text',
        'settings' => array(
          'rows' => 20,
          'summary_rows' => 5,
        ),
        'type' => 'text_textarea_with_summary',
        'weight' => '31',
      ),
    ),
  );

  // Exported field: 'node-dataschema_category-field_is_missing'
  $fields['node-dataschema_category-field_is_missing'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_is_missing',
      'foreign keys' => array(),
      'indexes' => array(
        'value' => array(
          0 => 'value',
        ),
      ),
      'module' => 'list',
      'settings' => array(
        'allowed_values' => array(
          0 => '',
          1 => '',
        ),
        'allowed_values_function' => '',
        'field_description_infos' => array(
          'field_description' => 0,
          'field_description_body' => '',
          'field_description_value_type' => '',
        ),
        'field_permissions' => array(
          'create' => 0,
          'edit' => 0,
          'edit own' => 0,
          'view' => 0,
          'view own' => 0,
        ),
      ),
      'translatable' => '0',
      'type' => 'list_boolean',
    ),
    'field_instance' => array(
      'bundle' => 'dataschema_category',
      'default_value' => array(
        0 => array(
          'value' => 0,
        ),
      ),
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'custom_dimensions' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'custom_page' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'custom_variable' => array(
          'label' => 'inline',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '0',
        ),
        'default' => array(
          'label' => 'above',
          'module' => 'list',
          'settings' => array(),
          'type' => 'list_default',
          'weight' => '2',
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_is_missing',
      'label' => 'Missing',
      'required' => 0,
      'settings' => array(
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'options',
        'settings' => array(
          'display_label' => 0,
        ),
        'type' => 'options_onoff',
        'weight' => '33',
      ),
    ),
  );

  // Exported field: 'node-dataschema_category-field_name'
  $fields['node-dataschema_category-field_name'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_name',
      'foreign keys' => array(
        'format' => array(
          'columns' => array(
            'format' => 'format',
          ),
          'table' => 'filter_format',
        ),
      ),
      'indexes' => array(
        'format' => array(
          0 => 'format',
        ),
      ),
      'module' => 'text',
      'settings' => array(
        'field_description_infos' => array(
          'field_description' => 0,
          'field_description_body' => '',
          'field_description_value_type' => 'TEXT',
        ),
        'field_permissions' => array(
          'create' => 0,
          'edit' => 0,
          'edit own' => 0,
          'view' => 0,
          'view own' => 0,
        ),
        'max_length' => '255',
      ),
      'translatable' => '0',
      'type' => 'text',
    ),
    'field_instance' => array(
      'bundle' => 'dataschema_category',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'custom_dimensions' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'custom_page' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'custom_variable' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '1',
        ),
        'default' => array(
          'label' => 'above',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => '1',
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_name',
      'label' => 'Name',
      'required' => 0,
      'settings' => array(
        'text_processing' => '0',
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'text',
        'settings' => array(
          'size' => '60',
        ),
        'type' => 'text_textfield',
        'weight' => '32',
      ),
    ),
  );

  // Exported field: 'node-dataschema_variable-body'
  $fields['node-dataschema_variable-body'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(
        0 => 'node',
      ),
      'field_name' => 'body',
      'foreign keys' => array(
        'format' => array(
          'columns' => array(
            'format' => 'format',
          ),
          'table' => 'filter_format',
        ),
      ),
      'indexes' => array(
        'format' => array(
          0 => 'format',
        ),
      ),
      'module' => 'text',
      'settings' => array(
        'field_description_infos' => array(
          'field_description' => 0,
          'field_description_body' => '',
          'field_description_value_type' => 'TEXT',
        ),
        'field_permissions' => array(
          'create' => 0,
          'edit' => 0,
          'edit own' => 0,
          'view' => 0,
          'view own' => 0,
        ),
        'variable_infos' => array(
          'variable' => 1,
          'variable_body' => '',
          'variable_value_type' => 'TEXT',
        ),
      ),
      'translatable' => '1',
      'type' => 'text_with_summary',
    ),
    'field_instance' => array(
      'bundle' => 'dataschema_variable',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'custom_dimensions' => array(
          'label' => 'hidden',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '20',
        ),
        'custom_page' => array(
          'label' => 'hidden',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => '0',
        ),
        'custom_variable' => array(
          'label' => 'hidden',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => '0',
        ),
        'default' => array(
          'label' => 'hidden',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => '0',
        ),
        'teaser' => array(
          'label' => 'hidden',
          'module' => 'text',
          'settings' => array(
            'trim_length' => 600,
          ),
          'type' => 'text_summary_or_trimmed',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'body',
      'label' => 'Body',
      'required' => FALSE,
      'settings' => array(
        'display_summary' => TRUE,
        'text_processing' => 1,
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'module' => 'text',
        'settings' => array(
          'rows' => 20,
          'summary_rows' => 5,
        ),
        'type' => 'text_textarea_with_summary',
        'weight' => '1',
      ),
    ),
  );

  // Exported field: 'node-dataschema_variable-field_dataschema_ref'
  $fields['node-dataschema_variable-field_dataschema_ref'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '-1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_dataschema_ref',
      'foreign keys' => array(
        'nid' => array(
          'columns' => array(
            'nid' => 'nid',
          ),
          'table' => 'node',
        ),
      ),
      'indexes' => array(
        'nid' => array(
          0 => 'nid',
        ),
      ),
      'module' => 'node_reference',
      'settings' => array(
        'field_description_infos' => array(
          'field_description' => 0,
          'field_description_body' => '',
          'field_description_value_type' => '',
        ),
        'field_permissions' => array(
          'create' => 0,
          'edit' => 0,
          'edit own' => 0,
          'view' => 0,
          'view own' => 0,
        ),
        'referenceable_types' => array(
          'article' => 0,
          'blog' => 0,
          'contact' => 0,
          'data_access_request' => 0,
          'data_access_review' => 0,
          'dataschema' => 'dataschema',
          'dataschema_category' => 0,
          'dataschema_variable' => 0,
          'dataset' => 0,
          'documents' => 0,
          'event' => 0,
          'field_description' => 0,
          'forum' => 0,
          'institution' => 0,
          'page' => 0,
          'pairing' => 0,
          'panel' => 0,
          'participant_variable' => 0,
          'project' => 0,
          'publication' => 0,
          'study' => 0,
          'study_documents' => 0,
          'study_information' => 0,
          'teleconference' => 0,
        ),
        'view' => array(
          'args' => array(),
          'display_name' => '',
          'view_name' => '',
        ),
      ),
      'translatable' => '0',
      'type' => 'node_reference',
    ),
    'field_instance' => array(
      'bundle' => 'dataschema_variable',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'custom_dimensions' => array(
          'label' => 'inline',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '14',
        ),
        'custom_page' => array(
          'label' => 'inline',
          'module' => 'node_reference',
          'settings' => array(
            'node_reference_view_mode' => 'full',
          ),
          'type' => 'node_reference_node',
          'weight' => '1',
        ),
        'custom_variable' => array(
          'label' => 'inline',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '2',
        ),
        'default' => array(
          'label' => 'inline',
          'module' => 'node_reference',
          'settings' => array(),
          'type' => 'node_reference_default',
          'weight' => '1',
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'display_label' => '',
      'entity_type' => 'node',
      'field_name' => 'field_dataschema_ref',
      'label' => 'DataSchema',
      'required' => 0,
      'settings' => array(
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'options',
        'settings' => array(),
        'type' => 'options_buttons',
        'weight' => '2',
      ),
    ),
  );

  // Exported field: 'node-dataschema_variable-field_dim_biochemical_measures'
  $fields['node-dataschema_variable-field_dim_biochemical_measures'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '-1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_dim_biochemical_measures',
      'foreign keys' => array(
        'tid' => array(
          'columns' => array(
            'tid' => 'tid',
          ),
          'table' => 'taxonomy_term_data',
        ),
      ),
      'indexes' => array(
        'tid' => array(
          0 => 'tid',
        ),
      ),
      'module' => 'taxonomy',
      'settings' => array(
        'allowed_values' => array(
          0 => array(
            'parent' => '0',
            'vocabulary' => 'biochemical_measures',
          ),
        ),
        'field_description_infos' => array(
          'field_description' => 0,
          'field_description_body' => '',
          'field_description_value_type' => '',
        ),
        'field_permissions' => array(
          'create' => 0,
          'edit' => 0,
          'edit own' => 0,
          'view' => 0,
          'view own' => 0,
        ),
        'options_list_callback' => 'content_taxonomy_allowed_values',
      ),
      'translatable' => '0',
      'type' => 'taxonomy_term_reference',
    ),
    'field_instance' => array(
      'bundle' => 'dataschema_variable',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'custom_dimensions' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'custom_page' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'custom_variable' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'default' => array(
          'label' => 'above',
          'module' => 'taxonomy',
          'settings' => array(),
          'type' => 'taxonomy_term_reference_link',
          'weight' => 33,
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_dim_biochemical_measures',
      'label' => 'Biochemical measures',
      'required' => 0,
      'settings' => array(
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 0,
        'module' => 'tagging',
        'settings' => array(
          'autocomplete_path' => 'taxonomy/autocomplete',
          'size' => 40,
        ),
        'type' => 'tagging_taxonomy_autocomplete',
        'weight' => '81',
      ),
    ),
  );

  // Exported field: 'node-dataschema_variable-field_dim_body_functions_meas'
  $fields['node-dataschema_variable-field_dim_body_functions_meas'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '-1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_dim_body_functions_meas',
      'foreign keys' => array(
        'tid' => array(
          'columns' => array(
            'tid' => 'tid',
          ),
          'table' => 'taxonomy_term_data',
        ),
      ),
      'indexes' => array(
        'tid' => array(
          0 => 'tid',
        ),
      ),
      'module' => 'taxonomy',
      'settings' => array(
        'allowed_values' => array(
          0 => array(
            'parent' => '0',
            'vocabulary' => 'body_functions_measures',
          ),
        ),
        'field_description_infos' => array(
          'field_description' => 0,
          'field_description_body' => '',
          'field_description_value_type' => '',
        ),
        'field_permissions' => array(
          'create' => 0,
          'edit' => 0,
          'edit own' => 0,
          'view' => 0,
          'view own' => 0,
        ),
        'options_list_callback' => 'content_taxonomy_allowed_values',
      ),
      'translatable' => '0',
      'type' => 'taxonomy_term_reference',
    ),
    'field_instance' => array(
      'bundle' => 'dataschema_variable',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'custom_dimensions' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'custom_page' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'custom_variable' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'default' => array(
          'label' => 'above',
          'module' => 'taxonomy',
          'settings' => array(),
          'type' => 'taxonomy_term_reference_link',
          'weight' => 34,
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_dim_body_functions_meas',
      'label' => 'Body functions and measures',
      'required' => 0,
      'settings' => array(
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 0,
        'module' => 'tagging',
        'settings' => array(
          'autocomplete_path' => 'taxonomy/autocomplete',
          'size' => 40,
        ),
        'type' => 'tagging_taxonomy_autocomplete',
        'weight' => '73',
      ),
    ),
  );

  // Exported field: 'node-dataschema_variable-field_dim_class'
  $fields['node-dataschema_variable-field_dim_class'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '-1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_dim_class',
      'foreign keys' => array(
        'tid' => array(
          'columns' => array(
            'tid' => 'tid',
          ),
          'table' => 'taxonomy_term_data',
        ),
      ),
      'indexes' => array(
        'tid' => array(
          0 => 'tid',
        ),
      ),
      'module' => 'taxonomy',
      'settings' => array(
        'allowed_values' => array(
          0 => array(
            'parent' => '0',
            'vocabulary' => 'class',
          ),
        ),
        'field_description_infos' => array(
          'field_description' => 0,
          'field_description_body' => '',
          'field_description_value_type' => '',
        ),
        'field_permissions' => array(
          'create' => 0,
          'edit' => 0,
          'edit own' => 0,
          'view' => 0,
          'view own' => 0,
        ),
        'options_list_callback' => 'content_taxonomy_allowed_values',
      ),
      'translatable' => '0',
      'type' => 'taxonomy_term_reference',
    ),
    'field_instance' => array(
      'bundle' => 'dataschema_variable',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'custom_dimensions' => array(
          'label' => 'above',
          'module' => 'taxonomy',
          'settings' => array(),
          'type' => 'taxonomy_term_reference_plain',
          'weight' => '2',
        ),
        'custom_page' => array(
          'label' => 'inline',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '10',
        ),
        'custom_variable' => array(
          'label' => 'inline',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '7',
        ),
        'default' => array(
          'label' => 'inline',
          'module' => 'taxonomy',
          'settings' => array(),
          'type' => 'taxonomy_term_reference_link',
          'weight' => '6',
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_dim_class',
      'label' => 'Class',
      'required' => 0,
      'settings' => array(
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'tagging',
        'settings' => array(
          'autocomplete_path' => 'taxonomy/autocomplete',
          'size' => 60,
        ),
        'type' => 'tagging_taxonomy_autocomplete',
        'weight' => '87',
      ),
    ),
  );

  // Exported field: 'node-dataschema_variable-field_dim_collection_mode'
  $fields['node-dataschema_variable-field_dim_collection_mode'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '-1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_dim_collection_mode',
      'foreign keys' => array(
        'tid' => array(
          'columns' => array(
            'tid' => 'tid',
          ),
          'table' => 'taxonomy_term_data',
        ),
      ),
      'indexes' => array(
        'tid' => array(
          0 => 'tid',
        ),
      ),
      'module' => 'taxonomy',
      'settings' => array(
        'allowed_values' => array(
          0 => array(
            'parent' => '0',
            'vocabulary' => 'collection_mode',
          ),
        ),
        'field_description_infos' => array(
          'field_description' => 0,
          'field_description_body' => '',
          'field_description_value_type' => '',
        ),
        'field_permissions' => array(
          'create' => 0,
          'edit' => 0,
          'edit own' => 0,
          'view' => 0,
          'view own' => 0,
        ),
        'options_list_callback' => 'content_taxonomy_allowed_values',
      ),
      'translatable' => '0',
      'type' => 'taxonomy_term_reference',
    ),
    'field_instance' => array(
      'bundle' => 'dataschema_variable',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'custom_dimensions' => array(
          'label' => 'above',
          'module' => 'taxonomy',
          'settings' => array(),
          'type' => 'taxonomy_term_reference_plain',
          'weight' => '9',
        ),
        'custom_page' => array(
          'label' => 'inline',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '19',
        ),
        'custom_variable' => array(
          'label' => 'inline',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '13',
        ),
        'default' => array(
          'label' => 'inline',
          'module' => 'taxonomy',
          'settings' => array(),
          'type' => 'taxonomy_term_reference_plain',
          'weight' => '12',
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_dim_collection_mode',
      'label' => 'Collection mode',
      'required' => 0,
      'settings' => array(
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'tagging',
        'settings' => array(
          'autocomplete_path' => 'taxonomy/autocomplete',
          'size' => 60,
        ),
        'type' => 'tagging_taxonomy_autocomplete',
        'weight' => '82',
      ),
    ),
  );

  // Exported field: 'node-dataschema_variable-field_dim_disease_history'
  $fields['node-dataschema_variable-field_dim_disease_history'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '-1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_dim_disease_history',
      'foreign keys' => array(
        'tid' => array(
          'columns' => array(
            'tid' => 'tid',
          ),
          'table' => 'taxonomy_term_data',
        ),
      ),
      'indexes' => array(
        'tid' => array(
          0 => 'tid',
        ),
      ),
      'module' => 'taxonomy',
      'settings' => array(
        'allowed_values' => array(
          0 => array(
            'parent' => '0',
            'vocabulary' => 'disease_history',
          ),
        ),
        'field_description_infos' => array(
          'field_description' => 0,
          'field_description_body' => '',
          'field_description_value_type' => '',
        ),
        'field_permissions' => array(
          'create' => 0,
          'edit' => 0,
          'edit own' => 0,
          'view' => 0,
          'view own' => 0,
        ),
        'options_list_callback' => 'content_taxonomy_allowed_values',
      ),
      'translatable' => '0',
      'type' => 'taxonomy_term_reference',
    ),
    'field_instance' => array(
      'bundle' => 'dataschema_variable',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'custom_dimensions' => array(
          'label' => 'above',
          'module' => 'taxonomy',
          'settings' => array(),
          'type' => 'taxonomy_term_reference_plain',
          'weight' => '0',
        ),
        'custom_page' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'custom_variable' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'default' => array(
          'label' => 'above',
          'module' => 'taxonomy',
          'settings' => array(),
          'type' => 'taxonomy_term_reference_link',
          'weight' => 24,
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_dim_disease_history',
      'label' => 'Disease history',
      'required' => 0,
      'settings' => array(
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 0,
        'module' => 'tagging',
        'settings' => array(
          'autocomplete_path' => 'taxonomy/autocomplete',
          'size' => 40,
        ),
        'type' => 'tagging_taxonomy_autocomplete',
        'weight' => '74',
      ),
    ),
  );

  // Exported field: 'node-dataschema_variable-field_dim_environmental_exp'
  $fields['node-dataschema_variable-field_dim_environmental_exp'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '-1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_dim_environmental_exp',
      'foreign keys' => array(
        'tid' => array(
          'columns' => array(
            'tid' => 'tid',
          ),
          'table' => 'taxonomy_term_data',
        ),
      ),
      'indexes' => array(
        'tid' => array(
          0 => 'tid',
        ),
      ),
      'module' => 'taxonomy',
      'settings' => array(
        'allowed_values' => array(
          0 => array(
            'parent' => '0',
            'vocabulary' => 'environmental_exposures',
          ),
        ),
        'field_description_infos' => array(
          'field_description' => 0,
          'field_description_body' => '',
          'field_description_value_type' => '',
        ),
        'field_permissions' => array(
          'create' => 0,
          'edit' => 0,
          'edit own' => 0,
          'view' => 0,
          'view own' => 0,
        ),
        'options_list_callback' => 'content_taxonomy_allowed_values',
      ),
      'translatable' => '0',
      'type' => 'taxonomy_term_reference',
    ),
    'field_instance' => array(
      'bundle' => 'dataschema_variable',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'custom_dimensions' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'custom_page' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'custom_variable' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'default' => array(
          'label' => 'above',
          'module' => 'taxonomy',
          'settings' => array(),
          'type' => 'taxonomy_term_reference_link',
          'weight' => 35,
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_dim_environmental_exp',
      'label' => 'Environmental exposures',
      'required' => 0,
      'settings' => array(
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 0,
        'module' => 'tagging',
        'settings' => array(
          'autocomplete_path' => 'taxonomy/autocomplete',
          'size' => 40,
        ),
        'type' => 'tagging_taxonomy_autocomplete',
        'weight' => '80',
      ),
    ),
  );

  // Exported field: 'node-dataschema_variable-field_dim_format'
  $fields['node-dataschema_variable-field_dim_format'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '-1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_dim_format',
      'foreign keys' => array(
        'tid' => array(
          'columns' => array(
            'tid' => 'tid',
          ),
          'table' => 'taxonomy_term_data',
        ),
      ),
      'indexes' => array(
        'tid' => array(
          0 => 'tid',
        ),
      ),
      'module' => 'taxonomy',
      'settings' => array(
        'allowed_values' => array(
          0 => array(
            'parent' => '0',
            'vocabulary' => 'format',
          ),
        ),
        'field_description_infos' => array(
          'field_description' => 0,
          'field_description_body' => '',
          'field_description_value_type' => '',
        ),
        'field_permissions' => array(
          'create' => 0,
          'edit' => 0,
          'edit own' => 0,
          'view' => 0,
          'view own' => 0,
        ),
        'options_list_callback' => 'content_taxonomy_allowed_values',
      ),
      'translatable' => '0',
      'type' => 'taxonomy_term_reference',
    ),
    'field_instance' => array(
      'bundle' => 'dataschema_variable',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'custom_dimensions' => array(
          'label' => 'above',
          'module' => 'taxonomy',
          'settings' => array(),
          'type' => 'taxonomy_term_reference_plain',
          'weight' => '1',
        ),
        'custom_page' => array(
          'label' => 'inline',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '20',
        ),
        'custom_variable' => array(
          'label' => 'inline',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '11',
        ),
        'default' => array(
          'label' => 'inline',
          'module' => 'taxonomy',
          'settings' => array(),
          'type' => 'taxonomy_term_reference_plain',
          'weight' => '11',
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_dim_format',
      'label' => 'Format',
      'required' => 0,
      'settings' => array(
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'tagging',
        'settings' => array(
          'autocomplete_path' => 'taxonomy/autocomplete',
          'size' => 60,
        ),
        'type' => 'tagging_taxonomy_autocomplete',
        'weight' => '86',
      ),
    ),
  );

  // Exported field: 'node-dataschema_variable-field_dim_life_habits_behaviours'
  $fields['node-dataschema_variable-field_dim_life_habits_behaviours'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '-1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_dim_life_habits_behaviours',
      'foreign keys' => array(
        'tid' => array(
          'columns' => array(
            'tid' => 'tid',
          ),
          'table' => 'taxonomy_term_data',
        ),
      ),
      'indexes' => array(
        'tid' => array(
          0 => 'tid',
        ),
      ),
      'module' => 'taxonomy',
      'settings' => array(
        'allowed_values' => array(
          0 => array(
            'parent' => '0',
            'vocabulary' => 'life_habits_behaviours',
          ),
        ),
        'field_description_infos' => array(
          'field_description' => 0,
          'field_description_body' => '',
          'field_description_value_type' => '',
        ),
        'field_permissions' => array(
          'create' => 0,
          'edit' => 0,
          'edit own' => 0,
          'view' => 0,
          'view own' => 0,
        ),
        'options_list_callback' => 'content_taxonomy_allowed_values',
      ),
      'translatable' => '0',
      'type' => 'taxonomy_term_reference',
    ),
    'field_instance' => array(
      'bundle' => 'dataschema_variable',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'custom_dimensions' => array(
          'label' => 'above',
          'module' => 'taxonomy',
          'settings' => array(),
          'type' => 'taxonomy_term_reference_plain',
          'weight' => '0',
        ),
        'custom_page' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'custom_variable' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'default' => array(
          'label' => 'above',
          'module' => 'taxonomy',
          'settings' => array(),
          'type' => 'taxonomy_term_reference_link',
          'weight' => 26,
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_dim_life_habits_behaviours',
      'label' => 'Life habits / Behaviours',
      'required' => 0,
      'settings' => array(
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 0,
        'module' => 'tagging',
        'settings' => array(
          'autocomplete_path' => 'taxonomy/autocomplete',
          'size' => 60,
        ),
        'type' => 'tagging_taxonomy_autocomplete',
        'weight' => '72',
      ),
    ),
  );

  // Exported field: 'node-dataschema_variable-field_dim_medication'
  $fields['node-dataschema_variable-field_dim_medication'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '-1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_dim_medication',
      'foreign keys' => array(
        'tid' => array(
          'columns' => array(
            'tid' => 'tid',
          ),
          'table' => 'taxonomy_term_data',
        ),
      ),
      'indexes' => array(
        'tid' => array(
          0 => 'tid',
        ),
      ),
      'module' => 'taxonomy',
      'settings' => array(
        'allowed_values' => array(
          0 => array(
            'parent' => '0',
            'vocabulary' => 'medication',
          ),
        ),
        'field_description_infos' => array(
          'field_description' => 0,
          'field_description_body' => '',
          'field_description_value_type' => '',
        ),
        'field_permissions' => array(
          'create' => 0,
          'edit' => 0,
          'edit own' => 0,
          'view' => 0,
          'view own' => 0,
        ),
        'options_list_callback' => 'content_taxonomy_allowed_values',
      ),
      'translatable' => '0',
      'type' => 'taxonomy_term_reference',
    ),
    'field_instance' => array(
      'bundle' => 'dataschema_variable',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'custom_dimensions' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'custom_page' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'custom_variable' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'default' => array(
          'label' => 'above',
          'module' => 'taxonomy',
          'settings' => array(),
          'type' => 'taxonomy_term_reference_link',
          'weight' => 30,
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_dim_medication',
      'label' => 'Medication',
      'required' => 0,
      'settings' => array(
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 0,
        'module' => 'tagging',
        'settings' => array(
          'autocomplete_path' => 'taxonomy/autocomplete',
          'size' => 40,
        ),
        'type' => 'tagging_taxonomy_autocomplete',
        'weight' => '79',
      ),
    ),
  );

  // Exported field: 'node-dataschema_variable-field_dim_period'
  $fields['node-dataschema_variable-field_dim_period'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '-1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_dim_period',
      'foreign keys' => array(
        'tid' => array(
          'columns' => array(
            'tid' => 'tid',
          ),
          'table' => 'taxonomy_term_data',
        ),
      ),
      'indexes' => array(
        'tid' => array(
          0 => 'tid',
        ),
      ),
      'module' => 'taxonomy',
      'settings' => array(
        'allowed_values' => array(
          0 => array(
            'parent' => '0',
            'vocabulary' => 'period',
          ),
        ),
        'field_description_infos' => array(
          'field_description' => 0,
          'field_description_body' => '',
          'field_description_value_type' => '',
        ),
        'field_permissions' => array(
          'create' => 0,
          'edit' => 0,
          'edit own' => 0,
          'view' => 0,
          'view own' => 0,
        ),
        'options_list_callback' => 'content_taxonomy_allowed_values',
      ),
      'translatable' => '0',
      'type' => 'taxonomy_term_reference',
    ),
    'field_instance' => array(
      'bundle' => 'dataschema_variable',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'custom_dimensions' => array(
          'label' => 'above',
          'module' => 'taxonomy',
          'settings' => array(),
          'type' => 'taxonomy_term_reference_plain',
          'weight' => '6',
        ),
        'custom_page' => array(
          'label' => 'inline',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '13',
        ),
        'custom_variable' => array(
          'label' => 'inline',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '19',
        ),
        'default' => array(
          'label' => 'inline',
          'module' => 'taxonomy',
          'settings' => array(),
          'type' => 'taxonomy_term_reference_plain',
          'weight' => '18',
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_dim_period',
      'label' => 'Period',
      'required' => 0,
      'settings' => array(
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'tagging',
        'settings' => array(
          'autocomplete_path' => 'taxonomy/autocomplete',
          'size' => 60,
        ),
        'type' => 'tagging_taxonomy_autocomplete',
        'weight' => '89',
      ),
    ),
  );

  // Exported field: 'node-dataschema_variable-field_dim_reproductive_history'
  $fields['node-dataschema_variable-field_dim_reproductive_history'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '-1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_dim_reproductive_history',
      'foreign keys' => array(
        'tid' => array(
          'columns' => array(
            'tid' => 'tid',
          ),
          'table' => 'taxonomy_term_data',
        ),
      ),
      'indexes' => array(
        'tid' => array(
          0 => 'tid',
        ),
      ),
      'module' => 'taxonomy',
      'settings' => array(
        'allowed_values' => array(
          0 => array(
            'parent' => '0',
            'vocabulary' => 'reproductive_history',
          ),
        ),
        'field_description_infos' => array(
          'field_description' => 0,
          'field_description_body' => '',
          'field_description_value_type' => '',
        ),
        'field_permissions' => array(
          'create' => 0,
          'edit' => 0,
          'edit own' => 0,
          'view' => 0,
          'view own' => 0,
        ),
        'options_list_callback' => 'content_taxonomy_allowed_values',
      ),
      'translatable' => '0',
      'type' => 'taxonomy_term_reference',
    ),
    'field_instance' => array(
      'bundle' => 'dataschema_variable',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'custom_dimensions' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'custom_page' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'custom_variable' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'default' => array(
          'label' => 'above',
          'module' => 'taxonomy',
          'settings' => array(),
          'type' => 'taxonomy_term_reference_link',
          'weight' => 31,
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_dim_reproductive_history',
      'label' => 'Reproductive history',
      'required' => 0,
      'settings' => array(
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 0,
        'module' => 'tagging',
        'settings' => array(
          'autocomplete_path' => 'taxonomy/autocomplete',
          'size' => 60,
        ),
        'type' => 'tagging_taxonomy_autocomplete',
        'weight' => '76',
      ),
    ),
  );

  // Exported field: 'node-dataschema_variable-field_dim_sample'
  $fields['node-dataschema_variable-field_dim_sample'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '-1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_dim_sample',
      'foreign keys' => array(
        'tid' => array(
          'columns' => array(
            'tid' => 'tid',
          ),
          'table' => 'taxonomy_term_data',
        ),
      ),
      'indexes' => array(
        'tid' => array(
          0 => 'tid',
        ),
      ),
      'module' => 'taxonomy',
      'settings' => array(
        'allowed_values' => array(
          0 => array(
            'parent' => '0',
            'vocabulary' => 'sample',
          ),
        ),
        'field_description_infos' => array(
          'field_description' => 0,
          'field_description_body' => '',
          'field_description_value_type' => '',
        ),
        'field_permissions' => array(
          'create' => 0,
          'edit' => 0,
          'edit own' => 0,
          'view' => 0,
          'view own' => 0,
        ),
        'options_list_callback' => 'content_taxonomy_allowed_values',
      ),
      'translatable' => '0',
      'type' => 'taxonomy_term_reference',
    ),
    'field_instance' => array(
      'bundle' => 'dataschema_variable',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'custom_dimensions' => array(
          'label' => 'above',
          'module' => 'taxonomy',
          'settings' => array(),
          'type' => 'taxonomy_term_reference_plain',
          'weight' => '7',
        ),
        'custom_page' => array(
          'label' => 'inline',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '12',
        ),
        'custom_variable' => array(
          'label' => 'inline',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '20',
        ),
        'default' => array(
          'label' => 'inline',
          'module' => 'taxonomy',
          'settings' => array(),
          'type' => 'taxonomy_term_reference_plain',
          'weight' => '19',
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_dim_sample',
      'label' => 'Sample',
      'required' => 0,
      'settings' => array(
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'tagging',
        'settings' => array(
          'autocomplete_path' => 'taxonomy/autocomplete',
          'size' => 60,
        ),
        'type' => 'tagging_taxonomy_autocomplete',
        'weight' => '90',
      ),
    ),
  );

  // Exported field: 'node-dataschema_variable-field_dim_sociodemo_charact'
  $fields['node-dataschema_variable-field_dim_sociodemo_charact'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '-1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_dim_sociodemo_charact',
      'foreign keys' => array(
        'tid' => array(
          'columns' => array(
            'tid' => 'tid',
          ),
          'table' => 'taxonomy_term_data',
        ),
      ),
      'indexes' => array(
        'tid' => array(
          0 => 'tid',
        ),
      ),
      'module' => 'taxonomy',
      'settings' => array(
        'allowed_values' => array(
          0 => array(
            'parent' => '0',
            'vocabulary' => 'sociodemographic_characteristics',
          ),
        ),
        'field_description_infos' => array(
          'field_description' => 0,
          'field_description_body' => '',
          'field_description_value_type' => '',
        ),
        'field_permissions' => array(
          'create' => 0,
          'edit' => 0,
          'edit own' => 0,
          'view' => 0,
          'view own' => 0,
        ),
        'options_list_callback' => 'content_taxonomy_allowed_values',
      ),
      'translatable' => '0',
      'type' => 'taxonomy_term_reference',
    ),
    'field_instance' => array(
      'bundle' => 'dataschema_variable',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'custom_dimensions' => array(
          'label' => 'above',
          'module' => 'taxonomy',
          'settings' => array(),
          'type' => 'taxonomy_term_reference_plain',
          'weight' => '0',
        ),
        'custom_page' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'custom_variable' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'default' => array(
          'label' => 'above',
          'module' => 'taxonomy',
          'settings' => array(),
          'type' => 'taxonomy_term_reference_link',
          'weight' => 29,
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_dim_sociodemo_charact',
      'label' => 'Sociodemographic characteristics',
      'required' => 0,
      'settings' => array(
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 0,
        'module' => 'tagging',
        'settings' => array(
          'autocomplete_path' => 'taxonomy/autocomplete',
          'size' => 60,
        ),
        'type' => 'tagging_taxonomy_autocomplete',
        'weight' => '75',
      ),
    ),
  );

  // Exported field: 'node-dataschema_variable-field_dim_source_of_info'
  $fields['node-dataschema_variable-field_dim_source_of_info'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '-1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_dim_source_of_info',
      'foreign keys' => array(
        'tid' => array(
          'columns' => array(
            'tid' => 'tid',
          ),
          'table' => 'taxonomy_term_data',
        ),
      ),
      'indexes' => array(
        'tid' => array(
          0 => 'tid',
        ),
      ),
      'module' => 'taxonomy',
      'settings' => array(
        'allowed_values' => array(
          0 => array(
            'parent' => '0',
            'vocabulary' => 'source_of_information',
          ),
        ),
        'field_description_infos' => array(
          'field_description' => 0,
          'field_description_body' => '',
          'field_description_value_type' => '',
        ),
        'field_permissions' => array(
          'create' => 0,
          'edit' => 0,
          'edit own' => 0,
          'view' => 0,
          'view own' => 0,
        ),
        'options_list_callback' => 'content_taxonomy_allowed_values',
      ),
      'translatable' => '0',
      'type' => 'taxonomy_term_reference',
    ),
    'field_instance' => array(
      'bundle' => 'dataschema_variable',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'custom_dimensions' => array(
          'label' => 'above',
          'module' => 'taxonomy',
          'settings' => array(),
          'type' => 'taxonomy_term_reference_plain',
          'weight' => '10',
        ),
        'custom_page' => array(
          'label' => 'inline',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '11',
        ),
        'custom_variable' => array(
          'label' => 'inline',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '18',
        ),
        'default' => array(
          'label' => 'inline',
          'module' => 'taxonomy',
          'settings' => array(),
          'type' => 'taxonomy_term_reference_plain',
          'weight' => '20',
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_dim_source_of_info',
      'label' => 'Source of information',
      'required' => 0,
      'settings' => array(
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'tagging',
        'settings' => array(
          'autocomplete_path' => 'taxonomy/autocomplete',
          'size' => 60,
        ),
        'type' => 'tagging_taxonomy_autocomplete',
        'weight' => '85',
      ),
    ),
  );

  // Exported field: 'node-dataschema_variable-field_dim_target'
  $fields['node-dataschema_variable-field_dim_target'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '-1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_dim_target',
      'foreign keys' => array(
        'tid' => array(
          'columns' => array(
            'tid' => 'tid',
          ),
          'table' => 'taxonomy_term_data',
        ),
      ),
      'indexes' => array(
        'tid' => array(
          0 => 'tid',
        ),
      ),
      'module' => 'taxonomy',
      'settings' => array(
        'allowed_values' => array(
          0 => array(
            'parent' => '0',
            'vocabulary' => 'target',
          ),
        ),
        'field_description_infos' => array(
          'field_description' => 0,
          'field_description_body' => '',
          'field_description_value_type' => '',
        ),
        'field_permissions' => array(
          'create' => 0,
          'edit' => 0,
          'edit own' => 0,
          'view' => 0,
          'view own' => 0,
        ),
        'options_list_callback' => 'content_taxonomy_allowed_values',
      ),
      'translatable' => '0',
      'type' => 'taxonomy_term_reference',
    ),
    'field_instance' => array(
      'bundle' => 'dataschema_variable',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'custom_dimensions' => array(
          'label' => 'above',
          'module' => 'taxonomy',
          'settings' => array(),
          'type' => 'taxonomy_term_reference_plain',
          'weight' => '3',
        ),
        'custom_page' => array(
          'label' => 'inline',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '16',
        ),
        'custom_variable' => array(
          'label' => 'inline',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '17',
        ),
        'default' => array(
          'label' => 'inline',
          'module' => 'taxonomy',
          'settings' => array(),
          'type' => 'taxonomy_term_reference_plain',
          'weight' => '15',
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_dim_target',
      'label' => 'Target',
      'required' => 0,
      'settings' => array(
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'tagging',
        'settings' => array(
          'autocomplete_path' => 'taxonomy/autocomplete',
          'size' => 60,
        ),
        'type' => 'tagging_taxonomy_autocomplete',
        'weight' => '83',
      ),
    ),
  );

  // Exported field: 'node-dataschema_variable-field_dim_target_gender'
  $fields['node-dataschema_variable-field_dim_target_gender'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '-1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_dim_target_gender',
      'foreign keys' => array(
        'tid' => array(
          'columns' => array(
            'tid' => 'tid',
          ),
          'table' => 'taxonomy_term_data',
        ),
      ),
      'indexes' => array(
        'tid' => array(
          0 => 'tid',
        ),
      ),
      'module' => 'taxonomy',
      'settings' => array(
        'allowed_values' => array(
          0 => array(
            'parent' => '0',
            'vocabulary' => 'target_gender',
          ),
        ),
        'field_description_infos' => array(
          'field_description' => 0,
          'field_description_body' => '',
          'field_description_value_type' => '',
        ),
        'field_permissions' => array(
          'create' => 0,
          'edit' => 0,
          'edit own' => 0,
          'view' => 0,
          'view own' => 0,
        ),
        'options_list_callback' => 'content_taxonomy_allowed_values',
      ),
      'translatable' => '0',
      'type' => 'taxonomy_term_reference',
    ),
    'field_instance' => array(
      'bundle' => 'dataschema_variable',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'custom_dimensions' => array(
          'label' => 'above',
          'module' => 'taxonomy',
          'settings' => array(),
          'type' => 'taxonomy_term_reference_plain',
          'weight' => '5',
        ),
        'custom_page' => array(
          'label' => 'inline',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '15',
        ),
        'custom_variable' => array(
          'label' => 'inline',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '12',
        ),
        'default' => array(
          'label' => 'inline',
          'module' => 'taxonomy',
          'settings' => array(),
          'type' => 'taxonomy_term_reference_plain',
          'weight' => '16',
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_dim_target_gender',
      'label' => 'Target gender',
      'required' => 0,
      'settings' => array(
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'tagging',
        'settings' => array(
          'autocomplete_path' => 'taxonomy/autocomplete',
          'size' => 60,
        ),
        'type' => 'tagging_taxonomy_autocomplete',
        'weight' => '84',
      ),
    ),
  );

  // Exported field: 'node-dataschema_variable-field_dim_therapeutic_inter'
  $fields['node-dataschema_variable-field_dim_therapeutic_inter'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '-1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_dim_therapeutic_inter',
      'foreign keys' => array(
        'tid' => array(
          'columns' => array(
            'tid' => 'tid',
          ),
          'table' => 'taxonomy_term_data',
        ),
      ),
      'indexes' => array(
        'tid' => array(
          0 => 'tid',
        ),
      ),
      'module' => 'taxonomy',
      'settings' => array(
        'allowed_values' => array(
          0 => array(
            'parent' => '0',
            'vocabulary' => 'therapeutic_interventions',
          ),
        ),
        'field_description_infos' => array(
          'field_description' => 0,
          'field_description_body' => '',
          'field_description_value_type' => '',
        ),
        'field_permissions' => array(
          'create' => 0,
          'edit' => 0,
          'edit own' => 0,
          'view' => 0,
          'view own' => 0,
        ),
        'options_list_callback' => 'content_taxonomy_allowed_values',
      ),
      'translatable' => '0',
      'type' => 'taxonomy_term_reference',
    ),
    'field_instance' => array(
      'bundle' => 'dataschema_variable',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'custom_dimensions' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'custom_page' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'custom_variable' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'default' => array(
          'label' => 'above',
          'module' => 'taxonomy',
          'settings' => array(),
          'type' => 'taxonomy_term_reference_link',
          'weight' => 32,
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_dim_therapeutic_inter',
      'label' => 'Therapeutic interventions',
      'required' => 0,
      'settings' => array(
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 0,
        'module' => 'tagging',
        'settings' => array(
          'autocomplete_path' => 'taxonomy/autocomplete',
          'size' => 40,
        ),
        'type' => 'tagging_taxonomy_autocomplete',
        'weight' => '78',
      ),
    ),
  );

  // Exported field: 'node-dataschema_variable-field_dim_type'
  $fields['node-dataschema_variable-field_dim_type'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '-1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_dim_type',
      'foreign keys' => array(
        'tid' => array(
          'columns' => array(
            'tid' => 'tid',
          ),
          'table' => 'taxonomy_term_data',
        ),
      ),
      'indexes' => array(
        'tid' => array(
          0 => 'tid',
        ),
      ),
      'module' => 'taxonomy',
      'settings' => array(
        'allowed_values' => array(
          0 => array(
            'parent' => '0',
            'vocabulary' => 'type',
          ),
        ),
        'field_description_infos' => array(
          'field_description' => 0,
          'field_description_body' => '',
          'field_description_value_type' => '',
        ),
        'field_permissions' => array(
          'create' => 0,
          'edit' => 0,
          'edit own' => 0,
          'view' => 0,
          'view own' => 0,
        ),
        'options_list_callback' => 'content_taxonomy_allowed_values',
      ),
      'translatable' => '0',
      'type' => 'taxonomy_term_reference',
    ),
    'field_instance' => array(
      'bundle' => 'dataschema_variable',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'custom_dimensions' => array(
          'label' => 'above',
          'module' => 'taxonomy',
          'settings' => array(),
          'type' => 'taxonomy_term_reference_plain',
          'weight' => '0',
        ),
        'custom_page' => array(
          'label' => 'inline',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '17',
        ),
        'custom_variable' => array(
          'label' => 'inline',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '14',
        ),
        'default' => array(
          'label' => 'inline',
          'module' => 'taxonomy',
          'settings' => array(),
          'type' => 'taxonomy_term_reference_plain',
          'weight' => '14',
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_dim_type',
      'label' => 'Type',
      'required' => 0,
      'settings' => array(
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'tagging',
        'settings' => array(
          'autocomplete_path' => 'taxonomy/autocomplete',
          'size' => 60,
        ),
        'type' => 'tagging_taxonomy_autocomplete',
        'weight' => '88',
      ),
    ),
  );

  // Exported field: 'node-dataschema_variable-field_unit'
  $fields['node-dataschema_variable-field_unit'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_unit',
      'foreign keys' => array(
        'format' => array(
          'columns' => array(
            'format' => 'format',
          ),
          'table' => 'filter_format',
        ),
      ),
      'indexes' => array(
        'format' => array(
          0 => 'format',
        ),
      ),
      'module' => 'text',
      'settings' => array(
        'field_description_infos' => array(
          'field_description' => 0,
          'field_description_body' => '',
          'field_description_value_type' => 'TEXT',
        ),
        'field_permissions' => array(
          'create' => 0,
          'edit' => 0,
          'edit own' => 0,
          'view' => 0,
          'view own' => 0,
        ),
        'max_length' => '255',
      ),
      'translatable' => '0',
      'type' => 'text',
    ),
    'field_instance' => array(
      'bundle' => 'dataschema_variable',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => 'Measuring unit of the variable (i.e. kg, siblings, cigarettes, etc.).',
      'display' => array(
        'custom_dimensions' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '11',
        ),
        'custom_page' => array(
          'label' => 'inline',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '9',
        ),
        'custom_variable' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '3',
        ),
        'default' => array(
          'label' => 'above',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => '2',
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_unit',
      'label' => 'Unit',
      'required' => 0,
      'settings' => array(
        'text_processing' => '0',
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'text',
        'settings' => array(
          'size' => '60',
        ),
        'type' => 'text_textfield',
        'weight' => '3',
      ),
    ),
  );

  // Exported field: 'node-dataschema_variable-field_uri'
  $fields['node-dataschema_variable-field_uri'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_uri',
      'foreign keys' => array(
        'format' => array(
          'columns' => array(
            'format' => 'format',
          ),
          'table' => 'filter_format',
        ),
      ),
      'indexes' => array(
        'format' => array(
          0 => 'format',
        ),
      ),
      'module' => 'text',
      'settings' => array(
        'field_description_infos' => array(
          'field_description' => 0,
          'field_description_body' => '',
          'field_description_value_type' => 'TEXT',
        ),
        'field_permissions' => array(
          'create' => 0,
          'edit' => 0,
          'edit own' => 0,
          'view' => 0,
          'view own' => 0,
        ),
        'max_length' => '255',
      ),
      'translatable' => '0',
      'type' => 'text',
    ),
    'field_instance' => array(
      'bundle' => 'dataschema_variable',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => 'A Uniform Resource Identifier (URI) is a string of characters used to identify a name or a resource on the Internet.',
      'display' => array(
        'custom_dimensions' => array(
          'label' => 'hidden',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '21',
        ),
        'custom_page' => array(
          'label' => 'hidden',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '21',
        ),
        'custom_variable' => array(
          'label' => 'hidden',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '21',
        ),
        'default' => array(
          'label' => 'hidden',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '21',
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_uri',
      'label' => 'URI',
      'required' => 0,
      'settings' => array(
        'text_processing' => '0',
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'text',
        'settings' => array(
          'size' => '60',
        ),
        'type' => 'text_textfield',
        'weight' => '6',
      ),
    ),
  );

  // Exported field: 'node-dataschema_variable-field_variable_categories'
  $fields['node-dataschema_variable-field_variable_categories'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '-1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_variable_categories',
      'foreign keys' => array(
        'nid' => array(
          'columns' => array(
            'nid' => 'nid',
          ),
          'table' => 'node',
        ),
      ),
      'indexes' => array(
        'nid' => array(
          0 => 'nid',
        ),
      ),
      'module' => 'node_reference',
      'settings' => array(
        'field_description_infos' => array(
          'field_description' => 0,
          'field_description_body' => '',
          'field_description_value_type' => '',
        ),
        'field_permissions' => array(
          'create' => 0,
          'edit' => 0,
          'edit own' => 0,
          'view' => 0,
          'view own' => 0,
        ),
        'referenceable_types' => array(
          'article' => 0,
          'blog' => 0,
          'contact' => 0,
          'data_access_request' => 0,
          'data_access_review' => 0,
          'dataschema' => 0,
          'dataschema_category' => 'dataschema_category',
          'dataschema_variable' => 0,
          'dataset' => 0,
          'documents' => 0,
          'event' => 0,
          'field_description' => 0,
          'forum' => 0,
          'institution' => 0,
          'page' => 0,
          'pairing' => 0,
          'panel' => 0,
          'participant_variable' => 0,
          'project' => 0,
          'publication' => 0,
          'study' => 0,
          'study_documents' => 0,
          'study_information' => 0,
          'teleconference' => 0,
        ),
        'view' => array(
          'args' => array(),
          'display_name' => '',
          'view_name' => '',
        ),
      ),
      'translatable' => '0',
      'type' => 'node_reference',
    ),
    'field_instance' => array(
      'bundle' => 'dataschema_variable',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'custom_dimensions' => array(
          'label' => 'inline',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '15',
        ),
        'custom_page' => array(
          'label' => 'above',
          'module' => 'node_reference',
          'settings' => array(
            'node_reference_view_mode' => 'full',
          ),
          'type' => 'node_reference_node',
          'weight' => '5',
        ),
        'custom_variable' => array(
          'label' => 'inline',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '9',
        ),
        'default' => array(
          'label' => 'inline',
          'module' => 'node_reference',
          'settings' => array(),
          'type' => 'node_reference_plain',
          'weight' => '10',
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_variable_categories',
      'label' => 'Categories',
      'required' => 0,
      'settings' => array(
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 0,
        'module' => 'node_reference',
        'settings' => array(
          'autocomplete_match' => 'contains',
          'autocomplete_path' => 'node_reference/autocomplete',
          'size' => 60,
        ),
        'type' => 'node_reference_autocomplete',
        'weight' => '4',
      ),
    ),
  );

  // Exported field: 'node-pairing-body'
  $fields['node-pairing-body'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(
        0 => 'node',
      ),
      'field_name' => 'body',
      'foreign keys' => array(
        'format' => array(
          'columns' => array(
            'format' => 'format',
          ),
          'table' => 'filter_format',
        ),
      ),
      'indexes' => array(
        'format' => array(
          0 => 'format',
        ),
      ),
      'module' => 'text',
      'settings' => array(
        'field_description_infos' => array(
          'field_description' => 0,
          'field_description_body' => '',
          'field_description_value_type' => 'TEXT',
        ),
        'field_permissions' => array(
          'create' => 0,
          'edit' => 0,
          'edit own' => 0,
          'view' => 0,
          'view own' => 0,
        ),
        'variable_infos' => array(
          'variable' => 1,
          'variable_body' => '',
          'variable_value_type' => 'TEXT',
        ),
      ),
      'translatable' => '1',
      'type' => 'text_with_summary',
    ),
    'field_instance' => array(
      'bundle' => 'pairing',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'custom_dimensions' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'custom_page' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'custom_variable' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'default' => array(
          'label' => 'hidden',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => 0,
        ),
        'teaser' => array(
          'label' => 'hidden',
          'module' => 'text',
          'settings' => array(
            'trim_length' => 600,
          ),
          'type' => 'text_summary_or_trimmed',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'body',
      'label' => 'Body',
      'required' => FALSE,
      'settings' => array(
        'display_summary' => TRUE,
        'text_processing' => 1,
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'module' => 'text',
        'settings' => array(
          'rows' => 20,
          'summary_rows' => 5,
        ),
        'type' => 'text_textarea_with_summary',
        'weight' => '31',
      ),
    ),
  );

  // Exported field: 'node-pairing-field_match'
  $fields['node-pairing-field_match'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_match',
      'foreign keys' => array(),
      'indexes' => array(
        'value' => array(
          0 => 'value',
        ),
      ),
      'module' => 'list',
      'settings' => array(
        'allowed_values' => array(
          'Complete' => 'Complete',
          'Impossible' => 'Impossible',
          'Partial' => 'Partial',
        ),
        'allowed_values_function' => '',
        'field_description_infos' => array(
          'field_description' => 0,
          'field_description_body' => '',
          'field_description_value_type' => '',
        ),
        'field_permissions' => array(
          'create' => 0,
          'edit' => 0,
          'edit own' => 0,
          'view' => 0,
          'view own' => 0,
        ),
      ),
      'translatable' => '0',
      'type' => 'list_text',
    ),
    'field_instance' => array(
      'bundle' => 'pairing',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'custom_dimensions' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'custom_page' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'custom_variable' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'default' => array(
          'label' => 'above',
          'module' => 'list',
          'settings' => array(),
          'type' => 'list_default',
          'weight' => 1,
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_match',
      'label' => 'Match',
      'required' => 1,
      'settings' => array(
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'options',
        'settings' => array(),
        'type' => 'options_select',
        'weight' => '32',
      ),
    ),
  );

  // Exported field: 'node-pairing-field_project'
  $fields['node-pairing-field_project'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_project',
      'foreign keys' => array(
        'nid' => array(
          'columns' => array(
            'nid' => 'nid',
          ),
          'table' => 'node',
        ),
      ),
      'indexes' => array(
        'nid' => array(
          0 => 'nid',
        ),
      ),
      'module' => 'node_reference',
      'settings' => array(
        'field_description_infos' => array(
          'field_description' => 0,
          'field_description_body' => '',
          'field_description_value_type' => '',
        ),
        'field_permissions' => array(
          'create' => 0,
          'edit' => 0,
          'edit own' => 0,
          'view' => 0,
          'view own' => 0,
        ),
        'referenceable_types' => array(
          'article' => 0,
          'blog' => 0,
          'contact' => 0,
          'data_access_request' => 0,
          'data_access_review' => 0,
          'dataschema' => 0,
          'dataschema_category' => 0,
          'dataschema_variable' => 0,
          'dataset' => 0,
          'documents' => 0,
          'event' => 0,
          'field_description' => 0,
          'forum' => 0,
          'institution' => 0,
          'page' => 0,
          'pairing' => 0,
          'panel' => 0,
          'participant_variable' => 0,
          'project' => 'project',
          'publication' => 0,
          'study' => 0,
          'study_documents' => 0,
          'study_information' => 0,
          'teleconference' => 0,
        ),
        'view' => array(
          'args' => array(),
          'display_name' => '',
          'view_name' => '',
        ),
      ),
      'translatable' => '1',
      'type' => 'node_reference',
    ),
    'field_instance' => array(
      'bundle' => 'pairing',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'custom_dimensions' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'custom_page' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'custom_variable' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'default' => array(
          'label' => 'above',
          'module' => 'node_reference',
          'settings' => array(),
          'type' => 'node_reference_default',
          'weight' => 5,
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_project',
      'label' => 'Project',
      'required' => 1,
      'settings' => array(
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'node_reference',
        'settings' => array(
          'autocomplete_match' => 'contains',
          'autocomplete_path' => 'node_reference/autocomplete',
          'size' => '60',
        ),
        'type' => 'node_reference_autocomplete',
        'weight' => '37',
      ),
    ),
  );

  // Exported field: 'node-pairing-field_study'
  $fields['node-pairing-field_study'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_study',
      'foreign keys' => array(
        'nid' => array(
          'columns' => array(
            'nid' => 'nid',
          ),
          'table' => 'node',
        ),
      ),
      'indexes' => array(
        'nid' => array(
          0 => 'nid',
        ),
      ),
      'module' => 'node_reference',
      'settings' => array(
        'field_description_infos' => array(
          'field_description' => 0,
          'field_description_body' => '',
          'field_description_value_type' => '',
        ),
        'field_permissions' => array(
          'create' => 0,
          'edit' => 0,
          'edit own' => 0,
          'view' => 0,
          'view own' => 0,
        ),
        'referenceable_types' => array(
          'article' => 0,
          'blog' => 0,
          'contact' => 0,
          'data_access_request' => 0,
          'data_access_review' => 0,
          'dataschema' => 0,
          'dataschema_category' => 0,
          'dataschema_variable' => 0,
          'dataset' => 0,
          'documents' => 0,
          'event' => 0,
          'field_description' => 0,
          'forum' => 0,
          'institution' => 0,
          'page' => 0,
          'pairing' => 0,
          'panel' => 0,
          'participant_variable' => 0,
          'project' => 0,
          'publication' => 0,
          'study' => 'study',
          'study_documents' => 0,
          'study_information' => 0,
          'teleconference' => 0,
        ),
        'view' => array(
          'args' => array(),
          'display_name' => '',
          'view_name' => '',
        ),
      ),
      'translatable' => '0',
      'type' => 'node_reference',
    ),
    'field_instance' => array(
      'bundle' => 'pairing',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'custom_dimensions' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'custom_page' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'custom_variable' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'default' => array(
          'label' => 'above',
          'module' => 'node_reference',
          'settings' => array(),
          'type' => 'node_reference_default',
          'weight' => 6,
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_study',
      'label' => 'Study',
      'required' => 1,
      'settings' => array(
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'node_reference',
        'settings' => array(
          'autocomplete_match' => 'contains',
          'autocomplete_path' => 'node_reference/autocomplete',
          'size' => '60',
        ),
        'type' => 'node_reference_autocomplete',
        'weight' => '38',
      ),
    ),
  );

  // Exported field: 'node-pairing-field_variable'
  $fields['node-pairing-field_variable'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_variable',
      'foreign keys' => array(
        'nid' => array(
          'columns' => array(
            'nid' => 'nid',
          ),
          'table' => 'node',
        ),
      ),
      'indexes' => array(
        'nid' => array(
          0 => 'nid',
        ),
      ),
      'module' => 'node_reference',
      'settings' => array(
        'field_description_infos' => array(
          'field_description' => 0,
          'field_description_body' => '',
          'field_description_value_type' => '',
        ),
        'field_permissions' => array(
          'create' => 0,
          'edit' => 0,
          'edit own' => 0,
          'view' => 0,
          'view own' => 0,
        ),
        'referenceable_types' => array(
          'article' => 0,
          'blog' => 0,
          'contact' => 0,
          'data_access_request' => 0,
          'data_access_review' => 0,
          'dataschema' => 0,
          'dataschema_category' => 0,
          'dataschema_variable' => 'dataschema_variable',
          'dataset' => 0,
          'documents' => 0,
          'event' => 0,
          'field_description' => 0,
          'forum' => 0,
          'institution' => 0,
          'page' => 0,
          'pairing' => 0,
          'panel' => 0,
          'participant_variable' => 0,
          'project' => 0,
          'publication' => 0,
          'study' => 0,
          'study_documents' => 0,
          'study_information' => 0,
          'teleconference' => 0,
        ),
        'view' => array(
          'args' => array(),
          'display_name' => '',
          'view_name' => '',
        ),
      ),
      'translatable' => '0',
      'type' => 'node_reference',
    ),
    'field_instance' => array(
      'bundle' => 'pairing',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'custom_dimensions' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'custom_page' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'custom_variable' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'default' => array(
          'label' => 'above',
          'module' => 'node_reference',
          'settings' => array(),
          'type' => 'node_reference_default',
          'weight' => 7,
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_variable',
      'label' => 'Variable',
      'required' => 1,
      'settings' => array(
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'node_reference',
        'settings' => array(
          'autocomplete_match' => 'contains',
          'autocomplete_path' => 'node_reference/autocomplete',
          'size' => '60',
        ),
        'type' => 'node_reference_autocomplete',
        'weight' => '39',
      ),
    ),
  );

  // Exported field: 'node-project-field_dataschema_ref'
  $fields['node-project-field_dataschema_ref'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '-1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_dataschema_ref',
      'foreign keys' => array(
        'nid' => array(
          'columns' => array(
            'nid' => 'nid',
          ),
          'table' => 'node',
        ),
      ),
      'indexes' => array(
        'nid' => array(
          0 => 'nid',
        ),
      ),
      'module' => 'node_reference',
      'settings' => array(
        'field_description_infos' => array(
          'field_description' => 0,
          'field_description_body' => '',
          'field_description_value_type' => '',
        ),
        'field_permissions' => array(
          'create' => 0,
          'edit' => 0,
          'edit own' => 0,
          'view' => 0,
          'view own' => 0,
        ),
        'referenceable_types' => array(
          'article' => 0,
          'blog' => 0,
          'contact' => 0,
          'data_access_request' => 0,
          'data_access_review' => 0,
          'dataschema' => 'dataschema',
          'dataschema_category' => 0,
          'dataschema_variable' => 0,
          'dataset' => 0,
          'documents' => 0,
          'event' => 0,
          'field_description' => 0,
          'forum' => 0,
          'institution' => 0,
          'page' => 0,
          'pairing' => 0,
          'panel' => 0,
          'participant_variable' => 0,
          'project' => 0,
          'publication' => 0,
          'study' => 0,
          'study_documents' => 0,
          'study_information' => 0,
          'teleconference' => 0,
        ),
        'view' => array(
          'args' => array(),
          'display_name' => '',
          'view_name' => '',
        ),
      ),
      'translatable' => '0',
      'type' => 'node_reference',
    ),
    'field_instance' => array(
      'bundle' => 'project',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'custom_dimensions' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '4',
        ),
        'custom_page' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '1',
        ),
        'custom_variable' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'default' => array(
          'label' => 'above',
          'module' => 'node_reference',
          'settings' => array(),
          'type' => 'node_reference_default',
          'weight' => '1',
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_dataschema_ref',
      'label' => 'DataSchema',
      'required' => 0,
      'settings' => array(
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 0,
        'module' => 'node_reference',
        'settings' => array(
          'autocomplete_match' => 'contains',
          'autocomplete_path' => 'node_reference/autocomplete',
          'size' => 60,
        ),
        'type' => 'node_reference_autocomplete',
        'weight' => '32',
      ),
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('A Uniform Resource Identifier (URI) is a string of characters used to identify a name or a resource on the Internet.');
  t('Biochemical measures');
  t('Body');
  t('Body functions and measures');
  t('Categories');
  t('Class');
  t('Collection mode');
  t('DataSchema');
  t('Disease history');
  t('Environmental exposures');
  t('Format');
  t('Life habits / Behaviours');
  t('Match');
  t('Measuring unit of the variable (i.e. kg, siblings, cigarettes, etc.).');
  t('Medication');
  t('Missing');
  t('Name');
  t('Period');
  t('Project');
  t('Reproductive history');
  t('Sample');
  t('Sociodemographic characteristics');
  t('Source of information');
  t('Study');
  t('Target');
  t('Target gender');
  t('Therapeutic interventions');
  t('Type');
  t('URI');
  t('Unit');
  t('Variable');
  t('Variables');

  return $fields;
}
