; Drupal Core

api = "2"
core = "7.x"

projects[drupal][type] = core
projects[drupal][version] = 7.15

; Use vocabulary machine name for permissions - http://drupal.org/node/995156
projects[drupal][patch][995156] = http://drupal.org/files/issues/995156-5_portable_taxonomy_permissions.patch

; Add backtrace to all errors - http://drupal.org/node/1158322
projects[drupal][patch][1158322] = http://drupal.org/files/drupal-1158322-82-add-backtrace-to-errors-D7.patch
