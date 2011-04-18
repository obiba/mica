#
# Mica Makefile
# Requires drush 4+ to be installed: http://drush.ws/
#

version=1.0-SNAPSHOT
micadir=mica-$(version)

#
# Modules dependencies
#
drupal_version=7.0
ctools_version=7.x-1.0-alpha4
email_version=7.x-1.0-beta1
name_version=7.x-1.0-beta1
field_group_version=7.x-1.0-rc2
link_version=7.x-1.0-alpha3
entity_version=7.x-1.0-beta8
views_version=7.x-3.x-dev
search_api_version=7.x-1.0-beta8
search_api_solr_version=7.x-1.x-dev
features_version=7.x-1.0-beta2
strongarm_version=7.x-2.0-beta2
references_version=7.x-2.x-dev

#
# Mysql db access
#
db_user=root
db_pass=rootadmin

#
# Your site
#
site_db_name=mica_site
site_name=MicaSite
site_dir_name=site.mica-obiba.org

#
# Clean urls: 0/1
#
clean_url=0

all: drupal mica package

target:
	mkdir -p target

drupal: target
	cd target && \
	drush dl drupal-$(drupal_version) --drupal-project-rename=$(micadir) && \
	cd $(micadir) && \
	drush dl advanced_help panels ctools-$(ctools_version) && \
	drush dl email-$(email_version) name-$(name_version) field_group-$(field_group_version) link-$(link_version) && \
	drush dl entity-$(entity_version) views-$(views_version) && \
	drush dl search_api-$(search_api_version) search_api_solr-$(search_api_solr_version) && \
	svn checkout -r22 http://solr-php-client.googlecode.com/svn/trunk/ sites/all/modules/search_api_solr/SolrPhpClient && \
	drush dl features-$(features_version) strongarm-$(strongarm_version) && \
	drush dl references-$(references_version)

mica:
	cd target/$(micadir) && \
	cp -r ../../mica-profiles/mica_standard profiles && \
	cp -r ../../mica-modules/mica sites/all/modules && \
	cp -r ../../mica-modules/mica_feature sites/all/modules && \
	rm -rf `find . -type d -name .svn`

package:
	cd target && \
	rm -f $(micadir).tar.gz && \
	tar czf $(micadir).tar.gz $(micadir)

default-site:
	cd target/$(micadir) && \
	drush site-install mica_standard --db-url=mysql://$(db_user):$(db_pass)@localhost/mica --site-name=Mica --clean-url=$(clean_url) --yes

site:
	cd target/$(micadir) && \
	drush site-install mica_standard --db-url=mysql://$(db_user):$(db_pass)@localhost/$(site_db_name) --site-name=$(site_name) --sites-subdir=$(site_dir_name) --clean-url=$(clean_url)

demo:
	cd target/$(micadir) && \
	drush dl node_export-7.x-3.x-dev && drush en --yes node_export && \
	drush ne-import --file=sites/all/modules/mica/data/mica-demo.txt

clean:
	rm -rf target

help:
	@echo "Mica version $(version)"
	@echo
	@echo "Available make targets:"
	@echo "  all          : Download Drupal, required modules, install Mica modules/profiles and make a package of it."
	@echo "  package      : Package Drupal for Mica ($(micadir).tar.gz)."
	@echo "  default-site : Install default site with Mica profile."
	@echo "  site         : Install configured site with Mica profile."
	@echo "  mica         : Install Mica modules/profiles in Drupal."
	@echo "  clean        : Remove target directory."
	@echo
	@echo "Requires drush 4+ to be installed [http://drush.ws]"
	@echo "  " `drush version`
	@echo
