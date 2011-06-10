<?php

class MicaDatasetOpalConnectionClass extends MicaDatasetAbstractConnection {

  public function __construct(MicaDatasetConnector $connector) {
    parent::__construct($connector);
  }

  public function configurationForm(array $form, array &$form_state) {
    $form_items = array();
    $opal_url = _mica_datasets_node_field_values($study_node, 'mica_opal');

    if (!empty($opal_url)) {
      $form_items['opal-url'] = array (
        '#type' => 'item',
        '#title' => t('Opal server'),
        '#markup' => !empty($opal_url) ? '<a href="' . $opal_url[0]['url'] . '">' . $opal_url[0]['url'] . '</a></div>' : '',
      );
    }
    else {
      $form_items['opal-url'] = array (
      '#title' => t('Opal server'),
      '#type' => 'textfield',
      '#description' => t('The Opal server secured url (https is required).'),
      '#required' => TRUE,
      );
    }
    $form_items['datasource'] = array (
    '#title' => t('Datasource'),
    '#type' => 'textfield',
    '#description' => t('The Opal datasource name.'),
    '#required' => TRUE,
    );
    $form_items['table'] = array (
    '#title' => t('Table'),
    '#type' => 'textfield',
    '#description' => t('The Opal table name from which variables and data can be fetched.'),
    '#required' => TRUE,
    );

    return $form_items;
  }


  public function configurationFormValidate(array $form, array &$values, array &$form_state) {
    $form_errors = array();

    if (array_key_exists('opal-url', $values)) {
      $value = trim($values['opal-url']);
      if ($value == '' || strpos($value,'https://') === FALSE) {
        $form_errors['opal-url'] = t('You must provide a valid Opal server url: https://...');
      }
    }
    // todo check for valid chars in names
    $value = trim($values['datasource']);
    if ($value == '') {
      $form_errors['datasource'] = t('You must provide a valid Opal datasource name.');
    }
    $value = trim($values['table']);
    if ($value == '') {
      $form_errors['table'] = t('You must provide a valid Opal table name.');
    }

    return $form_errors;
  }


  public function configurationFormSubmit(array $form, array &$values, array &$form_state){
    $options = array();
    if (array_key_exists('opal-url', $values)) {
      $study_node = node_load($form_state['values'][MICA_STUDY_ID]);
      $study_node->mica_opal[$study_node->language][] = array('url' => $values['opal-url']);
      node_save($study_node);
    }
    $options['datasource'] = trim($values['datasource']);
    $options['table'] = trim($values['table']);

    return $options;
  }


  public function getImporterId() {
    return 'opal_participant_variables';
  }



}
