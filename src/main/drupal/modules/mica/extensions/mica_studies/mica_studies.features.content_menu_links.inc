<?php
/**
 * @file
 * mica_studies.features.content_menu_links.inc
 */

/**
 * Implements hook_content_menu_links_defaults().
 */
function mica_studies_content_menu_links_defaults() {
  $menu_links = array();

  // Exported menu link: main-menu:<front>
  $menu_links['main-menu:<front>'] = array(
    'menu_name' => 'main-menu',
    'link_path' => '<front>',
    'router_path' => '',
    'link_title' => 'Home',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'langcode' => 'en',
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '1',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-50',
  );
  // Exported menu link: main-menu:datasets
  $menu_links['main-menu:datasets'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'datasets',
    'router_path' => 'datasets',
    'link_title' => 'Datasets',
    'options' => array(),
    'module' => 'system',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-50',
    'parent_path' => 'node/2',
  );
  // Exported menu link: main-menu:documents
  $menu_links['main-menu:documents'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'documents',
    'router_path' => 'documents',
    'link_title' => 'Documents',
    'options' => array(),
    'module' => 'system',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-49',
    'parent_path' => 'node/2',
  );
  // Exported menu link: main-menu:node/4
  $menu_links['main-menu:node/4'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node-name/about',
    'router_path' => 'node/%',
    'link_title' => 'About',
    'options' => array(
      'langcode' => 'en',
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '1',
    'weight' => '-44',
  );
  // Exported menu link: main-menu:node/2
  $menu_links['main-menu:node/1'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node-name/research',
    'router_path' => 'node/%',
    'link_title' => 'Research',
    'options' => array(
      'attributes' => array(),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '1',
    'expanded' => '1',
    'weight' => '-46',
  );
  // Exported menu link: main-menu:node/1
  $menu_links['main-menu:node/2'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node-name/resources',
    'router_path' => 'node/%',
    'link_title' => 'Resources',
    'options' => array(
      'attributes' => array(),
      'langcode' => 'en',
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '1',
    'expanded' => '1',
    'weight' => '-48',
  );
  // Exported menu link: main-menu:projects
  $menu_links['main-menu:projects'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'projects',
    'router_path' => 'projects',
    'link_title' => 'Projects',
    'options' => array(),
    'module' => 'system',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '1',
    'expanded' => '0',
    'weight' => '0',
    'parent_path' => 'node/1',
  );
  // Exported menu link: main-menu:publications
  $menu_links['main-menu:publications'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'publications',
    'router_path' => 'publications',
    'link_title' => 'Publications',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'langcode' => 'en',
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '1',
    'parent_path' => 'node/1',
  );
  // Exported menu link: main-menu:studies
  $menu_links['main-menu:studies'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'studies',
    'router_path' => 'studies',
    'link_title' => 'Studies',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
    ),
    'module' => 'system',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-49',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('About');
  t('Datasets');
  t('Documents');
  t('Home');
  t('Projects');
  t('Publications');
  t('Research');
  t('Resources');
  t('Studies');


  return $menu_links;
}
