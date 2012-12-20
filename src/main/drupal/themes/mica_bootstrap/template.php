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
 * Implements hook_js_alter().
 * Replace bootstrap lib path
 */
function mica_bootstrap_js_alter(&$js) {
  $bootstrap_theme = drupal_get_path('theme', 'bootstrap');
  $js[$bootstrap_theme . '/bootstrap/js/bootstrap.js']['data'] = drupal_get_path('theme', 'mica_bootstrap') . '/bootstrap/js/bootstrap.min.js';
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