#
# Mica Drupal Makefile
# Requires drush 4+ to be installed: http://drush.ws/
#

#
# Modules dependencies
#
acl_version=7.x-1.0-beta3
calendar_version=7.x-3.0-alpha1
chain_menu_access_version=7.x-1.0
ckeditor_version=7.x-1.6
collapsiblock_version=7.x-1.0
content_access_version=7.x-1.2-beta1
content_taxonomy_version=7.x-1.0-beta1
date_version=7.x-2.0-alpha5
drupal_version=7.9
email_version=7.x-1.0
entity_version=7.x-1.0-rc1
facetapi_version=7.x-1.0-beta8
features_version=7.x-1.x-beta4
feeds_version=7.x-2.0-alpha4
feeds_jsonpath_parser_version=7.x-1.0-beta2
field_group_version=7.x-1.1
field_permissions_version=7.x-1.0-beta1
forum_access_version=7.x-1.0-alpha4
google_fonts_version=7.x-2.3
http_client_version=7.x-2.2
imce_version=7.x-1.5
job_scheduler_version=7.x-2.0-alpha2
link_version=7.x-1.0
login_destination_version=7.x-1.0
menu_firstchild_version=7.x-1.1
multiselect_version=7.x-1.8
namedb_version=7.x-1.0-beta2
name_version=7.x-1.4
noderefcreate_version=7.x-1.0
panels_version=7.x-3.0-alpha3
pathauto_version=7.x-1.0
search_api_page_version=7.x-1.0-beta2
search_api_solr_version=7.x-1.0-rc1
search_api_version=7.x-1.0-rc1
strongarm_version=7.x-2.0-beta4
tagging_version=7.x-3.3
taxonomy_csv_version=7.x-5.7
taxonomy_manager_version=7.x-1.0-beta2
token_version=7.x-1.0-beta7
viewreference_version=7.x-3.1
views_data_export_version=7.x-3.0-beta5
views_version=7.x-3.0-rc3

#
# Libraries dependencies
#
solr-php-client-version=r60.2011-05-04

#
# Modules to get stable dev revisions
#

# Issue http://drupal.org/node/1234010
ctools_revision=dd65335ef5b823702ea5f1688a3000b09a04a739

# Issue http://drupal.org/node/1275096
references_revision=e00686587a53cf51bdcca45248e9a72b483b8916

# Waiting for release that supports FacetAPI
search_api_ranges_revision=7256e42869632a939b4240396a69110a5beedf2f

# CKEditor Library Version
ckeditor_version=3.6.1

#
# Drupal Build
#

drupal: drupal-prepare drupal-download drupal-stable-dev drupal-install-clients ckeditor-library drupal-default 

drupal-prepare:
	mkdir -p target

drupal-download:
	cd target && \
	$(drushexec) dl drupal-$(drupal_version) --drupal-project-rename=$(micadir) && \
	cd $(micadir) && \
	$(drushexec) dl \
		acl-$(acl_version) \
		advanced_help \
		calendar-$(calendar_version) \
		chain_menu_access-$(chain_menu_access_version) \
		ckeditor-$(ckeditor_version) \
		collapsiblock-$(collapsiblock_version) \
		content_access-$(content_access_version) \
		content_taxonomy-$(content_taxonomy_version) \
		date-$(date_version) \
		email-$(email_version) \
		entity-$(entity_version) \
		facetapi-$(facetapi_version) \
		features-$(features_version) \
		feeds-$(feeds_version) \
		feeds_jsonpath_parser-$(feeds_jsonpath_parser_version) \
		field_group-$(field_group_version) \
		field_permissions-$(field_permissions_version) \
		forum_access-$(forum_access_version) \
		google_fonts-$(google_fonts_version) \
		http_client-$(http_client_version) \
		imce-$(imce_version) \
		job_scheduler-$(job_scheduler_version) \
		link-$(link_version) \
		login_destination-$(login_destination_version) \
		menu_firstchild-$(menu_firstchild_version) \
		multiselect-$(multiselect_version) \
		namedb-$(namedb_version) \
		name-$(name_version) \
		noderefcreate-$(noderefcreate_version) \
		panels-$(panels_version) \
		pathauto-$(pathauto_version) \
		search_api_page-$(search_api_page_version) \
		search_api-$(search_api_version) \
		search_api_solr-$(search_api_solr_version) \
		strongarm-$(strongarm_version) \
		tagging-$(tagging_version) \
		taxonomy_csv-$(taxonomy_csv_version) \
		taxonomy_manager-$(taxonomy_manager_version) \
		token-$(token_version) \
		viewreference-$(viewreference_version) \
		views_data_export-$(views_data_export_version) \
		views-$(views_version)

