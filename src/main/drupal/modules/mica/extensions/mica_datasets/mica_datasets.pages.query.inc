<?php

/**
 * @file
 * Mica Datasets pages.
 */

//
// Queries
//

function _mica_datasets_dataset_query_url($dataset_node, $query_entity, $action = NULL) {
  $url = 'node/' . $dataset_node->nid . '/queries/' . $query_entity->id;
  if(isset($action)) {
    $url .= "/$action";
  }
  return $url;
}

function _mica_datasets_dataset_query_link($dataset_node, $query_entity, $action = NULL, $title = NULL) {
  $url = _mica_datasets_dataset_query_url($dataset_node, $query_entity, $action);
  if(isset($title) == false) {$title = $query_entity->name;
  }
  return l($title, $url);
}

function _mica_datasets_dataset_query_term_url($dataset_node, $query_entity, $term_entity, $action = NULL) {
  $url = 'node/' . $dataset_node->nid . '/queries/' . $query_entity->id . '/term/' . $term_entity->id;
  if(isset($action)) {
    $url .= "/$action";
  }
  return $url;
}

/**
 * Display queries.
 */
function mica_datasets_dataset_queries_page($dataset_node) {
  drupal_set_title(t('!title -- Queries', array('!title' => $dataset_node->title)));

  global $user;

  $header = array (
    'name' => t('Name'),
    'description' => t('Description'),
    'actions' => t('Operations'),
  );

  $options = array();

  $queries = mica_dataset_query_query($dataset_node->nid);
  if ($queries) {
    foreach ($queries as $query) {
      if ($query->published || $query->user_id == $user->uid) {
        $option = array(
          'name' => _mica_datasets_dataset_query_link($dataset_node, $query),
          'description' => $query->description,
          'actions' => array('data' => array())
        );

        $option['actions']['data'][] = array(
          '#type' => 'link',
          '#title' => t('View'),
          '#href' => _mica_datasets_dataset_query_url($dataset_node, $query, 'view'),
          '#attributes' => array('style' => array('margin-right: 10px;')),
        );

        // author of the query or user with update dataset permission can edit/delete a query
        $update_access = _mica_datasets_query_access($dataset_node, $query, 'update');
        if ($update_access) {
          $option['actions']['data'][] = array(
              '#type' => 'link',
              '#title' => t('Edit'),
              '#href' => _mica_datasets_dataset_query_url($dataset_node, $query, 'edit'),
              '#attributes' => array('style' => array('margin-right: 10px;')),
          );
           
          $option['actions']['data'][] =  array(
              '#type' => 'link',
              '#title' => t('Delete'),
              '#href' => _mica_datasets_dataset_query_url($dataset_node, $query, 'delete'),
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

  return  drupal_get_form('mica_datasets_dataset_query_edit_form', $dataset_node, $query);
}

function mica_datasets_dataset_query_edit_form($form, &$form_state) {
  $dataset_node = $form_state['build_info']['args'][0];
  $query = $form_state['build_info']['args'][1];

  $form = array(
  	'#attached' => array('css' => array(drupal_get_path('module', 'mica_datasets') . '/includes/connection.css'),),
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

  $form['general']['publish'] = array(
    '#type' => 'checkbox', 
    '#title' => t('Published'),
    '#default_value' => $query ? $query->published : 0,
  );

  // Add a query term by selecting a variable
  $variable_options = array();
  foreach(mica_dataset_dataset_participant_variables($dataset_node->nid) as $variable) {
    // todo cannot add a variable that is already in the process of being added
    $variable_options[$variable->nid] = $variable->title;
  }

  if (!empty($variable_options)) {
    $form['add-term']['variables']= array(
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
    //debug($form_state['values']);
    if (array_key_exists('list', $form_state['values'])) {
      foreach($form_state['values']['list'] as $datum) {
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
    $terms = mica_dataset_query_term_query($query->id);
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

  $form['actions']= array(
    '#type' => 'container',
    '#attributes' => array('class' => array('form-actions')),
  );

  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save'),
  );

  return $form;
}

function theme_mica_datasets_dataset_query_edit_form($variables) {
  $form = $variables['form'];
  drupal_add_tabledrag('draggabledemo-sort', 'order', 'sibling', 'sort');
  $header = array(t('Query Term'),t('Weight'));

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

  $output = drupal_render_children($form,array('general'));
  if (array_key_exists('add-term', $form)) {
    $output .= drupal_render_children($form,array('add-term'));
  }
  $output .= theme('table', array('header' => $header, 'rows' => $rows, 'empty' => t('No query term found'), 'attributes' => array('id' => 'draggabledemo-sort')));
  $output .= drupal_render_children($form,array('actions'));

  // add form hidden items, otherwise submit and validate will be ignored
  foreach(element_children($form) as $key) {
    if (strpos($key,'form_') === 0) {
      $output .= drupal_render_children($form,array($key));
    }
  }

  return $output;
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
    case 'submit':
      if (!isset($query)) {
        global $user;
        $values = array();
        $values['name'] = check_plain($form_state['values']['name']);
        $values['description'] = $form_state['values']['description'];
        $values['dataset_id'] = $dataset_node->nid;
        $values['published'] = $form_state['values']['publish'];
        $values['user_id'] = $user->uid;
        $values['module'] = 'mica_datasets';

        $rval = mica_dataset_query_insert($values);
        if ($rval === FALSE) {
          drupal_set_message(t('Unable to save query: !name', array('!name' => $values['name'])), 'error');
        }
        else {
          // save the terms
          if (array_key_exists('list', $form_state['values'])) {
            _mica_datasets_query_terms_save($rval->id, $form_state['values']['list']);
          }
        }
      }
      else {
        // update the weights
        $query->name = check_plain($form_state['values']['name']);
        $query->description = $form_state['values']['description'];
        $query->published = $form_state['values']['publish'];

        $query->save();

        // save the terms
        if (array_key_exists('list', $form_state['values'])) {
          _mica_datasets_query_terms_save($query->id, $form_state['values']['list']);
        }
      }

      drupal_set_message(t('Your configuration has been saved.'));
      $form_state['redirect'] = _mica_datasets_dataset_query_url($dataset_node, isset($query) ? $query : $rval);
      break;
  }
}

function _mica_datasets_query_terms_save($query_id, $data) {
  foreach ($data as $datum) {
    if ($datum['id'] == 0) {
      // new query term
      $values = array();
      $values['query_id'] = $query_id;
      $values['variable_id'] = $datum['vid'];
      $values['weight'] = $datum['weight'];
      $values['module'] = 'mica_datasets';
      $values['options'] = array(
        'type' => AbstractTerm::typeFor(node_load($values['variable_id']))
      );

      mica_dataset_query_term_insert($values);
    }
    else {
      $query_term = mica_dataset_query_term_load($datum['id']);
      $query_term->weight = $datum['weight'];
      $query_term->save();
    }
  }
}


//
// Delete Query form
//

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

  $form['actions']= array(
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
    '#href' => 'node/'.$dataset_node->nid.'/queries',
  );

  return $form;
}

function mica_datasets_dataset_query_delete_form_submit($form, &$form_state) {
  $dataset_node = $form_state['build_info']['args'][0];
  $query = $form_state['build_info']['args'][1];

  // delete all terms
  $query_terms = mica_dataset_query_term_query($query->id);
  if ($query_terms) {
    foreach ($query_terms as $qt) {
      $qt->delete();
    }
  }

  // and then delete query
  $query->delete();

  $form_state['redirect'] = 'node/' . $dataset_node->nid . '/queries';
}

//
// View and Run query
//

function mica_datasets_dataset_query_run_page($dataset_node, $query_node) {

  mica_modal_prepare(array(
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

  drupal_set_title(t('!title -- !query', array('!title' => $dataset_node->title, '!query' => $query_node->name)));

  $description = '<p>' . $query_node->description . '</p>';

  $mica_dataset_connectors = mica_dataset_connector_query_multiple($dataset_node->nid);
  $terms = mica_dataset_query_term_query($query_node->id);

  $labels = array();
  if ($terms!==FALSE) {
    foreach($terms as $term) {
      $impl = $term->termImpl();
      $title = $impl->toString();
      $variable = node_load($term->variable_id);
      $variable_link = ctools_modal_text_button($title, 'mica/nojs/node/' . $variable->nid, t('View !title', array('!title' => $variable->title)), 'ctools-modal-node-style');

      if (_mica_datasets_query_term_access($dataset_node, $query_node, $term)) {
        $labels[] = $variable_link //
        . '<div>' //
        . ctools_modal_text_button(t('Edit'), 'mica/nojs/' . _mica_datasets_dataset_query_term_url($dataset_node, $query_node, $term, 'edit'), t('Edit query term options'), 'ctools-modal-edit-style') //
        . '<span style="margin-left: 10px;">' //
        . ctools_modal_text_button(t('Delete'), 'mica/nojs/' . _mica_datasets_dataset_query_term_url($dataset_node, $query_node, $term, 'delete'), t('Delete query term'), 'ctools-modal-delete-style') //
        . '</span></div>' ;
      }
      else {
        $labels[] = $variable_link;
      }
    }
  }

  $columns = array_merge(array(t('Study'), t('Total')) , $labels);
  $columns[] = t('Matched');

  $rows = array();
  foreach($mica_dataset_connectors as $connector) {
    $study = node_load($connector->study_id);
    $row = array(array('data'=>$study->title));
    try {
      $result = $connector->query($terms);
      $row[] = $result['total'];
      foreach($terms as $t) {
        $impl = $t->termImpl();
        $row[] = $result[$impl->getName()];
      }
      $row[] = array('data'=>$result['_matched'], 'class'=>array('active'));
      $rows[] = array('data'=> $row);
    } catch(Exception $e) {
      if($e->getCode() == 401) {
        drupal_set_message(t("Study %study: Authentication failed (401).", array("%study" => $study->title)), 'error');
      } else if($e->getCode() == 403) {
        drupal_set_message(t("Study %study: Not authorized to search dataset (403).", array("%study" => $study->title)), 'error');
      } else if($e->getCode() == 404) {
        drupal_set_message(t("Study %study: Cannot find dataset (404). Make sure the study's configuration is valid.", array("%study" => $study->title)), 'error');
      } else {
        drupal_set_message(t("Study %study: Failed executing search. Message was: %msg", array("%study" => $study->title, "%msg" => $e->getMessage())), 'error');
      }
    }
  }

  // Add a summary row if there's more than one connector
  if(count($mica_dataset_connectors) > 1) {
    $totals = array(array('data'=>'Totals', 'class'=>array('active')));
    foreach($rows as $row) {
      foreach($row['data'] as $key => $value) {
        if($key == 0) continue;
        if(isset($totals[$key]) == FALSE) {
          $totals[$key] = array('data'=> 0, 'class'=>'active');
        }
        $totals[$key]['data'] += isset($value['data']) ? $value['data'] : $value;
      }
    }
    $rows[] = array('data' => $totals, 'class' => array('active'));
  }

  return $description . theme('table', array("header"=>$columns, "rows"=>$rows, 'attributes'=>array('class'=>array('query-table')), 'empty' => t('No connectors available')));
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
    mica_modal_form_render($title, 'mica_datasets_dataset_query_term_edit_form', $node, $query, $term);
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
  return  drupal_get_form('mica_datasets_dataset_query_term_edit_form', $node, $query, $term);
}

function mica_datasets_dataset_query_term_edit_form($form, &$form_state) {
  $form = array();

  $dataset_node = $form_state['build_info']['args'][0];
  $query = $form_state['build_info']['args'][1];
  $term = $form_state['build_info']['args'][2];
  $variable = node_load($term->variable_id);

  $form=array();

  $impl = $term->termImpl();
  $termForm = $impl->form($form, $form_state);
  $form[] = $termForm;

  $form['actions']['save'] = array(
    '#type' => 'submit',
    '#value' => t('Save'),
  );

  $form['actions']['cancel'] = array(
    '#type' => 'link',
    '#title' => t('Cancel'),
    '#href' => 'node/'.$dataset_node->nid.'/queries/'.$query->id.'/view',
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
  $query_entity = $form_state['build_info']['args'][1];
  $term_entity = $form_state['build_info']['args'][2];

  $impl = $term_entity->termImpl();
  $impl->submit($form, $form_state);

  $errors = form_get_errors();
  if(empty($errors)) {
    switch ($form_state['triggering_element']['#parents'][0]) {
      case 'save':
        $term_entity->save();
        drupal_set_message(t('Query term options saved.'));
        $form_state['complete'] = TRUE;
        break;
      case 'cancel':
        $form_state['cancel'] = TRUE;
        break;
    }
    $form_state['redirect'] = _mica_datasets_dataset_query_url($dataset_node, $query_entity);
  }
}

function variables_autocomplete($dataset_nid, $string) {
  $variables = array();
  foreach(mica_dataset_dataset_participant_variables($dataset_id) as $variable) {
    if (strpos(strtolower($variable->title), $string) === 0 || $string === "*") {
      $variables[$variable->title]=$variable->title;
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
    mica_modal_form_render($title, 'mica_datasets_dataset_query_term_delete_form', $node, $query, $term);
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

  $form['actions']= array(
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
    '#href' => 'node/'.$dataset_node->nid.'/queries/'.$query->id.'/view',
  );

  return $form;
}

function mica_datasets_dataset_query_term_delete_form_submit($form, &$form_state) {
  $dataset_node = $form_state['build_info']['args'][0];
  $query = $form_state['build_info']['args'][1];
  $term = $form_state['build_info']['args'][2];

  // delete term
  $term->delete();

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
