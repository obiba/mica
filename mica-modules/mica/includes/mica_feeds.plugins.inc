<?php

include_once(drupal_get_path('module', 'mica') . '/mappers/mica.inc');
include_once(drupal_get_path('module', 'mica') . '/mappers/email.inc');
include_once(drupal_get_path('module', 'mica') . '/mappers/name.inc');
include_once(drupal_get_path('module', 'mica') . '/mappers/references.inc');

/**
 * hook_feeds_plugins
 */
function mica_feeds_plugins() {
  $path = drupal_get_path('module', 'mica') .'/plugins';
  $info = array();
  $info['FeedsStudyChildProcessor'] = array(
    'name' => 'Study Child Node processor',
    'description' => 'Update nodes that are linked to a Study through a field_study_legacy_id.',
    'help' => 'Update nodes from parsed content.',
    'handler' => array(
      'parent' => 'FeedsNodeProcessor',
      'class' => 'FeedsStudyChildProcessor',
      'file' => 'FeedsStudyChildProcessor.inc',
      'path' => $path,
    ),
  );
  $info['FeedsUniqueNodeProcessor'] = array(
    'name' => 'Unique Node processor',
    'description' => 'Update nodes if it already exists or creates a new one.',
    'help' => 'Update nodes from parsed content.',
    'handler' => array(
      'parent' => 'FeedsNodeProcessor',
      'class' => 'FeedsUniqueNodeProcessor',
      'file' => 'FeedsUniqueNodeProcessor.inc',
      'path' => $path,
    ),
  );

  return $info;
}
