<?php
/**
 * @file
 * mica_datasets.views_default.inc
 */

/**
 * Implementation of hook_views_default_views().
 */
function mica_datasets_views_default_views() {
  $export = array();

  $view = new view;
  $view->name = 'dataset_participant_variables';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Dataset Participant Variables';
  $view->core = 7;
  $view->api_version = '3.0-alpha1';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Participant Variables';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all'] = 0;
  $handler->display->display_options['style_plugin'] = 'table';
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['label'] = 'empty_dataset_participant_variables';
  $handler->display->display_options['empty']['area']['empty'] = FALSE;
  $handler->display->display_options['empty']['area']['content'] = 'No variables found.';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Name';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title']['alter']['external'] = 0;
  $handler->display->display_options['fields']['title']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 0;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 0;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['title']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['link_to_node'] = 1;
  /* Field: Content: Label */
  $handler->display->display_options['fields']['field_label']['id'] = 'field_label';
  $handler->display->display_options['fields']['field_label']['table'] = 'field_data_field_label';
  $handler->display->display_options['fields']['field_label']['field'] = 'field_label';
  $handler->display->display_options['fields']['field_label']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_label']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_label']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_label']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_label']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_label']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_label']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_label']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_label']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_label']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_label']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_label']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_label']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_label']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_label']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_label']['field_api_classes'] = 0;
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  /* Contextual filter: Fields: Dataset (field_dataset) - nid */
  $handler->display->display_options['arguments']['field_dataset_nid']['id'] = 'field_dataset_nid';
  $handler->display->display_options['arguments']['field_dataset_nid']['table'] = 'field_data_field_dataset';
  $handler->display->display_options['arguments']['field_dataset_nid']['field'] = 'field_dataset_nid';
  $handler->display->display_options['arguments']['field_dataset_nid']['default_action'] = 'empty';
  $handler->display->display_options['arguments']['field_dataset_nid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_dataset_nid']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['field_dataset_nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_dataset_nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_dataset_nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_dataset_nid']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['field_dataset_nid']['not'] = 0;
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
    'participant_variable' => 'participant_variable',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'dataset-participant-variables';
  $translatables['dataset_participant_variables'] = array(
    t('Master'),
    t('Participant Variables'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('empty_dataset_participant_variables'),
    t('No variables found.'),
    t('Name'),
    t('Label'),
    t('All'),
    t('Page'),
  );
  $export['dataset_participant_variables'] = $view;

  $view = new view;
  $view->name = 'dataset_studies';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Dataset Studies';
  $view->core = 7;
  $view->api_version = '3.0-alpha1';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Studies';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
    'field_full_name' => 'field_full_name',
    'field_target_number_participants' => 'field_target_number_participants',
    'field_study_country' => 'field_study_country',
    'field_p3g_observatory_link' => 'field_p3g_observatory_link',
  );
  $handler->display->display_options['style_options']['default'] = 'title';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
    'field_full_name' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
    'field_target_number_participants' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
    'field_study_country' => array(
      'align' => '',
      'separator' => '',
    ),
    'field_p3g_observatory_link' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
  );
  $handler->display->display_options['style_options']['override'] = 1;
  $handler->display->display_options['style_options']['sticky'] = 0;
  $handler->display->display_options['style_options']['empty_table'] = 0;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['label'] = 'empty_dataset_studies';
  $handler->display->display_options['empty']['area']['empty'] = FALSE;
  $handler->display->display_options['empty']['area']['content'] = 'No studies found.';
  /* Relationship: Fields: Study Information (mica_study_information) - nid */
  $handler->display->display_options['relationships']['mica_study_information_nid']['id'] = 'mica_study_information_nid';
  $handler->display->display_options['relationships']['mica_study_information_nid']['table'] = 'field_data_mica_study_information';
  $handler->display->display_options['relationships']['mica_study_information_nid']['field'] = 'mica_study_information_nid';
  $handler->display->display_options['relationships']['mica_study_information_nid']['required'] = 0;
  $handler->display->display_options['relationships']['mica_study_information_nid']['delta'] = '-1';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Name';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title']['alter']['external'] = 0;
  $handler->display->display_options['fields']['title']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 0;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 0;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['title']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['link_to_node'] = 1;
  /* Field: Content: Full Name */
  $handler->display->display_options['fields']['field_full_name']['id'] = 'field_full_name';
  $handler->display->display_options['fields']['field_full_name']['table'] = 'field_data_field_full_name';
  $handler->display->display_options['fields']['field_full_name']['field'] = 'field_full_name';
  $handler->display->display_options['fields']['field_full_name']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_full_name']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_full_name']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_full_name']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_full_name']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_full_name']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_full_name']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_full_name']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_full_name']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_full_name']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_full_name']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_full_name']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_full_name']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_full_name']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_full_name']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_full_name']['field_api_classes'] = 0;
  /* Field: Content: Target number of participants */
  $handler->display->display_options['fields']['field_target_number_participants']['id'] = 'field_target_number_participants';
  $handler->display->display_options['fields']['field_target_number_participants']['table'] = 'field_data_field_target_number_participants';
  $handler->display->display_options['fields']['field_target_number_participants']['field'] = 'field_target_number_participants';
  /* Field: Content: Country selection criteria */
  $handler->display->display_options['fields']['field_study_country']['id'] = 'field_study_country';
  $handler->display->display_options['fields']['field_study_country']['table'] = 'field_data_field_study_country';
  $handler->display->display_options['fields']['field_study_country']['field'] = 'field_study_country';
  $handler->display->display_options['fields']['field_study_country']['relationship'] = 'mica_study_information_nid';
  $handler->display->display_options['fields']['field_study_country']['label'] = 'Country(ies)';
  $handler->display->display_options['fields']['field_study_country']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_study_country']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_study_country']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_study_country']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_study_country']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_study_country']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_study_country']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_study_country']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_study_country']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_study_country']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_study_country']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_study_country']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_study_country']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_study_country']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_study_country']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_study_country']['group_rows'] = 1;
  $handler->display->display_options['fields']['field_study_country']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_study_country']['delta_reversed'] = 0;
  $handler->display->display_options['fields']['field_study_country']['field_api_classes'] = 0;
  /* Field: Content: P3G Catalogue Link */
  $handler->display->display_options['fields']['field_p3g_observatory_link']['id'] = 'field_p3g_observatory_link';
  $handler->display->display_options['fields']['field_p3g_observatory_link']['table'] = 'field_data_field_p3g_observatory_link';
  $handler->display->display_options['fields']['field_p3g_observatory_link']['field'] = 'field_p3g_observatory_link';
  $handler->display->display_options['fields']['field_p3g_observatory_link']['label'] = 'P3G Catalogue';
  $handler->display->display_options['fields']['field_p3g_observatory_link']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_p3g_observatory_link']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_p3g_observatory_link']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_p3g_observatory_link']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_p3g_observatory_link']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_p3g_observatory_link']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_p3g_observatory_link']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_p3g_observatory_link']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_p3g_observatory_link']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_p3g_observatory_link']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_p3g_observatory_link']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_p3g_observatory_link']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_p3g_observatory_link']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_p3g_observatory_link']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_p3g_observatory_link']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_p3g_observatory_link']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_p3g_observatory_link']['type'] = 'short';
  $handler->display->display_options['fields']['field_p3g_observatory_link']['field_api_classes'] = 0;
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  /* Contextual filter: Fields: Datasets (mica_dataset) - nid */
  $handler->display->display_options['arguments']['mica_dataset_nid']['id'] = 'mica_dataset_nid';
  $handler->display->display_options['arguments']['mica_dataset_nid']['table'] = 'field_data_mica_dataset';
  $handler->display->display_options['arguments']['mica_dataset_nid']['field'] = 'mica_dataset_nid';
  $handler->display->display_options['arguments']['mica_dataset_nid']['default_action'] = 'empty';
  $handler->display->display_options['arguments']['mica_dataset_nid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['mica_dataset_nid']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['mica_dataset_nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['mica_dataset_nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['mica_dataset_nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['mica_dataset_nid']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['mica_dataset_nid']['not'] = 0;
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

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'dataset-studies';
  $translatables['dataset_studies'] = array(
    t('Master'),
    t('Studies'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('empty_dataset_studies'),
    t('No studies found.'),
    t('mica_study_information'),
    t('Name'),
    t('Full Name'),
    t('Target number of participants'),
    t('Country(ies)'),
    t('P3G Catalogue'),
    t('All'),
    t('Page'),
  );
  $export['dataset_studies'] = $view;

  $view = new view;
  $view->name = 'datasets';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Datasets';
  $view->core = 7;
  $view->api_version = '3.0-alpha1';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Datasets';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
    'body' => 'body',
    'field_dataschema' => 'field_dataschema',
  );
  $handler->display->display_options['style_options']['default'] = 'title';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
    'body' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
    'field_dataschema' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
  );
  $handler->display->display_options['style_options']['override'] = 1;
  $handler->display->display_options['style_options']['sticky'] = 0;
  $handler->display->display_options['style_options']['empty_table'] = 1;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['empty'] = TRUE;
  $handler->display->display_options['header']['area']['content'] = 'The consortium makes available different datasets to the research community. Each dataset is described by a comprehensive data dictionary which gives details on each available variable. Moreover, Mica includes for  studies using the OBiBa Opal software as main database solution, a distributed query engine that enables researchers to obtain real-time aggregated reports on the exact number of participant with specific characteristics or phenotypes. Mica makes even possible to run remotely some regression analyses on the real study data using the DataSHIELD method (Wolfson M et al. <i>Int J Epidemiol</i>. 2010) which is implemented both in Mica and Opal. <br/><br/>';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['label'] = 'empty_datasets';
  $handler->display->display_options['empty']['area']['empty'] = FALSE;
  $handler->display->display_options['empty']['area']['content'] = 'No dataset found.';
  $handler->display->display_options['empty']['area']['format'] = 'filtered_html';
  $handler->display->display_options['empty']['area']['tokenize'] = 0;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Name';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title']['alter']['external'] = 0;
  $handler->display->display_options['fields']['title']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 0;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 0;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['title']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['title']['link_to_node'] = 1;
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = 'Description';
  $handler->display->display_options['fields']['body']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['body']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['body']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['body']['alter']['external'] = 0;
  $handler->display->display_options['fields']['body']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['body']['alter']['trim'] = 1;
  $handler->display->display_options['fields']['body']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['body']['alter']['max_length'] = '200';
  $handler->display->display_options['fields']['body']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['body']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['body']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['body']['alter']['html'] = 1;
  $handler->display->display_options['fields']['body']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['body']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['body']['hide_empty'] = 0;
  $handler->display->display_options['fields']['body']['empty_zero'] = 0;
  $handler->display->display_options['fields']['body']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['body']['field_api_classes'] = 0;
  /* Field: Content: Dataschema */
  $handler->display->display_options['fields']['field_dataschema']['id'] = 'field_dataschema';
  $handler->display->display_options['fields']['field_dataschema']['table'] = 'field_data_field_dataschema';
  $handler->display->display_options['fields']['field_dataschema']['field'] = 'field_dataschema';
  $handler->display->display_options['fields']['field_dataschema']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_dataschema']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_dataschema']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_dataschema']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_dataschema']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_dataschema']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_dataschema']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_dataschema']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_dataschema']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_dataschema']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_dataschema']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_dataschema']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_dataschema']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_dataschema']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_dataschema']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_dataschema']['field_api_classes'] = 0;
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
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
    'dataset' => 'dataset',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'datasets';

  /* Display: Feed */
  $handler = $view->new_display('feed', 'Feed', 'feed');
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['style_plugin'] = 'rss';
  $handler->display->display_options['row_plugin'] = 'node_rss';
  $handler->display->display_options['path'] = 'datasets.xml';
  $handler->display->display_options['displays'] = array(
    'default' => 'default',
    'page' => 'page',
  );
  $translatables['datasets'] = array(
    t('Master'),
    t('Datasets'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('The consortium makes available different datasets to the research community. Each dataset is described by a comprehensive data dictionary which gives details on each available variable. Moreover, Mica includes for  studies using the OBiBa Opal software as main database solution, a distributed query engine that enables researchers to obtain real-time aggregated reports on the exact number of participant with specific characteristics or phenotypes. Mica makes even possible to run remotely some regression analyses on the real study data using the DataSHIELD method (Wolfson M et al. <i>Int J Epidemiol</i>. 2010), which is implemented both in Mica and Opal. <br/><br/>'),
    t('empty_datasets'),
    t('No dataset found.'),
    t('Name'),
    t('Description'),
    t('Dataschema'),
    t('Page'),
    t('Feed'),
  );
  $export['datasets'] = $view;

  $view = new view;
  $view->name = 'participant_variable_search';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'search_api_index_participant_variable_index';
  $view->human_name = 'Participant Variable Search';
  $view->core = 7;
  $view->api_version = '3.0-alpha1';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Participant Variables';
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['grouping'] = 'field_dataset';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
    'field_label' => 'field_label',
    'field_categories' => 'field_categories',
    'field_repeatable' => 'field_repeatable',
    'field_value_type' => 'field_value_type',
    'field_dataset' => 'field_dataset',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'align' => '',
      'separator' => '',
    ),
    'field_label' => array(
      'align' => '',
      'separator' => '',
    ),
    'field_categories' => array(
      'align' => '',
      'separator' => '',
    ),
    'field_repeatable' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
    'field_value_type' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
    'field_dataset' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
  );
  $handler->display->display_options['style_options']['override'] = 1;
  $handler->display->display_options['style_options']['sticky'] = 0;
  $handler->display->display_options['style_options']['empty_table'] = 0;
  /* Field: Node: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'search_api_index_participant_variable_index';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Name';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title']['alter']['external'] = 0;
  $handler->display->display_options['fields']['title']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['title']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['link_to_entity'] = 1;
  /* Field: Node: Label */
  $handler->display->display_options['fields']['field_label']['id'] = 'field_label';
  $handler->display->display_options['fields']['field_label']['table'] = 'search_api_index_participant_variable_index';
  $handler->display->display_options['fields']['field_label']['field'] = 'field_label';
  $handler->display->display_options['fields']['field_label']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_label']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_label']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_label']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_label']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_label']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_label']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_label']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_label']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_label']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_label']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_label']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_label']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_label']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_label']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_label']['link_to_entity'] = 0;
  /* Field: Node: Categories */
  $handler->display->display_options['fields']['field_categories']['id'] = 'field_categories';
  $handler->display->display_options['fields']['field_categories']['table'] = 'search_api_index_participant_variable_index';
  $handler->display->display_options['fields']['field_categories']['field'] = 'field_categories';
  $handler->display->display_options['fields']['field_categories']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_categories']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_categories']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_categories']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_categories']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_categories']['alter']['trim'] = 1;
  $handler->display->display_options['fields']['field_categories']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_categories']['alter']['max_length'] = '70';
  $handler->display->display_options['fields']['field_categories']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_categories']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_categories']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_categories']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_categories']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_categories']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_categories']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_categories']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_categories']['link_to_entity'] = 0;
  /* Field: Node: Value Type */
  $handler->display->display_options['fields']['field_value_type']['id'] = 'field_value_type';
  $handler->display->display_options['fields']['field_value_type']['table'] = 'search_api_index_participant_variable_index';
  $handler->display->display_options['fields']['field_value_type']['field'] = 'field_value_type';
  $handler->display->display_options['fields']['field_value_type']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_value_type']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_value_type']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_value_type']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_value_type']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_value_type']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_value_type']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_value_type']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_value_type']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_value_type']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_value_type']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_value_type']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_value_type']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_value_type']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_value_type']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_value_type']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['field_value_type']['format_name'] = 1;
  /* Field: Node: Repeatable */
  $handler->display->display_options['fields']['field_repeatable']['id'] = 'field_repeatable';
  $handler->display->display_options['fields']['field_repeatable']['table'] = 'search_api_index_participant_variable_index';
  $handler->display->display_options['fields']['field_repeatable']['field'] = 'field_repeatable';
  $handler->display->display_options['fields']['field_repeatable']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_repeatable']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_repeatable']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_repeatable']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_repeatable']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_repeatable']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_repeatable']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_repeatable']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_repeatable']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_repeatable']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_repeatable']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_repeatable']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_repeatable']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_repeatable']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_repeatable']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_repeatable']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['field_repeatable']['format_name'] = 1;
  /* Field: Node: Dataset */
  $handler->display->display_options['fields']['field_dataset']['id'] = 'field_dataset';
  $handler->display->display_options['fields']['field_dataset']['table'] = 'search_api_index_participant_variable_index';
  $handler->display->display_options['fields']['field_dataset']['field'] = 'field_dataset';
  $handler->display->display_options['fields']['field_dataset']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_dataset']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_dataset']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_dataset']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_dataset']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_dataset']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_dataset']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_dataset']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_dataset']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_dataset']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_dataset']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_dataset']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_dataset']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_dataset']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_dataset']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_dataset']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_dataset']['link_to_entity'] = 1;
  $handler->display->display_options['fields']['field_dataset']['format_name'] = 1;
  /* Filter criterion: Search: Fulltext search */
  $handler->display->display_options['filters']['search_api_views_fulltext']['id'] = 'search_api_views_fulltext';
  $handler->display->display_options['filters']['search_api_views_fulltext']['table'] = 'search_api_index_participant_variable_index';
  $handler->display->display_options['filters']['search_api_views_fulltext']['field'] = 'search_api_views_fulltext';
  $handler->display->display_options['filters']['search_api_views_fulltext']['exposed'] = TRUE;
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['operator_id'] = 'search_api_views_fulltext_op';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['label'] = 'Fulltext search';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['operator'] = 'search_api_views_fulltext_op';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['identifier'] = 'search_api_views_fulltext';
  $handler->display->display_options['filters']['search_api_views_fulltext']['fields'] = array(
    'title' => 'title',
    'field_label' => 'field_label',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'participant-variable-search';
  $translatables['participant_variable_search'] = array(
    t('Master'),
    t('Participant Variables'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('Name'),
    t('Label'),
    t('Categories'),
    t('Value Type'),
    t('Repeatable'),
    t('Dataset'),
    t('Fulltext search'),
    t('Page'),
  );
  $export['participant_variable_search'] = $view;

  return $export;
}
