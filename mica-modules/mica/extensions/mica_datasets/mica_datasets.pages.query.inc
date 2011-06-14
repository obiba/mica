<?php

/**
 * @file
 * Mica Datasets pages.
 */


/**
 * Display form for submitting queries.
 */
function mica_datasets_dataset_queries_page($node) {
  drupal_set_title(t('!title -- Queries', array('!title' => $node->title)));

  return  drupal_get_form('mica_datasets_dataset_queries_form', $node);

}

function mica_datasets_dataset_query_page($node, $query_id) {
  if ($query_id != '0') {
    drupal_set_title(t('!title -- Edit Query', array('!title' => $node->title)));
  }
  else {
    $query_id = 0;
    drupal_set_title(t('!title -- Add Query', array('!title' => $node->title)));
  }

  return  drupal_get_form('mica_datasets_dataset_query_form', $node, $query_id);
}

//
// Queries form
//

function mica_datasets_dataset_queries_form($form, &$form_state) {
  global $user;
  $dataset_node = $form_state['build_info']['args'][0];
  
  $header = array (
    'name' => t('Name'),
    'description' => t('Description'),
    'actions' => t('Operations'),
  );

  $options = array();
  
  foreach (mica_dataset_query_query($dataset_node->nid) as $query) {
    if ($query->published || $query->user_id == $user->uid) {
      $options[] = array(
        'name' => $query->name,
        'description' => $query->description,
        'actions' => array(
          'data' => array(
            array(
              '#type' => 'link',
              '#title' => t('Run'),
              '#href' => 'mica/dataset/' . $dataset_node->nid . '/query/' . $query->id . '/run',
            ),
            array(
              '#type' => 'link',
              '#title' => t('Edit'),
              '#href' => 'mica/dataset/' . $dataset_node->nid . '/query/' . $query->id . '/edit',
              '#attributes' => array('style' => array('margin-left: 10px;')),
            ),
            array(
              '#type' => 'link',
              '#title' => t('Delete'),
              '#href' => 'mica/dataset/' . $dataset_node->nid . '/query/' . $query->id . '/delete',
              '#attributes' => array('style' => array('margin-left: 10px;')),
            ),
        )),
      );
    } 
  }

  $form['table'] = array (
    '#type' => 'tableselect',
    '#header' => $header,
    '#options' => $options,
    '#empty' => t('No query found'),
  );

  if (!empty($options)) {
    $form['delete'] = array(
      '#type' => 'submit',
      '#value' => t('Delete selected items'),
    );
  }

  return $form;
}

//
// Query form
//

