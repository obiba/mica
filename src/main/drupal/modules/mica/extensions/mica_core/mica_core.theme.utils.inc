<?php


function mica_core_get_current_theme() {
  global $custom_theme, $theme, $user;

  if (!empty($user->theme)) {
    return $user->theme;
  }
  if (!empty($custom_theme)) {
    return $custom_theme;
  }
  return $theme ? $theme : variable_get('theme_default', 'mica_subtheme');
}

/**
 * Check if current theme is based on Twitter Bootstrap
 */
function mica_core_is_bootstrap_based_theme() {
  // cannot use module_invoke_all() because hook are invoked only for modules
  $current_theme = mica_core_get_current_theme();
  $function = $current_theme . '_bootstrap_based_theme';
  if (function_exists($function)) {
    $result = call_user_func_array($function, array());
    return !empty($result) && is_array($result) && isset($result[$current_theme]) ? $result[$current_theme] : FALSE;
  }
  return FALSE;
}