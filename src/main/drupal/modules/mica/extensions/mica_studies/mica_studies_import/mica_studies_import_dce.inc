<?php
/**
 * @file
 * mica_studies_import_dce.inc
 */

function  _mica_studies_import_set_dce_properties($dom, $wrapper, $path) {
  // xpath with contact/name/title
  $xpath = new DOMXPath($dom);

  //Required field
  $title_dce = $xpath->query('/data-collection-event/title')->item(0)->nodeValue;
  if (empty($title_dce)) {
    throw new Exception(t('DCE : Field title required'));
  }
  else {
    $wrapper->title_field->set($title_dce);
    $wrapper->title->set($title_dce);
  }

  $wrapper->field_dce_start_year->set(mica_studies_import_get_node_value($xpath, '/data-collection-event/start-year'));

  $wrapper->field_dce_start_month->set(mica_studies_import_get_node_value($xpath, '/data-collection-event/start-month'));

  $wrapper->field_dce_end_year->set(mica_studies_import_get_node_value($xpath, '/data-collection-event/end-year'));

  $wrapper->field_dce_end_month->set(mica_studies_import_get_node_value($xpath, '/data-collection-event/end-month'));

  //required field
  if (empty($xpath->query('/data-collection-event/description/summary')->item(0)->nodeValue)) {
    throw new Exception(t('DCE : Field Summary description required'));
  }
  else {
    $wrapper->body->set(array(
      'value' => mica_studies_import_get_node_value($xpath, '/data-collection-event/description/body'),
      'summary' => mica_studies_import_get_node_value($xpath, '/data-collection-event/description/summary'),
      'format' => mica_studies_import_get_node_value($xpath, '/data-collection-event/description/format')
    ));
  }

  $dom_data_source_elements = $xpath->query('/data-collection-event/sources-of-data/source');
  $data_source_elements = mica_studies_import_get_node_value($xpath, '/data-collection-event/sources-of-data/source');
  $wrapper->field_dce_data_sources->set();
  if (!empty($data_source_elements)) {
    foreach ($dom_data_source_elements as $index => $data_source_element) {
      $wrapper->field_dce_data_sources[$index]->set($data_source_element->getAttribute("code"));
    }
  }
  $wrapper->field_dce_data_sources_sp->set(mica_studies_import_get_node_value($xpath, '/data-collection-event/sources-of-data/other-data-source'));

  $db_source_elements = $xpath->query('/data-collection-event/administrative-database/source');
  $wrapper->field_dce_data_sources_admin_db->set();
  if (!empty($db_source_elements)) {
    foreach ($db_source_elements as $index => $db_source_element) {
      $wrapper->field_dce_data_sources_admin_db[$index]->set($db_source_element->getAttribute("code"));
    }
  }

  $sample_elements = $xpath->query('/data-collection-event/biological-samples/sample');
  $wrapper->field_dce_bio_samples_management->set();
  if (!empty($sample_elements)) {
    foreach ($sample_elements as $index => $sample_element) {
      $wrapper->field_dce_bio_samples_management[$index]->set($sample_element->getAttribute("code"));
    }
  }

  $dom_dce_samples_man_other_sp = $xpath->query('/data-collection-event/biological-samples/other-biological-samples');
  $dce_samples_man_other_sp = mica_studies_import_get_node_value($xpath, '/data-collection-event/biological-samples/other-biological-samples');
  if (empty($dce_samples_man_other_sp)) {
    $wrapper->field_dce_samples_man_other_sp->set();

  }
  else {
    $wrapper->field_dce_samples_man_other_sp->set(array(
      'value' => $dce_samples_man_other_sp,
      'format' => $dom_dce_samples_man_other_sp->item(0)->getAttribute('format')
    ));
  }

  $wrapper->field_dce_tissues_sp->set(mica_studies_import_get_node_value($xpath, '/data-collection-event/biological-samples/tissues-type'));

  //Deal with attachment files
  _mica_import_attach_file($xpath->query('/data-collection-event/files/documents/document'), 'field_dce_questionnaires', $path, $wrapper);
  _mica_import_attach_file($xpath->query('/data-collection-event/files/standard-operating-procedures/sop'), 'field_dce_sops', $path, $wrapper);
  _mica_import_attach_file($xpath->query('/data-collection-event/files/data-dictionaries/dictionary'), 'field_dce_data_dictionaries', $path, $wrapper);
  _mica_import_attach_file($xpath->query('/data-collection-event/files/other_docs/other_doc'), 'field_dce_others', $path, $wrapper);

}