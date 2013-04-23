#
# Mica Installer Makefile
# Requires drush 5+ to be installed: http://drush.ws/
#

oldversion=
micadir=mica
installdir=/usr/share
backupdir=/var/lib/mica-installer/backups/mica-$(oldversion)
drushexec=/var/cache/mica-installer/drush/drush
ifeq (exists, $(shell [ -d /usr/share/mica/sites/all/modules/mica ] && echo exists))
	module_in_sites_all=true
else
	module_in_sites_all=false
endif

#
# Mysql db access
#
db_user=mica
db_pass=

#
# Drush install
#

drush_version=5.8

all: 

drush:
	@echo "**** Drush install"
	if [ ! -e $(drushexec) ]; then \
	  cd /var/cache/mica-installer && \
	  wget http://ftp.drupal.org/files/projects/drush-$(drupal_version)-$(drush_version).tar.gz && \
	  tar xzf drush-$(drupal_version)-$(drush_version).tar.gz ; \
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
	@echo "**** Mica core/modules/themes/profiles upgrade from $(oldversion)"
	make mica-prepare-update
endif

#
# Mica dist install
#

mica-dist-install: mica-dist-install-prepare drupal-profiles drupal-sites drupal-doc

mica-dist-install-prepare:
	@echo "**** Download Mica archive"
	mkdir -p /var/cache/mica-installer/target && \
	cd /var/cache/mica-installer/target && \
	wget -q http://ftp.drupal.org/files/projects/mica_distribution-$(drupal_version)-$(dist_version)-core.tar.gz && \
	#cp ${HOME}/projects/mica/target/mica_distribution-$(drupal_version)-$(dist_version).tar.gz mica_distribution-$(drupal_version)-$(dist_version)-core.tar.gz && \
	tar xzf mica_distribution-$(drupal_version)-$(dist_version)-core.tar.gz && \
	mv mica_distribution-$(drupal_version)-$(dist_version) mica && \
	rm -rf mica/profiles/minimal && \
	rm -rf mica/profiles/standard && \
	rm -rf mica/profiles/testing && \
	chown -R root:www-data mica && \
	mv mica /usr/share

