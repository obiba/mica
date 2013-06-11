<?php

require_once('mica_query.entity.inc');
require_once(drupal_get_path('module', 'mica_datasets') . '/mica_datasets.utils.inc');

/**
 * @file
 * Mica Datasets pages.
 */

//
// Queries
//

function _mica_query_url($dataset_node, $query, $action = NULL) {
  $url = 'node/' . $dataset_node->nid . '/queries/' . $query->id;
  if (!empty($action)) {
    $url .= '/' . $action;
  }
  return $url;
}

function _mica_query_link($dataset_node, $query, $action = NULL, $title = NULL) {
  $url = _mica_query_url($dataset_node, $query, $action);
  if (!isset($title)) {
    $title = $query->name;
  }
  return l($title, $url);
}

function _mica_query_term_url($dataset_node, $query, $term, $action, $cross_variable = NULL) {
  $url = 'node/' . $dataset_node->nid . '/queries/' . $query->id . '/term/' . $term->id;
  if (!empty($action)) {
    $url .= '/' . $action;
  }
  if (!empty($cross_variable)) {
    $url .= '/' . $cross_variable->nid;
  }
  return $url;
}

/**
 * Display queries.
 */
function mica_query_queries_page($dataset_node) {
  drupal_set_title(t('!title -- Queries', array('!title' => $dataset_node->title)));

  mica_core_modal_prepare(array(
    array(
      'name' => 'delete-style',
      'width' => 400,
      'height' => 150,
    ),
  ));

  global $user;

  $header = array(
    'name' => t('Name'),
    'description' => t('Description'),
    'actions' => t('Operations'),
  );

  $options = array();

  $queries = MicaDatasetQueryManager::getAllQueries($dataset_node->nid);
  if ($queries) {
    foreach ($queries as $query) {
      if ($query->published || $query->user_id == $user->uid) {
        $name = _mica_query_link($dataset_node, $query);

        if ($user->uid != 0 && MicaDatasetQueryManager::isCached($query)) {
          $name = $name . ' ' . t('(not saved)');
        }
        $option = array(
          'name' => $name,
          'description' => $query->description,
          'actions' => array('data' => array())
        );

        $option['actions']['data'][] = array(
          '#type' => 'link',
          '#title' => t('Run'),
          '#href' => _mica_query_url($dataset_node, $query),
          '#attributes' => array('style' => array('margin-right: 10px;')),
        );

        // author of the query or user with update dataset permission can edit/delete a query
        if (_mica_datasets_query_access($dataset_node, $query, 'update')) {
          $option['actions']['data'][] = array(
            '#type' => 'link',
            '#title' => t('Edit'),
            '#href' => _mica_query_url($dataset_node, $query, 'edit'),
            '#attributes' => array('style' => array('margin-right: 10px;')),
          );

          $option['actions']['data'][] = array(
            '#markup' => ctools_modal_text_button(
              t('Delete'),
              'mica/nojs/' . _mica_query_url($dataset_node, $query, 'delete'),
              t('Delete query'),
              'ctools-modal-delete-style'
            ),
          );
        }

        $options[] = $option;
      }
    }
  }

  return theme('table', array('header' => $header, 'rows' => $options, 'empty' => t('No query found')));
}

//
// Add/Edit Query form
//

function mica_query_edit_page($dataset_node, $query) {
  drupal_set_title(t('!title -- !action Query', array(
      '!title' => $dataset_node->title,
      '!action' => $query ? t('Edit') : t('Add'),
    )
  ));
  return drupal_get_form('mica_query_edit_form', $dataset_node, $query);
}

