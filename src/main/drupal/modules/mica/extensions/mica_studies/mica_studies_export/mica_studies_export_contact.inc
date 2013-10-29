<?php
/**
 * @file
 * mica_export_contact.inc
 */

function _mica_studies_export_contact_xml($nid) {
  $wrapper = entity_metadata_wrapper('node', $nid);
  $dom = new DomDocument('1.0', 'utf-8');
  $root = $dom->createElement('contact');
  $root->setAttribute('uuid', $wrapper->uuid->value());
  $root->setAttribute('mica_origin_url', $wrapper->mica_origin_url->value());
  $dom->appendChild($root);
  $name_element = $root->appendChild($dom->createElement('name'));
  $name_element->appendChild($dom->createElement('title'))
    ->appendChild($dom->createTextNode($wrapper->field_contact_name->title->value()));
  $name_element->appendChild($dom->createElement('given'))
    ->appendChild($dom->createTextNode($wrapper->field_contact_name->given->value()));
  $name_element->appendChild($dom->createElement('family'))
    ->appendChild($dom->createTextNode($wrapper->field_contact_name->family->value()));

  $root->appendChild($dom->createElement('data-access-committee-member'))
    ->appendChild($dom->createTextNode($wrapper->field_daco->value()));
  $root->appendChild($dom->createElement('title'))->appendChild($dom->createTextNode($wrapper->title_field->value()));
  $root->appendChild($dom->createElement('email'))
    ->appendChild($dom->createTextNode($wrapper->field_contact_email->value()));
  $root->appendChild($dom->createElement('phone'))
    ->appendChild($dom->createTextNode($wrapper->field_telephone->value()));

  $institution_element = $root->appendChild($dom->createElement('institution'));
  $institution_element->appendChild($dom->createElement('name'))
    ->appendChild($dom->createTextNode($wrapper->field_institution_name->value()));
  $institution_element->appendChild($dom->createElement('department-unit'))
    ->appendChild($dom->createTextNode($wrapper->field_department_unit->value()));
  $institution_element->appendChild($dom->createElement('address'))
    ->appendChild($dom->createTextNode($wrapper->field_address->value()));
  $institution_element->appendChild($dom->createElement('city'))
    ->appendChild($dom->createTextNode($wrapper->field_city->value()));
  $institution_element->appendChild($dom->createElement('state-province'))
    ->appendChild($dom->createTextNode($wrapper->field_state->value()));
  $institution_element->appendChild($dom->createElement('postal-code'))
    ->appendChild($dom->createTextNode($wrapper->field_postal_code->value()));

  $country_element = $institution_element->appendChild($dom->createElement('country'));
  $country_element->setAttribute('code', $wrapper->field_contact_country->value());
  $country_element->appendChild($dom->createTextNode($wrapper->field_contact_country->label()));

  $timestamp_element = $root->appendChild($dom->createElement('time-stamp'));
  $timestamp_element->appendChild($dom->createElement('date-created'))
    ->appendChild($dom->createTextNode($wrapper->created->value()));
  $timestamp_element->appendChild($dom->createElement('date-changed'))
    ->appendChild($dom->createTextNode($wrapper->changed->value()));

  return $dom->saveXML();
}
