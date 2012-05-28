<?php

/**
 * Implements hook_install_tasks()
 */
function mica_standard_install_tasks($install_state) {

  global $conf;
  if (empty($conf['theme_settings'])) {
    $conf['theme_settings'] = array(
      'default_logo' => 0,
      'logo_path' => 'profiles/mica_standard/mica.png',
    );
  }

  // Preselect the English language, so users can skip the language selection form
  if (!isset($_GET['locale'])) {
    $_POST['locale'] = 'en';
  }

  $tasks = array(
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

function _mica_configuration_batch() {

  $operations = array();

  // import default content
  // for some reason drupal_get_path('profile', 'mica_standard') is empty, maybe a cache related issue...
  $default_data = array(
    'csv_field_description_import' => array('file' => 'profiles/mica_standard/data/field_description_import.csv')
  );
  foreach($default_data as $importer => $file) {
    $source = feeds_source($importer);
    foreach ($source->importer->plugin_types as $type) {
      if ($source->importer->$type->hasSourceConfig()) {
        $class = get_class($source->importer->$type);
        if ($class === 'FeedsFileFetcher') {
          $config = isset($source->config[$class]) ? $source->config[$class] : array();
          $config['source'] = $file['file'];
          $source->setConfigFor($source->importer->$type, $config);
        }
      }
    }
    $source->save();
    $operations[] = array('feeds_batch', array('import', $source->id, $source->feed_nid));
  }

  $operations[] = array('_create_default_content', array());

  $operations[] = array('_import_taxonomies', array());

  // prepare permissions rebuild
  $mica_length = strlen('mica_');
  foreach (module_list() as $module) {
    if (substr($module, 0, $mica_length) === 'mica_') {
      $operations[] = array('_rebuild_user_permission', array($module));
    }
  }

  $operations[] = array('_studies_block_configuration', array());
  $operations[] = array('_datasets_block_configuration', array());

  $batch = array(
    'operations' => $operations,
    'title' => st('Configure Mica'),
    'init_message' => st('Starting Mica configuration'),
    'error_message' => st('Error while configuring Mica'),
    'finished' => '_mica_configuration_finished',
  );
  return $batch;
}

//TODO merge this with _create_default_content
function _import_taxonomies($module, &$context) {
  module_invoke_all('taxonomies_operations_import');
}

function _create_default_content($module, &$context) {
  drupal_flush_all_caches();
  module_invoke_all('create_default_content');
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

function _datasets_block_configuration(&$context) {
  module_load_include('inc', 'mica_datasets', 'mica_datasets.facet_blocks');
  mica_datasets_configure_facet_blocks();
  $context['message'] = st('Mica datasets configured');
}

function _mica_configuration_finished($success, $results, $operations) {
  drupal_set_message(st("Mica configuration finished"));
}