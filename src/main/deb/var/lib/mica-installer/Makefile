#
# Mica Installer Makefile
# Requires drush 4+ to be installed: http://drush.ws/
#

include drupal.mk

version=1.0-dev

micadir=mica
installdir=/tmp/mica-install

drushexec=$(installdir)/var/cache/mica-installer/drush/drush

all: drush drupal

drush:
	mkdir -p $(installdir)/var/cache/mica-installer
	cd $(installdir)/var/cache/mica-installer && \
	wget -q http://ftp.drupal.org/files/projects/drush-7.x-4.4.tar.gz && \
	tar xzf drush-7.x-4.4.tar.gz
	$(drushexec) version

install: install-prepare drupal-install drupal-profiles drupal-sites drupal-doc mica-install

install-prepare: 
	mkdir -p $(installdir)/usr/share/mica
	mkdir -p $(installdir)/usr/share/doc/mica
	mkdir -p $(installdir)/etc/mica/sites

drupal-install:
	rm -rf target/$(micadir)/profiles/minimal target/$(micadir)/profiles/testing
	cp -r target/$(micadir)/* $(installdir)/usr/share/mica

drupal-profiles:
	mv $(installdir)/usr/share/mica/profiles $(installdir)/etc/mica/
	ln -s $(installdir)/etc/mica/profiles $(installdir)/usr/share/mica/profiles

drupal-sites:
	mv $(installdir)/usr/share/mica/sites/default $(installdir)/etc/mica/sites
	ln -s $(installdir)/etc/mica/sites/default $(installdir)/usr/share/mica/sites/default
	mv $(installdir)/usr/share/mica/sites/*.php $(installdir)/etc/mica/sites
	
drupal-doc:
	mv $(installdir)/usr/share/mica/*.txt $(installdir)/usr/share/doc/mica
	mv $(installdir)/usr/share/doc/mica/robots.txt $(installdir)/usr/share/mica
	
mica-install:
	$(call make-sites-install,themes,mica_samara)
	$(call make-sites-install,modules,mica)
	$(call make-sites-install,modules,mica_feature)
	$(call make-sites-install,modules,mica_addons)
	$(call make-profiles-install,mica_minimal)
	$(call make-profiles-install,mica_standard)
	$(call make-profiles-install,mica_demo)
	
clean:
	rm -rf target
	
#
# Functions
#

make-sites-install = cd $(installdir)/var/cache/mica-installer && \
	wget -q http://ci.obiba.org/job/Mica/ws/target/$(2)-$($(2)_version).tar.gz && \
	tar xzf $(2)-$($(2)_version).tar.gz && \
	mv $(2) $(installdir)/usr/share/mica/sites/all/$(1)
	
make-profiles-install = cd $(installdir)/var/cache/mica-installer && \
	wget -q http://ci.obiba.org/job/Mica/ws/target/$(1)-$($(1)_version).tar.gz && \
	tar xzf $(1)-$($(1)_version).tar.gz && \
	mv $(1) $(installdir)/etc/mica/profiles

#
# Modules versions
#

