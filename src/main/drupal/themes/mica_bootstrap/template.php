<?php

/**
 * Implements hook_bootstrap_based_theme().
 */
function mica_bootstrap_bootstrap_based_theme() {
  return array('mica_bootstrap' => TRUE);
}

/**
 * Add drop down for user menu
 */
function mica_bootstrap_menu_tree__user_menu($variables) {
  return '<div id="user-menu" class="pull-right btn-group">'
  . '<a class="btn dropdown-toggle" data-toggle="dropdown" href="#"><i class="icon-user"></i> ' . t('User menu') . ' <span class="caret"></span></a>'
  . '<ul class="dropdown-menu">' . $variables['tree'] . '</ul></div>';
}

/**
 * Implements template_preprocess_views_view()
 *  Attach javascript to views
 */
function mica_bootstrap_preprocess_views_view(&$vars) {
  $view = $vars['view'];

  switch ($view->name) {
    case 'studies_search':
    case 'variable_search':
      drupal_add_js(drupal_get_path('theme', 'mica_bootstrap') . '/js/mica_bootstrap.fulltext-search.js');
      drupal_add_js(drupal_get_path('theme', 'mica_bootstrap') . '/js/mica_bootstrap.views-export.js');
      drupal_add_js(array('downloadLabel' => t('Download')), array('type' => 'setting'));
      break;

    case 'studies':
    case 'variables_dimensions':
      drupal_add_js(drupal_get_path('theme', 'mica_bootstrap') . '/js/mica_bootstrap.views-export.js');
      drupal_add_js(array('downloadLabel' => t('Download')), array('type' => 'setting'));
      break;
  }
}

/**
 * Implements template_preprocess_html()
 */
function mica_bootstrap_preprocess_html(&$variables) {
  // hide breadcrumb on home page
  if ($variables['is_front']) {
    drupal_set_breadcrumb(array());
  }
}