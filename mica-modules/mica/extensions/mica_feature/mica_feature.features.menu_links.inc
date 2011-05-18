<?php
/**
 * @file
 * mica_feature.features.menu_links.inc
 */

/**
 * Implementation of hook_menu_default_menu_links().
 */
function mica_feature_menu_default_menu_links() {
  $menu_links = array();
  
  // Exported menu link: main-menu:<front>
  $menu_links['main-menu:<front>'] = array(
    'menu_name' => 'main-menu',
    'link_path' => '<front>',
    'router_path' => '',
    'link_title' => 'Home',
    'options' => array(),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '1',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '0',
  );  
  
  // Exported menu link: main-menu:studies
  $menu_links['main-menu:studies'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'studies',
    'router_path' => 'studies',
    'link_title' => 'Studies',
    'options' => array(),
    'module' => 'system',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '1',
    'expanded' => '0',
    'weight' => '1',
  );  

  // Exported menu link: main-menu:<firstchild>
  $menu_links['main-menu:<firstchild>'] = array(
    'menu_name' => 'main-menu',
    'link_path' => '<firstchild>',
    'router_path' => '<firstchild>',
    'link_title' => 'Search',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
      'unaltered_hidden' => 0,
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '1',
    'expanded' => '1',
    'weight' => '2',
  );
  
  // Exported menu link: main-menu:studies-search
  $menu_links['main-menu:studies-search'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'studies-search',
    'router_path' => 'studies-search',
    'link_title' => 'Studies Search',
    'options' => array(),
    'module' => 'system',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '0',
    'parent_path' => '<firstchild>',
  );  

  // Exported menu link: main-menu:fields-description-search
  $menu_links['main-menu:fields-description-search'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'fields-description-search',
    'router_path' => 'fields-description-search',
    'link_title' => 'Fields Description Search',
    'options' => array(),
    'module' => 'system',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '1',
    'expanded' => '0',
    'weight' => '1',
    'parent_path' => '<firstchild>',
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Fields Description Search');
  t('Home');
  t('Search');
  t('Studies');
  t('Studies Search');

  return $menu_links;
}
