<?php
/**
 * @file
 * mica_studies_export_contact.inc
 */

function mica_studies_export_contact_fields_map($nid) {
  $wrapper = entity_metadata_wrapper('node', $nid);

//Mapping contact array Drupal_fields => Attribute
  $fields_convertion =
    array(
      'field_address' => 'address',
      'field_city' => 'city',
      'field_contact_country' => 'country',
      'field_contact_email' => 'email',
      'field_contact_name' => 'contact-name',
      'field_daco' => 'data-access-committee-member',
      'field_department_unit' => 'department-unit',
      'field_institution_name' => 'institution-name',
      'field_postal_code' => 'postal-code',
      'field_state' => 'state-province',
      'field_telephone' => 'telephone',
      'title_field' => 'title',
      'nid' => 'node-id',
      'type' => 'content-type',
      'title' => 'title',
      'language' => 'language',
      'created' => 'date-created',
      'changed' => 'date-changed',
      'uuid' => 'uuid'
    );
//Rearrange hierarchical  data and retrieve  values
  $fieldes = array();
  foreach ($fields_convertion as $k => $v) {
    $fieldes['contact'][$v] = $wrapper->{$k}->value();
    if ($k == 'field_institution_name') {
      $fieldes['contact']['institution']['institution-name'] = $wrapper->{$k}->value();
      unset($fieldes['contact']['institution-name']);
    }
    if ($k == 'field_department_unit') {
      $fieldes['contact']['Institution']['department-unit'] = $wrapper->{$k}->value();
      unset($fieldes['contact']['department-unit']);
    }
    if ($k == 'field_contact_country') {
      $fieldes['contact']['institution']['country'] = $wrapper->{$k}->value();
      unset($fieldes['contact']['country']);
    }
    if ($k == 'field_city') {
      $fieldes['contact']['institution']['city'] = $wrapper->{$k}->value();
      unset($fieldes['contact']['city']);
    }
    if ($k == 'field_state') {
      $fieldes['contact']['institution']['state-province'] = $wrapper->{$k}->value();
      unset($fieldes['contact']['state-province']);
    }
    if ($k == 'field_address') {
      $fieldes['contact']['institution']['address'] = $wrapper->{$k}->value();
      unset($fieldes['contact']['address']);
    }
    if ($k == 'field_postal_code') {
      $fieldes['contact']['institution']['postal-code'] = $wrapper->{$k}->value();
      unset($fieldes['contact']['postal-code']);
    }

    if ($k = 'created') {
      $fieldes['contact']['timestamp']['date-created'] = $wrapper->{$k}->value();
      unset($fieldes['contact']['date-created']);
    }
    if ($k = 'created') {
      $fieldes['contact']['timestamp']['date-changed'] = $wrapper->{$k}->value();
      unset($fieldes['contact']['date-changed']);
    }

    unset($fieldes['contact']['contact-name']['safe']);

  }

  return $fieldes;

}