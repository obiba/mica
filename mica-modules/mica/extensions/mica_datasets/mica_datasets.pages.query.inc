<?php

/**
 * @file
 * Mica Datasets pages.
 */

//
// Queries form
//

/**
 * Display form for submitting queries.
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
          'name' => l($query->name,'mica/dataset/' . $dataset_node->nid . '/query/' . $query->id),
          'description' => $query->description,
          'actions' => array(
            'data' => array(
        array(
              '#type' => 'link',
              '#title' => t('Run'),
              '#href' => 'mica/dataset/' . $dataset_node->nid . '/query/' . $query->id . '/run',
        ),
        )),
        );

        // author of the query or user with update dataset permission can edit/delete a query
        if ($user->uid == $query->user_id || node_access('update', $dataset_node)) {
          $option['actions']['data'][] = array(
              '#type' => 'link',
              '#title' => t('Edit'),
              '#href' => 'mica/dataset/' . $dataset_node->nid . '/query/' . $query->id . '/edit',
              '#attributes' => array('style' => array('margin-left: 10px;')),
          );
           
          $option['actions']['data'][] =  array(
              '#type' => 'link',
              '#title' => t('Delete'),
              '#href' => 'mica/dataset/' . $dataset_node->nid . '/query/' . $query->id . '/delete',
              '#attributes' => array('style' => array('margin-left: 10px;')),
          );
        }

        $options[] = $option;
      }
    }
  }

  return theme('table', array('header' => $header, 'rows' => $options, 'empty' => t('No query found')));
}

//
// View Query
//

function mica_datasets_dataset_query_page($dataset_node, $query_id) {
  $query = mica_dataset_query_load($query_id);
  drupal_set_title(t('!title -- !query', array('!title' => $dataset_node->title, '!query' => $query->name)));

  $items = array();

  $items[] = $query->description;

  // add saved query terms ordered by weight
  $rows = array();
  foreach (mica_dataset_query_term_query($query_id) as $query_term) {
    $rows[] = array(
      'title' => $query_term->toExpString(),
      'operations' => array(
        'data' => array(
            'data' => array(
        array(
              '#type' => 'link',
              '#title' => t('Edit'),
              '#href' => 'mica/dataset/' . $dataset_node->nid . '/query/' . $query->id . '/term/' . $query_term->id . '/edit',
        ),
        array(
              '#type' => 'link',
              '#title' => t('Delete'),
              '#href' => 'mica/dataset/' . $dataset_node->nid . '/query/' . $query->id . '/term/' . $query_term->id . '/delete',
              '#attributes' => array('style' => array('margin-left: 10px;')),
        ),
        ))),    
    );
  }

  $header = array(t('Query Term'), t('Operations'));

  $items[] = theme('table', array('header' => $header, 'rows' => $rows, 'empty' => t('No query term found')));

  return theme('item_list', array('items' => $items));
}

//
// Add/Edit Query form
//

function mica_datasets_dataset_query_edit_page($dataset_node, $query_id) {
  if ($query_id != '0') {
    drupal_set_title(t('!title -- Edit Query', array('!title' => $dataset_node->title)));
  }
  else {
    $query_id = 0;
    drupal_set_title(t('!title -- Add Query', array('!title' => $dataset_node->title)));
  }

  return  drupal_get_form('mica_datasets_dataset_query_edit_form', $dataset_node, $query_id);
}

function mica_datasets_dataset_query_edit_form($form, &$form_state) {
  $dataset_node = $form_state['build_info']['args'][0];
  $query_id = $form_state['build_info']['args'][1];
  $query = NULL;
  if ($query_id != 0) {
    $query = mica_dataset_query_load($query_id);
  }

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
    '#title' => t('Publish'),
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
          'title' => $qt->toExpString(), //$datum['id'] == 0 ? $datum['expression'] : $qt->options['value'],
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
    foreach (mica_dataset_query_term_query($query_id) as $query_term) {
      $data[] = array(
        'id' => $query_term->id,
        'title' => $query_term->toExpString(),
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

  if ($query) {
    $form['actions']['delete'] = array(
      '#type' => 'submit',
      '#value' => t('Delete'),
    );
  }

  $form['actions']['dataset-link'] = array(
    '#type' => 'link',
    '#title' => t('Cancel'),
    '#href' => 'node/' . $dataset_node->nid . '/queries',
    '#attributes' => array('style' => 'margin:0 5px 0 5px;'),
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
  $query_id = $form_state['build_info']['args'][1];

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
      $form_state['redirect'] = 'mica/dataset/' . $dataset_node->nid . '/query/' . $query_id . '/delete';
      break;
    case 'submit':
      if ($query_id == 0) {
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
            _mica_datasets_query_terms_save($rval, $form_state['values']['list']);
          }
        }
      }
      else {
        // update the weights
        $query = mica_dataset_query_load($query_id);
        $query->name = check_plain($form_state['values']['name']);
        $query->description = $form_state['values']['description'];
        $query->published = $form_state['values']['publish'];

        $query->save();

        // save the terms
        if (array_key_exists('list', $form_state['values'])) {
          _mica_datasets_query_terms_save($query_id, $form_state['values']['list']);
        }
      }

      drupal_set_message(t('Your configuration has been saved.'));
      $form_state['redirect'] = 'node/' . $dataset_node->nid . '/queries';
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
        'type' => 'expression',
        'value' => $datum['expression'],
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

function mica_datasets_dataset_query_delete_page($dataset_node, $query_id) {
  $query = mica_dataset_query_load($query_id);
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

  $form['actions']['dataset-link'] = array(
    '#type' => 'link',
    '#title' => t('Cancel'),
    '#href' => 'node/' . $dataset_node->nid . '/queries',
    '#attributes' => array('style' => array('margin:0 5px 0 5px;')),
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
// Run query
//

function mica_datasets_dataset_query_run_page($dataset_node, $query_id) {
  $query = mica_dataset_query_load($query_id);
  drupal_set_title(t('!title -- Run !query', array('!title' => $dataset_node->title, '!query' => $query->name)));

  return _doQuery($dataset_node, $query);
}

function _doQuery($dataset_node, $query_node) {
  $mica_dataset_connectors = mica_dataset_connector_query_multiple($dataset_node->nid);
  $variables = array();
  foreach(mica_dataset_query_term_query($query_node->id) as $term) {
    $variable = node_load($term->variable_id);
    array_push($variables, $variable->title);
  }

  $columns = array_merge(array('Study', 'Total') , $variables);
  $h = "<table><thead><tr>";
  foreach($columns as $var) {
    $h .=  "<th>" . $var . "</th>";
  }
  $h .= "</tr></thread><tbody>";
  foreach($mica_dataset_connectors as $connector) {
    $study = node_load($connector->study_id);
    try {
      $result = $connector->query($variables);
      $h .= "<tr><td>" . $study->title . "</td><td>".$result['total']."</td>";
      foreach($variables as $var) {
        $h.="<td>" . $result[$var] . "</td>";
      }
      $h .=  "</tr>";
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
  $h .= "</tbody></table>";

  return $h;
}

//
// Query Term Form
//

function mica_datasets_dataset_query_term_page($node, $query_id, $term_id) {
  $query = mica_dataset_query_load($query_id);
  $term = mica_dataset_query_term_load($term_id);
  drupal_set_title(t('!title -- Edit !term in !query', array('!title' => $node->title, '!query' => $query->name, '!term' => $term->id)));
  return  drupal_get_form('mica_datasets_dataset_query_term_form', $node, $query, $term);
}

function mica_datasets_dataset_query_term_form($form, &$form_state) {
  $form = array();

  $dataset_node = $form_state['build_info']['args'][0];
  $query_node = $form_state['build_info']['args'][1];
  $term_entity = $form_state['build_info']['args'][2];
  $variable = node_load($term_entity->variable_id);

  $form=array();

  $is_categorical=$variable->field_categories['und'][0]['value'] !== '';
  if($is_categorical) {
    append_categorical_form($form,$variable);
  } else {
    append_open_form($form);
  }


  $form['actions']['save'] = array(
    '#type' => 'submit',
    '#value' => t('Save'),
  );
  return $form;
}

/**
 * Form for categorical variable
 */
