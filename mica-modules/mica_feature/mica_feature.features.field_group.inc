<?php
/**
 * @file
 * mica_feature.features.field_group.inc
 */

/**
 * Implementation of hook_field_group_default_field_groups().
 */
function mica_feature_field_group_default_field_groups() {
  $field_groups = array();

  // Exported field_group: 'node-fractures-default-group_1'
  $field_groups['node-fractures-default-group_1'] = array(
    'group_name' => 'group_1',
    'entity_type' => 'node',
    'bundle' => 'fractures',
    'mode' => 'default',
    'parent_name' => '',
    'label' => 'Information',
    'weight' => '0',
    'children' => array(
      0 => 'field_f100',
      1 => 'field_f106',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'classes' => '',
      ),
    ),
  );

  // Exported field_group: 'node-fractures-default-group_2'
  $field_groups['node-fractures-default-group_2'] = array(
    'group_name' => 'group_2',
    'entity_type' => 'node',
    'bundle' => 'fractures',
    'mode' => 'default',
    'parent_name' => '',
    'label' => 'Statistics',
    'weight' => '1',
    'children' => array(
      0 => 'field_f101',
      1 => 'field_102a',
      2 => 'field_102b',
      3 => 'field_103a',
      4 => 'field_103b',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'classes' => '',
      ),
    ),
  );

  // Exported field_group: 'node-fractures-form-group_1'
  $field_groups['node-fractures-form-group_1'] = array(
    'group_name' => 'group_1',
    'entity_type' => 'node',
    'bundle' => 'fractures',
    'mode' => 'form',
    'parent_name' => '',
    'label' => 'Information',
    'weight' => '1',
    'children' => array(
      0 => 'field_f100',
      1 => 'field_f106',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'classes' => '',
      ),
    ),
  );

  // Exported field_group: 'node-fractures-form-group_2'
  $field_groups['node-fractures-form-group_2'] = array(
    'group_name' => 'group_2',
    'entity_type' => 'node',
    'bundle' => 'fractures',
    'mode' => 'form',
    'parent_name' => '',
    'label' => 'Statistics',
    'weight' => '2',
    'children' => array(
      0 => 'field_f101',
      1 => 'field_102a',
      2 => 'field_102b',
      3 => 'field_103a',
      4 => 'field_103b',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'classes' => '',
      ),
    ),
  );

  // Exported field_group: 'node-study_information-default-group_1'
  $field_groups['node-study_information-default-group_1'] = array(
    'group_name' => 'group_1',
    'entity_type' => 'node',
    'bundle' => 'study_information',
    'mode' => 'default',
    'parent_name' => '',
    'label' => 'Summary',
    'weight' => '0',
    'children' => array(
      0 => 'field_g2',
      1 => 'field_g4',
      2 => 'field_g4b',
      3 => 'field_g5a',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'classes' => '',
      ),
    ),
  );

  // Exported field_group: 'node-study_information-default-group_2'
  $field_groups['node-study_information-default-group_2'] = array(
    'group_name' => 'group_2',
    'entity_type' => 'node',
    'bundle' => 'study_information',
    'mode' => 'default',
    'parent_name' => '',
    'label' => 'Information',
    'weight' => '1',
    'children' => array(
      0 => 'field_g3',
      1 => 'field_g6',
      2 => 'field_g7',
      3 => 'field_g8',
      4 => 'field_g8c',
      5 => 'field_g10',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'classes' => '',
      ),
    ),
  );

  // Exported field_group: 'node-study_information-default-group_3'
  $field_groups['node-study_information-default-group_3'] = array(
    'group_name' => 'group_3',
    'entity_type' => 'node',
    'bundle' => 'study_information',
    'mode' => 'default',
    'parent_name' => '',
    'label' => 'Statistics',
    'weight' => '5',
    'children' => array(
      0 => 'field_g8d',
      1 => 'field_g8e',
      2 => 'field_g9a',
      3 => 'field_g9b',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'classes' => '',
      ),
    ),
  );

  // Exported field_group: 'node-study_information-form-group_1'
  $field_groups['node-study_information-form-group_1'] = array(
    'group_name' => 'group_1',
    'entity_type' => 'node',
    'bundle' => 'study_information',
    'mode' => 'form',
    'parent_name' => '',
    'label' => 'Summary',
    'weight' => '1',
    'children' => array(
      0 => 'field_g2',
      1 => 'field_g4',
      2 => 'field_g4b',
      3 => 'field_g5a',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Summary',
      'instance_settings' => array(
        'classes' => '',
      ),
      'formatter' => 'collapsible',
    ),
  );

  // Exported field_group: 'node-study_information-form-group_2'
  $field_groups['node-study_information-form-group_2'] = array(
    'group_name' => 'group_2',
    'entity_type' => 'node',
    'bundle' => 'study_information',
    'mode' => 'form',
    'parent_name' => '',
    'label' => 'Information',
    'weight' => '2',
    'children' => array(
      0 => 'field_g3',
      1 => 'field_g6',
      2 => 'field_g7',
      3 => 'field_g8',
      4 => 'field_g8c',
      5 => 'field_g10',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Information',
      'instance_settings' => array(
        'classes' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );

  // Exported field_group: 'node-study_information-form-group_3'
  $field_groups['node-study_information-form-group_3'] = array(
    'group_name' => 'group_3',
    'entity_type' => 'node',
    'bundle' => 'study_information',
    'mode' => 'form',
    'parent_name' => '',
    'label' => 'Statistics',
    'weight' => '3',
    'children' => array(
      0 => 'field_g8d',
      1 => 'field_g8e',
      2 => 'field_g9a',
      3 => 'field_g9b',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Statistics',
      'instance_settings' => array(
        'classes' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );

  return $field_groups;
}
