<?php
/**
 * @file
 * mica_networks.features.field.inc
 */

/**
 * Implements hook_field_default_fields().
 */
function mica_networks_field_default_fields() {
  $fields = array();

  // Exported field: 'node-network-body'.
  $fields['node-network-body'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(
        0 => 'node',
      ),
      'field_name' => 'body',
      'field_permissions' => array(
        'type' => '0',
      ),
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
      'locked' => '0',
      'module' => 'text',
      'settings' => array(
        'field_description_infos' => array(
          'field_description' => 0,
          'field_description_body' => '',
          'field_description_value_type' => 'text',
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
          'variable_value_type' => 'text',
        ),
      ),
      'translatable' => '1',
      'type' => 'text_with_summary',
    ),
    'field_instance' => array(
      'bundle' => 'network',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'banner_area' => array(
          'label' => 'hidden',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => '1',
        ),
        'center_area' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '11',
        ),
        'default' => array(
          'label' => 'hidden',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => '1',
        ),
        'footer_area' => array(
          'label' => 'hidden',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => '1',
        ),
        'left_area' => array(
          'label' => 'hidden',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '5',
        ),
        'right_area' => array(
          'label' => 'hidden',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '9',
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
      'display_label' => '',
      'entity_type' => 'node',
      'field_name' => 'body',
      'label' => 'Body',
      'required' => 1,
      'settings' => array(
        'display_summary' => 1,
        'text_processing' => '1',
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'text',
        'settings' => array(
          'rows' => '20',
          'summary_rows' => 5,
        ),
        'type' => 'text_textarea_with_summary',
        'weight' => '4',
      ),
    ),
  );

  // Exported field: 'node-network-field_acroym'.
  $fields['node-network-field_acroym'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_acroym',
      'field_permissions' => array(
        'type' => '0',
      ),
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
      'locked' => '0',
      'module' => 'text',
      'settings' => array(
        'field_description_infos' => array(
          'field_description' => 0,
          'field_description_body' => '',
          'field_description_label' => '',
          'field_description_value_type' => 'text',
        ),
        'max_length' => '255',
      ),
      'translatable' => '1',
      'type' => 'text',
    ),
    'field_instance' => array(
      'bundle' => 'network',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => 'Acronym of the network if applicable.',
      'display' => array(
        'banner_area' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '2',
        ),
        'center_area' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '7',
        ),
        'default' => array(
          'label' => 'above',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => '2',
        ),
        'footer_area' => array(
          'label' => 'above',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => '2',
        ),
        'left_area' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '6',
        ),
        'right_area' => array(
          'label' => 'above',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => '0',
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
      'field_name' => 'field_acroym',
      'label' => 'Acronym',
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
        'weight' => '1',
      ),
    ),
  );

  // Exported field: 'node-network-field_authorising_date_m'.
  $fields['node-network-field_authorising_date_m'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_authorising_date_m',
      'field_permissions' => array(
        'type' => '2',
      ),
      'foreign keys' => array(),
      'indexes' => array(),
      'locked' => '0',
      'module' => 'date',
      'settings' => array(
        'cache_count' => '4',
        'cache_enabled' => 0,
        'field_description_infos' => array(
          'field_description' => 0,
          'field_description_body' => '',
          'field_description_label' => '',
          'field_description_value_type' => 'text',
        ),
        'granularity' => array(
          'day' => 'day',
          'hour' => 0,
          'minute' => 0,
          'month' => 'month',
          'second' => 0,
          'year' => 'year',
        ),
        'timezone_db' => '',
        'todate' => '',
        'tz_handling' => 'none',
      ),
      'translatable' => '0',
      'type' => 'datetime',
    ),
    'field_instance' => array(
      'bundle' => 'network',
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'banner_area' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '11',
        ),
        'center_area' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '8',
        ),
        'default' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '11',
        ),
        'footer_area' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '11',
        ),
        'left_area' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '11',
        ),
        'right_area' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '11',
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
      'field_name' => 'field_authorising_date_m',
      'label' => 'Authorising date',
      'required' => 0,
      'settings' => array(
        'default_value' => 'now',
        'default_value2' => 'same',
        'default_value_code' => '',
        'default_value_code2' => '',
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'date',
        'settings' => array(
          'increment' => '15',
          'input_format' => 'm/d/Y - H:i:s',
          'input_format_custom' => '',
          'label_position' => 'above',
          'text_parts' => array(),
          'year_range' => '-3:+3',
        ),
        'type' => 'date_popup',
        'weight' => '14',
      ),
    ),
  );

  // Exported field: 'node-network-field_authorising_person_name_m'.
  $fields['node-network-field_authorising_person_name_m'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_authorising_person_name_m',
      'field_permissions' => array(
        'type' => '2',
      ),
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
      'locked' => '0',
      'module' => 'text',
      'settings' => array(
        'field_description_infos' => array(
          'field_description' => 0,
          'field_description_body' => '',
          'field_description_label' => '',
          'field_description_value_type' => 'text',
        ),
        'max_length' => '255',
      ),
      'translatable' => '0',
      'type' => 'text',
    ),
    'field_instance' => array(
      'bundle' => 'network',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'banner_area' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '10',
        ),
        'center_area' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '9',
        ),
        'default' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '10',
        ),
        'footer_area' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '10',
        ),
        'left_area' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '10',
        ),
        'right_area' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '10',
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
      'field_name' => 'field_authorising_person_name_m',
      'label' => 'Name of the person authorising the contribution to Maelstrom Research',
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
        'weight' => '13',
      ),
    ),
  );

  // Exported field: 'node-network-field_authorization_maelstrom'.
  $fields['node-network-field_authorization_maelstrom'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_authorization_maelstrom',
      'field_permissions' => array(
        'type' => '2',
      ),
      'foreign keys' => array(),
      'indexes' => array(
        'value' => array(
          0 => 'value',
        ),
      ),
      'locked' => '0',
      'module' => 'list',
      'settings' => array(
        'allowed_values' => array(
          0 => 'No',
          1 => 'Yes',
        ),
        'allowed_values_function' => '',
        'field_description_infos' => array(
          'field_description' => 0,
          'field_description_body' => '',
          'field_description_label' => '',
          'field_description_value_type' => 'text',
        ),
      ),
      'translatable' => '0',
      'type' => 'list_boolean',
    ),
    'field_instance' => array(
      'bundle' => 'network',
      'default_value' => array(
        0 => array(
          'value' => 0,
        ),
      ),
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'banner_area' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '9',
        ),
        'center_area' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '10',
        ),
        'default' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '9',
        ),
        'footer_area' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '9',
        ),
        'left_area' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '9',
        ),
        'right_area' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '8',
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'display_label' => 'Authorization from contributors to the Maelstrom Catalogues',
      'entity_type' => 'node',
      'field_name' => 'field_authorization_maelstrom',
      'label' => 'Authorization Maelstrom',
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
        'weight' => '12',
      ),
    ),
  );

  // Exported field: 'node-network-field_contacts_ref'.
  $fields['node-network-field_contacts_ref'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '-1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_contacts_ref',
      'field_permissions' => array(
        'type' => '0',
      ),
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
      'locked' => '0',
      'module' => 'node_reference',
      'settings' => array(
        'referenceable_types' => array(
          'article' => 0,
          'blog' => 0,
          'contact' => 'contact',
          'data_access_request' => 0,
          'data_access_review' => 0,
          'dataset' => 0,
          'documents' => 0,
          'event' => 0,
          'field_description' => 0,
          'forum' => 0,
          'network' => 0,
          'page' => 0,
          'panel' => 0,
          'project' => 0,
          'publication' => 0,
          'study' => 0,
          'study_variable_attributes' => 0,
          'teleconference' => 0,
          'variable' => 0,
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
      'bundle' => 'network',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'banner_area' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '4',
        ),
        'center_area' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '6',
        ),
        'default' => array(
          'label' => 'above',
          'module' => 'node_reference',
          'settings' => array(),
          'type' => 'node_reference_default',
          'weight' => '4',
        ),
        'footer_area' => array(
          'label' => 'above',
          'module' => 'node_reference',
          'settings' => array(),
          'type' => 'node_reference_default',
          'weight' => '4',
        ),
        'left_area' => array(
          'label' => 'above',
          'module' => 'node_reference',
          'settings' => array(),
          'type' => 'node_reference_default',
          'weight' => '1',
        ),
        'right_area' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '6',
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
      'field_name' => 'field_contacts_ref',
      'label' => 'Contacts',
      'required' => 0,
      'settings' => array(
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'noderefcreate',
        'settings' => array(
          'autocomplete_match' => 'contains',
          'autocomplete_path' => 'node_reference/autocomplete',
          'size' => '60',
        ),
        'type' => 'noderefcreate_autocomplete',
        'weight' => '3',
      ),
    ),
  );

  // Exported field: 'node-network-field_investigators'.
  $fields['node-network-field_investigators'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '-1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_investigators',
      'field_permissions' => array(
        'type' => '0',
      ),
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
      'locked' => '0',
      'module' => 'node_reference',
      'settings' => array(
        'referenceable_types' => array(
          'article' => 0,
          'blog' => 0,
          'contact' => 'contact',
          'data_access_request' => 0,
          'data_access_review' => 0,
          'dataset' => 0,
          'documents' => 0,
          'event' => 0,
          'field_description' => 0,
          'forum' => 0,
          'network' => 0,
          'page' => 0,
          'panel' => 0,
          'project' => 0,
          'publication' => 0,
          'study' => 0,
          'study_variable_attributes' => 0,
          'teleconference' => 0,
          'variable' => 0,
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
      'bundle' => 'network',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'banner_area' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '3',
        ),
        'center_area' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '5',
        ),
        'default' => array(
          'label' => 'above',
          'module' => 'node_reference',
          'settings' => array(),
          'type' => 'node_reference_default',
          'weight' => '3',
        ),
        'footer_area' => array(
          'label' => 'above',
          'module' => 'node_reference',
          'settings' => array(),
          'type' => 'node_reference_default',
          'weight' => '3',
        ),
        'left_area' => array(
          'label' => 'above',
          'module' => 'node_reference',
          'settings' => array(),
          'type' => 'node_reference_default',
          'weight' => '0',
        ),
        'right_area' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '7',
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
      'field_name' => 'field_investigators',
      'label' => 'Investigators',
      'required' => 0,
      'settings' => array(
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'noderefcreate',
        'settings' => array(
          'autocomplete_match' => 'contains',
          'autocomplete_path' => 'node_reference/autocomplete',
          'size' => '60',
        ),
        'type' => 'noderefcreate_autocomplete',
        'weight' => '2',
      ),
    ),
  );

  // Exported field: 'node-network-field_logo'.
  $fields['node-network-field_logo'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_logo',
      'field_permissions' => array(
        'type' => '0',
      ),
      'foreign keys' => array(
        'fid' => array(
          'columns' => array(
            'fid' => 'fid',
          ),
          'table' => 'file_managed',
        ),
      ),
      'indexes' => array(
        'fid' => array(
          0 => 'fid',
        ),
      ),
      'locked' => '0',
      'module' => 'image',
      'settings' => array(
        'default_image' => 0,
        'field_description_infos' => array(
          'field_description' => 0,
          'field_description_body' => '',
          'field_description_label' => '',
          'field_description_value_type' => 'text',
        ),
        'uri_scheme' => 'public',
      ),
      'translatable' => '1',
      'type' => 'image',
    ),
    'field_instance' => array(
      'bundle' => 'network',
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'banner_area' => array(
          'label' => 'hidden',
          'module' => 'image',
          'settings' => array(
            'image_link' => '',
            'image_style' => 'study_logo',
          ),
          'type' => 'image',
          'weight' => '0',
        ),
        'center_area' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '1',
        ),
        'default' => array(
          'label' => 'hidden',
          'module' => 'image',
          'settings' => array(
            'image_link' => '',
            'image_style' => 'study_logo',
          ),
          'type' => 'image',
          'weight' => '0',
        ),
        'footer_area' => array(
          'label' => 'hidden',
          'module' => 'image',
          'settings' => array(
            'image_link' => '',
            'image_style' => 'study_logo',
          ),
          'type' => 'image',
          'weight' => '0',
        ),
        'left_area' => array(
          'label' => 'hidden',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '4',
        ),
        'right_area' => array(
          'label' => 'hidden',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '5',
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
      'field_name' => 'field_logo',
      'label' => 'Logo',
      'required' => 0,
      'settings' => array(
        'alt_field' => 0,
        'default_image' => 0,
        'file_directory' => '',
        'file_extensions' => 'png gif jpg jpeg',
        'max_filesize' => '',
        'max_resolution' => '',
        'min_resolution' => '',
        'title_field' => 0,
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'image',
        'settings' => array(
          'preview_image_style' => 'thumbnail',
          'progress_indicator' => 'throbber',
        ),
        'type' => 'image_image',
        'weight' => '8',
      ),
    ),
  );

  // Exported field: 'node-network-field_studies'.
  $fields['node-network-field_studies'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '-1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_studies',
      'field_permissions' => array(
        'type' => '0',
      ),
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
      'locked' => '0',
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
          'event' => 0,
          'field_description' => 0,
          'forum' => 0,
          'institution' => 0,
          'page' => 0,
          'panel' => 0,
          'project' => 0,
          'publication' => 0,
          'study' => 'study',
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
      'bundle' => 'network',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'banner_area' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '6',
        ),
        'center_area' => array(
          'label' => 'above',
          'module' => 'mica_core',
          'settings' => array(),
          'type' => 'node_reference_url_or_plain',
          'weight' => '0',
        ),
        'default' => array(
          'label' => 'above',
          'module' => 'mica_core',
          'settings' => array(),
          'type' => 'node_reference_url_or_plain',
          'weight' => '6',
        ),
        'footer_area' => array(
          'label' => 'above',
          'module' => 'mica_core',
          'settings' => array(),
          'type' => 'node_reference_url_or_plain',
          'weight' => '6',
        ),
        'left_area' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '2',
        ),
        'right_area' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '4',
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
      'field_name' => 'field_studies',
      'label' => 'Studies',
      'required' => 0,
      'settings' => array(
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'noderefcreate',
        'settings' => array(
          'autocomplete_match' => 'contains',
          'autocomplete_path' => 'node_reference/autocomplete',
          'size' => '60',
        ),
        'type' => 'noderefcreate_autocomplete',
        'weight' => '6',
      ),
    ),
  );

  // Exported field: 'node-network-field_supp_infos'.
  $fields['node-network-field_supp_infos'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_supp_infos',
      'field_permissions' => array(
        'type' => '0',
      ),
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
      'locked' => '0',
      'module' => 'text',
      'settings' => array(
        'field_description_infos' => array(
          'field_description' => 0,
          'field_description_body' => '',
          'field_description_label' => '',
          'field_description_value_type' => 'text',
        ),
      ),
      'translatable' => '1',
      'type' => 'text_long',
    ),
    'field_instance' => array(
      'bundle' => 'network',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'banner_area' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '7',
        ),
        'center_area' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '2',
        ),
        'default' => array(
          'label' => 'above',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => '7',
        ),
        'footer_area' => array(
          'label' => 'above',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => '7',
        ),
        'left_area' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '8',
        ),
        'right_area' => array(
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
      'display_label' => '',
      'entity_type' => 'node',
      'field_name' => 'field_supp_infos',
      'label' => 'Supplementary information',
      'required' => 0,
      'settings' => array(
        'text_processing' => '0',
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'text',
        'settings' => array(
          'rows' => '5',
        ),
        'type' => 'text_textarea',
        'weight' => '7',
      ),
    ),
  );

  // Exported field: 'node-network-field_website'.
  $fields['node-network-field_website'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_website',
      'field_permissions' => array(
        'type' => '0',
      ),
      'foreign keys' => array(),
      'indexes' => array(),
      'locked' => '0',
      'module' => 'link',
      'settings' => array(
        'attributes' => array(
          'class' => '',
          'rel' => '',
          'target' => 'default',
        ),
        'display' => array(
          'url_cutoff' => 80,
        ),
        'enable_tokens' => 1,
        'field_description_infos' => array(
          'field_description' => 0,
          'field_description_body' => '',
          'field_description_label' => '',
          'field_description_value_type' => 'text',
        ),
        'title' => 'optional',
        'title_maxlength' => 128,
        'title_value' => '',
        'url' => 0,
      ),
      'translatable' => '0',
      'type' => 'link_field',
    ),
    'field_instance' => array(
      'bundle' => 'network',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'banner_area' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '5',
        ),
        'center_area' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '3',
        ),
        'default' => array(
          'label' => 'above',
          'module' => 'link',
          'settings' => array(),
          'type' => 'link_default',
          'weight' => '5',
        ),
        'footer_area' => array(
          'label' => 'above',
          'module' => 'link',
          'settings' => array(),
          'type' => 'link_default',
          'weight' => '5',
        ),
        'left_area' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '7',
        ),
        'right_area' => array(
          'label' => 'above',
          'module' => 'link',
          'settings' => array(),
          'type' => 'link_default',
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
      'field_name' => 'field_website',
      'label' => 'Website',
      'required' => 0,
      'settings' => array(
        'attributes' => array(
          'class' => '',
          'configurable_title' => 0,
          'rel' => '',
          'target' => 'default',
          'title' => '',
        ),
        'display' => array(
          'url_cutoff' => '80',
        ),
        'enable_tokens' => 1,
        'title' => 'optional',
        'title_maxlength' => '128',
        'title_value' => '',
        'url' => 0,
        'user_register_form' => FALSE,
        'validate_url' => 1,
      ),
      'widget' => array(
        'active' => 0,
        'module' => 'link',
        'settings' => array(),
        'type' => 'link_field',
        'weight' => '5',
      ),
    ),
  );

  // Exported field: 'node-network-title_field'.
  $fields['node-network-title_field'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'title_field',
      'field_permissions' => array(
        'type' => '0',
      ),
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
      'locked' => '0',
      'module' => 'text',
      'settings' => array(
        'field_description_infos' => array(
          'field_description' => 0,
          'field_description_body' => '',
          'field_description_label' => '',
          'field_description_value_type' => 'text',
        ),
        'max_length' => '255',
      ),
      'translatable' => '1',
      'type' => 'text',
    ),
    'field_instance' => array(
      'bundle' => 'network',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'banner_area' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'center_area' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '4',
        ),
        'default' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 12,
        ),
        'left_area' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '3',
        ),
        'right_area' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
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
      'field_name' => 'title_field',
      'label' => 'Complete name',
      'required' => 1,
      'settings' => array(
        'hide_label' => array(
          'entity' => 0,
          'page' => 0,
        ),
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
        'weight' => -5,
      ),
    ),
  );

  // Exported field: 'node-study-field_networks'.
  $fields['node-study-field_networks'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '-1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_networks',
      'field_permissions' => array(
        'type' => '0',
      ),
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
      'locked' => '0',
      'module' => 'node_reference',
      'settings' => array(
        'referenceable_types' => array(
          'article' => 0,
          'blog' => 0,
          'contact' => 0,
          'data_access_request' => 0,
          'data_access_review' => 0,
          'dataset' => 0,
          'documents' => 0,
          'event' => 0,
          'field_description' => 0,
          'forum' => 0,
          'network' => 'network',
          'page' => 0,
          'panel' => 0,
          'project' => 0,
          'publication' => 0,
          'study' => 0,
          'study_variable_attributes' => 0,
          'teleconference' => 0,
          'variable' => 0,
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
      'bundle' => 'study',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'banner_area' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'center_area' => array(
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
          'weight' => 97,
        ),
        'footer_area' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'left_area' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'right_area' => array(
          'label' => 'above',
          'module' => 'node_reference',
          'settings' => array(),
          'type' => 'node_reference_default',
          'weight' => '4',
        ),
        'summary_banner_area' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'summary_left_area' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'summary_right_area' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
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
      'field_name' => 'field_networks',
      'label' => 'Networks',
      'required' => 0,
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
        'weight' => '6',
      ),
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Acronym');
  t('Acronym of the network if applicable.');
  t('Authorising date');
  t('Authorization Maelstrom');
  t('Authorization from contributors to the Maelstrom Catalogues');
  t('Body');
  t('Complete name');
  t('Contacts');
  t('Investigators');
  t('Logo');
  t('Name of the person authorising the contribution to Maelstrom Research');
  t('Networks');
  t('Studies');
  t('Supplementary information');
  t('Website');

  return $fields;
}
