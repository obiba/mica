<?php
/**
 * @file
 * mica_networks.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function mica_networks_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_networks'
  $field_bases['field_networks'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_networks',
    'field_permissions' => array(
      'type' => 0,
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
    'locked' => 0,
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
    'translatable' => 0,
    'type' => 'node_reference',
  );

  return $field_bases;
}
