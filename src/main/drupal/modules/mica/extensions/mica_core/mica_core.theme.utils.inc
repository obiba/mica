<?php


function mica_core_get_current_theme() {
  global $custom_theme, $theme, $user;

  if (!empty($user->theme)) {
    return $user->theme;
  }
  if (!empty($custom_theme)) {
    return $custom_theme;
  }
  return $theme ? $theme : variable_get('theme_default', 'mica_bootstrap');
}

function mica_core_is_bootstrap_based_theme() {
  $themes = module_invoke_all('bootstrap_based_theme');
  debug($themes, '$themes');

  $theme = mica_core_get_current_theme();
  debug($theme, '$theme');
}