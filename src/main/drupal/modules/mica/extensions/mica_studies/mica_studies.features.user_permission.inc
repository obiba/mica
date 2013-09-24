<?php
/**
 * @file
 * mica_studies.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function mica_studies_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'access comments'.
  $permissions['access comments'] = array(
    'name' => 'access comments',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'comment',
  );

  // Exported permission: 'access content'.
  $permissions['access content'] = array(
    'name' => 'access content',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: 'access private fields'.
  $permissions['access private fields'] = array(
    'name' => 'access private fields',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'access search_api_page'.
  $permissions['access search_api_page'] = array(
    'name' => 'access search_api_page',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'search_api_page',
  );

  // Exported permission: 'access toolbar'.
  $permissions['access toolbar'] = array(
    'name' => 'access toolbar',
    'roles' => array(
      'administrator' => 'administrator',
      'consortium administrator' => 'consortium administrator',
      'dataset administrator' => 'dataset administrator',
      'dataset reviewer' => 'dataset reviewer',
      'study administrator' => 'study administrator',
      'study reviewer' => 'study reviewer',
    ),
    'module' => 'toolbar',
  );

  // Exported permission: 'access workbench'.
  $permissions['access workbench'] = array(
    'name' => 'access workbench',
    'roles' => array(
      'administrator' => 'administrator',
      'consortium administrator' => 'consortium administrator',
      'dataset administrator' => 'dataset administrator',
      'dataset reviewer' => 'dataset reviewer',
      'study administrator' => 'study administrator',
      'study reviewer' => 'study reviewer',
    ),
    'module' => 'workbench',
  );

  // Exported permission: 'administer content types'.
  $permissions['administer content types'] = array(
    'name' => 'administer content types',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'administer field permissions'.
  $permissions['administer field permissions'] = array(
    'name' => 'administer field permissions',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'administer module filter'.
  $permissions['administer module filter'] = array(
    'name' => 'administer module filter',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'module_filter',
  );

  // Exported permission: 'administer nodes'.
  $permissions['administer nodes'] = array(
    'name' => 'administer nodes',
    'roles' => array(
      'administrator' => 'administrator',
      'consortium administrator' => 'consortium administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'administer page manager'.
  $permissions['administer page manager'] = array(
    'name' => 'administer page manager',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'page_manager',
  );

  // Exported permission: 'administer search'.
  $permissions['administer search'] = array(
    'name' => 'administer search',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'search',
  );

  // Exported permission: 'administer search_api'.
  $permissions['administer search_api'] = array(
    'name' => 'administer search_api',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'search_api',
  );

  // Exported permission: 'administer workbench'.
  $permissions['administer workbench'] = array(
    'name' => 'administer workbench',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'workbench',
  );

  // Exported permission: 'administer workbench moderation'.
  $permissions['administer workbench moderation'] = array(
    'name' => 'administer workbench moderation',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'workbench_moderation',
  );

  // Exported permission: 'bypass node access'.
  $permissions['bypass node access'] = array(
    'name' => 'bypass node access',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'bypass workbench moderation'.
  $permissions['bypass workbench moderation'] = array(
    'name' => 'bypass workbench moderation',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'workbench_moderation',
  );

  // Exported permission: 'create article content'.
  $permissions['create article content'] = array(
    'name' => 'create article content',
    'roles' => array(
      'administrator' => 'administrator',
      'consortium administrator' => 'consortium administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create contact content'.
  $permissions['create contact content'] = array(
    'name' => 'create contact content',
    'roles' => array(
      'administrator' => 'administrator',
      'consortium administrator' => 'consortium administrator',
      'network administrator' => 'network administrator',
      'network reviewer' => 'network reviewer',
      'study administrator' => 'study administrator',
      'study reviewer' => 'study reviewer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create data_collection_event content'.
  $permissions['create data_collection_event content'] = array(
    'name' => 'create data_collection_event content',
    'roles' => array(
      'administrator' => 'administrator',
      'consortium administrator' => 'consortium administrator',
      'study administrator' => 'study administrator',
      'study reviewer' => 'study reviewer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create documents content'.
  $permissions['create documents content'] = array(
    'name' => 'create documents content',
    'roles' => array(
      'administrator' => 'administrator',
      'consortium administrator' => 'consortium administrator',
      'study administrator' => 'study administrator',
      'study reviewer' => 'study reviewer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create field_authorising_date'.
  $permissions['create field_authorising_date'] = array(
    'name' => 'create field_authorising_date',
    'roles' => array(
      'administrator' => 'administrator',
      'consortium administrator' => 'consortium administrator',
      'study administrator' => 'study administrator',
      'study reviewer' => 'study reviewer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_authorising_date_m'.
  $permissions['create field_authorising_date_m'] = array(
    'name' => 'create field_authorising_date_m',
    'roles' => array(
      'administrator' => 'administrator',
      'consortium administrator' => 'consortium administrator',
      'study administrator' => 'study administrator',
      'study reviewer' => 'study reviewer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_authorising_person_name'.
  $permissions['create field_authorising_person_name'] = array(
    'name' => 'create field_authorising_person_name',
    'roles' => array(
      'administrator' => 'administrator',
      'consortium administrator' => 'consortium administrator',
      'study administrator' => 'study administrator',
      'study reviewer' => 'study reviewer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_authorising_person_name_m'.
  $permissions['create field_authorising_person_name_m'] = array(
    'name' => 'create field_authorising_person_name_m',
    'roles' => array(
      'administrator' => 'administrator',
      'consortium administrator' => 'consortium administrator',
      'study administrator' => 'study administrator',
      'study reviewer' => 'study reviewer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_authorization_maelstrom'.
  $permissions['create field_authorization_maelstrom'] = array(
    'name' => 'create field_authorization_maelstrom',
    'roles' => array(
      'administrator' => 'administrator',
      'consortium administrator' => 'consortium administrator',
      'study administrator' => 'study administrator',
      'study reviewer' => 'study reviewer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_authorization_specific'.
  $permissions['create field_authorization_specific'] = array(
    'name' => 'create field_authorization_specific',
    'roles' => array(
      'administrator' => 'administrator',
      'consortium administrator' => 'consortium administrator',
      'study administrator' => 'study administrator',
      'study reviewer' => 'study reviewer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create page content'.
  $permissions['create page content'] = array(
    'name' => 'create page content',
    'roles' => array(
      'administrator' => 'administrator',
      'consortium administrator' => 'consortium administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create panel content'.
  $permissions['create panel content'] = array(
    'name' => 'create panel content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create population content'.
  $permissions['create population content'] = array(
    'name' => 'create population content',
    'roles' => array(
      'administrator' => 'administrator',
      'consortium administrator' => 'consortium administrator',
      'study administrator' => 'study administrator',
      'study reviewer' => 'study reviewer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create study content'.
  $permissions['create study content'] = array(
    'name' => 'create study content',
    'roles' => array(
      'administrator' => 'administrator',
      'consortium administrator' => 'consortium administrator',
      'study administrator' => 'study administrator',
      'study reviewer' => 'study reviewer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any article content'.
  $permissions['delete any article content'] = array(
    'name' => 'delete any article content',
    'roles' => array(
      'administrator' => 'administrator',
      'consortium administrator' => 'consortium administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any contact content'.
  $permissions['delete any contact content'] = array(
    'name' => 'delete any contact content',
    'roles' => array(
      'administrator' => 'administrator',
      'consortium administrator' => 'consortium administrator',
      'network reviewer' => 'network reviewer',
      'study reviewer' => 'study reviewer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any data_collection_event content'.
  $permissions['delete any data_collection_event content'] = array(
    'name' => 'delete any data_collection_event content',
    'roles' => array(
      'administrator' => 'administrator',
      'consortium administrator' => 'consortium administrator',
      'study reviewer' => 'study reviewer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any documents content'.
  $permissions['delete any documents content'] = array(
    'name' => 'delete any documents content',
    'roles' => array(
      'administrator' => 'administrator',
      'consortium administrator' => 'consortium administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any page content'.
  $permissions['delete any page content'] = array(
    'name' => 'delete any page content',
    'roles' => array(
      'administrator' => 'administrator',
      'consortium administrator' => 'consortium administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any panel content'.
  $permissions['delete any panel content'] = array(
    'name' => 'delete any panel content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any population content'.
  $permissions['delete any population content'] = array(
    'name' => 'delete any population content',
    'roles' => array(
      'administrator' => 'administrator',
      'consortium administrator' => 'consortium administrator',
      'study reviewer' => 'study reviewer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any study content'.
  $permissions['delete any study content'] = array(
    'name' => 'delete any study content',
    'roles' => array(
      'administrator' => 'administrator',
      'consortium administrator' => 'consortium administrator',
      'study reviewer' => 'study reviewer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own article content'.
  $permissions['delete own article content'] = array(
    'name' => 'delete own article content',
    'roles' => array(
      'administrator' => 'administrator',
      'consortium administrator' => 'consortium administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own contact content'.
  $permissions['delete own contact content'] = array(
    'name' => 'delete own contact content',
    'roles' => array(
      'administrator' => 'administrator',
      'consortium administrator' => 'consortium administrator',
      'network administrator' => 'network administrator',
      'network reviewer' => 'network reviewer',
      'study administrator' => 'study administrator',
      'study reviewer' => 'study reviewer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own data_collection_event content'.
  $permissions['delete own data_collection_event content'] = array(
    'name' => 'delete own data_collection_event content',
    'roles' => array(
      'administrator' => 'administrator',
      'consortium administrator' => 'consortium administrator',
      'study administrator' => 'study administrator',
      'study reviewer' => 'study reviewer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own documents content'.
  $permissions['delete own documents content'] = array(
    'name' => 'delete own documents content',
    'roles' => array(
      'administrator' => 'administrator',
      'consortium administrator' => 'consortium administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own page content'.
  $permissions['delete own page content'] = array(
    'name' => 'delete own page content',
    'roles' => array(
      'administrator' => 'administrator',
      'consortium administrator' => 'consortium administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own panel content'.
  $permissions['delete own panel content'] = array(
    'name' => 'delete own panel content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own population content'.
  $permissions['delete own population content'] = array(
    'name' => 'delete own population content',
    'roles' => array(
      'administrator' => 'administrator',
      'consortium administrator' => 'consortium administrator',
      'study administrator' => 'study administrator',
      'study reviewer' => 'study reviewer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own study content'.
  $permissions['delete own study content'] = array(
    'name' => 'delete own study content',
    'roles' => array(
      'administrator' => 'administrator',
      'consortium administrator' => 'consortium administrator',
      'study administrator' => 'study administrator',
      'study reviewer' => 'study reviewer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete revisions'.
  $permissions['delete revisions'] = array(
    'name' => 'delete revisions',
    'roles' => array(
      'administrator' => 'administrator',
      'consortium administrator' => 'consortium administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any article content'.
  $permissions['edit any article content'] = array(
    'name' => 'edit any article content',
    'roles' => array(
      'administrator' => 'administrator',
      'consortium administrator' => 'consortium administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any contact content'.
  $permissions['edit any contact content'] = array(
    'name' => 'edit any contact content',
    'roles' => array(
      'administrator' => 'administrator',
      'consortium administrator' => 'consortium administrator',
      'study administrator' => 'study administrator',
      'network administrator' => 'network administrator',
      'network reviewer' => 'network reviewer',
      'study reviewer' => 'study reviewer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any data_collection_event content'.
  $permissions['edit any data_collection_event content'] = array(
    'name' => 'edit any data_collection_event content',
    'roles' => array(
      'administrator' => 'administrator',
      'consortium administrator' => 'consortium administrator',
      'study administrator' => 'study administrator',
      'study reviewer' => 'study reviewer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any documents content'.
  $permissions['edit any documents content'] = array(
    'name' => 'edit any documents content',
    'roles' => array(
      'administrator' => 'administrator',
      'consortium administrator' => 'consortium administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any page content'.
  $permissions['edit any page content'] = array(
    'name' => 'edit any page content',
    'roles' => array(
      'administrator' => 'administrator',
      'consortium administrator' => 'consortium administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any panel content'.
  $permissions['edit any panel content'] = array(
    'name' => 'edit any panel content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any population content'.
  $permissions['edit any population content'] = array(
    'name' => 'edit any population content',
    'roles' => array(
      'administrator' => 'administrator',
      'consortium administrator' => 'consortium administrator',
      'study administrator' => 'study administrator',
      'study reviewer' => 'study reviewer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any study content'.
  $permissions['edit any study content'] = array(
    'name' => 'edit any study content',
    'roles' => array(
      'administrator' => 'administrator',
      'consortium administrator' => 'consortium administrator',
      'study administrator' => 'study administrator',
      'study reviewer' => 'study reviewer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit field_authorising_date'.
  $permissions['edit field_authorising_date'] = array(
    'name' => 'edit field_authorising_date',
    'roles' => array(
      'administrator' => 'administrator',
      'consortium administrator' => 'consortium administrator',
      'study reviewer' => 'study reviewer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_authorising_date_m'.
  $permissions['edit field_authorising_date_m'] = array(
    'name' => 'edit field_authorising_date_m',
    'roles' => array(
      'administrator' => 'administrator',
      'consortium administrator' => 'consortium administrator',
      'study reviewer' => 'study reviewer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_authorising_person_name'.
  $permissions['edit field_authorising_person_name'] = array(
    'name' => 'edit field_authorising_person_name',
    'roles' => array(
      'administrator' => 'administrator',
      'consortium administrator' => 'consortium administrator',
      'study reviewer' => 'study reviewer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_authorising_person_name_m'.
  $permissions['edit field_authorising_person_name_m'] = array(
    'name' => 'edit field_authorising_person_name_m',
    'roles' => array(
      'administrator' => 'administrator',
      'consortium administrator' => 'consortium administrator',
      'study reviewer' => 'study reviewer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_authorization_maelstrom'.
  $permissions['edit field_authorization_maelstrom'] = array(
    'name' => 'edit field_authorization_maelstrom',
    'roles' => array(
      'administrator' => 'administrator',
      'consortium administrator' => 'consortium administrator',
      'study reviewer' => 'study reviewer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_authorization_specific'.
  $permissions['edit field_authorization_specific'] = array(
    'name' => 'edit field_authorization_specific',
    'roles' => array(
      'administrator' => 'administrator',
      'consortium administrator' => 'consortium administrator',
      'study reviewer' => 'study reviewer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own article content'.
  $permissions['edit own article content'] = array(
    'name' => 'edit own article content',
    'roles' => array(
      'administrator' => 'administrator',
      'consortium administrator' => 'consortium administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own contact content'.
  $permissions['edit own contact content'] = array(
    'name' => 'edit own contact content',
    'roles' => array(
      'administrator' => 'administrator',
      'consortium administrator' => 'consortium administrator',
      'network administrator' => 'network administrator',
      'network reviewer' => 'network reviewer',
      'study administrator' => 'study administrator',
      'study reviewer' => 'study reviewer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own data_collection_event content'.
  $permissions['edit own data_collection_event content'] = array(
    'name' => 'edit own data_collection_event content',
    'roles' => array(
      'administrator' => 'administrator',
      'consortium administrator' => 'consortium administrator',
      'study administrator' => 'study administrator',
      'study reviewer' => 'study reviewer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own documents content'.
  $permissions['edit own documents content'] = array(
    'name' => 'edit own documents content',
    'roles' => array(
      'administrator' => 'administrator',
      'consortium administrator' => 'consortium administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own field_authorising_date'.
  $permissions['edit own field_authorising_date'] = array(
    'name' => 'edit own field_authorising_date',
    'roles' => array(
      'administrator' => 'administrator',
      'consortium administrator' => 'consortium administrator',
      'study administrator' => 'study administrator',
      'study reviewer' => 'study reviewer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_authorising_date_m'.
  $permissions['edit own field_authorising_date_m'] = array(
    'name' => 'edit own field_authorising_date_m',
    'roles' => array(
      'administrator' => 'administrator',
      'consortium administrator' => 'consortium administrator',
      'study administrator' => 'study administrator',
      'study reviewer' => 'study reviewer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_authorising_person_name'.
  $permissions['edit own field_authorising_person_name'] = array(
    'name' => 'edit own field_authorising_person_name',
    'roles' => array(
      'administrator' => 'administrator',
      'consortium administrator' => 'consortium administrator',
      'study administrator' => 'study administrator',
      'study reviewer' => 'study reviewer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_authorising_person_name_m'.
  $permissions['edit own field_authorising_person_name_m'] = array(
    'name' => 'edit own field_authorising_person_name_m',
    'roles' => array(
      'administrator' => 'administrator',
      'consortium administrator' => 'consortium administrator',
      'study administrator' => 'study administrator',
      'study reviewer' => 'study reviewer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_authorization_maelstrom'.
  $permissions['edit own field_authorization_maelstrom'] = array(
    'name' => 'edit own field_authorization_maelstrom',
    'roles' => array(
      'administrator' => 'administrator',
      'consortium administrator' => 'consortium administrator',
      'study administrator' => 'study administrator',
      'study reviewer' => 'study reviewer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_authorization_specific'.
  $permissions['edit own field_authorization_specific'] = array(
    'name' => 'edit own field_authorization_specific',
    'roles' => array(
      'administrator' => 'administrator',
      'consortium administrator' => 'consortium administrator',
      'study administrator' => 'study administrator',
      'study reviewer' => 'study reviewer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own page content'.
  $permissions['edit own page content'] = array(
    'name' => 'edit own page content',
    'roles' => array(
      'administrator' => 'administrator',
      'consortium administrator' => 'consortium administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own panel content'.
  $permissions['edit own panel content'] = array(
    'name' => 'edit own panel content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own population content'.
  $permissions['edit own population content'] = array(
    'name' => 'edit own population content',
    'roles' => array(
      'administrator' => 'administrator',
      'consortium administrator' => 'consortium administrator',
      'study administrator' => 'study administrator',
      'study reviewer' => 'study reviewer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own study content'.
  $permissions['edit own study content'] = array(
    'name' => 'edit own study content',
    'roles' => array(
      'administrator' => 'administrator',
      'consortium administrator' => 'consortium administrator',
      'study administrator' => 'study administrator',
      'study reviewer' => 'study reviewer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'export data'.
  $permissions['export data'] = array(
    'name' => 'export data',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'mica_studies',
  );

  // Exported permission: 'moderate content from draft to needs_review'.
  $permissions['moderate content from draft to needs_review'] = array(
    'name' => 'moderate content from draft to needs_review',
    'roles' => array(
      'administrator' => 'administrator',
      'consortium administrator' => 'consortium administrator',
      'dataset administrator' => 'dataset administrator',
      'dataset reviewer' => 'dataset reviewer',
      'study administrator' => 'study administrator',
      'study reviewer' => 'study reviewer',
    ),
    'module' => 'workbench_moderation',
  );

  // Exported permission: 'moderate content from needs_review to draft'.
  $permissions['moderate content from needs_review to draft'] = array(
    'name' => 'moderate content from needs_review to draft',
    'roles' => array(
      'administrator' => 'administrator',
      'consortium administrator' => 'consortium administrator',
      'dataset administrator' => 'dataset administrator',
      'dataset reviewer' => 'dataset reviewer',
      'study administrator' => 'study administrator',
      'study reviewer' => 'study reviewer',
    ),
    'module' => 'workbench_moderation',
  );

  // Exported permission: 'moderate content from needs_review to published'.
  $permissions['moderate content from needs_review to published'] = array(
    'name' => 'moderate content from needs_review to published',
    'roles' => array(
      'administrator' => 'administrator',
      'consortium administrator' => 'consortium administrator',
      'dataset administrator' => 'dataset administrator',
      'dataset reviewer' => 'dataset reviewer',
      'study administrator' => 'study administrator',
      'study reviewer' => 'study reviewer',
    ),
    'module' => 'workbench_moderation',
  );

  // Exported permission: 'post comments'.
  $permissions['post comments'] = array(
    'name' => 'post comments',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'comment',
  );

  // Exported permission: 'revert revisions'.
  $permissions['revert revisions'] = array(
    'name' => 'revert revisions',
    'roles' => array(
      'administrator' => 'administrator',
      'consortium administrator' => 'consortium administrator',
      'dataset reviewer' => 'dataset reviewer',
      'study reviewer' => 'study reviewer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'search content'.
  $permissions['search content'] = array(
    'name' => 'search content',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'search',
  );

  // Exported permission: 'skip comment approval'.
  $permissions['skip comment approval'] = array(
    'name' => 'skip comment approval',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'comment',
  );

  // Exported permission: 'use advanced search'.
  $permissions['use advanced search'] = array(
    'name' => 'use advanced search',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'search',
  );

  // Exported permission: 'use page manager'.
  $permissions['use page manager'] = array(
    'name' => 'use page manager',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'page_manager',
  );

  // Exported permission: 'use workbench_moderation my drafts tab'.
  $permissions['use workbench_moderation my drafts tab'] = array(
    'name' => 'use workbench_moderation my drafts tab',
    'roles' => array(
      'administrator' => 'administrator',
      'consortium administrator' => 'consortium administrator',
      'dataset administrator' => 'dataset administrator',
      'dataset reviewer' => 'dataset reviewer',
      'study administrator' => 'study administrator',
      'study reviewer' => 'study reviewer',
    ),
    'module' => 'workbench_moderation',
  );

  // Exported permission: 'use workbench_moderation needs review tab'.
  $permissions['use workbench_moderation needs review tab'] = array(
    'name' => 'use workbench_moderation needs review tab',
    'roles' => array(
      'administrator' => 'administrator',
      'consortium administrator' => 'consortium administrator',
      'dataset administrator' => 'dataset administrator',
      'dataset reviewer' => 'dataset reviewer',
      'study administrator' => 'study administrator',
      'study reviewer' => 'study reviewer',
    ),
    'module' => 'workbench_moderation',
  );

  // Exported permission: 'view all unpublished content'.
  $permissions['view all unpublished content'] = array(
    'name' => 'view all unpublished content',
    'roles' => array(
      'administrator' => 'administrator',
      'consortium administrator' => 'consortium administrator',
      'dataset administrator' => 'dataset administrator',
      'dataset reviewer' => 'dataset reviewer',
      'study administrator' => 'study administrator',
      'study reviewer' => 'study reviewer',
    ),
    'module' => 'workbench_moderation',
  );

  // Exported permission: 'view any unpublished contact content'.
  $permissions['view any unpublished contact content'] = array(
    'name' => 'view any unpublished contact content',
    'roles' => array(
      'administrator' => 'administrator',
      'study administrator' => 'study administrator',
      'study reviewer' => 'study reviewer',
    ),
    'module' => 'view_unpublished',
  );

  // Exported permission: 'view any unpublished content'.
  $permissions['view any unpublished content'] = array(
    'name' => 'view any unpublished content',
    'roles' => array(
      'administrator' => 'administrator',
      'consortium administrator' => 'consortium administrator',
    ),
    'module' => 'view_unpublished',
  );

  // Exported permission: 'view any unpublished data_collection_event content'.
  $permissions['view any unpublished data_collection_event content'] = array(
    'name' => 'view any unpublished data_collection_event content',
    'roles' => array(
      'study administrator' => 'study administrator',
      'study reviewer' => 'study reviewer',
    ),
    'module' => 'view_unpublished',
  );

  // Exported permission: 'view any unpublished documents content'.
  $permissions['view any unpublished documents content'] = array(
    'name' => 'view any unpublished documents content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'view_unpublished',
  );

  // Exported permission: 'view any unpublished population content'.
  $permissions['view any unpublished population content'] = array(
    'name' => 'view any unpublished population content',
    'roles' => array(
      'study administrator' => 'study administrator',
      'study reviewer' => 'study reviewer',
    ),
    'module' => 'view_unpublished',
  );

  // Exported permission: 'view any unpublished study content'.
  $permissions['view any unpublished study content'] = array(
    'name' => 'view any unpublished study content',
    'roles' => array(
      'administrator' => 'administrator',
      'study administrator' => 'study administrator',
      'study reviewer' => 'study reviewer',
    ),
    'module' => 'view_unpublished',
  );

  // Exported permission: 'view field_authorising_date'.
  $permissions['view field_authorising_date'] = array(
    'name' => 'view field_authorising_date',
    'roles' => array(
      'administrator' => 'administrator',
      'consortium administrator' => 'consortium administrator',
      'study reviewer' => 'study reviewer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_authorising_date_m'.
  $permissions['view field_authorising_date_m'] = array(
    'name' => 'view field_authorising_date_m',
    'roles' => array(
      'administrator' => 'administrator',
      'consortium administrator' => 'consortium administrator',
      'study reviewer' => 'study reviewer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_authorising_person_name'.
  $permissions['view field_authorising_person_name'] = array(
    'name' => 'view field_authorising_person_name',
    'roles' => array(
      'administrator' => 'administrator',
      'consortium administrator' => 'consortium administrator',
      'study reviewer' => 'study reviewer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_authorising_person_name_m'.
  $permissions['view field_authorising_person_name_m'] = array(
    'name' => 'view field_authorising_person_name_m',
    'roles' => array(
      'administrator' => 'administrator',
      'consortium administrator' => 'consortium administrator',
      'study reviewer' => 'study reviewer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_authorization_maelstrom'.
  $permissions['view field_authorization_maelstrom'] = array(
    'name' => 'view field_authorization_maelstrom',
    'roles' => array(
      'administrator' => 'administrator',
      'consortium administrator' => 'consortium administrator',
      'study reviewer' => 'study reviewer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_authorization_specific'.
  $permissions['view field_authorization_specific'] = array(
    'name' => 'view field_authorization_specific',
    'roles' => array(
      'administrator' => 'administrator',
      'consortium administrator' => 'consortium administrator',
      'study reviewer' => 'study reviewer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view moderation history'.
  $permissions['view moderation history'] = array(
    'name' => 'view moderation history',
    'roles' => array(
      'administrator' => 'administrator',
      'consortium administrator' => 'consortium administrator',
      'dataset administrator' => 'dataset administrator',
      'dataset reviewer' => 'dataset reviewer',
      'study administrator' => 'study administrator',
      'study reviewer' => 'study reviewer',
    ),
    'module' => 'workbench_moderation',
  );

  // Exported permission: 'view moderation messages'.
  $permissions['view moderation messages'] = array(
    'name' => 'view moderation messages',
    'roles' => array(
      'administrator' => 'administrator',
      'consortium administrator' => 'consortium administrator',
      'dataset administrator' => 'dataset administrator',
      'dataset reviewer' => 'dataset reviewer',
      'study administrator' => 'study administrator',
      'study reviewer' => 'study reviewer',
    ),
    'module' => 'workbench_moderation',
  );

  // Exported permission: 'view own field_authorising_date'.
  $permissions['view own field_authorising_date'] = array(
    'name' => 'view own field_authorising_date',
    'roles' => array(
      'administrator' => 'administrator',
      'consortium administrator' => 'consortium administrator',
      'study administrator' => 'study administrator',
      'study reviewer' => 'study reviewer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_authorising_date_m'.
  $permissions['view own field_authorising_date_m'] = array(
    'name' => 'view own field_authorising_date_m',
    'roles' => array(
      'administrator' => 'administrator',
      'consortium administrator' => 'consortium administrator',
      'study administrator' => 'study administrator',
      'study reviewer' => 'study reviewer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_authorising_person_name'.
  $permissions['view own field_authorising_person_name'] = array(
    'name' => 'view own field_authorising_person_name',
    'roles' => array(
      'administrator' => 'administrator',
      'consortium administrator' => 'consortium administrator',
      'study administrator' => 'study administrator',
      'study reviewer' => 'study reviewer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_authorising_person_name_m'.
  $permissions['view own field_authorising_person_name_m'] = array(
    'name' => 'view own field_authorising_person_name_m',
    'roles' => array(
      'administrator' => 'administrator',
      'consortium administrator' => 'consortium administrator',
      'study administrator' => 'study administrator',
      'study reviewer' => 'study reviewer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_authorization_maelstrom'.
  $permissions['view own field_authorization_maelstrom'] = array(
    'name' => 'view own field_authorization_maelstrom',
    'roles' => array(
      'administrator' => 'administrator',
      'consortium administrator' => 'consortium administrator',
      'study administrator' => 'study administrator',
      'study reviewer' => 'study reviewer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_authorization_specific'.
  $permissions['view own field_authorization_specific'] = array(
    'name' => 'view own field_authorization_specific',
    'roles' => array(
      'administrator' => 'administrator',
      'consortium administrator' => 'consortium administrator',
      'study administrator' => 'study administrator',
      'study reviewer' => 'study reviewer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own unpublished content'.
  $permissions['view own unpublished content'] = array(
    'name' => 'view own unpublished content',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: 'view revisions'.
  $permissions['view revisions'] = array(
    'name' => 'view revisions',
    'roles' => array(
      'administrator' => 'administrator',
      'consortium administrator' => 'consortium administrator',
      'dataset administrator' => 'dataset administrator',
      'dataset reviewer' => 'dataset reviewer',
      'study administrator' => 'study administrator',
      'study reviewer' => 'study reviewer',
    ),
    'module' => 'node',
  );

  return $permissions;
}
