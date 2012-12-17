<?php


/**
 * Implements hook_bootstrap_based_theme().
 */
function mica_bootstrap_bootstrap_based_theme() {
  return array('mica_bootstrap' => TRUE);
}

/**
 * Implements hook_css_alter().
 * Replace bootstrap.css by mica_bootstrap.css
 */
function mica_bootstrap_css_alter(&$css) {

  $bootstrap_theme = drupal_get_path('theme', 'bootstrap');
  $key = $bootstrap_theme . '/bootstrap/css/bootstrap.css';
  $file = $css[$key];
  $file['data'] = drupal_get_path('theme', 'mica_bootstrap') . '/less/mica_bootstrap.less';
  $file['weight'] = 1000; // set it as last imported css
  unset($css[$key]);
  $css[$file['data']] = $file;

  $key = $bootstrap_theme . '/bootstrap/css/bootstrap-responsive.css';
  $file = $css[$key];
  $file['data'] = drupal_get_path('theme', 'mica_bootstrap') . '/less/mica_bootstrap_responsive.less';
  $file['weight'] = 1001; // set it after mica_bootstrap.css
  unset($css[$key]);
  $css[$file['data']] = $file;
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
 */
function mica_bootstrap_preprocess_views_view(&$vars) {
  $view = $vars['view'];
  if ($view->name === 'studies_search' || $view->name === 'variable_search') {
    // attach javascript to views
    drupal_add_js(drupal_get_path('theme', 'mica_bootstrap') . '/js/mica_bootstrap.fulltext-search.js');
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