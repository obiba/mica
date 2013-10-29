<?php
/**
 * @file
 * mica_export_dce.inc
 */

function _mica_studies_export_dce_xml($nid, $tmp_folder_name) {

  $wrapper = entity_metadata_wrapper('node', $nid);
  if (isset($wrapper->field_dce_questionnaires)) {
    mica_export_copy_attachment_file($wrapper->field_dce_questionnaires->value(), $tmp_folder_name);
  }
  if (isset($wrapper->field_dce_sops)) {
    mica_export_copy_attachment_file($wrapper->field_dce_sops->value(), $tmp_folder_name);
  }
  if (isset($wrapper->field_dce_data_dictionaries)) {
    mica_export_copy_attachment_file($wrapper->field_dce_data_dictionaries->value(), $tmp_folder_name);
  }
  if (isset($wrapper->field_dce_others)) {
    mica_export_copy_attachment_file($wrapper->field_dce_others->value(), $tmp_folder_name);
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
  $dce_body = $wrapper->body->value();
  $gen_info_body_element->appendChild($dom->createElement('body'))
    ->appendChild($dom->createTextNode(isset($dce_body) ? $wrapper->body->value->value() : ''));
  $gen_info_body_element->appendChild($dom->createElement('summary'))
    ->appendChild($dom->createTextNode(isset($dce_body) ? $wrapper->body->summary->value() : ''));
  $gen_info_body_element->appendChild($dom->createElement('format'))
    ->appendChild($dom->createTextNode(isset($dce_body) ? $wrapper->body->format->value() : ''));

  $populations_element = $root->appendChild($dom->createElement('populations'));
  foreach ($wrapper->field_dce_population->getIterator() as $pop_wrapper) {
    $element = $populations_element->appendChild($dom->createElement('population'));
    $element->setAttribute('ref-uuid', $pop_wrapper->uuid->value());
  }

  $source_data_element = $dom->createElement('sources-of-data');
  $root->appendChild($source_data_element);
  foreach ($wrapper->field_dce_data_sources->getIterator() as $sources) {
    $element = $source_data_element->appendChild($dom->createElement('source'));
    $element->appendChild($dom->createTextNode($sources->label()));
    $element->setAttribute('code', $sources->value());
  }
  $source_data_element->appendChild($dom->createElement('other-data-source'))
    ->appendChild($dom->createTextNode($wrapper->field_dce_data_sources_sp->value()));

  $admin_data_element = $dom->createElement('administrative-database');
  $root->appendChild($admin_data_element);
  foreach ($wrapper->field_dce_data_sources_admin_db->getIterator() as $admindata) {
    $element = $admin_data_element->appendChild($dom->createElement('source'));
    $element->appendChild($dom->createTextNode($admindata->label()));
    $element->setAttribute('code', $admindata->value());
  }

  $bio_samples_element = $dom->createElement('biological-samples');
  $root->appendChild($bio_samples_element);
  foreach ($wrapper->field_dce_bio_samples_management->getIterator() as $biosample) {
    $element = $bio_samples_element->appendChild($dom->createElement('sample'));
    $element->appendChild($dom->createTextNode($biosample->label()));
    $element->setAttribute('code', $biosample->value());
  }

  $dce_samples_man_other_sp = $wrapper->field_dce_samples_man_other_sp->value();
  $parent_bio_samples_element = $bio_samples_element->appendChild($dom->createElement('other-biological-samples'));
  $parent_bio_samples_element->appendChild($dom->createTextNode(isset($dce_samples_man_other_sp) ? $wrapper->field_dce_samples_man_other_sp->value->value() : ''));
  $parent_bio_samples_element->setAttribute('format', isset($dce_samples_man_other_sp) ? $wrapper->field_dce_samples_man_other_sp->format->value() : '');
  $bio_samples_element->appendChild($dom->createElement('tissues-type'))
    ->appendChild($dom->createTextNode($wrapper->field_dce_tissues_sp->value()));

  $files_element = $dom->createElement('files');
  $root->appendChild($files_element);
  $document_element = $dom->createElement('documents');
  $files_element->appendChild($document_element);
  if (isset($wrapper->field_dce_questionnaires)) {
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
  }
  $sop_element = $dom->createElement('standard-operating-procedures');
  $files_element->appendChild($sop_element);
  if (isset($wrapper->field_dce_sops)) {
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
  }
  $dictionaries_element = $dom->createElement('data-dictionaries');
  $files_element->appendChild($dictionaries_element);
  if (isset($wrapper->field_dce_data_dictionaries)) {
    foreach ($wrapper->field_dce_data_dictionaries->value() as $document) {
      $dictionaries_detail_element = $dom->createElement('dictionary');
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
  }
  $doc_others_element = $dom->createElement('other_docs');
  $files_element->appendChild($doc_others_element);
  if (isset($wrapper->field_dce_others)) {
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
  }

  return $dom->saveXML();
}