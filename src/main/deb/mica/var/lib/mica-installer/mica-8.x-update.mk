#
# Populated using src/main/drupal/profiles/mica_distribution/drupal-org.make
#

mica-delete-8.0: mica-delete-module-8.0 mica-delete-library-8.0 mica-delete-theme-8.0
	$(call delete-profile,mica_distribution)

mica-delete-theme-8.0:
	$(call delete-theme,bootstrap) && \
	$(call delete-theme,mica_bootstrap)

mica-delete-library-8.0:
	$(call delete-library,ckeditor) && \
	$(call delete-library,jquery_tooltip) && \
	$(call delete-library,prettify_css) && \
	$(call delete-library,prettify_js) && \
	$(call delete-library,solr_php_client)

mica-delete-module-8.0:
	$(call delete-module,acl) && \
	$(call delete-module,auto_entitylabel) && \
	$(call delete-module,autocomplete_deluxe) && \
	$(call delete-module,auto_nodetitle) && \
	$(call delete-module,advanced_help) && \
	$(call delete-module,calendar) && \
	$(call delete-module,captcha) && \
	$(call delete-module,cck_select_other) && \
	$(call delete-module,chain_menu_access) && \
	$(call delete-module,ckeditor) && \
	$(call delete-module,collapsiblock) && \
	$(call delete-module,cnr) && \
	$(call delete-module,content_access) && \
	$(call delete-module,content_taxonomy) && \
	$(call delete-module,ctools) && \
	$(call delete-module,date) && \
	$(call delete-module,diff) && \
	$(call delete-module,devel) && \
	$(call delete-module,email) && \
	$(call delete-module,entity) && \
	$(call delete-module,entity_translation) && \
	$(call delete-module,facetapi) && \
	$(call delete-module,facetapi_i18n) && \
	$(call delete-module,features) && \
	$(call delete-module,features_override) && \
	$(call delete-module,feeds) && \
	$(call delete-module,feeds_tamper) && \
	$(call delete-module,field_display_label) && \
	$(call delete-module,field_group) && \
	$(call delete-module,field_permissions) && \
	$(call delete-module,forum_access) && \
	$(call delete-module,google_analytics) && \
	$(call delete-module,google_fonts) && \
	$(call delete-module,graphapi) && \
	$(call delete-module,http_client) && \
	$(call delete-module,i18n) && \
	$(call delete-module,image_url_formatter) && \
	$(call delete-module,imce) && \
	$(call delete-module,job_scheduler) && \
	$(call delete-module,jquery_update) && \
	$(call delete-module,jquery_ui_multiselect_widget) && \
	$(call delete-module,l10n_update) && \
	$(call delete-module,lang_dropdown) && \
	$(call delete-module,languageicons) && \
	$(call delete-module,libraries) && \
	$(call delete-module,link) && \
	$(call delete-module,logintoboggan) && \
	$(call delete-module,mail_edit) && \
	$(call delete-module,masquerade) && \
	$(call delete-module,menu_breadcrumb) && \
	$(call delete-module,menu_firstchild) && \
	$(call delete-module,menu_view_unpublished) && \
	$(call delete-module,mica) && \
	$(call delete-module,module_filter) && \
	$(call delete-module,multiselect) && \
	$(call delete-module,name) && \
	$(call delete-module,noderefcreate) && \
	$(call delete-module,panels) && \
	$(call delete-module,password_policy) && \
	$(call delete-module,pathauto) && \
	$(call delete-module,profile2) && \
	$(call delete-module,potx) && \
	$(call delete-module,progress) && \
	$(call delete-module,recaptcha) && \
	$(call delete-module,references) && \
	$(call delete-module,search_api) && \
	$(call delete-module,search_api_combined) && \
	$(call delete-module,search_api_page) && \
	$(call delete-module,search_api_ranges) && \
	$(call delete-module,search_api_solr) && \
	$(call delete-module,services) && \
	$(call delete-module,smtp) && \
	$(call delete-module,strongarm) && \
	$(call delete-module,taxonomy_csv) && \
	$(call delete-module,taxonomy_manager) && \
	$(call delete-module,title) && \
	$(call delete-module,token) && \
	$(call delete-module,variable) && \
	$(call delete-module,view_unpublished) && \
	$(call delete-module,views) && \
	$(call delete-module,views_bulk_operations) && \
	$(call delete-module,views_data_export) && \
	$(call delete-module,viewreference) && \
	$(call delete-module,workbench) && \
	$(call delete-module,workbench_moderation) && \
	$(call delete-module,xmlsitemap)

mica-delete-8.0-dev: mica-delete-8.0
mica-delete-8.0-rc1: mica-delete-8.0
mica-delete-8.0-rc2: mica-delete-8.0
mica-delete-8.0-rc3: mica-delete-8.0
mica-delete-8.0-rc4: mica-delete-8.0
mica-delete-8.0-rc5: mica-delete-8.0
mica-delete-8.0-rc6: mica-delete-8.0
mica-delete-8.0-rc7: mica-delete-8.0
mica-delete-8.0-rc8: mica-delete-8.0
mica-delete-8.0-rc9: mica-delete-8.0

mica-delete-8.2-rc1: mica-delete-8.0
mica-delete-8.2-rc2: mica-delete-8.0
mica-delete-8.2-rc3: mica-delete-8.0
mica-delete-8.2-rc4: mica-delete-8.0
mica-delete-8.2-rc5: mica-delete-8.0
mica-delete-8.2-rc6: mica-delete-8.0
mica-delete-8.2-rc7: mica-delete-8.0
mica-delete-8.2: mica-delete-8.0

mica-delete-8.3-rc1: mica-delete-8.0
mica-delete-8.3-rc2: mica-delete-8.0
mica-delete-8.3-rc3: mica-delete-8.0
mica-delete-8.3-rc4: mica-delete-8.0
mica-delete-8.3-rc5: mica-delete-8.0
mica-delete-8.3-rc6: mica-delete-8.0
mica-delete-8.3-rc7: mica-delete-8.0
mica-delete-8.3: mica-delete-8.0
