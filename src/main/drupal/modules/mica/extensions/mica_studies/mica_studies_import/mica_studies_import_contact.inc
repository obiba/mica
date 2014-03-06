<?php
/**
 * @file
 * mica_studies_import_contact.inc
 */

function _mica_studies_import_set_contact_properties($dom, $wrapper) {

  // xpath with contact/name/title
  $xpath = new DOMXPath($dom);
  $wrapper->field_contact_name->title->set(mica_studies_import_get_node_value($xpath, '/contact/name/title'));

  $wrapper->field_contact_name->given->set(mica_studies_import_get_node_value($xpath, '/contact/name/given'));

  $wrapper->field_contact_name->family->set(mica_studies_import_get_node_value($xpath, '/contact/name/family'));

  $wrapper->field_daco->set(mica_studies_import_get_node_value($xpath, '/contact/data-access-committee-member'));

  $wrapper->field_contact_email->set(mica_studies_import_get_node_value($xpath, '/contact/email'));

  $wrapper->field_telephone->set(mica_studies_import_get_node_value($xpath, '/contact/phone'));

  $wrapper->field_institution_name->set(mica_studies_import_get_node_value($xpath, '/contact/institution/name'));

  $wrapper->field_department_unit->set(mica_studies_import_get_node_value($xpath, '/contact/institution/department-unit'));

  $wrapper->field_address->set(mica_studies_import_get_node_value($xpath, '/contact/institution/address'));

  $wrapper->field_city->set(mica_studies_import_get_node_value($xpath, '/contact/institution/city'));

  $wrapper->field_postal_code->set(mica_studies_import_get_node_value($xpath, '/contact/institution/state-province'));

  $wrapper->field_state->set(mica_studies_import_get_node_value($xpath, '/contact/institution/postal-code'));

  $wrapper->field_contact_country->set($xpath->query('/contact/institution/country')->item(0)->getAttribute("code"));
}
