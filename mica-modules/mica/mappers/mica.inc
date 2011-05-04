<?php
// $Id$

/**
 * @file
 * Mica mapper for mica fields.
 */

/**
 * Implementation of hook_feeds_node_processor_targets_alter().
 */
function mica_feeds_processor_targets_alter(&$targets, $entity_type, $bundle_name) {
  foreach (field_info_instances($entity_type, $bundle_name) as $name => $instance) {
    debug($name);
    if ($name == 'body') {
      $targets[$name] = array(
        'name' => $name,
        'callback' => 'mica_feeds_set_target_body',
        'description' => t('The @label field of the node.', array('@label' => $instance['label'])),
      );
    }
    elseif ($name == 'title') {
      $targets[$name] = array(
        'name' => $name,
        'callback' => 'mica_feeds_set_target_title',
        'description' => t('The @label field of the node.', array('@label' => $instance['label'])),
      );
    }
    elseif ($name == 'field_study_legacy_id') {
      $targets['field_study_legacy_id'] = array(
        'name' => $instance['label'],
        'callback' => 'mica_feeds_set_target_legacy_id',
        'description' => t('The Legacy Id of the parent Study of the node.', array('@label' => $instance['label'])),
      );
    }
  }
}

function mica_feeds_set_target_title($source, $entity, $target, $value ) {
  _mica_set_target($source, $entity, $target, $value);
}

function mica_feeds_set_target_body($source, $entity, $target, $value) {
  _mica_set_target($source, $entity, $target, $value);
}

function mica_feeds_set_target_legacy_id($source, $entity, $target, $value) {
  // Get the study parent of this node...
  _mica_set_target($source, $entity, $target, $value);
}

/**
 * Callback for mapping. Here is where the actual mapping happens.
 *
 * When the callback is invoked, $target contains the name of the field the
 * user has decided to map to and $value contains the value of the feed item
 * element the user has picked as a source.
 */
function _mica_set_target($source, $entity, $target, $value, $value_field = 'value') {
  if (empty($value)) {
    return;
  }

  // Handle non-multiple value fields.
  if (!is_array($value)) {
    $value = array($value);
  }

  // Iterate over all values.
  $i = 0;
  $info = field_info_field($target);
  list($field_name, $sub_field) = explode(':', $target);
  foreach ($value as $v) {
    $new_value = $v;
    if (!is_array($new_value) && !is_object($new_value)) {
      if (isset($sub_field)) {
        $field['und'][$i][$sub_field] = $new_value;
      }
      else{
        $field['und'][$i][$value_field] = $new_value;
      }
    }
    if ($info['cardinality'] == 1) {
      break;
    }
    $i++;
  }
 
  if (isset($sub_field)) {
    foreach ($field['und'] as $i => $sub) {
      $entity->{$field_name}['und'][$i][$sub_field] = $field['und'][$i][$sub_field]; 
    }
  }
  else {
    $entity->{$field_name} = $field;
  }
}