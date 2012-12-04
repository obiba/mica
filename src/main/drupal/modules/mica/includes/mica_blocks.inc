<?php
/**
 * @file
 * Mica blocks.
 */

//
// Site vs. Studies search block
//

/**
 * Site or Studies search block content function.
 */
function mica_search_block_content() {
  return drupal_get_form('mica_search_form');
}

/**
 * Returns a form for site or studies full text search.
 */
function mica_search_form(&$form, &$form_state) {

  // get studies view default display title
  $title = views_get_view('studies')->display['default']->display_options['title'];

  $form['search'] = array(
    '#type' => 'textfield',
    '#attributes' => array(
      'title' => t('Enter the terms you wish to search for in Site or !title.', array('!title' => t($title))),
    ),
    '#prefix' => '<div class="container-inline">',
  );

  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Go'),
    '#suffix' => '</div>',
  );

  $form['target'] = array(
    '#type' => 'radios',
    '#default_value' => 'site',
    '#options' => array('site' => t('Site'), 'studies' => t($title)),
  );

  // get studies_search view default display title
  $title = views_get_view('studies_search')->display['default']->display_options['title'];

  $form['link'] = array(
    '#type' => 'link',
    '#title' => check_plain(t('Advanced !title', array('!title' => t($title)))),
    '#href' => 'studies-search',
    '#prefix' => '<div class="advanced">',
    '#suffix' => '</div>',
  );

  return $form;
}

function mica_search_form_submit($form, &$form_state) {
  if ($form_state['values']['target'] == 'studies') {
    drupal_goto('studies-search', array(
      'query' => array(
        'search_api_views_fulltext' => $form_state['values']['search']
      )
    ));
  }
  else {
    drupal_goto('search/node/' . $form_state['values']['search']);
  }
}

//
// Search API search block
//

/**
 * Search API block content function.
 */
function mica_search_api_block_content($search_api_view, $help = '') {
  // todo check studies index is enabled
  return drupal_get_form('mica_search_api_form', $search_api_view, $help);
}

/**
 * Returns a form for search api full text search.
 */
function mica_search_api_form($form, &$form_state) {
  $form['search'] = array(
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

  $form['link'] = array(
    '#type' => 'link',
    '#title' => t('Advanced search'),
    '#href' => $form_state['build_info']['args'][0],
    '#prefix' => '<div class="advanced">',
    '#suffix' => '</div>',
  );

  return $form;
}

function mica_search_api_form_submit($form, &$form_state) {
  drupal_goto($form_state['build_info']['args'][0], array(
      'query' => array('search_api_views_fulltext' => $form_state['values']['search'])
    )
  );
}

//
// Search filters block
//

/**
 * Search filters block content function.
 */
function mica_search_filters_block_content() {

  global $user;
  $rids = array_keys($user->roles);
  $result = db_query("SELECT DISTINCT b.* FROM {block} b LEFT JOIN {block_role} r ON b.module = r.module AND b.delta = r.delta " .
      "WHERE b.status = 1 AND b.custom <> 0 AND (r.rid IN (:rids) OR r.rid IS NULL) ORDER BY b.weight, b.module",
    array(':rids' => $rids));

  $blocks = array();
  foreach ($result as $block) {
    // only configure blocks from facetapi related modules
    if (strpos($block->module, 'facetapi') !== FALSE) {

      $data = module_invoke($block->module, 'block_info');
      if (!empty($block->delta) && !empty($data)
        && array_key_exists($block->delta, $data) && $data[$block->delta]['info']) {

        $blocks[$block->module][$block->module . ':' . $block->delta] = array(
          '#type' => 'checkbox',
          '#title' => $block->title,
          '#default_value' => isset($user->data['block'][$block->module][$block->delta])
            ? $user->data['block'][$block->module][$block->delta]
            : ($block->custom == 1),
        );
      }
    }
  }

  if ($blocks) {
    return drupal_get_form('mica_search_filters_form', $blocks);
  }
  return NULL; // nothing to be shown
}

/**
 * Returns a form for toggling facet visibility.
 */
function mica_search_filters_form($form, &$form_state, $blocks) {

  $form = array(
    '#attached' => array(
      'js' => array(drupal_get_path('module', 'mica') . '/includes/search-filters.js'),
    ),
  );

  $form['search_filter'] = array(
    '#type' => 'textfield',
    '#attributes' => array('placeholder' => t('Click here to select filters')),
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

  $title = views_get_view('fields_description_search')->display['default']->display_options['title'];

  $form['link'] = array(
    '#type' => 'link',
    '#title' => check_plain(t('More about !title', array('!title' => t($title)))),
    '#href' => 'fields-description-search',
    '#prefix' => '<div class="advanced">',
    '#suffix' => '</div>',
  );

  return $form;
}

/**
 * Persist the user preferences about facet visibility.
 */
function mica_search_filters_form_submit($form, &$form_state) {
  global $user;

  foreach ($form_state['values'] as $key => $value) {
    $pos = strpos($key, ':');
    if ($pos !== FALSE) {
      // split key as module:delta
      $user->data['block'][drupal_substr($key, 0, $pos)][drupal_substr($key, $pos + 1)] = $value;
    }
  }

  db_update('users')
    ->fields(array('data' => serialize($user->data)))
    ->condition('uid', $user->uid)
    ->execute();
}