function mica_query_edit_form($form, &$form_state) {
  global $user;
  $dataset_node = $form_state['build_info']['args'][0];
  $query = $form_state['build_info']['args'][1];

  $form = array(
    '#attached' => array('css' => array(drupal_get_path('module', 'mica_connector') . '/css/mica_connector.css')),
  );

  $form['general'] = array(
    '#type' => 'fieldset',
    '#title' => t('Name'),
    '#collapsible' => FALSE,
    '#collapsed' => FALSE,
  );

  $form['general']['name'] = array(
    '#type' => 'textfield',
    '#title' => t('Name'),
    '#default_value' => $query ? $query->name : '',
    '#size' => 60,
    '#maxlength' => 128,
    '#required' => TRUE,
  );

  $form['general']['description'] = array(
    '#type' => 'textarea',
    '#title' => t('Description'),
    '#default_value' => $query ? $query->description : '',
    '#rows' => 3,
    '#required' => FALSE,
  );

  if ($user->uid != 0 && user_access('publish dataset query')) {
    $form['general']['publish'] = array(
      '#type' => 'checkbox',
      '#title' => t('Published'),
      '#default_value' => $query ? $query->published : 0,
    );
  }

  $data = array();
  if (isset($form_state['values'])) {
    if (isset($form_state['values']['list'])) {
      foreach ($form_state['values']['list'] as $datum) {
        $qt = mica_query_term_load($datum['id']);
        $data[] = array(
          'id' => $datum['id'],
          'title' => ($qt ? $qt->toString() : node_load($datum['vid'])->title),
          'vid' => $datum['vid'],
          'weight' => $datum['weight'],
          'depth' => 0,
        );
      }
    }
    if (isset($form_state['values']['added-term'])) {
      $added_term = $form_state['values']['added-term'];
      $data[] = array(
        'id' => 0,
        'title' => $added_term['title'],
        'vid' => $added_term['vid'],
        'weight' => 0,
        'depth' => 0,
      );
    }
  }
  elseif ($query) {
    // add saved query terms ordered by weight
    $terms = mica_query_term_query($query);
    $terms = $terms ? $terms : array();
    foreach ($terms as $query_term) {
      $data[] = array(
        'id' => $query_term->id,
        'title' => $query_term->toString(),
        'vid' => $query_term->variable_id,
        'weight' => $query_term->weight,
        'depth' => $query_term->depth,
      );
    }
  }

  _mica_query_edit_form_remove_term($form_state, $data);

  // Add a query term by selecting a variable
  $variable_options = array();
  foreach (mica_dataset_dataset_variables($dataset_node->nid) as $variable) {
    if (node_access('view', $variable)) {
      $variable_options[$variable->nid] = $variable->title;
    }
  }
  // remove variables that are already term of this query
  foreach ($data as $datum) {
    unset($variable_options[$datum['vid']]);
  }

  if (!empty($variable_options)) {
    asort($variable_options);
    $form['add-term'] = array(
      '#type' => 'item',
      '#description' => t('Select the variables you want to query the dataset on.'),
    );
    $form['add-term']['variables'] = array(
      '#type' => 'select',
      '#title' => t('Variables'),
      '#options' => $variable_options,
    );
    $form['add-term']['add-variable'] = array(
      '#type' => 'submit',
      '#value' => t('Add Variable'),
    );
  }

  $form['list']['#tree'] = TRUE;
  $form['list']['#theme'] = 'mica_query_edit_form';
  foreach ($data as $key => $datum) {
    $form['list'][$key]['title'] = array(
      '#markup' => $datum['title'],
    );
    if ($datum['id'] == 0) {
      $form['list'][$key]['expression'] = array(
        '#type' => 'hidden',
        '#value' => $datum['title'],
      );
    }
    $form['list'][$key]['weight'] = array(
      '#type' => 'weight',
      '#delta' => count($data),
      '#default_value' => $datum['weight'],
    );
    $form['list'][$key]['id'] = array(
      '#type' => 'hidden',
      '#value' => $datum['id'],
    );
    $form['list'][$key]['vid'] = array(
      '#type' => 'hidden',
      '#value' => $datum['vid'],
    );
    $form['remove-term'][$key] = array(
      '#type' => 'submit',
      '#value' => t('Remove') . ' ' . $datum['title'],
      '#vid' => $datum['vid'],
    );
  }

  $categorical_variables = mica_datasets_find_categorical_variables($dataset_node->nid);
  $cross_options = array();
  foreach ($categorical_variables as $variable) {
    if (node_access('view', $variable)) {
      $cross_options[$variable->nid] = $variable->title;
    }
  }
  // remove variables that are already term of this query
  foreach ($data as $datum) {
    unset($cross_options[$datum['vid']]);
  }

  if (!empty($cross_options)) {
    $form['cross'] = array(
      '#type' => 'fieldset',
      '#title' => t('Cross variable'),
      '#collapsible' => FALSE,
      '#collapsed' => FALSE,
    );
    $form['cross']['cross-variable'] = array(
      '#type' => 'select',
      '#title' => t('Variable to cross with'),
      '#options' => $cross_options,
      '#default_value' => $query ? $query->cross_variable_id : -1,
      '#empty_options' => -1,
      '#empty_value' => ' - ' . t('None') . ' - ',
    );
  }

  $form['actions'] = array(
    '#type' => 'container',
    '#attributes' => array('class' => array('form-actions')),
  );

  // Do not offer to save for anonymous, expected for already saved queries
  if ($user->uid != 0 || (isset($query) && !MicaDatasetQueryManager::isCached($query))) {
    $form['actions']['save'] = array(
      '#type' => 'submit',
      '#value' => t('Save and Run'),
    );
  }

  // Do not edit in the cache a persisted query
  if (!isset($query) || MicaDatasetQueryManager::isCached($query)) {
    $form['actions']['run'] = array(
      '#type' => 'submit',
      '#value' => t('Run'),
    );
  }

  return $form;
}

