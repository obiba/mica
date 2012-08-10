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
  /* Field: Content: Please specify what other design */
  $handler->display->display_options['fields']['field_design_other_sp']['id'] = 'field_design_other_sp';
  $handler->display->display_options['fields']['field_design_other_sp']['table'] = 'field_data_field_design_other_sp';
  $handler->display->display_options['fields']['field_design_other_sp']['field'] = 'field_design_other_sp';
  $handler->display->display_options['fields']['field_design_other_sp']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_design_other_sp']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_design_other_sp']['alter']['text'] = '([field_design_other_sp])';
  $handler->display->display_options['fields']['field_design_other_sp']['alter']['max_length'] = '60';
  $handler->display->display_options['fields']['field_design_other_sp']['alter']['trim'] = TRUE;
  /* Field: Content: What is the study design? */
  $handler->display->display_options['fields']['field_design']['id'] = 'field_design';
  $handler->display->display_options['fields']['field_design']['table'] = 'field_data_field_design';
  $handler->display->display_options['fields']['field_design']['field'] = 'field_design';
  $handler->display->display_options['fields']['field_design']['label'] = 'Study design';
  $handler->display->display_options['fields']['field_design']['alter']['text'] = '[field_design] [field_design_other_sp] ';
  $handler->display->display_options['fields']['field_design']['delta_offset'] = '0';
  /* Field: Content: How many people are planned to be recruited? Or if the study is completed, what is the final number of participants? */
  $handler->display->display_options['fields']['field_target_number_participants']['id'] = 'field_target_number_participants';
  $handler->display->display_options['fields']['field_target_number_participants']['table'] = 'field_data_field_target_number_participants';
  $handler->display->display_options['fields']['field_target_number_participants']['field'] = 'field_target_number_participants';
  $handler->display->display_options['fields']['field_target_number_participants']['label'] = 'Target number of participants';
  $handler->display->display_options['fields']['field_target_number_participants']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Country of residence */
  $handler->display->display_options['fields']['field_country']['id'] = 'field_country';
  $handler->display->display_options['fields']['field_country']['table'] = 'field_data_field_country';
  $handler->display->display_options['fields']['field_country']['field'] = 'field_country';
  $handler->display->display_options['fields']['field_country']['delta_offset'] = '0';
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
  /* Field: Content: Period */
  $handler->display->display_options['fields']['field_period']['id'] = 'field_period';
  $handler->display->display_options['fields']['field_period']['table'] = 'field_data_field_period';
  $handler->display->display_options['fields']['field_period']['field'] = 'field_period';
  $handler->display->display_options['fields']['field_period']['label'] = 'period';
  $handler->display->display_options['fields']['field_period']['type'] = 'taxonomy_term_reference_plain';
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
  /* Field: Content: Individual Participant Measures */
  $handler->display->display_options['fields']['field_individual_participant_mea']['id'] = 'field_individual_participant_mea';
  $handler->display->display_options['fields']['field_individual_participant_mea']['table'] = 'field_data_field_individual_participant_mea';
  $handler->display->display_options['fields']['field_individual_participant_mea']['field'] = 'field_individual_participant_mea';
  $handler->display->display_options['fields']['field_individual_participant_mea']['label'] = 'individual_participant_measures';
  $handler->display->display_options['fields']['field_individual_participant_mea']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Content: Laboratory Measures */
  $handler->display->display_options['fields']['field_laboratory_measures']['id'] = 'field_laboratory_measures';
  $handler->display->display_options['fields']['field_laboratory_measures']['table'] = 'field_data_field_laboratory_measures';
  $handler->display->display_options['fields']['field_laboratory_measures']['field'] = 'field_laboratory_measures';
  $handler->display->display_options['fields']['field_laboratory_measures']['label'] = 'laboratory_measures';
  $handler->display->display_options['fields']['field_laboratory_measures']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_laboratory_measures']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_laboratory_measures']['separator'] = '|';
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

  /* Display: Data export */
  $handler = $view->new_display('views_data_export', 'Data export', 'views_data_export_2');
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
  $handler->display->display_options['path'] = 'variable-csv-html';
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
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '20';
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
  $handler->display->display_options['filters']['search_api_views_fulltext']['fields'] = array(
    'search_api_aggregation_1' => 'search_api_aggregation_1',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['path'] = 'variable-search';

  /* Display: Export XLS */
  $handler = $view->new_display('views_data_export', 'Export XLS', 'views_data_export_1');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_data_export_xls';
  $handler->display->display_options['style_options']['provide_file'] = 1;
  $handler->display->display_options['style_options']['filename'] = '%view-%timestamp-yyyy%timestamp-mm%timestamp-dd%timestamp-hh%timestamp-ii%timestamp-ss.xls';
  $handler->display->display_options['style_options']['parent_sort'] = 1;
  $handler->display->display_options['defaults']['fields'] = FALSE;
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
  /* Field: Indexed Node: Categories */
  $handler->display->display_options['fields']['field_variable_categories']['id'] = 'field_variable_categories';
  $handler->display->display_options['fields']['field_variable_categories']['table'] = 'search_api_index_variable_index';
  $handler->display->display_options['fields']['field_variable_categories']['field'] = 'field_variable_categories';
  $handler->display->display_options['fields']['field_variable_categories']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_variable_categories']['alter']['text'] = 'Label:[field_variable_categories-label] Name: [field_variable_categories-name] Missing:[field_variable_categories-missing]';
  $handler->display->display_options['fields']['field_variable_categories']['click_sort_column'] = 'name';
  $handler->display->display_options['fields']['field_variable_categories']['type'] = 'category_field_key_formatter';
  $handler->display->display_options['fields']['field_variable_categories']['delta_offset'] = '0';
  /* Field: Indexed Node: Dataset */
  $handler->display->display_options['fields']['field_dataset']['id'] = 'field_dataset';
  $handler->display->display_options['fields']['field_dataset']['table'] = 'search_api_index_variable_index';
  $handler->display->display_options['fields']['field_dataset']['field'] = 'field_dataset';
  $handler->display->display_options['fields']['field_dataset']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['field_dataset']['view_mode'] = 'full';
  /* Field: Indexed Node: Data Source */
  $handler->display->display_options['fields']['field_data_source']['id'] = 'field_data_source';
  $handler->display->display_options['fields']['field_data_source']['table'] = 'search_api_index_variable_index';
  $handler->display->display_options['fields']['field_data_source']['field'] = 'field_data_source';
  $handler->display->display_options['fields']['field_data_source']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['field_data_source']['view_mode'] = 'full';
  /* Field: Indexed Node: Diseases History and Related Health Problems */
  $handler->display->display_options['fields']['field_disease_history']['id'] = 'field_disease_history';
  $handler->display->display_options['fields']['field_disease_history']['table'] = 'search_api_index_variable_index';
  $handler->display->display_options['fields']['field_disease_history']['field'] = 'field_disease_history';
  $handler->display->display_options['fields']['field_disease_history']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['field_disease_history']['view_mode'] = 'full';
  /* Field: Indexed Node: Medical Health Interventions/Health Services Utilization */
  $handler->display->display_options['fields']['field_medical_health_interv']['id'] = 'field_medical_health_interv';
  $handler->display->display_options['fields']['field_medical_health_interv']['table'] = 'search_api_index_variable_index';
  $handler->display->display_options['fields']['field_medical_health_interv']['field'] = 'field_medical_health_interv';
  $handler->display->display_options['fields']['field_medical_health_interv']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['field_medical_health_interv']['view_mode'] = 'full';
  /* Field: Indexed Node: Medication */
  $handler->display->display_options['fields']['field_medication']['id'] = 'field_medication';
  $handler->display->display_options['fields']['field_medication']['table'] = 'search_api_index_variable_index';
  $handler->display->display_options['fields']['field_medication']['field'] = 'field_medication';
  $handler->display->display_options['fields']['field_medication']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['field_medication']['view_mode'] = 'full';
  /* Field: Indexed Node: Reproductive Health and History */
  $handler->display->display_options['fields']['field_reproductive_history']['id'] = 'field_reproductive_history';
  $handler->display->display_options['fields']['field_reproductive_history']['table'] = 'search_api_index_variable_index';
  $handler->display->display_options['fields']['field_reproductive_history']['field'] = 'field_reproductive_history';
  $handler->display->display_options['fields']['field_reproductive_history']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['field_reproductive_history']['view_mode'] = 'full';
  /* Field: Indexed Node: Participant's Early Life/Childhood */
  $handler->display->display_options['fields']['field_early_life']['id'] = 'field_early_life';
  $handler->display->display_options['fields']['field_early_life']['table'] = 'search_api_index_variable_index';
  $handler->display->display_options['fields']['field_early_life']['field'] = 'field_early_life';
  $handler->display->display_options['fields']['field_early_life']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['field_early_life']['view_mode'] = 'full';
  /* Field: Indexed Node: Life Habits/Behaviours */
  $handler->display->display_options['fields']['field_life_habits_behaviours']['id'] = 'field_life_habits_behaviours';
  $handler->display->display_options['fields']['field_life_habits_behaviours']['table'] = 'search_api_index_variable_index';
  $handler->display->display_options['fields']['field_life_habits_behaviours']['field'] = 'field_life_habits_behaviours';
  $handler->display->display_options['fields']['field_life_habits_behaviours']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['field_life_habits_behaviours']['view_mode'] = 'full';
  /* Field: Indexed Node: Sociodemographic/Socioeconomic Characteristics */
  $handler->display->display_options['fields']['field_sociodemographic_charact']['id'] = 'field_sociodemographic_charact';
  $handler->display->display_options['fields']['field_sociodemographic_charact']['table'] = 'search_api_index_variable_index';
  $handler->display->display_options['fields']['field_sociodemographic_charact']['field'] = 'field_sociodemographic_charact';
  $handler->display->display_options['fields']['field_sociodemographic_charact']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['field_sociodemographic_charact']['view_mode'] = 'full';
  /* Field: Indexed Node: Physical Environment */
  $handler->display->display_options['fields']['field_physical_environment']['id'] = 'field_physical_environment';
  $handler->display->display_options['fields']['field_physical_environment']['table'] = 'search_api_index_variable_index';
  $handler->display->display_options['fields']['field_physical_environment']['field'] = 'field_physical_environment';
  $handler->display->display_options['fields']['field_physical_environment']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['field_physical_environment']['view_mode'] = 'full';
  /* Field: Indexed Node: Social Environment */
  $handler->display->display_options['fields']['field_social_environment']['id'] = 'field_social_environment';
  $handler->display->display_options['fields']['field_social_environment']['table'] = 'search_api_index_variable_index';
  $handler->display->display_options['fields']['field_social_environment']['field'] = 'field_social_environment';
  $handler->display->display_options['fields']['field_social_environment']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['field_social_environment']['view_mode'] = 'full';
  /* Field: Indexed Node: Perception of Health/Quality of life */
  $handler->display->display_options['fields']['field_perception_of_health']['id'] = 'field_perception_of_health';
  $handler->display->display_options['fields']['field_perception_of_health']['table'] = 'search_api_index_variable_index';
  $handler->display->display_options['fields']['field_perception_of_health']['field'] = 'field_perception_of_health';
  $handler->display->display_options['fields']['field_perception_of_health']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['field_perception_of_health']['view_mode'] = 'full';
  /* Field: Indexed Node: Anthropometric Structures */
  $handler->display->display_options['fields']['field_anthropometric_structures']['id'] = 'field_anthropometric_structures';
  $handler->display->display_options['fields']['field_anthropometric_structures']['table'] = 'search_api_index_variable_index';
  $handler->display->display_options['fields']['field_anthropometric_structures']['field'] = 'field_anthropometric_structures';
  $handler->display->display_options['fields']['field_anthropometric_structures']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['field_anthropometric_structures']['view_mode'] = 'full';
  /* Field: Indexed Node: Body Structures */
  $handler->display->display_options['fields']['field_body_structures']['id'] = 'field_body_structures';
  $handler->display->display_options['fields']['field_body_structures']['table'] = 'search_api_index_variable_index';
  $handler->display->display_options['fields']['field_body_structures']['field'] = 'field_body_structures';
  $handler->display->display_options['fields']['field_body_structures']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['field_body_structures']['view_mode'] = 'full';
  /* Field: Indexed Node: Body Functions */
  $handler->display->display_options['fields']['field_body_functions']['id'] = 'field_body_functions';
  $handler->display->display_options['fields']['field_body_functions']['table'] = 'search_api_index_variable_index';
  $handler->display->display_options['fields']['field_body_functions']['field'] = 'field_body_functions';
  $handler->display->display_options['fields']['field_body_functions']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['field_body_functions']['view_mode'] = 'full';
  /* Field: Indexed Node: Essence */
  $handler->display->display_options['fields']['field_essence']['id'] = 'field_essence';
  $handler->display->display_options['fields']['field_essence']['table'] = 'search_api_index_variable_index';
  $handler->display->display_options['fields']['field_essence']['field'] = 'field_essence';
  $handler->display->display_options['fields']['field_essence']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['field_essence']['view_mode'] = 'full';
  /* Field: Indexed Node: Target */
  $handler->display->display_options['fields']['field_target']['id'] = 'field_target';
  $handler->display->display_options['fields']['field_target']['table'] = 'search_api_index_variable_index';
  $handler->display->display_options['fields']['field_target']['field'] = 'field_target';
  $handler->display->display_options['fields']['field_target']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['field_target']['view_mode'] = 'full';
  /* Field: Indexed Node: Period */
  $handler->display->display_options['fields']['field_period']['id'] = 'field_period';
  $handler->display->display_options['fields']['field_period']['table'] = 'search_api_index_variable_index';
  $handler->display->display_options['fields']['field_period']['field'] = 'field_period';
  $handler->display->display_options['fields']['field_period']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['field_period']['view_mode'] = 'full';
  /* Field: Indexed Node: Measure */
  $handler->display->display_options['fields']['field_measure']['id'] = 'field_measure';
  $handler->display->display_options['fields']['field_measure']['table'] = 'search_api_index_variable_index';
  $handler->display->display_options['fields']['field_measure']['field'] = 'field_measure';
  $handler->display->display_options['fields']['field_measure']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['field_measure']['view_mode'] = 'full';
  /* Field: Indexed Node: Value Type */
  $handler->display->display_options['fields']['field_value_type']['id'] = 'field_value_type';
  $handler->display->display_options['fields']['field_value_type']['table'] = 'search_api_index_variable_index';
  $handler->display->display_options['fields']['field_value_type']['field'] = 'field_value_type';
  $handler->display->display_options['fields']['field_value_type']['type'] = 'list_key';
  /* Field: Indexed Node: Repeatable */
  $handler->display->display_options['fields']['field_repeatable']['id'] = 'field_repeatable';
  $handler->display->display_options['fields']['field_repeatable']['table'] = 'search_api_index_variable_index';
  $handler->display->display_options['fields']['field_repeatable']['field'] = 'field_repeatable';
  $handler->display->display_options['fields']['field_repeatable']['type'] = 'list_key';
  $handler->display->display_options['path'] = 'variables-search-xls';
  $handler->display->display_options['displays'] = array(
    'default' => 'default',
    'page' => 'page',
  );
  $handler->display->display_options['use_batch'] = '0';

  /* Display: Export CSV */
  $handler = $view->new_display('views_data_export', 'Export CSV', 'views_data_export_2');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_data_export_csv';
  $handler->display->display_options['style_options']['provide_file'] = 1;
  $handler->display->display_options['style_options']['filename'] = '%view-%timestamp-yyyy%timestamp-mm%timestamp-dd%timestamp-hh%timestamp-ii%timestamp-ss.csv';
  $handler->display->display_options['style_options']['parent_sort'] = 0;
  $handler->display->display_options['style_options']['quote'] = 1;
  $handler->display->display_options['style_options']['trim'] = 0;
  $handler->display->display_options['style_options']['replace_newlines'] = 0;
  $handler->display->display_options['style_options']['header'] = 1;
  $handler->display->display_options['defaults']['fields'] = FALSE;
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
  /* Field: Indexed Node: Categories */
  $handler->display->display_options['fields']['field_variable_categories']['id'] = 'field_variable_categories';
  $handler->display->display_options['fields']['field_variable_categories']['table'] = 'search_api_index_variable_index';
  $handler->display->display_options['fields']['field_variable_categories']['field'] = 'field_variable_categories';
  $handler->display->display_options['fields']['field_variable_categories']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_variable_categories']['alter']['text'] = 'Label:[field_variable_categories-label] Name: [field_variable_categories-name] Missing:[field_variable_categories-missing]';
  $handler->display->display_options['fields']['field_variable_categories']['click_sort_column'] = 'name';
  $handler->display->display_options['fields']['field_variable_categories']['type'] = 'category_field_key_formatter';
  $handler->display->display_options['fields']['field_variable_categories']['delta_offset'] = '0';
  /* Field: Indexed Node: Dataset */
  $handler->display->display_options['fields']['field_dataset']['id'] = 'field_dataset';
  $handler->display->display_options['fields']['field_dataset']['table'] = 'search_api_index_variable_index';
  $handler->display->display_options['fields']['field_dataset']['field'] = 'field_dataset';
  $handler->display->display_options['fields']['field_dataset']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['field_dataset']['view_mode'] = 'full';
  /* Field: Indexed Node: Data Source */
  $handler->display->display_options['fields']['field_data_source']['id'] = 'field_data_source';
  $handler->display->display_options['fields']['field_data_source']['table'] = 'search_api_index_variable_index';
  $handler->display->display_options['fields']['field_data_source']['field'] = 'field_data_source';
  $handler->display->display_options['fields']['field_data_source']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['field_data_source']['view_mode'] = 'full';
  /* Field: Indexed Node: Diseases History and Related Health Problems */
  $handler->display->display_options['fields']['field_disease_history']['id'] = 'field_disease_history';
  $handler->display->display_options['fields']['field_disease_history']['table'] = 'search_api_index_variable_index';
  $handler->display->display_options['fields']['field_disease_history']['field'] = 'field_disease_history';
  $handler->display->display_options['fields']['field_disease_history']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['field_disease_history']['view_mode'] = 'full';
  /* Field: Indexed Node: Medical Health Interventions/Health Services Utilization */
  $handler->display->display_options['fields']['field_medical_health_interv']['id'] = 'field_medical_health_interv';
  $handler->display->display_options['fields']['field_medical_health_interv']['table'] = 'search_api_index_variable_index';
  $handler->display->display_options['fields']['field_medical_health_interv']['field'] = 'field_medical_health_interv';
  $handler->display->display_options['fields']['field_medical_health_interv']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['field_medical_health_interv']['view_mode'] = 'full';
  /* Field: Indexed Node: Medication */
  $handler->display->display_options['fields']['field_medication']['id'] = 'field_medication';
  $handler->display->display_options['fields']['field_medication']['table'] = 'search_api_index_variable_index';
  $handler->display->display_options['fields']['field_medication']['field'] = 'field_medication';
  $handler->display->display_options['fields']['field_medication']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['field_medication']['view_mode'] = 'full';
  /* Field: Indexed Node: Reproductive Health and History */
  $handler->display->display_options['fields']['field_reproductive_history']['id'] = 'field_reproductive_history';
  $handler->display->display_options['fields']['field_reproductive_history']['table'] = 'search_api_index_variable_index';
  $handler->display->display_options['fields']['field_reproductive_history']['field'] = 'field_reproductive_history';
  $handler->display->display_options['fields']['field_reproductive_history']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['field_reproductive_history']['view_mode'] = 'full';
  /* Field: Indexed Node: Participant's Early Life/Childhood */
  $handler->display->display_options['fields']['field_early_life']['id'] = 'field_early_life';
  $handler->display->display_options['fields']['field_early_life']['table'] = 'search_api_index_variable_index';
  $handler->display->display_options['fields']['field_early_life']['field'] = 'field_early_life';
  $handler->display->display_options['fields']['field_early_life']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['field_early_life']['view_mode'] = 'full';
  /* Field: Indexed Node: Life Habits/Behaviours */
  $handler->display->display_options['fields']['field_life_habits_behaviours']['id'] = 'field_life_habits_behaviours';
  $handler->display->display_options['fields']['field_life_habits_behaviours']['table'] = 'search_api_index_variable_index';
  $handler->display->display_options['fields']['field_life_habits_behaviours']['field'] = 'field_life_habits_behaviours';
  $handler->display->display_options['fields']['field_life_habits_behaviours']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['field_life_habits_behaviours']['view_mode'] = 'full';
  /* Field: Indexed Node: Sociodemographic/Socioeconomic Characteristics */
  $handler->display->display_options['fields']['field_sociodemographic_charact']['id'] = 'field_sociodemographic_charact';
  $handler->display->display_options['fields']['field_sociodemographic_charact']['table'] = 'search_api_index_variable_index';
  $handler->display->display_options['fields']['field_sociodemographic_charact']['field'] = 'field_sociodemographic_charact';
  $handler->display->display_options['fields']['field_sociodemographic_charact']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['field_sociodemographic_charact']['view_mode'] = 'full';
  /* Field: Indexed Node: Physical Environment */
  $handler->display->display_options['fields']['field_physical_environment']['id'] = 'field_physical_environment';
  $handler->display->display_options['fields']['field_physical_environment']['table'] = 'search_api_index_variable_index';
  $handler->display->display_options['fields']['field_physical_environment']['field'] = 'field_physical_environment';
  $handler->display->display_options['fields']['field_physical_environment']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['field_physical_environment']['view_mode'] = 'full';
  /* Field: Indexed Node: Social Environment */
  $handler->display->display_options['fields']['field_social_environment']['id'] = 'field_social_environment';
  $handler->display->display_options['fields']['field_social_environment']['table'] = 'search_api_index_variable_index';
  $handler->display->display_options['fields']['field_social_environment']['field'] = 'field_social_environment';
  $handler->display->display_options['fields']['field_social_environment']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['field_social_environment']['view_mode'] = 'full';
  /* Field: Indexed Node: Perception of Health/Quality of life */
  $handler->display->display_options['fields']['field_perception_of_health']['id'] = 'field_perception_of_health';
  $handler->display->display_options['fields']['field_perception_of_health']['table'] = 'search_api_index_variable_index';
  $handler->display->display_options['fields']['field_perception_of_health']['field'] = 'field_perception_of_health';
  $handler->display->display_options['fields']['field_perception_of_health']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['field_perception_of_health']['view_mode'] = 'full';
  /* Field: Indexed Node: Anthropometric Structures */
  $handler->display->display_options['fields']['field_anthropometric_structures']['id'] = 'field_anthropometric_structures';
  $handler->display->display_options['fields']['field_anthropometric_structures']['table'] = 'search_api_index_variable_index';
  $handler->display->display_options['fields']['field_anthropometric_structures']['field'] = 'field_anthropometric_structures';
  $handler->display->display_options['fields']['field_anthropometric_structures']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['field_anthropometric_structures']['view_mode'] = 'full';
  /* Field: Indexed Node: Body Structures */
  $handler->display->display_options['fields']['field_body_structures']['id'] = 'field_body_structures';
  $handler->display->display_options['fields']['field_body_structures']['table'] = 'search_api_index_variable_index';
  $handler->display->display_options['fields']['field_body_structures']['field'] = 'field_body_structures';
  $handler->display->display_options['fields']['field_body_structures']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['field_body_structures']['view_mode'] = 'full';
  /* Field: Indexed Node: Body Functions */
  $handler->display->display_options['fields']['field_body_functions']['id'] = 'field_body_functions';
  $handler->display->display_options['fields']['field_body_functions']['table'] = 'search_api_index_variable_index';
  $handler->display->display_options['fields']['field_body_functions']['field'] = 'field_body_functions';
  $handler->display->display_options['fields']['field_body_functions']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['field_body_functions']['view_mode'] = 'full';
  /* Field: Indexed Node: Essence */
  $handler->display->display_options['fields']['field_essence']['id'] = 'field_essence';
  $handler->display->display_options['fields']['field_essence']['table'] = 'search_api_index_variable_index';
  $handler->display->display_options['fields']['field_essence']['field'] = 'field_essence';
  $handler->display->display_options['fields']['field_essence']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['field_essence']['view_mode'] = 'full';
  /* Field: Indexed Node: Target */
  $handler->display->display_options['fields']['field_target']['id'] = 'field_target';
  $handler->display->display_options['fields']['field_target']['table'] = 'search_api_index_variable_index';
  $handler->display->display_options['fields']['field_target']['field'] = 'field_target';
  $handler->display->display_options['fields']['field_target']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['field_target']['view_mode'] = 'full';
  /* Field: Indexed Node: Period */
  $handler->display->display_options['fields']['field_period']['id'] = 'field_period';
  $handler->display->display_options['fields']['field_period']['table'] = 'search_api_index_variable_index';
  $handler->display->display_options['fields']['field_period']['field'] = 'field_period';
  $handler->display->display_options['fields']['field_period']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['field_period']['view_mode'] = 'full';
  /* Field: Indexed Node: Measure */
  $handler->display->display_options['fields']['field_measure']['id'] = 'field_measure';
  $handler->display->display_options['fields']['field_measure']['table'] = 'search_api_index_variable_index';
  $handler->display->display_options['fields']['field_measure']['field'] = 'field_measure';
  $handler->display->display_options['fields']['field_measure']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['field_measure']['view_mode'] = 'full';
  /* Field: Indexed Node: Value Type */
  $handler->display->display_options['fields']['field_value_type']['id'] = 'field_value_type';
  $handler->display->display_options['fields']['field_value_type']['table'] = 'search_api_index_variable_index';
  $handler->display->display_options['fields']['field_value_type']['field'] = 'field_value_type';
  $handler->display->display_options['fields']['field_value_type']['type'] = 'list_key';
  /* Field: Indexed Node: Repeatable */
  $handler->display->display_options['fields']['field_repeatable']['id'] = 'field_repeatable';
  $handler->display->display_options['fields']['field_repeatable']['table'] = 'search_api_index_variable_index';
  $handler->display->display_options['fields']['field_repeatable']['field'] = 'field_repeatable';
  $handler->display->display_options['fields']['field_repeatable']['type'] = 'list_key';
  $handler->display->display_options['path'] = 'variables-search-csv';
  $handler->display->display_options['displays'] = array(
    'default' => 'default',
    'page' => 'page',
  );
  $handler->display->display_options['use_batch'] = '0';
  $export['variable_search'] = $view;

  return $export;
}
