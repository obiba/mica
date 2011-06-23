<?php

require_once('includes/datashield.inc');

function mica_datashield_form($form, &$form_state) {
  drupal_set_title("DataSHIELD!");
  $dataset_node = $form_state['build_info']['args'][0];

  $model = _mica_datashield_model_load($dataset_node);

  $variable_options = array();
  foreach(mica_dataset_dataset_participant_variables($dataset_node->nid) as $variable) {
    if($model->hasVariable($variable) == FALSE) {
      $variable_options[$variable->nid] = $variable->title;
    }
  }

  $form = array();
  
  $form['selection'] = array(
    '#type' =>'fieldset',
    '#title' => t('Variables'),
    '#collapsible' => FALSE
  );

  $form['selection']['add-term']['variable']= array(
    '#type' => 'select', 
    '#title' => t('Variables'), 
    '#options' => $variable_options,
  );
  $form['selection']['add-term']['add-variable'] = array(
    '#type' => 'submit',
    '#value' => t('Add Variable'),
  );

  $form['selection']['list']['variables'] = array(
    '#type' => 'tableselect',
    '#header' => array('Variable'),
    '#options' => $model->options(),
    '#empty' => t('No variables selected')
  );

  $form['selection']['list']['remove-variable'] = array(
    '#type' => 'submit',
    '#value' => t('Remove Variable(s)'),
  );

  $form['model'] = array(
    '#type' =>'fieldset',
    '#title' => t('Model'),
    '#collapsible' => FALSE
  );

  $form['model']['model-to-fit'] = array(
    '#type' => 'textfield',
    '#disabled' => (count($model->variables()) < 1),
    '#title' => t('Model'),
    '#description' => t('The R formula to fit. Should reference the selected variables above (e.g.: ') . (count($model->variables()) > 1 ? $model->model() : 'BMI ~ HEIGHT + WEIGHT') .')',
    '#default_value' => !empty($form_state['values']['model-to-fit']) ? $form_state['values']['model-to-fit'] : '',
    '#size' => 70,
  );

  $form['model']['model-family'] = array(
    '#type' => 'select',
    '#title' => t('Family'),
    '#options' => array('gaussian' => t('Gaussian'), 'binomial' => t('Binomial'), 'poisson' => t('Poisson')),
    '#default_value' => !empty($form_state['values']['model-family']) ? $form_state['values']['model-family'] : 'gaussian',
  );

  $form['fit'] = array(
    '#type' => 'submit',
    '#value' => t('DataSHIELD!'),
  );

  if(!empty($form_state['values']['output'])) {
    $form['result'] = array(
      '#type' =>'fieldset',
      '#title' => t('DataSHIELD Result'),
      '#collapsible' => TRUE
    );
    $form['result']['output'] = array(
      '#markup' => '<pre>' . $form_state['values']['output'] . '</pre>',
    );
  }

  return $form;
}

function mica_datashield_form_submit($form, &$form_state) {
  $dataset_node = $form_state['build_info']['args'][0];

  switch ($form_state['triggering_element']['#parents'][0]) {
    case 'add-variable':
      $vid = $form_state['values']['variable'];
      
      $model = _mica_datashield_model_load($dataset_node);

      $model->addVariable(node_load($vid));

      _mica_datashield_model_store($dataset_node, $model);
      $form_state['rebuild'] = TRUE;
      break;

    case 'remove-variable':
      $vids = $form_state['values']['variables'];
      $model = _mica_datashield_model_load($dataset_node);
      $model->removeVariables($vids);

      _mica_datashield_model_store($dataset_node, $model);
      
      $form_state['rebuild'] = TRUE;
      break;
    case 'fit':
      $model = _mica_datashield_model_load($dataset_node);
      
      $model->launch($form_state['values']['model-to-fit'], array('family'=>$form_state['values']['model-family']));

      $form_state['values']['output'] = $model->stdout();

      _mica_datashield_model_store($dataset_node, $model);
      $form_state['rebuild'] = TRUE;
      break;
  }
}

function _mica_datashield_model_load($dataset_node) {
  if(isset($_SESSION['datashield'][$dataset_node->nid]) == false) {
    return new DataShieldModel($dataset_node);
  }
  return unserialize($_SESSION['datashield'][$dataset_node->nid]);
}

function _mica_datashield_model_store($dataset_node, $model) {
  $_SESSION['datashield'][$dataset_node->nid] = serialize($model);
}