<?php
/**
 * @file
 * mica_projects.features.menu_links.inc
 */

/**
 * Implementation of hook_menu_default_menu_links().
 */
function mica_projects_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: main-menu:projects
  $menu_links['main-menu:projects'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'projects',
    'router_path' => 'projects',
    'link_title' => 'Projects',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
    ),
    'module' => 'system',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '1',
    'expanded' => '1',
    'weight' => '0',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Projects');


  return $menu_links;
}
