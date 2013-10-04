<?php
/**
 * @file
 * mica_export_dce.inc
 */

function _mica_studies_export_dce_xml($nid, $tmp_folder_name) {

  $wrapper = entity_metadata_wrapper('node', $nid);

  $documents = $wrapper->field_dce_questionnaires->value();
  if (isset($documents)) {
    mica_export_copy_attachment_file($documents, $tmp_folder_name);
  }

  $sops = $wrapper->field_dce_sops->value();
  if (isset($sops)) {
    mica_export_copy_attachment_file($sops, $tmp_folder_name);
  }

  $dictionaries = $wrapper->field_dce_data_dictionaries->value();
  if (isset($dictionaries)) {
    mica_export_copy_attachment_file($dictionaries, $tmp_folder_name);
  }

  $doc_others = $wrapper->field_dce_others->value();
  if (isset($doc_others)) {
    mica_export_copy_attachment_file($doc_others, $tmp_folder_name);
  }

  $dom = new DomDocument('1.0', 'utf-8');
  $root = $dom->createElement('data-collection-event');
  $root->setAttribute('uuid', $wrapper->uuid->value());
  $root->setAttribute('mica_origin_url', $wrapper->mica_origin_url->value());
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

  $gen_info_body_element = $root->appendChild($dom->createElement('description'));
  $gen_info_body_element->appendChild($dom->createElement('body'))
    ->appendChild($dom->createTextNode($wrapper->body->value->value()));
  $gen_info_body_element->appendChild($dom->createElement('summary'))
    ->appendChild($dom->createTextNode($wrapper->body->summary->value()));
  $gen_info_body_element->appendChild($dom->createElement('format'))
    ->appendChild($dom->createTextNode($wrapper->body->format->value()));

  $to_attrib_gen_info = $root->appendChild($dom->createElement('populations'));
  foreach ($wrapper->field_dce_population->getIterator() as $popula) {
    $to_attrib = $to_attrib_gen_info->appendChild($dom->createElement('population'));
    $to_attrib->setAttribute('ref-uuid', $popula->uuid->value());
  }

  $source_data_element = $dom->createElement('sources-of-data');
  $root->appendChild($source_data_element);
  foreach ($wrapper->field_dce_data_sources->getIterator() as $sources) {
    $to_attrib = $source_data_element->appendChild($dom->createElement('source'));
    $to_attrib->appendChild($dom->createTextNode($sources->label()));
    $to_attrib->setAttribute('code', $sources->value());
  }
  $source_data_element->appendChild($dom->createElement('other-data-source'))
    ->appendChild($dom->createTextNode($wrapper->field_dce_data_sources_sp->value()));

  $admin_data_element = $dom->createElement('administrative-database');
  $root->appendChild($admin_data_element);
  foreach ($wrapper->field_dce_data_sources_admin_db->getIterator() as $admindata) {
    $to_attrib = $admin_data_element->appendChild($dom->createElement('source'));
    $to_attrib->appendChild($dom->createTextNode($admindata->label()));
    $to_attrib->setAttribute('code', $admindata->value());
  }

  $bio_samples_element = $dom->createElement('biological-samples');
  $root->appendChild($bio_samples_element);
  foreach ($wrapper->field_dce_bio_samples_management->getIterator() as $biosample) {
    $to_attrib = $bio_samples_element->appendChild($dom->createElement('sample'));
    $to_attrib->appendChild($dom->createTextNode($biosample->label()));
    $to_attrib->setAttribute('code', $biosample->value());
  }
  $bio_samples_element->appendChild($dom->createElement('other-biological-samples'))
    ->appendChild($dom->createTextNode($wrapper->field_dce_samples_man_other_sp->value->value()));

  $bio_samples_element->appendChild($dom->createElement('tissues-type'))
    ->appendChild($dom->createTextNode($wrapper->field_dce_tissues_sp->value()));

  $files_element = $dom->createElement('files');
  $root->appendChild($files_element);
  $document_element = $dom->createElement('documents');
  $files_element->appendChild($document_element);
  foreach ($wrapper->field_dce_questionnaires->value() as $document) {
    $document_detail_element = $dom->createElement('document');
    $document_element->appendChild($document_detail_element);
    $document_detail_element->appendChild($dom->createElement('filename'))
      ->appendChild($dom->createTextNode($document['filename']));
    $document_detail_element->appendChild($dom->createElement('description'))
      ->appendChild($dom->createTextNode($document['description']));

    $document_detail_element->appendChild($dom->createElement('filemime'))
      ->appendChild($dom->createTextNode($document['filemime']));
    $document_detail_element->appendChild($dom->createElement('filesize'))
      ->appendChild($dom->createTextNode($document['filesize']));
    $document_detail_element->setAttribute('ref-uuid', $document['uuid']);
  }

  $sop_element = $dom->createElement('standard-operating-procedures');
  $files_element->appendChild($sop_element);
  foreach ($wrapper->field_dce_sops->value() as $document) {
    $sop_detail_element = $dom->createElement('sop');
    $sop_element->appendChild($sop_detail_element);
    $sop_detail_element->appendChild($dom->createElement('filename'))
      ->appendChild($dom->createTextNode($document['filename']));
    $sop_detail_element->appendChild($dom->createElement('description'))
      ->appendChild($dom->createTextNode($document['description']));

    $sop_detail_element->appendChild($dom->createElement('filemime'))
      ->appendChild($dom->createTextNode($document['filemime']));
    $sop_detail_element->appendChild($dom->createElement('filesize'))
      ->appendChild($dom->createTextNode($document['filesize']));
    $sop_detail_element->setAttribute('ref-uuid', $document['uuid']);
  }

  $dictionaries_element = $dom->createElement('data-dictionaries');
  $files_element->appendChild($dictionaries_element);
  foreach ($wrapper->field_dce_data_dictionaries->value() as $document) {
    $dictionaries_detail_element = $dom->createElement('dictionarie');
    $dictionaries_element->appendChild($dictionaries_detail_element);
    $dictionaries_detail_element->appendChild($dom->createElement('filename'))
      ->appendChild($dom->createTextNode($document['filename']));
    $dictionaries_detail_element->appendChild($dom->createElement('description'))
      ->appendChild($dom->createTextNode($document['description']));

    $dictionaries_detail_element->appendChild($dom->createElement('filemime'))
      ->appendChild($dom->createTextNode($document['filemime']));
    $dictionaries_detail_element->appendChild($dom->createElement('filesize'))
      ->appendChild($dom->createTextNode($document['filesize']));
    $dictionaries_detail_element->setAttribute('ref-uuid', $document['uuid']);
  }

  $doc_others_element = $dom->createElement('other_docs');
  $files_element->appendChild($doc_others_element);
  foreach ($wrapper->field_dce_others->value() as $document) {
    $doc_others_detail_element = $dom->createElement('other_doc');
    $doc_others_element->appendChild($doc_others_detail_element);
    $doc_others_detail_element->appendChild($dom->createElement('filename'))
      ->appendChild($dom->createTextNode($document['filename']));
    $doc_others_detail_element->appendChild($dom->createElement('description'))
      ->appendChild($dom->createTextNode($document['description']));

    $doc_others_detail_element->appendChild($dom->createElement('filemime'))
      ->appendChild($dom->createTextNode($document['filemime']));
    $doc_others_detail_element->appendChild($dom->createElement('filesize'))
      ->appendChild($dom->createTextNode($document['filesize']));
    $doc_others_detail_element->setAttribute('ref-uuid', $document['uuid']);
  }

  return $dom->saveXML();
}