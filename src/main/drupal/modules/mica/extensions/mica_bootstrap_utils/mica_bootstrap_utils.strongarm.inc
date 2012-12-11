<?php
/**
 * @file
 * mica_bootstrap_utils2.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function mica_bootstrap_utils_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'theme_mica_bootstrap_settings';
  $strongarm->value = array(
    'toggle_logo' => 1,
    'toggle_name' => 0,
    'toggle_slogan' => 0,
    'toggle_node_user_picture' => 0,
    'toggle_comment_user_picture' => 0,
    'toggle_comment_user_verification' => 0,
    'toggle_favicon' => 1,
    'toggle_main_menu' => 0,
    'toggle_secondary_menu' => 0,
    'default_logo' => 1,
    'logo_path' => '',
    'logo_upload' => '',
    'default_favicon' => 1,
    'favicon_path' => '',
    'favicon_upload' => '',
    'bootstrap_rebuild_registry' => 0,
    'cdn_bootstrap' => 0,
    'cdn_jquery' => 0,
    'collapsiblock_block' => 'section.block',
    'collapsiblock_title' => ':header:first',
    'collapsiblock_content' => 'div.block-content',
  );
  $export['theme_mica_bootstrap_settings'] = $strongarm;

  return $export;
}
