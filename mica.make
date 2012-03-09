; Core version
; ------------
; Each makefile should begin by declaring the core version of Drupal that all
; projects should be compatible with.
  
core = 7.x
  
; API version
; ------------
; Every makefile needs to declare its Drush Make API version. This version of
; drush make uses API version `2`.
  
api = 2
  
; Core project
; ------------
; In order for your makefile to generate a full Drupal site, you must include
; a core project. This is usually Drupal core, but you can also specify
; alternative core projects like Pressflow. Note that makefiles included with
; install profiles *should not* include a core project.
  
; Drupal 7.x. Requires the `core` property to be set to 7.x.
projects[drupal][type] = core
projects[drupal][version] = 7.12

; Use vocabulary machine name for permissions
; http://drupal.org/node/995156
projects[drupal][patch][995156] = http://drupal.org/files/issues/995156-5_portable_taxonomy_permissions.patch
  
; Modules
; --------
projects[acl][version] = 1.0-beta3
projects[acl][type] = module

projects[auto_nodetitle][version] = 1.0
projects[auto_nodetitle][type] = module

projects[] = advanced_help

projects[calendar][version] = 3.0
projects[calendar][type] = module

projects[cck_select_other][version] = 1.0
projects[cck_select_other][type] = module

projects[chain_menu_access][version] = 1.0
projects[chain_menu_access][type] = module

projects[ckeditor][version] = 1.6
projects[ckeditor][type] = module

projects[collapsiblock][type] = module
projects[collapsiblock][download][type] = git
projects[collapsiblock][download][url] = http://git.drupal.org/project/collapsiblock.git
projects[collapsiblock][download][revision] = 36f42804ee1d4072d8cbb81c25b663bd4cdcc447
projects[collapsiblock][patch][1475244] = http://drupal.org/files/api-function-and-constants-patch1301454-patch1429956.patch

projects[content_access][version] = 1.2-beta1
projects[content_access][type] = module

projects[content_taxonomy][version] = 1.0-beta1
projects[content_taxonomy][type] = module

projects[ctools][type] = module
projects[ctools][download][type] = git
projects[ctools][download][url] = http://git.drupal.org/project/ctools.git
projects[ctools][download][revision] = dd65335ef5b823702ea5f1688a3000b09a04a739

projects[date][version] = 2.2
projects[date][type] = module

projects[defaultcontent][version] = 1.0-alpha5
projects[defaultcontent][type] = module

projects[] = devel

projects[email][type] = module
projects[email][download][type] = git
projects[email][download][url] = http://git.drupal.org/project/email.git
projects[email][download][revision] = 523cd0de1387a4fca52f007f7594160a56378196
projects[email][patch][718414] = http://drupal.org/files/email_feeds_target-718414-36.patch

projects[entity][version] = 1.0-rc1
projects[entity][type] = module
projects[entity][patch][1344056] = http://drupal.org/files/1344056--node-status-1.patch

projects[facetapi][version] = 1.0-rc4
projects[facetapi][type] = module

projects[] = examples

projects[features][version] = 1.0-beta6
projects[features][type] = module

projects[feeds][type] = module
projects[feeds][download][type] = git
projects[feeds][download][url] = http://git.drupal.org/project/feeds.git
projects[feeds][download][revision] = cc2d2eccfe7c8a30dcfefa49fd57407cb6f47cf5
projects[feeds][patch][1107522] = http://drupal.org/files/issues/1107522-empty-fields-2.patch



projects[feeds_jsonpath_parser][version] = 1.0-beta2
projects[feeds_jsonpath_parser][type] = module

projects[feeds_tamper][version] = 1.0-beta3
projects[feeds_tamper][type] = module

projects[field_display_label][version] = 1.2
projects[field_display_label][type] = module

projects[field_group][download][type] = git
projects[field_group][download][url] = http://git.drupal.org/project/field_group.git
projects[field_group][download][revision] = 3f5af2537bd01bf42e24bc3e3782f914add43186
projects[field_group][patch][1196890] = http://drupal.org/files/group-description-translation-1196890.patch

projects[field_permissions][version] = 1.0-beta2
projects[field_permissions][type] = module

projects[forum_access][version] = 1.0-alpha4
projects[forum_access][type] = module

projects[google_analytics][version] = 1.2
projects[google_analytics][type] = module

projects[google_fonts][version] = 2.3
projects[google_fonts][type] = module

projects[http_client][version] = 2.3
projects[http_client][type] = module

projects[image_url_formatter][version] = 1.0-rc1
projects[image_url_formatter][type] = module

projects[imce][version] = 1.5
projects[imce][type] = module

projects[job_scheduler][version] = 2.0-alpha2
projects[job_scheduler][type] = module

projects[job_scheduler][version] = 2.0-alpha2
projects[job_scheduler][type] = module

projects[link][version] = 1.0
projects[link][type] = module

projects[login_destination][version] = 1.0
projects[login_destination][type] = module

projects[masquerade][version] = 1.0-rc4
projects[masquerade][type] = module

projects[menu_breadcrumb][version] = 1.3
projects[menu_breadcrumb][type] = module

