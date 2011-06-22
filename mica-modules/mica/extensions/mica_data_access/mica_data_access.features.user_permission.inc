<?php
/**
 * @file
 * mica_data_access.features.user_permission.inc
 */

/**
 * Implementation of hook_user_default_permissions().
 */
function mica_data_access_user_default_permissions() {
  $permissions = array();

  // Exported permission: create data_access_request content
  $permissions['create data_access_request content'] = array(
    'name' => 'create data_access_request content',
    'roles' => array(
      0 => 'anonymous user',
      1 => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: create data_access_review content
  $permissions['create data_access_review content'] = array(
    'name' => 'create data_access_review content',
    'roles' => array(
      0 => 'consortium administrator',
      1 => 'data access committee member',
    ),
    'module' => 'node',
  );

  // Exported permission: delete any data_access_request content
  $permissions['delete any data_access_request content'] = array(
    'name' => 'delete any data_access_request content',
    'roles' => array(
      0 => 'consortium administrator',
      1 => 'data access committee member',
    ),
    'module' => 'node',
  );

  // Exported permission: delete any data_access_review content
  $permissions['delete any data_access_review content'] = array(
    'name' => 'delete any data_access_review content',
    'roles' => array(
      0 => 'consortium administrator',
      1 => 'data access committee member',
    ),
    'module' => 'node',
  );

  // Exported permission: delete own data_access_request content
  $permissions['delete own data_access_request content'] = array(
    'name' => 'delete own data_access_request content',
    'roles' => array(
      0 => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: delete own data_access_review content
  $permissions['delete own data_access_review content'] = array(
    'name' => 'delete own data_access_review content',
    'roles' => array(
      0 => 'consortium administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: edit any data_access_request content
  $permissions['edit any data_access_request content'] = array(
    'name' => 'edit any data_access_request content',
    'roles' => array(
      0 => 'consortium administrator',
      1 => 'data access committee member',
    ),
    'module' => 'node',
  );

  // Exported permission: edit any data_access_review content
  $permissions['edit any data_access_review content'] = array(
    'name' => 'edit any data_access_review content',
    'roles' => array(
      0 => 'consortium administrator',
      1 => 'data access committee member',
    ),
    'module' => 'node',
  );

  // Exported permission: edit own data_access_request content
  $permissions['edit own data_access_request content'] = array(
    'name' => 'edit own data_access_request content',
    'roles' => array(
      0 => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: edit own data_access_review content
  $permissions['edit own data_access_review content'] = array(
    'name' => 'edit own data_access_review content',
    'roles' => array(
      0 => 'consortium administrator',
      1 => 'data access committee member',
    ),
    'module' => 'node',
  );

  return $permissions;
}
