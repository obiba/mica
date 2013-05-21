<?php
/**
 * @file
 * mica_studies.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function mica_studies_user_default_roles() {
  $roles = array();

  // Exported role: study administrator.
  $roles['study administrator'] = array(
    'name' => 'study administrator',
    'weight' => 5,
  );

  // Exported role: study reviewer.
  $roles['study reviewer'] = array(
    'name' => 'study reviewer',
    'weight' => 4,
  );

  return $roles;
}
