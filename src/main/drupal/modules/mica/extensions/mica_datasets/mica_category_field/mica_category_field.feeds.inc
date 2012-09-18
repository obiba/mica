<?php

/**
 * @file
 * Integration with the Feeds module.
 */

/**
 * Implements hook_feeds_processor_targets_alter().
 */
function mica_category_field_feeds_processor_targets_alter(&$targets, $entity_type, $bundle_name) {
  foreach (field_info_instances($entity_type, $bundle_name) as $name => $instance) {
    $info = field_info_field($name);
    if ($info['type'] === 'category_field') {
      foreach ($info['columns'] as $sub_field => $schema_info) {
        $name_label = $instance['label'] . ': ' . drupal_ucfirst(str_replace('_', ' ', $sub_field));
        $targets[$name . ':' . $sub_field] = array(
          'name' => $name_label,
          'callback' => 'mica_category_field_set_target',
          'real_target' => $info['field_name'],
          'description' => $schema_info['description'],
        );
      }
    }
  }
}

/**
 * Callback for hook_feeds_set_target().
 *
 * @param $source
 *   Field mapper source settings.
 * @param $entity
 *   An entity object, for instance a node object.
 * @param $target
 *   A string identifying the target on the node.
 * @param $value
 *   The value to populate the target with.
 */
function mica_category_field_set_target($source, $entity, $target, $value) {

  if (empty($value)) {
    return;
  }

  list($field_name, $sub_field) = explode(':', $target, 2);

  // Handle non-multiple value fields.
  if (!is_array($value)) {
    $value = array($value);
  }

  $field = isset($entity->$field_name) ? $entity->$field_name : array();

  foreach ($value as $i => $v) {
    // if we receive true/false, switch to '0' - '1'
    $v = is_bool($v) ? (int) $v : $v;
    // TODO this does not support i18n
    $field[LANGUAGE_NONE][$i][$sub_field] = isset($v) ? $v : '0';
  }

  $entity->$field_name = $field;
}
