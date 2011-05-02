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
  $info['FeedsStudyInfoProcessor'] = array(
    'name' => 'Study Information Node processor',
    'description' => 'Update nodes of type Study Information.',
    'help' => 'Update nodes from parsed content.',
    'handler' => array(
      'parent' => 'FeedsNodeProcessor',
      'class' => 'FeedsStudyInfoProcessor',
      'file' => 'FeedsStudyInfoProcessor.inc',
      'path' => $path,
  ),
  );
   
  return $info;
}
