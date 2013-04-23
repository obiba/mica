; Note that if we define more attributes for a specific project than just the version,
; the 'version' key *must* be defined for the project!

; Support Drush 5.4 only

; Drupal Core
core = "7.x"
api = "2"

projects[acl] = 1.0

projects[adaptivetheme] = 3.1

projects[auto_entitylabel] = 1.1

projects[autocomplete_deluxe][download][type] = git
projects[autocomplete_deluxe][download][revision] = c562451
projects[autocomplete_deluxe][download][branch] = 7.x-2.x

; needed because of migration to auto_entitylabel
projects[auto_nodetitle] = 1.0

projects[] = advanced_help

projects[calendar] = 3.4

projects[captcha] = 1.0-beta2

projects[cck_select_other] = 1.0

projects[chain_menu_access] = 1.0

projects[ckeditor][download][type] = git
projects[ckeditor][download][revision] = 57c7a9c
projects[ckeditor][download][branch] = 7.x-1.x

projects[collapsiblock][download][type] = git
projects[collapsiblock][download][revision] = 36f4280
projects[collapsiblock][download][branch] = 7.x-1.x
projects[collapsiblock][patch][1475244] = http://drupal.org/files/api-function-and-constants-patch1301454-patch1429956.patch

projects[cnr][download][type] = git
projects[cnr][download][revision] = 89f859e
projects[cnr][download][branch] = 7.x-4.x

projects[content_access] = 1.2-beta1

projects[content_taxonomy] = 1.0-beta2

projects[ctools][version] = 1.2
projects[ctools][patch][1494860] = http://drupal.org/files/ctools-dependent-js-broken-with-jquery-1.7-1494860-30.patch

projects[date] = 2.6

projects[diff] = 3.2

projects[] = devel

projects[email] = 1.2

projects[entity][version] = 1.0
projects[entity][patch][1621226] = http://drupal.org/files/entity-add-field-info-on-validation-exception.patch

projects[entity_translation] = 1.0-alpha2

projects[facetapi] = 1.2

projects[facetapi_i18n] = 1.0-beta2

;projects[] = examples

projects[features][download][type] = git
projects[features][download][revision] = 63db687
projects[features][download][branch] = 7.x-2.x
projects[features][patch][1844566] = http://drupal.org/files/features_1844566_1_invoke-hooks-for-all-components.patch
projects[features][patch][656312] = http://drupal.org/files/keep_negative_permissions-656312-17.patch
projects[features][patch][1689598] = http://drupal.org/files/field_display_label_support.patch

projects[features_override][download][type] = git
projects[features_override][download][revision] = 602e87b
projects[features_override][download][branch] = 7.x-2.x
projects[features_override][patch][1648078] = http://drupal.org/files/invalid_argument_supplied-1648078-10.patch

projects[feeds][version] = 2.0-alpha7
projects[feeds][patch][1107522-59] = http://drupal.org/files/feeds-empty-behavior-1107522-59.patch
projects[feeds][patch][1107522-13] = http://drupal.org/files/ignore-empty-taxonomy-terms-1107522-13.patch
projects[feeds][patch][1107522-15] = http://drupal.org/files/ignore-empty-link-fields-1107522-60.patch

projects[feeds_tamper][version] = 1.0-beta4
projects[feeds_tamper][patch][1416700] = http://drupal.org/files/1416700-4-feeds_tamper-existing-terms-plugin.patch

projects[field_display_label][version] = 1.2
projects[field_display_label][patch][1689574] = http://drupal.org/files/field_display_label_i18n_field-1689574-6.patch

projects[field_group][version] = 1.1
projects[field_group][patch][1175102] = http://drupal.org/files/description_translation-1175102-16.patch

projects[field_permissions] = 1.0-beta2

projects[forum_access] = 1.2

projects[google_analytics] = 1.3

projects[google_fonts] = 2.3

projects[] = graphapi

projects[http_client] = 2.4

projects[i18n][version] = 1.7
projects[i18n][patch][1662884] = http://drupal.org/files/support_multiple_translation_modes-1662884-1.patch

projects[image_url_formatter] = 1.0

projects[imce] = 1.6

projects[job_scheduler] = 2.0-alpha3

projects[jquery_update][type] = module
projects[jquery_update][download][type] = git
projects[jquery_update][download][revision] = baff5d1
projects[jquery_update][download][branch] = 7.x-2.x

projects[jquery_ui_multiselect_widget] = 1.5

projects[l10n_update] = 1.0-beta3

projects[lang_dropdown] = 1.5

projects[languageicons] = 1.0

;projects[less] = 3.0-beta1

projects[libraries] = 2.1

projects[link] = 1.1

projects[logintoboggan] = 1.3

projects[mail_edit] = 1.0

projects[masquerade] = 1.0-rc5

projects[menu_breadcrumb] = 1.3

projects[menu_firstchild] = 1.1

projects[menu_view_unpublished][download][type] = git
projects[menu_view_unpublished][download][revision] = 5f1f951
projects[menu_view_unpublished][download][branch] = 7.x-1.x

projects[mica] = 7.1

projects[module_filter] = 1.7

projects[multiselect][version] = 1.9
projects[multiselect][patch][1670224] = http://drupal.org/files/options_translations-1670224-2.patch

projects[name][version] = 1.7
projects[name][patch][1788156] = http://drupal.org/files/name_title_translation-1788156-1.patch

