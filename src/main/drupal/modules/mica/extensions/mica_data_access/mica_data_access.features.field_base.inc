<?php
/**
 * @file
 * mica_data_access.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function mica_data_access_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_collaborator'
  $field_bases['field_collaborator'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_collaborator',
    'foreign keys' => array(),
    'indexes' => array(
      'family' => array(
        0 => 'family',
      ),
      'given' => array(
        0 => 'given',
      ),
    ),
    'locked' => 0,
    'module' => 'name',
    'settings' => array(
      'allow_family_or_given' => 0,
      'autocomplete_separator' => array(
        'credentials' => ', ',
        'family' => ' -',
        'generational' => ' ',
        'given' => ' -',
        'middle' => ' -',
        'title' => ' ',
      ),
      'autocomplete_source' => array(
        'credentials' => array(
          'namedb' => 0,
        ),
        'family' => array(
          'namedb' => 0,
        ),
        'generational' => array(
          'generational' => 0,
          'namedb' => 0,
        ),
        'given' => array(
          'namedb' => 0,
        ),
        'middle' => array(
          'namedb' => 0,
        ),
        'title' => array(
          'namedb' => 0,
          'title' => 'title',
        ),
      ),
      'components' => array(
        'credentials' => 0,
        'family' => 'family',
        'generational' => 0,
        'given' => 'given',
        'middle' => 0,
        'title' => 'title',
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
      'generational_options' => '-- --
Jr.
Sr.
I
II
III
IV
V
VI
VII
VIII
IX
X',
      'labels' => array(
        'credentials' => 'Credentials',
        'family' => 'Family',
        'generational' => 'Generational',
        'given' => 'Given',
        'middle' => 'Middle name(s)',
        'title' => 'Title',
      ),
      'max_length' => array(
        'credentials' => 255,
        'family' => 63,
        'generational' => 15,
        'given' => 63,
        'middle' => 127,
        'title' => 31,
      ),
      'minimum_components' => array(
        'credentials' => 0,
        'family' => 'family',
        'generational' => 0,
        'given' => 'given',
        'middle' => 0,
        'title' => 0,
      ),
      'sort_options' => array(
        'generational' => 0,
        'title' => 'title',
      ),
      'title_options' => '-- --
Mr.
Mrs.
Miss
Ms.
Dr.
Prof.',
    ),
    'translatable' => 1,
    'type' => 'name',
  );

  // Exported field_base: 'field_country_text'
  $field_bases['field_country_text'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_country_text',
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
    'locked' => 0,
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
      'max_length' => 255,
    ),
    'translatable' => 1,
    'type' => 'text',
  );

  // Exported field_base: 'field_data_access'
  $field_bases['field_data_access'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_data_access',
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
    'locked' => 0,
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
        'data_access_request' => 'data_access_request',
        'data_access_review' => 0,
        'dataset' => 0,
        'documents' => 0,
        'event' => 0,
        'field_description' => 0,
        'forum' => 0,
        'institution' => 0,
        'page' => 0,
        'panel' => 0,
        'publication' => 0,
        'study' => 0,
        'variable' => 0,
      ),
      'view' => array(
        'args' => array(),
        'display_name' => '',
        'view_name' => '',
      ),
    ),
    'translatable' => 1,
    'type' => 'node_reference',
  );

  // Exported field_base: 'field_data_access_review'
  $field_bases['field_data_access_review'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_data_access_review',
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
    'locked' => 0,
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
        'data_access_review' => 'data_access_review',
        'dataset' => 0,
        'documents' => 0,
        'event' => 0,
        'field_description' => 0,
        'forum' => 0,
        'institution' => 0,
        'page' => 0,
        'panel' => 0,
        'publication' => 0,
        'study' => 0,
        'variable' => 0,
      ),
      'view' => array(
        'args' => array(),
        'display_name' => '',
        'view_name' => '',
      ),
    ),
    'translatable' => 1,
    'type' => 'node_reference',
  );

  // Exported field_base: 'field_dataset_access'
  $field_bases['field_dataset_access'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_dataset_access',
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
    'locked' => 0,
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
        'dataset' => 'dataset',
        'documents' => 0,
        'event' => 0,
        'field_description' => 0,
        'forum' => 0,
        'institution' => 0,
        'page' => 0,
        'panel' => 0,
        'project' => 0,
        'publication' => 0,
        'study' => 0,
        'teleconference' => 0,
        'variable' => 0,
      ),
      'view' => array(
        'args' => array(),
        'display_name' => '',
        'view_name' => '',
      ),
    ),
    'translatable' => 1,
    'type' => 'node_reference',
  );

  // Exported field_base: 'field_project_summary'
  $field_bases['field_project_summary'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_project_summary',
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
    'locked' => 0,
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
    ),
    'translatable' => 1,
    'type' => 'text_with_summary',
  );

  // Exported field_base: 'field_rep_email'
  $field_bases['field_rep_email'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_rep_email',
    'foreign keys' => array(),
    'indexes' => array(),
    'locked' => 0,
    'module' => 'email',
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
    ),
    'translatable' => 1,
    'type' => 'email',
  );

  // Exported field_base: 'field_representative'
  $field_bases['field_representative'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_representative',
    'foreign keys' => array(),
    'indexes' => array(
      'family' => array(
        0 => 'family',
      ),
      'given' => array(
        0 => 'given',
      ),
    ),
    'locked' => 0,
    'module' => 'name',
    'settings' => array(
      'allow_family_or_given' => 0,
      'autocomplete_separator' => array(
        'credentials' => ', ',
        'family' => ' -',
        'generational' => ' ',
        'given' => ' -',
        'middle' => ' -',
        'title' => ' ',
      ),
      'autocomplete_source' => array(
        'credentials' => array(
          'namedb' => 0,
        ),
        'family' => array(
          'namedb' => 0,
        ),
        'generational' => array(
          'generational' => 0,
          'namedb' => 0,
        ),
        'given' => array(
          'namedb' => 0,
        ),
        'middle' => array(
          'namedb' => 0,
        ),
        'title' => array(
          'namedb' => 0,
          'title' => 'title',
        ),
      ),
      'components' => array(
        'credentials' => 0,
        'family' => 'family',
        'generational' => 0,
        'given' => 'given',
        'middle' => 0,
        'title' => 'title',
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
      'generational_options' => '-- --
Jr.
Sr.
I
II
III
IV
V
VI
VII
VIII
IX
X',
      'labels' => array(
        'credentials' => 'Credentials',
        'family' => 'Family',
        'generational' => 'Generational',
        'given' => 'Given',
        'middle' => 'Middle name(s)',
        'title' => 'Title',
      ),
      'max_length' => array(
        'credentials' => 255,
        'family' => 63,
        'generational' => 15,
        'given' => 63,
        'middle' => 127,
        'title' => 31,
      ),
      'minimum_components' => array(
        'credentials' => 0,
        'family' => 'family',
        'generational' => 0,
        'given' => 'given',
        'middle' => 0,
        'title' => 0,
      ),
      'sort_options' => array(
        'generational' => 0,
        'title' => 'title',
      ),
      'title_options' => '-- --
Mr.
Mrs.
Miss
Ms.
Dr.
Prof.',
    ),
    'translatable' => 1,
    'type' => 'name',
  );

  // Exported field_base: 'field_review_notes'
  $field_bases['field_review_notes'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_review_notes',
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
    'locked' => 0,
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
    ),
    'translatable' => 1,
    'type' => 'text_long',
  );

  // Exported field_base: 'field_review_status'
  $field_bases['field_review_status'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_review_status',
    'foreign keys' => array(),
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => 0,
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(
        'accepted' => 'Accepted',
        'rejected' => 'Rejected',
        'submitted' => 'Submitted',
        'incomplete' => 'Incomplete',
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
    'translatable' => 1,
    'type' => 'list_text',
  );

  // Exported field_base: 'field_street'
  $field_bases['field_street'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_street',
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
    'locked' => 0,
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
      'max_length' => 255,
    ),
    'translatable' => 1,
    'type' => 'text',
  );

  return $field_bases;
}
