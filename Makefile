#
# Mica Makefile
# Requires drush 4+ to be installed: http://drush.ws/
#

include drupal.mk

version=1.0-SNAPSHOT
mica_version=7.x-1.0-dev
mica_feature_version=7.x-1.0-dev
mica_addons_version=7.x-1.0-dev
mica_minimal_version=7.x-1.0-dev
mica_standard_version=7.x-1.0-dev
mica_demo_version=7.x-1.0-dev
mica_samara_version=7.x-1.0-dev

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

all: drupal mica

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

deploy: package
	cp target/*.deb /var/www/deb/stable

deploy-unstable: package
	cp target/*.deb /var/www/deb/unstable

#
# Package
#

package: package-modules package-profiles package-themes debian
	cd target && \
	rm -f $(micadir).* && \
	tar czf $(micadir).tar.gz $(micadir) && \
	zip -qr $(micadir).zip $(micadir)

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
	mkdir -p target/deb/usr/share/doc/mica
	mkdir -p target/deb/usr/share
	mkdir -p target/deb/etc/mica/sites
	mkdir -p target/deb/var/lib/mica-installer
	
deb: deb-install deb-changelog
	
deb-install:
	cp src/main/deb/debian/* target/deb/debian
	cp src/main/deb/etc/mica/* target/deb/etc/mica
	cp src/main/deb/var/lib/mica-installer/* target/deb/var/lib/mica-installer
	echo "version=$(deb_version)" >> target/deb/var/lib/mica-installer/Makefile
	cp drupal.mk target/deb/var/lib/mica-installer
	mkdir -p target/deb/var/cache/mica-installer
	$(call deb-package,mica)
	$(call deb-package,mica_feature)
	$(call deb-package,mica_addons)
	$(call deb-package,mica_minimal)
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
	@echo "  package      : Package Drupal for Mica ($(micadir).tar.gz), Mica modules and make a Mica installer Debian package."
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
	tar czf $(2)-$($(2)_version).tar.gz $(2) && \
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
drushexec=drush