function theme_mica_query_edit_form($variables) {
  $form = $variables['form'];
  drupal_add_tabledrag('draggabledemo-sort', 'order', 'sibling', 'sort');
  $header = array(t('Query Term'), t('Weight'), t('Operations'));

  $rows = array();
  foreach (element_children($form['list']) as $key) {

    // Add class to group weight fields for drag and drop.
    $form['list'][$key]['weight']['#attributes'] = array(
      'class' => array('sort'),
    );

    $row = array();

    // title
    $row[] = drupal_render($form['list'][$key]['title']);

    // weight and hidden fields
    $row_rendered = drupal_render($form['list'][$key]['weight']);
    if (array_key_exists('expression', $form['list'][$key])) {
      $row_rendered .= drupal_render($form['list'][$key]['expression']);
    }
    $row_rendered .= drupal_render($form['list'][$key]['id']) . drupal_render($form['list'][$key]['vid']);
    $row[] = $row_rendered;

    // operation
    $row[] = drupal_render($form['remove-term'][$key]);

    $rows[] = array('data' => $row, 'class' => array('draggable')); //note the difference between $row and $rows
  }

  $output = drupal_render_children($form, array('general'));
  if (array_key_exists('add-term', $form)) {
    $output .= drupal_render_children($form, array('add-term'));
  }
  $output .= theme('table',
    array(
      'header' => $header,
      'rows' => $rows,
      'empty' => t('No query term found'),
      'attributes' => array('id' => 'draggabledemo-sort')
    )
  );

  $output .= drupal_render_children($form, array('cross'));

  $output .= drupal_render_children($form, array('actions'));

  // add form hidden items, otherwise submit and validate will be ignored
  foreach (element_children($form) as $key) {
    if (strpos($key, 'form_') === 0) {
      $output .= drupal_render_children($form, array($key));
    }
  }

  return $output;
}

function _mica_query_edit_form_remove_term(&$form_state, &$data) {
  if (isset($form_state['values']) && isset($form_state['values']['removed-term'])) {
    $removed_term_vid = $form_state['values']['removed-term']['vid'];
    foreach ($data as $index => $datum) {
      if ($datum['vid'] == $removed_term_vid) {
        unset($data[$index]);
        break;
      }
    }
  }
}

function mica_query_edit_form_validate($form, &$form_state) {
  if ($form_state['triggering_element']['#parents'][0] != 'add-variable') {
    if (isset($form_state['values']['list']) == FALSE) {
      form_set_error('variables', t('At least one variable selection is required.'));
    }
    // check new query name is unique in the dataset
    if (!isset($form_state['build_info']['args'][1])) {
      $dataset_node = $form_state['build_info']['args'][0];
      foreach (MicaDatasetQueryManager::getAllQueries($dataset_node->nid) as $query) {
        if ($query->name == $form_state['values']['name']) {
          form_set_error('name', t('A query with this name already exists.'));
          break;
        }
      }
    }
  }
}

