#
# Mica Makefile
# Requires drush 4+ to be installed: http://drush.ws/
#

version=1.1-SNAPSHOT

#
# Mica versions
#
# Modules
mica_version=7.x-1.1-dev
mica_community_version=$(mica_version)
mica_data_access_version=$(mica_version)
mica_datasets_version=$(mica_version)
mica_dataschemas_version=$(mica_version)
mica_datashield_version=$(mica_version)
mica_node_reference_field_version=$(mica_version)
mica_opal_version=$(mica_version)
mica_projects_version=$(mica_version)
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
db_pass=rootadmin

#
# Build
#

all: drupal mica
	echo "ini_set('max_execution_time', 0);" >> target/$(micadir)/sites/default/default.settings.php
	echo "ini_set('max_execution_time', 0);" >> target/$(micadir)/sites/default/settings.php

#
# Include drupal targets
#
include includes/drupal.mk

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
		cp profiles/standard/standard.install profiles/mica_standard/standard.install && \
		rm -rf profiles/standard && \
		rm -rf profiles/minimal ; \
	fi
	
htaccess:
	cp target/$(micadir)/.htaccess target/$(micadir)/.htaccess_bak
	sed '/# RewriteBase \/drupal/ a RewriteBase \/mica' target/$(micadir)/.htaccess > target/$(micadir)/.htaccess_new
	mv target/$(micadir)/.htaccess_new target/$(micadir)/.htaccess 
	
#
# Deploy
#

