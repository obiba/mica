<?php
/**
 * @file
 * mica_core.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function mica_core_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'menu view unpublished'.
  $permissions['menu view unpublished'] = array(
    'name' => 'menu view unpublished',
    'roles' => array(
      'administrator' => 'administrator',
      'consortium administrator' => 'consortium administrator',
    ),
    'module' => 'menu_view_unpublished',
  );

  return $permissions;
}
