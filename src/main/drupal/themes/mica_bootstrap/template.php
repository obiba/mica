<?php

/**
 * Implements hook_css_alter().
 *
 * Replace bootstrap.css by mica_bootstrap.css
 * @param $css
 */
function mica_bootstrap_css_alter(&$css) {
  $key = drupal_get_path('theme', 'bootstrap') . '/bootstrap/css/bootstrap.css';
  $file = $css[$key];
  $file['data'] = drupal_get_path('theme', 'mica_bootstrap') . '/css/mica_bootstrap.css';
  unset($css[$key]);
  $css[$file['data']] = $file;
}