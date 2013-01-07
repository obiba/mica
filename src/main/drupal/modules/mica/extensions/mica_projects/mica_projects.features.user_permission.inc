<?php
/**
 * @file
 * mica_projects.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function mica_projects_user_default_permissions() {
  $permissions = array();

  // Exported permission: access content overview.
  $permissions['access content overview'] = array(
    'name' => 'access content overview',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: clear csv_project_import feeds.
  $permissions['clear csv_project_import feeds'] = array(
    'name' => 'clear csv_project_import feeds',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'feeds',
  );

  // Exported permission: clear csv_teleconference_import feeds.
  $permissions['clear csv_teleconference_import feeds'] = array(
    'name' => 'clear csv_teleconference_import feeds',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'feeds',
  );

  // Exported permission: create project content.
  $permissions['create project content'] = array(
    'name' => 'create project content',
    'roles' => array(
      'administrator' => 'administrator',
      'consortium administrator' => 'consortium administrator',
      'study administrator' => 'study administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: create teleconference content.
  $permissions['create teleconference content'] = array(
    'name' => 'create teleconference content',
    'roles' => array(
      'administrator' => 'administrator',
      'consortium administrator' => 'consortium administrator',
      'study administrator' => 'study administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: delete any project content.
  $permissions['delete any project content'] = array(
    'name' => 'delete any project content',
    'roles' => array(
      'administrator' => 'administrator',
      'consortium administrator' => 'consortium administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: delete any teleconference content.
  $permissions['delete any teleconference content'] = array(
    'name' => 'delete any teleconference content',
    'roles' => array(
      'administrator' => 'administrator',
      'consortium administrator' => 'consortium administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: delete own project content.
  $permissions['delete own project content'] = array(
    'name' => 'delete own project content',
    'roles' => array(
      'administrator' => 'administrator',
      'consortium administrator' => 'consortium administrator',
      'study administrator' => 'study administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: delete own teleconference content.
  $permissions['delete own teleconference content'] = array(
    'name' => 'delete own teleconference content',
    'roles' => array(
      'administrator' => 'administrator',
      'consortium administrator' => 'consortium administrator',
      'study administrator' => 'study administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: edit any project content.
  $permissions['edit any project content'] = array(
    'name' => 'edit any project content',
    'roles' => array(
      'administrator' => 'administrator',
      'consortium administrator' => 'consortium administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: edit any teleconference content.
  $permissions['edit any teleconference content'] = array(
    'name' => 'edit any teleconference content',
    'roles' => array(
      'administrator' => 'administrator',
      'consortium administrator' => 'consortium administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: edit own project content.
  $permissions['edit own project content'] = array(
    'name' => 'edit own project content',
    'roles' => array(
      'administrator' => 'administrator',
      'consortium administrator' => 'consortium administrator',
      'study administrator' => 'study administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: edit own teleconference content.
  $permissions['edit own teleconference content'] = array(
    'name' => 'edit own teleconference content',
    'roles' => array(
      'administrator' => 'administrator',
      'consortium administrator' => 'consortium administrator',
      'study administrator' => 'study administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: import csv_project_import feeds.
  $permissions['import csv_project_import feeds'] = array(
    'name' => 'import csv_project_import feeds',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'feeds',
  );

  // Exported permission: import csv_teleconference_import feeds.
  $permissions['import csv_teleconference_import feeds'] = array(
    'name' => 'import csv_teleconference_import feeds',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'feeds',
  );

  // Exported permission: tamper csv_project_import.
  $permissions['tamper csv_project_import'] = array(
    'name' => 'tamper csv_project_import',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'feeds_tamper',
  );

  // Exported permission: tamper csv_teleconference_import.
  $permissions['tamper csv_teleconference_import'] = array(
    'name' => 'tamper csv_teleconference_import',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'feeds_tamper',
  );

  // Exported permission: view any unpublished project content.
  $permissions['view any unpublished project content'] = array(
    'name' => 'view any unpublished project content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'view_unpublished',
  );

  // Exported permission: view any unpublished teleconference content.
  $permissions['view any unpublished teleconference content'] = array(
    'name' => 'view any unpublished teleconference content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'view_unpublished',
  );

  return $permissions;
}
