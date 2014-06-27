<?php
/**
 * @file
 * mica_publications.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function mica_publications_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_category'
  $field_bases['field_category'] = array(
    'active' => 1,
    'cardinality' => 5,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_category',
    'field_permissions' => array(
      'type' => 0,
    ),
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
    'locked' => 0,
    'module' => 'taxonomy',
    'settings' => array(
      'allowed_values' => array(
        0 => array(
          'vocabulary' => 'publications_categories',
          'parent' => 0,
        ),
      ),
      'field_description_infos' => array(
        'field_description' => 0,
        'field_description_body' => '',
        'field_description_label' => '',
        'field_description_value_type' => 'text',
      ),
      'options_list_callback' => 'i18n_taxonomy_allowed_values',
      'profile2_private' => FALSE,
    ),
    'translatable' => 0,
    'type' => 'taxonomy_term_reference',
  );

  return $field_bases;
}
