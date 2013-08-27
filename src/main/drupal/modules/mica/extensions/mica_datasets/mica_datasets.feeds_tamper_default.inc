<?php
/**
 * @file
 * mica_datasets.feeds_tamper_default.inc
 */

/**
 * Implements hook_feeds_tamper_default().
 */
function mica_datasets_feeds_tamper_default() {
  $export = array();

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'csv_variables-administrative_information-only_existing_terms';
  $feeds_tamper->importer = 'csv_variables';
  $feeds_tamper->source = 'administrative_information';
  $feeds_tamper->plugin_id = 'existing_terms';
  $feeds_tamper->settings = array(
    'vocabulary' => 'administrative_information',
  );
  $feeds_tamper->weight = 2;
  $feeds_tamper->description = 'Only existing terms';
  $export['csv_variables-administrative_information-only_existing_terms'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'csv_variables-administrative_information-trim';
  $feeds_tamper->importer = 'csv_variables';
  $feeds_tamper->source = 'administrative_information';
  $feeds_tamper->plugin_id = 'trim';
  $feeds_tamper->settings = array(
    'mask' => '',
    'side' => 'trim',
  );
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'Trim';
  $export['csv_variables-administrative_information-trim'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'csv_variables-anthropometric_structures-explode';
  $feeds_tamper->importer = 'csv_variables';
  $feeds_tamper->source = 'anthropometric_structures';
  $feeds_tamper->plugin_id = 'explode';
  $feeds_tamper->settings = array(
    'separator' => '|',
    'limit' => '',
    'real_separator' => '|',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Explode';
  $export['csv_variables-anthropometric_structures-explode'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'csv_variables-anthropometric_structures-only_existing_terms';
  $feeds_tamper->importer = 'csv_variables';
  $feeds_tamper->source = 'anthropometric_structures';
  $feeds_tamper->plugin_id = 'existing_terms';
  $feeds_tamper->settings = array(
    'vocabulary' => 'anthropometric_structures',
  );
  $feeds_tamper->weight = 2;
  $feeds_tamper->description = 'Only existing terms';
  $export['csv_variables-anthropometric_structures-only_existing_terms'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'csv_variables-anthropometric_structures-trim';
  $feeds_tamper->importer = 'csv_variables';
  $feeds_tamper->source = 'anthropometric_structures';
  $feeds_tamper->plugin_id = 'trim';
  $feeds_tamper->settings = array(
    'mask' => '',
    'side' => 'trim',
  );
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'Trim';
  $export['csv_variables-anthropometric_structures-trim'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'csv_variables-body_functions-explode';
  $feeds_tamper->importer = 'csv_variables';
  $feeds_tamper->source = 'body_functions';
  $feeds_tamper->plugin_id = 'explode';
  $feeds_tamper->settings = array(
    'separator' => '|',
    'limit' => '',
    'real_separator' => '|',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Explode';
  $export['csv_variables-body_functions-explode'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'csv_variables-body_functions-only_existing_terms';
  $feeds_tamper->importer = 'csv_variables';
  $feeds_tamper->source = 'body_functions';
  $feeds_tamper->plugin_id = 'existing_terms';
  $feeds_tamper->settings = array(
    'vocabulary' => 'body_functions',
  );
  $feeds_tamper->weight = 2;
  $feeds_tamper->description = 'Only existing terms';
  $export['csv_variables-body_functions-only_existing_terms'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'csv_variables-body_functions-trim';
  $feeds_tamper->importer = 'csv_variables';
  $feeds_tamper->source = 'body_functions';
  $feeds_tamper->plugin_id = 'trim';
  $feeds_tamper->settings = array(
    'mask' => '',
    'side' => 'trim',
  );
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'Trim';
  $export['csv_variables-body_functions-trim'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'csv_variables-body_structures-explode';
  $feeds_tamper->importer = 'csv_variables';
  $feeds_tamper->source = 'body_structures';
  $feeds_tamper->plugin_id = 'explode';
  $feeds_tamper->settings = array(
    'separator' => '|',
    'limit' => '',
    'real_separator' => '|',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Explode';
  $export['csv_variables-body_structures-explode'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'csv_variables-body_structures-only_existing_terms';
  $feeds_tamper->importer = 'csv_variables';
  $feeds_tamper->source = 'body_structures';
  $feeds_tamper->plugin_id = 'existing_terms';
  $feeds_tamper->settings = array(
    'vocabulary' => 'body_structures',
  );
  $feeds_tamper->weight = 2;
  $feeds_tamper->description = 'Only existing terms';
  $export['csv_variables-body_structures-only_existing_terms'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'csv_variables-body_structures-trim';
  $feeds_tamper->importer = 'csv_variables';
  $feeds_tamper->source = 'body_structures';
  $feeds_tamper->plugin_id = 'trim';
  $feeds_tamper->settings = array(
    'mask' => '',
    'side' => 'trim',
  );
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'Trim';
  $export['csv_variables-body_structures-trim'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'csv_variables-categories_label-explode';
  $feeds_tamper->importer = 'csv_variables';
  $feeds_tamper->source = 'categories_label';
  $feeds_tamper->plugin_id = 'explode';
  $feeds_tamper->settings = array(
    'separator' => '|',
    'limit' => '',
    'real_separator' => '|',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Explode';
  $export['csv_variables-categories_label-explode'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'csv_variables-categories_label-trim';
  $feeds_tamper->importer = 'csv_variables';
  $feeds_tamper->source = 'categories_label';
  $feeds_tamper->plugin_id = 'trim';
  $feeds_tamper->settings = array(
    'mask' => '',
    'side' => 'trim',
  );
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'Trim';
  $export['csv_variables-categories_label-trim'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'csv_variables-categories_missing-explode';
  $feeds_tamper->importer = 'csv_variables';
  $feeds_tamper->source = 'categories_missing';
  $feeds_tamper->plugin_id = 'explode';
  $feeds_tamper->settings = array(
    'separator' => '|',
    'limit' => '',
    'real_separator' => '|',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Explode';
  $export['csv_variables-categories_missing-explode'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'csv_variables-categories_missing-trim';
  $feeds_tamper->importer = 'csv_variables';
  $feeds_tamper->source = 'categories_missing';
  $feeds_tamper->plugin_id = 'trim';
  $feeds_tamper->settings = array(
    'mask' => '',
    'side' => 'trim',
  );
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'Trim';
  $export['csv_variables-categories_missing-trim'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'csv_variables-categories_name-explode';
  $feeds_tamper->importer = 'csv_variables';
  $feeds_tamper->source = 'categories_name';
  $feeds_tamper->plugin_id = 'explode';
  $feeds_tamper->settings = array(
    'separator' => '|',
    'limit' => '',
    'real_separator' => '|',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Explode';
  $export['csv_variables-categories_name-explode'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'csv_variables-categories_name-trim';
  $feeds_tamper->importer = 'csv_variables';
  $feeds_tamper->source = 'categories_name';
  $feeds_tamper->plugin_id = 'trim';
  $feeds_tamper->settings = array(
    'mask' => '',
    'side' => 'trim',
  );
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'Trim';
  $export['csv_variables-categories_name-trim'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'csv_variables-class-explode';
  $feeds_tamper->importer = 'csv_variables';
  $feeds_tamper->source = 'class';
  $feeds_tamper->plugin_id = 'explode';
  $feeds_tamper->settings = array(
    'separator' => '|',
    'limit' => '',
    'real_separator' => '|',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Explode';
  $export['csv_variables-class-explode'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'csv_variables-class-only_existing_terms';
  $feeds_tamper->importer = 'csv_variables';
  $feeds_tamper->source = 'class';
  $feeds_tamper->plugin_id = 'existing_terms';
  $feeds_tamper->settings = array(
    'vocabulary' => 'class',
  );
  $feeds_tamper->weight = 2;
  $feeds_tamper->description = 'Only existing terms';
  $export['csv_variables-class-only_existing_terms'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'csv_variables-class-trim';
  $feeds_tamper->importer = 'csv_variables';
  $feeds_tamper->source = 'class';
  $feeds_tamper->plugin_id = 'trim';
  $feeds_tamper->settings = array(
    'mask' => '',
    'side' => 'trim',
  );
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'Trim';
  $export['csv_variables-class-trim'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'csv_variables-data_source-explode';
  $feeds_tamper->importer = 'csv_variables';
  $feeds_tamper->source = 'data_source';
  $feeds_tamper->plugin_id = 'explode';
  $feeds_tamper->settings = array(
    'separator' => '|',
    'limit' => '',
    'real_separator' => '|',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Explode';
  $export['csv_variables-data_source-explode'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'csv_variables-data_source-only_existing_terms';
  $feeds_tamper->importer = 'csv_variables';
  $feeds_tamper->source = 'data_source';
  $feeds_tamper->plugin_id = 'existing_terms';
  $feeds_tamper->settings = array(
    'vocabulary' => 'data_source',
  );
  $feeds_tamper->weight = 2;
  $feeds_tamper->description = 'Only existing terms';
  $export['csv_variables-data_source-only_existing_terms'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'csv_variables-data_source-trim';
  $feeds_tamper->importer = 'csv_variables';
  $feeds_tamper->source = 'data_source';
  $feeds_tamper->plugin_id = 'trim';
  $feeds_tamper->settings = array(
    'mask' => '',
    'side' => 'trim',
  );
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'Trim';
  $export['csv_variables-data_source-trim'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'csv_variables-dataset-required_field';
  $feeds_tamper->importer = 'csv_variables';
  $feeds_tamper->source = 'dataset';
  $feeds_tamper->plugin_id = 'required';
  $feeds_tamper->settings = '';
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Required field';
  $export['csv_variables-dataset-required_field'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'csv_variables-disease_history-explode';
  $feeds_tamper->importer = 'csv_variables';
  $feeds_tamper->source = 'disease_history';
  $feeds_tamper->plugin_id = 'explode';
  $feeds_tamper->settings = array(
    'separator' => '|',
    'limit' => '',
    'real_separator' => '|',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Explode';
  $export['csv_variables-disease_history-explode'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'csv_variables-disease_history-only_existing_terms';
  $feeds_tamper->importer = 'csv_variables';
  $feeds_tamper->source = 'disease_history';
  $feeds_tamper->plugin_id = 'existing_terms';
  $feeds_tamper->settings = array(
    'vocabulary' => 'disease_history',
  );
  $feeds_tamper->weight = 2;
  $feeds_tamper->description = 'Only existing terms';
  $export['csv_variables-disease_history-only_existing_terms'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'csv_variables-disease_history-trim';
  $feeds_tamper->importer = 'csv_variables';
  $feeds_tamper->source = 'disease_history';
  $feeds_tamper->plugin_id = 'trim';
  $feeds_tamper->settings = array(
    'mask' => '',
    'side' => 'trim',
  );
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'Trim';
  $export['csv_variables-disease_history-trim'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'csv_variables-early_life-explode';
  $feeds_tamper->importer = 'csv_variables';
  $feeds_tamper->source = 'early_life';
  $feeds_tamper->plugin_id = 'explode';
  $feeds_tamper->settings = array(
    'separator' => '|',
    'limit' => '',
    'real_separator' => '|',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Explode';
  $export['csv_variables-early_life-explode'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'csv_variables-early_life-only_existing_terms';
  $feeds_tamper->importer = 'csv_variables';
  $feeds_tamper->source = 'early_life';
  $feeds_tamper->plugin_id = 'existing_terms';
  $feeds_tamper->settings = array(
    'vocabulary' => 'early_life',
  );
  $feeds_tamper->weight = 2;
  $feeds_tamper->description = 'Only existing terms';
  $export['csv_variables-early_life-only_existing_terms'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'csv_variables-early_life-trim';
  $feeds_tamper->importer = 'csv_variables';
  $feeds_tamper->source = 'early_life';
  $feeds_tamper->plugin_id = 'trim';
  $feeds_tamper->settings = array(
    'mask' => '',
    'side' => 'trim',
  );
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'Trim';
  $export['csv_variables-early_life-trim'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'csv_variables-format-explode';
  $feeds_tamper->importer = 'csv_variables';
  $feeds_tamper->source = 'format';
  $feeds_tamper->plugin_id = 'explode';
  $feeds_tamper->settings = array(
    'separator' => '|',
    'limit' => '',
    'real_separator' => '|',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Explode';
  $export['csv_variables-format-explode'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'csv_variables-format-only_existing_terms';
  $feeds_tamper->importer = 'csv_variables';
  $feeds_tamper->source = 'format';
  $feeds_tamper->plugin_id = 'existing_terms';
  $feeds_tamper->settings = array(
    'vocabulary' => 'format',
  );
  $feeds_tamper->weight = 2;
  $feeds_tamper->description = 'Only existing terms';
  $export['csv_variables-format-only_existing_terms'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'csv_variables-format-trim';
  $feeds_tamper->importer = 'csv_variables';
  $feeds_tamper->source = 'format';
  $feeds_tamper->plugin_id = 'trim';
  $feeds_tamper->settings = array(
    'mask' => '',
    'side' => 'trim',
  );
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'Trim';
  $export['csv_variables-format-trim'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'csv_variables-individual_participant_measures-only_existing_terms';
  $feeds_tamper->importer = 'csv_variables';
  $feeds_tamper->source = 'individual_participant_measures';
  $feeds_tamper->plugin_id = 'existing_terms';
  $feeds_tamper->settings = array(
    'vocabulary' => 'individual_participant_measures',
  );
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'Only existing terms';
  $export['csv_variables-individual_participant_measures-only_existing_terms'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'csv_variables-individual_participant_measures-trim';
  $feeds_tamper->importer = 'csv_variables';
  $feeds_tamper->source = 'individual_participant_measures';
  $feeds_tamper->plugin_id = 'trim';
  $feeds_tamper->settings = array(
    'mask' => '',
    'side' => 'trim',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Trim';
  $export['csv_variables-individual_participant_measures-trim'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'csv_variables-laboratory_measures-explode';
  $feeds_tamper->importer = 'csv_variables';
  $feeds_tamper->source = 'laboratory_measures';
  $feeds_tamper->plugin_id = 'explode';
  $feeds_tamper->settings = array(
    'separator' => '|',
    'limit' => '',
    'real_separator' => '|',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Explode';
  $export['csv_variables-laboratory_measures-explode'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'csv_variables-laboratory_measures-only_existing_terms';
  $feeds_tamper->importer = 'csv_variables';
  $feeds_tamper->source = 'laboratory_measures';
  $feeds_tamper->plugin_id = 'existing_terms';
  $feeds_tamper->settings = array(
    'vocabulary' => 'laboratory_measures',
  );
  $feeds_tamper->weight = 2;
  $feeds_tamper->description = 'Only existing terms';
  $export['csv_variables-laboratory_measures-only_existing_terms'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'csv_variables-laboratory_measures-trim';
  $feeds_tamper->importer = 'csv_variables';
  $feeds_tamper->source = 'laboratory_measures';
  $feeds_tamper->plugin_id = 'trim';
  $feeds_tamper->settings = array(
    'mask' => '',
    'side' => 'trim',
  );
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'Trim';
  $export['csv_variables-laboratory_measures-trim'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'csv_variables-life_habits_behaviours-explode';
  $feeds_tamper->importer = 'csv_variables';
  $feeds_tamper->source = 'life_habits_behaviours';
  $feeds_tamper->plugin_id = 'explode';
  $feeds_tamper->settings = array(
    'separator' => '|',
    'limit' => '',
    'real_separator' => '|',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Explode';
  $export['csv_variables-life_habits_behaviours-explode'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'csv_variables-life_habits_behaviours-only_existing_terms';
  $feeds_tamper->importer = 'csv_variables';
  $feeds_tamper->source = 'life_habits_behaviours';
  $feeds_tamper->plugin_id = 'existing_terms';
  $feeds_tamper->settings = array(
    'vocabulary' => 'life_habits_behaviours',
  );
  $feeds_tamper->weight = 2;
  $feeds_tamper->description = 'Only existing terms';
  $export['csv_variables-life_habits_behaviours-only_existing_terms'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'csv_variables-life_habits_behaviours-trim';
  $feeds_tamper->importer = 'csv_variables';
  $feeds_tamper->source = 'life_habits_behaviours';
  $feeds_tamper->plugin_id = 'trim';
  $feeds_tamper->settings = array(
    'mask' => '',
    'side' => 'trim',
  );
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'Trim';
  $export['csv_variables-life_habits_behaviours-trim'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'csv_variables-medical_health_interv-explode';
  $feeds_tamper->importer = 'csv_variables';
  $feeds_tamper->source = 'medical_health_interv';
  $feeds_tamper->plugin_id = 'explode';
  $feeds_tamper->settings = array(
    'separator' => '|',
    'limit' => '',
    'real_separator' => '|',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Explode';
  $export['csv_variables-medical_health_interv-explode'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'csv_variables-medical_health_interv-only_existing_terms';
  $feeds_tamper->importer = 'csv_variables';
  $feeds_tamper->source = 'medical_health_interv';
  $feeds_tamper->plugin_id = 'existing_terms';
  $feeds_tamper->settings = array(
    'vocabulary' => 'medical_health_intervention',
  );
  $feeds_tamper->weight = 2;
  $feeds_tamper->description = 'Only existing terms';
  $export['csv_variables-medical_health_interv-only_existing_terms'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'csv_variables-medical_health_interv-trim';
  $feeds_tamper->importer = 'csv_variables';
  $feeds_tamper->source = 'medical_health_interv';
  $feeds_tamper->plugin_id = 'trim';
  $feeds_tamper->settings = array(
    'mask' => '',
    'side' => 'trim',
  );
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'Trim';
  $export['csv_variables-medical_health_interv-trim'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'csv_variables-medication-explode';
  $feeds_tamper->importer = 'csv_variables';
  $feeds_tamper->source = 'medication';
  $feeds_tamper->plugin_id = 'explode';
  $feeds_tamper->settings = array(
    'separator' => '|',
    'limit' => '',
    'real_separator' => '|',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Explode';
  $export['csv_variables-medication-explode'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'csv_variables-medication-only_existing_terms';
  $feeds_tamper->importer = 'csv_variables';
  $feeds_tamper->source = 'medication';
  $feeds_tamper->plugin_id = 'existing_terms';
  $feeds_tamper->settings = array(
    'vocabulary' => 'medication',
  );
  $feeds_tamper->weight = 2;
  $feeds_tamper->description = 'Only existing terms';
  $export['csv_variables-medication-only_existing_terms'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'csv_variables-medication-trim';
  $feeds_tamper->importer = 'csv_variables';
  $feeds_tamper->source = 'medication';
  $feeds_tamper->plugin_id = 'trim';
  $feeds_tamper->settings = array(
    'mask' => '',
    'side' => 'trim',
  );
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'Trim';
  $export['csv_variables-medication-trim'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'csv_variables-perception_of_health-explode';
  $feeds_tamper->importer = 'csv_variables';
  $feeds_tamper->source = 'perception_of_health';
  $feeds_tamper->plugin_id = 'explode';
  $feeds_tamper->settings = array(
    'separator' => '|',
    'limit' => '',
    'real_separator' => '|',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Explode';
  $export['csv_variables-perception_of_health-explode'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'csv_variables-perception_of_health-only_existing_terms';
  $feeds_tamper->importer = 'csv_variables';
  $feeds_tamper->source = 'perception_of_health';
  $feeds_tamper->plugin_id = 'existing_terms';
  $feeds_tamper->settings = array(
    'vocabulary' => 'perception_of_health',
  );
  $feeds_tamper->weight = 2;
  $feeds_tamper->description = 'Only existing terms';
  $export['csv_variables-perception_of_health-only_existing_terms'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'csv_variables-perception_of_health-trim';
  $feeds_tamper->importer = 'csv_variables';
  $feeds_tamper->source = 'perception_of_health';
  $feeds_tamper->plugin_id = 'trim';
  $feeds_tamper->settings = array(
    'mask' => '',
    'side' => 'trim',
  );
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'Trim';
  $export['csv_variables-perception_of_health-trim'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'csv_variables-physical_environment-explode';
  $feeds_tamper->importer = 'csv_variables';
  $feeds_tamper->source = 'physical_environment';
  $feeds_tamper->plugin_id = 'explode';
  $feeds_tamper->settings = array(
    'separator' => '|',
    'limit' => '',
    'real_separator' => '|',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Explode';
  $export['csv_variables-physical_environment-explode'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'csv_variables-physical_environment-only_existing_terms';
  $feeds_tamper->importer = 'csv_variables';
  $feeds_tamper->source = 'physical_environment';
  $feeds_tamper->plugin_id = 'existing_terms';
  $feeds_tamper->settings = array(
    'vocabulary' => 'physical_environment',
  );
  $feeds_tamper->weight = 2;
  $feeds_tamper->description = 'Only existing terms';
  $export['csv_variables-physical_environment-only_existing_terms'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'csv_variables-physical_environment-trim';
  $feeds_tamper->importer = 'csv_variables';
  $feeds_tamper->source = 'physical_environment';
  $feeds_tamper->plugin_id = 'trim';
  $feeds_tamper->settings = array(
    'mask' => '',
    'side' => 'trim',
  );
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'Trim';
  $export['csv_variables-physical_environment-trim'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'csv_variables-reproductive_history-explode';
  $feeds_tamper->importer = 'csv_variables';
  $feeds_tamper->source = 'reproductive_history';
  $feeds_tamper->plugin_id = 'explode';
  $feeds_tamper->settings = array(
    'separator' => '|',
    'limit' => '',
    'real_separator' => '|',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Explode';
  $export['csv_variables-reproductive_history-explode'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'csv_variables-reproductive_history-only_existing_terms';
  $feeds_tamper->importer = 'csv_variables';
  $feeds_tamper->source = 'reproductive_history';
  $feeds_tamper->plugin_id = 'existing_terms';
  $feeds_tamper->settings = array(
    'vocabulary' => 'reproductive_history',
  );
  $feeds_tamper->weight = 2;
  $feeds_tamper->description = 'Only existing terms';
  $export['csv_variables-reproductive_history-only_existing_terms'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'csv_variables-reproductive_history-trim';
  $feeds_tamper->importer = 'csv_variables';
  $feeds_tamper->source = 'reproductive_history';
  $feeds_tamper->plugin_id = 'trim';
  $feeds_tamper->settings = array(
    'mask' => '',
    'side' => 'trim',
  );
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'Trim';
  $export['csv_variables-reproductive_history-trim'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'csv_variables-response_unit-explode';
  $feeds_tamper->importer = 'csv_variables';
  $feeds_tamper->source = 'response_unit';
  $feeds_tamper->plugin_id = 'explode';
  $feeds_tamper->settings = array(
    'separator' => '|',
    'limit' => '',
    'real_separator' => '|',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Explode';
  $export['csv_variables-response_unit-explode'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'csv_variables-response_unit-only_existing_terms';
  $feeds_tamper->importer = 'csv_variables';
  $feeds_tamper->source = 'response_unit';
  $feeds_tamper->plugin_id = 'existing_terms';
  $feeds_tamper->settings = array(
    'vocabulary' => 'response_unit',
  );
  $feeds_tamper->weight = 2;
  $feeds_tamper->description = 'Only existing terms';
  $export['csv_variables-response_unit-only_existing_terms'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'csv_variables-response_unit-trim';
  $feeds_tamper->importer = 'csv_variables';
  $feeds_tamper->source = 'response_unit';
  $feeds_tamper->plugin_id = 'trim';
  $feeds_tamper->settings = array(
    'mask' => '',
    'side' => 'trim',
  );
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'Trim';
  $export['csv_variables-response_unit-trim'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'csv_variables-social_environment-explode';
  $feeds_tamper->importer = 'csv_variables';
  $feeds_tamper->source = 'social_environment';
  $feeds_tamper->plugin_id = 'explode';
  $feeds_tamper->settings = array(
    'separator' => '|',
    'limit' => '',
    'real_separator' => '|',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Explode';
  $export['csv_variables-social_environment-explode'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'csv_variables-social_environment-only_existing_terms';
  $feeds_tamper->importer = 'csv_variables';
  $feeds_tamper->source = 'social_environment';
  $feeds_tamper->plugin_id = 'existing_terms';
  $feeds_tamper->settings = array(
    'vocabulary' => 'social_environment',
  );
  $feeds_tamper->weight = 2;
  $feeds_tamper->description = 'Only existing terms';
  $export['csv_variables-social_environment-only_existing_terms'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'csv_variables-social_environment-trim';
  $feeds_tamper->importer = 'csv_variables';
  $feeds_tamper->source = 'social_environment';
  $feeds_tamper->plugin_id = 'trim';
  $feeds_tamper->settings = array(
    'mask' => '',
    'side' => 'trim',
  );
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'Trim';
  $export['csv_variables-social_environment-trim'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'csv_variables-sociodemographic_charact-explode';
  $feeds_tamper->importer = 'csv_variables';
  $feeds_tamper->source = 'sociodemographic_charact';
  $feeds_tamper->plugin_id = 'explode';
  $feeds_tamper->settings = array(
    'separator' => '|',
    'limit' => '',
    'real_separator' => '|',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Explode';
  $export['csv_variables-sociodemographic_charact-explode'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'csv_variables-sociodemographic_charact-only_existing_terms';
  $feeds_tamper->importer = 'csv_variables';
  $feeds_tamper->source = 'sociodemographic_charact';
  $feeds_tamper->plugin_id = 'existing_terms';
  $feeds_tamper->settings = array(
    'vocabulary' => 'sociodemographic_characteristics',
  );
  $feeds_tamper->weight = 2;
  $feeds_tamper->description = 'Only existing terms';
  $export['csv_variables-sociodemographic_charact-only_existing_terms'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'csv_variables-sociodemographic_charact-trim';
  $feeds_tamper->importer = 'csv_variables';
  $feeds_tamper->source = 'sociodemographic_charact';
  $feeds_tamper->plugin_id = 'trim';
  $feeds_tamper->settings = array(
    'mask' => '',
    'side' => 'trim',
  );
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'Trim';
  $export['csv_variables-sociodemographic_charact-trim'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'csv_variables-target-explode';
  $feeds_tamper->importer = 'csv_variables';
  $feeds_tamper->source = 'target';
  $feeds_tamper->plugin_id = 'explode';
  $feeds_tamper->settings = array(
    'separator' => '|',
    'limit' => '',
    'real_separator' => '|',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Explode';
  $export['csv_variables-target-explode'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'csv_variables-target-only_existing_terms';
  $feeds_tamper->importer = 'csv_variables';
  $feeds_tamper->source = 'target';
  $feeds_tamper->plugin_id = 'existing_terms';
  $feeds_tamper->settings = array(
    'vocabulary' => 'target',
  );
  $feeds_tamper->weight = 2;
  $feeds_tamper->description = 'Only existing terms';
  $export['csv_variables-target-only_existing_terms'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'csv_variables-target-trim';
  $feeds_tamper->importer = 'csv_variables';
  $feeds_tamper->source = 'target';
  $feeds_tamper->plugin_id = 'trim';
  $feeds_tamper->settings = array(
    'mask' => '',
    'side' => 'trim',
  );
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'Trim';
  $export['csv_variables-target-trim'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'csv_variables-target_gender-explode';
  $feeds_tamper->importer = 'csv_variables';
  $feeds_tamper->source = 'target_gender';
  $feeds_tamper->plugin_id = 'explode';
  $feeds_tamper->settings = array(
    'separator' => '|',
    'limit' => '',
    'real_separator' => '|',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Explode';
  $export['csv_variables-target_gender-explode'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'csv_variables-target_gender-only_existing_terms';
  $feeds_tamper->importer = 'csv_variables';
  $feeds_tamper->source = 'target_gender';
  $feeds_tamper->plugin_id = 'existing_terms';
  $feeds_tamper->settings = array(
    'vocabulary' => 'target_gender',
  );
  $feeds_tamper->weight = 2;
  $feeds_tamper->description = 'Only existing terms';
  $export['csv_variables-target_gender-only_existing_terms'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'csv_variables-target_gender-trim';
  $feeds_tamper->importer = 'csv_variables';
  $feeds_tamper->source = 'target_gender';
  $feeds_tamper->plugin_id = 'trim';
  $feeds_tamper->settings = array(
    'mask' => '',
    'side' => 'trim',
  );
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'Trim';
  $export['csv_variables-target_gender-trim'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'csv_variables-value_type-required_field';
  $feeds_tamper->importer = 'csv_variables';
  $feeds_tamper->source = 'value_type';
  $feeds_tamper->plugin_id = 'required';
  $feeds_tamper->settings = '';
  $feeds_tamper->weight = 2;
  $feeds_tamper->description = 'Required field';
  $export['csv_variables-value_type-required_field'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'csv_variables-value_type-trim';
  $feeds_tamper->importer = 'csv_variables';
  $feeds_tamper->source = 'value_type';
  $feeds_tamper->plugin_id = 'trim';
  $feeds_tamper->settings = array(
    'mask' => '',
    'side' => 'trim',
  );
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'Trim';
  $export['csv_variables-value_type-trim'] = $feeds_tamper;

  return $export;
}
