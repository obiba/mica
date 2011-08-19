<?php
/**
 * @file
 * mica_community.features.menu_custom.inc
 */

/**
 * Implementation of hook_menu_default_menu_custom().
 */
function mica_community_menu_default_menu_custom() {
  $menus = array();

  // Exported menu: navigation
  $menus['navigation'] = array(
    'menu_name' => 'navigation',
    'title' => 'Navigation',
    'description' => 'The <em>Navigation</em> menu contains links intended for site visitors. Links are added to the <em>Navigation</em> menu automatically by some modules.',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Navigation');
  t('The <em>Navigation</em> menu contains links intended for site visitors. Links are added to the <em>Navigation</em> menu automatically by some modules.');


  return $menus;
}
