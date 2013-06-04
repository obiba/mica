<?php
/**
 * @file
 * mica_core.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function mica_core_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_profile_first_name'
  $field_bases['field_profile_first_name'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_profile_first_name',
    'field_permissions' => array(
      'type' => 0,
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
    'locked' => 0,
    'module' => 'text',
    'settings' => array(
      'field_description_infos' => array(
        'field_description' => 0,
        'field_description_body' => '',
        'field_description_label' => '',
        'field_description_value_type' => 'text',
      ),
      'max_length' => 255,
      'profile2_private' => 0,
    ),
    'translatable' => 0,
    'type' => 'text',
  );

  // Exported field_base: 'field_profile_last_name'
  $field_bases['field_profile_last_name'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_profile_last_name',
    'field_permissions' => array(
      'type' => 0,
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
    'locked' => 0,
    'module' => 'text',
    'settings' => array(
      'field_description_infos' => array(
        'field_description' => 0,
        'field_description_body' => '',
        'field_description_label' => '',
        'field_description_value_type' => 'text',
      ),
      'max_length' => 255,
      'profile2_private' => 0,
    ),
    'translatable' => 0,
    'type' => 'text',
  );

  return $field_bases;
}
