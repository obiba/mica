<?php
// $Id$

/**
 * @file
 * Email mapper.
 */

/**
 * Implementation of hook_feeds_node_processor_targets_alter().
 */
function email_feeds_processor_targets_alter(&$targets, $entity_type, $bundle_name) {
  foreach (field_info_instances($entity_type, $bundle_name) as $name => $instance) {
    $info = field_info_field($name);
    if ($info['type'] == 'email') {
      $targets[$name . ':email'] = array(
            'name' => $instance['label'],
            'callback' => 'email_feeds_set_target_email',
            'description' => t('The @name field of the node.', array('@name' => $instance['label'])),
      );
    }
  }
}

function email_feeds_set_target_email($source, $entity, $target, $value) {
  _email_set_target($source, $entity, $target, $value);
}

/**
 * Callback for mapping. Here is where the actual mapping happens.
 *
 * When the callback is invoked, $target contains the name of the field the
 * user has decided to map to and $value contains the value of the feed item
 * element the user has picked as a source.
 */
function _email_set_target($source, $entity, $target, $value, $value_field = 'value') {
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
    if (!is_array($v) && !is_object($v)) {
      if (isset($sub_field)) {
        $field[LANGUAGE_NONE][$i][$sub_field] = $v;
      }
      else{
          $field[LANGUAGE_NONE][$i][$value_field] = $v;
      }
    }
    if ($info['cardinality'] == 1) {
      break;
    }
    $i++;
  }

  if (isset($sub_field)) {
    foreach ($field[LANGUAGE_NONE] as $i => $sub) {
      $entity->{$field_name}[LANGUAGE_NONE][$i][$sub_field] = $field[LANGUAGE_NONE][$i][$sub_field];
    }
  }
  else{
    $entity->{$field_name} = $field;
  }
}

