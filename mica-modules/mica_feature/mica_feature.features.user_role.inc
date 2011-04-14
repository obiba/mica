<?php
/**
 * @file
 * mica_feature.features.user_role.inc
 */

/**
 * Implementation of hook_user_default_roles().
 */
function mica_feature_user_default_roles() {
  $roles = array();

  // Exported role: administrator
  $roles['administrator'] = array(
    'name' => 'administrator',
    'weight' => '2',
  );

  // Exported role: studies administrator
  $roles['studies administrator'] = array(
    'name' => 'studies administrator',
    'weight' => '3',
  );

  // Exported role: study administrator
  $roles['study administrator'] = array(
    'name' => 'study administrator',
    'weight' => '4',
  );

  return $roles;
}
