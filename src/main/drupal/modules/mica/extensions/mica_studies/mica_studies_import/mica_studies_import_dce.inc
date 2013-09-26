<?php
/**
 * @file
 * mica_studies_import_dce.inc
 */

function  _mica_study_import_get_dce_structure($dom, $wrapper) {

  // xpath with contact/name/title
  $xpath = new DOMXPath($dom);
  $current_document = $dom->documentElement;
  $origin_url = $current_document->getAttribute("mica_origin_url");

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
    $population_wrapper = _mica_import_find_or_create_node($population_uuid, 'population', $origin_url);
    $nid = $population_wrapper->nid->value();
    if (empty($nid)) {
      $population_wrapper->save();
    }

    $wrapper->field_dce_population[$key]->set($population_wrapper->nid->value());
    $population_wrapper->save();
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
}