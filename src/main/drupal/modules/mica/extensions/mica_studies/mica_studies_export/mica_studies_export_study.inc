<?php
/**
 * @file
 * mica_studies_export_contact.inc
 */

function mica_studies_export_study_fields_map($nid){

  $wrapper = entity_metadata_wrapper('node', $nid);

  $dom = new DomDocument('1.0', 'utf-8');
  $root = $dom->createElement('study');
  $root->setAttribute('uuid', $wrapper->uuid->value());
  $dom->appendChild($root);

  $name_element = $root->appendChild($dom->createElement('name'));
  $name_element->appendChild($dom->createElement('title'))->appendChild($dom->createTextNode($wrapper->title_field->value()));
  $name_element->appendChild($dom->createElement('acronym'))->appendChild($dom->createTextNode($wrapper->field_acroym->value()));

  $investigators_element = $root->appendChild($dom->createElement('investigators'));
          foreach($wrapper->field_investigators->value() as $kc=>$vc){
             $to_attrib = $investigators_element->appendChild($dom->createElement('investigator'));
             $to_attrib ->setAttribute('uuid',$vc->uuid);
           }

  $contacts_element = $root->appendChild($dom->createElement('contacts'));
  foreach($wrapper->field_contacts_ref->value() as $kc=>$vc){
    $to_attrib = $contacts_element->appendChild($dom->createElement('contact'));
    $to_attrib ->setAttribute('uuid',$vc->uuid);
  }

  $content_element = $root->appendChild($dom->createElement('content'));
  $content_element->appendChild($dom->createElement('body'))->appendChild($dom->createTextNode($wrapper->body->value->value()));
  $content_element->appendChild($dom->createElement('summary'))->appendChild($dom->createTextNode($wrapper->body->summary->value()));
  $content_element->appendChild($dom->createElement('format'))->appendChild($dom->createTextNode($wrapper->body->format->value()));

  $website_element = $dom->createElement('web-site');
  $root->appendChild($website_element);
  $website_element->appendChild($dom->createTextNode($wrapper->field_website->url->value()));

  $methods_element =  $dom->createElement('methods');
  $root->appendChild($methods_element);

  $study_design_element =  $dom->createElement('study-designs');
  $methods_element->appendChild($study_design_element);

  $design_element =  $dom->createElement('designs');
  $study_design_element->appendChild($design_element);
  foreach ( $wrapper->field_design->getIterator() as $design) {
    $to_attrib = $design_element->appendChild($dom->createElement('design'));
    $to_attrib->appendChild($dom->createTextNode($design->label()));
    $to_attrib ->setAttribute('code-design',$design->value());
  }

  $study_design_element->appendChild($dom->createElement('other-design'))->appendChild($dom->createTextNode($wrapper->field_design_other_sp->value()));
  $study_design_element->appendChild($dom->createElement('general-information-follow-up'))->appendChild($dom->createTextNode($wrapper->field_info_design_follow_up->value()));

  $recruitment_target_element =  $dom->createElement('recruitment-target');
  $study_design_element->appendChild($recruitment_target_element );
  foreach ( $wrapper->field_recruitment->getIterator() as $target) {
    $to_attrib = $recruitment_target_element ->appendChild($dom->createElement('target'));
    $to_attrib->appendChild($dom->createTextNode($target->label()));
    $to_attrib ->setAttribute('code-target',$target->value());
  }

  $study_design_element->appendChild($dom->createElement('other-recruitment-target'))->appendChild($dom->createTextNode($wrapper->field_recruitment_other_sp->value()));
  $study_design_element->appendChild($dom->createElement('supplementary-information-about-study-design'))->appendChild($dom->createTextNode($wrapper->field_recruitment_supp_info->value()));

  $nbr_participants_element =  $dom->createElement('number-participant');
  $methods_element->appendChild($nbr_participants_element);

  $target_participants_element =  $dom->createElement('target-participant');
  $nbr_participants_element->appendChild($target_participants_element);
  $target_participants_element->appendChild($dom->createElement('target-number-of-participants'))->appendChild($dom->createTextNode($wrapper->field_target_number_participants->value()));
  $target_participants_element->appendChild($dom->createElement('no-limits-in-the-number-of-participants'))->appendChild($dom->createTextNode($wrapper->field_no_limits_participants->value()));

  $target_samples_element =  $dom->createElement('target-samples');
  $nbr_participants_element->appendChild($target_samples_element);
  $target_samples_element->appendChild($dom->createElement('target-number-biosamples'))->appendChild($dom->createTextNode($wrapper->field_target_number_biosamples->value()));
  $target_samples_element->appendChild($dom->createElement('no-limits-samples'))->appendChild($dom->createTextNode($wrapper->field_no_limits_samples->value()));

  $nbr_participants_element->appendChild($dom->createElement('other-info-target-number-participants'))->appendChild($dom->createTextNode($wrapper->field_target_nb_supp_info->value()));


  $timeline_element =  $dom->createElement('Timeline');
  $methods_element->appendChild($timeline_element);
  $timeline_element->appendChild($dom->createElement('start-year'))->appendChild($dom->createTextNode($wrapper->field_study_start_year->value()));
  $timeline_element->appendChild($dom->createElement('end-year'))->appendChild($dom->createTextNode($wrapper->field_study_end_year->value()));


  $acess_element = $root->appendChild($dom->createElement('access'));
  $acess_element->appendChild($dom->createElement('data'))->appendChild($dom->createTextNode($wrapper->field_access_data->value()));
  $acess_element->appendChild($dom->createElement('biosamples'))->appendChild($dom->createTextNode($wrapper->field_access_biosamples->value()));
  $acess_element->appendChild($dom->createElement('other'))->appendChild($dom->createTextNode($wrapper->field_access_other->value()));
  $acess_element->appendChild($dom->createElement('other-info'))->appendChild($dom->createTextNode($wrapper->field_access_other_sp->value()));

  $maker_paper_element = $root->appendChild($dom->createElement('maker-paper'));
  $maker_paper_element->appendChild($dom->createElement('maker-paper'))->appendChild($dom->createTextNode($wrapper->field_marker_paper->value()));
  $maker_paper_element->appendChild($dom->createElement('pubmed-id'))->appendChild($dom->createTextNode($wrapper->field_pubmedid->value()));

  $sup_info_element = $root->appendChild($dom->createElement('supplementary-information'));
  $sup_info_element->appendChild($dom->createElement('supplementary-information'))->appendChild($dom->createTextNode($wrapper->field_supp_infos->value()));

  $poplutions_element = $root->appendChild($dom->createElement('populations'));
  foreach($wrapper->field_study_populations->value() as $kc=>$vc){
    $to_attrib = $poplutions_element->appendChild($dom->createElement('population'));
    $to_attrib ->setAttribute('uuid',$vc->uuid);
  }

  $myxml = $dom->saveXML();

  return $myxml;

}