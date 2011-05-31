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
  $feeds_importer->id = 'csv_contact_import';
  $feeds_importer->config = array(
    'name' => 'Contact',
    'description' => 'Import Contact from a CSV file',
    'fetcher' => array(
      'plugin_key' => 'FeedsFileFetcher',
      'config' => array(
        'allowed_extensions' => 'txt csv',
        'direct' => 0,
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsMultiValueCSVParser',
      'config' => array(
        'delimiter' => ';',
        'no_headers' => 0,
        'multivalue_separator' => '|',
        'multivalue_trim_spaces' => 1,
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsUniqueNodeProcessor',
      'config' => array(
        'content_type' => 'contact',
        'expire' => '-1',
        'author' => 0,
        'key_field' => 'title',
        'mappings' => array(
          0 => array(
            'source' => 'title',
            'target' => 'title',
            'unique' => FALSE,
          ),
          1 => array(
            'source' => 'field_contact_name:title',
            'target' => 'field_contact_name:title',
            'unique' => FALSE,
          ),
          2 => array(
            'source' => 'field_contact_name:given',
            'target' => 'field_contact_name:given',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'field_contact_name:family',
            'target' => 'field_contact_name:family',
            'unique' => FALSE,
          ),
          4 => array(
            'source' => 'field_telephone',
            'target' => 'field_telephone',
            'unique' => FALSE,
          ),
          5 => array(
            'source' => 'field_institution',
            'target' => 'field_institution:title',
            'unique' => FALSE,
          ),
          6 => array(
            'source' => 'title',
            'target' => 'guid',
            'unique' => 1,
          ),
          7 => array(
            'source' => 'field_contact_email:email',
            'target' => 'field_contact_email:email',
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
  $export['csv_contact_import'] = $feeds_importer;

  $feeds_importer = new stdClass;
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'csv_field_description_import';
  $feeds_importer->config = array(
    'name' => 'Field Description',
    'description' => 'Import Field Description from a CSV file',
    'fetcher' => array(
      'plugin_key' => 'FeedsFileFetcher',
      'config' => array(
        'allowed_extensions' => 'txt csv',
        'direct' => 0,
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsMultiValueCSVParser',
      'config' => array(
        'delimiter' => ';',
        'no_headers' => 0,
        'multivalue_separator' => '|',
        'multivalue_trim_spaces' => 1,
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsUniqueNodeProcessor',
      'config' => array(
        'content_type' => 'field_description',
        'expire' => '-1',
        'author' => 0,
        'key_field' => 'title',
        'mappings' => array(
          0 => array(
            'source' => 'title',
            'target' => 'title',
            'unique' => FALSE,
          ),
          1 => array(
            'source' => 'title',
            'target' => 'guid',
            'unique' => 1,
          ),
          2 => array(
            'source' => 'field_bundle',
            'target' => 'field_bundle',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'field_value_type',
            'target' => 'field_value_type',
            'unique' => FALSE,
          ),
          4 => array(
            'source' => 'field_original_field_name',
            'target' => 'field_original_field_name',
            'unique' => FALSE,
          ),
          5 => array(
            'source' => 'body',
            'target' => 'body',
            'unique' => FALSE,
          ),
          6 => array(
            'source' => 'field_original_field_label',
            'target' => 'field_original_field_label',
            'unique' => FALSE,
          ),
          7 => array(
            'source' => 'field_bundle_label',
            'target' => 'field_bundle_label',
            'unique' => FALSE,
          ),
          8 => array(
            'source' => 'field_categories',
            'target' => 'field_categories',
            'unique' => FALSE,
          ),
          9 => array(
            'source' => 'field_repeatable',
            'target' => 'field_repeatable',
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
  $export['csv_field_description_import'] = $feeds_importer;

  $feeds_importer = new stdClass;
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'csv_institution_import';
  $feeds_importer->config = array(
    'name' => 'Institution',
    'description' => 'Import Institution from a CSV file',
    'fetcher' => array(
      'plugin_key' => 'FeedsFileFetcher',
      'config' => array(
        'allowed_extensions' => 'txt csv',
        'direct' => 0,
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsMultiValueCSVParser',
      'config' => array(
        'delimiter' => ';',
        'no_headers' => 0,
        'multivalue_separator' => '|',
        'multivalue_trim_spaces' => 1,
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsUniqueNodeProcessor',
      'config' => array(
        'content_type' => 'institution',
        'expire' => '-1',
        'author' => 0,
        'key_field' => 'title',
        'mappings' => array(
          0 => array(
            'source' => 'title',
            'target' => 'guid',
            'unique' => 1,
          ),
          1 => array(
            'source' => 'field_street',
            'target' => 'field_street',
            'unique' => FALSE,
          ),
          2 => array(
            'source' => 'field_city',
            'target' => 'field_city',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'field_postal_code',
            'target' => 'field_postal_code',
            'unique' => FALSE,
          ),
          4 => array(
            'source' => 'title',
            'target' => 'title',
            'unique' => FALSE,
          ),
          5 => array(
            'source' => 'field_country_text',
            'target' => 'field_country_text',
            'unique' => FALSE,
          ),
        ),
        'update_existing' => '2',
        'input_format' => 'filtered_html',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['csv_institution_import'] = $feeds_importer;

  $feeds_importer = new stdClass;
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'csv_study_files_importer';
  $feeds_importer->config = array(
    'name' => 'Study Files',
    'description' => 'Import Study Files from a CSV file',
    'fetcher' => array(
      'plugin_key' => 'FeedsFileFetcher',
      'config' => array(
        'allowed_extensions' => 'txt csv',
        'direct' => 0,
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsMultiValueCSVParser',
      'config' => array(
        'delimiter' => ';',
        'no_headers' => 0,
        'multivalue_separator' => '|',
        'multivalue_trim_spaces' => 1,
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsMicaProcessor',
      'config' => array(
        'content_type' => 'study_files',
        'expire' => '-1',
        'author' => 0,
		'parent_bundle' => 'study',
        'parent_unique_id_field' => 'field_study_legacy_id',
        'mappings' => array(
          0 => array(
            'source' => 'field_study_legacy_id',
            'target' => 'field_study_legacy_id',
            'unique' => FALSE,
          ),
          1 => array(
            'source' => 'field_study_legacy_id',
            'target' => 'guid',
            'unique' => 1,
          ),
          2 => array(
            'source' => 'title',
            'target' => 'title',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'body',
            'target' => 'body',
            'unique' => FALSE,
          ),
          4 => array(
            'source' => 'field_study_files',
            'target' => 'field_study_files',
            'unique' => FALSE,
          ),
        ),
        'update_existing' => '1',
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
  $export['csv_study_files_importer'] = $feeds_importer;

  $feeds_importer = new stdClass;
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'csv_study_import';
  $feeds_importer->config = array(
    'name' => 'Study',
    'description' => 'Import Study from a CSV file',
    'fetcher' => array(
      'plugin_key' => 'FeedsFileFetcher',
      'config' => array(
        'allowed_extensions' => 'txt csv',
        'direct' => 0,
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsMultiValueCSVParser',
      'config' => array(
        'delimiter' => ';',
        'no_headers' => 0,
        'multivalue_separator' => '|',
        'multivalue_trim_spaces' => 1,
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsUniqueNodeProcessor',
      'config' => array(
        'content_type' => 'study',
        'expire' => '-1',
        'author' => 0,
        'key_field' => 'field_study_legacy_id',
        'mappings' => array(
          0 => array(
            'source' => 'title',
            'target' => 'title',
            'unique' => FALSE,
          ),
          1 => array(
            'source' => 'body',
            'target' => 'body',
            'unique' => FALSE,
          ),
          2 => array(
            'source' => 'field_study_legacy_id',
            'target' => 'field_study_legacy_id',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'field_website',
            'target' => 'field_website:url',
            'unique' => FALSE,
          ),
          4 => array(
            'source' => 'field_study_legacy_id',
            'target' => 'guid',
            'unique' => 1,
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
      'plugin_key' => 'FeedsMultiValueCSVParser',
      'config' => array(
        'delimiter' => ';',
        'no_headers' => 0,
        'multivalue_separator' => '|',
        'multivalue_trim_spaces' => 1,
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsMicaProcessor',
      'config' => array(
        'content_type' => 'study_information',
        'expire' => '-1',
        'author' => 0,
        'parent_bundle' => 'study',
        'parent_unique_id_field' => 'field_study_legacy_id',
        'mappings' => array(
          0 => array(
            'source' => 'field_study_legacy_id',
            'target' => 'guid',
            'unique' => 1,
          ),
          1 => array(
            'source' => 'title',
            'target' => 'title',
            'unique' => FALSE,
          ),
          2 => array(
            'source' => 'field_investigator',
            'target' => 'field_investigator:title',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'field_contact',
            'target' => 'field_contact:title',
            'unique' => FALSE,
          ),
          4 => array(
            'source' => 'field_design',
            'target' => 'field_design',
            'unique' => FALSE,
          ),
          5 => array(
            'source' => 'field_design_other',
            'target' => 'field_design_other',
            'unique' => FALSE,
          ),
          6 => array(
            'source' => 'field_design_target',
            'target' => 'field_design_target',
            'unique' => FALSE,
          ),
          7 => array(
            'source' => 'field_target_other',
            'target' => 'field_target_other',
            'unique' => FALSE,
          ),
          8 => array(
            'source' => 'field_target_number_participants',
            'target' => 'field_target_number_participants',
            'unique' => FALSE,
          ),
          9 => array(
            'source' => 'field_selection_criteria',
            'target' => 'field_selection_criteria',
            'unique' => FALSE,
          ),
          10 => array(
            'source' => 'field_gender',
            'target' => 'field_gender',
            'unique' => FALSE,
          ),
          11 => array(
            'source' => 'field_study_country',
            'target' => 'field_study_country',
            'unique' => FALSE,
          ),
          12 => array(
            'source' => 'field_age_min',
            'target' => 'field_age_min',
            'unique' => FALSE,
          ),
          13 => array(
            'source' => 'field_age_max',
            'target' => 'field_age_max',
            'unique' => FALSE,
          ),
          14 => array(
            'source' => 'field_biosamples_collected',
            'target' => 'field_biosamples_collected',
            'unique' => FALSE,
          ),
          15 => array(
            'source' => 'field_biosamples_collected_other',
            'target' => 'field_biosamples_collected_other',
            'unique' => FALSE,
          ),
          16 => array(
            'source' => 'field_biosamples_tissues',
            'target' => 'field_biosamples_tissues',
            'unique' => FALSE,
          ),
          17 => array(
            'source' => 'field_gwas_analysis',
            'target' => 'field_gwas_analysis',
            'unique' => FALSE,
          ),
          18 => array(
            'source' => 'field_gwas_number',
            'target' => 'field_gwas_number',
            'unique' => FALSE,
          ),
          19 => array(
            'source' => 'field_access',
            'target' => 'field_access',
            'unique' => FALSE,
          ),
          20 => array(
            'source' => 'field_access_other',
            'target' => 'field_access_other',
            'unique' => FALSE,
          ),
          21 => array(
            'source' => 'field_status_start',
            'target' => 'field_status_start',
            'unique' => FALSE,
          ),
          22 => array(
            'source' => 'field_status_end',
            'target' => 'field_status_end',
            'unique' => FALSE,
          ),
          23 => array(
            'source' => 'field_study_legacy_id',
            'target' => 'field_study_legacy_id',
            'unique' => FALSE,
          ),
          24 => array(
            'source' => 'field_full_name',
            'target' => 'field_full_name',
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
