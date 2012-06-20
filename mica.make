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
projects[drupal][version] = 7.14

; Use vocabulary machine name for permissions
; http://drupal.org/node/995156
projects[drupal][patch][995156] = http://drupal.org/files/issues/995156-5_portable_taxonomy_permissions.patch
  
; Modules
; --------
projects[acl][version] = 1.0-beta3
projects[acl][type] = module

projects[auto_nodetitle][version] = 1.0
projects[auto_nodetitle][type] = module

projects[autocomplete_deluxe][type] = module
projects[autocomplete_deluxe][download][type] = git
projects[autocomplete_deluxe][download][revision] = a92b71e
projects[autocomplete_deluxe][download][branch] = 7.x-1.x

projects[] = advanced_help

projects[calendar][version] = 3.4
projects[calendar][type] = module

projects[cck_select_other][version] = 1.0
projects[cck_select_other][type] = module

projects[chain_menu_access][version] = 1.0
projects[chain_menu_access][type] = module

projects[ckeditor][version] = 1.9
projects[ckeditor][type] = module

projects[collapsiblock][type] = module
projects[collapsiblock][download][type] = git
projects[collapsiblock][download][revision] = 36f4280
projects[collapsiblock][download][branch] = 7.x-1.x
projects[collapsiblock][patch][1475244] = http://drupal.org/files/api-function-and-constants-patch1301454-patch1429956.patch

projects[cnr][type] = module
projects[cnr][download][type] = git
projects[cnr][download][revision] =  89f859e
projects[cnr][download][branch] =  7.x-4.x

projects[content_access][version] = 1.2-beta1
projects[content_access][type] = module

projects[content_taxonomy][type] = module
projects[content_taxonomy][version] = 1.0-beta1

projects[ctools][type] = module
projects[ctools][version] = 1.0

projects[date][version] = 2.5
projects[date][type] = module

projects[diff][version] = 2.0
projects[diff][type] = module

projects[] = devel

projects[email][type] = module
projects[email][download][type] = git
projects[email][download][revision] = 523cd0d
projects[email][download][branch] = 7.x-1.x
projects[email][patch][718414] = http://drupal.org/files/email_feeds_target-718414-36.patch

projects[entity][type] = module
projects[entity][version] = 1.0-rc3
projects[entity][patch][1621226] = http://drupal.org/files/entity-add-field-info-on-validation-exception.patch

projects[entity_translation][type] = module
projects[entity_translation][version] = 1.0-alpha2

projects[facetapi][version] = 1.0-rc4
projects[facetapi][type] = module
projects[facetapi][patch][1630714] = http://drupal.org/files/undefined-index-html-item_group-inc.patch

;projects[] = examples

projects[features][version] = 1.0-rc2
projects[features][type] = module
projects[features][patch][1530386] = http://drupal.org/files/features-1530386-10-improve_installation_performance.patch

projects[feeds][type] = module
projects[feeds][download][type] = git
projects[feeds][download][revision] = cc2d2ec
projects[feeds][download][branch] = 7.x-2.x
projects[feeds][patch][11075222] = http://drupal.org/files/issues/1107522-empty-fields-2.patch
projects[feeds][patch][110752213] = http://drupal.org/files/ignore-empty-taxonomy-terms-1107522-13.patch
projects[feeds][patch][110752215links] = http://drupal.org/files/ignore-empty-link-fields-1107522-15.patch

projects[feeds_tamper][download][type] = git
projects[feeds_tamper][download][revision] = 8f7f581
projects[feeds_tamper][download][branch] = 7.x-1.x
projects[feeds_tamper][patch][1416700] = http://drupal.org/files/1416700-4-feeds_tamper-existing-terms-plugin.patch
projects[feeds_tamper][patch][1180726] = http://drupal.org/files/empty_check-1180726-6.patch

projects[field_display_label][version] = 1.2
projects[field_display_label][type] = module

projects[field_group][version] = 1.1
projects[field_group][type] = module

projects[field_permissions][version] = 1.0-beta2
projects[field_permissions][type] = module

projects[forum_access][version] = 1.0-alpha4
projects[forum_access][type] = module

projects[google_analytics][version] = 1.2
projects[google_analytics][type] = module

projects[google_fonts][version] = 2.3
projects[google_fonts][type] = module

projects[] = graphapi

projects[http_client][version] = 2.3
projects[http_client][type] = module

projects[i18n][version] = 1.5
projects[i18n][type] = module

projects[image_url_formatter][version] = 1.0
projects[image_url_formatter][type] = module

projects[imce][version] = 1.5
projects[imce][type] = module

projects[job_scheduler][version] = 2.0-alpha3
projects[job_scheduler][type] = module

projects[lang_dropdown][version] = 1.5
projects[lang_dropdown][type] = module

projects[languageicons][version] = 1.0
projects[languageicons][type] = module

projects[link][version] = 1.0
projects[link][type] = module

projects[login_destination][version] = 1.0
projects[login_destination][type] = module

projects[mail_edit][version] = 1.0-rc1
projects[mail_edit][type] = module

projects[masquerade][version] = 1.0-rc4
projects[masquerade][type] = module

projects[menu_breadcrumb][version] = 1.3
projects[menu_breadcrumb][type] = module

