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
content_access_version=7.x-1.x-dev
ctools_version=7.x-1.0-alpha4
date_version=7.x-2.0-alpha3
drupal_version=7.2
email_version=7.x-1.0-beta1
entity_version=7.x-1.0-beta8
features_version=7.x-1.0-beta2
feeds_version=7.x-2.0-alpha3
field_group_version=7.x-1.0-rc2
field_permissions_version=7.x-1.0-alpha1
forum_access_version=7.x-1.0-alpha4
job_scheduler_version=7.x-2.0-alpha2
link_version=7.x-1.0-alpha3
login_destination_version=7.x-1.0-beta1
multiselect_version=7.x-1.8
name_version=7.x-1.0-beta1
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

#
# Drupal Build
#

drupal: drupal-prepare drupal-download drupal-forks drupal-stable-dev solr-php-client drupal-default 

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
	$(drushexec) dl feeds-$(feeds_version) && \
	$(drushexec) dl field_permissions-$(field_permissions_version) relation-$(relation_version) && \
	$(drushexec) dl collapsiblock-$(collapsiblock_version) && \
	$(drushexec) dl date-$(date_version) calendar-$(calendar_version) && \
	$(drushexec) dl login_destination-$(login_destination_version) && \
	$(drushexec) dl viewreference-$(viewreference_version) && \
	$(drushexec) dl views_data_export-$(views_data_export_version) multiselect-$(multiselect_version) job_scheduler-$(job_scheduler_version) && \
	$(drushexec) dl acl-$(acl_version) chain_menu_access-$(chain_menu_access_version) forum_access-$(forum_access_version)
	
drupal-examples:
	cd target/$(micadir) && \
	$(drushexec) dl examples

drupal-en:
	cd target/$(micadir) && \
	$(drushexec) en --yes $(module)

drupal-dis:
	cd target/$(micadir) && \
	$(drushexec) pm-disable --yes $(module)	

drupal-forks:	
	cp -r forks/* target/$(micadir)/sites/all/modules

drupal-stable-dev:
	$(call drupal-checkout-module,http_client)

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
	
# drupal-checkout-module function: checkout a specific module version using git
drupal-checkout-module = cd target/$(micadir)/sites/all/modules && \
	rm -rf $(1) && \
	git clone -b $($(1)_branch) http://git.drupal.org/project/$(1).git && \
	cd $(1) && \
	git checkout $($(1)_revision) && \
	git status