function append_categorical_form(&$form, &$variable) {

  // TODO: why is the first category '' when the variable doesn't have any categories?
  $is_categorical=$variable->field_categories['und'][0]['value'] !== '';
  $is_repeatable=$variable->field_repeatable['und'][0]['value'] === '1';
  $type=$variable->field_value_type['und'][0]['value'];

  $form['operator']=array(
    '#title' => t('Operator'), 
    '#type' => 'select',
    '#required' => TRUE,
    '#options' => get_operators($type, $is_categorical),    
  );

  $options = array();
  foreach($variable->field_categories['und'] as $category) {
    // TODO: wtf! if the category's label is 0, it does not appear. So we add a &nbsp; so that it is no longer 0.
    $options['c_'.$category["value"]] = $category["value"] . "&nbsp;";
  }

  $form['categories'] = array(
      '#type' => 'checkboxes',
      '#title' => 'Categories',
      '#options' => $options,
      '#default_value' => isset($term_entity->options['state']['categories']) ? $term_entity->options['state']['categories'] : array(),
  );
}
/**
 * Form for "continue" value of variable
 */
function append_open_form(&$form) {
  $form['min'] = array(
      '#type' => 'textfield',
      '#title' => 'Min',
  );
   $form['max'] = array(
      '#type' => 'textfield',
      '#title' => 'Max',
  );
}



