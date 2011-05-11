<?php

/**
 * Implements hook_form_FORM_ID_alter().
 *
 * Allows the profile to alter the site configuration form.
 */
function mica_minimal_form_install_configure_form_alter(&$form, $form_state) {
  // Pre-populate the site name with the server name.
  $form['site_information']['site_name']['#default_value'] = $_SERVER['SERVER_NAME'];
}

/**
 * Implements hook_install_tasks()
 *
 */
function mica_minimal_install_tasks($install_state){
  $task['mica_minimal_content'] = array(
    'display_name' => st('Add default Mica content'),
    'display' => TRUE,
    'type' => 'batch',
    'run' => INSTALL_TASK_RUN_IF_NOT_COMPLETED, // default to insert content
    'function' => 'mica_import_default_feeds',
  ); 
  
  return $task;
}

function mica_import_default_feeds($install_state){
  $root = 'profiles/mica_minimal/data'; // for some reason drupal_get_path('profile', 'mica_minimal') is empty, maybe a cache related issue...
  $feed_configs = array();
  $feed_configs['csv_variable_import'] = array(
    'file' => $root . '/variable_import.csv',
  );
    
  $operations = array();
  foreach($feed_configs as $importer => $file){
    $source = feeds_source($importer);

    foreach ($source->importer->plugin_types as $type) {
      if ($source->importer->$type->hasSourceConfig()) {
        $class = get_class($source->importer->$type);
        if ($class == 'FeedsFileFetcher'){
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
      'progress_message' => 'Creating default Mica content',
    );

  return $batch;
}

