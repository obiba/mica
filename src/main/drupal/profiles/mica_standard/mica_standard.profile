<?php

/**
 * Implements hook_install_tasks()
 */
function mica_standard_install_tasks($install_state) {
  $tasks = array(
  	'mica_default_content' => array(
      'display_name' => st('Import Mica default content'),
      'display' => TRUE,
      'type' => 'batch',
      'run' => INSTALL_TASK_RUN_IF_NOT_COMPLETED, // default to insert content
      'function' => '_import_default_data',
    ),
    'mica_configure' => array(
      'display_name' => st('Configure Mica'),
      'display' => TRUE,
      'type' => 'batch',
      'run' => INSTALL_TASK_RUN_IF_NOT_COMPLETED, // default to insert content
      'function' => '_mica_configuration_batch',
    ),
  );
  return $tasks;
}

function _import_default_data($install_state) {

  // for some reason drupal_get_path('profile', 'mica_standard') is empty, maybe a cache related issue...
  $root = 'profiles/mica_standard/data';
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

function _mica_configuration_batch() {

  $operations = array();

  // find all mica french translation files
  $filename = '/fr.po$/';
  $files = drupal_system_listing($filename, 'sites/all/modules/mica', 'name', 0);
  foreach($files as $file){
    $operations[] = array('_update_mica_languages', array($file));
  }

  $length = strlen('mica_');
  foreach (module_list() as $module) {
    if (substr($module, 0, $length) === 'mica_') {
      $operations[] = array('_rebuild_user_permission', array($module));
    }
  }

  $operations[] = array('_update_language_french', array());
  $operations[] = array('_studies_block_configuration', array());

  $batch = array(
    'operations' => $operations,
    'title' => st('Configure Mica'),
    'init_message' => st('Starting Mica configuration'),
    'error_message' => st('Error while configuring Mica'),
    'finished' => '_mica_configuration_finished',
  );
  return $batch;
}

function _update_mica_languages($file, &$context) {
  module_load_include('inc', 'l10n_update', 'l10n_update.locale');
  $langcode = 'fr';
  $group = 'default';
  if (preg_match('/.field.' . $langcode . '.po$/', $file->filename) === 1) {
    $group = 'field';
  } elseif (preg_match('/.menu.' . $langcode . '.po$/', $file->filename) === 1) {
    $group = 'menu';
  } elseif (preg_match('/.blocks.' . $langcode . '.po$/', $file->filename) === 1) {
    $group = 'blocks';
  }
  _l10n_update_locale_import_po($file, $langcode, LOCALE_IMPORT_OVERWRITE, $group);

  watchdog('mica', 'Imported %group for %name',
    array('%group' => $group, '%name' => $file->filename), WATCHDOG_DEBUG);

  $context['message'] = st('Imported interface translations: %name.', array('%name' => $file->filename));
}

/**
 * Application of user permissions by features fails at modules installation.
 * So rebuild them in a post-install task.
 */
function _rebuild_user_permission($module, &$context) {
  module_load_include('inc', 'features', 'includes/features.user');
  module_load_include('inc', 'features', 'features.export');
  user_permission_features_rebuild($module);
  $context['message'] = st('Rebuilt user permissions for %module.', array('%module' => $module));
}

function _studies_block_configuration(&$context) {
  module_load_include('inc', 'mica_studies', 'mica_studies.facet_blocks');
  mica_studies_configure_facet_blocks();
  $context['message'] = st('Mica studies configured');
}

function _update_language_french(&$context) {
  $result = db_query("SELECT * FROM {languages} l WHERE l.language = 'fr'");
  if ($result->rowCount() === 0) {
    locale_add_language('fr', 'French', 'Français', 0, '', 'fr', '1', 0);
    // Additional params, locale_add_language does not implement.
    db_update('languages')
      ->fields(array(
      'plurals' => '2',
      'formula' => '($n!=1)',
    ))
      ->condition('language', 'fr')
      ->execute();
    $context['message'] = st('French language configured');
  }
}

function _mica_configuration_finished($success, $results, $operations) {
  drupal_set_message(st("Mica configuration finished"));
}