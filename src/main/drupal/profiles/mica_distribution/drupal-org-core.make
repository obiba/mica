; Drupal Core

api = "2"
core = "7.x"

projects[drupal][type] = core
projects[drupal][version] = 7.19

; Use vocabulary machine name for permissions
; http://drupal.org/node/995156
projects[drupal][patch][995156] = http://drupal.org/files/issues/995156-5_portable_taxonomy_permissions.patch

; Install profile is disabled for lots of different reasons and core doesn't allow for that
; http://drupal.org/node/1170362
projects[drupal][patch][1170362] = http://drupal.org/files/minimal-install-profile-1170362-181-do-not-test.patch

; Add backtrace to all errors
; http://drupal.org/node/1158322
projects[drupal][patch][1158322] = http://drupal.org/files/drupal-1158322-82-add-backtrace-to-errors-D7.patch

; Remove file_attach_load() from field_field_update()
; http://drupal.org/node/1714596 and http://drupal.org/node/985642
projects[drupal][patch][985642] = http://drupal.org/files/load-original-entity-985642-31.patch

; My Data Access Requests does not show requests for other users than administrators
projects[drupal][patch][1349080] = http://drupal.org/files/d7_move_access_to_join_condition-1349080-89.patch

; Undefined index in field.info.inc
http://drupal.org/files/field-undefined-index-module-1001060-57.patch
http://drupal.org/files/field-undefined-index-module-955658-42.patch
