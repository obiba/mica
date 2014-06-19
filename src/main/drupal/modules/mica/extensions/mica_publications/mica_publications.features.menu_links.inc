<?php
/**
 * @file
 * mica_publications.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function mica_publications_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: main-menu_publication-search:publication-search
  $menu_links['main-menu_publication-search:publication-search'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'publication-search',
    'router_path' => 'publication-search',
    'link_title' => 'Publication Search',
    'options' => array(
      'identifier' => 'main-menu_publication-search:publication-search',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -50,
    'customized' => 1,
    'parent_identifier' => 'main-menu_research:node/3',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Publication Search');

  return $menu_links;
}
