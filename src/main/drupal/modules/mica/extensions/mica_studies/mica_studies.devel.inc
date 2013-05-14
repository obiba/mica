<?php

function _mica_studies_devel_form() {

  $form = array();
  $form['migrate'] = array(
    '#type' => 'fieldset',
    '#title' => t('Migration'),
    '#description' => t('Migrate to longitudinal studies'),
  );
  $form['migrate']['migration'] = array(
    '#type' => 'submit',
    '#value' => t('Run migration method'),
    '#submit' => array('_mica_studies_longitudinal_migration'),
  );
  $form['migrate']['clear'] = array(
    '#type' => 'submit',
    '#value' => t('Run clear method'),
    '#submit' => array('_mica_studies_longitudinal_migration_clear'),
  );

  $form['stepbystep'] = array(
    '#type' => 'fieldset',
    '#title' => t('study migration upgrade step by step'),
    '#description' => NULL,
  );
  $form['stepbystep']['revert'] = array(
    '#type' => 'submit',
    '#value' => t('Run revert method'),
    '#submit' => array('_mica_studies_revert'),
  );
  $form['stepbystep']['upgrade'] = array(
    '#type' => 'submit',
    '#value' => t('Run upgrade method'),
    '#submit' => array('_migrate_content_types'),
  );
  $form['stepbystep']['delete'] = array(
    '#type' => 'submit',
    '#value' => t('Run delete method'),
    '#submit' => array('_delete_deprecated_fields_groups'),
  );
  $form['stepbystep']['delete'] = array(
    '#type' => 'submit',
    '#value' => t('Run delete method'),
    '#submit' => array('_delete_deprecated_fields_groups'),
  );

  $form['field_descriptions'] = array(
    '#type' => 'fieldset',
    '#title' => t('Field Descriptions'),
    '#description' => t('Generate field descriptions for study, population & events'),
  );
  $form['field_descriptions']['run'] = array(
    '#type' => 'submit',
    '#value' => t('Generate field descriptions'),
    '#submit' => array('_mica_studies_devel_generate_field_description'),
  );

  return $form;
}

function _mica_studies_devel_generate_field_description() {

  $header = array(
    'title',
    'body',
    'field_original_field_label',
    'field_original_field_name',
    'field_bundle_label',
    'field_bundle',
    'field_value_type',
    'field_categories',
    'field_repeatable'
  );
  $rows = array($header);
  foreach (field_info_instances('node', 'study') as $field) {
    $field_info = field_info_field($field['field_name']);
    $label = empty($field['display_label']) ? $field['label'] : $field['display_label'];
    $categories = array();
    if (!empty($field_info['settings']) && !empty($field_info['settings']['allowed_values'])) {
      foreach ($field_info['settings']['allowed_values'] as $key => $value) {
        $categories[] = $key . '=' . $value;
      }
    }
    $rows[] = array(
      "Study \xBB $label",
      "",
      "$label",
      $field['field_name'],
      'Study',
      'study',
      mica_field_description_get_field_value_type($field['widget']['type']),
      implode('|', $categories),
      $field_info['cardinality'] == 1 ? 0 : 1,
    );
  }

  foreach (field_info_instances('node', 'population') as $field) {
    $field_info = field_info_field($field['field_name']);
    $label = empty($field['display_label']) ? $field['label'] : $field['display_label'];
    $categories = array();
    if (!empty($field_info['settings']) && !empty($field_info['settings']['allowed_values'])) {
      foreach ($field_info['settings']['allowed_values'] as $key => $value) {
        $categories[] = $key . '=' . $value;
      }
    }
    $rows[] = array(
      "Study Population \xBB $label",
      "",
      "$label",
      $field['field_name'],
      'Population',
      'population',
      mica_field_description_get_field_value_type($field['widget']['type']),
      implode('|', $categories),
      $field_info['cardinality'] == 1 ? 0 : 1,
    );
  }

  foreach (field_info_instances('node', 'data_collection_event') as $field) {
    $field_info = field_info_field($field['field_name']);
    $label = empty($field['display_label']) ? $field['label'] : $field['display_label'];
    $categories = array();
    if (!empty($field_info['settings']) && !empty($field_info['settings']['allowed_values'])) {
      foreach ($field_info['settings']['allowed_values'] as $key => $value) {
        $categories[] = $key . '=' . $value;
      }
    }
    $rows[] = array(
      "Study Collection Event \xBB $label",
      "",
      "$label",
      $field['field_name'],
      'Data Collection Event',
      'data_collection_event',
      mica_field_description_get_field_value_type($field['widget']['type']),
      implode('|', $categories),
      $field_info['cardinality'] == 1 ? 0 : 1,
    );
  }

  // send response headers to the browser
  drupal_add_http_header('Content-Type', 'text/csv');
  drupal_add_http_header('Content-Disposition', 'attachment;filename=study_field_description.csv');
  $fp = fopen('php://output', 'w');
  foreach ($rows as $line) {
    fputcsv($fp, $line, ';', '"');
  }
  fclose($fp);
  drupal_exit();
}