drupal-profiles:
	@echo "**** Prepare Mica profile"
	mv /usr/share/mica/profiles/* /etc/mica/profiles && \
	rmdir /usr/share/mica/profiles && \
	ln -s /etc/mica/profiles /usr/share/mica/profiles

drupal-sites:
	@echo "**** Prepare Mica site"
	mkdir -p /etc/mica/sites/default && \
	mv /usr/share/mica/sites/default/* /etc/mica/sites/default && \
	rmdir /usr/share/mica/sites/default && \
	mv /usr/share/mica/sites/* /etc/mica/sites/ && \
	rmdir /usr/share/mica/sites && \
	ln -s /etc/mica/sites /usr/share/mica/sites && \
	mkdir -p /etc/mica/sites/default/files && \
	cp -r /etc/mica/sites/default/files /var/lib/mica/default && \
	rm -rf /etc/mica/sites/default/files && \
	ln -s /var/lib/mica/default/files /etc/mica/sites/default/files && \
	chmod a+w /var/lib/mica/default/files && \
	if [ ! -e /etc/mica/sites/default/settings.php ]; then \
		cp /etc/mica/sites/default/default.settings.php /etc/mica/sites/default/settings.php ; \
	fi
	chmod a+w /etc/mica/sites/default/settings.php

drupal-doc:
	mv /usr/share/mica/*.txt /usr/share/doc/mica
	mv /usr/share/doc/mica/robots.txt /usr/share/mica	


#
# Mica prepare update
#
include mica-1.1-update.mk
include mica-1.2-update.mk
include mica-1.3-update.mk
include mica-1.4-update.mk
include mica-5.x-update.mk
include mica-6.x-update.mk
include mica-7.x-update.mk

mica-prepare-update: drush mica-maintenance-mode-on mica-backup mica-delete mica-copy-user-files delete-core mica-dist-install mica-restore-user-data mica-clear-tmp-update mica-echo-update

mica-maintenance-mode-on:
	@echo "**** Set site in maintenance mode"
	cd /usr/share/mica/sites/default && \
	$(drushexec) vset --always-set maintenance_mode 1

mica-backup:
	@echo "**** Backup database and files"
	mkdir -p $(backupdir)	 && \
	cp -rL /usr/share/mica $(backupdir) && \
	tar czf mica-$(oldversion).tar.gz $(backupdir)/mica && \
	cd /usr/share/mica/sites/default && \
	$(drushexec) sql-dump --gzip --result-file=$(backupdir)/mica-$(oldversion).sql

mica-delete:
	@echo "**** Delete Mica files"
	$(call make-delete-mica-files,$(dist_version))

make-delete-mica-files = make mica-delete-$(1)

mica-copy-user-files:
	@echo "**** Copy user files"
	rm -rf /var/cache/mica-installer/update && \
	mkdir -p /var/cache/mica-installer/update && \
	cp /usr/share/mica/.htaccess /var/cache/mica-installer/update && \
	cp -rL /usr/share/mica/profiles /var/cache/mica-installer/update && \
	cp -rL /usr/share/mica/sites /var/cache/mica-installer/update && \
	rm -rf /var/cache/mica-installer/update/sites/default/files && \
	cp -rL /var/lib/mica/default/files /var/cache/mica-installer/update && \
	cp -L /etc/mica/sites/default/settings.php /var/cache/mica-installer/update

delete-core:
	@echo "**** Delete Drupal core" 
	rm -rf /usr/share/mica && \
	rm -rf /etc/mica/profiles/* && \
	rm -rf /etc/mica/sites/*

mica-restore-user-data:	mica-restore-user-config mica-restore-user-profiles mica-restore-user-sites mica-restore-user-files

mica-restore-user-config:	
	@echo "**** Restore user files" 
	cp /var/cache/mica-installer/update/.htaccess /usr/share/mica && \
	cp /var/cache/mica-installer/update/settings.php /etc/mica/sites/default/settings.php

mica-restore-user-profiles:	
	if [ $(find /var/cache/mica-installer/update/profiles -type d -not -empty) ] ; then \
		cp -rf /var/cache/mica-installer/update/profiles/* /etc/mica/profiles ; \
	fi 

mica-restore-user-sites:
	if [ $(find /var/cache/mica-installer/update/sites -type d -not -empty) ] ; then \
		cp -rf /var/cache/mica-installer/update/sites/* /etc/mica/sites ; \
	fi

mica-restore-user-files:
	if [ $(find /var/cache/mica-installer/update/files -type d -not -empty) ] ; then \
		cp -rf /var/cache/mica-installer/update/files/* /var/lib/mica/default/files ; \
	fi

mica-clear-tmp-update:
	@echo "**** Clear temp files" 
	rm -rf /var/cache/mica-installer/update

mica-echo-update:
	@echo 
	@echo "****"
	@echo 
	@echo "Mica updates are ready to be applied:"
	@echo 
	@echo "  1. Run update.php by visiting http://www.example.com/update.php (replace www.example.com with your domain name)."
	@echo "     This will update the database tables."
	@echo 
	@echo "     If you are unable to access update.php do the following:"
	@echo "       - Open /usr/share/mica/sites/default/settings.php with a text editor."
	@echo "       - Find the line that says: $update_free_access = FALSE;"
	@echo "       - Change it into: $update_free_access = TRUE;"
	@echo "     Once the upgrade is done, $update_free_access must be reverted to FALSE."	
	@echo
	@echo "  2. Go to Administration > Configuration > Development and clear all caches."
	@echo
	@echo "  3. Go to Administration > Configuration > Development > Maintenance mode." 
	@echo "     Disable the 'Put site into maintenance mode' checkbox and save the configuration."
	@echo  
	@echo "Mica files and database were backuped before update to:"
	@echo "  $(backupdir)"
	@echo 
	@echo "****"
	@echo 

#
# Clean
#

clean:
	rm -rf /var/cache/mica-installer/target
	rm -rf /var/cache/mica-installer/*.gz

#
# Functions
#

delete-module = rm -rf /usr/share/mica/sites/all/modules/$(1) && \
	rm -rf /etc/mica/profiles/mica_distribution/modules/$(1)

delete-theme = rm -rf /usr/share/mica/sites/all/themes/$(1) && \
	rm -rf /etc/mica/profiles/mica_distribution/themes/$(1)

delete-library = rm -rf /usr/share/mica/sites/all/libraries/$(1) && \
	rm -rf /etc/mica/profiles/mica_distribution/libraries/$(1)

delete-profile = rm -rf /usr/share/mica/profiles/$(1)
