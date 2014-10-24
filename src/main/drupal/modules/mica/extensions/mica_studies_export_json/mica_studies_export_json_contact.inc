<?php
/**
 * @file
 * mica_export_contact.inc
 */

function _mica_studies_export_json_contact_dto($dto_util, $wrapper) {
  $contact = new obiba\mica\ContactDto();

  $contact->setTitle($wrapper->field_contact_name->title->value());
  $contact->setFirstName($wrapper->field_contact_name->given->value());
  $last_name = $wrapper->field_contact_name->family->value();
  $contact->setLastName(!empty($last_name) ? $last_name : $wrapper->field_contact_name->given->value());
  $contact->setEmail($wrapper->field_contact_email->value());
  $contact->setPhone($wrapper->field_telephone->value());
  $contact->setDataAccessCommitteeMember($wrapper->field_daco->value());

  $institution = new obiba\mica\ContactDto\InstitutionDto;

  $institution_name = $wrapper->field_institution_name->value();
  if (!empty($institution_name)) {
    $dto_util->_mica_studies_export_json_add_translated_Field($institution, 'addName', $wrapper, 'field_institution_name');
  }

  $departement_name = $wrapper->field_department_unit->value();
  if (!empty($departement_name)) {
    $dto_util->_mica_studies_export_json_add_translated_Field($institution, 'addDepartment', $wrapper, 'field_department_unit');
  }

  $address = new obiba\mica\AddressDto();
  $address_street = $wrapper->field_address->value();
  if (!empty($address_street)) {
    $dto_util->_mica_studies_export_json_add_translated_Field($address, 'addStreet', $wrapper, 'field_address');
  }

  $address_city = $wrapper->field_city->value();

  if (!empty($address_city)) {
    $dto_util->_mica_studies_export_json_add_translated_Field($address, 'addCity', $wrapper, 'field_city');
  }

  $address->setZip($wrapper->field_postal_code->value());
  $address->setState($wrapper->field_state->value());

  $contry = $wrapper->field_contact_country->value();
  if (!empty($contry)) {
    $coutryIso = new \obiba\mica\CountryDto();
    $coutryIso->setIso($wrapper->field_contact_country->value());

    $country_name = $wrapper->field_contact_country->label();

    if (!empty($country_name)) {
      $dto_util->_mica_studies_export_json_add_translated_Field($coutryIso, 'addName', $wrapper, 'field_contact_country', NULL, 'label');
    }

    $address->setCountry($coutryIso);
  }
  $institution->setAddress($address);
  $contact->setInstitution($institution);

  return $contact;
}