function mica_query_edit_form_submit($form, &$form_state) {
  $dataset_node = $form_state['build_info']['args'][0];
  $query = $form_state['build_info']['args'][1];

  if (isset($form_state['triggering_element']['#array_parents'])
    && $form_state['triggering_element']['#array_parents'][0] === 'remove-term'
  ) {
    $form_state['values']['removed-term']['vid'] = $form_state['triggering_element']['#vid'];
    drupal_set_message(t('Query term temporarily removed. Changes made will not be saved until the form is submitted.'), 'warning');
    $form_state['rebuild'] = TRUE;
  }
  else {

    switch ($form_state['triggering_element']['#parents'][0]) {

      case 'add-variable':
        $vid = $form_state['values']['variables'];
        $form_state['values']['added-term'] = array(
          'vid' => $vid,
          'title' => $form['add-term']['variables']['#options'][$vid],
        );
        drupal_set_message(t('Query term temporarily added. Changes made will not be saved until the form is submitted.'), 'warning');
        $form_state['rebuild'] = TRUE;
        break;

      case 'delete':
        $form_state['redirect'] = _mica_query_url($dataset_node, $query, 'delete');
        break;

      case 'save':
        // persist query and terms in the database
        // remove from cache
        if (!isset($query)) {
          // new query
          $values = _mica_query_extract_new_query_values($form_state);
          $query = new MicaDatasetQuery($values);
          $query->is_new = TRUE;
          $query->save();
          // save the terms
          _mica_query_terms_submit($query, $form_state);
        }
        else {
          // update query
          $query->name = check_plain($form_state['values']['name']);
          $query->description = $form_state['values']['description'];
          $query->cross_variable_id = $form_state['values']['cross-variable'] == '-1' ? NULL : $form_state['values']['cross-variable'];

          if (isset($form_state['values']['publish'])) {
            $query->published = $form_state['values']['publish'];
          }

          if (MicaDatasetQueryManager::isCached($query)) {
            // update terms cached
            _mica_query_terms_submit_cache($query, $form_state);
            // then save all and remove from cache
            MicaDatasetQueryManager::save($query);
          }
          else {
            // save query
            $query->save();
            // save the terms
            _mica_query_terms_submit($query, $form_state);
          }
        }
        $form_state['redirect'] = _mica_query_url($dataset_node, $query);
        $form_state['complete'] = TRUE;
        break;

      case 'run':
        // persist query and terms in the session cache
        if (!isset($query)) {
          // new query
          $values = _mica_query_extract_new_query_values($form_state);
          $query = MicaDatasetQueryManager::addQuery($values);

          // cache the terms
          _mica_query_terms_submit_cache($query, $form_state);
        }
        else {
          // update query
          $query->name = check_plain($form_state['values']['name']);
          $query->description = $form_state['values']['description'];
          $query->cross_variable_id = $form_state['values']['cross-variable'] == '-1' ? NULL : $form_state['values']['cross-variable'];

          if (MicaDatasetQueryManager::isCached($query)) {
            // update query cached
            MicaDatasetQueryManager::updateQuery($query);
            // update terms cached
            _mica_query_terms_submit_cache($query, $form_state);
          }
          else {
            // TODO not tested (currently not accessible because View is not offered for persisted queries)
            $cache = MicaDatasetQueryManager::addCache($query);
            _mica_query_terms_submit_cache($query, $form_state);
          }
        }
        $form_state['redirect'] = _mica_query_url($dataset_node, $query);
        $form_state['complete'] = TRUE;
        break;
    }
  }
}

function _mica_query_extract_new_query_values(&$form_state) {
  $dataset_node = $form_state['build_info']['args'][0];
  global $user;
  $values = array();
  $values['name'] = check_plain($form_state['values']['name']);
  $values['description'] = $form_state['values']['description'];
  $values['dataset_id'] = $dataset_node->nid;
  $values['cross_variable_id'] = $form_state['values']['cross-variable'] == '-1' ? NULL : $form_state['values']['cross-variable'];
  if (isset($form_state['values']['publish'])) {
    $values['published'] = $form_state['values']['publish'];
  }
  $values['user_id'] = $user->uid;
  $values['module'] = 'mica_query';
  return $values;
}

function _mica_query_terms_submit($query, &$form_state) {
  $data = $form_state['values']['list'];
  foreach ($data as $datum) {
    if ($datum['id'] == 0) {
      // new query term
      $values = _mica_query_extract_new_query_term_values($query, $datum);
      mica_query_term_insert($values);
    }
    else {
      $term = mica_query_term_load($datum['id']);
      $term->weight = $datum['weight'];
      $term->save();
    }
  }
  _mica_query_remove_term($query, $form_state);
}

function _mica_query_terms_submit_cache($query, &$form_state) {
  $data = $form_state['values']['list'];
  foreach ($data as $datum) {
    if ($datum['id'] == 0) {
      // new query term
      $values = _mica_query_extract_new_query_term_values($query, $datum);
      MicaDatasetQueryManager::getCache($query)->addTerm($values);
    }
    else {
      $term = MicaDatasetQueryManager::getCache($query)->getTerm($datum['id']);
      if ($term === FALSE) {
        $term = mica_query_term_load($datum['id']);
      }
      $term->weight = $datum['weight'];
      MicaDatasetQueryManager::getCache($query)->updateTerm($term);
    }
  }
}

