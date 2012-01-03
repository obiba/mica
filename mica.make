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
projects[drupal][version] = 7.10

; Use vocabulary machine name for permissions
; http://drupal.org/node/995156
projects[drupal][patch][995156] = http://drupal.org/files/issues/995156-5_portable_taxonomy_permissions.patch
;projects[drupal][patch][MICA-205] = http://svn.obiba.org/mica/trunk/src/main/drupal/patches/MICA-205-block-info-test.patch
  
; Modules
; --------
projects[acl][version] = 1.0-beta3
projects[acl][type] = module

projects[] = advanced_help

projects[calendar][version] = 3.0-alpha2
projects[calendar][type] = module

projects[chain_menu_access][version] = 1.0
projects[chain_menu_access][type] = module

projects[ckeditor][version] = 1.6
projects[ckeditor][type] = module

projects[collapsiblock][version] = 1.0
projects[collapsiblock][type] = module

projects[content_access][version] = 1.2-beta1
projects[content_access][type] = module

projects[content_taxonomy][version] = 1.0-beta1
projects[content_taxonomy][type] = module

projects[ctools][type] = module
projects[ctools][download][type] = git
projects[ctools][download][url] = http://git.drupal.org/project/ctools.git
projects[ctools][download][revision] = dd65335ef5b823702ea5f1688a3000b09a04a739

projects[date][version] = 2.0-rc1
projects[date][type] = module

projects[email][version] = 1.0
projects[email][type] = module

projects[entity][version] = 1.0-rc1
projects[entity][type] = module

projects[facetapi][version] = 1.0-rc1
projects[facetapi][type] = module

projects[features][version] = 1.0-beta5
projects[features][type] = module

projects[feeds][version] = 2.0-alpha4
projects[feeds][type] = module

projects[feeds_jsonpath_parser][version] = 1.0-beta2
projects[feeds_jsonpath_parser][type] = module

projects[field_group][version] = 1.1
projects[field_group][type] = module

projects[field_permissions][version] = 1.0-beta1
projects[field_permissions][type] = module

projects[forum_access][version] = 1.0-alpha4
projects[forum_access][type] = module

projects[google_fonts][version] = 2.3
projects[google_fonts][type] = module

projects[http_client][version] = 2.2
projects[http_client][type] = module

projects[imce][version] = 1.5
projects[imce][type] = module

projects[job_scheduler][version] = 2.0-alpha2
projects[job_scheduler][type] = module

projects[link][version] = 1.0
projects[link][type] = module

projects[login_destination][version] = 1.0
projects[login_destination][type] = module

projects[menu_firstchild][version] = 1.1
projects[menu_firstchild][type] = module

projects[multiselect][version] = 1.8
projects[multiselect][type] = module

projects[namedb][version] = 1.0-beta2
projects[namedb][type] = module

projects[name][version] = 1.4
projects[name][type] = module

projects[noderefcreate][version] = 1.0
projects[noderefcreate][type] = module

projects[panels][version] = 3.0-alpha3
projects[panels][type] = module

projects[pathauto][version] = 1.0
projects[pathauto][type] = module

projects[references][type] = module
projects[references][download][type] = git
projects[references][download][url] = http://git.drupal.org/project/references.git
projects[references][download][revision] = e00686587a53cf51bdcca45248e9a72b483b8916

projects[search_api][version] = 1.0
projects[search_api][type] = module

projects[search_api_db][version] = 1.0-beta2
projects[search_api_db][type] = module

projects[search_api_page][version] = 1.0-beta2
projects[search_api_page][type] = module

projects[search_api_ranges][type] = module
projects[search_api_ranges][download][type] = git
projects[search_api_ranges][download][url] = http://git.drupal.org/project/search_api_ranges.git
projects[search_api_ranges][download][revision] = 7256e42869632a939b4240396a69110a5beedf2f

projects[search_api_solr][version] = 1.0-rc1
projects[search_api_solr][type] = module

projects[strongarm][version] = 2.0-beta5
projects[strongarm][type] = module

projects[tagging][version] = 3.3
projects[tagging][type] = module

projects[taxonomy_csv][version] = 5.7
projects[taxonomy_csv][type] = module

projects[taxonomy_manager][version] = 1.0-beta2
projects[taxonomy_manager][type] = module

projects[token][version] = 1.0-beta7
projects[token][type] = module

projects[views][version] = 3.0
projects[views][type] = module

projects[views_data_export][version] = 3.0-beta5
projects[views_data_export][type] = module

projects[viewreference][version] = 3.2
projects[viewreference][type] = module

  
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
libraries[jsonpath][destination] = "modules/feeds_jsonpath_parser"
libraries[jsonpath][overwrite] = TRUE
