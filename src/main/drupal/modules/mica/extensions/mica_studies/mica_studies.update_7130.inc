<?php 

/**
 * Implements hook_feeds_importer_default().
 */
/*function mica_studies_update_7130_feeds_importer_default() {
  $export = array();
  
  $feeds_importer = new stdClass;
  $feeds_importer->id = 'csv_study_import';
  $feeds_importer->config = array(
    'processor' => array(
      'config' => array(
        'mappings' => array(
          67 => array(
            'source' => 'dataset',
            'target' => 'mica_dataset:title',
            'unique' => FALSE,
          ),
        ),
      ),
    ),
  );
  $export['csv_study_import'] = $feeds_importer;

  return $export;
}*/