function mica_datasets_dataset_query_form($form, &$form_state) {
  $dataset_node = $form_state['build_info']['args'][0];
  $query_id = $form_state['build_info']['args'][1];
  
  $form = array(
  	'#attached' => array('css' => array(drupal_get_path('module', 'mica_datasets') . '/includes/connection.css'),),
  );

  $form['general']['name'] = array(
    '#type' => 'textfield',
    '#title' => t('Name'), 
    '#default_value' => '',
    '#size' => 60,
    '#maxlength' => 128, 
    '#required' => TRUE,
  );

  $form['general']['description'] = array(
    '#type' => 'textarea', 
    '#title' => t('Description'), 
    '#default_value' => '', 
    '#rows' => 3,
    '#required' => FALSE,
  );

  $form['general']['publish'] = array(
    '#type' => 'checkbox', 
    '#title' => t('Publish'),
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

  //  $data = array(
  //  1 => array(
  //      'id' => 1,
  //      'title' => 'VAR1 is not null',
  //      'vid' => 0,
  //      'weight' => 1,
  //      'depth' => 1,
  //  ),
  //  2 => array(
  //      'id' => 2,
  //      'title' => 'VAR2 in (\'C1\', \'C2\')',
  //      'vid' => 0,
  //      'weight' => 2,
  //      'depth' => 1,
  //  ),
  //  3 => array(
  //      'id' => 3,
  //      'title' => 'VAR3 > 10',
  //      'vid' => 0,
  //      'weight' => 3,
  //      'depth' => 1,
  //  ),
  //  );
  $data = array();
  if (array_key_exists('values', $form_state)) {
    debug($form_state['values']);
    if (array_key_exists('list', $form_state['values'])) {
      foreach($form_state['values']['list'] as $datum) {
        $data[] = array(
          'id' => $datum['id'],
          'title' => $datum['id'] == 0 ? $datum['expression'] : 'todo',
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

  $form['list']['#tree'] = TRUE;
  $form['list']['#theme'] = 'mica_datasets_dataset_query_form';
  foreach ($data as $key => $datum) {
    $form['list'][$key]['title'] = array(
      '#markup' => $datum['title'],
    );
    if ($datum['id'] != 0) {
      $form['list'][$key]['actions']['edit'] = array(
        '#type' => 'link', 
        '#title' => t('edit'), 
        '#href' => 'mica/query-term/' . $datum['id'] . '/edit',
        '#attributes' => array(
          'style' => array('margin-right:10px;'),
      ),
      );
      $form['list'][$key]['actions']['delete'] = array(
        '#type' => 'link', 
        '#title' => t('delete'), 
        '#href' => 'mica/query-term/' . $datum['id'] . '/delete',
      );
    } else {
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

  //debug($form);

  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save'),
  );
  return $form;
}

function theme_mica_datasets_dataset_query_form($variables) {
  $form = $variables['form'];
  drupal_add_tabledrag('draggabledemo-sort', 'order', 'sibling', 'sort');
  $header = array('Query Term', '',t('Weight'));

  $rows = array();
  foreach (element_children($form['list']) as $key) {
    // Add class to group weight fields for drag and drop.
    $form['list'][$key]['weight']['#attributes'] = array(
      'class' => array('sort'),
    );

    $row = array();

    $row[] = drupal_render($form['list'][$key]['title']);
    if (array_key_exists('actions', $form['list'][$key])) {
      $row[] = drupal_render($form['list'][$key]['actions']['edit']) . drupal_render($form['list'][$key]['actions']['delete']);
    }
    else {
      $row[] = drupal_render($form['list'][$key]['expression']);
    }
    $row[] = drupal_render($form['list'][$key]['weight']) . drupal_render($form['list'][$key]['id']) . drupal_render($form['list'][$key]['vid']);
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

function mica_datasets_dataset_query_form_validate($form, &$form_state) {
  //debug($form_state);
}

function mica_datasets_dataset_query_form_submit($form, &$form_state) {

  switch ($form_state['triggering_element']['#parents'][0]) {
    case 'add-variable':
      $vid = $form_state['values']['variables'];
      $form_state['values']['added-term'] = array(
        'vid' => $vid,
        'title' => $form['add-term']['variables']['#options'][$vid],
      );
      drupal_set_message(t('Query term temporarily added.'), 'warning');
      //debug($form_state['values']);
      break;
    case 'submit':
      debug($form_state['values']);
      $dataset_node = $form_state['build_info']['args'][0];
      $query_id = $form_state['build_info']['args'][1];
      
      if ($query_id == 0) {
        global $user;
        $values = array();
        $values['name'] = $form_state['values']['name'];
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
            foreach ($form_state['values']['list'] as $datum) {
              if ($datum['id'] == 0) {
                // new query term
                $values = array();
                $values['query_id'] = $rval;
                $values['variable_id'] = $datum['vid'];
                $values['weight'] = $datum['weight'];
                $values['module'] = 'mica_datasets';
                $values['options'] = array(
                  'type' => 'expression',
                  'value' => $datum['expression'],
                );
                
                mica_dataset_query_term_insert($values);
              }
            }
          }
        }
      }
      else {
        // todo
      }
      
      drupal_set_message(t('Your configuration has been saved.'));
      break;
  }

  //debug($form_state);


  $form_state['rebuild'] = TRUE;
}

//
// Edit/Add Query form
//



//
// Run query
//

function mica_datasets_dataset_query_run_page($node, $query_id) {
  $query = mica_dataset_query_load($query_id);
  drupal_set_title(t('!title -- Run !query', array('!title' => $node->title, '!query' => $query->name)));

  return _doQuery($node, $query);
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
