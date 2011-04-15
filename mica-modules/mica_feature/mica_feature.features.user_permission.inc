<?php
/**
 * @file
 * mica_feature.features.user_permission.inc
 */

/**
 * Implementation of hook_user_default_permissions().
 */
function mica_feature_user_default_permissions() {
  $permissions = array();

  // Exported permission: access comments
  $permissions['access comments'] = array(
    'name' => 'access comments',
    'roles' => array(
      0 => 'administrator',
      1 => 'anonymous user',
      2 => 'authenticated user',
    ),
    'module' => 'comment',
  );

  // Exported permission: access content
  $permissions['access content'] = array(
    'name' => 'access content',
    'roles' => array(
      0 => 'administrator',
      1 => 'anonymous user',
      2 => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: create study content
  $permissions['create study content'] = array(
    'name' => 'create study content',
    'roles' => array(
      0 => 'studies administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: create study_information content
  $permissions['create study_information content'] = array(
    'name' => 'create study_information content',
    'roles' => array(
      0 => 'studies administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: delete any study content
  $permissions['delete any study content'] = array(
    'name' => 'delete any study content',
    'roles' => array(
      0 => 'studies administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: delete any study_information content
  $permissions['delete any study_information content'] = array(
    'name' => 'delete any study_information content',
    'roles' => array(
      0 => 'studies administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: delete own study content
  $permissions['delete own study content'] = array(
    'name' => 'delete own study content',
    'roles' => array(
      0 => 'studies administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: delete own study_information content
  $permissions['delete own study_information content'] = array(
    'name' => 'delete own study_information content',
    'roles' => array(
      0 => 'studies administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: delete revisions
  $permissions['delete revisions'] = array(
    'name' => 'delete revisions',
    'roles' => array(
      0 => 'administrator',
      1 => 'studies administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: edit any study content
  $permissions['edit any study content'] = array(
    'name' => 'edit any study content',
    'roles' => array(
      0 => 'studies administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: edit any study_information content
  $permissions['edit any study_information content'] = array(
    'name' => 'edit any study_information content',
    'roles' => array(
      0 => 'studies administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: edit own study content
  $permissions['edit own study content'] = array(
    'name' => 'edit own study content',
    'roles' => array(
      0 => 'studies administrator',
      1 => 'study administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: edit own study_information content
  $permissions['edit own study_information content'] = array(
    'name' => 'edit own study_information content',
    'roles' => array(
      0 => 'studies administrator',
      1 => 'study administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: post comments
  $permissions['post comments'] = array(
    'name' => 'post comments',
    'roles' => array(
      0 => 'administrator',
      1 => 'authenticated user',
    ),
    'module' => 'comment',
  );

  // Exported permission: revert revisions
  $permissions['revert revisions'] = array(
    'name' => 'revert revisions',
    'roles' => array(
      0 => 'administrator',
      1 => 'studies administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: skip comment approval
  $permissions['skip comment approval'] = array(
    'name' => 'skip comment approval',
    'roles' => array(
      0 => 'administrator',
      1 => 'authenticated user',
    ),
    'module' => 'comment',
  );

  // Exported permission: view own unpublished content
  $permissions['view own unpublished content'] = array(
    'name' => 'view own unpublished content',
    'roles' => array(
      0 => 'administrator',
      1 => 'studies administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: view revisions
  $permissions['view revisions'] = array(
    'name' => 'view revisions',
    'roles' => array(
      0 => 'administrator',
      1 => 'studies administrator',
    ),
    'module' => 'node',
  );

  return $permissions;
}
