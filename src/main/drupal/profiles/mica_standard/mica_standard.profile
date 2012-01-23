<?php

function mica_standard_install_tasks($install_state){
  $task['mica_update_languages'] = array(
  	'display_name' => st('Download Drupal french translations'),
    'display' => TRUE,
    'type' => 'batch',
    'run' => INSTALL_TASK_RUN_IF_NOT_COMPLETED,
    'function' => 'mica_update_languages',
  );
  
  $task['mica_standard_content'] = array(
    'display_name' => st('Add Mica default content'),
    'display' => TRUE,
    'type' => 'batch',
    'run' => INSTALL_TASK_RUN_IF_NOT_COMPLETED, // default to insert content
    'function' => 'mica_import_default_feeds',
  ); 

  $task['mica_standard_permissions'] = array(
    'display_name' => st('Apply Mica default permissions'),
    'display' => TRUE,
    'type' => 'batch',
    'run' => INSTALL_TASK_RUN_IF_NOT_COMPLETED,
    'function' => 'mica_user_permission_rebuild',
  ); 
  
 
  return $task;
}

/**
 * Application of user permissions by features fails at modules installation. 
 * So rebuild them in a post-install task.
 */
function mica_user_permission_rebuild() {
  module_load_include('inc', 'features', 'includes/features.user');
  module_load_include('inc', 'features', 'features.export');
  
  // rebuild all mica modules permissions
  $length = strlen('mica_');
  foreach (module_list() as $module) {
    if (substr($module, 0, $length) === 'mica_') {
      user_permission_features_rebuild($module);
    }
  }
}

function mica_import_default_feeds($install_state){
  $root = 'profiles/mica_standard/data'; // for some reason drupal_get_path('profile', 'mica_standard') is empty, maybe a cache related issue...
  $feed_configs = array();
  $feed_configs['csv_field_description_import'] = array(
    'file' => $root . '/field_description_import.csv',
  );
    
  $operations = array();
  foreach($feed_configs as $importer => $file){
    $source = feeds_source($importer);

    foreach ($source->importer->plugin_types as $type) {
      if ($source->importer->$type->hasSourceConfig()) {
        $class = get_class($source->importer->$type);
        if ($class == 'FeedsFileFetcher') {
          $config = isset($source->config[$class]) ? $source->config[$class] : array();
          $config['source'] = $file['file'];
          $source->setConfigFor($source->importer->$type, $config);
        }  
      }
    }
    $source->save();
    $operations[] = array('feeds_batch', array('import', $source->id, $source->feed_nid));
  }
  
  $batch = array(
    'title' => st('Importing'),
    'operations' => $operations,
    'progress_message' => st('Creating default Mica content'),
  );

  return $batch;
}

function mica_update_languages($install_state){
  module_load_include('batch.inc', 'l10n_update');
  
  $history = l10n_update_get_history();
  $available = l10n_update_available_releases();
  $updates = l10n_update_build_updates($history, $available);
  
//   Filter out updates in other languages. If no languages, all of them will be updated
  $languages = array('fr');
  $updates = _l10n_update_prepare_updates($updates, NULL, $languages);
  
  $batch = l10n_update_batch_multiple($updates, null);
  
  return $batch;
}