projects[menu_firstchild][version] = 1.1
projects[menu_firstchild][type] = module

projects[module_filter][version] = 1.6
projects[module_filter][type] = module

projects[multiselect][version] = 1.9
projects[multiselect][type] = module

projects[namedb][type] = module
projects[namedb][download][type] = git
projects[namedb][download][revision] = 7284d85
projects[namedb][download][branch] = 7.x-1.x

projects[name][version] = 1.5
projects[name][type] = module

projects[noderefcreate][type] = module
projects[noderefcreate][download][type] = git
projects[noderefcreate][download][revision] = 4268ba7
projects[noderefcreate][download][branch] = 7.x-1.x
projects[noderefcreate][patch][892052] = http://drupal.org/files/noderefcreate-workflow-options-892052-4.patch
projects[noderefcreate][patch][1538328] = http://drupal.org/files/maxlength-1538328-1.patch

projects[panels][version] = 3.2
projects[panels][type] = module

projects[password_policy][version] = 1.0-rc2
projects[password_policy][type] = module

projects[pathauto][version] = 1.1
projects[pathauto][type] = module

projects[potx][version] = 1.0
projects[potx][type] = module

projects[progress][version] = 1.3
projects[progress][type] = module

projects[recaptcha][version] = 1.7
projects[recaptcha][type] = module

projects[references][type] = module
projects[references][download][type] = git
projects[references][download][revision] = 311bd49
projects[references][download][branch] = 7.x-2.x

projects[search_api][version] = 1.1
projects[search_api][type] = module
projects[search_api][patch][1363114] = http://drupal.org/files/max_inclusive-1363114-5.patch
projects[search_api][patch][1617794] = http://drupal.org/files/search_api-view_unpublished-support-1617794-6.patch

projects[search_api_db][version] = 1.0-beta2
projects[search_api_db][type] = module

projects[search_api_combined][version] = 1.0-alpha1
projects[search_api_combined][type] = module

projects[search_api_page][version] = 1.0-beta2
projects[search_api_page][type] = module

projects[search_api_ranges][type] = module
projects[search_api_ranges][download][type] = git
projects[search_api_ranges][download][revision] = fe3b59f
projects[search_api_ranges][download][branch] = 7.x-1.x
projects[search_api_ranges][patch][1450772] = http://drupal.org/files/force-numeric-and-config-for-no-slider-no-commit-on-change-1450772-1_1.patch
projects[search_api_ranges][patch][1460410] = http://drupal.org/files/max-inclusive.patch

projects[search_api_solr][version] = 1.0-rc2
projects[search_api_solr][type] = module
projects[search_api_solr][patch][1276970] = http://drupal.org/files/solr_queries_post-1276970-10.patch

projects[services][version] = 3.1
projects[services][type] = module

projects[smtp][version] = 1.0-beta1
projects[smtp][type] = module

projects[strongarm][version] = 2.0-rc1
projects[strongarm][type] = module
projects[strongarm][patch][1525768] = http://drupal.org/files/print_stdclass_variables.patch

projects[taxonomy_csv][version] = 5.10
projects[taxonomy_csv][type] = module

projects[taxonomy_manager][version] = 1.0-beta2
projects[taxonomy_manager][type] = module

projects[title][type] = module
projects[title][download][type] = git
projects[title][download][revision] = 5cfda9b
projects[title][download][branch] = 7.x-1.x
projects[title][patch][1362790] = http://drupal.org/files/check_if_legacy_field_is_set-1362790-1.patch

projects[token][version] = 1.1
projects[token][type] = module

projects[variable][version] = 1.1
projects[variable][type] = module

projects[view_unpublished][version] = 1.1
projects[view_unpublished][type] = module

projects[views][version] = 3.3
projects[views][type] = module

projects[views_data_export][version] = 3.0-beta6
projects[views_data_export][type] = module
projects[views_data_export][patch][1224894] = http://drupal.org/files/html_in_csv-1224894-10.patch

projects[viewreference][version] = 3.3
projects[viewreference][type] = module

projects[workbench][version] = 1.1
projects[workbench][type] = module

projects[workbench_moderation][version] = 1.2
projects[workbench_moderation][type] = module
projects[workbench_moderation][patch][1245590] = http://drupal.org/files/retaintitle-1245590-12.patch

  
; Libraries
; ---------
libraries[solr_php_client][type] = libraries
libraries[solr_php_client][download][type] = get
libraries[solr_php_client][download][url] = http://solr-php-client.googlecode.com/files/SolrPhpClient.r60.2011-05-04.tgz
libraries[solr_php_client][directory_name] = SolrPhpClient

libraries[ckeditor][type] = libraries
libraries[ckeditor][download][type]= get
libraries[ckeditor][download][url] = http://download.cksource.com/CKEditor/CKEditor/CKEditor%203.6.3/ckeditor_3.6.3.tar.gz
libraries[ckeditor][directory_name] = ckeditor

libraries[spyc][type] = libraries
libraries[spyc][download][type]= get
libraries[spyc][download][url] = http://spyc.googlecode.com/svn/trunk/spyc.php
libraries[spyc][destination] = modules
libraries[spyc][directory_name] = services/servers/rest_server/lib
libraries[spyc][overwrite] = TRUE
