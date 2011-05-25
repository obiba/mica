#
# Mica Installer Makefile
# Requires drush 4+ to be installed: http://drush.ws/
#

oldversion=
micadir=mica
installdir=/usr/share
drushexec=/var/cache/mica-installer/drush/drush

#
# Mysql db access
#
db_user=mica
db_pass=

#
# Drush install
#

all: drush

drush:
	@echo "**** Drush install"
	if [ ! -e $(drushexec) ]; then \
	  cd /var/cache/mica-installer && \
	  wget -q http://ftp.drupal.org/files/projects/drush-7.x-4.4.tar.gz && \
	  tar xzf drush-7.x-4.4.tar.gz ; \
	fi
	$(drushexec) version

#
# Install
#

install: 
ifndef oldversion
	@echo "**** Mica distribution install" 
	make mica-dist-install
else
	@echo "**** Mica modules/themes/profiles upgrade" 
	make mica-install
endif

#
# Mica dist install
#

mica-dist-install: mica-dist-install-prepare drupal-profiles drupal-sites drupal-doc

mica-dist-install-prepare:
	mkdir -p target	
	cd target && \
	wget -q http://download.obiba.org/mica/$(stability)/mica-dist-$(deb_version).tar.gz && \
	tar xzf mica-dist-$(deb_version).tar.gz && \
	mv $(micadir)-$(version) mica && \
	mv mica /usr/share

drupal-profiles:
	mv /usr/share/mica/profiles/* /etc/mica/profiles && \
	rmdir /usr/share/mica/profiles && \
	ln -s /etc/mica/profiles /usr/share/mica/profiles

drupal-sites:
	mv /usr/share/mica/sites/default/* /etc/mica/sites/default && \
	rmdir /usr/share/mica/sites/default && \
	mv /usr/share/mica/sites/* /etc/mica/sites/ && \
	rmdir /usr/share/mica/sites && \
	ln -s /etc/mica/sites /usr/share/mica/sites
	if [ ! -e /etc/mica/sites/default/settings.php ]; then \
		cd /etc/mica/sites/default && \
		cp default.settings.php settings.php && \
		chmod a+w settings.php ; \
	fi
	
drupal-doc:
	mv /usr/share/mica/*.txt /usr/share/doc/mica
	mv /usr/share/doc/mica/robots.txt /usr/share/mica	

#
# Mica install
#
	
mica-install:
	mkdir -p target	
	$(call make-sites-install,themes,mica_samara)
	$(call make-sites-install,modules,mica)
	$(call make-profiles-install,mica_minimal)
	$(call make-profiles-install,mica_standard)
	$(call make-profiles-install,mica_demo)

#
# Clean
#

clean:
	rm -rf target
	rm -rf /var/cache/mica-installer/*.gz

#
# Functions
#

make-sites-install = cd target && \
	wget -q http://download.obiba.org/mica/$(stability)/$(2)-$($(2)_version).tar.gz && \
	tar xzf $(2)-$($(2)_version).tar.gz && \
	rm -rf /usr/share/mica/sites/all/$(1)/$(2) && \
	mv $(2) /usr/share/mica/sites/all/$(1)
	
make-profiles-install = cd target && \
	wget -q http://download.obiba.org/mica/$(stability)/$(1)-$($(1)_version).tar.gz && \
	tar xzf $(1)-$($(1)_version).tar.gz && \
	rm -rf /usr/share/mica/profiles/$(1) && \
	mv $(1) /usr/share/mica/profiles

#
# Versions
#

