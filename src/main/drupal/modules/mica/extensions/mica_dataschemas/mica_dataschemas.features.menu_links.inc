<?php
/**
 * @file
 * mica_dataschemas.features.menu_links.inc
 */

/**
 * Implementation of hook_menu_default_menu_links().
 */
function mica_dataschemas_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: main-menu:dataschema-variables
  $menu_links['main-menu:dataschema-variables'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'dataschema-variables',
    'router_path' => 'dataschema-variables',
    'link_title' => 'Variables Library',
    'options' => array(),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-49',
    'parent_path' => 'node/3',
  );
  // Exported menu link: main-menu:dataschemas
  $menu_links['main-menu:dataschemas'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'dataschemas',
    'router_path' => 'dataschemas',
    'link_title' => 'DataSchemas',
    'options' => array(),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-50',
    'parent_path' => 'node/3',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('DataSchemas');
  t('Variables Library');


  return $menu_links;
}
