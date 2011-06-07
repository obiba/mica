<?php

function _unit_certificate_page() {
  $unit_certificate_form="unit_certificate_form";
  $certificate_exists=is_file('private://csrStr.csrStr');
  if ($certificate_exists) {
    $content=file_get_contents('private://csrStr.csrStr');
  }
 
  $form[$unit_certificate_form]['certificate'] = array(
    '#type' => 'textarea',
    '#title' => t('Certificate'),
    '#value' =>  $certificate_exists ? $content : '',
    '#rows' => 20,
    '#attributes' => array('readonly' => 'readonly'),
  );
  return $form;
}

function _unit_form($form, &$form_state) {
  $unit_form="unit_form";
  $unit_configure="configure";
   
  $form[$unit_form]['description'] = array(
    '#type' => 'item',
    '#title' => t('Mica server can communicate with third-party using a key pair (private key/certificate)'),
  );

  $form[$unit_form][$unit_configure] = array(
    '#type' => 'fieldset',
    '#title' => t('Configure key pair'),
  );

  $form[$unit_form][$unit_configure]['first_and_last_name'] = array(
    '#type' => 'textfield',
    '#title' => t('First and last name'),
    '#required' => TRUE,
  );
  $form[$unit_form][$unit_configure]['organizational_unit'] = array(
    '#type' => 'textfield',
    '#title' => t('Organizational unit'),
    '#required' => TRUE,
  );
  $form[$unit_form][$unit_configure]['city_or_organization_name'] = array(
    '#type' => 'textfield',
    '#title' => t('Name of the organization'),
    '#required' => TRUE,
  );
  $form[$unit_form][$unit_configure]['city_name'] = array(
    '#type' => 'textfield',
    '#title' => t('City or Locality name'),
    '#required' => TRUE,
  );
  $form[$unit_form][$unit_configure]['state_or_province_name'] = array(
    '#type' => 'textfield',
    '#title' => t('State or province'),
    '#required' => TRUE,
  );
  $form[$unit_form][$unit_configure]['two_letter_country_code'] = array(
    '#type' => 'textfield',
    '#title' => t('Two letter Country code'),  
    '#required' => TRUE,
    '#size' => 2,
    '#maxlength' => 2,
  );

  $form[$unit_form][$unit_configure]['submit'] = array(
    '#type' => 'submit',
    '#value' => 'Save',
  );
  return $form;
}

function _unit_form_submit($form, &$form_state) {

  $dn=array('countryName' => $form_state['values']['two_letter_country_code'],
   'stateOrProvinceName' => $form_state['values']['state_or_province_name'],
   'localityName' => $form_state['values']['city_name'],
   'organizationName' => $form_state['values']['city_or_organization_name'],
   'organizationalUnitName' => $form_state['values']['organizational_unit'],
   'commonName' => $form_state['values']['first_and_last_name'],
   'emailAddress' => 'user@domain.com');

  $privkeypass = '1234';
  $numberofdays = 365;

  $privkey = openssl_pkey_new(); //TODO $privkey is NULL why ?

  $csr = openssl_csr_new($dn, $privkey);

  $sscert = openssl_csr_sign($csr, null, $privkey, $numberofdays);
  openssl_x509_export($sscert, $publickey);
  openssl_pkey_export($privkey, $privatekey, $privkeypass);
  openssl_csr_export($csr, $csrStr);


  //debug($privatekey); // Will hold the exported PriKey
  //debug($publickey);  // Will hold the exported PubKey
  //debug($csrStr);     // Will hold the exported Certificate
  
  file_unmanaged_save_data($privatekey, 'private://privatekey.privatekey', FILE_EXISTS_REPLACE);
  file_unmanaged_save_data($publickey, 'private://publickey.publickey', FILE_EXISTS_REPLACE);
  file_unmanaged_save_data($csrStr, 'private://csrStr.csrStr', FILE_EXISTS_REPLACE);
  
  //TODO maybe drupal can do different (maybe directly call a method like _unit_certificate_page())
  return drupal_goto('admin/config/system/mica');
}


function _unit_form_validate($form, &$form_state) {
  $tlcc = $form_state['values']['two_letter_country_code'];
  if (strlen($tlcc)!=2 || !ctype_alpha($tlcc)) {
    form_set_error('two_letter_country_code',t('Bad syntax of two letter Country code'));
  }
}