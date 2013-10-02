<?php
/**
 * @file
 * mica_studies_import_dce.inc
 */

function  _mica_studies_mica_import_set_dce_properties($dom, $wrapper, $path) {
  $errors_message = array();
  // xpath with contact/name/title
  $xpath = new DOMXPath($dom);
  $current_document = $dom->documentElement;
  $wrapper->title->set($xpath->query('/data-collection-event/title')->item(0)->nodeValue);
  $wrapper->field_dce_start_year->set($xpath->query('/data-collection-event/start-year')->item(0)->nodeValue);
  $wrapper->field_dce_start_month->set($xpath->query('/data-collection-event/start-month')->item(0)->nodeValue);
  $wrapper->field_dce_end_year->set($xpath->query('/data-collection-event/end-year')->item(0)->nodeValue);
  $wrapper->field_dce_end_month->set($xpath->query('/data-collection-event/end-month')->item(0)->nodeValue);

  $wrapper->body->value->set($xpath->query('/data-collection-event/description/body')->item(0)->nodeValue);
  $wrapper->body->summary->set($xpath->query('/data-collection-event/description/summary')->item(0)->nodeValue);
  // $wrapper->body->format->set($xpath->query('/data-collection-event/description/format')->item(0)->nodeValue);

//Create populations node
  $populations = $xpath->query('/data-collection-event/populations/population');
  foreach ($populations as $key => $population_value) {
    $population_uuid = $population_value->getAttribute("ref-uuid");
    $population_wrapper = _mica_import_find_or_create_node($population_uuid, 'population');
    if ($population_wrapper !== FALSE) {
      $nid = $population_wrapper->nid->value();
      if (empty($nid)) {
        $population_wrapper->save();
      }
      else {
        $wrapper->field_dce_population[$key]->set($population_wrapper->nid->value());
        $population_wrapper->save();
      }
    }
    else {
      $errors_message .= t('can\'t set population nid => you don\'t have permission to edit/create population</ br>');
    }
  }

  $origin_url = $current_document->getAttribute("mica_origin_url");
  if (empty($wrapper->mica_origin_url)) {
    $wrapper->mica_origin_url->set($origin_url);
  }
  $sources_data = $xpath->query('/data-collection-event/sources-of-data/source');
  foreach ($sources_data as $key_data => $source_data_value) {
    $wrapper->field_dce_data_sources[$key_data]->set($source_data_value->getAttribute("code"));
  }
  $wrapper->field_dce_data_sources_sp->set($xpath->query('/data-collection-event/sources-of-data/other-data-source')
    ->item(0)->nodeValue);

  $sources_admin_data = $xpath->query('/data-collection-event/administrative-database/source');
  foreach ($sources_admin_data as $key_data => $source_admin_data_value) {
    $wrapper->field_dce_data_sources_admin_db[$key_data]->set($source_admin_data_value->getAttribute("code"));
  }

  $bio_sample_data = $xpath->query('/data-collection-event/biological-samples/sample');
  foreach ($bio_sample_data as $key_data => $sample_value) {
    $wrapper->field_dce_bio_samples_management[$key_data]->set($sample_value->getAttribute("code"));
  }
  $wrapper->field_dce_samples_man_other_sp->set(array(
    'value' => $xpath
      ->query('/data-collection-event/biological-samples/other-biological-samples')
      ->item(0)
      ->nodeValue
  ));
  $wrapper->field_dce_tissues_sp->set($xpath->query('/data-collection-event/biological-samples/tissues-type')
    ->item(0)->nodeValue);
//Deal with attachment files
  $questionnaires = $xpath->query('/data-collection-event/files/documents/document');
  $errors_message .= _mica_import_attache_file($questionnaires, 'field_dce_questionnaires', $path, $wrapper);

  $sops = $xpath->query('/data-collection-event/files/standard-operating-procedures/sop');
  $errors_message .= _mica_import_attache_file($sops, 'field_dce_sops', $path, $wrapper);

  $dictionaries = $xpath->query('/data-collection-event/files/data-dictionaries/dictionarie');
  $errors_message .= _mica_import_attache_file($dictionaries, 'field_dce_data_dictionaries', $path, $wrapper);

  $other_documents = $xpath->query('/data-collection-event/files/other_docs/other_doc');
  $errors_message .= _mica_import_attache_file($other_documents, 'field_dce_others', $path, $wrapper);

  return $errors_message;
}