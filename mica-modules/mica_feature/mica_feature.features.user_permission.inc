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

  // Exported permission: administer field permissions
  $permissions['administer field permissions'] = array(
    'name' => 'administer field permissions',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: create article content
  $permissions['create article content'] = array(
    'name' => 'create article content',
    'roles' => array(
      0 => 'administrator',
      1 => 'studies administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: create mica_study_information
  $permissions['create mica_study_information'] = array(
    'name' => 'create mica_study_information',
    'roles' => array(
      0 => 'administrator',
      1 => 'studies administrator',
      2 => 'study administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: create page content
  $permissions['create page content'] = array(
    'name' => 'create page content',
    'roles' => array(
      0 => 'administrator',
      1 => 'studies administrator',
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

  // Exported permission: delete any article content
  $permissions['delete any article content'] = array(
    'name' => 'delete any article content',
    'roles' => array(
      0 => 'administrator',
      1 => 'studies administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: delete any page content
  $permissions['delete any page content'] = array(
    'name' => 'delete any page content',
    'roles' => array(
      0 => 'administrator',
      1 => 'studies administrator',
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

  // Exported permission: delete own article content
  $permissions['delete own article content'] = array(
    'name' => 'delete own article content',
    'roles' => array(
      0 => 'administrator',
      1 => 'studies administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: delete own page content
  $permissions['delete own page content'] = array(
    'name' => 'delete own page content',
    'roles' => array(
      0 => 'administrator',
      1 => 'studies administrator',
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
      2 => 'study administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: edit any article content
  $permissions['edit any article content'] = array(
    'name' => 'edit any article content',
    'roles' => array(
      0 => 'administrator',
      1 => 'studies administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: edit any page content
  $permissions['edit any page content'] = array(
    'name' => 'edit any page content',
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

  // Exported permission: edit own article content
  $permissions['edit own article content'] = array(
    'name' => 'edit own article content',
    'roles' => array(
      0 => 'administrator',
      1 => 'studies administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: edit own page content
  $permissions['edit own page content'] = array(
    'name' => 'edit own page content',
    'roles' => array(
      0 => 'administrator',
      1 => 'studies administrator',
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

  // Exported permission: use search_api_facets
  $permissions['use search_api_facets'] = array(
    'name' => 'use search_api_facets',
    'roles' => array(
      0 => 'administrator',
      1 => 'studies administrator',
      2 => 'study administrator',
    ),
    'module' => 'search_api_facets',
  );

  // Exported permission: view mica_study_information
  $permissions['view mica_study_information'] = array(
    'name' => 'view mica_study_information',
    'roles' => array(
      0 => 'anonymous user',
      1 => 'authenticated user',
    ),
    'module' => 'field_permissions',
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
