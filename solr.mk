solr_version=3.6.2

start-solr:
	cd solr/apache-solr-$(solr_version)/example && \
  java -jar start.jar

install-solr:
	mkdir -p solr && \
	cd solr && \
	wget http://apache.marz.ca/lucene/solr/$(solr_version)/apache-solr-$(solr_version).tgz && \
	tar -zxf apache-solr-$(solr_version).tgz && \
	cp ../target/mica-dev/profiles/mica_distribution/modules/search_api_solr/solr-conf/3.x/* apache-solr-$(solr_version)/example/solr/conf && \
	rm apache-solr-$(solr_version).tgz

clean-solr:
	rm -rf solr
