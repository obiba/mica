#
# Mica Makefile
# Requires drush 4+ to be installed: http://drush.ws/
#

version=1.0-SNAPSHOT
mica_version=7.x-1.0-dev
mica_feature_version=7.x-1.0-dev
mica_addons_version=7.x-1.0-dev
mica_minimal_version=7.x-1.0-dev
mica_standard_version=7.x-1.0-dev
mica_demo_version=7.x-1.0-dev
mica_samara_version=7.x-1.0-dev

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
site_account_name=admin         
site_account_pass=admin

#
# Clean urls: 0/1
#
clean_url=0

#
# Build
#

all: target drupal mica

target:
	mkdir -p target

#
# Drupal Build
#

drupal: drupal-download solr-php-client drupal-default 

drupal-download:
	cd target && \
	drush dl drupal-$(drupal_version) --drupal-project-rename=$(micadir) && \
	cd $(micadir) && \
	drush dl advanced_help panels ctools-$(ctools_version) && \
	drush dl email-$(email_version) name-$(name_version) field_group-$(field_group_version) link-$(link_version) && \
	drush dl entity-$(entity_version) views-$(views_version) && \
	drush dl search_api-$(search_api_version) search_api_solr-$(search_api_solr_version) search_api_ranges-${search_api_ranges_version} && \
	drush dl features-$(features_version) strongarm-$(strongarm_version) && \
	drush dl references-$(references_version) field_permissions-${field_permissions_version} relation-${relation_version} && \
	drush dl date-$(date_version) calendar-$(calendar_version) && \
	drush dl login_destination-$(login_destination_version) && \
	drush dl views_data_export-$(views_data_export_version) noderefcreate-$(noderefcreate_version) multiselect-$(multiselect_version) job_scheduler-$(job_scheduler_version) feeds-$(feeds_version) && \
	drush dl node_export-$(node_export_version)

solr-php-client:
	cd target/$(micadir) && \
	rm -rf sites/all/modules/search_api_solr/SolrPhpClient && \
	wget -q -r -R index.html,wiki -P tmp http://solr-php-client.googlecode.com/svn/\!svn/bc/22/trunk/ && \
	mv tmp/solr-php-client.googlecode.com/svn/\!svn/bc/22/trunk/ sites/all/modules/search_api_solr/SolrPhpClient
	rm -rf tmp

