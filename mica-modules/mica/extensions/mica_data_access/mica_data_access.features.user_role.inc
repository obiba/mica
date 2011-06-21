<?php
/**
 * @file
 * mica_data_access.features.user_role.inc
 */

/**
 * Implementation of hook_user_default_roles().
 */
function mica_data_access_user_default_roles() {
  $roles = array();

  // Exported role: data access committee member
  $roles['data access committee member'] = array(
    'name' => 'data access committee member',
    'weight' => '5',
  );

  return $roles;
}