function _mica_query_remove_term($query, &$form_state) {
  $vids = array();
  $data = $form_state['values']['list'];
  foreach ($data as $datum) {
    $vids[$datum['vid']] = $datum['vid'];
  }
  $terms = mica_query_term_query($query);
  foreach ($terms as $term) {
    if (!isset($vids[$term->variable_id])) {
      mica_query_term_delete($term->id);
    }
  }
}

function _mica_query_extract_new_query_term_values($query, $datum) {
  $values = array();
  $values['query_id'] = $query->id;
  $values['variable_id'] = $datum['vid'];
  $values['weight'] = $datum['weight'];
  return $values;
}

//
// Delete Query form
//

function mica_query_delete_modal_page($js = NULL, $dataset_node, $query) {
  if ($js) {
    $title = t('Delete !query', array('!query' => $query->name));
    mica_core_modal_form_render($title, 'mica_query_delete_form', $dataset_node, $query);
  }
  else {
    // fallback to plain page
    return mica_query_delete_page($dataset_node, $query);
  }
}

function mica_query_delete_page($dataset_node, $query) {
  drupal_set_title(t('Are you sure you want to delete query <em>!query</em>?', array('!query' => $query->name)), PASS_THROUGH);

  return drupal_get_form('mica_query_delete_form', $dataset_node, $query);
}

function mica_query_delete_form($form, &$form_state) {
  $dataset_node = $form_state['build_info']['args'][0];
//  $query = $form_state['build_info']['args'][1];

  $form['message'] = array(
    '#markup' => t('This action cannot be undone.'),
    '#attributes' => array('style'),
  );

  $form['actions'] = array(
    '#type' => 'container',
    '#attributes' => array('class' => array('form-actions')),
  );

  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Delete'),
  );

  $form['actions']['cancel'] = array(
    '#type' => 'link',
    '#title' => t('Cancel'),
    '#href' => 'node/' . $dataset_node->nid . '/queries',
  );

  return $form;
}

function mica_query_delete_form_submit($form, &$form_state) {
  $dataset_node = $form_state['build_info']['args'][0];
  $query = $form_state['build_info']['args'][1];

  // remove from database or cache
  if (MicaDatasetQueryManager::isCached($query) == FALSE) {
    // delete all terms
    $query_terms = mica_query_term_query($query);
    if ($query_terms) {
      foreach ($query_terms as $qt) {
        $qt->delete();
      }
    }

    // and then delete query
    $query->delete();
  }
  else {
    // remove from cache
    MicaDatasetQueryManager::delete($query);
  }

  $form_state['complete'] = TRUE;
  $form_state['redirect'] = 'node/' . $dataset_node->nid . '/queries';
}

//
// View and Run query
//

function mica_query_run_page($form, &$form_state, $dataset_node, $query, $cross_variable_nid = NULL) {

  drupal_set_title(t('!title -- !query', array('!title' => $dataset_node->title, '!query' => $query->name)));

  ctools_add_css('mica_datasets', 'mica_datasets');

  if (MicaDatasetQueryManager::isCached($query)) {
    global $user;
    if ($user->uid != 0) {
      drupal_set_message(t('Your query is not saved yet.'), 'warning');
    }
  }

  mica_core_modal_prepare(array(
    array(
      'name' => 'node-style',
    ),
    array(
      'name' => 'edit-style',
      'width' => 600,
      'height' => 500,
    ),
    array(
      'name' => 'delete-style',
      'width' => 400,
      'height' => 150,
    ),
  ));

  $cross_variable = node_load($query->cross_variable_id);
  if (isset($form_state['values']['cross_variable'])) {
    $cross_variable = node_load($form_state['values']['cross_variable']);
  }
  if (!empty($cross_variable_nid)) {
    $cross_variable = node_load($cross_variable_nid);
  }

  $result_table = _mica_query_result_table($dataset_node, $query, $cross_variable);


  $categorical_variables = mica_datasets_find_categorical_variables($dataset_node->nid);
  $options = array();
  foreach ($categorical_variables as $variable) {
    if (node_access('view', $variable)) {
      $options[$variable->nid] = $variable->title;
    }
  }

  $form_state['mica']['dataset_node'] = $dataset_node;
  $form_state['mica']['query'] = $query;

  $xls_link = _mica_query_xls_link($dataset_node, $query, $cross_variable);

  $form['description'] = array(
    '#markup' => '<p>' . $query->description . '</p>',
  );
  $form['cross_variable'] = array(
    '#type' => 'select',
    '#title' => t('Cross with'),
    '#options' => $options,
    '#default_value' => empty($cross_variable) ? NULL : $cross_variable->nid,
    '#empty_options' => -1,
    '#empty_value' => ' - ' . t('None') . ' - ',
    '#ajax' => array(
      'callback' => 'mica_query_run_page_submit_callback',
    ),
    '#field_suffix' => '<span id="cross-variable-detail">' . _mica_query_cross_variable_detail_link($cross_variable) . '</span>',
  );
  $form['results'] = array(
    '#markup' => $result_table . $xls_link,
    '#prefix' => '<div id="result-wrapper">',
    '#suffix' => '</div>',
  );
  return $form;
}

