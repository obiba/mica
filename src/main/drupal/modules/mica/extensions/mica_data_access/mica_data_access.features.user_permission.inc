<?php
/**
 * @file
 * mica_data_access.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function mica_data_access_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'access print'.
  $permissions['access print'] = array(
    'name' => 'access print',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'print',
  );

  // Exported permission: 'administer print'.
  $permissions['administer print'] = array(
    'name' => 'administer print',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'print',
  );

  // Exported permission: 'create data_access_request content'.
  $permissions['create data_access_request content'] = array(
    'name' => 'create data_access_request content',
    'roles' => array(
      'administrator' => 'administrator',
      'consortium administrator' => 'consortium administrator',
      'researcher' => 'researcher',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create data_access_review content'.
  $permissions['create data_access_review content'] = array(
    'name' => 'create data_access_review content',
    'roles' => array(
      'administrator' => 'administrator',
      'consortium administrator' => 'consortium administrator',
      'data access committee officer' => 'data access committee officer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any data_access_request content'.
  $permissions['delete any data_access_request content'] = array(
    'name' => 'delete any data_access_request content',
    'roles' => array(
      'administrator' => 'administrator',
      'consortium administrator' => 'consortium administrator',
      'data access committee officer' => 'data access committee officer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any data_access_review content'.
  $permissions['delete any data_access_review content'] = array(
    'name' => 'delete any data_access_review content',
    'roles' => array(
      'administrator' => 'administrator',
      'consortium administrator' => 'consortium administrator',
      'data access committee officer' => 'data access committee officer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own data_access_request content'.
  $permissions['delete own data_access_request content'] = array(
    'name' => 'delete own data_access_request content',
    'roles' => array(
      'administrator' => 'administrator',
      'consortium administrator' => 'consortium administrator',
      'researcher' => 'researcher',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own data_access_review content'.
  $permissions['delete own data_access_review content'] = array(
    'name' => 'delete own data_access_review content',
    'roles' => array(
      'administrator' => 'administrator',
      'consortium administrator' => 'consortium administrator',
      'data access committee officer' => 'data access committee officer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any data_access_request content'.
  $permissions['edit any data_access_request content'] = array(
    'name' => 'edit any data_access_request content',
    'roles' => array(
      'administrator' => 'administrator',
      'consortium administrator' => 'consortium administrator',
      'data access committee officer' => 'data access committee officer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any data_access_review content'.
  $permissions['edit any data_access_review content'] = array(
    'name' => 'edit any data_access_review content',
    'roles' => array(
      'administrator' => 'administrator',
      'consortium administrator' => 'consortium administrator',
      'data access committee officer' => 'data access committee officer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own data_access_request content'.
  $permissions['edit own data_access_request content'] = array(
    'name' => 'edit own data_access_request content',
    'roles' => array(
      'administrator' => 'administrator',
      'consortium administrator' => 'consortium administrator',
      'researcher' => 'researcher',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own data_access_review content'.
  $permissions['edit own data_access_review content'] = array(
    'name' => 'edit own data_access_review content',
    'roles' => array(
      'administrator' => 'administrator',
      'consortium administrator' => 'consortium administrator',
      'data access committee officer' => 'data access committee officer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'node-specific print configuration'.
  $permissions['node-specific print configuration'] = array(
    'name' => 'node-specific print configuration',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'print',
  );

  // Exported permission: 'view any unpublished data_access_request content'.
  $permissions['view any unpublished data_access_request content'] = array(
    'name' => 'view any unpublished data_access_request content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'view_unpublished',
  );

  // Exported permission: 'view any unpublished data_access_review content'.
  $permissions['view any unpublished data_access_review content'] = array(
    'name' => 'view any unpublished data_access_review content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'view_unpublished',
  );

  return $permissions;
}
