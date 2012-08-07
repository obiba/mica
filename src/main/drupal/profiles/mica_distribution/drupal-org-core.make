; Drupal Core

api = "2"
core = "7.x"

projects[drupal][type] = core
projects[drupal][version] = 7.15

; Use vocabulary machine name for permissions
; http://drupal.org/node/995156
projects[drupal][patch][995156] = http://drupal.org/files/issues/995156-5_portable_taxonomy_permissions.patch

; Install profile is disabled for lots of different reasons and core doesn't allow for that
; http://drupal.org/node/1170362
projects[drupal][patch][1170362] = http://drupal.org/files/mimimal-install-profile-1170362-168.patch