drupal-examples:
	cd target/$(micadir) && \
	$(drushexec) dl examples

drupal-dl:
	cd target/$(micadir) && \
	$(drushexec) dl $(module)

drupal-en:
	cd target/$(micadir) && \
	$(drushexec) en --yes $(module)

drupal-dis:
	cd target/$(micadir) && \
	$(drushexec) pm-disable --yes $(module)	

drupal-cache-clear:
	cd target/$(micadir) && \
	$(drushexec) cache-clear	

drupal-stable-dev: drupal-core-patch drupal-module-patch
	$(call drupal-git-checkout-module,references, 0)
	$(call drupal-git-checkout-module,ctools, 0)
	$(call drupal-git-checkout-module,search_api_ranges, 0)
	
drupal-module-patch:
#	$(call drupal-git-patch-module,search_api_ranges, 1)
#	$(call drupal-patch-module-file,sites/all/modules/search_api_ranges/search_api_ranges.module,MICA-206-ranges-block-title-truncated.patch)
#	$(call drupal-patch-module-file,sites/all/modules/search_api_ranges/search_api_ranges.module,MICA-207-hide-ranges-block-when-min-equals-max.patch)
	
drupal-core-patch:
	$(call drupal-patch-module-file,modules/block/block.module,MICA-205-block-info-test.patch)
	
drupal-install-clients: jsonpath-php-client solr-php-client

jsonpath-php-client:
	cd target/$(micadir)/sites/all/modules/feeds_jsonpath_parser && \
	wget http://jsonpath.googlecode.com/files/jsonpath-0.8.1.php
	
solr-php-client:
	cd target/$(micadir)/sites/all/modules/search_api_solr && \
	rm -rf SolrPhpClient && \
	wget http://solr-php-client.googlecode.com/files/SolrPhpClient.${solr-php-client-version}.tgz && \
	tar -zxvf SolrPhpClient.${solr-php-client-version}.tgz && \
	rm -rf SolrPhpClient.${solr-php-client-version}.tgz

ckeditor-library:
	cd target/$(micadir)/sites/all/modules/ckeditor && \
	rm -rf ckeditor && \
	wget -q http://download.cksource.com/CKEditor/CKEditor/CKEditor%20$(ckeditor_version)/ckeditor_$(ckeditor_version).tar.gz && \
	tar xfz ckeditor_$(ckeditor_version).tar.gz && \
	rm ckeditor_$(ckeditor_version).tar.gz && \
	cd ckeditor && \
	rm -rf _samples && \
	rm -rf _source

drupal-default:
	cd target/$(micadir) && \
	chmod a+w sites/default && \
	mkdir sites/default/files && \
	chmod a+w sites/default/files && \
	cp sites/default/default.settings.php sites/default/settings.php && \
	chmod a+w sites/default/settings.php && \
	chmod +x scripts/*.sh

drupal-git-patch-module = $(call drupal-git-checkout-module,$(1)) && \
	wget -O - $($(1)_patch) | git apply -p$(2)	

drupal-git-patch-module-file = $(call drupal-git-checkout-module,$(1)) && \
	git apply -p$(2) ../../../../../../src/main/drupal/patches/$($(1)_patch)
	
# drupal-git-checkout-module function: checkout a specific module version using git
drupal-git-checkout-module = cd target/$(micadir)/sites/all/modules && \
	rm -rf $(1) && \
	git clone http://git.drupal.org/project/$(1).git && \
	cd $(1) && \
	git checkout $($(1)_revision)

drupal-patch-module-file = patch target/$(micadir)/$(1) -i src/main/drupal/patches/$(2)
