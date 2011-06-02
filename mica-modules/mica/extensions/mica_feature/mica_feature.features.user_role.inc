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

  // Exported role: mica administrator
  $roles['mica administrator'] = array(
    'name' => 'mica administrator',
    'weight' => '3',
  );

  // Exported role: study administrator
  $roles['study administrator'] = array(
    'name' => 'study administrator',
    'weight' => '4',
  );

  return $roles;
}
