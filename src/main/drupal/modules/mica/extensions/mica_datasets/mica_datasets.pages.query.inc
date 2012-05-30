<?php

require_once('includes/query_entity.inc');
require_once('mica_datasets.utils.inc');

/**
 * @file
 * Mica Datasets pages.
 */

//
// Queries
//

function _mica_datasets_dataset_query_url($dataset_node, $query, $action = NULL) {
  $url = 'node/' . $dataset_node->nid . '/queries/' . $query->id;
  if (isset($action)) {
    $url .= "/$action";
  }
  return $url;
}

function _mica_datasets_dataset_query_link($dataset_node, $query, $action = NULL, $title = NULL) {
  $url = _mica_datasets_dataset_query_url($dataset_node, $query, $action);
  if (!isset($title)) {
    $title = $query->name;
  }
  return l($title, $url);
}

function _mica_datasets_dataset_query_term_url($dataset_node, $query, $term, $action = NULL) {
  $url = 'node/' . $dataset_node->nid . '/queries/' . $query->id . '/term/' . $term->id;
  if (isset($action)) {
    $url .= "/$action";
  }
  return $url;
}

/**
 * Display queries.
 */
function mica_datasets_dataset_queries_page($dataset_node) {
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
        $name = _mica_datasets_dataset_query_link($dataset_node, $query);

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
          '#href' => _mica_datasets_dataset_query_url($dataset_node, $query),
          '#attributes' => array('style' => array('margin-right: 10px;')),
        );

        // author of the query or user with update dataset permission can edit/delete a query
        if (_mica_datasets_query_access($dataset_node, $query, 'update')) {
          $option['actions']['data'][] = array(
            '#type' => 'link',
            '#title' => t('Edit'),
            '#href' => _mica_datasets_dataset_query_url($dataset_node, $query, 'edit'),
            '#attributes' => array('style' => array('margin-right: 10px;')),
          );

          $option['actions']['data'][] = array(
            '#markup' => ctools_modal_text_button(t('Delete'), 'mica/nojs/' . _mica_datasets_dataset_query_url($dataset_node, $query, 'delete'), t('Delete query'), 'ctools-modal-delete-style'),
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

function mica_datasets_dataset_query_edit_page($dataset_node, $query) {
  if (isset($query)) {
    drupal_set_title(t('!title -- Edit Query', array('!title' => $dataset_node->title)));
  }
  else {
    drupal_set_title(t('!title -- Add Query', array('!title' => $dataset_node->title)));
  }

  return drupal_get_form('mica_datasets_dataset_query_edit_form', $dataset_node, $query);
}

function mica_datasets_dataset_query_edit_form($form, &$form_state) {
  global $user;
  $dataset_node = $form_state['build_info']['args'][0];
  $query = $form_state['build_info']['args'][1];

  $form = array(
    '#attached' => array('css' => array(drupal_get_path('module', 'mica_datasets') . '/includes/connection.css')),
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

  // Add a query term by selecting a variable
  $variable_options = array();
  foreach (mica_dataset_dataset_variables($dataset_node->nid) as $variable) {
    // todo cannot add a variable that is already in the process of being added
    $variable_options[$variable->nid] = $variable->title;
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

  $data = array();
  if (array_key_exists('values', $form_state)) {
    if (array_key_exists('list', $form_state['values'])) {
      foreach ($form_state['values']['list'] as $datum) {
        $qt = mica_dataset_query_term_load($datum['id']);
        $data[] = array(
          'id' => $datum['id'],
          'title' => $qt ? $qt->toString() : node_load($datum['vid'])->title,
          'vid' => $datum['vid'],
          'weight' => $datum['weight'],
          'depth' => 0,
        );
      }
    }
    if (array_key_exists('added-term', $form_state['values'])) {
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
    $terms = mica_dataset_query_term_query($query);
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

  $form['list']['#tree'] = TRUE;
  $form['list']['#theme'] = 'mica_datasets_dataset_query_edit_form';
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

function theme_mica_datasets_dataset_query_edit_form($variables) {
  $form = $variables['form'];
  drupal_add_tabledrag('draggabledemo-sort', 'order', 'sibling', 'sort');
  $header = array(t('Query Term'), t('Weight'));

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
  $output .= drupal_render_children($form, array('actions'));

  // add form hidden items, otherwise submit and validate will be ignored
  foreach (element_children($form) as $key) {
    if (strpos($key, 'form_') === 0) {
      $output .= drupal_render_children($form, array($key));
    }
  }

  return $output;
}

function mica_datasets_dataset_query_edit_form_validate($form, &$form_state) {
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

function mica_datasets_dataset_query_edit_form_submit($form, &$form_state) {
  $dataset_node = $form_state['build_info']['args'][0];
  $query = $form_state['build_info']['args'][1];

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
      $form_state['redirect'] = _mica_datasets_dataset_query_url($dataset_node, $query, 'delete');
      break;

    case 'save':
      // persist query and terms in the database
      // remove from cache
      if (!isset($query)) {
        // new query
        $values = _mica_datasets_extract_new_query_values($form_state);
        $query = new MicaDatasetQuery($values);
        $query->is_new = TRUE;
        $query->save();
        // save the terms
        _mica_datasets_query_terms_submit($query, $form_state);
      }
      else {
        // update query
        $query->name = check_plain($form_state['values']['name']);
        $query->description = $form_state['values']['description'];
        if (isset($form_state['values']['publish'])) {
          $query->published = $form_state['values']['publish'];
        }

        if (MicaDatasetQueryManager::isCached($query)) {
          // update terms cached
          _mica_datasets_query_terms_submit_cache($query, $form_state);
          // then save all and remove from cache
          MicaDatasetQueryManager::save($query);
        }
        else {
          // save query
          $query->save();
          // save the terms
          _mica_datasets_query_terms_submit($query, $form_state);
        }
      }
      $form_state['redirect'] = _mica_datasets_dataset_query_url($dataset_node, $query);
      $form_state['complete'] = TRUE;
      break;

    case 'run':
      // persist query and terms in the session cache
      if (!isset($query)) {
        // new query
        $values = _mica_datasets_extract_new_query_values($form_state);
        $query = MicaDatasetQueryManager::addQuery($values);

        // cache the terms
        _mica_datasets_query_terms_submit_cache($query, $form_state);
      }
      else {
        // update query
        $query->name = check_plain($form_state['values']['name']);
        $query->description = $form_state['values']['description'];

        if (MicaDatasetQueryManager::isCached($query)) {
          // update query cached
          MicaDatasetQueryManager::updateQuery($query);
          // update terms cached
          _mica_datasets_query_terms_submit_cache($query, $form_state);
        }
        else {
          // TODO not tested (currently not accessible because View is not offered for persisted queries)
          $cache = MicaDatasetQueryManager::addCache($query);
          _mica_datasets_query_terms_submit_cache($query, $form_state);
        }
      }
      $form_state['redirect'] = _mica_datasets_dataset_query_url($dataset_node, $query);
      $form_state['complete'] = TRUE;
      break;
  }
}

function _mica_datasets_extract_new_query_values(&$form_state) {
  $dataset_node = $form_state['build_info']['args'][0];
  global $user;
  $values = array();

  $values['name'] = check_plain($form_state['values']['name']);
  $values['description'] = $form_state['values']['description'];
  $values['dataset_id'] = $dataset_node->nid;
  if (isset($form_state['values']['publish'])) {
    $values['published'] = $form_state['values']['publish'];
  }
  $values['user_id'] = $user->uid;
  $values['module'] = 'mica_datasets';

  return $values;
}

function _mica_datasets_query_terms_submit($query, &$form_state) {
  $data = $form_state['values']['list'];
  foreach ($data as $datum) {
    if ($datum['id'] == 0) {
      // new query term
      $values = _mica_datasets_extract_new_query_term_values($query, $datum);
      mica_dataset_query_term_insert($values);
    }
    else {
      $term = mica_dataset_query_term_load($datum['id']);
      $term->weight = $datum['weight'];
      $term->save();
    }
  }
}

function _mica_datasets_query_terms_submit_cache($query, &$form_state) {
  $data = $form_state['values']['list'];
  foreach ($data as $datum) {
    if ($datum['id'] == 0) {
      // new query term
      $values = _mica_datasets_extract_new_query_term_values($query, $datum);
      MicaDatasetQueryManager::getCache($query)->addTerm($values);
    }
    else {
      $term = MicaDatasetQueryManager::getCache($query)->getTerm($datum['id']);
      if ($term === FALSE) {
        $term = mica_dataset_query_term_load($datum['id']);
      }
      $term->weight = $datum['weight'];
      MicaDatasetQueryManager::getCache($query)->updateTerm($term);
    }
  }
}

function _mica_datasets_extract_new_query_term_values($query, $datum) {
  $values = array();

  $values['query_id'] = $query->id;
  $values['variable_id'] = $datum['vid'];
  $values['weight'] = $datum['weight'];

  return $values;
}

//
// Delete Query form
//

function mica_datasets_dataset_query_delete_modal_page($js = NULL, $dataset_node, $query) {
  if ($js) {
    $title = t('Delete !query', array('!query' => $query->name));
    mica_core_modal_form_render($title, 'mica_datasets_dataset_query_delete_form', $dataset_node, $query);
  }
  else {
    // fallback to plain page
    return mica_datasets_dataset_query_delete_page($dataset_node, $query);
  }
}

function mica_datasets_dataset_query_delete_page($dataset_node, $query) {
  drupal_set_title(t('Are you sure you want to delete query <em>!query</em>?', array('!query' => $query->name)), PASS_THROUGH);

  return drupal_get_form('mica_datasets_dataset_query_delete_form', $dataset_node, $query);
}

function mica_datasets_dataset_query_delete_form($form, &$form_state) {
  $dataset_node = $form_state['build_info']['args'][0];
  $query = $form_state['build_info']['args'][1];

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

function mica_datasets_dataset_query_delete_form_submit($form, &$form_state) {
  $dataset_node = $form_state['build_info']['args'][0];
  $query = $form_state['build_info']['args'][1];

  // remove from database or cache
  if (MicaDatasetQueryManager::isCached($query) == FALSE) {
    // delete all terms
    $query_terms = mica_dataset_query_term_query($query);
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

function mica_datasets_dataset_query_run_page($form, &$form_state, $dataset_node, $query) {

  $is_cross = FALSE;
  $category_label_by_name = array();

  $cross_variable_nid = isset($form_state['values']['cross_variable']) ? $form_state['values']['cross_variable'] : NULL;
  if (!empty($cross_variable_nid)) {
    $cross_variable = node_load($cross_variable_nid);
    $is_cross = !empty($cross_variable);
    if ($is_cross) {
      $cross_variable_wrapper = entity_metadata_wrapper('node', $cross_variable);
      foreach ($cross_variable_wrapper->field_variable_categories->value() as $category) {
        $category_label_by_name[$category['name']] = $category['label'];
      }
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

  drupal_set_title(t('!title -- !query', array('!title' => $dataset_node->title, '!query' => $query->name)));

  $description = '<p>' . $query->description . '</p>';

  $mica_dataset_connectors = mica_dataset_connector_query_multiple($dataset_node->nid);
  $terms = mica_dataset_query_term_query($query);

  $headers = array();
  $sub_headers = array();
  $rows = array();

  $headers[] = t('Study');
  $sub_headers[] = array(
    'data' => ' ',
    'header' => TRUE,
  );
  $headers_initialized = FALSE;
  $header_matched_tooltip = '';
  $header_colspan = count($category_label_by_name) + 1;

  foreach ($mica_dataset_connectors as $connector) {
    $row = array();

    $study = node_load($connector->study_id);
    $row[] = filter_xss($study->title);

    try {
      $result = $is_cross ? $connector->queryBy($terms, array($cross_variable->title)) : $connector->query($terms);
//      debug($result);

      $total = $is_cross ? $result['_all']['_all'] : $result['total']['_all'];

      if ($is_cross) {

        if (!$headers_initialized) {
          $headers[] = array(
            'data' => t('Total'),
            'colspan' => $header_colspan,
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
          );
        }
        $row[] = array(
          'data' => $result['_all']['_all'],
        );
      }
      else {

        if (!$headers_initialized) $headers[] = t('Total');
        $row[] = $total;

      }

      $has_multiple_terms = count($terms) > 1;
      foreach ($terms as $term) {
        $impl = $term->termImpl();
        $count = $result[$impl->getName()]['_all'];

        if ($is_cross) {

          if (!$headers_initialized) {
            $headers[] = array(
              'data' => _mica_datasets_dataset_query_run_page_header($dataset_node, $query, $term, $has_multiple_terms, $header_matched_tooltip),
              'colspan' => $header_colspan,
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
              'data' => mica_datasets_dataset_query_count_str($value, $total),
              'count' => $value,
            );
          }

          if (!$headers_initialized) {
            $sub_headers[] = array(
              'data' => t('All'),
              'header' => TRUE,
            );
          }
          $value = isset($result[$impl->getName()]['_all']) ? $result[$impl->getName()]['_all'] : 0;
          $row[] = array(
            'data' => mica_datasets_dataset_query_count_str($value, $total),
            'count' => $value,
          );

        }
        else {

          if (!$headers_initialized) {
            $headers[] = _mica_datasets_dataset_query_run_page_header($dataset_node, $query, $term, $has_multiple_terms,
              $header_matched_tooltip);
          }
          $row[] = array(
            'data' => mica_datasets_dataset_query_count_str($count, $total),
            'count' => $count
          );

        }

      }

      if ($is_cross) {

        if (!$headers_initialized) {
          $headers[] = array(
            'data' => t('Matched'),
            'colspan' => $header_colspan,
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
            'data' => mica_datasets_dataset_query_count_str($value, $total),
            'class' => array('active'),
          );
        }

        if (!$headers_initialized) {
          $sub_headers[] = array(
            'data' => t('All'),
            'header' => TRUE,
          );
        }
        $row[] = array(
          'data' => mica_datasets_dataset_query_count_str($result['_matched']['_all'], $total),
          'class' => array('active'),
        );

      }
      else {

        if (!$headers_initialized) {
          $headers[] = array('data' => t('Matched'));
        }

        $count = $result['_matched']['_all'];
        $row[] = array(
          'data' => mica_datasets_dataset_query_count_str($count, $total),
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
  if (count($mica_dataset_connectors) > 1) {
    _mica_datasets_dataset_query_run_page_summary($rows, $header_colspan);
  }

  if (MicaDatasetQueryManager::isCached($query)) {
    global $user;
    if ($user->uid != 0) {
      drupal_set_message(t('Your query is not saved yet.'), 'warning');
    }
  }

  // add tooltip to Matched header
  $headers[count($headers) - 1]['title'] = $header_matched_tooltip;

  $table_result = theme(
    'table',
    array(
      'header' => $headers,
      'rows' => $is_cross ? array_merge(array($sub_headers), $rows) : $rows,
      'attributes' => array('class' => array('query-table')),
      'empty' => t('No connectors available')
    )
  );

  $categorical_variables = mica_datasets_find_categorical_variables($dataset_node->nid);
  $options = array();
  foreach ($categorical_variables as $variable) {
    $options[$variable->nid] = $variable->title;
  }

  $form['description'] = array(
    '#markup' => $description,
  );
  $form['cross_variable'] = array(
    '#type' => 'select',
    '#title' => t('Cross with'),
    '#options' => $options,
    '#empty_options' => -1,
    '#empty_value' => ' - ' . t('None') . ' - ',
    '#ajax' => array(
      'callback' => 'mica_datasets_dataset_query_run_page_submit_callback',
      'wrapper' => 'query-results-table',
    ),
  );
  $form['results'] = array(
    '#markup' => $table_result,
    '#prefix' => '<div id="query-results-table">',
    '#suffix' => '</div>',
  );
  return $form;
}

function mica_datasets_dataset_query_run_page_submit($form, &$form_state) {
  // Setting $form_state['rebuild'] = TRUE causes the form to be rebuilt again.
  $form_state['rebuild'] = TRUE;
}

/**
 * Selects just the result table to be returned for re-rendering.
 */
function mica_datasets_dataset_query_run_page_submit_callback($form, $form_state) {
  return $form['results'];
}



function _mica_datasets_dataset_query_run_page_header($dataset_node, $query, $term, $has_multiple_terms, &$header_matched_tooltip) {
  $impl = $term->termImpl();
  $title = $impl->toString();
  $variable = node_load($term->variable_id);

  if (!empty($header_matched_tooltip)) $header_matched_tooltip .= ' ' . t('and') . ' ';
  $header_matched_tooltip .= $title;

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
        'mica/nojs/' . _mica_datasets_dataset_query_term_url($dataset_node, $query, $term, 'edit'),
        t('Edit query term options'),
        'ctools-modal-edit-style'
      );

    if ($has_multiple_terms) {
      $header .= '<span style="margin-left: 10px;">' //
        . ctools_modal_text_button(
          t('Delete'),
          'mica/nojs/' . _mica_datasets_dataset_query_term_url($dataset_node, $query, $term, 'delete'),
          t('Delete query term'),
          'ctools-modal-delete-style') //
        . '</span>';
    }

    $header .= '</div>';
  }
  else {
    $header = $variable_link;
  }

  return $header;
}


function _mica_datasets_dataset_query_run_page_summary(&$rows, $header_total_nb_sub_header) {
  $totals = array(
    array(
      'data' => 'Totals',
      'class' => array('active')
    )
  );
  foreach ($rows as $row) {
    foreach ($row['data'] as $key => $value) {
      if ($key == 0) continue;
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
    if ($key == 0) continue;
    if ($key <= $header_total_nb_sub_header) {
      $totals_count = $totals[$key]['count'];
      $totals[$key]['data'] = $totals_count;
    }
    else {
      $totals[$key]['data'] = mica_datasets_dataset_query_count_str($totals[$key]['count'], $totals_count);
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
function mica_datasets_dataset_query_count_str($count, $total) {
  $data = $count;
  if (isset($count) && $total > 0) {
    $data = $count . '<br/>(' . round(100 * $count / $total) . '%)';
  }
  return $data;
}

//
// Query Term Form
//

/**
 * Page to display the edit query term form in a modal dialog.
 * @param $js
 * @param $node
 * @param $query
 * @param $term
 */
function mica_datasets_dataset_query_term_edit_modal_page($js = NULL, $node, $query, $term) {
  if ($js) {
    $impl = $term->termImpl();
    $title = t('Edit !term', array('!term' => $impl->getFieldName()));
    mica_core_modal_form_render($title, 'mica_datasets_dataset_query_term_edit_form', $node, $query, $term);
  }
  else {
    // fallback to plain page
    return mica_datasets_dataset_query_term_edit_page($node, $query, $term);
  }
}

/**
 * Page to display the edit query term form.
 * @param $node
 * @param $query
 * @param $term
 */
function mica_datasets_dataset_query_term_edit_page($node, $query, $term) {
  $impl = $term->termImpl();
  drupal_set_title(t('!title -- Edit !term in !query', array('!title' => $node->title, '!query' => $query->name, '!term' => $impl->getFieldName())));
  return drupal_get_form('mica_datasets_dataset_query_term_edit_form', $node, $query, $term);
}

function mica_datasets_dataset_query_term_edit_form($form, &$form_state) {
  $form = array();

  $dataset_node = $form_state['build_info']['args'][0];
  $query = $form_state['build_info']['args'][1];
  $term = $form_state['build_info']['args'][2];
  $variable = node_load($term->variable_id);

  $form = array();

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
    '#href' => _mica_datasets_dataset_query_url($dataset_node, $query),
  );

  return $form;
}

function mica_datasets_dataset_query_term_edit_form_validate($form, &$form_state) {
  $term_entity = $form_state['build_info']['args'][2];
  $impl = $term_entity->termImpl();
  $impl->validate($form, $form_state);
}

function mica_datasets_dataset_query_term_edit_form_submit($form, &$form_state) {
  $dataset_node = $form_state['build_info']['args'][0];
  $query = $form_state['build_info']['args'][1];
  $term = $form_state['build_info']['args'][2];

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
    $form_state['redirect'] = _mica_datasets_dataset_query_url($dataset_node, $query);
  }
}

function variables_autocomplete($dataset_nid, $string) {
  $variables = array();
  foreach (mica_dataset_dataset_variables($dataset_nid) as $variable) {
    if (strpos(strtolower($variable->title), $string) === 0 || $string === "*") {
      $variables[$variable->title] = $variable->title;
    }
  }
  print drupal_json_encode($variables);
  exit;
}

//
// View Query Term
//

function mica_datasets_dataset_query_term_page($dataset_node, $query, $term) {
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
function mica_datasets_dataset_query_term_delete_modal_page($js = NULL, $node, $query, $term) {
  if ($js) {
    $impl = $term->termImpl();
    $title = t('Delete !term', array('!term' => $impl->getFieldName()));
    mica_core_modal_form_render($title, 'mica_datasets_dataset_query_term_delete_form', $node, $query, $term);
  }
  else {
    // fallback to plain page
    return mica_datasets_dataset_query_term_delete_page($node, $query, $term);
  }
}

/**
 * Page to display the delete query term form.
 * @param $dataset_node
 * @param $query
 * @param $term
 */
function mica_datasets_dataset_query_term_delete_page($dataset_node, $query, $term) {
  drupal_set_title(t('Are you sure you want to delete query term <em>!term</em>?', array('!term' => $term->toString())), PASS_THROUGH);

  return drupal_get_form('mica_datasets_dataset_query_term_delete_form', $dataset_node, $query, $term);
}

function mica_datasets_dataset_query_term_delete_form($form, &$form_state) {
  $dataset_node = $form_state['build_info']['args'][0];
  $query = $form_state['build_info']['args'][1];
  $term = $form_state['build_info']['args'][2];

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
    '#href' => _mica_datasets_dataset_query_url($dataset_node, $query),
  );

  return $form;
}

function mica_datasets_dataset_query_term_delete_form_submit($form, &$form_state) {
  $dataset_node = $form_state['build_info']['args'][0];
  $query = $form_state['build_info']['args'][1];
  $term = $form_state['build_info']['args'][2];

  if (is_numeric($term->id)) {
    // delete term
    $term->delete();
  }
  else {
    MicaDatasetQueryManager::getCache($query)->deleteTerm($term);
  }

  $form_state['complete'] = TRUE;
  $form_state['redirect'] = _mica_datasets_dataset_query_url($dataset_node, $query);
}

/**
 * Function callback ajax of RangeTerm
 *
 * @param $form
 * @param $form_state
 */
function replace_value_container(&$form, &$form_state) {
  return $form['valuecontainer'];
}
