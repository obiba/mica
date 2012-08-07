; Note that if we define more attributes for a specific project than just the version,
; the 'version' key *must* be defined for the project!

; Drupal Core
core = "7.x"
api = "2"

projects[acl] = 1.0-beta3

projects[auto_nodetitle] = 1.0

projects[autocomplete_deluxe][download][type] = git
projects[autocomplete_deluxe][download][revision] = a92b71e
projects[autocomplete_deluxe][download][branch] = 7.x-1.x

projects[] = advanced_help

projects[calendar] = 3.4

projects[cck_select_other] = 1.0

projects[chain_menu_access] = 1.0

projects[ckeditor] = 1.9

projects[collapsiblock][download][type] = git
projects[collapsiblock][download][revision] = 36f4280
projects[collapsiblock][download][branch] = 7.x-1.x
projects[collapsiblock][patch][1475244] = http://drupal.org/files/api-function-and-constants-patch1301454-patch1429956.patch

projects[cnr][download][type] = git
projects[cnr][download][revision] =  89f859e
projects[cnr][download][branch] =  7.x-4.x

projects[content_access] = 1.2-beta1

projects[content_taxonomy] = 1.0-beta1

projects[ctools] = 1.0

projects[date] = 2.5

projects[diff] = 2.0

projects[] = devel

projects[email][download][type] = git
projects[email][download][revision] = 523cd0d
projects[email][download][branch] = 7.x-1.x
projects[email][patch][718414] = http://drupal.org/files/email_feeds_target-718414-36.patch

projects[entity][version] = 1.0-rc3
projects[entity][patch][1621226] = http://drupal.org/files/entity-add-field-info-on-validation-exception.patch

projects[facetapi] = 1.0

;projects[] = examples

projects[features][version] = 1.0-rc3
projects[features][patch][981248] = http://drupal.org/files/hook_features_post_install-981248-58.patch
projects[features][patch][656312] = http://drupal.org/files/keep_negative_permissions-656312-17.patch

projects[feeds][version] = 2.0-alpha5
projects[feeds][patch][11075222] = http://drupal.org/files/issues/1107522-empty-fields-2.patch
projects[feeds][patch][110752213] = http://drupal.org/files/ignore-empty-taxonomy-terms-1107522-13.patch
projects[feeds][patch][110752215links] = http://drupal.org/files/ignore-empty-link-fields-1107522-15.patch

projects[feeds_tamper][download][type] = git
projects[feeds_tamper][download][revision] = 8f7f581
projects[feeds_tamper][download][branch] = 7.x-1.x
projects[feeds_tamper][patch][1416700] = http://drupal.org/files/1416700-4-feeds_tamper-existing-terms-plugin.patch
projects[feeds_tamper][patch][1180726] = http://drupal.org/files/empty_check-1180726-6.patch

projects[field_display_label] = 1.2

projects[field_group] = 1.1

projects[field_permissions] = 1.0-beta2

projects[forum_access] = 1.0-alpha4

projects[google_analytics] = 1.2

projects[google_fonts] = 2.3

projects[] = graphapi

projects[http_client] = 2.3

projects[image_url_formatter] = 1.0

projects[imce] = 1.5

projects[job_scheduler] = 2.0-alpha3

projects[link] = 1.0

projects[login_destination] = 1.0

projects[mail_edit] = 1.0-rc1

projects[masquerade] = 1.0-rc4

projects[menu_breadcrumb] = 1.3

projects[menu_firstchild] = 1.1

projects[mica] = 1.43

projects[module_filter] = 1.6

projects[multiselect] = 1.9

projects[namedb][download][type] = git
projects[namedb][download][revision] = 7284d85
projects[namedb][download][branch] = 7.x-1.x

projects[name] = 1.5

projects[noderefcreate][download][type] = git
projects[noderefcreate][download][revision] = 4268ba7
projects[noderefcreate][download][branch] = 7.x-1.x
projects[noderefcreate][patch][1181544] = http://drupal.org/files/noderefcreate-alter-and-worlflow-options-1181544-5.patch
projects[noderefcreate][patch][1538328] = http://drupal.org/files/maxlength-1538328-1.patch

projects[panels] = 3.2

projects[password_policy] = 1.0-rc2

projects[pathauto] = 1.1

projects[potx] = 1.0

projects[progress] = 1.3

projects[recaptcha] = 1.7

projects[references][download][type] = git
projects[references][download][revision] = 311bd49
projects[references][download][branch] = 7.x-2.x

projects[search_api][version] = 1.1
projects[search_api][patch][1363114] = http://drupal.org/files/max_inclusive-1363114-5.patch
projects[search_api][patch][1617794] = http://drupal.org/files/search_api-view_unpublished-support-1617794-6.patch

projects[search_api_db] = 1.0-beta2

projects[search_api_combined] = 1.0-alpha1

projects[search_api_page] = 1.0-beta2

projects[search_api_ranges][download][type] = git
projects[search_api_ranges][download][revision] = fe3b59f
projects[search_api_ranges][download][branch] = 7.x-1.x
projects[search_api_ranges][patch][1450772] = http://drupal.org/files/force-numeric-and-config-for-no-slider-no-commit-on-change-1450772-1_1.patch
projects[search_api_ranges][patch][1460410] = http://drupal.org/files/max-inclusive.patch

projects[search_api_solr][version] = 1.0-rc2
projects[search_api_solr][patch][1276970] = http://drupal.org/files/solr_queries_post-1276970-10.patch

projects[services] = 3.1

projects[smtp] = 1.0-beta1

projects[strongarm][version] = 2.0
projects[strongarm][patch][1525768] = http://drupal.org/files/print_stdclass_variables.patch

projects[taxonomy_csv] = 5.10

projects[taxonomy_manager] = 1.0-beta3

projects[title] = 1.0-alpha3

projects[token] = 1.1

projects[variable] = 1.1

projects[view_unpublished] = 1.1

projects[views] = 3.3

projects[views_data_export][version] = 3.0-beta6
projects[views_data_export][patch][1224894] = http://drupal.org/files/html_in_csv-1224894-10.patch

projects[viewreference] = 3.3

projects[workbench] = 1.1

projects[workbench_moderation][version] = 1.2
projects[workbench_moderation][patch][1245590] = http://drupal.org/files/retaintitle-1245590-12.patch


; Libraries
; ---------
libraries[solr_php_client][download][type] = get
libraries[solr_php_client][download][url] = http://solr-php-client.googlecode.com/files/SolrPhpClient.r60.2011-05-04.tgz
libraries[solr_php_client][directory_name] = SolrPhpClient

libraries[ckeditor][download][type]= get
libraries[ckeditor][download][url] = http://download.cksource.com/CKEditor/CKEditor/CKEditor%203.6.3/ckeditor_3.6.3.tar.gz
libraries[ckeditor][directory_name] = ckeditor

libraries[spyc][download][type]= get
libraries[spyc][download][url] = https://raw.github.com/mustangostang/spyc/master/spyc.php
libraries[spyc][destination] = modules
libraries[spyc][directory_name] = services/servers/rest_server/lib
libraries[spyc][overwrite] = TRUE
