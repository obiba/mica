<?php

require_once('mica_query.entity.inc');
require_once('mica_query.pages.inc');
require_once(drupal_get_path('module', 'mica_datasets') . '/mica_datasets.utils.inc');

/**
 * @file
 * Mica Datasets query term pages.
 */

/**
 * Page to display the edit query term form in a modal dialog.
 * @param $js
 * @param $node
 * @param $query
 * @param $term
 */
function mica_datasets_query_term_edit_modal_page($js = NULL, $node, $query, $term, $cross_variable = NULL) {
  if ($js) {
    $impl = $term->termImpl();
    $title = t('Edit !term', array('!term' => $impl->getFieldName()));
    mica_core_modal_form_render($title, 'mica_datasets_query_term_edit_form', $node, $query, $term, $cross_variable);
  }
  else {
    // fallback to plain page
    return mica_datasets_query_term_edit_page($node, $query, $term, $cross_variable);
  }
}

/**
 * Page to display the edit query term form.
 * @param $node
 * @param $query
 * @param $term
 */
function mica_datasets_query_term_edit_page($node, $query, $term, $cross_variable = NULL) {
  $impl = $term->termImpl();
  drupal_set_title(
    t('!title -- Edit !term in !query',
      array(
        '!title' => $node->title,
        '!query' => $query->name,
        '!term' => $impl->getFieldName()
      )
    )
  );
  return drupal_get_form('mica_datasets_query_term_edit_form', $node, $query, $term, $cross_variable);
}

function mica_datasets_query_term_edit_form($form, &$form_state) {

  $dataset_node = $form_state['build_info']['args'][0];
  $query = $form_state['build_info']['args'][1];
  $term = $form_state['build_info']['args'][2];
//  $cross_variable = $form_state['build_info']['args'][3];

  $impl = $term->termImpl();
  $term_form = $impl->form($form, $form_state);
  $form[] = $term_form;

  $form['actions']['save'] = array(
    '#type' => 'submit',
    '#value' => t('Save'),
  );

  $form['actions']['cancel'] = array(
    '#type' => 'link',
    '#title' => t('Cancel'),
    '#href' => _mica_query_url($dataset_node, $query),
  );

  return $form;
}

function mica_datasets_query_term_edit_form_validate($form, &$form_state) {
  $term_entity = $form_state['build_info']['args'][2];
  $impl = $term_entity->termImpl();
  $impl->validate($form, $form_state);
}

function mica_datasets_query_term_edit_form_submit($form, &$form_state) {
  $dataset_node = $form_state['build_info']['args'][0];
  $query = $form_state['build_info']['args'][1];
  $term = $form_state['build_info']['args'][2];
  $cross_variable = $form_state['build_info']['args'][3];

  $impl = $term->termImpl();
  $impl->submit($form, $form_state);

  $errors = form_get_errors();
  if (empty($errors)) {
    switch ($form_state['triggering_element']['#parents'][0]) {
      case 'save':
        if (is_numeric($term->id)) {
          $term->save();
        }
        else {
          // cached term
          MicaDatasetQueryManager::getCache($query)->updateTerm($term);
        }
        $form_state['complete'] = TRUE;
        break;
      case 'cancel':
        $form_state['cancel'] = TRUE;
        break;
    }
    $form_state['redirect'] = _mica_query_url($dataset_node, $query);
    if (!empty($cross_variable)) {
      $form_state['redirect'] .= '/' . $cross_variable;
    }
  }
}

//
// View Query Term
//

function mica_datasets_query_term_page($dataset_node, $query, $term, $cross_variable = NULL) {
  $impl = $term->termImpl();
  drupal_set_title(t('!title -- !term', array('!title' => $dataset_node->title, '!term' => $impl->toString())));
  return $impl->view();
}

//
// Delete Query Term
//

/**
 * Page to display the delete query term form in a modal dialog.
 * @param $js
 * @param $node
 * @param $query
 * @param $term
 */
function mica_datasets_query_term_delete_modal_page($js = NULL, $node, $query, $term, $cross_variable = NULL) {
  if ($js) {
    $impl = $term->termImpl();
    $title = t('Delete !term', array('!term' => $impl->getFieldName()));
    mica_core_modal_form_render($title, 'mica_datasets_query_term_delete_form', $node, $query, $term, $cross_variable);
  }
  else {
    // fallback to plain page
    return mica_datasets_query_term_delete_page($node, $query, $term, $cross_variable);
  }
}

/**
 * Page to display the delete query term form.
 * @param $dataset_node
 * @param $query
 * @param $term
 */
function mica_datasets_query_term_delete_page($dataset_node, $query, $term, $cross_variable = NULL) {
  drupal_set_title(t('Are you sure you want to delete query term <em>!term</em>?', array('!term' => $term->toString())), PASS_THROUGH);
  return drupal_get_form('mica_datasets_query_term_delete_form', $dataset_node, $query, $term, $cross_variable);
}

function mica_datasets_query_term_delete_form($form, &$form_state) {
  $dataset_node = $form_state['build_info']['args'][0];
  $query = $form_state['build_info']['args'][1];
//  $term = $form_state['build_info']['args'][2];
//  $cross_variable = $form_state['build_info']['args'][3];

  $form['message'] = array(
    '#markup' => t('This action cannot be undone.'),
    '#attributes' => array('style'),
  );

  $form['actions'] = array(
    '#type' => 'container',
    '#attributes' => array('class' => array('form-actions')),
  );

  $form['actions']['delete'] = array(
    '#type' => 'submit',
    '#value' => t('Delete'),
  );

  $form['actions']['cancel'] = array(
    '#type' => 'link',
    '#title' => t('Cancel'),
    '#href' => _mica_query_url($dataset_node, $query),
  );

  return $form;
}

function mica_datasets_query_term_delete_form_submit($form, &$form_state) {
  $dataset_node = $form_state['build_info']['args'][0];
  $query = $form_state['build_info']['args'][1];
  $term = $form_state['build_info']['args'][2];
  $cross_variable = $form_state['build_info']['args'][3];

  if (is_numeric($term->id)) {
    // delete term
    $term->delete();
  }
  else {
    MicaDatasetQueryManager::getCache($query)->deleteTerm($term);
  }

  $form_state['complete'] = TRUE;
  $form_state['redirect'] = _mica_query_url($dataset_node, $query);
  if (!empty($cross_variable)) {
    $form_state['redirect'] .= '/' . $cross_variable;
  }
}