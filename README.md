# [Mica](http://www.obiba.org/node/174) [![Build Status](http://ci.obiba.org/view/Mica/job/Mica/badge/icon)](http://ci.obiba.org/view/Mica/job/Mica/)

[Mica](http://www.obiba.org/node/174) is a powerful software application used to create web portals for epidemiological
study consortia.

Using Mica, consortia can build personalised web sites for publishing their research activities and their membership.
Mica includes many domain-specific features such as study catalogues, data dictionary browsers, on-line data access request
forms, community tools (forums, events, news) and others. Moreover, Mica includes a powerful data search engine that allows
authenticated researchers to perform distributed queries on the content of each individual study data collection hosted
by the OBiBa [Opal](http://www.obiba.org/node/63) database software.

Mica is based on the content management software [Drupal](http://www.drupal.org) used by millions of websites worldwide.
As such, a webmaster benefits from all the power and flexibility of Drupal, as well as the support of an extended developer community.

Mica is developped by [OBiBa](http://www.obiba.org).


## Documentation

Read [Mica documentation](http://wiki.obiba.org/display/MICADOC).


## Download

Mica is a PHP-based application, so it should run on any platform for which a PHP engine and a web server are provided.

### Debian-based Platforms

We provide a package for Debian-based platforms (Debian, Ubuntu, etc.). We **strongly** suggest to use this package as
it greatly simplifies the installation and upgrades.
Our package repository (with instructions) is [here](http://pkg.obiba.org).

### Other Platforms

All other platforms should follow the [installation instructions](http://wiki.obiba.org/display/MICADOC/Mica+Installation+Guide).

### Configuration

Once Mica is installed it probably needs to be configured for your environment. Please follow the instructions provided
in our wiki [here](http://wiki.obiba.org/display/MICADOC).


## Build
    
Prepare third party tools:

    make install-tools 
    
probaly we nee do install solr : 
    
    make install-solr

    make start-solr
    
Prepare Drupal/Mica instance

    make dev

Configure Apache

    sudo ln -s mica/target/mica-dev /var/www/mica-dev

Then go to [http://localhost/mica-dev](http://localhost/mica-dev)
    

## Bug tracker

Have a bug? Please create an issue on [OBiBa JIRA](http://jira.obiba.org/jira/browse/MICA).


## Mailing list

Have a question? Ask on our mailing list!

obiba-users@googlegroups.com

[http://groups.google.com/group/obiba-users](http://groups.google.com/group/obiba-users)


## License

OBiBa software are open source and made available under the [GPL3 licence](http://www.obiba.org/node/62).
OBiBa software are free of charge.
