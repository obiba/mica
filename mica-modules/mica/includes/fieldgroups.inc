<?php

/**
 * @file
 * Utility functions for handling field grouping. 
 */

function _mica_add_fieldset_group($bundle, $group_name, $label, $weight, $parent_name, $children) {
  _mica_add_mode_fieldset_group($bundle, 'form', $group_name, $label, $weight, $parent_name, $children);
  _mica_add_mode_fieldset_group($bundle, 'default', $group_name, $label, $weight, $parent_name, $children);
}

function _mica_add_mode_fieldset_group($bundle, $mode, $group_name, $label, $weight, $parent_name, $children) {
  $field_group = new stdClass;
  $field_group->api_version = 1;
  $field_group->identifier = $group_name . '|node|' . $bundle . '|' . $mode;
  $field_group->group_name = $group_name;
  $field_group->entity_type = 'node';
  $field_group->bundle = $bundle;
  $field_group->mode = $mode;
  $field_group->parent_name = $parent_name;
  $field_group->label = $label;
  $field_group->weight = $weight;
  $field_group->children = $children;
  $field_group->format_type = 'fieldset';
  $field_group->format_settings = array(
    'formatter' => 'collapsible',
    'instance_settings' => array(
      'classes' => '',
      'required_fields' => 1,
    ),
  );
  field_group_save($field_group);
}