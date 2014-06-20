<?php
/**
 * @file
 * mica_export_study.inc
 */
require_once('mica_studies_export_dto_api.inc');
function _mica_studies_export_dto_study_dto($nid) {

  $study = array();
  $wrapper = entity_metadata_wrapper('node', $nid);
  $dto_util = new QuerySendDto();

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
      $population = _mica_studies_export_dto_population_dto($dto_util, $population_wrapper);
      $study_dto->addPopulations($population);
    }
  }
  $logo = $wrapper->field_logo->value();
  $logo_tmp_file = mica_studies_send_attachement($logo);
  // dpm($logo_tmp_file);
  if (!empty($logo_tmp_file)) {
    $attachement_dto = new \obiba\mica\AttachmentDto;
    $attachement_dto->setId($logo_tmp_file);
    $attachement_dto->setFileName($logo['filename']);
    $attachement_dto->setType('document');
    $attachement_dto->setLang('en');
    $attachement_dto->setJustUploaded(TRUE);

    $study_dto->setLogo($attachement_dto);
  }
  unset($attachement_dto);
  foreach ($wrapper->field_documents->value() as $attachement) {
    $id_file_server_response = mica_studies_send_attachement($attachement);
    //  dpm($id_file_server_response);
    //  *******************************attachment
    if (!empty($id_file_server_response)) {
      $attachement_dto = new \obiba\mica\AttachmentDto;
      $attachement_dto->setId($id_file_server_response);
      $attachement_dto->setFileName($attachement['filename']);
      $attachement_dto->setType('document');
      $attachement_dto->setLang('en');
      $attachement_dto->setJustUploaded(TRUE);

      $study_dto->addAttachments($attachement_dto);
    }
  }
  //**********************************
//  //TODO Attach networks to study
//  if (module_exists('mica_networks')) {
//    foreach ($wrapper->field_networks->getIterator() as $network_wrapper) {
//      $network = _mica_studies_export_dto_network_dto($dto_util, $network_wrapper);
//    }
// //   $study_dto->addNetworks($network);
//  }

  $codec = new \DrSlump\Protobuf\Codec\Json();
  $data = $study_dto->serialize($codec);
  dpm($data);
  //dpm($data);
  //$url = 'http://198.168.138.210:8082/ws/draft/studies'; //ramin
  $url = 'http://localhost:8082/ws/draft/studies';

  $post = new HttpClientRequest($url, array(
    'method' => POST,
    'headers' => array('Content-Type' => array('application/json')),
    'data' => $data,
    'parameters' => array(),
  ));

  try {
    $client = new HttpClient($formatter = FALSE);
    $body = $client->execute($post);
  } catch (HttpClientException $e) {
    if ($e->getCode() == 0) {
      // curl error

      throw new Exception($e->getMessage());
    }
    elseif (!in_array($e->getCode(), array(200, 201, 202, 203, 204, 205, 206))) {
      dpm($e->getResponse());
      drupal_set_message(t('Export error'), $type = 'error');
      drupal_set_message($e->getResponse()->body, $type = 'error');
      //  throw $e;
    }

    $body = $e->getResponse()->body;
  }

  return TRUE;
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