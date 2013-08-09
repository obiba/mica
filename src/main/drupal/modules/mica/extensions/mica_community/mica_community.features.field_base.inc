<?php
/**
 * @file
 * mica_community.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function mica_community_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_abstract'
  $field_bases['field_abstract'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_abstract',
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

  // Exported field_base: 'field_authors'
  $field_bases['field_authors'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_authors',
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

  // Exported field_base: 'field_event_date'
  $field_bases['field_event_date'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_event_date',
    'foreign keys' => array(),
    'indexes' => array(),
    'locked' => 0,
    'module' => 'date',
    'settings' => array(
      'granularity' => array(
        'day' => 'day',
        'hour' => 'hour',
        'minute' => 'minute',
        'month' => 'month',
        'year' => 'year',
      ),
      'repeat' => 0,
      'timezone_db' => 'UTC',
      'todate' => 'optional',
      'tz_handling' => 'utc',
    ),
    'translatable' => 1,
    'type' => 'date',
  );

  // Exported field_base: 'field_event_files'
  $field_bases['field_event_files'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_event_files',
    'field_permissions' => array(
      'type' => 0,
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
    'locked' => 0,
    'module' => 'file',
    'settings' => array(
      'display_default' => 1,
      'display_field' => 1,
      'field_description_infos' => array(
        'field_description' => 0,
        'field_description_body' => '',
        'field_description_label' => '',
        'field_description_value_type' => 'text',
      ),
      'uri_scheme' => 'public',
    ),
    'translatable' => 0,
    'type' => 'file',
  );

  // Exported field_base: 'field_event_link'
  $field_bases['field_event_link'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_event_link',
    'foreign keys' => array(),
    'indexes' => array(),
    'locked' => 0,
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
        'field_description_value_type' => '',
      ),
      'field_permissions' => array(
        'create' => 0,
        'edit' => 0,
        'edit own' => 0,
        'view' => 0,
        'view own' => 0,
      ),
      'title' => 'optional',
      'title_maxlength' => 128,
      'title_value' => '',
      'url' => 0,
    ),
    'translatable' => 1,
    'type' => 'link_field',
  );

  // Exported field_base: 'field_publication_pmid'
  $field_bases['field_publication_pmid'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_publication_pmid',
    'foreign keys' => array(),
    'indexes' => array(),
    'locked' => 0,
    'module' => 'number',
    'settings' => array(
      'field_description_infos' => array(
        'field_description' => 0,
        'field_description_body' => '',
        'field_description_value_type' => 'integer',
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
    'type' => 'number_integer',
  );

  // Exported field_base: 'field_publication_reference'
  $field_bases['field_publication_reference'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_publication_reference',
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

  // Exported field_base: 'field_publication_url'
  $field_bases['field_publication_url'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_publication_url',
    'foreign keys' => array(),
    'indexes' => array(),
    'locked' => 0,
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
      'field_permissions' => array(
        'create' => 0,
        'edit' => 0,
        'edit own' => 0,
        'view' => 0,
        'view own' => 0,
      ),
      'title' => 'optional',
      'title_maxlength' => 128,
      'title_value' => '',
      'url' => 0,
      'variable_infos' => array(
        'variable' => 0,
        'variable_body' => '',
        'variable_value_type' => '',
      ),
    ),
    'translatable' => 1,
    'type' => 'link_field',
  );

  return $field_bases;
}
