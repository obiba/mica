#
# Mica Solr Installer Makefile
#

oldversion=
solr_version=1.4.1

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
	make mica-solr-install
else
	@echo "**** Mica modules/themes/profiles upgrade" 
	make mica-install
endif

#
# Mica Solr install
#

mica-solr-install: mica-solr-install-prepare solr-install 

mica-solr-install-prepare:
	mkdir -p target	
	cd target && \
	wget -q http://apache.raffsoftware.com//lucene/solr/$(solr_version)/apache-solr-$(solr_version).tgz && \
	tar xzf apache-solr-$(solr_version).tgz && \
	cp -r apache-solr-$(solr_version)/example /usr/share/mica-solr

solr-install:
	cd /usr/share && \
	cp mica/sites/all/modules/search_api_solr/solrconfig.xml mica-solr/solr/conf/ && \
	cp mica/sites/all/modules/search_api_solr/schema.xml mica-solr/solr/conf/ && \
	cd /etc && \
	mv /usr/share/mica-solr/solr/conf mica-solr && \
	ln -s /etc/mica-solr/conf /usr/share/mica-solr/solr/conf && \
	cd /var/lib && \
	mkdir -p mica-solr/data && \
	ln -s /var/lib/mica-solr/data /etc/mica-solr/conf/data

#
# Clean
#

clean:
	rm -rf /var/cache/mica-solr-installer/target

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