function _mica_query_xls_link($dataset_node, $query, $cross_variable) {
  $xls_url = url('node/' . $dataset_node->nid . '/queries/' . $query->id . '/xlsx' . (empty($cross_variable) ? '' : '/' . $cross_variable->nid));
  $xls_img_path = $GLOBALS['base_url'] . '/' . ctools_image_path('excel.png', 'mica_query');

  $xls_title = t('Download as Excel');
  $xls_img = "<img typeof='foaf:Image' class='image-style-none' src='$xls_img_path' alt='$xls_title' title='$xls_title' />";

  $xls_link = " <a href='$xls_url'>". t('!title', array('!title' => $xls_title )) ." $xls_img</a>";

  return $xls_link;
}

/**
 * Generate HTML array and save it to an XLSX file.
 *
 * @param $dataset_node
 * @param $query
 * @param null $cross_variable_nid
 */
function mica_query_run_xlsx($dataset_node, $query, $cross_variable_nid = NULL) {
  $cross_variable = empty($cross_variable_nid) ? NULL : node_load($cross_variable_nid);
  $html = _mica_query_result_table($dataset_node, $query, $cross_variable, FALSE);

  $filename = $dataset_node->title . ' - ' . $query->name;
  drupal_add_http_header('Content-Type', 'application/vnd.ms-excel');
  drupal_add_http_header('Content-Disposition', "attachment; filename=$filename.xls");

  print $html;
  drupal_exit();
}

/**
 * Selects just the result table to be returned for re-rendering.
 */
function mica_query_run_page_submit_callback($form, $form_state) {

  $dataset_node = $form_state['mica']['dataset_node'];
  $query = $form_state['mica']['query'];

  $cross_variable = isset($form_state['values']['cross_variable'])
    ? node_load($form_state['values']['cross_variable'])
    : NULL;
  $result_table = _mica_query_result_table($dataset_node, $query, $cross_variable);
  $xls_link = _mica_query_xls_link($dataset_node, $query, $cross_variable);

  return array(
    '#type' => 'ajax',
    '#commands' => array(
      ajax_command_html("#result-wrapper", $result_table . $xls_link),
      ajax_command_html("#cross-variable-detail", _mica_query_cross_variable_detail_link($cross_variable)),
    )
  );
}

function _mica_query_cross_variable_detail_link($cross_variable) {
  if (empty($cross_variable)) {
    return '';
  }
  return ctools_modal_text_button(
    t('Details'),
    'mica/nojs/node/' . $cross_variable->nid,
    t('View !title', array('!title' => $cross_variable->title)),
    'ctools-modal-node-style highlight'
  );
}