deploy: package
ifeq ($(findstring SNAPSHOT,$(version)),SNAPSHOT)
	cp target/deb/*.deb /var/www/pkg/unstable
	cp target/*.zip /var/www/download/mica/unstable
	cp target/*.tar.gz /var/www/download/mica/unstable
else
	cp target/deb/*.deb /var/www/pkg/stable
	cp target/*.zip /var/www/download/mica/stable
	cp target/*.tar.gz /var/www/download/mica/stable
endif

#
# Package
#

#package: package-modules package-profiles package-themes package-forks debian
package: package-prepare debian
	rm -f target/mica-dist*
	cd target && \
	tar czf mica-dist-$(deb_version).tar.gz $(micadir) && \
	zip -qr mica-dist-$(deb_version).zip $(micadir)

package-prepare: package-modules-prepare package-profiles-prepare package-themes-prepare package-forks-prepare

package-modules-prepare:
	$(call make-info,sites/all/modules/mica/extensions,mica_community)
	$(call make-info,sites/all/modules/mica/extensions,mica_data_access)
	$(call make-info,sites/all/modules/mica/extensions,mica_datasets)
	$(call make-info,sites/all/modules/mica/extensions,mica_dataschemas)
	$(call make-info,sites/all/modules/mica/extensions,mica_datashield)
	$(call make-info,sites/all/modules/mica/extensions,mica_node_reference_field)
	$(call make-info,sites/all/modules/mica/extensions,mica_opal)
	$(call make-info,sites/all/modules/mica/extensions,mica_projects)
	$(call make-info,sites/all/modules/mica/extensions,mica_studies)
	$(call make-info,sites/all/modules/mica/extensions,node_reference_block)
	$(call make-info,sites/all/modules,mica)
	
package-modules:
	$(call make-package,sites/all/modules,mica)

package-profiles-prepare:
	$(call make-info,profiles,mica_standard)
	$(call make-info,profiles,mica_demo)

package-profiles:

package-themes-prepare:
	$(call make-info,sites/all/themes,mica_samara)
	
package-themes:

package-forks-prepare:
	$(call make-info-version,sites/all/modules,feeds,$(feeds_branch)-mica)
	$(call make-info-version,sites/all/modules,http_client,$(http_client_branch)-mica)
	$(call make-info-version,sites/all/modules,menu_firstchild,$(menu_firstchild_revision)-mica)
	$(call make-info-version,sites/all/modules,references,$(references_revision)-mica)
	$(call make-info-version,sites/all/modules,search_api_ranges,$(search_api_ranges_revision)-mica)
	
package-forks:
	$(call make-package,sites/all/modules,feeds)
	$(call make-package,sites/all/modules,http_client)
	$(call make-package,sites/all/modules,menu_firstchild)
	$(call make-package,sites/all/modules,references)
	$(call make-package,sites/all/modules,search_api_ranges)

package-clean:
	rm -f target/*.zip && rm -f target/*.gz && rm -f target/*.deb

#
# Debian Package
#

# for testing (deb is not signed)
debuild_opts=-us -uc
#debuild_opts=

debian: deb-prepare deb	
	cd target/deb/mica && debuild $(debuild_opts) -b
	cd target/deb/mica-solr && debuild $(debuild_opts) -b
	
deb-prepare:
	rm -rf target/deb
	cp -r src/main/deb target
	rm -rf `find target/deb -type d -name .svn`
	
deb: deb-install deb-changelog
	
deb-install:
	echo "version=$(version)" >> target/deb/mica/var/lib/mica-installer/Makefile
	echo "deb_version=$(deb_version)" >> target/deb/mica/var/lib/mica-installer/Makefile
	echo "version=$(version)" >> target/deb/mica-solr/var/lib/mica-solr-installer/Makefile
	echo "deb_version=$(deb_version)" >> target/deb/mica-solr/var/lib/mica-solr-installer/Makefile
ifeq ($(findstring SNAPSHOT,$(version)),SNAPSHOT)
	echo "stability=unstable" >> target/deb/mica/var/lib/mica-installer/Makefile
	echo "stability=unstable" >> target/deb/mica-solr/var/lib/mica-solr-installer/Makefile
else
	echo "stability=stable" >> target/deb/mica/var/lib/mica-installer/Makefile
	echo "stability=stable" >> target/deb/mica-solr/var/lib/mica-solr-installer/Makefile
endif
	$(call deb-package,mica,mica)
	$(call deb-package,mica,mica_standard)
	$(call deb-package,mica,mica_demo)
	$(call deb-package,mica,mica_samara)
	$(call deb-package,mica-solr,mica)

deb-changelog:
	echo "mica ($(deb_version)) unstable; urgency=low" > target/deb/mica/debian/changelog
	echo "" >> target/deb/mica/debian/changelog
	echo "  * See http://wiki.obiba.org/ for more details." >> target/deb/mica/debian/changelog
	echo "" >> target/deb/mica/debian/changelog
	echo " -- OBiBa <info@obiba.org>  $(deb_date)" >> target/deb/mica/debian/changelog
	echo "mica-solr ($(deb_version)) unstable; urgency=low" > target/deb/mica-solr/debian/changelog
	echo "" >> target/deb/mica-solr/debian/changelog
	echo "  * See http://wiki.obiba.org/ for more details." >> target/deb/mica-solr/debian/changelog
	echo "" >> target/deb/mica-solr/debian/changelog
	echo " -- OBiBa <info@obiba.org>  $(deb_date)" >> target/deb/mica-solr/debian/changelog

#
# Site
#

installdir=target

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

coder:
	cd target/$(micadir) && \
	drush dl coder && \
 	drush en coder* --yes

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
# Misc
#

clean:
	rm -rf target

help:
	@echo "Mica version $(version)"
	@echo
	@echo "Available make targets:"
	@echo "  all          : Download Drupal, required modules and install Mica modules/profiles in it. Result is available in 'target' directory."
	@echo "  package      : Package Drupal for Mica ($(micadir).tar.gz), Mica modules and make a Mica installer Debian package."
	@echo "  mica         : Install Mica modules/profiles in Drupal."
	@echo "  clean        : Remove 'target' directory."
	@echo
	@echo "Requires drush 4+ to be installed [http://drush.ws]"
	@echo "  " `drush version`
	@echo

	
#
# Functions
#

# make-info function: add default version number to project info file
make-info = $(call make-info-version,$(1),$(2),$($(2)_version))
	
# make-info-version function: add specified version number to project info file
make-info-version = cd target/$(micadir)/$(1) && \
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
build_number=$(shell svnversion -n | cut -d : -f 1)
deb_version=$(version)-b$(build_number)
deb_date=$(shell date -R)
datestamp=$(shell date +%s)
drushexec=drush
