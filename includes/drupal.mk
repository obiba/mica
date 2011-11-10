#
# Mica Drupal Makefile
# Requires drush 4+ to be installed: http://drush.ws/
#

#
# Modules dependencies
#
acl_version=7.x-1.0-beta3
calendar_version=7.x-3.0-alpha1
chain_menu_access_version=7.x-1.0-beta2
ckeditor_version=7.x-1.6
content_access_version=7.x-1.2-beta1
ctools_version=7.x-1.0-rc1
date_version=7.x-2.0-alpha4
drupal_version=7.9
email_version=7.x-1.0
entity_version=7.x-1.0-beta10
features_version=7.x-1.0-beta3
#feeds_version=7.x-2.x-dev
feeds_jsonpath_parser_version=7.x-1.0-beta2
field_group_version=7.x-1.0
field_permissions_version=7.x-1.0-alpha1
forum_access_version=7.x-1.0-alpha4
google_fonts_version=7.x-2.3
imce_version=7.x-1.4
job_scheduler_version=7.x-2.0-alpha2
link_version=7.x-1.0-alpha3
login_destination_version=7.x-1.0
menu_firstchild_version=7.x-1.0
multiselect_version=7.x-1.8
name_version=7.x-1.4
namedb_version=7.x-1.0-beta2
noderefcreate_version=7.x-1.0
panels_version=7.x-3.0-alpha3
pathauto_version=7.x-1.0-rc2
relation_version=7.x-1.0-alpha2
search_api_version=7.x-1.0-beta10
search_api_ranges_version=7.x-1.2
search_api_solr_version=7.x-1.0-beta4
strongarm_version=7.x-2.0-beta2
token_version=7.x-1.0-beta5
views_data_export_version=7.x-3.0-beta5
views_version=7.x-3.0-rc1
viewreference_version=7.x-3.1

#
# Libraries dependencies
#
solr-php-client-version=22


#
# Modules to get stable dev revisions
#
http_client_branch=7.x-2.x
http_client_revision=6e65667997ffe79172249b42a897cd81dd4ab510

feeds_branch=7.x-2.x
feeds_revision=5f9ebacf6972bc5fe05f967cb33af0ddecc39ea5

# Patch for issue http://drupal.org/node/1138196
references_revision=7.x-2.0-beta3
references_patch=http://drupal.org/files/issues/references.node_type_property.patch

# Patch for issue http://drupal.org/node/1231540
search_api_ranges_revision=7.x-1.2
search_api_ranges_patch=http://drupal.org/files/issues/1231540-item-to-entity.patch

# Patch for issue http://drupal.org/node/1030216
menu_firstchild_revision=7.x-1.0
menu_firstchild_patch=1030216-undefined-index-add-shortcut.patch

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
		advanced_help \
		acl-$(acl_version) \
		chain_menu_access-$(chain_menu_access_version) \
		calendar-$(calendar_version) \
		ckeditor-$(ckeditor_version) \
		content_access-$(content_access_version) \
		ctools-$(ctools_version) \
		date-$(date_version) \
		email-$(email_version) \
		entity-$(entity_version) \
		features-$(features_version) \
		feeds_jsonpath_parser-$(feeds_jsonpath_parser_version) \
		field_group-$(field_group_version) \
		field_permissions-$(field_permissions_version) \
		forum_access-$(forum_access_version) \
		google_fonts-$(google_fonts_version) \
		imce-$(imce_version) \
		job_scheduler-$(job_scheduler_version) \
		link-$(link_version) \
		login_destination-$(login_destination_version) \
		menu_firstchild-$(menu_firstchild_version) \
		multiselect-$(multiselect_version) \
		name-$(name_version) \
		namedb-$(namedb_version) \
		noderefcreate-$(noderefcreate_version) \
		panels-$(panels_version) \
		pathauto-$(pathauto_version) \
		relation-$(relation_version) \
		search_api-$(search_api_version) \
		search_api_ranges-$(search_api_ranges_version) \
		search_api_solr-$(search_api_solr_version) \
		strongarm-$(strongarm_version) \
		token-$(token_version) \
		viewreference-$(viewreference_version) \
		views-$(views_version) \
		views_data_export-$(views_data_export_version)

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
	$(call drupal-git-checkout-module,http_client, 0)
	$(call drupal-git-checkout-module,feeds, 0)
	$(call drupal-git-patch-module,references, 0)
	$(call drupal-git-patch-module-file,menu_firstchild, 1)
	
drupal-module-patch:
	$(call drupal-git-patch-module,search_api_ranges, 1)
	$(call drupal-patch-module-file,sites/all/modules/search_api_ranges/search_api_ranges.module,MICA-206-ranges-block-title-truncated.patch)
	$(call drupal-patch-module-file,sites/all/modules/search_api_ranges/search_api_ranges.module,MICA-207-hide-ranges-block-when-min-equals-max.patch)
	
drupal-core-patch:
	$(call drupal-patch-module-file,modules/block/block.module,MICA-205-block-info-test.patch)
	
drupal-install-clients: jsonpath-php-client solr-php-client

jsonpath-php-client:
	cd target/$(micadir)/sites/all/modules/feeds_jsonpath_parser && \
	wget http://jsonpath.googlecode.com/files/jsonpath-0.8.1.php
	
solr-php-client:
	cd target/$(micadir) && \
	rm -rf sites/all/modules/search_api_solr/SolrPhpClient && \
	wget -q -r -R index.html,wiki -P tmp http://solr-php-client.googlecode.com/svn/\!svn/bc/$(solr-php-client-version)/trunk/ && \
	mv tmp/solr-php-client.googlecode.com/svn/\!svn/bc/$(solr-php-client-version)/trunk/ sites/all/modules/search_api_solr/SolrPhpClient && \
	rm -rf tmp

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