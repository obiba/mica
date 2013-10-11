<?php
/**
 * @file
 * mica_studies_import_dce.inc
 */

function  _mica_studies_mica_import_set_dce_properties($dom, $wrapper, $path) {
  // xpath with contact/name/title
  $xpath = new DOMXPath($dom);

  //Required field
  if (!empty($xpath->query('/data-collection-event/title')->item(0)->nodeValue)) {
    $wrapper->title_field->set($xpath->query('/data-collection-event/title')->item(0)->nodeValue);
    $wrapper->title->set($xpath->query('/data-collection-event/title')->item(0)->nodeValue);
  }
  else {
    try {
      $wrapper->title->set();
      $wrapper->title_field->set();
    } catch (Exception $e) {
      throw new Exception(t('DCE : Field title required'));
    }
  }

  $start_year = $xpath->query('/data-collection-event/start-year')->item(0)->nodeValue;
  $wrapper->field_dce_start_year->set();
  if (!empty($start_year)) {
    $wrapper->field_dce_start_year->set($start_year);
  }

  $start_month = $xpath->query('/data-collection-event/start-month')->item(0)->nodeValue;
  $wrapper->field_dce_start_month->set();
  if (!empty($start_month)) {
    $wrapper->field_dce_start_month->set($start_month);
  }

  $end_year = $xpath->query('/data-collection-event/end-year')->item(0)->nodeValue;
  $wrapper->field_dce_end_year->set();
  if (!empty($end_year)) {
    $wrapper->field_dce_end_year->set($end_year);
  }

  $end_month = $xpath->query('/data-collection-event/end-month')->item(0)->nodeValue;
  $wrapper->field_dce_end_month->set();
  if (!empty($end_month)) {
    $wrapper->field_dce_end_month->set($end_month);
  }

  if (!empty($xpath->query('/data-collection-event/description/body')->item(0)->nodeValue)) {
    $wrapper->body->set(array(
      'value' => $xpath->query('/data-collection-event/description/body')->item(0)->nodeValue,
      'summary' => $xpath->query('/data-collection-event/description/summary')->item(0)->nodeValue,
      'format' => $xpath->query('/data-collection-event/description/format')->item(0)->nodeValue
    ));
  }
  else {
    try {
      $wrapper->body->set();
    } catch (Exception $e) {
      throw new Exception(t('DCE : Field Body description required'));

    }

  }

  $data_source_elements = $xpath->query('/data-collection-event/sources-of-data/source');
  $wrapper->field_dce_data_sources->set();
  if (!empty($data_source_elements)) {
    foreach ($data_source_elements as $index => $data_source_element) {
      $wrapper->field_dce_data_sources[$index]->set($data_source_element->getAttribute("code"));
    }
  }

  $dce_data_sources_sp = $xpath->query('/data-collection-event/sources-of-data/other-data-source')->item(0)->nodeValue;
  $wrapper->field_dce_data_sources_sp->set();
  if (!empty($dce_data_sources_sp)) {
    $wrapper->field_dce_data_sources_sp->set($dce_data_sources_sp);
  }

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
  $dce_samples_man_other_sp = $dom_dce_samples_man_other_sp->item(0)->nodeValue;
  $wrapper->field_dce_samples_man_other_sp->set();
  if (!empty($dce_samples_man_other_sp)) {
    $wrapper->field_dce_samples_man_other_sp->set(array(
      'value' => $dce_samples_man_other_sp,
      'format' => $dom_dce_samples_man_other_sp->item(0)->getAttribute('format')
    ));
  }

  $dce_tissues_sp = $xpath->query('/data-collection-event/biological-samples/tissues-type')->item(0)->nodeValue;
  $wrapper->field_dce_tissues_sp->set();
  if (!empty($dce_tissues_sp)) {
    $wrapper->field_dce_tissues_sp->set($dce_tissues_sp);
  }
  //Deal with attachment files
  _mica_import_attach_file($xpath->query('/data-collection-event/files/documents/document'), 'field_dce_questionnaires', $path, $wrapper);
  _mica_import_attach_file($xpath->query('/data-collection-event/files/standard-operating-procedures/sop'), 'field_dce_sops', $path, $wrapper);
  _mica_import_attach_file($xpath->query('/data-collection-event/files/data-dictionaries/dictionary'), 'field_dce_data_dictionaries', $path, $wrapper);
  _mica_import_attach_file($xpath->query('/data-collection-event/files/other_docs/other_doc'), 'field_dce_others', $path, $wrapper);

}