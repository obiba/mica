Mica Opal
------------------------

Allows using Mica and Mica Datasets with an Opal instance (http://www.obiba.org/node/63).


INSTALLATION
------------------------

Download jsonpath-0.8.1.php

This module uses an external PHP library (http://code.google.com/p/jsonpath) for communicating with Opal servers.

Download  this modified version
http://git.obiba.org/raw/?f=src/main/lib/jsonpath-0.8.1.php&r=mica.git&h=065d44ae6bb1083533912dc35440dcdcbfac6679
because of issue http://code.google.com/p/jsonpath/issues/detail?id=8.

Copy jsonpath-0.8.1.php file to Drupal's libraries folder, so the directory tree looks like this:

DRUPAL_ROOT/sites/all/libraries/jsonpath/jsonpath-0.8.1.php


The library should then be found by the module.

Note: If you have the Libraries API (http://drupal.org/project/libraries) module installed, you can also place the
library into any other directory recognized by the Libraries API, e.g.
(depending on the module version):
- DRUPAL_ROOT/libraries/jsonpath/jsonpath-0.8.1.php
- DRUPAL_ROOT/profiles/PROFILE/libraries/jsonpath/jsonpath-0.8.1.php
- DRUPAL_ROOT/sites/CONF_DIR/libraries/jsonpath/jsonpath-0.8.1.php

