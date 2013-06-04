<?php
/**
 * @file
 * mica_datasets.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function mica_datasets_user_default_roles() {
  $roles = array();

  // Exported role: dataset administrator.
  $roles['dataset administrator'] = array(
    'name' => 'dataset administrator',
    'weight' => 9,
  );

  // Exported role: dataset reviewer.
  $roles['dataset reviewer'] = array(
    'name' => 'dataset reviewer',
    'weight' => 8,
  );

  return $roles;
}
