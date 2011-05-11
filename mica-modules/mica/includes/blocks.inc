<?php
// $Id$

/**
 * @file
 * Mica blocks. 
 */

/**
 * Facet visibility block content function.
 */
function mica_facet_visibility_block_content() {
  global $user;
  $rids = array_keys($user->roles);
  $result = db_query("SELECT DISTINCT b.* FROM {block} b LEFT JOIN {block_role} r ON b.module = r.module AND b.delta = r.delta WHERE b.status = 1 AND b.custom <> 0 AND (r.rid IN (:rids) OR r.rid IS NULL) ORDER BY b.weight, b.module", array(':rids' => $rids));

  $blocks = array();
  foreach ($result as $block) {
    // only configure blocks from search_api related modules
    if (strpos($block->module,'search_api_') !== FALSE) {
      $data = module_invoke($block->module, 'block_info');
      if ($data[$block->delta]['info']) {
        $blocks[$block->module][$block->module . ':' . $block->delta] = array(
        '#type' => 'checkbox',
        '#title' => check_plain($data[$block->delta]['info']),
        '#default_value' => isset($user->data['block'][$block->module][$block->delta]) ? $user->data['block'][$block->module][$block->delta] : ($block->custom == 1),
        );
      }
    }
  }
  
  if ($blocks) {
    return drupal_get_form('mica_facet_visibility_form',$blocks);
  }
  else {
    // nothing to be shown
    return;
  }
}

/**
 * Returns a form for toggling facet visibility.
 */
function mica_facet_visibility_form($form, &$form_state, $blocks) {
  $form = array(
  		'#attached' => array(
        'css' => array(drupal_get_path('module', 'mica') . '/includes/facet-visibility.css'),
  ),
  );
  $form += $blocks;

  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save preferences'),
  );
  return $form;
}

/**
 * Persist the user preferences about facet visibility.
 */
function mica_facet_visibility_form_submit($form, &$form_state) {
  global $user;

  foreach ($form_state['values'] as $key => $value) {
    $pos = strpos($key,':');
    if ($pos !== FALSE) {
      // split key as module:delta
      $user->data['block'][substr($key,0,$pos)][substr($key,$pos+1)] = $value;
    }
  }
  
  db_update('users')
    ->fields(array('data' => serialize($user->data)))
    ->condition('uid', $user->uid)
    ->execute();
}


?>