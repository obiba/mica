<?php
// $Id:

/**
 * Override or insert variables into the html template.
 */
function mica_samara_preprocess_html(&$vars) {

  // Add font and layout styles
  $css['font'] = 'html {font-size: ' . theme_get_setting('base_font_size') . ';}';
  $css['no-sidebars'] = '
  body.no-sidebars #navigation, body.no-sidebars #header, body.no-sidebars #main-columns, body.no-sidebars #footer {
    width: '     . theme_get_setting('layout_3_width')     . ';
    min-width: ' . theme_get_setting('layout_3_min_width') . ';
    max-width: ' . theme_get_setting('layout_3_max_width') . ';
  }';
  $css['one-sidebar'] = '
  body.one-sidebar #navigation, body.one-sidebar #header, body.one-sidebar #main-columns, body.one-sidebar #footer {
    width: '     . theme_get_setting('layout_3_width')     . ';
    min-width: ' . theme_get_setting('layout_3_min_width') . ';
    max-width: ' . theme_get_setting('layout_3_max_width') . ';
  }';
  $css['two-sidebars'] = '
  body.two-sidebars #navigation, body.two-sidebars #header, body.two-sidebars #main-columns, body.two-sidebars #footer {
    width: '     . theme_get_setting('layout_3_width')     . ';
    min-width: ' . theme_get_setting('layout_3_min_width') . ';
    max-width: ' . theme_get_setting('layout_3_max_width') . ';
  }';
  drupal_add_css(implode($css), array('type' => 'inline', 'group' => CSS_THEME));

  // Add color scheme CSS
  drupal_add_css(path_to_theme() . '/styles/sch-' . theme_get_setting('color_scheme') . '.css', array('group' => CSS_THEME));

  // Add conditional CSS for IE
  drupal_add_css(path_to_theme() . '/styles/ie8.css.css', array('group' => CSS_THEME, 'browsers' => array('IE' => 'lte IE 8', '!IE' => FALSE), 'preprocess' => FALSE));
  drupal_add_css(path_to_theme() . '/styles/ie7.css.css', array('group' => CSS_THEME, 'browsers' => array('IE' => 'lte IE 7', '!IE' => FALSE), 'preprocess' => FALSE));
  drupal_add_css(path_to_theme() . '/styles/ie6.css.css', array('group' => CSS_THEME, 'browsers' => array('IE' => 'lte IE 6', '!IE' => FALSE), 'preprocess' => FALSE));
}


/**
 * Override or insert variables into the page template.
 */
function mica_samara_preprocess_page(&$vars) {

  $sidebar_first_weight  = theme_get_setting('sidebar_first_weight');
  $sidebar_second_weight = theme_get_setting('sidebar_second_weight');

  $vars['left_sidebars'] = '';
  if($sidebar_first_weight == -2) {
    $vars['left_sidebars'] .= render($vars['page']['sidebar_first']);
  }
  if($sidebar_second_weight == -2) {
    $vars['left_sidebars'] .= render($vars['page']['sidebar_second']);
  }
  if($sidebar_first_weight == -1) {
    $vars['left_sidebars'] .= render($vars['page']['sidebar_first']);
  }
  if($sidebar_second_weight == -1) {
    $vars['left_sidebars'] .= render($vars['page']['sidebar_second']);
  }
  
  $vars['right_sidebars'] = '';
  if($sidebar_first_weight == 1) {
    $vars['right_sidebars'] .= render($vars['page']['sidebar_first']);
  }
  if($sidebar_second_weight == 1) {
    $vars['right_sidebars'] .= render($vars['page']['sidebar_second']);
  }
  if($sidebar_first_weight == 2) {
    $vars['right_sidebars'] .= render($vars['page']['sidebar_first']);
  }
  if($sidebar_second_weight == 2) {
    $vars['right_sidebars'] .= render($vars['page']['sidebar_second']);
  }

  // Add $navigation variable, unlike built-in $main_menu variable it supports drop-down menus
  $vars['navigation'] = $vars['main_menu'] ? render(menu_tree('main-menu')) : FALSE;

  // Add $copyright_information variable
  $vars['copyright_information'] = theme_get_setting('copyright_information');

}


/**
 * Override or insert variables into the region template.
 */
function mica_samara_preprocess_region(&$vars) {

  // Remove default classes from sidebars regions
  if($vars['region'] == 'sidebar_first') {
    $vars['classes_array'] = array('clearfix');
  }
  if( $vars['region'] == 'sidebar_second') {
    $vars['classes_array'] = array('clearfix');
  }
}


/**
 * Override or insert variables into the block template.
 */
function mica_samara_preprocess_block(&$vars) {

  // Remove default classes from some regions
  if(in_array($vars['block']->region, array('content', 'content_top', 'content_bottom', 'highlight'))) {
    $vars['classes_array'] = array();
  }

}


/**
 * Overrides theme_tablesort_indicator().
 */
function mica_samara_tablesort_indicator($vars) {
  $attributes = array(
    'alt' => t('sort icon'),
  );
  if ($vars['style'] == 'asc') {
    $attributes['path']  = path_to_theme() . '/images/tablesort-ascending.png';
    $attributes['title'] = t('sort ascending');
  }
  else {
    $attributes['path']  = path_to_theme() . '/images/tablesort-descending.png';
    $attributes['title'] = t('sort descending');
  }
  return theme('image', $attributes);
}
