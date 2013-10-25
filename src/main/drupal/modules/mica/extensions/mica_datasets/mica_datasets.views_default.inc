<?php
/**
 * @file
 * mica_datasets.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function mica_datasets_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'dataset_csv_export';
  $view->description = 'Export of all Dataset in CSV';
  $view->tag = 'csv, dataset';
  $view->base_table = 'node';
  $view->human_name = 'Dataset CSV Export';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title_field']['id'] = 'title_field';
  $handler->display->display_options['fields']['title_field']['table'] = 'field_data_title_field';
  $handler->display->display_options['fields']['title_field']['field'] = 'title_field';
  $handler->display->display_options['fields']['title_field']['label'] = 'title';
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = 'body';
  /* Field: Content: Published */
  $handler->display->display_options['fields']['status']['id'] = 'status';
  $handler->display->display_options['fields']['status']['table'] = 'node';
  $handler->display->display_options['fields']['status']['field'] = 'status';
  $handler->display->display_options['fields']['status']['label'] = 'published';
  $handler->display->display_options['fields']['status']['alter']['text'] = '[status]';
  $handler->display->display_options['fields']['status']['not'] = 0;
  /* Field: Content: Dataset Type */
  $handler->display->display_options['fields']['field_dataset_type']['id'] = 'field_dataset_type';
  $handler->display->display_options['fields']['field_dataset_type']['table'] = 'field_data_field_dataset_type';
  $handler->display->display_options['fields']['field_dataset_type']['field'] = 'field_dataset_type';
  $handler->display->display_options['fields']['field_dataset_type']['label'] = 'dataset_type';
  $handler->display->display_options['fields']['field_dataset_type']['type'] = 'list_key';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'dataset' => 'dataset',
  );

  /* Display: Export CSV */
  $handler = $view->new_display('views_data_export', 'Export CSV', 'views_data_export_1');
  $handler->display->display_options['display_description'] = 'Export datasets to CSV file';
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_data_export_csv';
  $handler->display->display_options['style_options']['provide_file'] = 1;
  $handler->display->display_options['style_options']['filename'] = '%view_%timestamp-yyyy-%timestamp-mm-%timestamp-dd.csv';
  $handler->display->display_options['style_options']['parent_sort'] = 0;
  $handler->display->display_options['style_options']['quote'] = 1;
  $handler->display->display_options['style_options']['trim'] = 0;
  $handler->display->display_options['style_options']['replace_newlines'] = 0;
  $handler->display->display_options['style_options']['header'] = 1;
  $handler->display->display_options['path'] = 'dataset-csv';

  /* Display: Export CSV (html) */
  $handler = $view->new_display('views_data_export', 'Export CSV (html)', 'views_data_export_2');
  $handler->display->display_options['display_description'] = 'Export datasets to CSV file (text is exported as html)';
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_data_export_csv';
  $handler->display->display_options['style_options']['provide_file'] = 1;
  $handler->display->display_options['style_options']['filename'] = '%view_%timestamp-yyyy-%timestamp-mm-%timestamp-dd.csv';
  $handler->display->display_options['style_options']['parent_sort'] = 0;
  $handler->display->display_options['style_options']['quote'] = 1;
  $handler->display->display_options['style_options']['trim'] = 0;
  $handler->display->display_options['style_options']['replace_newlines'] = 0;
  $handler->display->display_options['style_options']['header'] = 1;
  $handler->display->display_options['style_options']['keep_html'] = 1;
  $handler->display->display_options['path'] = 'dataset-csv-html';
  $export['dataset_csv_export'] = $view;

  $view = new view();
  $view->name = 'dataset_studies';
  $view->description = '';
  $view->tag = 'study, dataset';
  $view->base_table = 'node';
  $view->human_name = 'Dataset Studies';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Studies';
  $handler->display->display_options['css_class'] = 'table-striped';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
    'field_design_other_sp' => 'field_design_other_sp',
    'field_design' => 'field_design',
    'field_target_number_participants' => 'field_target_number_participants',
    'field_country' => 'field_country',
  );
  $handler->display->display_options['style_options']['default'] = 'title';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_design_other_sp' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_design' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_target_number_participants' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_country' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['label'] = 'empty_dataset_studies';
  $handler->display->display_options['empty']['area']['content'] = 'No studies found.';
  /* Relationship: Content: Populations (field_study_populations) */
  $handler->display->display_options['relationships']['field_study_populations_nid']['id'] = 'field_study_populations_nid';
  $handler->display->display_options['relationships']['field_study_populations_nid']['table'] = 'field_data_field_study_populations';
  $handler->display->display_options['relationships']['field_study_populations_nid']['field'] = 'field_study_populations_nid';
  $handler->display->display_options['relationships']['field_study_populations_nid']['delta'] = '0';
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title_field']['id'] = 'title_field';
  $handler->display->display_options['fields']['title_field']['table'] = 'field_data_title_field';
  $handler->display->display_options['fields']['title_field']['field'] = 'title_field';
  $handler->display->display_options['fields']['title_field']['label'] = 'Name';
  $handler->display->display_options['fields']['title_field']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['title_field']['alter']['path'] = 'node/[nid]';
  /* Field: Content: Other design */
  $handler->display->display_options['fields']['field_design_other_sp']['id'] = 'field_design_other_sp';
  $handler->display->display_options['fields']['field_design_other_sp']['table'] = 'field_data_field_design_other_sp';
  $handler->display->display_options['fields']['field_design_other_sp']['field'] = 'field_design_other_sp';
  $handler->display->display_options['fields']['field_design_other_sp']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_design_other_sp']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_design_other_sp']['alter']['text'] = '([field_design_other_sp])';
  $handler->display->display_options['fields']['field_design_other_sp']['alter']['max_length'] = '60';
  $handler->display->display_options['fields']['field_design_other_sp']['alter']['trim'] = TRUE;
  /* Field: Content: Study design */
  $handler->display->display_options['fields']['field_design']['id'] = 'field_design';
  $handler->display->display_options['fields']['field_design']['table'] = 'field_data_field_design';
  $handler->display->display_options['fields']['field_design']['field'] = 'field_design';
  $handler->display->display_options['fields']['field_design']['alter']['text'] = '[field_design] [field_design_other_sp] ';
  $handler->display->display_options['fields']['field_design']['delta_offset'] = '0';
  /* Field: Content: Target number of participants */
  $handler->display->display_options['fields']['field_target_number_participants']['id'] = 'field_target_number_participants';
  $handler->display->display_options['fields']['field_target_number_participants']['table'] = 'field_data_field_target_number_participants';
  $handler->display->display_options['fields']['field_target_number_participants']['field'] = 'field_target_number_participants';
  $handler->display->display_options['fields']['field_target_number_participants']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Country of residence */
  $handler->display->display_options['fields']['field_pop_country']['id'] = 'field_pop_country';
  $handler->display->display_options['fields']['field_pop_country']['table'] = 'field_data_field_pop_country';
  $handler->display->display_options['fields']['field_pop_country']['field'] = 'field_pop_country';
  $handler->display->display_options['fields']['field_pop_country']['relationship'] = 'field_study_populations_nid';
  $handler->display->display_options['fields']['field_pop_country']['delta_offset'] = '0';
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  /* Contextual filter: Content: Datasets (mica_dataset) */
  $handler->display->display_options['arguments']['mica_dataset_nid']['id'] = 'mica_dataset_nid';
  $handler->display->display_options['arguments']['mica_dataset_nid']['table'] = 'field_data_mica_dataset';
  $handler->display->display_options['arguments']['mica_dataset_nid']['field'] = 'mica_dataset_nid';
  $handler->display->display_options['arguments']['mica_dataset_nid']['default_action'] = 'empty';
  $handler->display->display_options['arguments']['mica_dataset_nid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['mica_dataset_nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['mica_dataset_nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['mica_dataset_nid']['summary_options']['items_per_page'] = '25';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 0;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'study' => 'study',
  );

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block_1');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $export['dataset_studies'] = $view;

  $view = new view();
  $view->name = 'datasets';
  $view->description = '';
  $view->tag = 'dataset';
  $view->base_table = 'search_api_index_dataset_index';
  $view->human_name = 'Datasets';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Datasets';
  $handler->display->display_options['css_class'] = 'table-striped';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['search_api_bypass_access'] = 1;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
    'body' => 'body',
    'field_dataset_type' => 'field_dataset_type',
  );
  $handler->display->display_options['style_options']['default'] = 'title';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'body' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_dataset_type' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['empty'] = TRUE;
  $handler->display->display_options['header']['area']['content'] = 'A Dataset holds and describes variables collected by studies participating in a consortium. Datasets make use of standardized data dictionary which gives information on variable definitions and characteristics (e.g. type, unit, categories, and area of information covered). Using the variable search tool, researchers are able to query data collected across studies participating in the consortium.';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['label'] = 'empty_datasets';
  $handler->display->display_options['empty']['area']['content'] = 'No dataset found.';
  $handler->display->display_options['empty']['area']['format'] = 'filtered_html';
  /* Field: Indexed Node: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'search_api_index_dataset_index';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Name';
  $handler->display->display_options['fields']['title']['link_to_entity'] = 1;
  /* Field: Indexed Node: Dataset Type */
  $handler->display->display_options['fields']['field_dataset_type']['id'] = 'field_dataset_type';
  $handler->display->display_options['fields']['field_dataset_type']['table'] = 'search_api_index_dataset_index';
  $handler->display->display_options['fields']['field_dataset_type']['field'] = 'field_dataset_type';
  $handler->display->display_options['fields']['field_dataset_type']['label'] = 'Type';
  /* Field: Indexed Node: The main body text */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'search_api_index_dataset_index';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = 'Description';
  $handler->display->display_options['fields']['body']['alter']['max_length'] = '200';
  $handler->display->display_options['fields']['body']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['body']['alter']['html'] = TRUE;
  $handler->display->display_options['fields']['body']['type'] = 'text_summary_or_trimmed';
  $handler->display->display_options['fields']['body']['settings'] = array(
    'trim_length' => '600',
  );
  /* Sort criterion: Indexed Node: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'search_api_index_dataset_index';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  $handler->display->display_options['sorts']['title']['expose']['label'] = 'Name';
  /* Filter criterion: Indexed Node: Content type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'search_api_index_dataset_index';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'dataset' => 'dataset',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['path'] = 'datasets';
  $export['datasets'] = $view;

  $view = new view();
  $view->name = 'harmonization_datasets';
  $view->description = '';
  $view->tag = 'dataset';
  $view->base_table = 'search_api_index_dataset_index';
  $view->human_name = 'Harmonization Datasets';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Harmonization Datasets';
  $handler->display->display_options['css_class'] = 'table-striped';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['search_api_bypass_access'] = 1;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
    'body' => 'body',
  );
  $handler->display->display_options['style_options']['default'] = 'title';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'body' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['empty'] = TRUE;
  $handler->display->display_options['header']['area']['content'] = 'A Harmonization Dataset documents and annotates a set of core variables which provides a concise but effective list of information to be harmonized in a specific scientific context. Variables found in a Harmonization Dataset therefore represent the reference format into which study-specific data needs to be processed to arrive at harmonized data. When a study can generate a variable defined in a Harmonization Dataset, a processing algorithm is developed to map study-specific data to the variable format defined in the Harmonization Dataset.<br/><br/>';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['label'] = 'empty_datasets';
  $handler->display->display_options['empty']['area']['content'] = 'No dataset found.';
  $handler->display->display_options['empty']['area']['format'] = 'filtered_html';
  /* Field: Indexed Node: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'search_api_index_dataset_index';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Name';
  $handler->display->display_options['fields']['title']['link_to_entity'] = 1;
  /* Field: Indexed Node: The main body text */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'search_api_index_dataset_index';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = 'Description';
  $handler->display->display_options['fields']['body']['alter']['max_length'] = '200';
  $handler->display->display_options['fields']['body']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['body']['alter']['html'] = TRUE;
  $handler->display->display_options['fields']['body']['type'] = 'text_summary_or_trimmed';
  $handler->display->display_options['fields']['body']['settings'] = array(
    'trim_length' => '600',
  );
  /* Sort criterion: Indexed Node: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'search_api_index_dataset_index';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  $handler->display->display_options['sorts']['title']['expose']['label'] = 'Name';
  /* Filter criterion: Indexed Node: Content type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'search_api_index_dataset_index';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'dataset' => 'dataset',
  );
  /* Filter criterion: Indexed Node: Dataset Type */
  $handler->display->display_options['filters']['field_dataset_type']['id'] = 'field_dataset_type';
  $handler->display->display_options['filters']['field_dataset_type']['table'] = 'search_api_index_dataset_index';
  $handler->display->display_options['filters']['field_dataset_type']['field'] = 'field_dataset_type';
  $handler->display->display_options['filters']['field_dataset_type']['value'] = array(
    'harmonization' => 'harmonization',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['path'] = 'harmonization-datasets';
  $export['harmonization_datasets'] = $view;

  $view = new view();
  $view->name = 'study_datasets';
  $view->description = '';
  $view->tag = 'dataset';
  $view->base_table = 'search_api_index_dataset_index';
  $view->human_name = 'Study Datasets';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Study Datasets';
  $handler->display->display_options['css_class'] = 'table-striped';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
    'body' => 'body',
  );
  $handler->display->display_options['style_options']['default'] = 'title';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'body' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['empty'] = TRUE;
  $handler->display->display_options['header']['area']['content'] = 'A Study Dataset holds and describes variables collected by studies participating in a consortium. Study Datasets make use of standardized data dictionary which gives information on variable definitions and characteristics (e.g. type, unit, categories, and area of information covered). Using the variable search tool, researchers are able to query data collected across studies participating in the consortium.<br/><br/>';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['label'] = 'empty_datasets';
  $handler->display->display_options['empty']['area']['content'] = 'No dataset found.';
  $handler->display->display_options['empty']['area']['format'] = 'filtered_html';
  /* Field: Indexed Node: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'search_api_index_dataset_index';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Name';
  $handler->display->display_options['fields']['title']['link_to_entity'] = 1;
  /* Field: Indexed Node: The main body text */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'search_api_index_dataset_index';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = 'Description';
  $handler->display->display_options['fields']['body']['alter']['max_length'] = '200';
  $handler->display->display_options['fields']['body']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['body']['alter']['html'] = TRUE;
  $handler->display->display_options['fields']['body']['type'] = 'text_summary_or_trimmed';
  $handler->display->display_options['fields']['body']['settings'] = array(
    'trim_length' => '600',
  );
  /* Sort criterion: Indexed Node: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'search_api_index_dataset_index';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  $handler->display->display_options['sorts']['title']['expose']['label'] = 'Name';
  /* Filter criterion: Indexed Node: Content type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'search_api_index_dataset_index';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'dataset' => 'dataset',
  );
  /* Filter criterion: Indexed Node: Dataset Type */
  $handler->display->display_options['filters']['field_dataset_type']['id'] = 'field_dataset_type';
  $handler->display->display_options['filters']['field_dataset_type']['table'] = 'search_api_index_dataset_index';
  $handler->display->display_options['filters']['field_dataset_type']['field'] = 'field_dataset_type';
  $handler->display->display_options['filters']['field_dataset_type']['value'] = array(
    'study' => 'study',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['path'] = 'study-datasets';
  $export['study_datasets'] = $view;

  $view = new view();
  $view->name = 'variable_csv_export';
  $view->description = 'Export of all Variables in CSV';
  $view->tag = 'csv, dataset';
  $view->base_table = 'node';
  $view->human_name = 'Variable CSV Export';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: Content: Dataset (field_dataset) */
  $handler->display->display_options['relationships']['field_dataset_nid']['id'] = 'field_dataset_nid';
  $handler->display->display_options['relationships']['field_dataset_nid']['table'] = 'field_data_field_dataset';
  $handler->display->display_options['relationships']['field_dataset_nid']['field'] = 'field_dataset_nid';
  $handler->display->display_options['relationships']['field_dataset_nid']['required'] = TRUE;
  $handler->display->display_options['relationships']['field_dataset_nid']['delta'] = '-1';
  /* Field: Content: Node UUID */
  $handler->display->display_options['fields']['uuid']['id'] = 'uuid';
  $handler->display->display_options['fields']['uuid']['table'] = 'node';
  $handler->display->display_options['fields']['uuid']['field'] = 'uuid';
  $handler->display->display_options['fields']['uuid']['label'] = 'UUID';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['trim_whitespace'] = TRUE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Label */
  $handler->display->display_options['fields']['field_label']['id'] = 'field_label';
  $handler->display->display_options['fields']['field_label']['table'] = 'field_data_field_label';
  $handler->display->display_options['fields']['field_label']['field'] = 'field_label';
  $handler->display->display_options['fields']['field_label']['label'] = 'label';
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = 'body';
  /* Field: Content: Dataset */
  $handler->display->display_options['fields']['field_dataset']['id'] = 'field_dataset';
  $handler->display->display_options['fields']['field_dataset']['table'] = 'field_data_field_dataset';
  $handler->display->display_options['fields']['field_dataset']['field'] = 'field_dataset';
  $handler->display->display_options['fields']['field_dataset']['label'] = 'dataset';
  $handler->display->display_options['fields']['field_dataset']['type'] = 'node_reference_plain';
  /* Field: Content: Value Type */
  $handler->display->display_options['fields']['field_value_type']['id'] = 'field_value_type';
  $handler->display->display_options['fields']['field_value_type']['table'] = 'field_data_field_value_type';
  $handler->display->display_options['fields']['field_value_type']['field'] = 'field_value_type';
  $handler->display->display_options['fields']['field_value_type']['label'] = 'value_type';
  $handler->display->display_options['fields']['field_value_type']['type'] = 'list_key';
  /* Field: Content: Unit */
  $handler->display->display_options['fields']['field_unit']['id'] = 'field_unit';
  $handler->display->display_options['fields']['field_unit']['table'] = 'field_data_field_unit';
  $handler->display->display_options['fields']['field_unit']['field'] = 'field_unit';
  $handler->display->display_options['fields']['field_unit']['label'] = 'unit';
  /* Field: Content: Repeatable */
  $handler->display->display_options['fields']['field_repeatable']['id'] = 'field_repeatable';
  $handler->display->display_options['fields']['field_repeatable']['table'] = 'field_data_field_repeatable';
  $handler->display->display_options['fields']['field_repeatable']['field'] = 'field_repeatable';
  $handler->display->display_options['fields']['field_repeatable']['label'] = 'repeatable';
  /* Field: Content: Categories */
  $handler->display->display_options['fields']['field_variable_categories_1']['id'] = 'field_variable_categories_1';
  $handler->display->display_options['fields']['field_variable_categories_1']['table'] = 'field_data_field_variable_categories';
  $handler->display->display_options['fields']['field_variable_categories_1']['field'] = 'field_variable_categories';
  $handler->display->display_options['fields']['field_variable_categories_1']['label'] = 'categories_name';
  $handler->display->display_options['fields']['field_variable_categories_1']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_variable_categories_1']['alter']['text'] = '[field_variable_categories_1-name]';
  $handler->display->display_options['fields']['field_variable_categories_1']['alter']['trim_whitespace'] = TRUE;
  $handler->display->display_options['fields']['field_variable_categories_1']['click_sort_column'] = 'name';
  $handler->display->display_options['fields']['field_variable_categories_1']['type'] = 'category_field_key_formatter';
  $handler->display->display_options['fields']['field_variable_categories_1']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_variable_categories_1']['separator'] = '|';
  /* Field: Content: Categories */
  $handler->display->display_options['fields']['field_variable_categories']['id'] = 'field_variable_categories';
  $handler->display->display_options['fields']['field_variable_categories']['table'] = 'field_data_field_variable_categories';
  $handler->display->display_options['fields']['field_variable_categories']['field'] = 'field_variable_categories';
  $handler->display->display_options['fields']['field_variable_categories']['label'] = 'categories_label';
  $handler->display->display_options['fields']['field_variable_categories']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_variable_categories']['alter']['text'] = '[field_variable_categories-label]';
  $handler->display->display_options['fields']['field_variable_categories']['alter']['trim_whitespace'] = TRUE;
  $handler->display->display_options['fields']['field_variable_categories']['click_sort_column'] = 'name';
  $handler->display->display_options['fields']['field_variable_categories']['type'] = 'category_field_key_formatter';
  $handler->display->display_options['fields']['field_variable_categories']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_variable_categories']['separator'] = '|';
  /* Field: Content: Categories */
  $handler->display->display_options['fields']['field_variable_categories_2']['id'] = 'field_variable_categories_2';
  $handler->display->display_options['fields']['field_variable_categories_2']['table'] = 'field_data_field_variable_categories';
  $handler->display->display_options['fields']['field_variable_categories_2']['field'] = 'field_variable_categories';
  $handler->display->display_options['fields']['field_variable_categories_2']['label'] = 'categories_missing';
  $handler->display->display_options['fields']['field_variable_categories_2']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_variable_categories_2']['alter']['text'] = '[field_variable_categories_2-missing]';
  $handler->display->display_options['fields']['field_variable_categories_2']['alter']['trim_whitespace'] = TRUE;
  $handler->display->display_options['fields']['field_variable_categories_2']['click_sort_column'] = 'name';
  $handler->display->display_options['fields']['field_variable_categories_2']['type'] = 'category_field_key_formatter';
  $handler->display->display_options['fields']['field_variable_categories_2']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_variable_categories_2']['separator'] = '|';
  /* Field: Content: Published */
  $handler->display->display_options['fields']['status']['id'] = 'status';
  $handler->display->display_options['fields']['status']['table'] = 'node';
  $handler->display->display_options['fields']['status']['field'] = 'status';
  $handler->display->display_options['fields']['status']['label'] = 'published';
  $handler->display->display_options['fields']['status']['alter']['text'] = '[status]';
  $handler->display->display_options['fields']['status']['not'] = 0;
  /* Field: Content: Anthropometric Structures */
  $handler->display->display_options['fields']['field_anthropometric_structures']['id'] = 'field_anthropometric_structures';
  $handler->display->display_options['fields']['field_anthropometric_structures']['table'] = 'field_data_field_anthropometric_structures';
  $handler->display->display_options['fields']['field_anthropometric_structures']['field'] = 'field_anthropometric_structures';
  $handler->display->display_options['fields']['field_anthropometric_structures']['label'] = 'anthropometric_structures';
  $handler->display->display_options['fields']['field_anthropometric_structures']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_anthropometric_structures']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_anthropometric_structures']['separator'] = '|';
  /* Field: Content: Body Functions */
  $handler->display->display_options['fields']['field_body_functions']['id'] = 'field_body_functions';
  $handler->display->display_options['fields']['field_body_functions']['table'] = 'field_data_field_body_functions';
  $handler->display->display_options['fields']['field_body_functions']['field'] = 'field_body_functions';
  $handler->display->display_options['fields']['field_body_functions']['label'] = 'body_functions';
  $handler->display->display_options['fields']['field_body_functions']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_body_functions']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_body_functions']['separator'] = '|';
  /* Field: Content: Body Structures */
  $handler->display->display_options['fields']['field_body_structures']['id'] = 'field_body_structures';
  $handler->display->display_options['fields']['field_body_structures']['table'] = 'field_data_field_body_structures';
  $handler->display->display_options['fields']['field_body_structures']['field'] = 'field_body_structures';
  $handler->display->display_options['fields']['field_body_structures']['label'] = 'body_structures';
  $handler->display->display_options['fields']['field_body_structures']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_body_structures']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_body_structures']['separator'] = '|';
  /* Field: Content: Data Source */
  $handler->display->display_options['fields']['field_data_source']['id'] = 'field_data_source';
  $handler->display->display_options['fields']['field_data_source']['table'] = 'field_data_field_data_source';
  $handler->display->display_options['fields']['field_data_source']['field'] = 'field_data_source';
  $handler->display->display_options['fields']['field_data_source']['label'] = 'data_source';
  $handler->display->display_options['fields']['field_data_source']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_data_source']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_data_source']['separator'] = '|';
  /* Field: Content: Diseases History and Related Health Problems */
  $handler->display->display_options['fields']['field_disease_history']['id'] = 'field_disease_history';
  $handler->display->display_options['fields']['field_disease_history']['table'] = 'field_data_field_disease_history';
  $handler->display->display_options['fields']['field_disease_history']['field'] = 'field_disease_history';
  $handler->display->display_options['fields']['field_disease_history']['label'] = 'disease_history';
  $handler->display->display_options['fields']['field_disease_history']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_disease_history']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_disease_history']['separator'] = '|';
  /* Field: Content: Life Habits/Behaviours */
  $handler->display->display_options['fields']['field_life_habits_behaviours']['id'] = 'field_life_habits_behaviours';
  $handler->display->display_options['fields']['field_life_habits_behaviours']['table'] = 'field_data_field_life_habits_behaviours';
  $handler->display->display_options['fields']['field_life_habits_behaviours']['field'] = 'field_life_habits_behaviours';
  $handler->display->display_options['fields']['field_life_habits_behaviours']['label'] = 'life_habits_behaviours';
  $handler->display->display_options['fields']['field_life_habits_behaviours']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_life_habits_behaviours']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_life_habits_behaviours']['separator'] = '|';
  /* Field: Content: Medical Health Interventions/Health Services Utilization */
  $handler->display->display_options['fields']['field_medical_health_interv']['id'] = 'field_medical_health_interv';
  $handler->display->display_options['fields']['field_medical_health_interv']['table'] = 'field_data_field_medical_health_interv';
  $handler->display->display_options['fields']['field_medical_health_interv']['field'] = 'field_medical_health_interv';
  $handler->display->display_options['fields']['field_medical_health_interv']['label'] = 'medical_health_interv';
  $handler->display->display_options['fields']['field_medical_health_interv']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_medical_health_interv']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_medical_health_interv']['separator'] = '|';
  /* Field: Content: Medication */
  $handler->display->display_options['fields']['field_medication']['id'] = 'field_medication';
  $handler->display->display_options['fields']['field_medication']['table'] = 'field_data_field_medication';
  $handler->display->display_options['fields']['field_medication']['field'] = 'field_medication';
  $handler->display->display_options['fields']['field_medication']['label'] = 'medication';
  $handler->display->display_options['fields']['field_medication']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_medication']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_medication']['separator'] = '|';
  /* Field: Content: Participant's Early Life/Childhood */
  $handler->display->display_options['fields']['field_early_life']['id'] = 'field_early_life';
  $handler->display->display_options['fields']['field_early_life']['table'] = 'field_data_field_early_life';
  $handler->display->display_options['fields']['field_early_life']['field'] = 'field_early_life';
  $handler->display->display_options['fields']['field_early_life']['label'] = 'early_life';
  $handler->display->display_options['fields']['field_early_life']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_early_life']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_early_life']['separator'] = '|';
  /* Field: Content: Perception of Health/Quality of life */
  $handler->display->display_options['fields']['field_perception_of_health']['id'] = 'field_perception_of_health';
  $handler->display->display_options['fields']['field_perception_of_health']['table'] = 'field_data_field_perception_of_health';
  $handler->display->display_options['fields']['field_perception_of_health']['field'] = 'field_perception_of_health';
  $handler->display->display_options['fields']['field_perception_of_health']['label'] = 'perception_of_health';
  $handler->display->display_options['fields']['field_perception_of_health']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_perception_of_health']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_perception_of_health']['separator'] = '|';
  /* Field: Content: Physical Environment */
  $handler->display->display_options['fields']['field_physical_environment']['id'] = 'field_physical_environment';
  $handler->display->display_options['fields']['field_physical_environment']['table'] = 'field_data_field_physical_environment';
  $handler->display->display_options['fields']['field_physical_environment']['field'] = 'field_physical_environment';
  $handler->display->display_options['fields']['field_physical_environment']['label'] = 'physical_environment';
  $handler->display->display_options['fields']['field_physical_environment']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_physical_environment']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_physical_environment']['separator'] = '|';
  /* Field: Content: Reproductive Health and History */
  $handler->display->display_options['fields']['field_reproductive_history']['id'] = 'field_reproductive_history';
  $handler->display->display_options['fields']['field_reproductive_history']['table'] = 'field_data_field_reproductive_history';
  $handler->display->display_options['fields']['field_reproductive_history']['field'] = 'field_reproductive_history';
  $handler->display->display_options['fields']['field_reproductive_history']['label'] = 'reproductive_history';
  $handler->display->display_options['fields']['field_reproductive_history']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_reproductive_history']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_reproductive_history']['separator'] = '|';
  /* Field: Content: Social Environment */
  $handler->display->display_options['fields']['field_social_environment']['id'] = 'field_social_environment';
  $handler->display->display_options['fields']['field_social_environment']['table'] = 'field_data_field_social_environment';
  $handler->display->display_options['fields']['field_social_environment']['field'] = 'field_social_environment';
  $handler->display->display_options['fields']['field_social_environment']['label'] = 'social_environment';
  $handler->display->display_options['fields']['field_social_environment']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_social_environment']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_social_environment']['separator'] = '|';
  /* Field: Content: Sociodemographic/Socioeconomic Characteristics */
  $handler->display->display_options['fields']['field_sociodemographic_charact']['id'] = 'field_sociodemographic_charact';
  $handler->display->display_options['fields']['field_sociodemographic_charact']['table'] = 'field_data_field_sociodemographic_charact';
  $handler->display->display_options['fields']['field_sociodemographic_charact']['field'] = 'field_sociodemographic_charact';
  $handler->display->display_options['fields']['field_sociodemographic_charact']['label'] = 'sociodemographic_charact';
  $handler->display->display_options['fields']['field_sociodemographic_charact']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_sociodemographic_charact']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_sociodemographic_charact']['separator'] = '|';
  /* Field: Content: Target */
  $handler->display->display_options['fields']['field_target']['id'] = 'field_target';
  $handler->display->display_options['fields']['field_target']['table'] = 'field_data_field_target';
  $handler->display->display_options['fields']['field_target']['field'] = 'field_target';
  $handler->display->display_options['fields']['field_target']['label'] = 'target';
  $handler->display->display_options['fields']['field_target']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_target']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_target']['separator'] = '|';
  /* Field: Content: Laboratory Measures */
  $handler->display->display_options['fields']['field_laboratory_measures']['id'] = 'field_laboratory_measures';
  $handler->display->display_options['fields']['field_laboratory_measures']['table'] = 'field_data_field_laboratory_measures';
  $handler->display->display_options['fields']['field_laboratory_measures']['field'] = 'field_laboratory_measures';
  $handler->display->display_options['fields']['field_laboratory_measures']['label'] = 'laboratory_measures';
  $handler->display->display_options['fields']['field_laboratory_measures']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_laboratory_measures']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_laboratory_measures']['separator'] = '|';
  /* Field: Content: Administrative Information */
  $handler->display->display_options['fields']['field_administrative_information']['id'] = 'field_administrative_information';
  $handler->display->display_options['fields']['field_administrative_information']['table'] = 'field_data_field_administrative_information';
  $handler->display->display_options['fields']['field_administrative_information']['field'] = 'field_administrative_information';
  $handler->display->display_options['fields']['field_administrative_information']['label'] = 'administrative_information';
  $handler->display->display_options['fields']['field_administrative_information']['type'] = 'taxonomy_term_reference_plain';
  /* Sort criterion: Content: Position index (field_position) */
  $handler->display->display_options['sorts']['field_position_value']['id'] = 'field_position_value';
  $handler->display->display_options['sorts']['field_position_value']['table'] = 'field_data_field_position';
  $handler->display->display_options['sorts']['field_position_value']['field'] = 'field_position_value';
  /* Contextual filter: Content: Dataset (field_dataset) */
  $handler->display->display_options['arguments']['field_dataset_nid']['id'] = 'field_dataset_nid';
  $handler->display->display_options['arguments']['field_dataset_nid']['table'] = 'field_data_field_dataset';
  $handler->display->display_options['arguments']['field_dataset_nid']['field'] = 'field_dataset_nid';
  $handler->display->display_options['arguments']['field_dataset_nid']['default_action'] = 'empty';
  $handler->display->display_options['arguments']['field_dataset_nid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_dataset_nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_dataset_nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_dataset_nid']['summary_options']['items_per_page'] = '25';
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'variable' => 'variable',
  );

  /* Display: Data export */
  $handler = $view->new_display('views_data_export', 'Data export', 'views_data_export_1');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_data_export_csv';
  $handler->display->display_options['style_options']['provide_file'] = 1;
  $handler->display->display_options['style_options']['filename'] = '%view_%timestamp-yyyy-%timestamp-mm-%timestamp-dd.csv';
  $handler->display->display_options['style_options']['parent_sort'] = 0;
  $handler->display->display_options['style_options']['quote'] = 1;
  $handler->display->display_options['style_options']['trim'] = 0;
  $handler->display->display_options['style_options']['replace_newlines'] = 0;
  $handler->display->display_options['style_options']['header'] = 1;
  $handler->display->display_options['path'] = 'variable-csv';
  $handler->display->display_options['use_batch'] = 'batch';
  $export['variable_csv_export'] = $view;

  $view = new view();
  $view->name = 'variable_search';
  $view->description = '';
  $view->tag = 'dataset, search';
  $view->base_table = 'search_api_index_variable_index';
  $view->human_name = 'Variable Search';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Variables';
  $handler->display->display_options['css_class'] = 'table-striped';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '50';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
    'field_label' => 'field_label',
    'field_dataset' => 'field_dataset',
    'field_position' => 'field_position',
  );
  $handler->display->display_options['style_options']['default'] = 'field_position';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_label' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_dataset' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_position' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['style_options']['sticky'] = TRUE;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['label'] = 'empty_variables';
  $handler->display->display_options['empty']['area']['content'] = 'No variables found.';
  $handler->display->display_options['empty']['area']['format'] = 'filtered_html';
  /* Field: Indexed Node: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'search_api_index_variable_index';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Name';
  $handler->display->display_options['fields']['title']['link_to_entity'] = 1;
  /* Field: Indexed Node: Label */
  $handler->display->display_options['fields']['field_label']['id'] = 'field_label';
  $handler->display->display_options['fields']['field_label']['table'] = 'search_api_index_variable_index';
  $handler->display->display_options['fields']['field_label']['field'] = 'field_label';
  $handler->display->display_options['fields']['field_label']['alter']['max_length'] = '70';
  /* Field: Indexed Node: Dataset */
  $handler->display->display_options['fields']['field_dataset']['id'] = 'field_dataset';
  $handler->display->display_options['fields']['field_dataset']['table'] = 'search_api_index_variable_index';
  $handler->display->display_options['fields']['field_dataset']['field'] = 'field_dataset';
  $handler->display->display_options['fields']['field_dataset']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['field_dataset']['view_mode'] = 'full';
  /* Field: Indexed Node: Position index */
  $handler->display->display_options['fields']['field_position']['id'] = 'field_position';
  $handler->display->display_options['fields']['field_position']['table'] = 'search_api_index_variable_index';
  $handler->display->display_options['fields']['field_position']['field'] = 'field_position';
  $handler->display->display_options['fields']['field_position']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_position']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 1,
  );
  /* Sort criterion: Indexed Node: Position index */
  $handler->display->display_options['sorts']['field_position']['id'] = 'field_position';
  $handler->display->display_options['sorts']['field_position']['table'] = 'search_api_index_variable_index';
  $handler->display->display_options['sorts']['field_position']['field'] = 'field_position';
  /* Filter criterion: Search: Fulltext search */
  $handler->display->display_options['filters']['search_api_views_fulltext']['id'] = 'search_api_views_fulltext';
  $handler->display->display_options['filters']['search_api_views_fulltext']['table'] = 'search_api_index_variable_index';
  $handler->display->display_options['filters']['search_api_views_fulltext']['field'] = 'search_api_views_fulltext';
  $handler->display->display_options['filters']['search_api_views_fulltext']['exposed'] = TRUE;
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['operator_id'] = 'search_api_views_fulltext_op';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['label'] = 'Fulltext search';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['operator'] = 'search_api_views_fulltext_op';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['identifier'] = 'search_api_views_fulltext';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    6 => 0,
    5 => 0,
    7 => 0,
    8 => 0,
    10 => 0,
    9 => 0,
  );
  $handler->display->display_options['filters']['search_api_views_fulltext']['fields'] = array(
    'search_api_aggregation_1' => 'search_api_aggregation_1',
    'search_api_aggregation_2' => 'search_api_aggregation_2',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['path'] = 'variable-search';
  $export['variable_search'] = $view;

  $view = new view();
  $view->name = 'variables_dimensions';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'search_api_index_variable_index';
  $view->human_name = 'variables-dimensions';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Manage Dataset Variables';
  $handler->display->display_options['css_class'] = 'table-striped';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'edit any variable content';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '100';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['pager']['options']['expose']['items_per_page'] = TRUE;
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options'] = '100, 250, 500, 1000, 2500';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'views_bulk_operations' => 'views_bulk_operations',
    'title_field' => 'title_field',
    'field_label' => 'field_label',
    'field_anthropometric_structures' => 'field_anthropometric_structures',
    'field_body_functions' => 'field_body_functions',
    'field_body_structures' => 'field_body_structures',
    'field_data_source' => 'field_data_source',
    'field_disease_history' => 'field_disease_history',
    'field_laboratory_measures' => 'field_laboratory_measures',
    'field_life_habits_behaviours' => 'field_life_habits_behaviours',
    'field_medical_health_interv' => 'field_medical_health_interv',
    'field_medication' => 'field_medication',
    'field_early_life' => 'field_early_life',
    'field_perception_of_health' => 'field_perception_of_health',
    'field_physical_environment' => 'field_physical_environment',
    'field_reproductive_history' => 'field_reproductive_history',
    'field_social_environment' => 'field_social_environment',
    'field_sociodemographic_charact' => 'field_sociodemographic_charact',
    'field_target' => 'field_target',
    'body' => 'body',
    'nothing' => 'nothing',
    'edit_node' => 'edit_node',
    'created' => 'created',
    'field_position' => 'field_position',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'views_bulk_operations' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 1,
    ),
    'title_field' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_label' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_anthropometric_structures' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 1,
    ),
    'field_body_functions' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 1,
    ),
    'field_body_structures' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 1,
    ),
    'field_data_source' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_disease_history' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_laboratory_measures' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_life_habits_behaviours' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_medical_health_interv' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 1,
    ),
    'field_medication' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 1,
    ),
    'field_early_life' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_perception_of_health' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_physical_environment' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_reproductive_history' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_social_environment' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_sociodemographic_charact' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_target' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'body' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'nothing' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'edit_node' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'created' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_position' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Header: Global: Result summary */
  $handler->display->display_options['header']['result']['id'] = 'result';
  $handler->display->display_options['header']['result']['table'] = 'views';
  $handler->display->display_options['header']['result']['field'] = 'result';
  /* Field: Indexed Node: Bulk operations */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'search_api_index_variable_index';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['label'] = 'Assign domains';
  $handler->display->display_options['fields']['views_bulk_operations']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '1';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['enable_select_all_pages'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['force_single'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['entity_load_capacity'] = '50';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_operations'] = array(
    'action::node_assign_owner_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::views_bulk_operations_delete_item' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::views_bulk_operations_script_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_make_sticky_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_make_unsticky_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::views_bulk_operations_modify_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 1,
      'override_label' => 1,
      'label' => 'Add domains',
      'settings' => array(
        'show_all_tokens' => 0,
        'display_values' => array(
          'variable::field_administrative_information' => 'variable::field_administrative_information',
          'variable::field_anthropometric_structures' => 'variable::field_anthropometric_structures',
          'variable::field_body_functions' => 'variable::field_body_functions',
          'variable::field_body_structures' => 'variable::field_body_structures',
          'variable::field_data_source' => 'variable::field_data_source',
          'variable::field_disease_history' => 'variable::field_disease_history',
          'variable::field_early_life' => 'variable::field_early_life',
          'variable::field_laboratory_measures' => 'variable::field_laboratory_measures',
          'variable::field_life_habits_behaviours' => 'variable::field_life_habits_behaviours',
          'variable::field_medical_health_interv' => 'variable::field_medical_health_interv',
          'variable::field_medication' => 'variable::field_medication',
          'variable::field_perception_of_health' => 'variable::field_perception_of_health',
          'variable::field_physical_environment' => 'variable::field_physical_environment',
          'variable::field_reproductive_history' => 'variable::field_reproductive_history',
          'variable::field_social_environment' => 'variable::field_social_environment',
          'variable::field_sociodemographic_charact' => 'variable::field_sociodemographic_charact',
          'variable::field_target' => 'variable::field_target',
        ),
      ),
    ),
    'action::views_bulk_operations_argument_selector_action' => array(
      'selected' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
      'settings' => array(
        'url' => '',
      ),
    ),
    'action::node_promote_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_publish_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_unpromote_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_save_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::system_send_email_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::workbench_moderation_set_state_action' => array(
      'selected' => 1,
      'postpone_processing' => 1,
      'skip_confirmation' => 1,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_unpublish_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_unpublish_by_keyword_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::auto_entitylabel_entity_update_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::pathauto_node_update_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
  );
  /* Field: Indexed Node: Title */
  $handler->display->display_options['fields']['title_field']['id'] = 'title_field';
  $handler->display->display_options['fields']['title_field']['table'] = 'search_api_index_variable_index';
  $handler->display->display_options['fields']['title_field']['field'] = 'title_field';
  $handler->display->display_options['fields']['title_field']['label'] = 'Name';
  /* Field: Indexed Node: Label */
  $handler->display->display_options['fields']['field_label']['id'] = 'field_label';
  $handler->display->display_options['fields']['field_label']['table'] = 'search_api_index_variable_index';
  $handler->display->display_options['fields']['field_label']['field'] = 'field_label';
  /* Field: Indexed Node: Anthropometric Structures */
  $handler->display->display_options['fields']['field_anthropometric_structures']['id'] = 'field_anthropometric_structures';
  $handler->display->display_options['fields']['field_anthropometric_structures']['table'] = 'search_api_index_variable_index';
  $handler->display->display_options['fields']['field_anthropometric_structures']['field'] = 'field_anthropometric_structures';
  $handler->display->display_options['fields']['field_anthropometric_structures']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_anthropometric_structures']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_anthropometric_structures']['alter']['text'] = '[field_anthropometric_structures];';
  $handler->display->display_options['fields']['field_anthropometric_structures']['alter']['max_length'] = '100';
  $handler->display->display_options['fields']['field_anthropometric_structures']['list']['separator'] = '; ';
  $handler->display->display_options['fields']['field_anthropometric_structures']['link_to_entity'] = 1;
  $handler->display->display_options['fields']['field_anthropometric_structures']['view_mode'] = 'full';
  /* Field: Indexed Node: Body Functions */
  $handler->display->display_options['fields']['field_body_functions']['id'] = 'field_body_functions';
  $handler->display->display_options['fields']['field_body_functions']['table'] = 'search_api_index_variable_index';
  $handler->display->display_options['fields']['field_body_functions']['field'] = 'field_body_functions';
  $handler->display->display_options['fields']['field_body_functions']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_body_functions']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_body_functions']['alter']['text'] = '[field_body_functions]; ';
  $handler->display->display_options['fields']['field_body_functions']['list']['separator'] = '; ';
  $handler->display->display_options['fields']['field_body_functions']['link_to_entity'] = 1;
  $handler->display->display_options['fields']['field_body_functions']['view_mode'] = 'full';
  /* Field: Indexed Node: Body Structures */
  $handler->display->display_options['fields']['field_body_structures']['id'] = 'field_body_structures';
  $handler->display->display_options['fields']['field_body_structures']['table'] = 'search_api_index_variable_index';
  $handler->display->display_options['fields']['field_body_structures']['field'] = 'field_body_structures';
  $handler->display->display_options['fields']['field_body_structures']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_body_structures']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_body_structures']['alter']['text'] = '[field_body_structures]; ';
  $handler->display->display_options['fields']['field_body_structures']['list']['separator'] = '; ';
  $handler->display->display_options['fields']['field_body_structures']['link_to_entity'] = 1;
  $handler->display->display_options['fields']['field_body_structures']['view_mode'] = 'full';
  /* Field: Indexed Node: Data Source */
  $handler->display->display_options['fields']['field_data_source']['id'] = 'field_data_source';
  $handler->display->display_options['fields']['field_data_source']['table'] = 'search_api_index_variable_index';
  $handler->display->display_options['fields']['field_data_source']['field'] = 'field_data_source';
  $handler->display->display_options['fields']['field_data_source']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_data_source']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_data_source']['alter']['text'] = '[field_data_source]; ';
  $handler->display->display_options['fields']['field_data_source']['list']['separator'] = '; ';
  $handler->display->display_options['fields']['field_data_source']['link_to_entity'] = 1;
  $handler->display->display_options['fields']['field_data_source']['view_mode'] = 'full';
  /* Field: Indexed Node: Diseases History and Related Health Problems */
  $handler->display->display_options['fields']['field_disease_history']['id'] = 'field_disease_history';
  $handler->display->display_options['fields']['field_disease_history']['table'] = 'search_api_index_variable_index';
  $handler->display->display_options['fields']['field_disease_history']['field'] = 'field_disease_history';
  $handler->display->display_options['fields']['field_disease_history']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_disease_history']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_disease_history']['alter']['text'] = '[field_disease_history]; ';
  $handler->display->display_options['fields']['field_disease_history']['list']['separator'] = '; ';
  $handler->display->display_options['fields']['field_disease_history']['link_to_entity'] = 1;
  $handler->display->display_options['fields']['field_disease_history']['view_mode'] = 'full';
  /* Field: Indexed Node: Laboratory Measures */
  $handler->display->display_options['fields']['field_laboratory_measures']['id'] = 'field_laboratory_measures';
  $handler->display->display_options['fields']['field_laboratory_measures']['table'] = 'search_api_index_variable_index';
  $handler->display->display_options['fields']['field_laboratory_measures']['field'] = 'field_laboratory_measures';
  $handler->display->display_options['fields']['field_laboratory_measures']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_laboratory_measures']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_laboratory_measures']['alter']['text'] = '[field_laboratory_measures]; ';
  $handler->display->display_options['fields']['field_laboratory_measures']['list']['separator'] = '; ';
  $handler->display->display_options['fields']['field_laboratory_measures']['link_to_entity'] = 1;
  $handler->display->display_options['fields']['field_laboratory_measures']['view_mode'] = 'full';
  /* Field: Indexed Node: Life Habits/Behaviours */
  $handler->display->display_options['fields']['field_life_habits_behaviours']['id'] = 'field_life_habits_behaviours';
  $handler->display->display_options['fields']['field_life_habits_behaviours']['table'] = 'search_api_index_variable_index';
  $handler->display->display_options['fields']['field_life_habits_behaviours']['field'] = 'field_life_habits_behaviours';
  $handler->display->display_options['fields']['field_life_habits_behaviours']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_life_habits_behaviours']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_life_habits_behaviours']['alter']['text'] = '[field_life_habits_behaviours]; ';
  $handler->display->display_options['fields']['field_life_habits_behaviours']['list']['separator'] = '; ';
  $handler->display->display_options['fields']['field_life_habits_behaviours']['link_to_entity'] = 1;
  $handler->display->display_options['fields']['field_life_habits_behaviours']['view_mode'] = 'full';
  /* Field: Indexed Node: Medical Health Interventions/Health Services Utilization */
  $handler->display->display_options['fields']['field_medical_health_interv']['id'] = 'field_medical_health_interv';
  $handler->display->display_options['fields']['field_medical_health_interv']['table'] = 'search_api_index_variable_index';
  $handler->display->display_options['fields']['field_medical_health_interv']['field'] = 'field_medical_health_interv';
  $handler->display->display_options['fields']['field_medical_health_interv']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_medical_health_interv']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_medical_health_interv']['alter']['text'] = '[field_medical_health_interv]; ';
  $handler->display->display_options['fields']['field_medical_health_interv']['list']['separator'] = '; ';
  $handler->display->display_options['fields']['field_medical_health_interv']['link_to_entity'] = 1;
  $handler->display->display_options['fields']['field_medical_health_interv']['view_mode'] = 'full';
  /* Field: Indexed Node: Medication */
  $handler->display->display_options['fields']['field_medication']['id'] = 'field_medication';
  $handler->display->display_options['fields']['field_medication']['table'] = 'search_api_index_variable_index';
  $handler->display->display_options['fields']['field_medication']['field'] = 'field_medication';
  $handler->display->display_options['fields']['field_medication']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_medication']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_medication']['alter']['text'] = '[field_medication]; ';
  $handler->display->display_options['fields']['field_medication']['list']['separator'] = '; ';
  $handler->display->display_options['fields']['field_medication']['link_to_entity'] = 1;
  $handler->display->display_options['fields']['field_medication']['view_mode'] = 'full';
  /* Field: Indexed Node: Participant's Early Life/Childhood */
  $handler->display->display_options['fields']['field_early_life']['id'] = 'field_early_life';
  $handler->display->display_options['fields']['field_early_life']['table'] = 'search_api_index_variable_index';
  $handler->display->display_options['fields']['field_early_life']['field'] = 'field_early_life';
  $handler->display->display_options['fields']['field_early_life']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_early_life']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_early_life']['alter']['text'] = '[field_early_life],';
  $handler->display->display_options['fields']['field_early_life']['link_to_entity'] = 1;
  $handler->display->display_options['fields']['field_early_life']['view_mode'] = 'full';
  /* Field: Indexed Node: Perception of Health/Quality of life */
  $handler->display->display_options['fields']['field_perception_of_health']['id'] = 'field_perception_of_health';
  $handler->display->display_options['fields']['field_perception_of_health']['table'] = 'search_api_index_variable_index';
  $handler->display->display_options['fields']['field_perception_of_health']['field'] = 'field_perception_of_health';
  $handler->display->display_options['fields']['field_perception_of_health']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_perception_of_health']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_perception_of_health']['alter']['text'] = '[field_perception_of_health]; ';
  $handler->display->display_options['fields']['field_perception_of_health']['list']['separator'] = '; ';
  $handler->display->display_options['fields']['field_perception_of_health']['link_to_entity'] = 1;
  $handler->display->display_options['fields']['field_perception_of_health']['view_mode'] = 'full';
  /* Field: Indexed Node: Physical Environment */
  $handler->display->display_options['fields']['field_physical_environment']['id'] = 'field_physical_environment';
  $handler->display->display_options['fields']['field_physical_environment']['table'] = 'search_api_index_variable_index';
  $handler->display->display_options['fields']['field_physical_environment']['field'] = 'field_physical_environment';
  $handler->display->display_options['fields']['field_physical_environment']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_physical_environment']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_physical_environment']['alter']['text'] = '[field_physical_environment]; ';
  $handler->display->display_options['fields']['field_physical_environment']['list']['separator'] = '; ';
  $handler->display->display_options['fields']['field_physical_environment']['link_to_entity'] = 1;
  $handler->display->display_options['fields']['field_physical_environment']['view_mode'] = 'full';
  /* Field: Indexed Node: Reproductive Health and History */
  $handler->display->display_options['fields']['field_reproductive_history']['id'] = 'field_reproductive_history';
  $handler->display->display_options['fields']['field_reproductive_history']['table'] = 'search_api_index_variable_index';
  $handler->display->display_options['fields']['field_reproductive_history']['field'] = 'field_reproductive_history';
  $handler->display->display_options['fields']['field_reproductive_history']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_reproductive_history']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_reproductive_history']['alter']['text'] = '[field_reproductive_history]; ';
  $handler->display->display_options['fields']['field_reproductive_history']['list']['separator'] = '; ';
  $handler->display->display_options['fields']['field_reproductive_history']['link_to_entity'] = 1;
  $handler->display->display_options['fields']['field_reproductive_history']['view_mode'] = 'full';
  /* Field: Indexed Node: Social Environment */
  $handler->display->display_options['fields']['field_social_environment']['id'] = 'field_social_environment';
  $handler->display->display_options['fields']['field_social_environment']['table'] = 'search_api_index_variable_index';
  $handler->display->display_options['fields']['field_social_environment']['field'] = 'field_social_environment';
  $handler->display->display_options['fields']['field_social_environment']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_social_environment']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_social_environment']['alter']['text'] = '[field_social_environment]; ';
  $handler->display->display_options['fields']['field_social_environment']['list']['separator'] = '; ';
  $handler->display->display_options['fields']['field_social_environment']['link_to_entity'] = 1;
  $handler->display->display_options['fields']['field_social_environment']['view_mode'] = 'full';
  /* Field: Indexed Node: Sociodemographic/Socioeconomic Characteristics */
  $handler->display->display_options['fields']['field_sociodemographic_charact']['id'] = 'field_sociodemographic_charact';
  $handler->display->display_options['fields']['field_sociodemographic_charact']['table'] = 'search_api_index_variable_index';
  $handler->display->display_options['fields']['field_sociodemographic_charact']['field'] = 'field_sociodemographic_charact';
  $handler->display->display_options['fields']['field_sociodemographic_charact']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_sociodemographic_charact']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_sociodemographic_charact']['alter']['text'] = '[field_sociodemographic_charact]; ';
  $handler->display->display_options['fields']['field_sociodemographic_charact']['list']['separator'] = '; ';
  $handler->display->display_options['fields']['field_sociodemographic_charact']['link_to_entity'] = 1;
  $handler->display->display_options['fields']['field_sociodemographic_charact']['view_mode'] = 'full';
  /* Field: Indexed Node: Administrative Information */
  $handler->display->display_options['fields']['field_administrative_information']['id'] = 'field_administrative_information';
  $handler->display->display_options['fields']['field_administrative_information']['table'] = 'search_api_index_variable_index';
  $handler->display->display_options['fields']['field_administrative_information']['field'] = 'field_administrative_information';
  $handler->display->display_options['fields']['field_administrative_information']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_administrative_information']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_administrative_information']['alter']['text'] = '[field_administrative_information]; ';
  /* Field: Indexed Node: Target */
  $handler->display->display_options['fields']['field_target']['id'] = 'field_target';
  $handler->display->display_options['fields']['field_target']['table'] = 'search_api_index_variable_index';
  $handler->display->display_options['fields']['field_target']['field'] = 'field_target';
  $handler->display->display_options['fields']['field_target']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_target']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_target']['alter']['text'] = '[field_target]; ';
  $handler->display->display_options['fields']['field_target']['list']['separator'] = '; ';
  $handler->display->display_options['fields']['field_target']['link_to_entity'] = 1;
  $handler->display->display_options['fields']['field_target']['view_mode'] = 'full';
  /* Field: Indexed Node: The main body text */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'search_api_index_variable_index';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = 'Description';
  $handler->display->display_options['fields']['body']['type'] = 'text_trimmed';
  $handler->display->display_options['fields']['body']['settings'] = array(
    'trim_length' => '200',
  );
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = 'Domains';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '[field_anthropometric_structures][field_body_functions][field_body_structures][field_medical_health_interv][field_medication][field_data_source][field_disease_history][field_laboratory_measures][field_life_habits_behaviours][field_early_life][field_perception_of_health][field_physical_environment][field_reproductive_history][field_social_environment][field_sociodemographic_charact][field_target][field_administrative_information]';
  $handler->display->display_options['fields']['nothing']['alter']['max_length'] = '400';
  $handler->display->display_options['fields']['nothing']['alter']['more_link_text'] = 'more';
  $handler->display->display_options['fields']['nothing']['element_wrapper_class'] = 'tooltip';
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = '';
  $handler->display->display_options['fields']['edit_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['edit_node']['text'] = 'Edit';
  /* Sort criterion: Indexed Node: Position index */
  $handler->display->display_options['sorts']['field_position']['id'] = 'field_position';
  $handler->display->display_options['sorts']['field_position']['table'] = 'search_api_index_variable_index';
  $handler->display->display_options['sorts']['field_position']['field'] = 'field_position';
  /* Contextual filter: Dataset: Node ID (indexed) */
  $handler->display->display_options['arguments']['field_dataset_nid']['id'] = 'field_dataset_nid';
  $handler->display->display_options['arguments']['field_dataset_nid']['table'] = 'search_api_index_variable_index';
  $handler->display->display_options['arguments']['field_dataset_nid']['field'] = 'field_dataset_nid';
  $handler->display->display_options['arguments']['field_dataset_nid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_dataset_nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_dataset_nid']['summary_options']['override'] = TRUE;
  $handler->display->display_options['arguments']['field_dataset_nid']['break_phrase'] = 1;
  /* Filter criterion: Search: Fulltext search */
  $handler->display->display_options['filters']['search_api_views_fulltext']['id'] = 'search_api_views_fulltext';
  $handler->display->display_options['filters']['search_api_views_fulltext']['table'] = 'search_api_index_variable_index';
  $handler->display->display_options['filters']['search_api_views_fulltext']['field'] = 'search_api_views_fulltext';
  $handler->display->display_options['filters']['search_api_views_fulltext']['exposed'] = TRUE;
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['operator_id'] = 'search_api_views_fulltext_op';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['label'] = 'Fulltext search';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['operator'] = 'search_api_views_fulltext_op';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['identifier'] = 'search_api_views_fulltext';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    6 => 0,
    5 => 0,
    7 => 0,
    8 => 0,
    10 => 0,
    9 => 0,
  );
  $handler->display->display_options['filters']['search_api_views_fulltext']['group_info']['label'] = 'Fulltext search';
  $handler->display->display_options['filters']['search_api_views_fulltext']['group_info']['identifier'] = 'search_api_views_fulltext';
  $handler->display->display_options['filters']['search_api_views_fulltext']['group_info']['remember'] = FALSE;
  $handler->display->display_options['filters']['search_api_views_fulltext']['group_info']['group_items'] = array(
    1 => array(),
    2 => array(),
    3 => array(),
  );
  $handler->display->display_options['filters']['search_api_views_fulltext']['fields'] = array(
    'search_api_aggregation_1' => 'search_api_aggregation_1',
    'body:value' => 'body:value',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['path'] = 'variables-dimensions';
  $handler->display->display_options['menu']['title'] = 'Variable Domains';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'main-menu';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: Variables Domains CSV */
  $handler = $view->new_display('views_data_export', 'Variables Domains CSV', 'views_data_export_1');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_data_export_csv';
  $handler->display->display_options['style_options']['provide_file'] = 1;
  $handler->display->display_options['style_options']['parent_sort'] = 0;
  $handler->display->display_options['style_options']['quote'] = 1;
  $handler->display->display_options['style_options']['trim'] = 0;
  $handler->display->display_options['style_options']['replace_newlines'] = 0;
  $handler->display->display_options['style_options']['header'] = 1;
  $handler->display->display_options['style_options']['keep_html'] = 0;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Indexed Node: Node ID */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'search_api_index_variable_index';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['separator'] = '';
  $handler->display->display_options['fields']['nid']['link_to_entity'] = 0;
  /* Field: Indexed Node: Title */
  $handler->display->display_options['fields']['title_field']['id'] = 'title_field';
  $handler->display->display_options['fields']['title_field']['table'] = 'search_api_index_variable_index';
  $handler->display->display_options['fields']['title_field']['field'] = 'title_field';
  /* Field: Indexed Node: Label */
  $handler->display->display_options['fields']['field_label']['id'] = 'field_label';
  $handler->display->display_options['fields']['field_label']['table'] = 'search_api_index_variable_index';
  $handler->display->display_options['fields']['field_label']['field'] = 'field_label';
  /* Field: Indexed Node: Anthropometric Structures */
  $handler->display->display_options['fields']['field_anthropometric_structures']['id'] = 'field_anthropometric_structures';
  $handler->display->display_options['fields']['field_anthropometric_structures']['table'] = 'search_api_index_variable_index';
  $handler->display->display_options['fields']['field_anthropometric_structures']['field'] = 'field_anthropometric_structures';
  $handler->display->display_options['fields']['field_anthropometric_structures']['label'] = 'anthropometric_structures';
  $handler->display->display_options['fields']['field_anthropometric_structures']['alter']['text'] = '[field_anthropometric_structures]';
  $handler->display->display_options['fields']['field_anthropometric_structures']['alter']['max_length'] = '100';
  $handler->display->display_options['fields']['field_anthropometric_structures']['list']['separator'] = '|';
  $handler->display->display_options['fields']['field_anthropometric_structures']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['field_anthropometric_structures']['view_mode'] = 'full';
  /* Field: Indexed Node: Body Functions */
  $handler->display->display_options['fields']['field_body_functions']['id'] = 'field_body_functions';
  $handler->display->display_options['fields']['field_body_functions']['table'] = 'search_api_index_variable_index';
  $handler->display->display_options['fields']['field_body_functions']['field'] = 'field_body_functions';
  $handler->display->display_options['fields']['field_body_functions']['label'] = 'body_functions';
  $handler->display->display_options['fields']['field_body_functions']['alter']['text'] = '[field_body_functions]';
  $handler->display->display_options['fields']['field_body_functions']['list']['separator'] = '|';
  $handler->display->display_options['fields']['field_body_functions']['link_to_entity'] = 1;
  $handler->display->display_options['fields']['field_body_functions']['view_mode'] = 'full';
  /* Field: Indexed Node: Body Structures */
  $handler->display->display_options['fields']['field_body_structures']['id'] = 'field_body_structures';
  $handler->display->display_options['fields']['field_body_structures']['table'] = 'search_api_index_variable_index';
  $handler->display->display_options['fields']['field_body_structures']['field'] = 'field_body_structures';
  $handler->display->display_options['fields']['field_body_structures']['label'] = 'body_structures';
  $handler->display->display_options['fields']['field_body_structures']['alter']['text'] = '[field_body_structures],';
  $handler->display->display_options['fields']['field_body_structures']['list']['separator'] = '|';
  $handler->display->display_options['fields']['field_body_structures']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['field_body_structures']['view_mode'] = 'full';
  /* Field: Indexed Node: Data Source */
  $handler->display->display_options['fields']['field_data_source']['id'] = 'field_data_source';
  $handler->display->display_options['fields']['field_data_source']['table'] = 'search_api_index_variable_index';
  $handler->display->display_options['fields']['field_data_source']['field'] = 'field_data_source';
  $handler->display->display_options['fields']['field_data_source']['label'] = 'data_source';
  $handler->display->display_options['fields']['field_data_source']['alter']['text'] = '[field_data_source],';
  $handler->display->display_options['fields']['field_data_source']['list']['separator'] = '|';
  $handler->display->display_options['fields']['field_data_source']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['field_data_source']['view_mode'] = 'full';
  /* Field: Indexed Node: Diseases History and Related Health Problems */
  $handler->display->display_options['fields']['field_disease_history']['id'] = 'field_disease_history';
  $handler->display->display_options['fields']['field_disease_history']['table'] = 'search_api_index_variable_index';
  $handler->display->display_options['fields']['field_disease_history']['field'] = 'field_disease_history';
  $handler->display->display_options['fields']['field_disease_history']['label'] = 'disease_history';
  $handler->display->display_options['fields']['field_disease_history']['alter']['text'] = '[field_disease_history],';
  $handler->display->display_options['fields']['field_disease_history']['list']['separator'] = '|';
  $handler->display->display_options['fields']['field_disease_history']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['field_disease_history']['view_mode'] = 'full';
  /* Field: Indexed Node: Laboratory Measures */
  $handler->display->display_options['fields']['field_laboratory_measures']['id'] = 'field_laboratory_measures';
  $handler->display->display_options['fields']['field_laboratory_measures']['table'] = 'search_api_index_variable_index';
  $handler->display->display_options['fields']['field_laboratory_measures']['field'] = 'field_laboratory_measures';
  $handler->display->display_options['fields']['field_laboratory_measures']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_laboratory_measures']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_laboratory_measures']['alter']['text'] = '[field_laboratory_measures],';
  $handler->display->display_options['fields']['field_laboratory_measures']['link_to_entity'] = 1;
  $handler->display->display_options['fields']['field_laboratory_measures']['view_mode'] = 'full';
  /* Field: Indexed Node: Life Habits/Behaviours */
  $handler->display->display_options['fields']['field_life_habits_behaviours']['id'] = 'field_life_habits_behaviours';
  $handler->display->display_options['fields']['field_life_habits_behaviours']['table'] = 'search_api_index_variable_index';
  $handler->display->display_options['fields']['field_life_habits_behaviours']['field'] = 'field_life_habits_behaviours';
  $handler->display->display_options['fields']['field_life_habits_behaviours']['label'] = 'life_habits_behaviours';
  $handler->display->display_options['fields']['field_life_habits_behaviours']['alter']['text'] = '[field_life_habits_behaviours],';
  $handler->display->display_options['fields']['field_life_habits_behaviours']['list']['separator'] = '|';
  $handler->display->display_options['fields']['field_life_habits_behaviours']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['field_life_habits_behaviours']['view_mode'] = 'full';
  /* Field: Indexed Node: Medical Health Interventions/Health Services Utilization */
  $handler->display->display_options['fields']['field_medical_health_interv']['id'] = 'field_medical_health_interv';
  $handler->display->display_options['fields']['field_medical_health_interv']['table'] = 'search_api_index_variable_index';
  $handler->display->display_options['fields']['field_medical_health_interv']['field'] = 'field_medical_health_interv';
  $handler->display->display_options['fields']['field_medical_health_interv']['label'] = 'medical_health_interv';
  $handler->display->display_options['fields']['field_medical_health_interv']['alter']['text'] = '[field_medical_health_interv],';
  $handler->display->display_options['fields']['field_medical_health_interv']['list']['separator'] = '|';
  $handler->display->display_options['fields']['field_medical_health_interv']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['field_medical_health_interv']['view_mode'] = 'full';
  /* Field: Indexed Node: Medication */
  $handler->display->display_options['fields']['field_medication']['id'] = 'field_medication';
  $handler->display->display_options['fields']['field_medication']['table'] = 'search_api_index_variable_index';
  $handler->display->display_options['fields']['field_medication']['field'] = 'field_medication';
  $handler->display->display_options['fields']['field_medication']['label'] = 'medication';
  $handler->display->display_options['fields']['field_medication']['alter']['text'] = '[field_medication],';
  $handler->display->display_options['fields']['field_medication']['list']['separator'] = '|';
  $handler->display->display_options['fields']['field_medication']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['field_medication']['view_mode'] = 'full';
  /* Field: Indexed Node: Participant's Early Life/Childhood */
  $handler->display->display_options['fields']['field_early_life']['id'] = 'field_early_life';
  $handler->display->display_options['fields']['field_early_life']['table'] = 'search_api_index_variable_index';
  $handler->display->display_options['fields']['field_early_life']['field'] = 'field_early_life';
  $handler->display->display_options['fields']['field_early_life']['label'] = 'early_life';
  $handler->display->display_options['fields']['field_early_life']['alter']['text'] = '[field_early_life],';
  $handler->display->display_options['fields']['field_early_life']['list']['separator'] = '|';
  $handler->display->display_options['fields']['field_early_life']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['field_early_life']['view_mode'] = 'full';
  /* Field: Indexed Node: Perception of Health/Quality of life */
  $handler->display->display_options['fields']['field_perception_of_health']['id'] = 'field_perception_of_health';
  $handler->display->display_options['fields']['field_perception_of_health']['table'] = 'search_api_index_variable_index';
  $handler->display->display_options['fields']['field_perception_of_health']['field'] = 'field_perception_of_health';
  $handler->display->display_options['fields']['field_perception_of_health']['label'] = 'perception_of_health';
  $handler->display->display_options['fields']['field_perception_of_health']['alter']['text'] = '[field_perception_of_health],';
  $handler->display->display_options['fields']['field_perception_of_health']['list']['separator'] = '|';
  $handler->display->display_options['fields']['field_perception_of_health']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['field_perception_of_health']['view_mode'] = 'full';
  /* Field: Indexed Node: Physical Environment */
  $handler->display->display_options['fields']['field_physical_environment']['id'] = 'field_physical_environment';
  $handler->display->display_options['fields']['field_physical_environment']['table'] = 'search_api_index_variable_index';
  $handler->display->display_options['fields']['field_physical_environment']['field'] = 'field_physical_environment';
  $handler->display->display_options['fields']['field_physical_environment']['label'] = 'physical_environment';
  $handler->display->display_options['fields']['field_physical_environment']['alter']['text'] = '[field_physical_environment],';
  $handler->display->display_options['fields']['field_physical_environment']['list']['separator'] = '|';
  $handler->display->display_options['fields']['field_physical_environment']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['field_physical_environment']['view_mode'] = 'full';
  /* Field: Indexed Node: Reproductive Health and History */
  $handler->display->display_options['fields']['field_reproductive_history']['id'] = 'field_reproductive_history';
  $handler->display->display_options['fields']['field_reproductive_history']['table'] = 'search_api_index_variable_index';
  $handler->display->display_options['fields']['field_reproductive_history']['field'] = 'field_reproductive_history';
  $handler->display->display_options['fields']['field_reproductive_history']['label'] = 'reproductive_history';
  $handler->display->display_options['fields']['field_reproductive_history']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_reproductive_history']['alter']['text'] = '[field_reproductive_history],';
  $handler->display->display_options['fields']['field_reproductive_history']['list']['separator'] = '|';
  $handler->display->display_options['fields']['field_reproductive_history']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['field_reproductive_history']['view_mode'] = 'full';
  /* Field: Indexed Node: Social Environment */
  $handler->display->display_options['fields']['field_social_environment']['id'] = 'field_social_environment';
  $handler->display->display_options['fields']['field_social_environment']['table'] = 'search_api_index_variable_index';
  $handler->display->display_options['fields']['field_social_environment']['field'] = 'field_social_environment';
  $handler->display->display_options['fields']['field_social_environment']['label'] = 'social_environment';
  $handler->display->display_options['fields']['field_social_environment']['alter']['text'] = '[field_social_environment],';
  $handler->display->display_options['fields']['field_social_environment']['list']['separator'] = '|';
  $handler->display->display_options['fields']['field_social_environment']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['field_social_environment']['view_mode'] = 'full';
  /* Field: Indexed Node: Sociodemographic/Socioeconomic Characteristics */
  $handler->display->display_options['fields']['field_sociodemographic_charact']['id'] = 'field_sociodemographic_charact';
  $handler->display->display_options['fields']['field_sociodemographic_charact']['table'] = 'search_api_index_variable_index';
  $handler->display->display_options['fields']['field_sociodemographic_charact']['field'] = 'field_sociodemographic_charact';
  $handler->display->display_options['fields']['field_sociodemographic_charact']['label'] = 'sociodemographic_charact';
  $handler->display->display_options['fields']['field_sociodemographic_charact']['alter']['text'] = '[field_sociodemographic_charact],';
  $handler->display->display_options['fields']['field_sociodemographic_charact']['list']['separator'] = '|';
  $handler->display->display_options['fields']['field_sociodemographic_charact']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['field_sociodemographic_charact']['view_mode'] = 'full';
  /* Field: Indexed Node: Target */
  $handler->display->display_options['fields']['field_target']['id'] = 'field_target';
  $handler->display->display_options['fields']['field_target']['table'] = 'search_api_index_variable_index';
  $handler->display->display_options['fields']['field_target']['field'] = 'field_target';
  $handler->display->display_options['fields']['field_target']['label'] = 'target';
  $handler->display->display_options['fields']['field_target']['alter']['text'] = '[field_target],';
  $handler->display->display_options['fields']['field_target']['list']['separator'] = '|';
  $handler->display->display_options['fields']['field_target']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['field_target']['view_mode'] = 'full';
  $handler->display->display_options['path'] = 'variables-dimensions-csv';
  $handler->display->display_options['displays'] = array(
    'default' => 0,
    'page' => 0,
  );
  $export['variables_dimensions'] = $view;

  return $export;
}
