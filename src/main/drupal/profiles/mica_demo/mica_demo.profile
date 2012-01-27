<?php
include_once('profiles/mica_standard/mica_standard.profile');

/**
 * Implements hook_form_FORM_ID_alter().
 *
 * Allows the profile to alter the site configuration form.
 */
function mica_demo_form_install_configure_form_alter(&$form, $form_state) {
  $form['site_information']['site_name']['#default_value'] = 'Mica';
}

/**
 * Implements hook_install_tasks()
 */
function mica_demo_install_tasks($install_state) {
  $tasks = mica_standard_install_tasks($install_state);
  
  $tasks['mica_demo_content'] = array(
    'display_name' => st('Add Mica demo content'),
    'display' => TRUE,
    'type' => 'batch',
    'run' => INSTALL_TASK_RUN_IF_NOT_COMPLETED, // default to insert content
    'function' => 'mica_import_demo_feeds',
  ); 
  
  return $tasks;
}

function mica_import_demo_feeds($install_state) {
  $base = 'profiles/mica_demo';
  $root = $base . '/data/feeds';
  $feed_configs = array();
  $feed_configs['csv_study_import'] = array(
    'file' => $root . '/study.csv',
  );
  $feed_configs['csv_event_import'] = array(
    'file' => $root . '/event.csv',
  );
  $feed_configs['csv_publication_import'] = array(
    'file' => $root . '/publication.csv',
  );
  $feed_configs['csv_project_import'] = array(
    'file' => $root . '/project.csv',
  );
  $feed_configs['csv_teleconference_import'] = array(
    'file' => $root . '/teleconference.csv',
  );
  
  
  $feed_configs['csv_documents_import'] = array(
    'file' => $base . '/documents/feeds/documents.csv',
  );
  
  $operations = array();
  foreach ($feed_configs as $importer => $file){
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
    'progress_message' => st('Creating demo content'),
  );

  return $batch;
}

