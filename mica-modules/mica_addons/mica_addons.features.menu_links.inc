<?php
/**
 * @file
 * mica_addons.features.menu_links.inc
 */

/**
 * Implementation of hook_menu_default_menu_links().
 */
function mica_addons_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: main-menu:events
  $menu_links['main-menu:events'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'events',
    'router_path' => 'events',
    'link_title' => 'Events',
    'options' => array(),
    'module' => 'system',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '1',
    'expanded' => '0',
    'weight' => '0',
  );
  // Exported menu link: main-menu:events_calendar
  $menu_links['main-menu:events_calendar'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'events_calendar',
    'router_path' => 'events_calendar',
    'link_title' => 'Events Calendar',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '0',
    'parent_path' => 'events',
  );
  // Exported menu link: navigation:blog
  $menu_links['navigation:blog'] = array(
    'menu_name' => 'navigation',
    'link_path' => 'blog',
    'router_path' => 'blog',
    'link_title' => 'Blogs',
    'options' => array(),
    'module' => 'system',
    'hidden' => '1',
    'external' => '0',
    'has_children' => '1',
    'expanded' => '0',
    'weight' => '0',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Blogs');
  t('Events');
  t('Events Calendar');


  return $menu_links;
}
