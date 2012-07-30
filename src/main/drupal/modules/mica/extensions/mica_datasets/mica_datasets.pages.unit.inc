<?php
/**
 * @file
 * Mica Datasets unit pages
 */

function mica_datasets_unit_certificate_page() {
  $unit_certificate_form = "unit_certificate_form";

  if (_mica_datasets_is_private_path_defined()) {
    $public_key_file_exists = is_file(PUBLIC_KEY_FILE);
  }
  else {
    $public_key_file_exists = FALSE;
    _mica_datasets_set_missing_private_warning_message();
  }

  $content = $public_key_file_exists ? file_get_contents(PUBLIC_KEY_FILE) : '';

  $form[$unit_certificate_form]['certificate'] = array(
    '#type' => 'textarea',
    '#title' => t('Certificate'),
    '#value' => $content,
    '#rows' => 20,
    '#attributes' => array('readonly' => 'readonly'),
  );
  return $form;
}

function mica_datasets_unit_form($form, &$form_state) {

  if (!_mica_datasets_is_private_path_defined()) {
    _mica_datasets_set_missing_private_warning_message();
  }

  $unit_form = 'mica_datasets_unit_form';
  $unit_configure = 'configure';

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
    '#disabled' => !_mica_datasets_is_private_path_defined(),
  );
  return $form;
}

function mica_datasets_unit_form_submit($form, &$form_state) {

  $dn = array(
    'countryName' => $form_state['values']['two_letter_country_code'],
    'stateOrProvinceName' => $form_state['values']['state_or_province_name'],
    'localityName' => $form_state['values']['city_name'],
    'organizationName' => $form_state['values']['city_or_organization_name'],
    'organizationalUnitName' => $form_state['values']['organizational_unit'],
    'commonName' => $form_state['values']['first_and_last_name']
  );

  $configargs = array(
    'private_key_bits' => 2048,
    'private_key_type' => OPENSSL_KEYTYPE_RSA
  );

  // get existing key if exists
  if (is_file(PRIVATE_KEY_FILE)) {
    openssl_pkey_get_private(PRIVATE_KEY_FILE);
  }
  else {
    $privkey = openssl_pkey_new($configargs);
  }

  $csr = openssl_csr_new($dn, $privkey);

  $sscert = openssl_csr_sign($csr, NULL, $privkey, 9999);
  openssl_x509_export($sscert, $publickey);
  openssl_pkey_export($privkey, $privatekey);

  file_unmanaged_save_data($privatekey, PRIVATE_KEY_FILE, FILE_EXISTS_REPLACE);
  file_unmanaged_save_data($publickey, PUBLIC_KEY_FILE, FILE_EXISTS_REPLACE);

  openssl_pkey_free($privkey);

  //TODO maybe drupal can do different (maybe directly call a method like mica_datasets_unit_certificate_page())
  drupal_goto('admin/config/system/mica');
}


function mica_datasets_unit_form_validate($form, &$form_state) {
  $tlcc = $form_state['values']['two_letter_country_code'];
  if (strlen($tlcc) != 2 || !ctype_alpha($tlcc)) {
    form_set_error('two_letter_country_code', t('Bad syntax of two letter Country code'));
  }
}

function _mica_datasets_is_private_path_defined() {
  return in_array('private', stream_get_wrappers());
}

function _mica_datasets_set_missing_private_warning_message() {
  drupal_set_message(t('Please define \'<b>Private file system path</b>\' in <a href="?q=admin/config/media/file-system" >Configuration > File system</a>'),
    'warning');
}