drupal-default:
	cd target/$(micadir) && \
	chmod a+w sites/default && \
	mkdir sites/default/files && \
	chmod a+w sites/default/files && \
	cp sites/default/default.settings.php sites/default/settings.php && \
	chmod a+w sites/default/settings.php && \
	chmod +x scripts/*.sh

#
# Mica Build
#

mica: mica-install mica-versions

mica-install:
	cd target/$(micadir) && \
	cp -r ../../mica-profiles/* profiles && \
	cp -r ../../mica-modules/* sites/all/modules && \
	cp -r ../../mica-themes/* sites/all/themes && \
	rm -rf `find . -type d -name .svn`

mica-versions: mica-versions-profiles mica-versions-themes mica-versions-modules

mica-versions-profiles:
	$(call make-version,profiles,mica_minimal)
	$(call make-version,profiles,mica_standard)
	$(call make-version,profiles,mica_demo)
	
mica-versions-themes:
	$(call make-version,sites/all/themes,mica_samara) 

mica-versions-modules:
	$(call make-version,sites/all/modules,mica)
	$(call make-version,sites/all/modules,mica_feature)
	$(call make-version,sites/all/modules,mica_addons)

#
# Deploy
#

deploy: debian package

#
# Package
#

package: package-modules package-profiles package-themes
	cd target && \
	rm -f $(micadir).* && \
	tar czf $(micadir).tar.gz $(micadir) && \
	zip -r $(micadir).zip $(micadir)

package-modules:
	$(call make-package,sites/all/modules,mica)
	$(call make-package,sites/all/modules,mica_feature)
	$(call make-package,sites/all/modules,mica_addons)
	
package-profiles:
	$(call make-package,profiles,mica_minimal)
	$(call make-package,profiles,mica_standard)
	$(call make-package,profiles,mica_demo)

package-themes:
	$(call make-package,sites/all/themes,mica_samara)

#
# Debian Package
#

debian: deb-prepare deb	
	cd target/deb && debuild -us -uc -b
	
deb-prepare:
	rm -rf target/deb
	mkdir -p target/deb/debian
	mkdir -p target/deb/var/lib/mica/backups
	mkdir -p target/deb/var/lib/mica/files
	mkdir -p target/deb/usr/share/doc/mica
	mkdir -p target/deb/usr/share
	mkdir -p target/deb/etc/mica/sites
	
deb: deb-install deb-profiles deb-sites deb-doc deb-changelog
	
deb-install:
	cp -r target/$(micadir) target/deb/usr/share/mica
	cp src/main/deb/debian/* target/deb/debian
	cp src/main/deb/etc/mica/* target/deb/etc/mica
	
deb-profiles:
	mv target/deb/usr/share/mica/profiles target/deb/etc/mica/
	rm -rf target/deb/etc/mica/profiles/minimal target/deb/etc/mica/profiles/testing
	ln -s /etc/mica/profiles target/deb/usr/share/mica/profiles

deb-sites:
	mv target/deb/usr/share/mica/sites/default target/deb/etc/mica/sites
	ln -s /etc/mica/sites/default target/deb/usr/share/mica/sites/default
	mv target/deb/usr/share/mica/sites/*.php target/deb/etc/mica/sites
	
deb-doc:
	mv target/deb/usr/share/mica/*.txt target/deb/usr/share/doc/mica
	mv target/deb/usr/share/doc/mica/robots.txt target/deb/usr/share/mica

deb-changelog:
	echo "mica ($(deb_version)) unstable; urgency=low" > target/deb/debian/changelog
	echo "" >> target/deb/debian/changelog
	echo "  * See http://wiki.obiba.org/ for more details." >> target/deb/debian/changelog
	echo "" >> target/deb/debian/changelog
	echo " -- OBiBa <info@obiba.org>  $(deb_date)" >> target/deb/debian/changelog

#
# Site
#

default-site:
	cd target/$(micadir) && \
	drush site-install mica_standard --db-url=mysql://$(db_user):$(db_pass)@localhost/mica --site-name=Mica --clean-url=$(clean_url) --yes

site:
	cd target/$(micadir) && \
	drush site-install mica_standard --db-url=mysql://$(db_user):$(db_pass)@localhost/$(site_db_name) --site-name=$(site_name) --sites-subdir=$(site_dir_name) --clean-url=$(clean_url) --account-name=$(site_account_name) --account-pass=$(site_account_pass)

demo-site:
	cd target/$(micadir) && \
	drush site-install mica_demo --db-url=mysql://$(db_user):$(db_pass)@localhost/mica --site-name=Mica --clean-url=$(clean_url) --yes && \
	drush ne-import --file=profiles/mica_demo/data/mica-demo.txt

demo-export:
	cd target/$(micadir) && \
	drush ne-export 2 3 4 5 -u 1 --file=../mica-demo.txt
	
#
# Devel
#

coder:
	cd target/$(micadir) && \
	drush dl coder && \
 	drush en coder* --yes

git: git-prepare git-modules git-themes git-modules

git-prepare:
	rm -rf target/git && mkdir -p target/git

git-modules: 
	$(call make-git,mica-modules,mica,sandbox/emorency/1128690)
	$(call make-git,mica-modules,mica_feature,sandbox/emorency/1128676)
	$(call make-git,mica-modules,mica_addons,sandbox/yop/1144682)

git-themes: 
	$(call make-git,mica-themes,mica_samara,sandbox/yop/1144820)
	
git-profiles:
	$(call make-git,mica-profiles,mica_minimal,sandbox/yop/1144812)
	$(call make-git,mica-profiles,mica_standard,sandbox/yop/1144814)
	$(call make-git,mica-profiles,mica_demo,sandbox/yop/1144816)

#
# Misc
#

clean:
	rm -rf target

help:
	@echo "Mica version $(version)"
	@echo
	@echo "Available make targets:"
	@echo "  all          : Download Drupal, required modules and install Mica modules/profiles in it. Result is available in 'target' directory."
	@echo "  package      : Package Drupal for Mica ($(micadir).tar.gz)."
	@echo "  default-site : Install default site with Mica profile."
	@echo "  site         : Install configured site with Mica profile."
	@echo "  mica         : Install Mica modules/profiles in Drupal."
	@echo "  clean        : Remove 'target' directory."
	@echo
	@echo "Requires drush 4+ to be installed [http://drush.ws]"
	@echo "  " `drush version`
	@echo

	
#
# Functions
#

# make-version function: add version number to project info file
make-version = cd target/$(micadir)/$(1) && \
	echo "version = \"$($(2)_version)\"" >> $2/$2.info 

# make-package function: build tar.gz and zip files of a project
make-package = cd target/$(micadir)/$(1) && \
	tar czvf $(2)-$($(2)_version).tar.gz $(2) && \
	zip -r $(2)-$($(2)_version).zip $(2) && \
	cd - && \
	mv target/$(micadir)/$(1)/*.tar.gz target && \
	mv target/$(micadir)/$(1)/*.zip target 

# make-git function: propagate svn changes to git
make-git = cd target/git && \
	git svn clone http://svn.obiba.org/mica/trunk/$(1)/$(2) $(2) && \
	cd $(2) && \
	git remote add origin $(git_user)@git.drupal.org:$(3) && \
	git pull --rebase origin master && \
	git push origin master

#
# Variables (not to be overridden)
#

micadir=mica-$(version)
build_number=$(shell svnversion -n | cut -d : -f 1)
deb_version=$(version)-b$(build_number)
deb_date=$(shell date -R)