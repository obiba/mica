<?php
/**
 * @file
 * mica_network_export_dto_dataset.inc
 */
$path_module_protobuf = drupal_get_path('module', 'obiba_protobuf');
include_once($path_module_protobuf . '/protobuf/Protobuf.php');
use \DrSlump\Protobuf;

function _mica_studies_export_json_network_dto($node, &$context) {

  $dataset_gen_dto = NULL;
  $dataset_type_parse = NULL;
  $resource_serv = NULL;
  $node_type = NULL;
  $attachments_files = array();
  $wrapper_study = entity_metadata_wrapper('node', $node);
  $dto_util = new QuerySendDto();

  foreach ($wrapper_study->field_networks->getIterator() as $network_wrapper) {
    $network_dto = new obiba\mica\NetworkDto();
    $network_dto->addStudyIds($wrapper_study->uuid->value());
    $network_title = $network_wrapper->title_field->value();
    if (!empty($network_title)) {
      $dto_util->_mica_studies_export_json_add_translated_Field($network_dto, 'addName',
        $network_wrapper, 'title_field');
    }

    $network_acronym = $network_wrapper->field_acroym->value();
    if (!empty($network_acronym)) {
      $dto_util->_mica_studies_export_json_add_translated_Field($network_dto, 'addAcronym', $network_wrapper, 'field_acroym');
    }

    $dto_util->_mica_studies_export_json_add_translated_Field($network_dto, 'addDescription', $network_wrapper, 'body', 'value');

    $url_website = $network_wrapper->field_website->value();
    if (!empty($url_website)) {
      $network_dto->setWebsite($url_website['url']);
    };

    $authorization_maelstrom_dto = new \obiba\mica\AuthorizationDto();
    $authorization_maelstrom_dto->setAuthorized($network_wrapper->field_authorization_maelstrom->value());
    $authorization_maelstrom_dto->setAuthorizer($network_wrapper->field_authorising_person_name_m->value());
    $authorization_maelstrom_dto->setDate($network_wrapper->field_authorising_date_m->value());
    $network_dto->setMaelstromAuthorization($authorization_maelstrom_dto);
    //@TODO Bug when exporting :Text '1350964800' could not be parsed at index 0 <Jira : MICASERVER-46>
    //$authorization_maelstrom_dto->setDate($wrapper->field_authorising_date_m->value());

    foreach ($network_wrapper->field_investigators->getIterator() as $investigator_wrapper) {
      if (!empty($investigator_wrapper)) {
        $investigator = _mica_studies_export_json_contact_dto($dto_util, $investigator_wrapper);
        $network_dto->addInvestigators($investigator);
      }
    }

    foreach ($network_wrapper->field_contacts_ref->getIterator() as $contact_wrapper) {
      if (!empty($contact_wrapper)) {
        $contact = _mica_studies_export_json_contact_dto($dto_util, $contact_wrapper);
        $network_dto->addContacts($contact);
      }
    }

    $supl_info = $network_wrapper->field_supp_infos->value();
    if (!empty($supl_info)) {
      $dto_util->_mica_studies_export_json_add_translated_Field($network_dto, 'addInfo', $network_wrapper,
        'field_supp_infos');
    }

    //attached Documents
    $logo = $network_wrapper->field_logo->value();
    if (!empty($logo['filename'])) {
      $attachment_logo_dto = $dto_util->_mica_studies_export_json_attachement_construct($logo, 'logo');
      $attachments_files[] = array(
        'uuid' => $logo['uuid'],
        'filename' => $logo['filename'],
        'uri' => $logo['uri']
      );
      $network_dto->addAttachments($attachment_logo_dto);
    }

    $raw_response = $network_wrapper->uuid->value();
    $network_dto->setPublished(FALSE);
    $network_dto->setId($raw_response);

    //Create  dataset
    $codec = new \DrSlump\Protobuf\Codec\Json();
    $network_dto_json = $network_dto->serialize($codec);
    $network_to_file_save[] = array(
      'uuid' => $raw_response,
      'title_network' => $network_wrapper->title->value(),
      'network_json' => $network_dto_json
    );
  }

  $context['results']['networks'] = $network_to_file_save;
  if (!empty($attachments_files)) {
    $context['results']['networks']['attachments'] = $attachments_files;
  }

  return $network_dto;
}