#
# Mica Makefile
# Requires drush 4+ to be installed: http://drush.ws/
#


version=1.0-SNAPSHOT

#
# Mica Modules
#
mica_version=7.x-1.0-dev
mica_studies_version=7.x-1.0-dev
mica_community_version=7.x-1.0-dev
mica_standard_version=7.x-1.0-dev
mica_demo_version=7.x-1.0-dev
mica_samara_version=7.x-1.0-dev


#
# Forked Modules
#
http_client_version=7.x-2.x-dev-mica
feeds_version=7.x-2.x-dev-mica
references_version=7.x-2.0-beta3-mica
search_api_ranges_version=7.x-1.x-dev-mica
noderefcreate_version=7.x-1.0-beta2-mica
menu_firstchild_version=7.x-1.0-mica
content_access_version=7.x-1.x-dev-mica

#
# Mysql db access
#
db_user=root
db_pass=rootadmin

#
# Build
#

all: drupal mica

#
# Include drupal targets
#
include includes/drupal.mk

#
# Mica Build
#

mica: mica-install

mica-install:
	cd target/$(micadir) && \
	cp -r ../../mica-profiles/* profiles && \
	cp -r ../../mica-modules/mica sites/all/modules && \
	cp -r ../../mica-themes/* sites/all/themes && \
	rm -rf `find . -type d -name .svn` && \
	rm -rf `find . -type d -name .git` && \
	if [ -e profiles/standard/standard.install ]; then \
		cp profiles/standard/standard.install profiles/mica_standard/standard.install && \
		rm -rf profiles/standard && \
		rm -rf profiles/minimal ; \
	fi

#
# Deploy
#

deploy: package
ifeq ($(findstring SNAPSHOT,$(version)),SNAPSHOT)
	cp target/*.deb /var/www/pkg/unstable
	cp target/*.zip /var/www/mica/unstable
	cp target/*.tar.gz /var/www/mica/unstable
else
	cp target/*.deb /var/www/pkg/stable
	cp target/*.zip /var/www/mica/stable
	cp target/*.tar.gz /var/www/mica/stable
endif

#
# Package
#

package: package-modules package-profiles package-themes package-forks debian
	rm -f target/mica-dist*
	cd target && \
	tar czf mica-dist-$(deb_version).tar.gz $(micadir) && \
	zip -qr mica-dist-$(deb_version).zip $(micadir)

package-modules: package-module-mica
	$(call make-package,sites/all/modules,mica)
	
package-profiles: package-profile-mica_standard package-profile-mica_demo

package-themes: package-theme-mica_samara

package-forks: package-module-content_access package-module-feeds package-module-http_client package-module-menu_firstchild package-module-noderefcreate package-module-references package-module-search_api_ranges

package-module-%: 
	$(call make-info,sites/all/modules,$*)
	$(call make-package,sites/all/modules,$*)

package-profile-%: 
	$(call make-info,profiles,$*)
	$(call make-package,profiles,$*)

package-theme-%: 
	$(call make-info,sites/all/themes,$*)
	$(call make-package,sites/all/themes,$*)

package-clean:
	rm -f target/*.zip && rm -f target/*.gz && rm -f target/*.deb

#
# Debian Package
#

# for testing (deb is not signed)
debuild_opts=-us -uc
#debuild_opts=

debian: deb-prepare deb	
	cd target/deb && debuild $(debuild_opts) -b
	
deb-prepare:
	rm -rf target/deb
	mkdir -p target/deb/debian
	mkdir -p target/deb/usr/share/doc/mica
	mkdir -p target/deb/usr/share
	mkdir -p target/deb/etc/mica/sites
	mkdir -p target/deb/var/lib/mica-installer
	
deb: deb-install deb-changelog
	
deb-install:
	cp src/main/deb/debian/* target/deb/debian
	cp src/main/deb/etc/mica/* target/deb/etc/mica
	cp src/main/deb/var/lib/mica-installer/* target/deb/var/lib/mica-installer
	echo "version=$(version)" >> target/deb/var/lib/mica-installer/Makefile
	echo "deb_version=$(deb_version)" >> target/deb/var/lib/mica-installer/Makefile
ifeq ($(findstring SNAPSHOT,$(version)),SNAPSHOT)
	echo "stability=unstable" >> target/deb/var/lib/mica-installer/Makefile
else
	echo "stability=stable" >> target/deb/var/lib/mica-installer/Makefile
endif
	mkdir -p target/deb/var/cache/mica-installer
	$(call deb-package,mica)
	$(call deb-package,mica_standard)
	$(call deb-package,mica_demo)
	$(call deb-package,mica_samara)

deb-changelog:
	echo "mica ($(deb_version)) unstable; urgency=low" > target/deb/debian/changelog
	echo "" >> target/deb/debian/changelog
	echo "  * See http://wiki.obiba.org/ for more details." >> target/deb/debian/changelog
	echo "" >> target/deb/debian/changelog
	echo " -- OBiBa <info@obiba.org>  $(deb_date)" >> target/deb/debian/changelog

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
	$(call make-git,mica-modules,mica,sandbox/emorency/1128690)

git-themes: 
	$(call make-git,mica-themes,mica_samara,sandbox/yop/1144820)
	
git-profiles:
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

# make-info function: add version number to project info file
make-info = cd target/$(micadir)/$(1) && \
	echo "\n\n; Information added by obiba.org packaging script on $(deb_date)" >> $2/$2.info && \
	echo "version = \"$($(2)_version)\"" >> $2/$2.info && \
	echo "datestamp = \"$(datestamp)\"" >> $2/$2.info

# make-package function: build tar.gz and zip files of a project
make-package = cd target/$(micadir)/$(1) && \
	tar --exclude-vcs -czf $(2)-$($(2)_version).tar.gz $(2) && \
	zip -qr $(2)-$($(2)_version).zip $(2) && \
	cd - && \
	mv target/$(micadir)/$(1)/*.tar.gz target && \
	mv target/$(micadir)/$(1)/*.zip target 

# deb-package: echo the modules versions in debian Makefile
deb-package = echo "$(1)_version=$($(1)_version)" >> target/deb/var/lib/mica-installer/Makefile

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
