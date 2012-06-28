#
# Mica Makefile
# Requires drush 5+ to be installed: http://drush.ws/
#

version=1.5-dev

#
# Mica versions
#
# Modules
mica_version=7.x-$(version)
mica_category_field_version=$(mica_version)
mica_community_version=$(mica_version)
mica_core_version=$(mica_version)
mica_data_access_version=$(mica_version)
mica_datasets_version=$(mica_version)
mica_datashield_version=$(mica_version)
mica_devel_version=$(mica_version)
mica_field_description_version=$(mica_version)
mica_networks_version=$(mica_version)
mica_node_reference_field_version=$(mica_version)
mica_opal_version=$(mica_version)
mica_opal_view_version=$(mica_version)
mica_projects_version=$(mica_version)
mica_relation_version=$(mica_version)
mica_studies_version=$(mica_version)
node_reference_block_version=$(mica_version)

# Profiles
mica_standard_version=$(mica_version)
mica_demo_version=$(mica_version)

# Themes
mica_samara_version=$(mica_version)

#
# Mysql db access
#
db_user=root
db_pass=1234

#
# Build
#

all: drupal mica package-prepare htaccess

drupal-settings:
	echo "ini_set('max_execution_time', 0);" >> target/$(micadir)/sites/default/default.settings.php
	echo "ini_set('max_execution_time', 0);" >> target/$(micadir)/sites/default/settings.php

#
# Build from continuous integration
#

ci-update: default-backup ci-build default-restore

ci-build:
	mkdir -p target && \
	cd target/ && \
	rm -rf $(micadir) && \
	rm -f $(micadir).zip && \
	wget http://ci.obiba.org/view/Mica/job/Mica/ws/mica/target/$(micadir)/*zip*/$(micadir).zip && \
	unzip $(micadir).zip

default-backup:
	cd target/ && \
	cp -r $(micadir)/sites/default/ .

default-restore:
	cd target/ && \
	cp -r default $(micadir)/sites

#
# Drupal targets
#
drupal: drush-make drupal-default 

drush-make:
	$(drushmake_exec) mica.make target/$(micadir)

