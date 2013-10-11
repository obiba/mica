<?php
/**
 * @file
 * mica_studies_import_contact.inc
 */

function _mica_studies_mica_import_set_contact_properties($dom, $wrapper) {

  // xpath with contact/name/title
  $xpath = new DOMXPath($dom);
  $wrapper->field_contact_name->title->set();
  $wrapper->field_contact_name->title->set($xpath->query('/contact/name/title')->item(0)->nodeValue);

  $wrapper->field_contact_name->given->set();
  $wrapper->field_contact_name->given->set($xpath->query('/contact/name/given')->item(0)->nodeValue);

  $wrapper->field_contact_name->family->set();
  $wrapper->field_contact_name->family->set($xpath->query('/contact/name/family')->item(0)->nodeValue);

  $wrapper->field_daco->set();
  $wrapper->field_daco->set($xpath->query('/contact/data-access-committee-member')->item(0)->nodeValue);

  //Required field
  if (!empty($xpath->query('/contact/title')->item(0)->nodeValue)) {
    $wrapper->title->set($xpath->query('/contact/title')->item(0)->nodeValue);
  }
  else {
    try {
      $wrapper->title->set();
    } catch (Exception $e) {
      throw new Exception(t('Contact : Field title required'));
    }
  }

  $wrapper->field_contact_email->set();
  $wrapper->field_contact_email->set($xpath->query('/contact/email')->item(0)->nodeValue);

  $wrapper->field_telephone->set();
  $wrapper->field_telephone->set($xpath->query('/contact/phone')->item(0)->nodeValue);

  $wrapper->field_institution_name->set();
  $wrapper->field_institution_name->set($xpath->query('/contact/institution/name')->item(0)->nodeValue);

  $wrapper->field_department_unit->set();
  $wrapper->field_department_unit->set($xpath->query('/contact/institution/department-unit')->item(0)->nodeValue);

  $wrapper->field_address->set();
  $wrapper->field_address->set($xpath->query('/contact/institution/address')->item(0)->nodeValue);

  $wrapper->field_city->set();
  $wrapper->field_city->set($xpath->query('/contact/institution/city')->item(0)->nodeValue);

  $wrapper->field_postal_code->set();
  $wrapper->field_postal_code->set($xpath->query('/contact/institution/state-province')->item(0)->nodeValue);

  $wrapper->field_state->set();
  $wrapper->field_state->set($xpath->query('/contact/institution/postal-code')->item(0)->nodeValue);

  $wrapper->field_contact_country->set();
  $wrapper->field_contact_country->set($xpath->query('/contact/institution/country')->item(0)->getAttribute("code"));
}
