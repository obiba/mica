#
# Mica Makefile
# Requires drush 5+ to be installed: http://drush.ws
#

version=4.4
branch=7.x-4.x

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
mica_distribution_version=$(mica_version)
mica_demo_version=$(mica_version)

# Themes
mica_samara_version=$(mica_version)

#
# Mysql db access
#
db_user=root
db_pass=1234

all: help

help:
	@echo "Mica version $(version)"
	@echo
	@echo "Available make targets:"
	@echo "  dev (default)      : Download Drupal, required modules and install Mica local dev version modules/profiles in it. Result is available in 'target' directory."
	@echo "  prod               : Download Drupal, required modules and install Mica $(version) modules/profiles in it. Result is available in 'target' directory."
	@echo "  package            : Package Drupal for Mica ($(micadir).tar.gz), Mica modules and make a Mica installer Debian package."
	@echo
	@echo "  git-push-mica      : Clone Drupal.org Mica Git repository, add current files, commit and push them."
	@echo "  git-push-mica-dist : Clone Drupal.org Mica Distribution Git repository, add current files, commit and push them."
	@echo
	@echo "  clean              : Remove 'target' directory."
	@echo
	@echo "  prepare-local      : Download Drupal and required modules to temp folder to avoid downloading everything from drupal.org for faster builds."
	@echo "  local              : Create a complete Mica Distribution with local Mica files based on previously downloaded Drupal and required modules (with target prepare-local)."
	@echo "                       This avoid downloading everything from drupal.org for faster builds "
	@echo
	@echo "  mica-install       : Copy Mica files from 'src' to distribution built in 'target' directory."
	@echo "  mica-install-clear : Copy Mica files from 'src' to distribution built in 'target' directory and clear all caches."
	@echo
	@echo "  dump               : Exports the Drupal DB as SQL using mysqldump."
	@echo
	@echo "  deploy             : Used by continuous integration server to copy packaged distribution to stable (for prod) or unstable (for dev)."
	@echo "                       http://ci.obiba.org/view/Mica/job/Mica"
	@echo
	@echo "Requires drush 5+ to be installed [http://drush.ws]"
	@echo "  " `drush version`
	@echo


#
# Build
#

prod: drush-make-prod prepare-mica-distribution htaccess

dev: drush-make-dev mica-install prepare-mica-distribution inject-version-info set-distribution-version htaccess

drush-make-prod:
	drush make --prepare-install src/main/drupal/profiles/mica_distribution/build-mica_distribution.make target/$(micadir) && \
	chmod -R a+w target/$(micadir)/sites/default

drush-make-dev:
	$(call drush-make-dev,$(micadir))

mica-install:
	rm -rf target/$(micadir)/profiles/mica_distribution/modules/mica && \
	cp -R src/main/drupal/modules target/$(micadir)/profiles/mica_distribution && \
	cp -R src/main/drupal/themes target/$(micadir)/profiles/mica_distribution && \
	cp -R src/main/drupal/profiles/mica_distribution target/$(micadir)/profiles && \
	make inject-version-info

prepare-mica-distribution: 
	cp src/main/drupal/themes/mica_samara/mica.png target/$(micadir)/themes/seven/logo.png && \
	cp src/main/drupal/themes/mica_samara/favicon.ico target/$(micadir)/misc/favicon.ico && \
	rm -rf target/$(micadir)/profiles/minimal target/$(micadir)/profiles/standard target/$(micadir)/profiles/testing

htaccess:
	cp target/$(micadir)/.htaccess target/$(micadir)/.htaccess_bak && \
	sed '/# RewriteBase \/drupal/ a RewriteBase \/mica' target/$(micadir)/.htaccess > target/$(micadir)/.htaccess_new && \
	mv target/$(micadir)/.htaccess_new target/$(micadir)/.htaccess 

