<?php
/**
 * @file
 * mica_datasets.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function mica_datasets_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: main-menu:<firstchild>
  $menu_links['main-menu:<firstchild>'] = array(
    'menu_name' => 'main-menu',
    'link_path' => '<firstchild>',
    'router_path' => '<firstchild>',
    'link_title' => 'Datasets / Data Dictionary',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
      'unaltered_hidden' => '0',
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '1',
    'expanded' => '1',
    'weight' => '-50',
    'parent_path' => 'node/3',
  );
  // Exported menu link: main-menu:single-study-datasets
  $menu_links['main-menu:single-study-datasets'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'single-study-datasets',
    'router_path' => 'single-study-datasets',
    'link_title' => 'Single Study',
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
    'weight' => '-52',
    'parent_path' => '<firstchild>',
  );
  // Exported menu link: main-menu:multiple-study-datasets
  $menu_links['main-menu:multiple-study-datasets'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'multiple-study-datasets',
    'router_path' => 'multiple-study-datasets',
    'link_title' => 'Multiple-study Datasets',
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
    'weight' => '-50',
    'parent_path' => '<firstchild>',
  );
  // Exported menu link: main-menu:variable-search
  $menu_links['main-menu:variable-search'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'variable-search',
    'router_path' => 'variable-search',
    'link_title' => 'Variables Search',
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
    'weight' => '-51',
    'parent_path' => '<firstchild>',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Datasets / Data Dictionary');
  t('Multiple-study Datasets');
  t('Single-study Datasets');
  t('Variables Search');


  return $menu_links;
}
