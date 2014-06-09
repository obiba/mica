<?php
/**
 * @file
 * mica_export_contact.inc
 */

function _mica_studies_export_dto_contact_dto($dto_util, $wrapper) {
  $contact = new obiba\mica\ContactDto();

  $contact->setTitle($wrapper->field_contact_name->title->value());
  $contact->setFirstName($wrapper->field_contact_name->given->value());
  $contact->setLastName($wrapper->field_contact_name->family->value());
  $contact->setEmail($wrapper->field_contact_email->value());
  $contact->setPhone($wrapper->field_telephone->value());
  $contact->setDataAccessCommitteeMember($wrapper->field_daco->value());

  $institution = new obiba\mica\ContactDto\InstitutionDto;

  $institution_name = $wrapper->field_institution_name->value();
  !empty($institution_name) ?
    $dto_util->_mica_studies_export_dto_add_translated_Field($institution, 'addName', $wrapper, 'field_institution_name')
    : NULL;

  $departement_name = $wrapper->field_department_unit->value();
  !empty($departement_name) ?
    $dto_util->_mica_studies_export_dto_add_translated_Field($institution, 'addDepartment', $wrapper, 'field_department_unit')
    : NULL;

  $address = new obiba\mica\AddressDto();
  $address_street = $wrapper->field_address->value();
  !empty($address_street) ?
    $dto_util->_mica_studies_export_dto_add_translated_Field($address, 'addStreet', $wrapper, 'field_address')
    : NULL;

  $address_city = $wrapper->field_city->value();

  !empty($address_city) ?
    $dto_util->_mica_studies_export_dto_add_translated_Field($address, 'addCity', $wrapper, 'field_city')
    : NULL;

  $address->setZip($wrapper->field_postal_code->value());
  $address->setState($wrapper->field_state->value());

  $contry = $wrapper->field_contact_country->value();
  if (!empty($contry)) {
    $coutryIso = new \obiba\mica\CountryDto();
    $coutryIso->setIso($wrapper->field_contact_country->value());

    $country_name = $wrapper->field_contact_country->label();

    !empty($country_name) ?
      $dto_util->_mica_studies_export_dto_add_translated_Field($coutryIso, 'addName', $wrapper, 'field_contact_country', NULL, 'label')
      : NULL;

    $address->setCountry($coutryIso);
  }
  $institution->setAddress($address);
  $contact->setInstitution($institution);

  return $contact;
}
