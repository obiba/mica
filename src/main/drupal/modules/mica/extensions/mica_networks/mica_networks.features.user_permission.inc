<?php
/**
 * @file
 * mica_networks.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function mica_networks_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create network content'.
  $permissions['create network content'] = array(
    'name' => 'create network content',
    'roles' => array(
      'administrator' => 'administrator',
      'consortium administrator' => 'consortium administrator',
      'network administrator' => 'network administrator',
      'network reviewer' => 'network reviewer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any network content'.
  $permissions['delete any network content'] = array(
    'name' => 'delete any network content',
    'roles' => array(
      'administrator' => 'administrator',
      'consortium administrator' => 'consortium administrator',
      'network reviewer' => 'network reviewer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own network content'.
  $permissions['delete own network content'] = array(
    'name' => 'delete own network content',
    'roles' => array(
      'administrator' => 'administrator',
      'consortium administrator' => 'consortium administrator',
      'network administrator' => 'network administrator',
      'network reviewer' => 'network reviewer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any network content'.
  $permissions['edit any network content'] = array(
    'name' => 'edit any network content',
    'roles' => array(
      'administrator' => 'administrator',
      'consortium administrator' => 'consortium administrator',
      'network reviewer' => 'network reviewer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own network content'.
  $permissions['edit own network content'] = array(
    'name' => 'edit own network content',
    'roles' => array(
      'administrator' => 'administrator',
      'consortium administrator' => 'consortium administrator',
      'network administrator' => 'network administrator',
      'network reviewer' => 'network reviewer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'view any unpublished network content'.
  $permissions['view any unpublished network content'] = array(
    'name' => 'view any unpublished network content',
    'roles' => array(
      'administrator' => 'administrator',
      'consortium administrator' => 'consortium administrator',
      'network reviewer' => 'network reviewer',
    ),
    'module' => 'view_unpublished',
  );

  return $permissions;
}
