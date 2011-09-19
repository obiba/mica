#
# Mica Solr Installer Makefile
#

oldversion=
solr_version=3.4.0

#
# Drush install
#

all: mica-solr-install-prepare

#
# Install
#

install: 
ifndef oldversion
	@echo "**** Mica Solr install" 
	make mica-solr-install
else
	@echo "**** Mica Solr upgrade" 
	make mica-install
endif

#
# Mica Solr install
#

mica-solr-install: solr-install 

mica-solr-install-prepare:
	@echo "**** Downloading Apache Solr version $(solr_version)"
	mkdir -p target	
	cd target && \
	wget -q http://apache.raffsoftware.com//lucene/solr/$(solr_version)/apache-solr-$(solr_version).tgz && \
	tar xzf apache-solr-$(solr_version).tgz

solr-install:
	cd target && \
	cp -r apache-solr-$(solr_version)/example/* /usr/share/mica-solr
	cd /usr/share && \
	cp mica/sites/all/modules/search_api_solr/solrconfig.xml mica-solr/solr/conf/ && \
	cp mica/sites/all/modules/search_api_solr/schema.xml mica-solr/solr/conf/ && \
	rmdir mica-solr/logs && \
	ln -s /var/log/mica-solr /usr/share/mica-solr/logs && \
	cd /etc && \
	mv /usr/share/mica-solr/solr/conf mica-solr && \
	ln -s /etc/mica-solr/conf /usr/share/mica-solr/solr/conf && \
	ln -s /var/lib/mica-solr/data /usr/share/mica-solr/solr/data

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

