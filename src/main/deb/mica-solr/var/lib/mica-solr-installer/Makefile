#
# Mica Solr Installer Makefile
#

oldversion=
solr_version=3.6.2


all: mica-solr-install-prepare

#
# Install
#

install: 
ifndef oldversion
	@echo "**** Mica Solr install"
	make mica-solr-install
else
	@echo "**** Mica Solr update"
	make mica-solr-update
endif

#
# Mica Solr install
#

mica-solr-install: solr-install 

mica-solr-update: solr-copy-config-files

mica-solr-install-prepare:
	@echo "**** Downloading Apache Solr version $(solr_version)"
	mkdir -p target	
	cd target && \
	wget -q http://archive.apache.org/dist/lucene/solr/$(solr_version)/apache-solr-$(solr_version).tgz && \
	tar xzf apache-solr-$(solr_version).tgz

solr-install: solr-install-setup solr-copy-config-files solr-install-finish
	
solr-install-setup:
	cp -r target/apache-solr-$(solr_version)/example/* /usr/share/mica-solr

solr-copy-config-files:
	cd /usr/share && \
	if [ -e mica/sites/all/modules/search_api_solr/solrconfig.xml ]; then \
		cp mica/sites/all/modules/search_api_solr/solrconfig.xml mica-solr/solr/conf/ ; \
	fi && \
	if [ -e /etc/mica/profiles/mica_distribution/modules/search_api_solr/solrconfig.xml ]; then \
		cp /etc/mica/profiles/mica_distribution/modules/search_api_solr/solrconfig.xml mica-solr/solr/conf/ ; \
	fi && \
	if [ -e mica/sites/all/modules/search_api_solr/schema.xml ]; then \
		cp mica/sites/all/modules/search_api_solr/schema.xml mica-solr/solr/conf/ ; \
	fi && \
	if [ -e /etc/mica/profiles/mica_distribution/modules/search_api_solr/schema.xml ]; then \
		cp /etc/mica/profiles/mica_distribution/modules/search_api_solr/schema.xml mica-solr/solr/conf/ ; \
	fi

solr-install-finish:
	rmdir /usr/share/mica-solr/logs && \
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
