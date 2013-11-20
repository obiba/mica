<?php

/**
 * Implements hook_install_tasks()
 */
function mica_distribution_install_tasks($install_state) {

  global $conf;
  if (empty($conf['theme_settings'])) {
    $conf['theme_settings'] = array(
      'default_logo' => 0,
      'logo_path' => 'profiles/mica_distribution/mica.png',
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
      'function' => '_mica_distribution_configuration_batch',
    ),
  );
  return $tasks;
}

function _mica_distribution_configuration_batch() {

  $operations = array();

  // import default content
  // for some reason drupal_get_path('profile', 'mica_distribution') is empty, maybe a cache related issue...
  $default_data = array(
    'csv_field_description_import' => array('file' => 'profiles/mica_distribution/data/field_description_import.csv')
  );
  foreach ($default_data as $importer => $file) {
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

  $operations = array_merge($operations, module_invoke_all('taxonomies_operations_import'));

  // prepare permissions rebuild
  $mica_length = strlen('mica_');
  foreach (module_list() as $module) {
    if (substr($module, 0, $mica_length) === 'mica_') {
      if (module_exists($module)) {
        $operations[] = array('_mica_distribution_rebuild_user_permission', array($module));

        //rebuild menus
        $operations = array_merge($operations, module_invoke_all('create_default_menu_module'));
      }
    }
  }

  $operations[] = array('_mica_distribution_field_description_block_configuration', array());
  $operations[] = array('_mica_distribution_studies_block_configuration', array());

  // hack to to revert again search_api_index config as fields are getting lost :-(
  $operations[] = array('features_revert', array(array('mica_field_description' => array('search_api_index'))));
  $operations[] = array('features_revert', array(array('mica_studies' => array('search_api_index'))));

  if (module_exists('mica_datasets')) {
    $operations[] = array('_mica_distribution_datasets_block_configuration', array());

    // hack to to revert again search_api_index config as fields are getting lost :-(
    $operations[] = array('features_revert', array(array('mica_datasets' => array('search_api_index'))));
  }

  $batch = array(
    'operations' => $operations,
    'title' => st('Configure Mica'),
    'init_message' => st('Starting Mica configuration'),
    'error_message' => st('Error while configuring Mica'),
    'finished' => '_mica_distribution_mica_configuration_finished',
  );
  return $batch;
}

/**
 * Application of user permissions by features fails at modules installation.
 * So rebuild them in a post-install task.
 */
function _mica_distribution_rebuild_user_permission($module, &$context) {
  module_load_include('inc', 'features', 'includes/features.user');
  module_load_include('inc', 'features', 'features.export');
  user_permission_features_rebuild($module);
  $context['message'] = st('Rebuilt user permissions for %module.', array('%module' => $module));
}

function _mica_distribution_field_description_block_configuration(&$context) {
  mica_field_description_configure_facet_blocks();
  $context['message'] = st('Mica Field Description configured');
}

function _mica_distribution_studies_block_configuration(&$context) {
  module_load_include('inc', 'mica_studies', 'mica_studies.facet_blocks');
  mica_studies_configure_facet_blocks();
  $context['message'] = st('Mica studies configured');
}

function _mica_distribution_datasets_block_configuration(&$context) {
  module_load_include('inc', 'mica_datasets', 'mica_datasets.facet_blocks');
  mica_datasets_configure_facet_blocks();
  $context['message'] = st('Mica datasets configured');
}

function _mica_distribution_mica_configuration_finished($success, $results, $operations) {
  drupal_set_message(st("Mica configuration finished"));
}
