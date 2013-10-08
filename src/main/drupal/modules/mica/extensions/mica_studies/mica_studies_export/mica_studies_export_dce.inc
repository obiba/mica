<?php
/**
 * @file
 * mica_export_dce.inc
 */

function _mica_studies_export_dce_xml($nid, $tmp_folder_name) {

  $wrapper = entity_metadata_wrapper('node', $nid);

  $documents = $wrapper->field_dce_questionnaires->value();
  if (isset($documents)) {
    mica_export_copy_attachment_file($documents, 'dce', $tmp_folder_name);
  }

  $dom = new DomDocument('1.0', 'utf-8');
  $root = $dom->createElement('data-collection-event');
  $root->setAttribute('uuid', $wrapper->uuid->value());
  $dom->appendChild($root);

  $root->appendChild($dom->createElement('title'))->appendChild($dom->createTextNode($wrapper->title_field->value()));

  $root->appendChild($dom->createElement('start-year'))
    ->appendChild($dom->createTextNode($wrapper->field_dce_start_year->value()));
  $root->appendChild($dom->createElement('start-month'))
    ->appendChild($dom->createTextNode($wrapper->field_dce_start_month->value()));
  $root->appendChild($dom->createElement('end-year'))
    ->appendChild($dom->createTextNode($wrapper->field_dce_end_year->value()));
  $root->appendChild($dom->createElement('end-month'))
    ->appendChild($dom->createTextNode($wrapper->field_dce_end_month->value()));

  $desc_element = $root->appendChild($dom->createElement('description'));
  $desc_element->appendChild($dom->createElement('body'))
    ->appendChild($dom->createTextNode($wrapper->body->value->value()));
  $desc_element->appendChild($dom->createElement('summary'))
    ->appendChild($dom->createTextNode($wrapper->body->summary->value()));
  $desc_element->appendChild($dom->createElement('format'))
    ->appendChild($dom->createTextNode($wrapper->body->format->value()));

  $pops_element = $root->appendChild($dom->createElement('populations'));
  foreach ($wrapper->field_dce_population->getIterator() as $pop_wrapper) {
    $pop_element = $pops_element->appendChild($dom->createElement('population'));
    $pop_element->setAttribute('ref-uuid', $pop_wrapper->uuid->value());
  }

  $source_data_element = $dom->createElement('sources-of-data');
  $root->appendChild($source_data_element);
  foreach ($wrapper->field_dce_data_sources->getIterator() as $sources) {
    $pop_element = $source_data_element->appendChild($dom->createElement('source'));
    $pop_element->appendChild($dom->createTextNode($sources->label()));
    $pop_element->setAttribute('code', $sources->value());
  }
  $source_data_element->appendChild($dom->createElement('other-data-source'))
    ->appendChild($dom->createTextNode($wrapper->field_dce_data_sources_sp->value()));

  $admin_data_element = $dom->createElement('administrative-database');
  $root->appendChild($admin_data_element);
  foreach ($wrapper->field_dce_data_sources_admin_db->getIterator() as $admin_db) {
    $pop_element = $admin_data_element->appendChild($dom->createElement('source'));
    $pop_element->appendChild($dom->createTextNode($admin_db->label()));
    $pop_element->setAttribute('code', $admin_db->value());
  }

  $bio_samples_element = $dom->createElement('biological-samples');
  $root->appendChild($bio_samples_element);
  foreach ($wrapper->field_dce_bio_samples_management->getIterator() as $biosample) {
    $pop_element = $bio_samples_element->appendChild($dom->createElement('sample'));
    $pop_element->appendChild($dom->createTextNode($biosample->label()));
    $pop_element->setAttribute('code', $biosample->value());
  }
  $bio_samples_element->appendChild($dom->createElement('other-biological-samples'))
    ->appendChild($dom->createTextNode($wrapper->field_dce_samples_man_other_sp->value()));

  $document_element = $dom->createElement('files');
  $root->appendChild($document_element);
  foreach ($wrapper->field_dce_questionnaires->value() as $document) {
    $document_detail_element = $dom->createElement('file');
    $document_element->appendChild($document_detail_element);
    $document_detail_element->appendChild($dom->createElement('filename'))
      ->appendChild($dom->createTextNode($document['filename']));
    $document_detail_element->appendChild($dom->createElement('url'))
      ->appendChild($dom->createTextNode($document['uri']));
    $document_detail_element->appendChild($dom->createElement('description'))
      ->appendChild($dom->createTextNode($document['description']));
    $document_detail_element->appendChild($dom->createElement('display'))
      ->appendChild($dom->createTextNode($document['display']));

    $document_detail_element->appendChild($dom->createElement('filemime'))
      ->appendChild($dom->createTextNode($document['filemime']));
    $document_detail_element->appendChild($dom->createElement('filesize'))
      ->appendChild($dom->createTextNode($document['filesize']));
    $document_detail_element->appendChild($dom->createElement('status'))
      ->appendChild($dom->createTextNode($document['status']));
    $document_detail_element->setAttribute('ref-uuid', $document['uuid']);

  }

  $root->appendChild($dom->createElement('tissues-type'))
    ->appendChild($dom->createTextNode($wrapper->field_dce_tissues_sp->value()));

  return $dom->saveXML();
}