inject-version-info:
	$(call inject-version-info,mica_distribution/modules/mica/extensions,mica_community)
	$(call inject-version-info,mica_distribution/modules/mica/extensions,mica_core)
	$(call inject-version-info,mica_distribution/modules/mica/extensions,mica_data_access)
	$(call inject-version-info,mica_distribution/modules/mica/extensions,mica_datasets)
	$(call inject-version-info,mica_distribution/modules/mica/extensions/mica_datasets,mica_category_field)
	$(call inject-version-info,mica_distribution/modules/mica/extensions,mica_datashield)
	$(call inject-version-info,mica_distribution/modules/mica/extensions,mica_devel)
	$(call inject-version-info,mica_distribution/modules/mica/extensions,mica_field_description)
	$(call inject-version-info,mica_distribution/modules/mica/extensions,mica_networks)
	$(call inject-version-info,mica_distribution/modules/mica/extensions,mica_node_reference_field)
	$(call inject-version-info,mica_distribution/modules/mica/extensions,mica_opal)
	$(call inject-version-info,mica_distribution/modules/mica/extensions/mica_opal,mica_opal_view)
	$(call inject-version-info,mica_distribution/modules/mica/extensions,mica_projects)
	$(call inject-version-info,mica_distribution/modules/mica/extensions,mica_relation)
	$(call inject-version-info,mica_distribution/modules/mica/extensions,mica_studies)
	$(call inject-version-info,mica_distribution/modules/mica/extensions,node_reference_block)
	$(call inject-version-info,mica_distribution/modules,mica)
	$(call inject-version-info,,mica_distribution)
	$(call inject-version-info,mica_distribution/themes,mica_samara)

clear-version-info:
	$(call clear-version-info,src/main/drupal/modules/mica/extensions,mica_community)
	$(call clear-version-info,src/main/drupal/modules/mica/extensions,mica_core)
	$(call clear-version-info,src/main/drupal/modules/mica/extensions,mica_data_access)
	$(call clear-version-info,src/main/drupal/modules/mica/extensions,mica_datasets)
	$(call clear-version-info,src/main/drupal/modules/mica/extensions/mica_datasets,mica_category_field)
	$(call clear-version-info,src/main/drupal/modules/mica/extensions,mica_datashield)
	$(call clear-version-info,src/main/drupal/modules/mica/extensions,mica_devel)
	$(call clear-version-info,src/main/drupal/modules/mica/extensions,mica_field_description)
	$(call clear-version-info,src/main/drupal/modules/mica/extensions,mica_networks)
	$(call clear-version-info,src/main/drupal/modules/mica/extensions,mica_node_reference_field)
	$(call clear-version-info,src/main/drupal/modules/mica/extensions,mica_opal)
	$(call clear-version-info,src/main/drupal/modules/mica/extensions/mica_opal,mica_opal_view)
	$(call clear-version-info,src/main/drupal/modules/mica/extensions,mica_projects)
	$(call clear-version-info,src/main/drupal/modules/mica/extensions,mica_relation)
	$(call clear-version-info,src/main/drupal/modules/mica/extensions,mica_studies)
	$(call clear-version-info,src/main/drupal/modules/mica/extensions,node_reference_block)
	$(call clear-version-info,src/main/drupal/modules,mica)
	$(call clear-version-info,src/main/drupal/profiles,mica_distribution)
	$(call clear-version-info,src/main/drupal/profiles,mica_demo)
	$(call clear-version-info,src/main/drupal/themes,mica_samara)

set-distribution-version:
	cd src/main/drupal/profiles/mica_distribution && \
	sed -i 's/^projects\[mica\].*$$/projects[mica] = $(version)/' drupal-org.make && \
	sed -i 's/^projects\[mica_distribution\]\[download\]\[branch\].*$$/projects[mica_distribution][download][branch] = 7.x-$(version)/' build-mica_distribution.make


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
# Deploy
#

deploy: package deploy-mica deploy-mica-solr

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
package: debian
	rm -f target/mica-dist*
	cd target && \
	tar czf mica-dist-$(deb_version).tar.gz $(micadir) && \
	zip -qr mica-dist-$(deb_version).zip $(micadir)


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
	$(call deb-package,mica,mica_distribution)
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
	mysqldump -u $(db_user) --password=$(db_pass) --hex-blob mica --result-file="target/mica.sql"
	@echo ">>> Database dumped to target/mica.sql"


