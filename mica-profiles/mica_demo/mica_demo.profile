<?php

/**
 * Implements hook_form_FORM_ID_alter().
 *
 * Allows the profile to alter the site configuration form.
 */
function mica_demo_form_install_configure_form_alter(&$form, $form_state) {
  // Pre-populate the site name with the server name.
  $form['site_information']['site_name']['#default_value'] = $_SERVER['SERVER_NAME'];
}

/**
 * Implements hook_install_tasks()
 *
 */
function mica_demo_install_tasks($install_state){
  include_once(drupal_get_path('profile', 'mica_minimal') . '/mica_minimal.profile');
  $tasks = mica_minimal_install_tasks($install_state);
  
  $tasks['mica_demo_content'] = array(
    'display_name' => st('Add demo content'),
    'display' => TRUE,
    'type' => 'batch',
    'run' => INSTALL_TASK_RUN_IF_NOT_COMPLETED, // default to insert content
    'function' => 'mica_import_demo_feeds',
  ); 
  
  return $tasks;
}

function mica_import_demo_feeds($install_state){
  $root = drupal_get_path('profile', 'mica_demo') . '/data';
  $feed_configs = array();
  $feed_configs['csv_study_import'] = array(
    'file' => $root . '/study_import.csv',
  );
  $feed_configs['csv_study_information_import'] = array(
    'file' => $root . '/study_information_import.csv',
  );
  $feed_configs['csv_contact_import'] = array(
    'file' => $root . '/contact_import.csv',
  );
  $feed_configs['csv_institution_import'] = array(
    'file' => $root . '/institution_import.csv',
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
      'progress_message' => 'Creating demo content',
    );

  return $batch;
}