projects[menu_firstchild][version] = 1.1
projects[menu_firstchild][type] = module

projects[module_filter][version] = 1.6
projects[module_filter][type] = module

projects[multiselect][version] = 1.8
projects[multiselect][type] = module

projects[namedb][type] = module
projects[namedb][download][type] = git
projects[namedb][download][url] = http://git.drupal.org/project/namedb.git
projects[namedb][download][revision] = 7284d85b1a028ceae722eba0685a5fe7b2623c04

projects[name][type] = module
projects[name][download][type] = git
projects[name][download][url] = http://git.drupal.org/project/name.git
projects[name][download][revision] = 6644c91893ac05b681509486f01353490372a393

projects[noderefcreate][type] = module
projects[noderefcreate][download][type] = git
projects[noderefcreate][download][url] = http://git.drupal.org/project/noderefcreate.git
projects[noderefcreate][download][revision] = 4268ba7832272348d0612e23ce11f42f0a255318
projects[noderefcreate][patch][892052] = http://drupal.org/files/noderefcreate-workflow-options-892052-4.patch

projects[panels][version] = 3.0
projects[panels][type] = module

projects[pathauto][version] = 1.0
projects[pathauto][type] = module

projects[potx][version] = 1.0
projects[potx][type] = module

projects[references][type] = module
projects[references][download][type] = git
projects[references][download][url] = http://git.drupal.org/project/references.git
projects[references][download][revision] = 311bd497bfb0f9de046d585006a7ef3d9c6c74c8

projects[search_api][type] = module
projects[search_api][download][type] = git
projects[search_api][download][url] = http://git.drupal.org/project/search_api.git
projects[search_api][download][revision] = bfc5f152b19560089406648617aad4cc42365a2d
projects[search_api][patch][1363114] = http://drupal.org/files/max_inclusive-1363114-5.patch

projects[search_api][type] = module

projects[search_api_db][version] = 1.0-beta2
projects[search_api_db][type] = module

projects[search_api_page][version] = 1.0-beta2
projects[search_api_page][type] = module

projects[search_api_ranges][type] = module
projects[search_api_ranges][download][type] = git
projects[search_api_ranges][download][url] = http://git.drupal.org/project/search_api_ranges.git
projects[search_api_ranges][download][revision] = fe3b59f9c0206ac822c4e6474f8715fc1c2026a5
projects[search_api_ranges][patch][1450772] = http://drupal.org/files/force-numeric-and-config-for-no-slider-no-commit-on-change-1450772-1_1.patch
projects[search_api_ranges][patch][1460410] = http://drupal.org/files/max-inclusive.patch

projects[search_api_solr][version] = 1.0-rc1
projects[search_api_solr][type] = module

projects[smtp][version] = 1.0-beta1
projects[smtp][type] = module

projects[strongarm][version] = 2.0-beta5
projects[strongarm][type] = module

projects[tagging][version] = 3.3
projects[tagging][type] = module

projects[taxonomy_csv][version] = 5.10
projects[taxonomy_csv][type] = module

projects[taxonomy_manager][version] = 1.0-beta2
projects[taxonomy_manager][type] = module

projects[title][type] = module
projects[title][download][type] = git
projects[title][download][url] = http://git.drupal.org/project/title.git
projects[title][download][revision] = 5cfda9bb7b2d18efaa01f85a4d10255a2866c83a
projects[title][patch][1362790] = http://drupal.org/files/check_if_legacy_field_is_set-1362790-1.patch

projects[token][version] = 1.0-rc1
projects[token][type] = module

projects[variable][version] = 1.1
projects[variable][type] = module

projects[view_unpublished][version] = 1.0
projects[view_unpublished][type] = module

projects[views][version] = 3.3
projects[views][type] = module

projects[views_data_export][version] = 3.0-beta5
projects[views_data_export][type] = module

projects[viewreference][version] = 3.2
projects[viewreference][type] = module

projects[workbench][version] = 1.1
projects[workbench][type] = module

projects[workbench_moderation][version] = 1.1
projects[workbench_moderation][type] = module

  
; Libraries
; ---------
libraries[solr_php_client][type] = "libraries"
libraries[solr_php_client][download][type] = "get"
libraries[solr_php_client][download][url] = "http://solr-php-client.googlecode.com/files/SolrPhpClient.r60.2011-05-04.tgz"
libraries[solr_php_client][directory_name] = "SolrPhpClient"

libraries[ckeditor][type] = "libraries"
libraries[ckeditor][download][type]= "get"
libraries[ckeditor][download][url] = "http://download.cksource.com/CKEditor/CKEditor/CKEditor%203.6.1/ckeditor_3.6.1.tar.gz"
libraries[ckeditor][directory_name] = "ckeditor"

libraries[jsonpath][type] = "libraries"
libraries[jsonpath][download][type]= "get"
libraries[jsonpath][download][url] = "http://jsonpath.googlecode.com/files/jsonpath-0.8.1.php"
libraries[jsonpath][destination] = "modules"
libraries[jsonpath][directory_name] = "feeds_jsonpath_parser"
libraries[jsonpath][overwrite] = TRUE
