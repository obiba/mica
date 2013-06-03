<?php
/**
 * @file
 * mica_data_access.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function mica_data_access_user_default_roles() {
  $roles = array();

  // Exported role: data access committee officer.
  $roles['data access committee officer'] = array(
    'name' => 'data access committee officer',
    'weight' => 6,
  );

  // Exported role: researcher.
  $roles['researcher'] = array(
    'name' => 'researcher',
    'weight' => 7,
  );

  return $roles;
}
