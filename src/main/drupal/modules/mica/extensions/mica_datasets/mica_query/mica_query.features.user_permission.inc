<?php
/**
 * @file
 * mica_query.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function mica_query_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create edit delete own dataset query'.
  $permissions['create edit delete own dataset query'] = array(
    'name' => 'create edit delete own dataset query',
    'roles' => array(
      'administrator' => 'administrator',
      'consortium administrator' => 'consortium administrator',
      'dataset administrator' => 'dataset administrator',
      'dataset reviewer' => 'dataset reviewer',
      'researcher' => 'researcher',
    ),
    'module' => 'mica_query',
  );

  // Exported permission: 'edit delete any dataset query'.
  $permissions['edit delete any dataset query'] = array(
    'name' => 'edit delete any dataset query',
    'roles' => array(
      'administrator' => 'administrator',
      'consortium administrator' => 'consortium administrator',
      'dataset administrator' => 'dataset administrator',
    ),
    'module' => 'mica_query',
  );

  // Exported permission: 'publish dataset query'.
  $permissions['publish dataset query'] = array(
    'name' => 'publish dataset query',
    'roles' => array(
      'administrator' => 'administrator',
      'consortium administrator' => 'consortium administrator',
      'dataset administrator' => 'dataset administrator',
      'dataset reviewer' => 'dataset reviewer',
    ),
    'module' => 'mica_query',
  );

  // Exported permission: 'view any dataset query'.
  $permissions['view any dataset query'] = array(
    'name' => 'view any dataset query',
    'roles' => array(
      'administrator' => 'administrator',
      'consortium administrator' => 'consortium administrator',
      'dataset administrator' => 'dataset administrator',
      'dataset reviewer' => 'dataset reviewer',
      'researcher' => 'researcher',
    ),
    'module' => 'mica_query',
  );

  return $permissions;
}
