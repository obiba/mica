<?php
// $Id$

/**
 * @file
 * Mica blocks. 
 */

/**
 * Studies search block content function.
 */
function mica_search_api_block_content($search_api_view, $help = '') {
  // todo check studies index is enabled
  return drupal_get_form('mica_search_api_form', $search_api_view, $help);
}

/**
 * Returns a form for studies full text search.
 */
function mica_search_api_form($form, &$form_state) {
  $form = array(
    '#attached' => array(
      'css' => array(drupal_get_path('module', 'mica') . '/includes/blocks.css'),
    ),
  );  

  $form['search']  = array(
    '#type' => 'textfield',
    '#attributes' => array(
      'title' => $form_state['build_info']['args'][1],
    ),
    '#prefix' => '<table><tr><td>',
    '#suffix' => '</td>',
  );
  
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Go'),
    '#prefix' => '<td>',
    '#suffix' => '</td></tr></table>',
  );

  $form['link']  = array(
    '#type' => 'link',
    '#title' => t('Advanced search'),
    '#href' => $form_state['build_info']['args'][0],
    '#prefix' => '<div class="advanced">',
    '#suffix' => '</div>',
  );
  
  return $form;
}

function mica_search_api_form_submit($form, &$form_state) {
  drupal_goto($form_state['build_info']['args'][0] , array('query' => array('search_api_views_fulltext' => $form_state['values']['search'])));
}

/**
 * Search filters block content function.
 */
function mica_search_filters_block_content() {
  
  global $user;
  $rids = array_keys($user->roles);
  $result = db_query("SELECT DISTINCT b.* FROM {block} b LEFT JOIN {block_role} r ON b.module = r.module AND b.delta = r.delta WHERE b.status = 1 AND b.custom <> 0 AND (r.rid IN (:rids) OR r.rid IS NULL) ORDER BY b.weight, b.module", array(':rids' => $rids));
        
  $blocks = array();
  foreach ($result as $block)  {   
    // only configure blocks from search_api related modules
    if (strpos($block->module,'search_api_') !== FALSE) {
      
      $data = module_invoke($block->module, 'block_info');
      if (array_key_exists($block->delta, $data) && $data[$block->delta]['info']) {
        $blocks[$block->module][$block->module . ':' . $block->delta] = array(
          '#type' => 'checkbox',
          '#title' => check_plain($data[$block->delta]['info']),
          '#default_value' => isset($user->data['block'][$block->module][$block->delta]) ? $user->data['block'][$block->module][$block->delta] : ($block->custom == 1),
        );
      }
    }
  }
  
  if ($blocks) {
    return drupal_get_form('mica_search_filters_form',$blocks);
  }
  else {
    // nothing to be shown
    return;
  }
}

/**
 * Returns a form for toggling facet visibility.
 */
function mica_search_filters_form($form, &$form_state, $blocks) {
  
  $form = array(
    '#attached' => array(
      'css' => array(drupal_get_path('module', 'mica') . '/includes/blocks.css'),
      'js' => array(drupal_get_path('module', 'mica') . '/includes/search-filters.js'),
    ),
  );

  $form['search_filter']  = array(
    '#type' => 'textfield',
     '#attributes' => array ('placeholder' => t('Click here to select filters')),
     '#prefix' => '<table><tr><td>',
    '#suffix' => '</td>',
  );

  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Apply'),
    '#prefix' => '<td>',
    '#suffix' => '</td></tr></table>',
  );
  
  $form['block'] = array(
    '#type' => 'fieldset',
  );
  
  $form['block'] += $blocks;

  return $form;
}

/**
 * Persist the user preferences about facet visibility.
 */
function mica_search_filters_form_submit($form, &$form_state) {
  global $user;

  foreach ($form_state['values'] as $key => $value) {
    $pos = strpos($key,':');
    if ($pos !== FALSE) {
      // split key as module:delta
      $user->data['block'][drupal_substr($key,0,$pos)][drupal_substr($key,$pos+1)] = $value;
    }
  }
  
  db_update('users')
    ->fields(array('data' => serialize($user->data)))
    ->condition('uid', $user->uid)
    ->execute();
}


?>
