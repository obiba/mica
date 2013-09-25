<?php
/**
 * @file
 * mica_export_study.inc
 */

function _mica_export_study_xml($nid, $tmp_folder_name) {

  $wrapper = entity_metadata_wrapper('node', $nid);

//Retrieve attachments files
  $documents = $wrapper->field_documents->value();
  if (isset($documents)) {
    mica_export_copy_attachment_file($documents, 'study-documents', $tmp_folder_name);
  }
  $logo = $wrapper->field_logo->value();
  if (isset($logo)) {
    mica_export_copy_attachment_file($logo, 'study-logo', $tmp_folder_name);
  }

  //Xml mapper
  $dom = new DomDocument('1.0', 'utf-8');
  $root = $dom->createElement('study');
  $root->setAttribute('uuid', $wrapper->uuid->value());
  $root->setAttribute('mica_origin_url', $wrapper->mica_origin_url->value());
  $dom->appendChild($root);

  $root->appendChild($dom->createElement('title'))->appendChild($dom->createTextNode($wrapper->title->value()));
  $root->appendChild($dom->createElement('acronym'))
    ->appendChild($dom->createTextNode($wrapper->field_acroym->value()));

  $investigators_element = $root->appendChild($dom->createElement('investigators'));
  foreach ($wrapper->field_investigators->value() as $kc => $vc) {
    $to_attrib = $investigators_element->appendChild($dom->createElement('investigator'));
    $to_attrib->setAttribute('ref-uuid', $vc->uuid);
  }

  $contacts_element = $root->appendChild($dom->createElement('contacts'));
  foreach ($wrapper->field_contacts_ref->value() as $kc => $vc) {
    $to_attrib = $contacts_element->appendChild($dom->createElement('contact'));
    $to_attrib->setAttribute('ref-uuid', $vc->uuid);
  }

  $content_element = $root->appendChild($dom->createElement('objectives'));
  $content_element->appendChild($dom->createElement('body'))
    ->appendChild($dom->createTextNode($wrapper->body->value->value()));
  $content_element->appendChild($dom->createElement('summary'))
    ->appendChild($dom->createTextNode($wrapper->body->summary->value()));
  $content_element->appendChild($dom->createElement('format'))
    ->appendChild($dom->createTextNode($wrapper->body->format->value()));

  $website_element = $dom->createElement('web-site');
  $root->appendChild($website_element);
  $website_element->appendChild($dom->createTextNode($wrapper->field_website->value() ? $wrapper->field_website->url->value() : ''));
  $study_design_element = $dom->createElement('study-designs');
  $root->appendChild($study_design_element);

  $design_element = $dom->createElement('designs');
  $study_design_element->appendChild($design_element);
  foreach ($wrapper->field_design->getIterator() as $design) {
    $to_attrib = $design_element->appendChild($dom->createElement('design'));
    $to_attrib->appendChild($dom->createTextNode($design->label()));
    $to_attrib->setAttribute('code', $design->value());
  }
  $design_element->appendChild($dom->createElement('other'))
    ->appendChild($dom->createTextNode($wrapper->field_design_other_sp->value()));

  $study_design_element->appendChild($dom->createElement('general-information-follow-up'))
    ->appendChild($dom->createTextNode($wrapper->field_info_design_follow_up->value()));

  $recruitment_target_element = $dom->createElement('recruitment-target');
  $study_design_element->appendChild($recruitment_target_element);
  foreach ($wrapper->field_recruitment->getIterator() as $target) {
    $to_attrib = $recruitment_target_element->appendChild($dom->createElement('target'));
    $to_attrib->appendChild($dom->createTextNode($target->label()));
    $to_attrib->setAttribute('code', $target->value());
  }
  $recruitment_target_element->appendChild($dom->createElement('other'))
    ->appendChild($dom->createTextNode($wrapper->field_recruitment_other_sp->value()));

  $study_design_element->appendChild($dom->createElement('supplementary-information'))
    ->appendChild($dom->createTextNode($wrapper->field_recruitment_supp_info->value()));

  $nbr_participants_element = $dom->createElement('number-participant');
  $study_design_element->appendChild($nbr_participants_element);

  $target_participants_element = $dom->createElement('target-number-of-participants');
  $nbr_participants_element->appendChild($target_participants_element);
  $target_participants_element->appendChild($dom->createElement('number'))
    ->appendChild($dom->createTextNode($wrapper->field_target_number_participants->value()));
  $target_participants_element->appendChild($dom->createElement('no-limits'))
    ->appendChild($dom->createTextNode($wrapper->field_no_limits_participants->value() ? 'true' : 'false'));

  $target_samples_element = $dom->createElement('target-number-of-participants-with-biosamples');
  $nbr_participants_element->appendChild($target_samples_element);
  $target_samples_element->appendChild($dom->createElement('number'))
    ->appendChild($dom->createTextNode($wrapper->field_target_number_biosamples->value()));
  $target_samples_element->appendChild($dom->createElement('no-limits'))
    ->appendChild($dom->createTextNode($wrapper->field_no_limits_samples->value() ? 'true' : 'false'));

  $nbr_participants_element->appendChild($dom->createElement('supplementary-information'))
    ->appendChild($dom->createTextNode($wrapper->field_target_nb_supp_info->value()));

  $timeline_element = $dom->createElement('timeline');
  $study_design_element->appendChild($timeline_element);
  $timeline_element->appendChild($dom->createElement('start-year'))
    ->appendChild($dom->createTextNode($wrapper->field_study_start_year->value()));
  $timeline_element->appendChild($dom->createElement('end-year'))
    ->appendChild($dom->createTextNode($wrapper->field_study_end_year->value()));

  $acess_element = $root->appendChild($dom->createElement('access'));
  $acess_element->appendChild($dom->createElement('data'))
    ->appendChild($dom->createTextNode($wrapper->field_access_data->value() ? 'true' : 'false'));
  $acess_element->appendChild($dom->createElement('biosamples'))
    ->appendChild($dom->createTextNode($wrapper->field_access_biosamples->value() ? 'true' : 'false'));
  $acess_element->appendChild($dom->createElement('other'))
    ->appendChild($dom->createTextNode($wrapper->field_access_other->value() ? 'true' : 'false'));
  $acess_element->appendChild($dom->createElement('other-info'))
    ->appendChild($dom->createTextNode($wrapper->field_access_other_sp->value()));

  $root->appendChild($dom->createElement('maker-paper'))
    ->appendChild($dom->createTextNode($wrapper->field_marker_paper->value()));
  $root->appendChild($dom->createElement('pubmed-id'))
    ->appendChild($dom->createTextNode($wrapper->field_pubmedid->value()));
  $root->appendChild($dom->createElement('supplementary-information'))
    ->appendChild($dom->createTextNode($wrapper->field_supp_infos->value()));

  $poplutions_element = $root->appendChild($dom->createElement('populations'));
  foreach ($wrapper->field_study_populations->value() as $kc => $vc) {
    $to_attrib = $poplutions_element->appendChild($dom->createElement('population'));
    $to_attrib->setAttribute('ref-uuid', $vc->uuid);
  }

  $files_element = $dom->createElement('files');
  $root->appendChild($files_element);

  $documents_element = $dom->createElement('documents');
  $files_element->appendChild($documents_element);

  foreach ($wrapper->field_documents->value() as $document) {

    $document_detail_element = $dom->createElement('document');
    $documents_element->appendChild($document_detail_element);
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

  $logo_detail_element = $dom->createElement('logo');
  $files_element->appendChild($logo_detail_element);
  $logo_detail_element->appendChild($dom->createElement('filename'))
    ->appendChild($dom->createTextNode($logo['filename']));
  $logo_detail_element->appendChild($dom->createElement('url'))
    ->appendChild($dom->createTextNode($logo['uri']));
  $logo_detail_element->appendChild($dom->createElement('description'))
    ->appendChild($dom->createTextNode($logo['description']));
  $logo_detail_element->appendChild($dom->createElement('display'))
    ->appendChild($dom->createTextNode($logo['display']));

  $logo_detail_element->appendChild($dom->createElement('filemime'))
    ->appendChild($dom->createTextNode($logo['filemime']));
  $logo_detail_element->appendChild($dom->createElement('filesize'))
    ->appendChild($dom->createTextNode($logo['filesize']));
  $logo_detail_element->appendChild($dom->createElement('status'))
    ->appendChild($dom->createTextNode($logo['status']));
  $logo_detail_element->setAttribute('ref-uuid', $logo['uuid']);

  $myxml = $dom->saveXML();

  return $myxml;

}