function _mica_query_result_table($dataset_node, $query, $cross_variable, $add_links = TRUE) {

  $is_cross = !empty($cross_variable);
  $category_label_by_name = array();

  if ($is_cross) {
    $cross_variable_wrapper = entity_metadata_wrapper('node', $cross_variable);
    foreach ($cross_variable_wrapper->field_variable_categories->value() as $category) {
      $category_label_by_name[$category['name']] = $category['label'];
    }
  }

  $mica_connectors = mica_connector_query_multiple($dataset_node->nid, TRUE);
  $terms = mica_query_term_query($query);

  $headers = array();
  $sub_headers = array();
  $rows = array();

  // cannot use rowspan for cross queries because of use of <thead> and <tbody>
  $headers[] = array(
    'data' => t('Study'),
  );
  $sub_headers[] = array(
    'data' => ' ',
    'header' => TRUE,
    'class' => 'border-right',
  );

  $headers_initialized = FALSE;
  $header_matched_tooltip = '';
  $header_colspan = count($category_label_by_name) + 1;

  foreach ($mica_connectors as $connector) {
    $row = array();

    $study = node_load($connector->study_id);
    $study_wrapper = entity_metadata_wrapper('node', $study);
    $acronym = $study_wrapper->field_acroym->value();
    $name = !empty($acronym) ? $study_wrapper->field_acroym->value() : $study_wrapper->title->value();

    $row[] = array(
      'data' => filter_xss($name),
      'class' => $is_cross ? 'border-right' : '',
    );

    try {
      $result = $is_cross ? $connector->queryBy($terms, array($cross_variable->title)) : $connector->query($terms);

      $total = $is_cross ? $result['_all']['_all'] : $result['total']['_all'];

      if ($is_cross) {

        if (!$headers_initialized) {
          $headers[] = array(
            'data' => t('Total'),
            'colspan' => $header_colspan,
            'class' => array('border-left', 'border-right'),
          );
        }

        foreach ($category_label_by_name as $name => $label) {
          if (!$headers_initialized) {
            $sub_headers[] = array(
              'data' => $name,
              'header' => TRUE,
              'title' => $label,
            );
          }
          $row[] = array(
            'data' => isset($result['_all'][$name]) ? $result['_all'][$name] : 0,
          );
        }
        if (!$headers_initialized) {
          $sub_headers[] = array(
            'data' => t('All'),
            'header' => TRUE,
            'class' => 'border-right',
          );
        }
        $row[] = array(
          'data' => $result['_all']['_all'],
          'class' => 'border-right',
        );
      }
      else {

        if (!$headers_initialized) {
          $headers[] = t('Total');
        }
        $row[] = $total;

      }

      $has_multiple_terms = count($terms) > 1;
      foreach ($terms as $term) {
        $impl = $term->termImpl();
        $count = $result[$impl->getName()]['_all'];

        if ($is_cross) {

          if (!$headers_initialized) {
            $headers[] = array(
              'data' => _mica_query_run_page_header($dataset_node, $query, $term, $cross_variable,
                $has_multiple_terms, $header_matched_tooltip, $add_links),
              'colspan' => $header_colspan,
              'class' => array('border-left', 'border-right'),
            );
          }

          foreach ($category_label_by_name as $name => $label) {

            if (!$headers_initialized) {
              $sub_headers[] = array(
                'data' => $name,
                'header' => TRUE,
                'title' => $label,
              );
            }
            $value = isset($result[$impl->getName()][$name]) ? $result[$impl->getName()][$name] : 0;
            $row[] = array(
              'data' => _mica_query_count_str($value, $total),
              'count' => $value,
            );
          }

          if (!$headers_initialized) {
            $sub_headers[] = array(
              'data' => t('All'),
              'header' => TRUE,
              'class' => 'border-right',
            );
          }
          $value = isset($result[$impl->getName()]['_all']) ? $result[$impl->getName()]['_all'] : 0;
          $row[] = array(
            'data' => _mica_query_count_str($value, $total),
            'count' => $value,
            'class' => 'border-right',
          );

        }
        else {

          if (!$headers_initialized) {
            $headers[] = _mica_query_run_page_header($dataset_node, $query, $term, $cross_variable, $has_multiple_terms,
              $header_matched_tooltip, $add_links);
          }
          $row[] = array(
            'data' => _mica_query_count_str($count, $total),
            'count' => $count
          );

        }

      }

      if ($is_cross) {

        if (!$headers_initialized) {
          $headers[] = array(
            'data' => t('Matched'),
            'colspan' => $header_colspan,
            'class' => array('border-left', 'border-right'),
          );
        }

        foreach ($category_label_by_name as $name => $label) {

          if (!$headers_initialized) {
            $sub_headers[] = array(
              'data' => $name,
              'header' => TRUE,
              'title' => $label,
            );
          }
          $value = isset($result['_matched'][$name]) ? $result['_matched'][$name] : 0;
          $row[] = array(
            'data' => _mica_query_count_str($value, $total),
            'class' => array('active'),
          );
        }

        if (!$headers_initialized) {
          $sub_headers[] = array(
            'data' => t('All'),
            'header' => TRUE,
            'class' => 'border-right',
          );
        }
        $row[] = array(
          'data' => _mica_query_count_str($result['_matched']['_all'], $total),
          'class' => array('active', 'border-right'),
        );

      }
      else {

        if (!$headers_initialized) {
          $headers[] = array('data' => t('Matched'));
        }

        $count = $result['_matched']['_all'];
        $row[] = array(
          'data' => _mica_query_count_str($count, $total),
          'count' => $count,
          'class' => array('active')
        );
      }

      $rows[] = array('data' => $row);

    } catch (Exception $e) {
      $connector->displayError($e);
    }

    $headers_initialized = TRUE;

  }

  // Add a summary row if there's more than one connector
  if (count($mica_connectors) > 1) {
    _mica_query_run_page_summary($rows, $header_colspan);
  }

  // add tooltip to Matched header
  $headers[count($headers) - 1]['title'] = $header_matched_tooltip;

  return theme(
    'table',
    array(
      'header' => $headers,
      'rows' => $is_cross ? array_merge(array($sub_headers), $rows) : $rows,
      'attributes' => array('class' => array('query-table')),
      'empty' => t('No connectors available')
    )
  );
}

