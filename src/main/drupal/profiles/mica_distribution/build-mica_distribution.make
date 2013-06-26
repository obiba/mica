api = 2
core = 7.x

;Include the definition for how to build Drupal core directly, including patches:
includes[] = drupal-org-core.make

; Download the mica_distribution Install profile and recursively build all its dependencies:
projects[mica_distribution][type] = profile
projects[mica_distribution][version] = 8.0
