#
# Mica Drupal Makefile
# Requires drush 4+ to be installed: http://drush.ws/
#

#
# Modules dependencies
#
calendar_version=7.x-2.0-alpha1
ctools_version=7.x-1.0-alpha4
date_version=7.x-2.0-alpha3
drupal_version=7.0
email_version=7.x-1.0-beta1
entity_version=7.x-1.0-beta8
features_version=7.x-1.0-beta2
feeds_version=7.x-2.0-alpha3
field_group_version=7.x-1.0-rc2
field_permissions_version=7.x-1.0-alpha1
job_scheduler_version=7.x-2.0-alpha2
link_version=7.x-1.0-alpha3
login_destination_version=7.x-1.0-beta1
multiselect_version=7.x-1.8
name_version=7.x-1.0-beta1
node_export_version=7.x-3.x-dev
noderefcreate_version=7.x-1.0-beta2
references_version=7.x-2.x-dev
relation_version=7.x-1.0-alpha2
search_api_ranges_version=7.x-1.x-dev
search_api_solr_version=7.x-1.x-dev
search_api_version=7.x-1.0-beta8
strongarm_version=7.x-2.0-beta2
views_data_export_version=7.x-3.0-beta4
views_version=7.x-3.x-dev

#
# Drupal Build
#

drupal: drupal-prepare drupal-download solr-php-client drupal-default 

drupal-prepare:
	mkdir -p target

drupal-download:
	cd target && \
	$(drushexec) dl drupal-$(drupal_version) --drupal-project-rename=$(micadir) && \
	cd $(micadir) && \
	$(drushexec) dl advanced_help panels ctools-$(ctools_version) && \
	$(drushexec) dl email-$(email_version) name-$(name_version) field_group-$(field_group_version) link-$(link_version) && \
	$(drushexec) dl entity-$(entity_version) views-$(views_version) && \
	$(drushexec) dl search_api-$(search_api_version) search_api_solr-$(search_api_solr_version) search_api_ranges-${search_api_ranges_version} && \
	$(drushexec) dl features-$(features_version) strongarm-$(strongarm_version) && \
	$(drushexec) dl references-$(references_version) field_permissions-${field_permissions_version} relation-${relation_version} && \
	$(drushexec) dl date-$(date_version) calendar-$(calendar_version) && \
	$(drushexec) dl login_destination-$(login_destination_version) && \
	$(drushexec) dl views_data_export-$(views_data_export_version) noderefcreate-$(noderefcreate_version) multiselect-$(multiselect_version) job_scheduler-$(job_scheduler_version) feeds-$(feeds_version) && \
	$(drushexec) dl node_export-$(node_export_version)

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
	