function _mica_query_run_page_header($dataset_node, $query, $term, $cross_variable, $has_multiple_terms, &$header_matched_tooltip, $add_links = TRUE) {
  $impl = $term->termImpl();
  $title = $impl->toString();
  $variable = node_load($term->variable_id);

  if (!empty($header_matched_tooltip)) {
    $header_matched_tooltip .= ' ' . t('and') . ' ';
  }
  $header_matched_tooltip .= $title;

  if ($add_links) {
    $variable_link = ctools_modal_text_button(
      $title,
      'mica/nojs/node/' . $variable->nid,
      t('View !title', array('!title' => $variable->title)),
      'ctools-modal-node-style highlight'
    );

    $header = NULL;
    if (_mica_datasets_query_term_access($dataset_node, $query, $term)) {

      $header = $variable_link //
        . '<div>' //
        . ctools_modal_text_button(
          t('Edit'),
          'mica/nojs/' . _mica_query_term_url($dataset_node, $query, $term, 'edit', $cross_variable),
          t('Edit query term options'),
          'ctools-modal-edit-style'
        );

      if ($has_multiple_terms) {
        $header .= '<span style="margin-left: 10px;">' //
          . ctools_modal_text_button(
            t('Delete'),
            'mica/nojs/' . _mica_query_term_url($dataset_node, $query, $term, 'delete', $cross_variable),
            t('Delete query term'),
            'ctools-modal-delete-style') //
          . '</span>';
      }

      $header .= '</div>';
    }
    else {
      $header = $variable_link;
    }
  }
  else {
    $header = $title;
  }
  return $header;
}


function _mica_query_run_page_summary(&$rows, $header_total_nb_sub_header) {
  $totals = array(
    array(
      'data' => 'Totals',
      'class' => array('active')
    )
  );
  foreach ($rows as $row) {
    foreach ($row['data'] as $key => $value) {
      if ($key == 0) {
        continue;
      }
      if (!isset($totals[$key])) {
        $totals[$key] = array(
          'data' => 0,
          'count' => 0,
          'class' => array('active'),
        );
      }
      $totals[$key]['count'] +=
        isset($value['count'])
          ? $value['count']
          : (isset($value['data']) ? $value['data'] : $value);
    }
  }
  // We have the count sums, now build the count display strings (i.e. with percentage)
  $totals_count = 0;
  foreach ($totals as $key => $value) {
    if ($key == 0) {
      continue;
    }
    if ($key <= $header_total_nb_sub_header) {
      $totals_count = $totals[$key]['count'];
      $totals[$key]['data'] = $totals_count;
    }
    else {
      $totals[$key]['data'] = _mica_query_count_str($totals[$key]['count'], $totals_count);
    }
  }
  $rows[] = array(
    'data' => $totals,
    'class' => array('active'),
  );
}

/**
 * Display the count with the percentage (if applicable).
 * @param $count
 * @param $total
 * @return string
 */
function _mica_query_count_str($count, $total) {
  $data = $count;
  if (isset($count) && $total > 0) {
    $data = $count . '<br/>(' . round(100 * $count / $total, 2) . '%)';
  }
  return $data;
}



