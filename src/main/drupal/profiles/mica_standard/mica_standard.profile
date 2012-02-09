<?php

/**
 * Implements hook_install_tasks()
 */
function mica_standard_install_tasks($install_state) {
  $tasks = array(
  	'mica_update_mica_languages_batch' => array(
    	'display_name' => st('Installation of Mica translations'),
      'display' => TRUE,
      'type' => 'batch',
      'run' => INSTALL_TASK_RUN_IF_NOT_COMPLETED,
      'function' => '_update_mica_languages_batch',
    ),
    'mica_standard_permissions' => array(
      'display_name' => st('Apply Mica default permissions'),
      'display' => TRUE,
      'type' => 'batch',
      'run' => INSTALL_TASK_RUN_IF_NOT_COMPLETED,
      'function' => '_rebuild_user_permission_batch',
    ),  
  	'mica_standard_content' => array(
      'display_name' => st('Import Mica default content'),
      'display' => TRUE,
      'type' => 'batch',
      'run' => INSTALL_TASK_RUN_IF_NOT_COMPLETED, // default to insert content
      'function' => '_import_default_data',
    ),
  );
  return $tasks;
}

/**
* Application of user permissions by features fails at modules installation.
* So rebuild them in a post-install task.
*/
function _rebuild_user_permission_batch() {
  $length = strlen('mica_');
  foreach (module_list() as $module) {
  	if (substr($module, 0, $length) === 'mica_') {
  		$operations[] = array('_rebuild_user_permission', array($module));
  	}
  }  
  $batch = array(
    'operations' => $operations,
    'title' => st('Apply Mica default permissions.'),
    'init_message' => st('Starting user permissions rebuild.'),
    'error_message' => st('Error while applying Mica permissions'),
    'finished' => '_rebuild_user_permission_finished',
  );
  return $batch;  
}

function _rebuild_user_permission($module, &$context) {
  module_load_include('inc', 'features', 'includes/features.user');
  module_load_include('inc', 'features', 'features.export');
  user_permission_features_rebuild($module);    
  $context['message'] = st('Rebuilt user permissions for %module.', array('%module' => $module));
}

function _rebuild_user_permission_finished($success, $results, $operations) {
	drupal_set_message(st("Rebuild Mica user permissions finished"));
}

function _import_default_data($install_state){
  $root = 'profiles/mica_standard/data'; // for some reason drupal_get_path('profile', 'mica_standard') is empty, maybe a cache related issue...
  
  $feed_configs = array(
  	'csv_field_description_import' => array('file' => $root . '/field_description_import.csv')
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
    'operations' => $operations,
    'title' => st('Import Mica default content'),
  	'init_message'  => st('Creating Mica default content'),
  	'error_message' => st('Error while importing Mica default content'),
  );
  return $batch;
}

function _update_mica_languages_batch($install_state) {
  
  // find all mica french translation files
  $filename = '/fr.po$/';
  $files = drupal_system_listing($filename, 'sites/all/modules/mica', 'name', 0);

  $operations = array();
  foreach($files as $file){
    $operations[] = array('_update_mica_languages', array($file));
  }
  
  $batch = array(
    'operations' => $operations,
    'title' => st('Updating Mica translation.'),
    'init_message' => st('Downloading and importing files.'),
    'error_message' => st('Error importing interface translations'),
    'finished' => '_update_mica_languages_finished',
  );
  return $batch;  
}
  
function _update_mica_languages($file, &$context) {
  module_load_include('batch.inc', 'l10n_update');
  
  $langcode = 'fr';
  
  $field_pattern = '/.field.' . $langcode . '.po$/';
  $menu_pattern = '/.menu.' . $langcode . '.po$/';
  $blocks_pattern = '/.blocks.' . $langcode . '.po$/';
  if (preg_match($field_pattern, $file->filename) == 1) {
    _l10n_update_locale_import_po($file, $langcode, LOCALE_IMPORT_OVERWRITE, 'field'); 
  } elseif (preg_match($menu_pattern, $file->filename) == 1) {
    _l10n_update_locale_import_po($file, $langcode, LOCALE_IMPORT_OVERWRITE, 'menu'); 
  } elseif (preg_match($blocks_pattern, $file->filename) == 1) {
    _l10n_update_locale_import_po($file, $langcode, LOCALE_IMPORT_OVERWRITE, 'blocks');
  } else {
    _l10n_update_locale_import_po($file, $langcode, LOCALE_IMPORT_OVERWRITE, 'default');
  }
  
  $context['message'] = st('Imported: %name.', array('%name' => $file->filename));
}

function _update_mica_languages_finished($success, $results, $operations) {
	drupal_set_message(st("Mica French translations import finished."));
}
