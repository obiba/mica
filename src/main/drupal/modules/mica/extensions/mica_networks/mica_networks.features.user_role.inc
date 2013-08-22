<?php
/**
 * @file
 * mica_networks.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function mica_networks_user_default_roles() {
  $roles = array();

  // Exported role: network administrator.
  $roles['network administrator'] = array(
    'name' => 'network administrator',
    'weight' => 11,
  );

  // Exported role: network reviewer.
  $roles['network reviewer'] = array(
    'name' => 'network reviewer',
    'weight' => 10,
  );

  return $roles;
}