projects[noderefcreate][download][type] = git
projects[noderefcreate][download][revision] = 4268ba7
projects[noderefcreate][download][branch] = 7.x-1.x
projects[noderefcreate][patch][1181544] = http://drupal.org/files/noderefcreate-alter-and-worlflow-options-1181544-5.patch
projects[noderefcreate][patch][1538328] = http://drupal.org/files/maxlength-1538328-1.patch

projects[panels] = 3.3

projects[password_policy] = 1.3

projects[pathauto] = 1.2

projects[potx] = 1.0

projects[progress] = 1.3

projects[recaptcha] = 1.7

projects[references][download][type] = git
projects[references][download][revision] = 311bd49
projects[references][download][branch] = 7.x-2.x

projects[search_api][version] = 1.4
projects[search_api][patch][1672536] = http://drupal.org/files/facet_items_translation-1672536-3.patch
projects[search_api][patch][1471310] = http://drupal.org/files/1471310--unset-field-8_0.patch
projects[search_api][patch][1123454] = http://drupal.org/files/search_api-vbo-1123454-36.patch
projects[search_api][patch][1594762] = http://drupal.org/files/1594762-18-deleted-terms-cause-indexing-crash.patch

projects[search_api_combined] = 1.2

projects[search_api_page] = 1.0-beta2

projects[search_api_ranges][download][type] = git
projects[search_api_ranges][download][revision] = fe3b59f
projects[search_api_ranges][download][branch] = 7.x-1.x
projects[search_api_ranges][patch][1450772] = http://drupal.org/files/force-numeric-and-config-for-no-slider-no-commit-on-change-1450772-1_1.patch
projects[search_api_ranges][patch][1460410] = http://drupal.org/files/max-inclusive.patch

projects[search_api_solr] = 1.0-rc3

; DO NOT CHANGE VERSION UNTIL http://jira.obiba.org/jira/browse/MICA-888 IS FIXED
projects[services][version] = 3.3

projects[smtp] = 1.0-beta2

projects[strongarm][version] = 2.0
projects[strongarm][patch][1525768] = http://drupal.org/files/print_stdclass_variables.patch

projects[superfish] = 1.9-beta4

projects[taxonomy_csv] = 5.10

projects[taxonomy_manager] = 1.0-rc2

projects[title] = 1.0-alpha5

projects[token] = 1.5

projects[variable] = 2.2

projects[view_unpublished] = 1.1

projects[views] = 3.5

projects[views_bulk_operations][version] = 3.1
projects[views_bulk_operations][patch][1809282] = http://drupal.org/files/views_bulk_operations-invalid_arg_foreach_modify-1809282.patch

projects[views_data_export][version] = 3.0-beta6
projects[views_data_export][patch][1224894] = http://drupal.org/files/html_in_csv-1224894-10.patch

projects[viewreference] = 3.4

projects[workbench] = 1.2

projects[workbench_moderation] = 1.3

projects[xmlsitemap] = 2.0-rc2

; Themes
; ---------

projects[bootstrap][type] = theme
projects[bootstrap][download][type] = git
projects[bootstrap][download][revision] = dc32478
projects[bootstrap][download][branch] = 7.x-2.x

projects[corolla] = 3.0-rc1


; Libraries
; ---------

; jsonpath is not downloaded here because of http://code.google.com/p/jsonpath/issues/detail?id=8

libraries[ckeditor][download][type]= get
libraries[ckeditor][download][url] = http://download.cksource.com/CKEditor/CKEditor/CKEditor%203.6.5/ckeditor_3.6.5.tar.gz
libraries[ckeditor][directory_name] = ckeditor

libraries[jquery_tooltip][download][type]= get
libraries[jquery_tooltip][download][url] = http://jquery.bassistance.de/tooltip/jquery.tooltip.zip
libraries[jquery_tooltip][directory_name] = jquery_tooltip

;libraries[lessphp][download][type]= get
;libraries[lessphp][download][url] = http://leafo.net/lessphp/src/lessphp-0.3.8.tar.gz
;libraries[lessphp][directory_name] = lessphp

;libraries[opal_php][download][type]= get
;libraries[opal_php][download][url] = http://download.obiba.org/opal/unstable/opal-php_1.11-SNAPSHOT.zip
;libraries[opal_php][directory_name] = opal_php

libraries[prettify_css][download][type] = get
libraries[prettify_css][download][url] = http://google-code-prettify.googlecode.com/svn/branches/release-1-Jun-2011/src/prettify.css
libraries[prettify_css][directory_name] = prettify
libraries[prettify_css][overwrite] = TRUE

libraries[prettify_js][download][type] = get
libraries[prettify_js][download][url] = http://google-code-prettify.googlecode.com/svn/branches/release-1-Jun-2011/src/prettify.js
libraries[prettify_js][directory_name] = prettify
libraries[prettify_js][overwrite] = TRUE

libraries[solr_php_client][download][type] = get
libraries[solr_php_client][download][url] = http://solr-php-client.googlecode.com/files/SolrPhpClient.r60.2011-05-04.tgz
libraries[solr_php_client][directory_name] = SolrPhpClient

libraries[superfish][download][type]= get
libraries[superfish][download][url] = https://github.com/mehrpadin/Superfish-for-Drupal/zipball/master
libraries[superfish][directory_name] = superfish
libraries[superfish][overwrite] = TRUE

