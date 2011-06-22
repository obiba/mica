<?php
/**
 * @file
 * mica_projects.features.user_permission.inc
 */

/**
 * Implementation of hook_user_default_permissions().
 */
function mica_projects_user_default_permissions() {
  $permissions = array();

  // Exported permission: access content overview
  $permissions['access content overview'] = array(
    'name' => 'access content overview',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: create project content
  $permissions['create project content'] = array(
    'name' => 'create project content',
    'roles' => array(
      0 => 'administrator',
      1 => 'consortium administrator',
      2 => 'study administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: create teleconference content
  $permissions['create teleconference content'] = array(
    'name' => 'create teleconference content',
    'roles' => array(
      0 => 'administrator',
      1 => 'consortium administrator',
      2 => 'study administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: delete any project content
  $permissions['delete any project content'] = array(
    'name' => 'delete any project content',
    'roles' => array(
      0 => 'administrator',
      1 => 'consortium administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: delete any teleconference content
  $permissions['delete any teleconference content'] = array(
    'name' => 'delete any teleconference content',
    'roles' => array(
      0 => 'administrator',
      1 => 'consortium administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: delete own project content
  $permissions['delete own project content'] = array(
    'name' => 'delete own project content',
    'roles' => array(
      0 => 'administrator',
      1 => 'consortium administrator',
      2 => 'study administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: delete own teleconference content
  $permissions['delete own teleconference content'] = array(
    'name' => 'delete own teleconference content',
    'roles' => array(
      0 => 'administrator',
      1 => 'consortium administrator',
      2 => 'study administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: edit any project content
  $permissions['edit any project content'] = array(
    'name' => 'edit any project content',
    'roles' => array(
      0 => 'administrator',
      1 => 'consortium administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: edit any teleconference content
  $permissions['edit any teleconference content'] = array(
    'name' => 'edit any teleconference content',
    'roles' => array(
      0 => 'administrator',
      1 => 'consortium administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: edit own project content
  $permissions['edit own project content'] = array(
    'name' => 'edit own project content',
    'roles' => array(
      0 => 'administrator',
      1 => 'consortium administrator',
      2 => 'study administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: edit own teleconference content
  $permissions['edit own teleconference content'] = array(
    'name' => 'edit own teleconference content',
    'roles' => array(
      0 => 'administrator',
      1 => 'consortium administrator',
      2 => 'study administrator',
    ),
    'module' => 'node',
  );

  return $permissions;
}
