#
# Mica Drupal Makefile
# Requires drush 4+ to be installed: http://drush.ws/
#

#
# Modules dependencies
#
acl_version=7.x-1.0-beta3
calendar_version=7.x-2.0-alpha1
chain_menu_access_version=7.x-1.0-beta2
collapsiblock_version=7.x-1.0
#content_access_version=7.x-1.x-dev
ctools_version=7.x-1.0-beta1
date_version=7.x-2.0-alpha3
drupal_version=7.2
email_version=7.x-1.0-beta1
entity_version=7.x-1.0-beta8
features_version=7.x-1.0-beta2
#feeds_version=7.x-2.x-dev
feeds_jsonpath_parser_version=7.x-1.0-beta2
field_group_version=7.x-1.0-rc2
field_permissions_version=7.x-1.0-alpha1
forum_access_version=7.x-1.0-alpha4
google_fonts_version=7.x-2.1
job_scheduler_version=7.x-2.0-alpha2
link_version=7.x-1.0-alpha3
login_destination_version=7.x-1.0-beta1
multiselect_version=7.x-1.8
name_version=7.x-1.0-beta1
noderefcreate_version=7.x-1.0
relation_version=7.x-1.0-alpha2
search_api_solr_version=7.x-1.0-beta2
search_api_version=7.x-1.0-beta8
strongarm_version=7.x-2.0-beta2
views_data_export_version=7.x-3.0-beta4
views_version=7.x-3.0-beta3
viewreference_version=7.x-3.0


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

#
# Drupal Build
#

drupal: drupal-prepare drupal-download drupal-forks drupal-stable-dev drupal-install-clients drupal-default 

drupal-prepare:
	mkdir -p target

drupal-download:
	cd target && \
	$(drushexec) dl drupal-$(drupal_version) --drupal-project-rename=$(micadir) && \
	cd $(micadir) && \
	$(drushexec) dl advanced_help panels ctools-$(ctools_version) && \
	$(drushexec) dl email-$(email_version) name-$(name_version) field_group-$(field_group_version) link-$(link_version) && \
	$(drushexec) dl entity-$(entity_version) views-$(views_version) && \
	$(drushexec) dl search_api-$(search_api_version) search_api_solr-$(search_api_solr_version) && \
	$(drushexec) dl features-$(features_version) strongarm-$(strongarm_version) && \
	$(drushexec) dl feeds_jsonpath_parser-$(feeds_jsonpath_parser_version) && \
	$(drushexec) dl field_permissions-$(field_permissions_version) relation-$(relation_version) && \
	$(drushexec) dl collapsiblock-$(collapsiblock_version) && \
	$(drushexec) dl date-$(date_version) calendar-$(calendar_version) && \
	$(drushexec) dl login_destination-$(login_destination_version) noderefcreate-$(noderefcreate_version) && \
	$(drushexec) dl viewreference-$(viewreference_version) && \
	$(drushexec) dl views_data_export-$(views_data_export_version) multiselect-$(multiselect_version) job_scheduler-$(job_scheduler_version) && \
	$(drushexec) dl acl-$(acl_version) chain_menu_access-$(chain_menu_access_version) forum_access-$(forum_access_version) && \
	$(drushexec) dl google_fonts-$(google_fonts_version)

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


drupal-forks:	
	cp -r forks/* target/$(micadir)/sites/all/modules

drupal-stable-dev:
	$(call drupal-checkout-module,http_client)
	$(call drupal-checkout-module,feeds)
	$(call drupal-patch-module,references)
	
drupal-install-clients: jsonpath-php-client solr-php-client

jsonpath-php-client:
	cd target/$(micadir)/sites/all/modules/feeds_jsonpath_parser && \
	wget http://jsonpath.googlecode.com/files/jsonpath-0.8.1.php
	
solr-php-client:
	cd target/$(micadir) && \
	rm -rf sites/all/modules/search_api_solr/SolrPhpClient && \
	wget -q -r -R index.html,wiki -P tmp http://solr-php-client.googlecode.com/svn/\!svn/bc/22/trunk/ && \
	mv tmp/solr-php-client.googlecode.com/svn/\!svn/bc/22/trunk/ sites/all/modules/search_api_solr/SolrPhpClient && \
	rm -rf tmp

drupal-default:
	cd target/$(micadir) && \
	chmod a+w sites/default && \
	mkdir sites/default/files && \
	chmod a+w sites/default/files && \
	cp sites/default/default.settings.php sites/default/settings.php && \
	chmod a+w sites/default/settings.php && \
	chmod +x scripts/*.sh

drupal-patch-module = $(call drupal-checkout-module,$(1)) && \
	wget -O - $($(1)_patch) | git apply -p0	

# drupal-checkout-module function: checkout a specific module version using git
drupal-checkout-module = cd target/$(micadir)/sites/all/modules && \
	rm -rf $(1) && \
	git clone http://git.drupal.org/project/$(1).git && \
	cd $(1) && \
	git checkout $($(1)_revision)
