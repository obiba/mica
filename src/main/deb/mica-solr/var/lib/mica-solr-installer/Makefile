#
# Mica Solr Installer Makefile
#

oldversion=
solr_version=4.2.1
backupdir=/var/lib/mica-installer/backups/mica-solr-$(oldversion)


all: install

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

mica-solr-install: mica-solr-install-prepare solr-install

mica-solr-update: mica-solr-backup solr-copy-config-files

mica-solr-install-prepare:
	@echo "**** Downloading Apache Solr version $(solr_version)"
	mkdir -p target && \
	cd target && \
	wget http://archive.apache.org/dist/lucene/solr/$(solr_version)/solr-$(solr_version).tgz && \
	#cp /home/cthiebault/Downloads/solr-$(solr_version).tgz . && \
	tar xzf solr-$(solr_version).tgz

mica-solr-backup:
	@echo "**** Backup mica-solr $(oldversion)"
	mkdir -p $(backupdir) && \
	cp -rL /usr/share/mica-solr $(backupdir) && \
	tar czf mica-solr-$(oldversion).tar.gz $(backupdir)/mica-solr

solr-install: solr-install-setup solr-copy-config-files solr-install-finish

solr-install-setup:
	cp -r target/solr-$(solr_version)/example/* /usr/share/mica-solr

solr-copy-config-files:
	cd /usr/share && \
	if [ -e mica/sites/all/modules/search_api_solr/solr-conf/4.x/solrconfig.xml ]; then \
		cp mica/sites/all/modules/search_api_solr/solr-conf/4.x/* mica-solr/solr/collection1/conf/ ; \
	fi && \
	if [ -e /etc/mica/profiles/mica_distribution/modules/search_api_solr/solr-conf/4.x/solrconfig.xml ]; then \
		cp /etc/mica/profiles/mica_distribution/modules/search_api_solr/solr-conf/4.x/* mica-solr/solr/collection1/conf/ ; \
	fi

solr-install-finish:
	chown -R www-data:www-data /usr/share/mica-solr && \
	rmdir /usr/share/mica-solr/logs && \
	ln -s /var/log/mica-solr /usr/share/mica-solr/logs && \
	mv /usr/share/mica-solr/solr/collection1/conf /etc/mica-solr && \
	ln -s /etc/mica-solr/conf /usr/share/mica-solr/solr/collection1/conf && \
	ln -s /var/lib/mica-solr/data /usr/share/mica-solr/solr/collection1/data

#
# Clean
#

clean:
	rm -rf /var/lib/mica-solr-installer/target
