solr_version=4.2.1

start-solr:
	cd solr/solr-$(solr_version)/example && \
  java -jar start.jar && \
  @echo ">>> SolR is now running at http://localhost:8983/solr/admin"

install-solr:
	mkdir -p solr && \
	cd solr && \
	wget -q http://mirror.csclub.uwaterloo.ca/apache/lucene/solr/$(solr_version)/solr-$(solr_version).tgz && \
	tar -zxf solr-$(solr_version).tgz && \
	cp ../target/mica-dev/profiles/mica_distribution/modules/search_api_solr/solr-conf/4.x/* solr-$(solr_version)/example/solr/collection1/conf && \
	rm solr-$(solr_version).tgz

clean-solr:
	rm -rf solr

install-drush:
	apt-get install -y php-pear
	pear channel-discover pear.drush.org
	pear install drush/drush

install-lessc: install-nodejs install-bootstrap-dependencies

install-nodejs:
	apt-get install -y g++ curl libssl-dev apache2-utils && \
	mkdir target/nodejs && \
	cd target/nodejs && \
	wget -q http://nodejs.org/dist/v0.8.15/node-v0.8.15.tar.gz && \
	tar -xzvf node-v0.8.15.tar.gz && \
	cd node-v0.8.15 && \
	./configure && \
	make && \
	make install

install-bootstrap-dependencies:
	npm install less connect uglify-js@1 jshint -g

install-packaging-dependencies:
	apt-get install devscripts debhelper

install-tools: install-packaging-dependencies install-drush install-lessc install-solr