function mica_datasets_dataset_query_term_form_validate($form, &$form_state) {
}

function mica_datasets_dataset_query_term_form_submit($form, &$form_state) {
  drupal_set_message(t('Term configuration saved.'));

  $dataset_node = $form_state['build_info']['args'][0];
  $query_entity = $form_state['build_info']['args'][1];
  $term_entity = $form_state['build_info']['args'][2];
  $variable = node_load($term_entity->variable_id);

  $term_entity->options['value'] = $variable->title;
  $term_entity->options['state'] = $form_state['values'];

  $term_entity->save();

  $form_state['redirect'] = 'mica/dataset/' . $dataset_node->nid . '/query/' . $query_entity->id . '/edit';
}

//
// Delete Query Term
//

function mica_datasets_dataset_query_term_delete_page($dataset_node, $query_id, $term_id) {
  $query = mica_dataset_query_load($query_id);
  $term = mica_dataset_query_term_load($term_id);
  drupal_set_title(t('Are you sure you want to delete query term <em>!term</em>?', array('!term' => $term->toExpString())), PASS_THROUGH);

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

  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Delete'),
  );

  $form['actions']['dataset-link'] = array(
    '#type' => 'link',
    '#title' => t('Cancel'),
    '#href' => 'mica/dataset/' . $dataset_node->nid . '/query/' . $query->id,
    '#attributes' => array('style' => array('margin:0 5px 0 5px;')),
  );

  return $form;
}

function mica_datasets_dataset_query_term_delete_form_submit($form, &$form_state) {
  $dataset_node = $form_state['build_info']['args'][0];
  $query = $form_state['build_info']['args'][1];
  $term = $form_state['build_info']['args'][2];

  // delete term
  $term->delete();

  $form_state['redirect'] = 'mica/dataset/' . $dataset_node->nid . '/query/' . $query->id;
}

function get_operators($type,  $is_categorical) {
  if($is_categorical) {
    return array('is' => 'in', 'dif' => 'not in');
  } else {
    return array('inf' => '<', 'sup' => '>', 'eq' => '=', 'dif' => '!=');
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
