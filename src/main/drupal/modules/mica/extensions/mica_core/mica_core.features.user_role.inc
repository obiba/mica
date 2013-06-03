<?php
/**
 * @file
 * mica_core.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function mica_core_user_default_roles() {
  $roles = array();

  // Exported role: consortium administrator.
  $roles['consortium administrator'] = array(
    'name' => 'consortium administrator',
    'weight' => 3,
  );

  return $roles;
}