drupal-default:
	cd target/$(micadir) && \
	chmod a+r sites/all/modules/services/servers/rest_server/lib/spyc.php && \
	chmod a+w sites/default && \
	mkdir sites/default/files && \
	chmod a+w sites/default/files && \
	cp sites/default/default.settings.php sites/default/settings.php && \
	chmod a+w sites/default/settings.php && \
	chmod +x scripts/*.sh

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

#
# Mica Build
#
mica: mica-install
	cp src/main/drupal/themes/mica_samara/mica.png target/$(micadir)/themes/seven/logo.png
	cp src/main/drupal/themes/mica_samara/favicon.ico target/$(micadir)/misc/favicon.ico

mica-install:
	cd target/$(micadir) && \
	cp -r ../../src/main/drupal/profiles/* profiles && \
	cp -r ../../src/main/drupal/modules/mica sites/all/modules && \
	cp -r ../../src/main/drupal/themes/* sites/all/themes && \
	rm -rf `find . -type d -name .svn` && \
	rm -rf `find . -type d -name .git` && \
	if [ -e profiles/standard/standard.install ]; then \
#		cp profiles/standard/standard.install profiles/mica_standard/standard.install && \
		rm -rf profiles/standard && \
		rm -rf profiles/minimal ; \
	fi

mica-link: mica
	rm -rf $(CURDIR)/target/$(micadir)/sites/all/modules/mica && \
	ln -s $(CURDIR)/src/main/drupal/modules/* $(CURDIR)/target/$(micadir)/sites/all/modules

htaccess:
	cp target/$(micadir)/.htaccess target/$(micadir)/.htaccess_bak
	sed '/# RewriteBase \/drupal/ a RewriteBase \/mica' target/$(micadir)/.htaccess > target/$(micadir)/.htaccess_new
	mv target/$(micadir)/.htaccess_new target/$(micadir)/.htaccess 


#
# Deploy
#

deploy: package deploy-mica

deploy-mica:
ifeq ($(findstring dev,$(version)),dev)
	cp target/deb/mica_*.deb /var/www/pkg/unstable
	cp target/*.zip /var/www/download/mica/unstable
	cp target/*.tar.gz /var/www/download/mica/unstable
else
	cp target/deb/mica_*.deb /var/www/pkg/stable
	cp target/*.zip /var/www/download/mica/stable
	cp target/*.tar.gz /var/www/download/mica/stable
endif

deploy-mica-solr:
ifeq ($(findstring dev,$(version)),dev)
	cp target/deb/mica-solr_*.deb /var/www/pkg/unstable
else
	cp target/deb/mica-solr_*.deb /var/www/pkg/stable
endif

#
# Package
#
package: package-prepare debian
	rm -f target/mica-dist*
	cd target && \
	tar czf mica-dist-$(deb_version).tar.gz $(micadir) && \
	zip -qr mica-dist-$(deb_version).zip $(micadir)

package-prepare: package-modules-prepare package-profiles-prepare package-themes-prepare

package-modules-prepare:
	$(call make-info,sites/all/modules/mica/extensions,mica_community)
	$(call make-info,sites/all/modules/mica/extensions,mica_core)
	$(call make-info,sites/all/modules/mica/extensions,mica_data_access)
	$(call make-info,sites/all/modules/mica/extensions,mica_datasets)
	$(call make-info,sites/all/modules/mica/extensions/mica_datasets,mica_category_field)
	$(call make-info,sites/all/modules/mica/extensions,mica_datashield)
	$(call make-info,sites/all/modules/mica/extensions,mica_devel)
	$(call make-info,sites/all/modules/mica/extensions,mica_field_description)
	$(call make-info,sites/all/modules/mica/extensions,mica_networks)
	$(call make-info,sites/all/modules/mica/extensions,mica_node_reference_field)
	$(call make-info,sites/all/modules/mica/extensions,mica_opal)
	$(call make-info,sites/all/modules/mica/extensions/mica_opal,mica_opal_view)
	$(call make-info,sites/all/modules/mica/extensions,mica_projects)
	$(call make-info,sites/all/modules/mica/extensions,mica_relation)
	$(call make-info,sites/all/modules/mica/extensions,mica_studies)
	$(call make-info,sites/all/modules/mica/extensions,node_reference_block)
	$(call make-info,sites/all/modules,mica)

package-profiles-prepare:
	$(call make-info,profiles,mica_standard)
	$(call make-info,profiles,mica_demo)

package-themes-prepare:
	$(call make-info,sites/all/themes,mica_samara)


#
# Debian Package
#

# for testing (deb is not signed)
debuild_opts=-us -uc

debian: deb-prepare deb	
	cd target/deb/mica && debuild $(debuild_opts) -b
	cd target/deb/mica-solr && debuild $(debuild_opts) -b
	
deb-prepare:
	rm -rf target/deb
	cp -r src/main/deb target
	rm -rf `find target/deb -type d -name .svn`

deb: deb-mica deb-mica-solr

deb-mica: deb-mica-install deb-mica-changelog

deb-mica-solr: deb-mica-solr-install deb-mica-solr-changelog

deb-mica-install:
	echo "version=$(version)" >> target/deb/mica/var/lib/mica-installer/Makefile
	echo "deb_version=$(deb_version)" >> target/deb/mica/var/lib/mica-installer/Makefile
ifeq ($(findstring dev,$(version)),dev)
	echo "stability=unstable" >> target/deb/mica/var/lib/mica-installer/Makefile
else
	echo "stability=stable" >> target/deb/mica/var/lib/mica-installer/Makefile
endif
	$(call deb-package,mica,mica)
	$(call deb-package,mica,mica_standard)
	$(call deb-package,mica,mica_demo)
	$(call deb-package,mica,mica_samara)

deb-mica-solr-install:
	echo "version=$(version)" >> target/deb/mica-solr/var/lib/mica-solr-installer/Makefile
	echo "deb_version=$(deb_version)" >> target/deb/mica-solr/var/lib/mica-solr-installer/Makefile
ifeq ($(findstring dev,$(version)),dev)
	echo "stability=unstable" >> target/deb/mica-solr/var/lib/mica-solr-installer/Makefile
else
	echo "stability=stable" >> target/deb/mica-solr/var/lib/mica-solr-installer/Makefile
endif
	$(call deb-package,mica-solr,mica)

deb-mica-changelog:
ifeq ($(findstring dev,$(version)),dev)
	echo "mica ($(deb_version)) unstable; urgency=low" > target/deb/mica/debian/changelog
else
	echo "mica ($(deb_version)) stable; urgency=low" > target/deb/mica/debian/changelog
endif
	echo "" >> target/deb/mica/debian/changelog
	echo "  * See http://wiki.obiba.org/ for more details." >> target/deb/mica/debian/changelog
	echo "" >> target/deb/mica/debian/changelog
	echo " -- OBiBa <info@obiba.org>  $(deb_date)" >> target/deb/mica/debian/changelog

deb-mica-solr-changelog:
ifeq ($(findstring dev,$(version)),dev)
	echo "mica-solr ($(deb_version)) unstable; urgency=low" > target/deb/mica-solr/debian/changelog
else
	echo "mica-solr ($(deb_version)) stable; urgency=low" > target/deb/mica-solr/debian/changelog
endif
	echo "" >> target/deb/mica-solr/debian/changelog
	echo "  * See http://wiki.obiba.org/ for more details." >> target/deb/mica-solr/debian/changelog
	echo "" >> target/deb/mica-solr/debian/changelog
	echo " -- OBiBa <info@obiba.org>  $(deb_date)" >> target/deb/mica-solr/debian/changelog

#
# Site
#

installdir=target

mica-site:
	cd target/$(micadir) && \
	$(drushexec) site-install mica_standard --db-url=mysql://$(db_user):$(db_pass)@localhost/mica --site-name=Mica --yes

mica-dev-site: mica-site
	$(drushexec) en mica_devel --y

demo-site:
	cd target/$(micadir) && \
	$(drushexec) site-install mica_demo --db-url=mysql://$(db_user):$(db_pass)@localhost/mica --site-name=Mica --clean-url=$(clean_url) --yes && \
	$(drushexec) ne-import --file=profiles/mica_demo/data/mica-demo.txt

demo-export:
	cd target/$(micadir) && \
	$(drushexec) ne-export 2 3 4 5 -u 1 --file=../mica-demo.txt

#
# Devel
#

mica-install-clear: mica-install
	cd target/$(micadir) && \
	drush cc all && \
	cd ../..

coder:
	cd target/$(micadir) && \
	drush dl coder && \
	drush dl grammar_parser_lib && \
 	drush en coder* --yes

dump:
	mysqldump -u $(db_user) --password=$(db_pass) --hex-blob mica --result-file="mica.sql" 

git: git-prepare git-modules git-themes git-profiles

git-prepare:
	rm -rf target/git && mkdir -p target/git

git-modules: 
	$(call make-git,src/main/drupal/modules,mica,sandbox/emorency/1128690)

git-themes: 
	$(call make-git,src/main/drupal/themes,mica_samara,sandbox/yop/1144820)

git-profiles:
	$(call make-git,src/main/drupal/profiles,mica_standard,sandbox/yop/1144814)
	$(call make-git,src/main/drupal/profiles,mica_demo,sandbox/yop/1144816)


#
# Local make: avoid downloading everything from drupal.org for faster builds
#
# - Run mica-local-prepare to download drupal core and all modules in a temp folder
# - Run mica-local to build Mica with local drupal ditribution
#

mica-local-prepare:
	rm -rf target/$(micadir)-local && \
	$(drushmake_exec) mica.make target/$(micadir)-local

mica-local: mica-local-copy drupal-default mica package-prepare htaccess

mica-local-link: mica-local-copy drupal-default mica-link package-prepare htaccess

mica-local-copy:
	rm -rf target/$(micadir) && \
	cp -r target/$(micadir)-local target/$(micadir)


#
# Misc
#

clean:
	rm -rf target

help:
	@echo "Mica version $(version)"
	@echo
	@echo "Available make targets:"
	@echo "  all                : Download Drupal, required modules and install Mica modules/profiles in it. Result is available in 'target' directory."
	@echo "  package            : Package Drupal for Mica ($(micadir).tar.gz), Mica modules and make a Mica installer Debian package."
	@echo "  mica               : Install Mica modules/profiles in Drupal."
	@echo "  clean              : Remove 'target' directory."
	@echo "  mica-install-clear : Copy Mica files from 'src' to 'target' directory and clear all caches."
	@echo
	@echo "Requires drush 4+ to be installed [http://drush.ws]"
	@echo "  " `drush version`
	@echo

#
# Release to Drupal.org
#
release: release-mica release-mica-dist

release-mica:
	rm -rf target/drupal.org && \
	mkdir -p target/drupal.org && \
	git clone $(drupal_org_mica) target/drupal.org/mica && \
	cd target/drupal.org/mica && \
	git rm -rf * && \
	cp -r ../../../src/main/drupal/modules/mica/* . && \
	git add . && \
	git commit -m "Release Mica $(version)" && \
	cd ../../..

release-mica-dist:
	rm -rf target/drupal.org && \
	mkdir -p target/drupal.org && \
	git clone $(drupal_org_mica_dist) target/drupal.org/mica_dist && \
	cd target/drupal.org/mica_dist && \
	git rm -rf * && \
	cp -r ../../../src/main/drupal/profiles/mica_standard/* . && \
	cp -r ../../../src/main/drupal/themes . && \
	git add . && \
	git commit -m "Release Mica Distribution $(version)" && \
	cd ../../..


#
# Functions
#

# make-info function: add default version number to project info file
make-info = $(call make-info-version,$(1),$(2),$($(2)_version))

# make-info-version function: remove (if present) and add specified version number to project info file
make-info-version = cd target/$(micadir)/$(1) && \
	sed -i "/version/d" $2/$2.info && \
	sed -i "/datestamp/d" $2/$2.info && \
	sed -i "/Information added by obiba.org packaging script/d" $2/$2.info && \
	echo "\n\n; Information added by obiba.org packaging script on $(deb_date)" >> $2/$2.info && \
	echo "version = \"$(3)\"" >> $2/$2.info && \
	echo "datestamp = \"$(datestamp)\"" >> $2/$2.info

# make-package function: build tar.gz and zip files of a project
make-package = cd target/$(micadir)/$(1) && \
	tar --exclude-vcs -czf $(2)-$($(2)_version).tar.gz $(2) && \
	zip -qr $(2)-$($(2)_version).zip $(2) && \
	cd - && \
	mv target/$(micadir)/$(1)/*.tar.gz target && \
	mv target/$(micadir)/$(1)/*.zip target 

# deb-package: echo the modules versions in debian Makefile
deb-package = echo "$(2)_version=$($(2)_version)" >> target/deb/$(1)/var/lib/$(1)-installer/Makefile

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
ifeq ($(findstring dev,$(version)),dev)
	deb_version=$(subst -dev,,$(version))-b$(shell git describe --match build_number | cut -d - -f2)
else
	deb_version=$(version)
endif
deb_date=$(shell date -R)
datestamp=$(shell date +%s)
drushexec=drush
drushmake_exec=drush make
drupal_org_mica=/home/cthiebault/workspace/mica-drupal/mica
drupal_org_mica_dist=/home/cthiebault/workspace/mica-drupal/mica_dist
