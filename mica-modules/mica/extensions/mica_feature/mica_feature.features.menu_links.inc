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
    'expanded' => '1',
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
    'weight' => '3',
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
    'weight' => '4',
    'parent_path' => '<firstchild>',
  );
// Exported menu link: navigation:<firstchild>
  $menu_links['navigation:<firstchild>'] = array(
    'menu_name' => 'navigation',
    'link_path' => '<firstchild>',
    'router_path' => '<firstchild>',
    'link_title' => 'Export',
    'options' => array(
      'attributes' => array(
        'title' => 'Export content in CSV file',
      ),
      'alter' => TRUE,
      'unaltered_hidden' => '0',
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '1',
    'expanded' => '1',
    'weight' => '40',
  );
  // Exported menu link: navigation:csv-contact
  $menu_links['navigation:csv-contact'] = array(
    'menu_name' => 'navigation',
    'link_path' => 'csv-contact',
    'router_path' => 'csv-contact',
    'link_title' => 'Export Contacts',
    'options' => array(
      'attributes' => array(
        'title' => 'Export of all studies in CSV',
      ),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-46',
    'parent_path' => '<firstchild>',
  );
  // Exported menu link: navigation:csv-field-description
  $menu_links['navigation:csv-field-description'] = array(
    'menu_name' => 'navigation',
    'link_path' => 'csv-field-description',
    'router_path' => 'csv-field-description',
    'link_title' => 'Export Fields Description',
    'options' => array(
      'attributes' => array(
        'title' => 'Export of all studies in CSV',
      ),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-49',
    'parent_path' => '<firstchild>',
  );
  // Exported menu link: navigation:csv-institution
  $menu_links['navigation:csv-institution'] = array(
    'menu_name' => 'navigation',
    'link_path' => 'csv-institution',
    'router_path' => 'csv-institution',
    'link_title' => 'Export Institutions',
    'options' => array(
      'attributes' => array(
        'title' => 'Export of all studies in CSV',
      ),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '0',
    'parent_path' => '<firstchild>',
  );
  // Exported menu link: navigation:csv-study
  $menu_links['navigation:csv-study'] = array(
    'menu_name' => 'navigation',
    'link_path' => 'csv-study',
    'router_path' => 'csv-study',
    'link_title' => 'Export Studies',
    'options' => array(
      'attributes' => array(
        'title' => 'Export of all studies in CSV',
      ),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-50',
    'parent_path' => '<firstchild>',
  );
  // Exported menu link: navigation:csv-study-files
  $menu_links['navigation:csv-study-files'] = array(
    'menu_name' => 'navigation',
    'link_path' => 'csv-study-files',
    'router_path' => 'csv-study-files',
    'link_title' => 'Export Study Files',
    'options' => array(
      'attributes' => array(
        'title' => 'Export of all studies in CSV',
      ),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-47',
    'parent_path' => '<firstchild>',
  );
  // Exported menu link: navigation:csv-study-information
  $menu_links['navigation:csv-study-information'] = array(
    'menu_name' => 'navigation',
    'link_path' => 'csv-study-information',
    'router_path' => 'csv-study-information',
    'link_title' => 'Export Studies Information',
    'options' => array(
      'attributes' => array(
        'title' => 'Export of all studies in CSV',
      ),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-48',
    'parent_path' => '<firstchild>',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Export');
  t('Export Contacts');
  t('Export Fields Description');
  t('Export Institutions');
  t('Export Studies');
  t('Export Studies Information');
  t('Export Study Files');
  t('Fields Description Search');
  t('Home');
  t('Search');
  t('Studies');
  t('Studies Search');
  t('URL aliases');


  return $menu_links;
}
