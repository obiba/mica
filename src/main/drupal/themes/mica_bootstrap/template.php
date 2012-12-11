<?php


/**
 * Implements hook_bootstrap_based_theme().
 */
function mica_bootstrap_bootstrap_based_theme() {
  return array('mica_bootstrap' => TRUE);
}

/**
 * Implements hook_css_alter().
 *
 * Replace bootstrap.css by mica_bootstrap.css and remove responsive css as it is compiled to mica_bootstrap.css
 * @param $css
 */
function mica_bootstrap_css_alter(&$css) {

  $bootstrap_theme = drupal_get_path('theme', 'bootstrap');
  $key = $bootstrap_theme . '/bootstrap/css/bootstrap.css';
  $file = $css[$key];
  $file['data'] = drupal_get_path('theme', 'mica_bootstrap') . '/less/mica_bootstrap.less';
  $file['weight'] = 1000; // set it as last imported css
  unset($css[$key]);
  $css[$file['data']] = $file;

  // remove responsive css as it is compiled to mica_bootstrap.css
  unset($css[$bootstrap_theme . '/bootstrap/css/bootstrap-responsive.css']);
}

function mica_bootstrap_menu_tree__user_menu($variables) {
  return '<div id="user-menu" class="pull-right btn-group">'
    . '<a class="btn btn-success dropdown-toggle" data-toggle="dropdown" href="#">' . t('User menu') . ' <span class="caret"></span></a>'
    . '<ul class="dropdown-menu">' . $variables['tree'] . '</ul></div>';
}

function mica_bootstrap_menu_tree__login($variables) {

  dvm($variables);

  return '<div id="user-menu" class="pull-right btn-group">'
    . '<a class="btn btn-success dropdown-toggle" data-toggle="dropdown" href="#">' . t('User menu') . ' <span class="caret"></span></a>'
    . '<ul class="dropdown-menu">' . $variables['tree'] . '</ul></div>';
}
