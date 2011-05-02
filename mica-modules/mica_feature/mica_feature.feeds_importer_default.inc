<?php
/**
 * @file
 * mica_feature.feeds_importer_default.inc
 */

/**
 * Implementation of hook_feeds_importer_default().
 */
function mica_feature_feeds_importer_default() {
  $export = array();

  $feeds_importer = new stdClass;
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'csv_study_import';
  $feeds_importer->config = array(
    'name' => 'Study Importer',
    'description' => 'Import Study from a CSV file',
    'fetcher' => array(
      'plugin_key' => 'FeedsFileFetcher',
      'config' => array(
        'allowed_extensions' => 'txt csv',
        'direct' => 0,
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsCSVParser',
      'config' => array(
        'delimiter' => ';',
        'no_headers' => 0,
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsNodeProcessor',
      'config' => array(
        'content_type' => 'study',
        'expire' => '-1',
        'author' => 0,
        'mappings' => array(
          0 => array(
            'source' => 'Study Legacy Id',
            'target' => 'field_study_legacy_id',
            'unique' => FALSE,
          ),
          1 => array(
            'source' => 'Study Legacy Id',
            'target' => 'guid',
            'unique' => 1,
          ),
          2 => array(
            'source' => 'Name',
            'target' => 'title',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'Objectives',
            'target' => 'body',
            'unique' => FALSE,
          ),
          4 => array(
            'source' => 'Website',
            'target' => 'field_website:url',
            'unique' => FALSE,
          ),
          5 => array(
            'source' => 'Status',
            'target' => 'status',
            'unique' => FALSE,
          ),
        ),
        'update_existing' => '2',
        'input_format' => 'plain_text',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => -1,
    'expire_period' => 3600,
    'import_on_create' => TRUE,
    'process_in_background' => FALSE,
  );
  $export['csv_study_import'] = $feeds_importer;

  $feeds_importer = new stdClass;
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'csv_study_information_import';
  $feeds_importer->config = array(
    'name' => 'Study Information',
    'description' => 'Import Study Information from a CSV file',
    'fetcher' => array(
      'plugin_key' => 'FeedsFileFetcher',
      'config' => array(
        'allowed_extensions' => 'txt csv',
        'direct' => 0,
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsCSVParser',
      'config' => array(
        'delimiter' => ';',
        'no_headers' => 0,
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsStudyInfoProcessor',
      'config' => array(
        'content_type' => 'study_information',
        'expire' => '-1',
        'author' => 0,
        'mappings' => array(
          0 => array(
            'source' => 'Study Legacy Id',
            'target' => 'guid',
            'unique' => 1,
          ),
          1 => array(
            'source' => 'Target Number of Participants',
            'target' => 'field_target_number_participants',
            'unique' => FALSE,
          ),
          2 => array(
            'source' => 'Investigator Name and Association',
            'target' => 'field_investigator:title',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'Baseline Design',
            'target' => 'field_design',
            'unique' => FALSE,
          ),
          4 => array(
            'source' => 'Design Other',
            'target' => 'field_design_other',
            'unique' => FALSE,
          ),
          5 => array(
            'source' => 'Targets Recruitment',
            'target' => 'field_design_target',
            'unique' => FALSE,
          ),
          6 => array(
            'source' => 'Targets Other',
            'target' => 'field_target_other',
            'unique' => FALSE,
          ),
          7 => array(
            'source' => 'Selection Criteria',
            'target' => 'field_selection_criteria',
            'unique' => FALSE,
          ),
          8 => array(
            'source' => 'Specify Gender',
            'target' => 'field_gender',
            'unique' => FALSE,
          ),
          9 => array(
            'source' => 'Country',
            'target' => 'field_study_country',
            'unique' => FALSE,
          ),
          10 => array(
            'source' => 'Age min',
            'target' => 'field_age_min',
            'unique' => FALSE,
          ),
          11 => array(
            'source' => 'Age Max',
            'target' => 'field_age_max',
            'unique' => FALSE,
          ),
          12 => array(
            'source' => 'Biological Samples Collected',
            'target' => 'field_biosamples_collected',
            'unique' => FALSE,
          ),
          13 => array(
            'source' => 'Biological Samples Other',
            'target' => 'field_biosamples_collected_other',
            'unique' => FALSE,
          ),
          14 => array(
            'source' => 'Biological Samples Tissues Other',
            'target' => 'field_biosamples_tissues',
            'unique' => FALSE,
          ),
          15 => array(
            'source' => 'Proceeding to Genome-Wide Association',
            'target' => 'field_gwas_analysis',
            'unique' => FALSE,
          ),
          16 => array(
            'source' => 'GWAS Number fo Participants',
            'target' => 'field_gwas_number',
            'unique' => FALSE,
          ),
          17 => array(
            'source' => 'Access to external',
            'target' => 'field_access',
            'unique' => FALSE,
          ),
          18 => array(
            'source' => 'Access to external other',
            'target' => 'field_access_other',
            'unique' => FALSE,
          ),
          19 => array(
            'source' => 'Status Start Year',
            'target' => 'field_status_start',
            'unique' => FALSE,
          ),
          20 => array(
            'source' => 'Status End Year',
            'target' => 'field_status_end',
            'unique' => FALSE,
          ),
          21 => array(
            'source' => 'Contact Name and Association',
            'target' => 'field_contact:title',
            'unique' => FALSE,
          ),
          22 => array(
            'source' => 'Published Status',
            'target' => 'status',
            'unique' => FALSE,
          ),
        ),
        'update_existing' => '2',
        'input_format' => 'plain_text',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['csv_study_information_import'] = $feeds_importer;

  return $export;
}
