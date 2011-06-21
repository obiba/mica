<?php
/**
 * @file
 * mica_data_access.features.menu_links.inc
 */

/**
 * Implementation of hook_menu_default_menu_links().
 */
function mica_data_access_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: main-menu:data-access-committee
  $menu_links['main-menu:data-access-committee'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'data-access-committee',
    'router_path' => 'data-access-committee',
    'link_title' => 'Data Access Committee',
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
    'weight' => '-50',
    'parent_path' => 'node/71',
  );
  // Exported menu link: main-menu:data-access-requests
  $menu_links['main-menu:data-access-requests'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'data-access-requests',
    'router_path' => 'data-access-requests',
    'link_title' => 'DACO Approved Projects',
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
    'weight' => '-50',
    'parent_path' => 'node/72',
  );
  // Exported menu link: main-menu:data-access-requests-admin
  $menu_links['main-menu:data-access-requests-admin'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'data-access-requests-admin',
    'router_path' => 'data-access-requests-admin',
    'link_title' => 'Data Access Administration',
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
    'weight' => '-49',
    'parent_path' => 'node/71',
  );
  // Exported menu link: main-menu:node/71
  $menu_links['main-menu:node/71'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/71',
    'router_path' => 'node/%',
    'link_title' => 'Data Access',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '1',
    'expanded' => '1',
    'weight' => '0',
  );
  // Exported menu link: main-menu:node/72
  $menu_links['main-menu:node/72'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/72',
    'router_path' => 'node/%',
    'link_title' => 'Research',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '1',
    'expanded' => '1',
    'weight' => '0',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('DACO Approved Projects');
  t('Data Access');
  t('Data Access Administration');
  t('Data Access Committee');
  t('Research');


  return $menu_links;
}
