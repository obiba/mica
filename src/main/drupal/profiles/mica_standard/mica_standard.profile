<?php

function mica_standard_install_tasks($install_state) {
  $tasks = array(
//   	'mica_update_drupal_languages' => array(
//     	'display_name' => st('Download Drupal french translations'),
//       'display' => TRUE,
//       'type' => 'batch',
//       'run' => INSTALL_TASK_RUN_IF_NOT_COMPLETED,
//       'function' => 'mica_update_drupal_languages',
//     ),
//   	'mica_update_mica_languages_batch' => array(
//     	'display_name' => st('Load Mica French translations'),
//       'display' => TRUE,
//       'type' => 'batch',
//       'run' => INSTALL_TASK_RUN_IF_NOT_COMPLETED,
//       'function' => 'mica_update_mica_languages_batch',
//     ),
    'mica_standard_permissions' => array(
      'display_name' => st('Apply Mica default permissions'),
      'display' => TRUE,
      'type' => 'batch',
      'run' => INSTALL_TASK_RUN_IF_NOT_COMPLETED,
      'function' => 'mica_user_permission_rebuild_batch',
    ),  
//   	'mica_standard_content' => array(
//       'display_name' => st('Add Mica default content'),
//       'display' => TRUE,
//       'type' => 'batch',
//       'run' => INSTALL_TASK_RUN_IF_NOT_COMPLETED, // default to insert content
//       'function' => 'mica_import_default_feeds',
//     ),
  );
  return $tasks;
}

/**
* Application of user permissions by features fails at modules installation.
* So rebuild them in a post-install task.
*/
function mica_user_permission_rebuild_batch() {
	$batch = array(
    'operations' => array(array('mica_user_permission_rebuild', array())),
    'finished' => 'mica_user_permission_rebuild_finished',
    'title' => t('Apply Mica default permissions'),
    'init_message' => t('Starting user permissions rebuild.'),
    // We use a single multi-pass operation, so the default
    // 'Remaining x of y operations' message will be confusing here.
    'progress_message' => '',
    'error_message' => t('Permission rebuild batch has encountered an error.'),
	);
	return $batch;
}

function mica_user_permission_rebuild(&$context) {
  
  if (!isset($context['sandbox']['progress'])) {
    // retrieve only mica modules
    $mica_modules = array();
    $length = strlen('mica_');
    foreach (module_list() as $module) {
    	if (substr($module, 0, $length) === 'mica_') {
    		$mica_modules[] = $module;
    	}
    }    
  	$context['sandbox']['progress'] = 0;
  	$context['sandbox']['max'] = count($mica_modules);
  	$context['sandbox']['mica_modules'] = $mica_modules;
  }  
  
  module_load_include('inc', 'features', 'includes/features.user');
  module_load_include('inc', 'features', 'features.export');
  
  // rebuild all mica modules permissions  
  $module = array_pop($context['sandbox']['mica_modules']);
  user_permission_features_rebuild($module);    
  $context['results'][] = $module;
  $context['sandbox']['progress']++;
  $context['message'] = 'Rebuilt ' . $module . ' user permissions';    
  
  if ($context['sandbox']['progress'] != $context['sandbox']['max']) {
  	$context['finished'] = $context['sandbox']['progress'] / $context['sandbox']['max'];
  }  
}

function mica_user_permission_rebuild_finished($success, $results, $operations) {
	drupal_set_message(t("Rebuild Mica user permissions finished"));
}

function mica_import_default_feeds($install_state){
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
    'title' => st('Importing'),
    'operations' => $operations,
    'progress_message' => st('Creating default Mica content'),
  );

  return $batch;
}

function mica_update_drupal_languages($install_state) {
	module_load_include('batch.inc', 'l10n_update');

	$history = l10n_update_get_history();
	$available = l10n_update_available_releases();
	$updates = l10n_update_build_updates($history, $available);

	// Filter out updates in other languages. If no languages, all of them will be updated
	$languages = array('fr');
	$updates = _l10n_update_prepare_updates($updates, NULL, $languages);
	$batch = l10n_update_batch_multiple($updates, null);

	return $batch;
}

function mica_update_mica_languages_batch($install_state) {
  $batch = array(
    'operations' => array(array('mica_update_mica_languages', array())),
    'finished' => 'mica_update_mica_languages_finished',
    'title' => t('Load Mica French translations'),
    'init_message' => t('Starting French translations download.'),
    // We use a single multi-pass operation, so the default
    // 'Remaining x of y operations' message will be confusing here.
    'progress_message' => '',
    'error_message' => t('Mica French translations batch has encountered an error.'),
  );
  return $batch;  
}
  
function mica_update_mica_languages(&$context) {
  
  if (!isset($context['sandbox']['progress'])) {
    
    // find all mica french translation files
    $filename = '/\.fr.po$/';  
    $files = drupal_system_listing($filename, 'sites/all/modules/mica', 'name', 0);
   
  	$context['sandbox']['progress'] = 0;
  	$context['sandbox']['max'] = count($files);
  	$context['sandbox']['files'] = $files;
  }  
  
  module_load_include('batch.inc', 'l10n_update');
  
  // rebuild all mica modules permissions
  $file = array_pop($context['sandbox']['files']);
  _l10n_update_locale_import_po($file, 'fr', LOCALE_IMPORT_OVERWRITE, 'default');
  _l10n_update_locale_import_po($file, 'fr', LOCALE_IMPORT_OVERWRITE, 'field');
  	
  $context['results'][] = $file;
  $context['sandbox']['progress']++;
  $context['message'] = 'Imported ' . $file;
  
  if ($context['sandbox']['progress'] != $context['sandbox']['max']) {
  	$context['finished'] = $context['sandbox']['progress'] / $context['sandbox']['max'];
  }  
}


function mica_update_mica_languages_finished($success, $results, $operations) {
	drupal_set_message(t("Mica French translations loaded."));
}
