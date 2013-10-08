<?php
/**
 * @file
 * mica_studies_import_dce.inc
 */

function  _mica_studies_mica_import_set_dce_properties($dom, $wrapper, $path) {
  // xpath with contact/name/title
  $xpath = new DOMXPath($dom);
  $current_document = $dom->documentElement;
  $wrapper->title->set($xpath->query('/data-collection-event/title')->item(0)->nodeValue);
  $wrapper->field_dce_start_year->set($xpath->query('/data-collection-event/start-year')->item(0)->nodeValue);
  $wrapper->field_dce_start_month->set($xpath->query('/data-collection-event/start-month')->item(0)->nodeValue);
  $wrapper->field_dce_end_year->set($xpath->query('/data-collection-event/end-year')->item(0)->nodeValue);
  $wrapper->field_dce_end_month->set($xpath->query('/data-collection-event/end-month')->item(0)->nodeValue);

  $wrapper->body->set(array(
    'value' => $xpath->query('/data-collection-event/description/body')->item(0)->nodeValue,
    'summary' => $xpath->query('/data-collection-event/description/summary')->item(0)->nodeValue,
    'format' => $xpath->query('/data-collection-event/description/format')->item(0)->nodeValue
  ));

  //TODO remove this as it already done
  $origin_url = $current_document->getAttribute("mica_origin_url");
  $uuid = $current_document->getAttribute("uuid");
  //Can't set mica_origin_url using  wrapper  Error : .. 'Entity property mica_origin_url doesn't support writing
  if (!empty($origin_url)) {
    $nodes = entity_load('node', FALSE, array('uuid' => $uuid));
    foreach ($nodes as $node) {
      $node->mica_origin_url = $origin_url;
      node_save($node);
    }
  }

  $data_source_elements = $xpath->query('/data-collection-event/sources-of-data/source');
  foreach ($data_source_elements as $index => $data_source_element) {
    $wrapper->field_dce_data_sources[$index]->set($data_source_element->getAttribute("code"));
  }
  $wrapper->field_dce_data_sources_sp->set($xpath->query('/data-collection-event/sources-of-data/other-data-source')
    ->item(0)->nodeValue);

  $db_source_elements = $xpath->query('/data-collection-event/administrative-database/source');
  foreach ($db_source_elements as $index => $db_source_element) {
    $wrapper->field_dce_data_sources_admin_db[$index]->set($db_source_element->getAttribute("code"));
  }

  $sample_elements = $xpath->query('/data-collection-event/biological-samples/sample');
  foreach ($sample_elements as $index => $sample_element) {
    $wrapper->field_dce_bio_samples_management[$index]->set($sample_element->getAttribute("code"));
  }
  $wrapper->field_dce_samples_man_other_sp->set(array(
    'value' => $xpath->query('/data-collection-event/biological-samples/other-biological-samples')->item(0)->nodeValue
  ));
  $wrapper->field_dce_tissues_sp->set($xpath->query('/data-collection-event/biological-samples/tissues-type')
    ->item(0)->nodeValue);

  //Deal with attachment files
  _mica_import_attach_file($xpath->query('/data-collection-event/files/documents/document'), 'field_dce_questionnaires', $path, $wrapper);
  _mica_import_attach_file($xpath->query('/data-collection-event/files/standard-operating-procedures/sop'), 'field_dce_sops', $path, $wrapper);
  _mica_import_attach_file($xpath->query('/data-collection-event/files/data-dictionaries/dictionary'), 'field_dce_data_dictionaries', $path, $wrapper);
  _mica_import_attach_file($xpath->query('/data-collection-event/files/other_docs/other_doc'), 'field_dce_others', $path, $wrapper);

}