<?php
/**
 * @file
 * mica_export_study.inc
 */

function _mica_studies_export_study_xml($nid, $tmp_folder_name) {

  $wrapper = entity_metadata_wrapper('node', $nid);

  // Retrieve attachments files
  mica_export_copy_attachment_file($wrapper->field_documents->value(), $tmp_folder_name);

  $logo = $wrapper->field_logo->value();
  $logo_adapt[0] = $logo;
  mica_export_copy_attachment_file($logo_adapt, $tmp_folder_name);

  //Xml mapper
  $dom = new DomDocument('1.0', 'utf-8');
  $root = $dom->createElement('study');

  $root->setAttribute('uuid', $wrapper->uuid->value());
  $root->setAttribute('mica_origin_url', $wrapper->mica_origin_url->value());
  $dom->appendChild($root);

  $root->appendChild($dom->createElement('title'))->appendChild($dom->createTextNode($wrapper->title_field->value()));
  $study_acronym = $wrapper->field_acroym->value();
  $root->appendChild($dom->createElement('acronym'))
    ->appendChild($dom->createTextNode(isset($study_acronym) ? $wrapper->field_acroym->value() : ''));

  $investigators_element = $root->appendChild($dom->createElement('investigators'));
  foreach ($wrapper->field_investigators->getIterator() as $investigator_wrapper) {
    if (isset($investigator_wrapper)) {
      $element = $investigators_element->appendChild($dom->createElement('investigator'));
      $element->setAttribute('ref-uuid', $investigator_wrapper->uuid->value());
    }
  }

  $contacts_element = $root->appendChild($dom->createElement('contacts'));
  foreach ($wrapper->field_contacts_ref->getIterator() as $contact_wrapper) {
    if (isset($contact_wrapper)) {
      $element = $contacts_element->appendChild($dom->createElement('contact'));
      $element->setAttribute('ref-uuid', $contact_wrapper->uuid->value());
    }
  }

  $content_element = $root->appendChild($dom->createElement('objectives'));
  $study_body = $wrapper->body->value();
  $content_element->appendChild($dom->createElement('body'))
    ->appendChild($dom->createTextNode(isset($study_body) ? $wrapper->body->value->value() : ''));
  $content_element->appendChild($dom->createElement('summary'))
    ->appendChild($dom->createTextNode(isset($study_body) ? $wrapper->body->summary->value() : ''));
  $content_element->appendChild($dom->createElement('format'))
    ->appendChild($dom->createTextNode(isset($study_body) ? $wrapper->body->format->value() : 'filtered_html'));

  $website_element = $dom->createElement('web-site');
  $root->appendChild($website_element);
  $website_element->appendChild($dom->createTextNode($wrapper->field_website->value() ? $wrapper->field_website->url->value() : ''));
  $study_design_element = $dom->createElement('study-designs');
  $root->appendChild($study_design_element);

  $design_element = $dom->createElement('designs');
  $study_design_element->appendChild($design_element);
  foreach ($wrapper->field_design->getIterator() as $design) {
    $element = $design_element->appendChild($dom->createElement('design'));
    $element->appendChild($dom->createTextNode($design->label()));
    $element->setAttribute('code', $design->value());
  }

  $design_oth_inf = $wrapper->field_design_other_sp->value();
  $design_other_info = $design_element->appendChild($dom->createElement('other_design'));
  $design_other_info->appendChild($dom->createTextNode(isset($design_oth_inf) ? $wrapper->field_design_other_sp->value->value() : ''));
  $design_other_info->setAttribute('format', isset($design_oth_inf) ? $wrapper->field_design_other_sp->format->value() : 'filtered_html');

  $general_info_follow_up = $study_design_element->appendChild($dom->createElement('general-information-follow-up'));

  $gen = $wrapper->field_info_design_follow_up->value();
  $general_info_follow_up->appendChild($dom->createTextNode(isset($gen) ? $wrapper->field_info_design_follow_up->value->value() : ''));
  $general_info_follow_up->setAttribute('format', isset($gen) ? $wrapper->field_info_design_follow_up->format->value() : 'filtered_html');

  $recruitment_target_element = $dom->createElement('recruitment-target');
  $study_design_element->appendChild($recruitment_target_element);
  foreach ($wrapper->field_recruitment->getIterator() as $target) {
    $element = $recruitment_target_element->appendChild($dom->createElement('target'));
    $element->appendChild($dom->createTextNode($target->label()));
    $element->setAttribute('code', $target->value());
  }
  $recruitment_target_element->appendChild($dom->createElement('other_target'))
    ->appendChild($dom->createTextNode($wrapper->field_recruitment_other_sp->value()));

  $recrut_sup_info = $wrapper->field_recruitment_supp_info->value();
  $recrut_supplementary_information = $study_design_element->appendChild($dom->createElement('supplementary-information'));
  $recrut_supplementary_information->appendChild($dom->createTextNode(isset($recrut_sup_info) ? $wrapper->field_recruitment_supp_info->value->value() : ''));
  $recrut_supplementary_information->setAttribute('format', isset($recrut_sup_info) ? $wrapper->field_recruitment_supp_info->format->value() : 'filtered_html');

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

  $target_nb_supp_info = $wrapper->field_target_nb_supp_info->value();
  $recrut_target_nb_supp_info = $nbr_participants_element->appendChild($dom->createElement('supplementary-information'));
  $recrut_target_nb_supp_info->appendChild($dom->createTextNode(isset($target_nb_supp_info) ? $wrapper->field_target_nb_supp_info->value->value() : ''));
  $recrut_target_nb_supp_info->setAttribute('format', isset($target_nb_supp_info) ? $wrapper->field_target_nb_supp_info->format->value() : 'filtered_html');

  $timeline_element = $dom->createElement('timeline');
  $study_design_element->appendChild($timeline_element);
  $timeline_element->appendChild($dom->createElement('start-year'))
    ->appendChild($dom->createTextNode($wrapper->field_study_start_year->value()));
  $timeline_element->appendChild($dom->createElement('end-year'))
    ->appendChild($dom->createTextNode($wrapper->field_study_end_year->value()));
  $acess_element = $root->appendChild($dom->createElement('access'));
  $acess_element->appendChild($dom->createElement('data'))
    ->appendChild($dom->createTextNode($wrapper->field_access_data->value() == '1' ? 'true' : ($wrapper->field_access_data->value() == '0' ? 'false' : '')));
  $acess_element->appendChild($dom->createElement('biosamples'))
    ->appendChild($dom->createTextNode($wrapper->field_access_biosamples->value() == '1' ? 'true' : ($wrapper->field_access_biosamples->value() == '0' ? 'false' : '')));
  $acess_element->appendChild($dom->createElement('other_access'))
    ->appendChild($dom->createTextNode(($wrapper->field_access_other->value() == 1) ? 'true' : (($wrapper->field_access_other->value() == 0 ? 'false' : ''))));

  $oth_inf = $wrapper->field_access_other_sp->value();
  $other_info = $acess_element->appendChild($dom->createElement('other-info'));
  $other_info->appendChild($dom->createTextNode(isset($oth_inf) ? $wrapper->field_access_other_sp->value->value() : ''));
  $other_info->setAttribute('format', isset($oth_inf) ? $wrapper->field_access_other_sp->format->value() : 'filtered_html');

  $root->appendChild($dom->createElement('maker-paper'))
    ->appendChild($dom->createTextNode($wrapper->field_marker_paper->value()));
  $root->appendChild($dom->createElement('pubmed-id'))
    ->appendChild($dom->createTextNode($wrapper->field_pubmedid->value()));

  $parti_sup_info = $wrapper->field_supp_infos->value();
  $partic_supplementary_information = $root->appendChild($dom->createElement('supplementary-information'));
  $partic_supplementary_information->appendChild($dom->createTextNode(isset($parti_sup_info) ? $wrapper->field_supp_infos->value->value() : ''));
  $partic_supplementary_information->setAttribute('format', isset($parti_sup_info) ? $wrapper->field_supp_infos->format->value() : 'filtered_html');

  $poplutions_element = $root->appendChild($dom->createElement('populations'));
  foreach ($wrapper->field_study_populations->getIterator() as $population_wrapper) {
    $element = $poplutions_element->appendChild($dom->createElement('population'));
    $element->setAttribute('ref-uuid', $population_wrapper->uuid->value());
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
    $document_detail_element->appendChild($dom->createElement('description'))
      ->appendChild($dom->createTextNode($document['description']));

    $document_detail_element->appendChild($dom->createElement('filemime'))
      ->appendChild($dom->createTextNode($document['filemime']));
    $document_detail_element->appendChild($dom->createElement('filesize'))
      ->appendChild($dom->createTextNode($document['filesize']));
    $document_detail_element->setAttribute('ref-uuid', $document['uuid']);

  }

  $logo_detail_element = $dom->createElement('logo');
  $files_element->appendChild($logo_detail_element);
  $logo_detail_element->appendChild($dom->createElement('filename'))
    ->appendChild($dom->createTextNode($logo['filename']));
  $logo_detail_element->appendChild($dom->createElement('description'))
    ->appendChild($dom->createTextNode($logo['description']));

  $logo_detail_element->appendChild($dom->createElement('filemime'))
    ->appendChild($dom->createTextNode($logo['filemime']));
  $logo_detail_element->appendChild($dom->createElement('filesize'))
    ->appendChild($dom->createTextNode($logo['filesize']));
  $logo_detail_element->setAttribute('ref-uuid', $logo['uuid']);

  return $dom->saveXML();
}