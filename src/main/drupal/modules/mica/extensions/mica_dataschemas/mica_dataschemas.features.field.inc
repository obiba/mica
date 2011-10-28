<?php
/**
 * @file
 * mica_dataschemas.features.field.inc
 */

/**
 * Implementation of hook_field_default_fields().
 */
function mica_dataschemas_field_default_fields() {
  $fields = array();

  // Exported field: 'comment-comment_node_dataschema-comment_body'
  $fields['comment-comment_node_dataschema-comment_body'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(
        0 => 'comment',
      ),
      'field_name' => 'comment_body',
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
      'settings' => array(),
      'translatable' => '0',
      'type' => 'text_long',
    ),
    'field_instance' => array(
      'bundle' => 'comment_node_dataschema',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'hidden',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'comment',
      'field_name' => 'comment_body',
      'label' => 'Comment',
      'required' => TRUE,
      'settings' => array(
        'text_processing' => 1,
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'module' => 'text',
        'settings' => array(
          'rows' => 5,
        ),
        'type' => 'text_textarea',
        'weight' => 0,
      ),
    ),
  );

  // Exported field: 'comment-comment_node_ds_variable-comment_body'
  $fields['comment-comment_node_ds_variable-comment_body'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(
        0 => 'comment',
      ),
      'field_name' => 'comment_body',
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
      'settings' => array(),
      'translatable' => '0',
      'type' => 'text_long',
    ),
    'field_instance' => array(
      'bundle' => 'comment_node_ds_variable',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'hidden',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'comment',
      'field_name' => 'comment_body',
      'label' => 'Comment',
      'required' => TRUE,
      'settings' => array(
        'text_processing' => 1,
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'module' => 'text',
        'settings' => array(
          'rows' => 5,
        ),
        'type' => 'text_textarea',
        'weight' => 0,
      ),
    ),
  );

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

  // Exported field: 'node-dataschema-field_uri'
  $fields['node-dataschema-field_uri'] = array(
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
      'bundle' => 'dataschema',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
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
        'weight' => '33',
      ),
    ),
  );

  // Exported field: 'node-dataschema-field_variables'
  $fields['node-dataschema-field_variables'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '-1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_variables',
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
          'dataset_participant_variables:page' => 0,
          'dataset_studies:page' => 0,
          'datasets:feed' => 0,
          'datasets:page' => 0,
          'datasschema_variables:page' => 'datasschema_variables:page',
          'date_browser:date_nav_1' => 0,
          'date_browser:page' => 0,
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
          'publications:page' => 0,
          'studies:page' => 0,
          'studies_search:page' => 0,
          'taxonomy_term:feed' => 0,
          'taxonomy_term:page' => 0,
          'tracker:page' => 0,
        ),
      ),
      'translatable' => '0',
      'type' => 'viewreference',
    ),
    'field_instance' => array(
      'bundle' => 'dataschema',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'viewreference',
          'settings' => array(),
          'type' => 'viewreference_default',
          'weight' => 2,
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_variables',
      'label' => 'Variables',
      'required' => 0,
      'settings' => array(
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 0,
        'module' => 'viewreference',
        'settings' => array(),
        'type' => 'viewreference_select',
        'weight' => '34',
      ),
    ),
  );

  // Exported field: 'node-ds_variable-body'
  $fields['node-ds_variable-body'] = array(
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
      'bundle' => 'ds_variable',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
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
        'weight' => '2',
      ),
    ),
  );

  // Exported field: 'node-ds_variable-field_dataschemas'
  $fields['node-ds_variable-field_dataschemas'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '-1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_dataschemas',
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
          'dataset' => 0,
          'documents' => 0,
          'ds_variable' => 0,
          'event' => 0,
          'field_description' => 0,
          'forum' => 0,
          'institution' => 0,
          'page' => 0,
          'panel' => 0,
          'participant_variable' => 0,
          'publication' => 0,
          'study' => 0,
          'study_documents' => 0,
          'study_information' => 0,
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
      'bundle' => 'ds_variable',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'node_reference',
          'settings' => array(),
          'type' => 'node_reference_default',
          'weight' => 11,
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_dataschemas',
      'label' => 'DataSchemas',
      'required' => 0,
      'settings' => array(
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'options',
        'settings' => array(),
        'type' => 'options_buttons',
        'weight' => '31',
      ),
    ),
  );

  // Exported field: 'node-ds_variable-field_dim_collection_mode'
  $fields['node-ds_variable-field_dim_collection_mode'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_dim_collection_mode',
      'foreign keys' => array(),
      'indexes' => array(
        'value' => array(
          0 => 'value',
        ),
      ),
      'module' => 'list',
      'settings' => array(
        'allowed_values' => array(
          'Direct measure' => 'Direct measure',
          'Inventory' => 'Inventory',
          'Questionnaire' => 'Questionnaire',
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
      'bundle' => 'ds_variable',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => 'Term used to describe the method of gathering information for the construction of the variable (e.g. Direct measure, questionnaire...).',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'list',
          'settings' => array(),
          'type' => 'list_default',
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
      'field_name' => 'field_dim_collection_mode',
      'label' => 'Collection mode',
      'required' => 0,
      'settings' => array(
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'options',
        'settings' => array(),
        'type' => 'options_buttons',
        'weight' => '12',
      ),
    ),
  );

  // Exported field: 'node-ds_variable-field_dim_format'
  $fields['node-ds_variable-field_dim_format'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_dim_format',
      'foreign keys' => array(),
      'indexes' => array(
        'value' => array(
          0 => 'value',
        ),
      ),
      'module' => 'list',
      'settings' => array(
        'allowed_values' => array(
          'Categorical' => 'Categorical',
          'Open' => 'Open',
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
      'bundle' => 'ds_variable',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => 'Term used to describe the way in which the information collected is organized for the construction of the variables (e.g. open, categorical).',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'list',
          'settings' => array(),
          'type' => 'list_default',
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
      'field_name' => 'field_dim_format',
      'label' => 'Format',
      'required' => 0,
      'settings' => array(
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'options',
        'settings' => array(),
        'type' => 'options_buttons',
        'weight' => '13',
      ),
    ),
  );

  // Exported field: 'node-ds_variable-field_dim_sample'
  $fields['node-ds_variable-field_dim_sample'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '-1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_dim_sample',
      'foreign keys' => array(),
      'indexes' => array(
        'value' => array(
          0 => 'value',
        ),
      ),
      'module' => 'list',
      'settings' => array(
        'allowed_values' => array(
          'Buffy coat' => 'Buffy coat',
          'Plasma' => 'Plasma',
          'Red blood cells' => 'Red blood cells',
          'Saliva' => 'Saliva',
          'Serum' => 'Serum',
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
      'bundle' => 'ds_variable',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => 'Term used to define the sample type targeted by the variable (e.g. serum, plasma...).',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'list',
          'settings' => array(),
          'type' => 'list_default',
          'weight' => 8,
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
        'module' => 'options',
        'settings' => array(),
        'type' => 'options_buttons',
        'weight' => '14',
      ),
    ),
  );

  // Exported field: 'node-ds_variable-field_dim_target_gender'
  $fields['node-ds_variable-field_dim_target_gender'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '-1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_dim_target_gender',
      'foreign keys' => array(),
      'indexes' => array(
        'value' => array(
          0 => 'value',
        ),
      ),
      'module' => 'list',
      'settings' => array(
        'allowed_values' => array(
          'Female' => 'Female',
          'Male' => 'Male',
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
      'bundle' => 'ds_variable',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => 'Term used to describe the gender of the person targeted by the variable ( e.g. male, female).',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'list',
          'settings' => array(),
          'type' => 'list_default',
          'weight' => 9,
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
        'module' => 'options',
        'settings' => array(),
        'type' => 'options_buttons',
        'weight' => '15',
      ),
    ),
  );

  // Exported field: 'node-ds_variable-field_dim_type'
  $fields['node-ds_variable-field_dim_type'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_dim_type',
      'foreign keys' => array(),
      'indexes' => array(
        'value' => array(
          0 => 'value',
        ),
      ),
      'module' => 'list',
      'settings' => array(
        'allowed_values' => array(
          'Date' => 'Date',
          'Decimale' => 'Decimale',
          'Integer' => 'Integer',
          'Time' => 'Time',
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
      'bundle' => 'ds_variable',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => 'Term used to specify the type of an open variable in the DataSchema (e.g. date, decimal, integer...).',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'list',
          'settings' => array(),
          'type' => 'list_default',
          'weight' => 10,
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
        'module' => 'options',
        'settings' => array(),
        'type' => 'options_buttons',
        'weight' => '11',
      ),
    ),
  );

  // Exported field: 'node-ds_variable-field_domain'
  $fields['node-ds_variable-field_domain'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '-1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_domain',
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
      'bundle' => 'ds_variable',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => 'A domain is a risk factor or an outcome of interest, subsuming a number of variables.',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => 3,
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_domain',
      'label' => 'Domain',
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
        'weight' => '5',
      ),
    ),
  );

  // Exported field: 'node-ds_variable-field_module'
  $fields['node-ds_variable-field_module'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '-1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_module',
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
      'bundle' => 'ds_variable',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => 'A module is a grouping based on variables main unit of interest, assessment modes or type of element measured or collected. Each module subsumes one or more themes.',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
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
      'field_name' => 'field_module',
      'label' => 'Module',
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

  // Exported field: 'node-ds_variable-field_theme'
  $fields['node-ds_variable-field_theme'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '-1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_theme',
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
      'bundle' => 'ds_variable',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => 'A theme is a general area of interest. Each theme subsumes one or more domains.',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => 2,
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_theme',
      'label' => 'Theme',
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
        'weight' => '4',
      ),
    ),
  );

  // Exported field: 'node-ds_variable-field_unit'
  $fields['node-ds_variable-field_unit'] = array(
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
      'bundle' => 'ds_variable',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => 'Measuring unit of the variable (i.e. kg, siblings, cigarettes, etc.).',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
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
        'weight' => '6',
      ),
    ),
  );

  // Exported field: 'node-ds_variable-field_uri'
  $fields['node-ds_variable-field_uri'] = array(
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
      'bundle' => 'ds_variable',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => 'A Uniform Resource Identifier (URI) is a string of characters used to identify a name or a resource on the Internet.',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => 4,
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
      'required' => 1,
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
        'weight' => '8',
      ),
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('A Uniform Resource Identifier (URI) is a string of characters used to identify a name or a resource on the Internet.');
  t('A domain is a risk factor or an outcome of interest, subsuming a number of variables.');
  t('A module is a grouping based on variables main unit of interest, assessment modes or type of element measured or collected. Each module subsumes one or more themes.');
  t('A theme is a general area of interest. Each theme subsumes one or more domains.');
  t('Body');
  t('Collection mode');
  t('Comment');
  t('DataSchemas');
  t('Domain');
  t('Format');
  t('Measuring unit of the variable (i.e. kg, siblings, cigarettes, etc.).');
  t('Module');
  t('Sample');
  t('Target gender');
  t('Term used to define the sample type targeted by the variable (e.g. serum, plasma...).');
  t('Term used to describe the gender of the person targeted by the variable ( e.g. male, female).');
  t('Term used to describe the method of gathering information for the construction of the variable (e.g. Direct measure, questionnaire...).');
  t('Term used to describe the way in which the information collected is organized for the construction of the variables (e.g. open, categorical).');
  t('Term used to specify the type of an open variable in the DataSchema (e.g. date, decimal, integer...).');
  t('Theme');
  t('Type');
  t('URI');
  t('Unit');
  t('Variables');

  return $fields;
}
