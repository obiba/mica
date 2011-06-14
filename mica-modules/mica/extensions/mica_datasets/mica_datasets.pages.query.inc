<?php

/**
 * @file
 * Mica Datasets pages.
 */


/**
 * Display form for submitting queries.
 */
function mica_datasets_dataset_queries_page($node) {
  drupal_set_title(t('!title -- Query', array('!title' => $node->title)));
  
return  drupal_get_form('mica_datasets_dataset_query_form', $node);
  
}

function mica_datasets_dataset_query_form($form, &$form_state) {
  
 $data = array(
    1 => array(
      'id' => 1,
      'title' => 'VAR1 is not null',
      'pid' => 0,
      'weight' => 1,
      'depth' => 1,
    ),
    2 => array(
      'id' => 2,
      'title' => 'VAR2 in (\'C1\', \'C2\')',
      'pid' => 0,
      'weight' => 2,
      'depth' => 1,
    ),
    3 => array(
      'id' => 3,
      'title' => 'VAR3 > 10',
      'pid' => 0,
      'weight' => 3,
      'depth' => 1,
    ),
  );
  
  $form = array();
  
  $form['list']['#tree'] = TRUE;
  $form['list']['#theme'] = 'mica_datasets_dataset_query_form';
  foreach ($data as $key => $datum) {
    $form['list'][$key]['title'] = array( 
      '#markup' => $datum['title'],
    ); 
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
    $form['list'][$key]['weight'] = array(
      '#type' => 'weight', 
      '#delta' => count($data), 
      '#default_value' => $datum['weight'],
    );
    $form['list'][$key]['id'] = array(
      '#type' => 'hidden', 
      '#value' => $datum['id'],
    );
    $form['list'][$key]['pid'] = array(
      '#type' => 'hidden', 
      '#value' => $datum['pid'],
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
    $row[] = drupal_render($form['list'][$key]['actions']['edit']) . drupal_render($form['list'][$key]['actions']['delete']);
    $row[] = drupal_render($form['list'][$key]['weight']) . drupal_render($form['list'][$key]['id']) . drupal_render($form['list'][$key]['pid']);
    $rows[] = array('data' => $row, 'class' => array('draggable')); //note the difference between $row and $rows
  }
  
  $output = theme('table', array('header' => $header, 'rows' => $rows, 'attributes' => array('id' => 'draggabledemo-sort')));
  $output .= drupal_render_children($form,array('actions'));
  
  return $output;
}


function _doQuery($dataset_node) {
  $mica_dataset_connectors = mica_dataset_connector_query_multiple($dataset_node->nid);
  $variables = array();
  foreach(mica_dataset_dataset_participant_variables($dataset_node->nid) as $variable) {
    array_push($variables, $variable->title);
  }

  $columns = array_merge(array('Study', 'Total') , $variables);
  $h = "<table><thead><tr>";
  foreach($columns as $var) {
    $h .=  "<th>" . $var . "</th>"; 
  }
  $h .= "</tr></thread><tbody>";
  foreach($mica_dataset_connectors as $connector) {
    $result = $connector->query($variables);
    $study = node_load($connector->study_id);
    $h .= "<tr><td>" . $study->title . "</td><td>".$result['total']."</td>";
    foreach($variables as $var) {
      $h.="<td>" . $result[$var] . "</td>";
    }
    $h .=  "</tr>"; 
  }
  $h .= "</tbody></table>";

    return $h;
}
