<?php
/**
 * @file
 * mica_studies.features.user_permission.inc
 */

/**
 * Implementation of hook_user_default_permissions().
 */
function mica_studies_user_default_permissions() {
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

  // Exported permission: administer feeds
  $permissions['administer feeds'] = array(
    'name' => 'administer feeds',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'feeds',
  );

  // Exported permission: administer field permissions
  $permissions['administer field permissions'] = array(
    'name' => 'administer field permissions',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: administer page manager
  $permissions['administer page manager'] = array(
    'name' => 'administer page manager',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'page_manager',
  );

  // Exported permission: clear csv_contact_import feeds
  $permissions['clear csv_contact_import feeds'] = array(
    'name' => 'clear csv_contact_import feeds',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'feeds',
  );

  // Exported permission: clear csv_field_description_import feeds
  $permissions['clear csv_field_description_import feeds'] = array(
    'name' => 'clear csv_field_description_import feeds',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'feeds',
  );

  // Exported permission: clear csv_institution_import feeds
  $permissions['clear csv_institution_import feeds'] = array(
    'name' => 'clear csv_institution_import feeds',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'feeds',
  );

  // Exported permission: clear csv_study_documents_importer feeds
  $permissions['clear csv_study_documents_importer feeds'] = array(
    'name' => 'clear csv_study_documents_importer feeds',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'feeds',
  );

  // Exported permission: clear csv_study_import feeds
  $permissions['clear csv_study_import feeds'] = array(
    'name' => 'clear csv_study_import feeds',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'feeds',
  );

  // Exported permission: clear csv_study_information_import feeds
  $permissions['clear csv_study_information_import feeds'] = array(
    'name' => 'clear csv_study_information_import feeds',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'feeds',
  );

  // Exported permission: create article content
  $permissions['create article content'] = array(
    'name' => 'create article content',
    'roles' => array(
      0 => 'administrator',
      1 => 'consortium administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: create contact content
  $permissions['create contact content'] = array(
    'name' => 'create contact content',
    'roles' => array(
      0 => 'administrator',
      1 => 'consortium administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: create documents content
  $permissions['create documents content'] = array(
    'name' => 'create documents content',
    'roles' => array(
      0 => 'consortium administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: create field_description content
  $permissions['create field_description content'] = array(
    'name' => 'create field_description content',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: create institution content
  $permissions['create institution content'] = array(
    'name' => 'create institution content',
    'roles' => array(
      0 => 'administrator',
      1 => 'consortium administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: create mica_study_documents
  $permissions['create mica_study_documents'] = array(
    'name' => 'create mica_study_documents',
    'roles' => array(
      0 => 'administrator',
      1 => 'consortium administrator',
      2 => 'study administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: create mica_study_information
  $permissions['create mica_study_information'] = array(
    'name' => 'create mica_study_information',
    'roles' => array(
      0 => 'administrator',
      1 => 'consortium administrator',
      2 => 'study administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: create page content
  $permissions['create page content'] = array(
    'name' => 'create page content',
    'roles' => array(
      0 => 'administrator',
      1 => 'consortium administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: create panel content
  $permissions['create panel content'] = array(
    'name' => 'create panel content',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: create study content
  $permissions['create study content'] = array(
    'name' => 'create study content',
    'roles' => array(
      0 => 'administrator',
      1 => 'consortium administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: create study_documents content
  $permissions['create study_documents content'] = array(
    'name' => 'create study_documents content',
    'roles' => array(
      0 => 'administrator',
      1 => 'consortium administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: create study_information content
  $permissions['create study_information content'] = array(
    'name' => 'create study_information content',
    'roles' => array(
      0 => 'administrator',
      1 => 'consortium administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: delete any article content
  $permissions['delete any article content'] = array(
    'name' => 'delete any article content',
    'roles' => array(
      0 => 'administrator',
      1 => 'consortium administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: delete any contact content
  $permissions['delete any contact content'] = array(
    'name' => 'delete any contact content',
    'roles' => array(
      0 => 'administrator',
      1 => 'consortium administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: delete any documents content
  $permissions['delete any documents content'] = array(
    'name' => 'delete any documents content',
    'roles' => array(
      0 => 'consortium administrator',
      1 => 'consortium administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: delete any field_description content
  $permissions['delete any field_description content'] = array(
    'name' => 'delete any field_description content',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: delete any institution content
  $permissions['delete any institution content'] = array(
    'name' => 'delete any institution content',
    'roles' => array(
      0 => 'administrator',
      1 => 'consortium administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: delete any page content
  $permissions['delete any page content'] = array(
    'name' => 'delete any page content',
    'roles' => array(
      0 => 'administrator',
      1 => 'consortium administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: delete any panel content
  $permissions['delete any panel content'] = array(
    'name' => 'delete any panel content',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: delete any study content
  $permissions['delete any study content'] = array(
    'name' => 'delete any study content',
    'roles' => array(
      0 => 'administrator',
      1 => 'consortium administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: delete any study_documents content
  $permissions['delete any study_documents content'] = array(
    'name' => 'delete any study_documents content',
    'roles' => array(
      0 => 'administrator',
      1 => 'consortium administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: delete any study_information content
  $permissions['delete any study_information content'] = array(
    'name' => 'delete any study_information content',
    'roles' => array(
      0 => 'administrator',
      1 => 'consortium administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: delete own article content
  $permissions['delete own article content'] = array(
    'name' => 'delete own article content',
    'roles' => array(
      0 => 'administrator',
      1 => 'consortium administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: delete own contact content
  $permissions['delete own contact content'] = array(
    'name' => 'delete own contact content',
    'roles' => array(
      0 => 'administrator',
      1 => 'consortium administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: delete own documents content
  $permissions['delete own documents content'] = array(
    'name' => 'delete own documents content',
    'roles' => array(
      0 => 'administrator',
      1 => 'consortium administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: delete own field_description content
  $permissions['delete own field_description content'] = array(
    'name' => 'delete own field_description content',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: delete own institution content
  $permissions['delete own institution content'] = array(
    'name' => 'delete own institution content',
    'roles' => array(
      0 => 'administrator',
      1 => 'consortium administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: delete own page content
  $permissions['delete own page content'] = array(
    'name' => 'delete own page content',
    'roles' => array(
      0 => 'administrator',
      1 => 'consortium administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: delete own panel content
  $permissions['delete own panel content'] = array(
    'name' => 'delete own panel content',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: delete own study content
  $permissions['delete own study content'] = array(
    'name' => 'delete own study content',
    'roles' => array(
      0 => 'administrator',
      1 => 'consortium administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: delete own study_documents content
  $permissions['delete own study_documents content'] = array(
    'name' => 'delete own study_documents content',
    'roles' => array(
      0 => 'administrator',
      1 => 'consortium administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: delete own study_information content
  $permissions['delete own study_information content'] = array(
    'name' => 'delete own study_information content',
    'roles' => array(
      0 => 'administrator',
      1 => 'consortium administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: delete revisions
  $permissions['delete revisions'] = array(
    'name' => 'delete revisions',
    'roles' => array(
      0 => 'administrator',
      1 => 'consortium administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: edit any article content
  $permissions['edit any article content'] = array(
    'name' => 'edit any article content',
    'roles' => array(
      0 => 'administrator',
      1 => 'consortium administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: edit any contact content
  $permissions['edit any contact content'] = array(
    'name' => 'edit any contact content',
    'roles' => array(
      0 => 'administrator',
      1 => 'consortium administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: edit any documents content
  $permissions['edit any documents content'] = array(
    'name' => 'edit any documents content',
    'roles' => array(
      0 => 'administrator',
      1 => 'consortium administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: edit any field_description content
  $permissions['edit any field_description content'] = array(
    'name' => 'edit any field_description content',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: edit any institution content
  $permissions['edit any institution content'] = array(
    'name' => 'edit any institution content',
    'roles' => array(
      0 => 'administrator',
      1 => 'consortium administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: edit any page content
  $permissions['edit any page content'] = array(
    'name' => 'edit any page content',
    'roles' => array(
      0 => 'administrator',
      1 => 'consortium administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: edit any panel content
  $permissions['edit any panel content'] = array(
    'name' => 'edit any panel content',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: edit any study content
  $permissions['edit any study content'] = array(
    'name' => 'edit any study content',
    'roles' => array(
      0 => 'administrator',
      1 => 'consortium administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: edit any study_documents content
  $permissions['edit any study_documents content'] = array(
    'name' => 'edit any study_documents content',
    'roles' => array(
      0 => 'administrator',
      1 => 'consortium administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: edit any study_information content
  $permissions['edit any study_information content'] = array(
    'name' => 'edit any study_information content',
    'roles' => array(
      0 => 'administrator',
      1 => 'consortium administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: edit own article content
  $permissions['edit own article content'] = array(
    'name' => 'edit own article content',
    'roles' => array(
      0 => 'administrator',
      1 => 'consortium administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: edit own contact content
  $permissions['edit own contact content'] = array(
    'name' => 'edit own contact content',
    'roles' => array(
      0 => 'administrator',
      1 => 'consortium administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: edit own documents content
  $permissions['edit own documents content'] = array(
    'name' => 'edit own documents content',
    'roles' => array(
      0 => 'administrator',
      1 => 'consortium administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: edit own field_description content
  $permissions['edit own field_description content'] = array(
    'name' => 'edit own field_description content',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: edit own institution content
  $permissions['edit own institution content'] = array(
    'name' => 'edit own institution content',
    'roles' => array(
      0 => 'administrator',
      1 => 'consortium administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: edit own page content
  $permissions['edit own page content'] = array(
    'name' => 'edit own page content',
    'roles' => array(
      0 => 'administrator',
      1 => 'consortium administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: edit own panel content
  $permissions['edit own panel content'] = array(
    'name' => 'edit own panel content',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: edit own study content
  $permissions['edit own study content'] = array(
    'name' => 'edit own study content',
    'roles' => array(
      0 => 'consortium administrator',
      1 => 'study administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: edit own study_documents content
  $permissions['edit own study_documents content'] = array(
    'name' => 'edit own study_documents content',
    'roles' => array(
      0 => 'administrator',
      1 => 'consortium administrator',
      2 => 'study administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: edit own study_information content
  $permissions['edit own study_information content'] = array(
    'name' => 'edit own study_information content',
    'roles' => array(
      0 => 'administrator',
      1 => 'consortium administrator',
      2 => 'study administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: import csv_contact_import feeds
  $permissions['import csv_contact_import feeds'] = array(
    'name' => 'import csv_contact_import feeds',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'feeds',
  );

  // Exported permission: import csv_field_description_import feeds
  $permissions['import csv_field_description_import feeds'] = array(
    'name' => 'import csv_field_description_import feeds',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'feeds',
  );

  // Exported permission: import csv_institution_import feeds
  $permissions['import csv_institution_import feeds'] = array(
    'name' => 'import csv_institution_import feeds',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'feeds',
  );

  // Exported permission: import csv_study_documents_importer feeds
  $permissions['import csv_study_documents_importer feeds'] = array(
    'name' => 'import csv_study_documents_importer feeds',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'feeds',
  );

  // Exported permission: import csv_study_import feeds
  $permissions['import csv_study_import feeds'] = array(
    'name' => 'import csv_study_import feeds',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'feeds',
  );

  // Exported permission: import csv_study_information_import feeds
  $permissions['import csv_study_information_import feeds'] = array(
    'name' => 'import csv_study_information_import feeds',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'feeds',
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
      1 => 'consortium administrator',
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

  // Exported permission: use page manager
  $permissions['use page manager'] = array(
    'name' => 'use page manager',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'page_manager',
  );

  // Exported permission: use search_api_facets
  $permissions['use search_api_facets'] = array(
    'name' => 'use search_api_facets',
    'roles' => array(
      0 => 'administrator',
      1 => 'authenticated user',
      2 => 'anonymous user',
    ),
    'module' => 'search_api_facets',
  );

  // Exported permission: use search_api_ranges
  $permissions['use search_api_ranges'] = array(
    'name' => 'use search_api_ranges',
    'roles' => array(
      0 => 'administrator',
      1 => 'authenticated user',
      2 => 'anonymous user',
    ),
    'module' => 'search_api_ranges',
  );

  // Exported permission: view mica_study_documents
  $permissions['view mica_study_documents'] = array(
    'name' => 'view mica_study_documents',
    'roles' => array(
      0 => 'anonymous user',
      1 => 'authenticated user',
    ),
    'module' => 'field_permissions',
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
      1 => 'consortium administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: view revisions
  $permissions['view revisions'] = array(
    'name' => 'view revisions',
    'roles' => array(
      0 => 'administrator',
      1 => 'consortium administrator',
    ),
    'module' => 'node',
  );

  return $permissions;
}