#
# Local make: avoid downloading everything from drupal.org for faster builds
#
# - Run mica-local-prepare to download drupal core and all modules in a temp folder
# - Run mica-local to build Mica with local drupal distribution
#

prepare-local:
	rm -rf target/$(micadir)-local && \
	$(call drush-make-dev,$(micadir)-local) 

local: local-copy mica-install prepare-mica-distribution htaccess

local-copy:
	rm -rf target/$(micadir) && \
	cp -r target/$(micadir)-local target/$(micadir)

#
# Misc
#

clean:
	rm -rf target

#
# Push to Drupal.org
#
git-push-mica: clear-version-info
	$(call git-prepare,$(drupal_org_mica),mica) . && \
	cp -r ../../../src/main/drupal/modules/mica/* . && \
	$(call git-finish)

git-push-mica-dist: clear-version-info set-distribution-version
	$(call git-prepare,$(drupal_org_mica_dist),mica_distribution) . && \
	cp -r ../../../src/main/drupal/profiles/mica_distribution/* . && \
	cp -r ../../../src/main/drupal/themes . && \
	$(call git-finish)


#
# Functions
#

# inject-version-info-version function: remove (if present) and add specified version number to project info file
inject-version-info = cd target/$(micadir)/profiles/$(1) && \
	sed -i "/^version/d" $2/$2.info && \
	sed -i "/^project/d" $2/$2.info && \
	sed -i "/^datestamp/d" $2/$2.info && \
	sed -i "/Information added by obiba.org packaging script/d" $2/$2.info && \
	echo "; Information added by obiba.org packaging script on $(deb_date)" >> $2/$2.info && \
	echo "version = $($(2)_version)" >> $2/$2.info && \
	echo "project = $2" >> $2/$2.info && \
	echo "datestamp = $(datestamp)" >> $2/$2.info

# clear-version-info function: remove (if present) version number from project info file
clear-version-info = sed -i "/^version/d" $(1)/$2/$2.info && \
	sed -i "/^project/d" $(1)/$2/$2.info && \
	sed -i "/^datestamp/d" $(1)/$2/$2.info && \
	sed -i "/Information added by obiba.org packaging script/d" $(1)/$2/$2.info

drush-make-dev = drush make --prepare-install src/main/drupal/profiles/mica_distribution/drupal-org-core.make target/$(1) && \
	rm -rf target/$(1)-no-core && \
	drush make --no-core src/main/drupal/profiles/mica_distribution/drupal-org.make target/$(1)-no-core && \
	mv target/$(1)-no-core/sites/all target/$(1)/profiles/mica_distribution && \
	rm -rf target/$(1)-no-core && \
	chmod -R a+w target/$(1)/sites/default

# deb-package: echo the modules versions in debian Makefile
deb-package = echo "$(2)_version=$($(2)_version)" >> target/deb/$(1)/var/lib/$(1)-installer/Makefile

#git-prepare: checkout git repo $(1) to target $(2) and delete all files from this repo
git-prepare = rm -rf target/drupal.org && \
	mkdir -p target/drupal.org && \
	echo "Enter Drupal username?" && \
	read git_username && \
	git clone --recursive --branch $(branch) $$git_username@$(1) target/drupal.org/$(2) && \
	cd target/drupal.org/$(2) && \
	git rm -rf *

#git-finish: sanitize, add, commit and push all files to Git
git-finish = rm `find . -type f -name LICENSE.txt` && \
	rm `find . -type f -name COPYRIGHT.txt` && \
	rm -rf translations && \
	git add . && \
	git status && \
	echo "Enter a message for this commit?" && \
	read git_commit_msg && \
	git commit -m "$$git_commit_msg" && \
	git push origin && \
	cd ../../..

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
drupal_org_mica=git.drupal.org:project/mica.git
drupal_org_mica_dist=git.drupal.org:project/mica_distribution.git
