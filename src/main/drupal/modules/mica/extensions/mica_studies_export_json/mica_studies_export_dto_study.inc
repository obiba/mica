<?php
/**
 * @file
 * mica_export_study.inc
 */
require_once('mica_studies_export_dto_api.inc');

function _mica_studies_export_dto_study_dto($node, &$context) {
  $dto_util = new QuerySendDto();
  $wrapper = entity_metadata_wrapper('node', $node);
  $wrapper_id = $wrapper->uuid->value();
  $study_dto = _mica_studies_export_dto_construct_study_dto($dto_util, $wrapper, $context);
  $codec = new \DrSlump\Protobuf\Codec\Json();
  //create study-dto
  $study_dto->setId($wrapper_id);
  $data = $study_dto->serialize($codec);

  $context['results']['study']['title_study'] = $wrapper->title->value();
  $context['results']['study']['study_json'] = $data;
}

function _mica_studies_export_dto_construct_study_dto($dto_util, $wrapper, &$context) {

  $study_dto = new obiba\mica\StudyDto;
  $dto_util->_mica_studies_export_dto_add_translated_Field($study_dto, 'addName', $wrapper, 'title_field');

  $study_acronym = $wrapper->field_acroym->value();
  if (!empty($study_acronym)) {
    $dto_util->_mica_studies_export_dto_add_translated_Field($study_dto, 'addAcronym', $wrapper, 'field_acroym');
  }

  foreach ($wrapper->field_investigators->getIterator() as $investigator_wrapper) {
    if (!empty($investigator_wrapper)) {
      $investigator = _mica_studies_export_dto_contact_dto($dto_util, $investigator_wrapper);
      $study_dto->addInvestigators($investigator);
    }
  }

  //$study_dto->addObjectives($dto_util->_set_LocalizedStringDto($wrapper->body->value->value()));
  $dto_util->_mica_studies_export_dto_add_translated_Field($study_dto, 'addObjectives', $wrapper, 'body', 'value');

  $url_website = $wrapper->field_website->value();
  if (!empty($url_website)) {
    $study_dto->setWebsite($url_website['url']);
  };

  $opal_study = $wrapper->mica_opal->value();
  if (!empty($opal_study)) {
    $study_dto->setOpal($opal_study['url']);
  };

  foreach ($wrapper->field_contacts_ref->getIterator() as $contact_wrapper) {
    if (!empty($contact_wrapper)) {
      $contact = _mica_studies_export_dto_contact_dto($dto_util, $contact_wrapper);
      $study_dto->addContacts($contact);
    }
  }

  $authorization_spec_dto = new \obiba\mica\AuthorizationDto();
  $authorization_spec_dto->setAuthorized($wrapper->field_authorization_specific->value());
  $authorization_spec_dto->setAuthorizer($wrapper->field_authorising_person_name->value());
  //@TODO Bug when exporting :Text '1350964800' could not be parsed at index 0 <Jira : MICASERVER-46>
  // $authorization_spec_dto->setDate($wrapper->field_authorising_date->value());
  $study_dto->setSpecificAuthorization($authorization_spec_dto);

  $authorization_maelstrom_dto = new \obiba\mica\AuthorizationDto();
  $authorization_maelstrom_dto->setAuthorized($wrapper->field_authorization_maelstrom->value());
  $authorization_maelstrom_dto->setAuthorizer($wrapper->field_authorising_person_name_m->value());
  //@TODO Bug when exporting :Text '1350964800' could not be parsed at index 0 <Jira : MICASERVER-46>
  //$authorization_maelstrom_dto->setDate($wrapper->field_authorising_date_m->value());
  $study_dto->setMaelstromAuthorization($authorization_maelstrom_dto);

  $study_methods_dto = new \obiba\mica\StudyDto\StudyMethodsDto();
  foreach ($wrapper->field_design->getIterator() as $design) {
    $study_methods_dto->addDesigns($design->value());
    if ($design->value() == 'other') {
      $design_other_sp = $wrapper->field_design_other_sp->value();
      // dpm( $wrapper->language('en')->field_design_other_sp->value());
      if (!empty($design_other_sp)) {
        $dto_util->_mica_studies_export_dto_add_translated_Field($study_methods_dto, 'addOtherDesign', $wrapper,
          'field_design_other_sp', 'value');
      }
    }
  }
  $info_design_follow_up = $wrapper->field_info_design_follow_up->value();

  if (!empty($info_design_follow_up)) {
    $dto_util->_mica_studies_export_dto_add_translated_Field($study_methods_dto, 'addFollowUpInfo', $wrapper,
      'field_info_design_follow_up', 'value');
  }

  foreach ($wrapper->field_recruitment->getIterator() as $target) {
    $study_methods_dto->addRecruitments($target->value());
    if ($target->value() == 'other') {
      $recruitment_other_sp = $wrapper->field_recruitment_other_sp->value();
      if (!empty($recruitment_other_sp)) {
        $dto_util->_mica_studies_export_dto_add_translated_Field($study_methods_dto, 'addOtherRecruitment', $wrapper,
          'field_recruitment_other_sp');
      }
    }
  }

  $recruitment_supp_info = $wrapper->field_recruitment_supp_info->value();
  if (!empty($recruitment_supp_info)) {
    $dto_util->_mica_studies_export_dto_add_translated_Field($study_methods_dto, 'addInfo', $wrapper,
      'field_recruitment_supp_info', 'value');
  }

  $study_dto->setMethods($study_methods_dto);

  $participant_sample['number'] = $wrapper->field_target_number_participants->value();
  $participant_sample['noLimit'] = $wrapper->field_no_limits_participants->value();
  $biosample['number'] = $wrapper->field_target_number_biosamples->value();
  $biosample['noLimit'] = $wrapper->field_no_limits_samples->value();
  $study_dto->setNumberOfParticipants(
    mica_studies_export_dto_set_number_of_participants($participant_sample,
      $biosample, $wrapper, 'field_target_nb_supp_info'));

  $study_dto->setStartYear($wrapper->field_study_start_year->value());
  $study_dto->setEndYear($wrapper->field_study_end_year->value());

  if ($wrapper->field_access_data->value() == 1) {
    $study_dto->addAccess('data');
  }
  if ($wrapper->field_access_biosamples->value() == 1) {
    $study_dto->addAccess('biosamples');
  }
  if ($wrapper->field_access_other->value() == 1) {
    $study_dto->addAccess('other');
    $access_other_info = $wrapper->field_access_other_sp->value();
    if (!empty($access_other_info)) {
      $dto_util->_mica_studies_export_dto_add_translated_Field($study_dto, 'addOtherAccess', $wrapper,
        'field_access_other_sp', 'value');
    }
  }

  $study_dto->setMarkerPaper($wrapper->field_marker_paper->value());
  $study_dto->setPubmedId($wrapper->field_pubmedid->value());

  $supl_info = $wrapper->field_supp_infos->value();

  if (!empty($supl_info)) {
    $dto_util->_mica_studies_export_dto_add_translated_Field($study_dto, 'addInfo', $wrapper,
      'field_supp_infos', 'value');
  }

  foreach ($wrapper->field_study_populations->getIterator() as $population_wrapper) {
    if (!empty($population_wrapper)) {
      $population = _mica_studies_export_dto_population_dto($dto_util, $population_wrapper, $context);
      $study_dto->addPopulations($population);
    }
  }

  $attachments_files = array();

  $logo = $wrapper->field_logo->value();
  if (!empty($logo['filename'])) {
    $attachment_logo_dto = $dto_util->_mica_studies_export_dto_attachement_construct($logo, 'logo');
    $attachments_files[] = array(
      'uuid' => $logo['uuid'],
      'filename' => $logo['filename'],
      'uri' => $logo['uri']
    );
    $study_dto->setLogo($attachment_logo_dto);
  }

  foreach ($wrapper->field_documents->value() as $attachment) {
    if (!empty($attachment['filename'])) {
      $attachment_dto = $dto_util->_mica_studies_export_dto_attachement_construct($attachment, 'document');
      $attachments_files[] = array(
        'uuid' => $attachment['uuid'],
        'filename' => $attachment['filename'],
        'uri' => $attachment['uri']
      );
      $study_dto->addAttachments($attachment_dto);
    }
  }

  if (!empty($attachments_files)) {
    $context['results']['study']['attachments'] = $attachments_files;
  }
  return $study_dto;
}

function mica_studies_export_dto_set_number_of_participants($participant = NULL, $sample = NULL, $wrapper, $field) {
  $participant_dto = new \obiba\mica\StudyDto\NumberOfParticipantsDto();
  $dto_util = new QuerySendDto();
  $participant_dto->setParticipant(mica_studies_export_dto_set_target_number_dto($participant));
  $participant_dto->setSample(mica_studies_export_dto_set_target_number_dto($sample));
  $value_field = $wrapper->{$field}->value();
  !empty($value_field) ? $dto_util->_mica_studies_export_dto_add_translated_Field($participant_dto, 'addInfo', $wrapper, $field, 'value') : NULL;
  return $participant_dto;
}

function mica_studies_export_dto_set_target_number_dto($target) {
  $target_number = new \obiba\mica\TargetNumberDto();
  $target_number->setNumber($target['number']);
  $target_number->setNoLimit($target['noLimit']);
  return $target_number;
}