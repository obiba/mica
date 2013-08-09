<?php
/**
 * @file
 * mica_projects.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function mica_projects_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_instructions'
  $field_bases['field_instructions'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_instructions',
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

  // Exported field_base: 'field_minutes'
  $field_bases['field_minutes'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_minutes',
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
      'display_default' => 0,
      'display_field' => 0,
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
      'uri_scheme' => 'public',
    ),
    'translatable' => 1,
    'type' => 'file',
  );

  // Exported field_base: 'field_project'
  $field_bases['field_project'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
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
        'project' => 'project',
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

  // Exported field_base: 'field_project_description'
  $field_bases['field_project_description'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_project_description',
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
    'settings' => array(),
    'translatable' => 0,
    'type' => 'text_with_summary',
  );

  // Exported field_base: 'field_studies'
  $field_bases['field_studies'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_studies',
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
    'translatable' => 1,
    'type' => 'node_reference',
  );

  // Exported field_base: 'field_teleconference_date'
  $field_bases['field_teleconference_date'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_teleconference_date',
    'foreign keys' => array(),
    'indexes' => array(),
    'locked' => 0,
    'module' => 'date',
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

  // Exported field_base: 'field_teleconference_description'
  $field_bases['field_teleconference_description'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_teleconference_description',
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

  // Exported field_base: 'field_teleconferences'
  $field_bases['field_teleconferences'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_teleconferences',
    'foreign keys' => array(),
    'indexes' => array(
      'view_id' => array(
        0 => 'view_id',
      ),
    ),
    'locked' => 0,
    'module' => 'viewreference',
    'settings' => array(
      'append_id' => 0,
      'arguments' => array(
        'delimiter' => '/',
        'dsv_arguments' => 1,
        'php_arguments' => 0,
        'rows' => 1,
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
      'referenceable_tags' => array(
        'allow' => '',
        'deny' => '',
      ),
      'referenceable_views' => array(
        'archive:block' => 0,
        'archive:page' => 0,
        'backlinks:block' => 0,
        'backlinks:page' => 0,
        'calendar:block_1' => 0,
        'calendar:calendar_1' => 0,
        'calendar:calendar_block_1' => 0,
        'calendar:calendar_period_1' => 0,
        'calendar:calendar_period_2' => 0,
        'calendar:calendar_period_3' => 0,
        'calendar:calendar_period_4' => 0,
        'calendar:calendar_period_5' => 0,
        'comments_recent:block' => 0,
        'comments_recent:page' => 0,
        'community:page' => 0,
        'csv_contact_export:views_data_export_1' => 0,
        'csv_field_description_export:views_data_export_1' => 0,
        'csv_institution_export:views_data_export_1' => 0,
        'csv_study_export:views_data_export_1' => 0,
        'date_browser:date_nav_1' => 0,
        'date_browser:page' => 0,
        'events:feed' => 0,
        'events:page' => 0,
        'events_calendar:block_1' => 0,
        'events_calendar:calendar_1' => 0,
        'events_calendar:calendar_block_1' => 0,
        'events_calendar:calendar_period_1' => 0,
        'events_calendar:calendar_period_2' => 0,
        'events_calendar:calendar_period_3' => 0,
        'events_calendar:calendar_period_4' => 0,
        'events_calendar:calendar_period_5' => 0,
        'feeds_log:page_1' => 0,
        'feeds_log:page_2' => 0,
        'feeds_log:page_3' => 0,
        'fields_description_search:page' => 0,
        'frontpage:feed' => 0,
        'frontpage:page' => 0,
        'glossary:attachment' => 0,
        'glossary:page' => 0,
        'projects:page' => 0,
        'publications:page' => 0,
        'studies:page' => 0,
        'studies_search:page' => 0,
        'taxonomy_term:feed' => 0,
        'taxonomy_term:feed_1' => 0,
        'taxonomy_term:page' => 0,
        'teleconferences:page' => 'teleconferences:page',
        'tracker:page' => 0,
      ),
      'skip_default' => 1,
      'skip_empty' => 0,
    ),
    'translatable' => 1,
    'type' => 'viewreference',
  );

  return $field_bases;
}
