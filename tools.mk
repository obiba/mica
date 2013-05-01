solr_version=3.6.2

start-solr:
	cd solr/apache-solr-$(solr_version)/example && \
  java -jar start.jar && \
  @echo ">>> SolR is now running at http://localhost:8983/solr/admin"

install-solr:
	mkdir -p solr && \
	cd solr && \
	wget http://apache.marz.ca/lucene/solr/$(solr_version)/apache-solr-$(solr_version).tgz && \
	tar -zxf apache-solr-$(solr_version).tgz && \
	cp ../target/mica-dev/profiles/mica_distribution/modules/search_api_solr/solr-conf/3.x/* apache-solr-$(solr_version)/example/solr/conf && \
	rm apache-solr-$(solr_version).tgz

clean-solr:
	rm -rf solr

install-drush:
	apt-get install php-pear 
	pear channel-discover pear.drush.org
	pear install drush/drush

install-lessc: install-nodejs install-bootstrap-dependencies

install-nodejs:
	apt-get install g++ curl libssl-dev apache2-utils && \
	mkdir target/nodejs && \
	cd target/nodejs && \
	wget http://nodejs.org/dist/v0.8.15/node-v0.8.15.tar.gz && \
	tar -xzvf node-v0.8.15.tar.gz && \
	cd node-v0.8.15 && \
	./configure && \
	make && \
	make install

install-bootstrap-dependencies:
	npm install less connect uglify-js@1 jshint -g