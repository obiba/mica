<?php
/**
 * @file
 * mica_network_export_dto_dataset.inc
 */
$path_module_protobuf = drupal_get_path('module', 'obiba_protobuf');
include_once($path_module_protobuf . '/protobuf/Protobuf.php');
use \DrSlump\Protobuf;

function _mica_studies_export_dto_network_dto($node, $wrapper) {

  $dataset_gen_dto = NULL;
  $dataset_type_parse = NULL;
  $resource_serv = NULL;
  $node_type = NULL;
  $hamonizaed_dataset_dto = NULL;
  $wrapper_study = entity_metadata_wrapper('node', $node);

  $dto_util = new QuerySendDto();

  foreach ($wrapper_study->field_networks->getIterator() as $network_wrapper) {
    $mica_server_network_id = NULL;
    $network_finded_mica_server = NULL;
    $network_node = node_load($network_wrapper->getIdentifier());
    $mica_server_network_id = trim($network_node->mica_server_id);
    if (!empty($mica_server_network_id)) {
      $network_find_mica_server_json = $dto_util->get_from_mica_server('/draft/network/' . $mica_server_network_id);

      $dtoObj = new \obiba\mica\NetworkDto;
      $codec = new \DrSlump\Protobuf\Codec\Json();
      $network_find_mica_server = $codec->decode($dtoObj, $network_find_mica_server_json);

      if (empty($network_find_mica_server_json)) {
        $network_find_mica_server = $dto_util->get_from_mica_server('/network/' . $mica_server_network_id);

        $dtoObj = new \obiba\mica\DatasetDto;
        $codec = new \DrSlump\Protobuf\Codec\Json();
        $network_find_mica_server = $codec->decode($dtoObj, $network_find_mica_server_json);
      }
    }
  }

  $network_dto = new obiba\mica\NetworkDto();

  //@TODO populate network field
/////////////////////////////////////
  $network_title = $wrapper->title_field->value();
  if (!empty($network_title)) {
    $dto_util->_mica_studies_export_dto_add_translated_Field($network_dto, 'addName',
      $wrapper, 'title_field');
  }

  $network_acronym = $wrapper->field_acroym->value();
  if (!empty($network_acronym)) {
    $dto_util->_mica_studies_export_dto_add_translated_Field($network_dto, 'addAcronym', $wrapper, 'field_acroym');
  }

  $dto_util->_mica_studies_export_dto_add_translated_Field($network_dto, 'addDescription', $wrapper, 'body', 'value');

  $url_website = $wrapper->field_website->value();
  if (!empty($url_website)) {
    $network_dto->setWebsite($url_website['url']);
  };

  $authorization_maelstrom_dto = new \obiba\mica\AuthorizationDto();
  $authorization_maelstrom_dto->setAuthorized($wrapper->field_authorization_maelstrom->value());
  $authorization_maelstrom_dto->setAuthorizer($wrapper->field_authorising_person_name_m->value());
  $authorization_maelstrom_dto->setDate($wrapper->field_authorising_date_m->value());
  //@TODO Bug when exporting :Text '1350964800' could not be parsed at index 0 <Jira : MICASERVER-46>
  //$authorization_maelstrom_dto->setDate($wrapper->field_authorising_date_m->value());
  $network_dto->setMaelstromAuthorization($authorization_maelstrom_dto);

  foreach ($wrapper->field_investigators->getIterator() as $investigator_wrapper) {
    if (!empty($investigator_wrapper)) {
      $investigator = _mica_studies_export_dto_contact_dto($dto_util, $investigator_wrapper);
      $network_dto->addInvestigators($investigator);
    }
  }

  foreach ($wrapper->field_contacts_ref->getIterator() as $contact_wrapper) {
    if (!empty($contact_wrapper)) {
      $contact = _mica_studies_export_dto_contact_dto($dto_util, $contact_wrapper);
      $network_dto->addContacts($contact);
    }
  }

  //Add Logo attachment to Dto Network in server Side
//  $logo = $wrapper->field_logo->value();
//  $logo_tmp_file_id = $dto_util->export_file($logo);
//  if (!empty($logo_tmp_file_id)) {
//    $attachement_logo_dto = $dto_util->_mica_studies_export_dto_attachement_construct($logo, $logo_tmp_file_id);
//    $network_dto->setLogo($attachement_logo_dto);
//  }

//Add file attachment to Dto Network in server Side need that ?????
//  foreach ($wrapper->field_documents->value() as $attachement) {
//    $id_file_server_response = $dto_util->export_file($attachement);
//    if (!empty($id_file_server_response)) {
//      $attachement_dto = $dto_util->_mica_studies_export_dto_attachement_construct($attachement, $id_file_server_response, $attachement, $network_dto);
//      $network_dto->addAttachments($attachement_dto);
//    }
//  }

  $supl_info = $wrapper->field_supp_infos->value();
  dpm($supl_info);
  if (!empty($supl_info)) {
    $dto_util->_mica_studies_export_dto_add_translated_Field($network_dto, 'addInfo', $wrapper,
      'field_supp_infos');
  }

  dpm($network_dto);
  return $network_dto;
}