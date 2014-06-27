<?php
/**
 * @file
 * mica_publications.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function mica_publications_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'publication_search';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'search_api_index_publications';
  $view->human_name = 'Publication Search';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Publication Search';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['row_class'] = 'publication row-fluid';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Indexed Node: Node ID */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'search_api_index_publications';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_wrapper_type'] = 'span';
  $handler->display->display_options['fields']['nid']['element_wrapper_class'] = 'span12';
  $handler->display->display_options['fields']['nid']['link_to_entity'] = 0;
  /* Field: Indexed Node: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'search_api_index_publications';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_entity'] = 1;
  /* Field: Indexed Node: Reference */
  $handler->display->display_options['fields']['field_publication_reference']['id'] = 'field_publication_reference';
  $handler->display->display_options['fields']['field_publication_reference']['table'] = 'search_api_index_publications';
  $handler->display->display_options['fields']['field_publication_reference']['field'] = 'field_publication_reference';
  /* Field: Indexed Node: PMID */
  $handler->display->display_options['fields']['field_publication_pmid']['id'] = 'field_publication_pmid';
  $handler->display->display_options['fields']['field_publication_pmid']['table'] = 'search_api_index_publications';
  $handler->display->display_options['fields']['field_publication_pmid']['field'] = 'field_publication_pmid';
  $handler->display->display_options['fields']['field_publication_pmid']['label'] = '';
  $handler->display->display_options['fields']['field_publication_pmid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_publication_pmid']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_publication_pmid']['element_wrapper_class'] = 'less-top-margin';
  $handler->display->display_options['fields']['field_publication_pmid']['type'] = 'mica_pubmed_url';
  $handler->display->display_options['fields']['field_publication_pmid']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 1,
  );
  /* Field: Indexed Node: Categories */
  $handler->display->display_options['fields']['field_category']['id'] = 'field_category';
  $handler->display->display_options['fields']['field_category']['table'] = 'search_api_index_publications';
  $handler->display->display_options['fields']['field_category']['field'] = 'field_category';
  $handler->display->display_options['fields']['field_category']['label'] = 'Tags :';
  $handler->display->display_options['fields']['field_category']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_category']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_category']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['field_category']['view_mode'] = 'full';
  $handler->display->display_options['fields']['field_category']['bypass_access'] = 0;
  /* Field: Indexed Node: Authors */
  $handler->display->display_options['fields']['field_authors']['id'] = 'field_authors';
  $handler->display->display_options['fields']['field_authors']['table'] = 'search_api_index_publications';
  $handler->display->display_options['fields']['field_authors']['field'] = 'field_authors';
  $handler->display->display_options['fields']['field_authors']['label'] = '';
  $handler->display->display_options['fields']['field_authors']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_authors']['element_wrapper_type'] = 'em';
  $handler->display->display_options['fields']['field_authors']['element_wrapper_class'] = 'pull-left';
  $handler->display->display_options['fields']['field_authors']['type'] = 'text_plain';
  $handler->display->display_options['fields']['field_authors']['delta_offset'] = '0';
  /* Field: Indexed Node: Date created */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'search_api_index_publications';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = '';
  $handler->display->display_options['fields']['created']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['created']['element_wrapper_type'] = 'em';
  $handler->display->display_options['fields']['created']['element_wrapper_class'] = 'pull-right';
  $handler->display->display_options['fields']['created']['date_format'] = 'short';
  $handler->display->display_options['fields']['created']['link_to_entity'] = 0;
  /* Sort criterion: Indexed Node: Date created */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'search_api_index_publications';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Indexed Node: Content type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'search_api_index_publications';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'publication' => 'publication',
  );
  /* Filter criterion: Indexed Node: Authors */
  $handler->display->display_options['filters']['field_authors']['id'] = 'field_authors';
  $handler->display->display_options['filters']['field_authors']['table'] = 'search_api_index_publications';
  $handler->display->display_options['filters']['field_authors']['field'] = 'field_authors';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'publication-search';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Publication Search';
  $handler->display->display_options['menu']['name'] = 'main-menu';
  $translatables['publication_search'] = array(
    t('Master'),
    t('Publication Search'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('« first'),
    t('‹ previous'),
    t('next ›'),
    t('last »'),
    t('Node ID'),
    t('.'),
    t(','),
    t('Reference'),
    t('Tags :'),
    t('Page'),
  );
  $export['publication_search'] = $view;

  return $export;
}
