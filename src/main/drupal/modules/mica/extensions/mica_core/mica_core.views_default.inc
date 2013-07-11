<?php
/**
 * @file
 * mica_core.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function mica_core_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'clone_of_administration_nodes';
  $view->description = 'Find and manage content.';
  $view->tag = 'admin';
  $view->base_table = 'node';
  $view->human_name = 'Clone of Administration: Nodes';
  $view->core = 0;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Defaults */
  $handler = $view->new_display('default', 'Defaults', 'default');
  $handler->display->display_options['title'] = 'Content';
  $handler->display->display_options['css_class'] = 'admin-views-view';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'menu';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '100';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['pager']['options']['expose']['items_per_page'] = TRUE;
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options'] = '10, 50, 100, 250, 500';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all'] = TRUE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'views_bulk_operations' => 'views_bulk_operations',
    'title' => 'title',
    'timestamp' => 'title',
    'type' => 'type',
    'name' => 'name',
    'status' => 'status',
    'changed' => 'changed',
    'edit_node' => 'edit_node',
    'delete_node' => 'edit_node',
  );
  $handler->display->display_options['style_options']['default'] = 'changed';
  $handler->display->display_options['style_options']['info'] = array(
    'views_bulk_operations' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '&nbsp;',
      'empty_column' => 0,
    ),
    'timestamp' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'type' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'name' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'status' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'changed' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'edit_node' => array(
      'align' => '',
      'separator' => '&emsp;',
      'empty_column' => 0,
    ),
    'delete_node' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['style_options']['sticky'] = TRUE;
  $handler->display->display_options['style_options']['empty_table'] = TRUE;
  /* Header: Global: Result summary */
  $handler->display->display_options['header']['result']['id'] = 'result';
  $handler->display->display_options['header']['result']['table'] = 'views';
  $handler->display->display_options['header']['result']['field'] = 'result';
  /* No results behavior: Global: Unfiltered text */
  $handler->display->display_options['empty']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['empty']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['empty']['area_text_custom']['field'] = 'area_text_custom';
  $handler->display->display_options['empty']['area_text_custom']['empty'] = TRUE;
  $handler->display->display_options['empty']['area_text_custom']['content'] = 'No content available.';
  /* Relationship: Content: Author */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'node';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  /* Relationship: Content: Taxonomy terms on node */
  $handler->display->display_options['relationships']['term_node_tid']['id'] = 'term_node_tid';
  $handler->display->display_options['relationships']['term_node_tid']['table'] = 'node';
  $handler->display->display_options['relationships']['term_node_tid']['field'] = 'term_node_tid';
  $handler->display->display_options['relationships']['term_node_tid']['vocabularies'] = array(
    'forums' => 0,
    'tags' => 0,
  );
  /* Field: Bulk operations: Content */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'node';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['label'] = '';
  $handler->display->display_options['fields']['views_bulk_operations']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['views_bulk_operations']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '0';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['enable_select_all_pages'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['force_single'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['entity_load_capacity'] = '1';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_operations'] = array(
    'action::node_assign_owner_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 1,
      'override_label' => 1,
      'label' => 'Change author',
    ),
    'action::views_bulk_operations_delete_item' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 1,
      'label' => 'Delete',
    ),
    'action::views_bulk_operations_script_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_make_sticky_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 1,
      'override_label' => 1,
      'label' => 'Stick',
    ),
    'action::node_make_unsticky_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 1,
      'override_label' => 1,
      'label' => 'Unstick',
    ),
    'action::views_bulk_operations_modify_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 1,
      'override_label' => 1,
      'label' => 'Change value',
      'settings' => array(
        'show_all_tokens' => 1,
        'display_values' => array(
          '_all_' => '_all_',
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
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 1,
      'override_label' => 1,
      'label' => 'Promote to front page',
    ),
    'action::node_publish_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 1,
      'override_label' => 1,
      'label' => 'Publish',
    ),
    'action::node_unpromote_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 1,
      'override_label' => 1,
      'label' => 'Demote from front page',
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
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_unpublish_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 1,
      'override_label' => 1,
      'label' => 'Unpublish',
    ),
    'action::node_unpublish_by_keyword_action' => array(
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
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  /* Field: Content: Has new content */
  $handler->display->display_options['fields']['timestamp']['id'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['table'] = 'history';
  $handler->display->display_options['fields']['timestamp']['field'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['label'] = '';
  $handler->display->display_options['fields']['timestamp']['element_label_colon'] = FALSE;
  /* Field: Content: Type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'node';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['name']['label'] = 'Author';
  $handler->display->display_options['fields']['name']['hide_alter_empty'] = FALSE;
  /* Field: Content: Published */
  $handler->display->display_options['fields']['status']['id'] = 'status';
  $handler->display->display_options['fields']['status']['table'] = 'node';
  $handler->display->display_options['fields']['status']['field'] = 'status';
  $handler->display->display_options['fields']['status']['not'] = 0;
  /* Field: Content: Updated date */
  $handler->display->display_options['fields']['changed']['id'] = 'changed';
  $handler->display->display_options['fields']['changed']['table'] = 'node';
  $handler->display->display_options['fields']['changed']['field'] = 'changed';
  $handler->display->display_options['fields']['changed']['label'] = 'Updated';
  $handler->display->display_options['fields']['changed']['date_format'] = 'short';
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = 'Operations';
  /* Field: Content: Delete link */
  $handler->display->display_options['fields']['delete_node']['id'] = 'delete_node';
  $handler->display->display_options['fields']['delete_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['delete_node']['field'] = 'delete_node';
  $handler->display->display_options['fields']['delete_node']['label'] = '';
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['operator'] = 'contains';
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Title';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
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
    12 => 0,
    11 => 0,
  );
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['exposed'] = TRUE;
  $handler->display->display_options['filters']['type']['expose']['operator_id'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['label'] = 'Type';
  $handler->display->display_options['filters']['type']['expose']['operator'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['identifier'] = 'type';
  $handler->display->display_options['filters']['type']['expose']['remember'] = TRUE;
  /* Filter criterion: User: Name */
  $handler->display->display_options['filters']['uid']['id'] = 'uid';
  $handler->display->display_options['filters']['uid']['table'] = 'users';
  $handler->display->display_options['filters']['uid']['field'] = 'uid';
  $handler->display->display_options['filters']['uid']['relationship'] = 'uid';
  $handler->display->display_options['filters']['uid']['value'] = '';
  $handler->display->display_options['filters']['uid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['uid']['expose']['operator_id'] = 'uid_op';
  $handler->display->display_options['filters']['uid']['expose']['label'] = 'Author';
  $handler->display->display_options['filters']['uid']['expose']['operator'] = 'uid_op';
  $handler->display->display_options['filters']['uid']['expose']['identifier'] = 'author';
  $handler->display->display_options['filters']['uid']['expose']['remember'] = TRUE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 'All';
  $handler->display->display_options['filters']['status']['exposed'] = TRUE;
  $handler->display->display_options['filters']['status']['expose']['operator_id'] = '';
  $handler->display->display_options['filters']['status']['expose']['label'] = 'Published';
  $handler->display->display_options['filters']['status']['expose']['operator'] = 'status_op';
  $handler->display->display_options['filters']['status']['expose']['identifier'] = 'status';
  $handler->display->display_options['filters']['status']['expose']['remember'] = TRUE;
  /* Filter criterion: Taxonomy term: Vocabulary */
  $handler->display->display_options['filters']['vid']['id'] = 'vid';
  $handler->display->display_options['filters']['vid']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['filters']['vid']['field'] = 'vid';
  $handler->display->display_options['filters']['vid']['relationship'] = 'term_node_tid';
  $handler->display->display_options['filters']['vid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['vid']['expose']['operator_id'] = 'vid_op';
  $handler->display->display_options['filters']['vid']['expose']['label'] = 'Vocabulary';
  $handler->display->display_options['filters']['vid']['expose']['operator'] = 'vid_op';
  $handler->display->display_options['filters']['vid']['expose']['identifier'] = 'vid';
  $handler->display->display_options['filters']['vid']['expose']['remember'] = TRUE;
  /* Filter criterion: Content: Dataset (field_dataset) */
  $handler->display->display_options['filters']['field_dataset_nid']['id'] = 'field_dataset_nid';
  $handler->display->display_options['filters']['field_dataset_nid']['table'] = 'field_data_field_dataset';
  $handler->display->display_options['filters']['field_dataset_nid']['field'] = 'field_dataset_nid';
  $handler->display->display_options['filters']['field_dataset_nid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_dataset_nid']['expose']['operator_id'] = 'field_dataset_nid_op';
  $handler->display->display_options['filters']['field_dataset_nid']['expose']['label'] = 'Dataset';
  $handler->display->display_options['filters']['field_dataset_nid']['expose']['operator'] = 'field_dataset_nid_op';
  $handler->display->display_options['filters']['field_dataset_nid']['expose']['identifier'] = 'field_dataset_nid';
  $handler->display->display_options['filters']['field_dataset_nid']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['field_dataset_nid']['expose']['remember_roles'] = array(
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
    12 => 0,
    11 => 0,
  );

  /* Display: System */
  $handler = $view->new_display('system', 'System', 'system_1');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['hide_admin_links'] = TRUE;
  $handler->display->display_options['defaults']['access'] = FALSE;
  $handler->display->display_options['path'] = 'admin/content';

  /* Display: Data export */
  $handler = $view->new_display('views_data_export', 'Data export', 'views_data_export_1');
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
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title_field']['id'] = 'title_field';
  $handler->display->display_options['fields']['title_field']['table'] = 'field_data_title_field';
  $handler->display->display_options['fields']['title_field']['field'] = 'title_field';
  $handler->display->display_options['fields']['title_field']['label'] = 'title';
  $handler->display->display_options['fields']['title_field']['type'] = 'text_plain';
  $handler->display->display_options['fields']['title_field']['link_to_entity'] = 0;
  /* Field: Content: Label */
  $handler->display->display_options['fields']['field_label']['id'] = 'field_label';
  $handler->display->display_options['fields']['field_label']['table'] = 'field_data_field_label';
  $handler->display->display_options['fields']['field_label']['field'] = 'field_label';
  $handler->display->display_options['fields']['field_label']['label'] = 'label';
  $handler->display->display_options['fields']['field_label']['type'] = 'text_plain';
  /* Field: Content: Administrative Information */
  $handler->display->display_options['fields']['field_administrative_information']['id'] = 'field_administrative_information';
  $handler->display->display_options['fields']['field_administrative_information']['table'] = 'field_data_field_administrative_information';
  $handler->display->display_options['fields']['field_administrative_information']['field'] = 'field_administrative_information';
  $handler->display->display_options['fields']['field_administrative_information']['label'] = 'administrative_information';
  $handler->display->display_options['fields']['field_administrative_information']['type'] = 'taxonomy_term_reference_plain';
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
  $handler->display->display_options['fields']['field_data_source']['separator'] = '| ';
  /* Field: Content: Dataset */
  $handler->display->display_options['fields']['field_dataset']['id'] = 'field_dataset';
  $handler->display->display_options['fields']['field_dataset']['table'] = 'field_data_field_dataset';
  $handler->display->display_options['fields']['field_dataset']['field'] = 'field_dataset';
  $handler->display->display_options['fields']['field_dataset']['label'] = 'dataset';
  $handler->display->display_options['fields']['field_dataset']['type'] = 'node_reference_plain';
  /* Field: Content: Diseases History and Related Health Problems */
  $handler->display->display_options['fields']['field_disease_history']['id'] = 'field_disease_history';
  $handler->display->display_options['fields']['field_disease_history']['table'] = 'field_data_field_disease_history';
  $handler->display->display_options['fields']['field_disease_history']['field'] = 'field_disease_history';
  $handler->display->display_options['fields']['field_disease_history']['label'] = 'disease_history';
  $handler->display->display_options['fields']['field_disease_history']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_disease_history']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_disease_history']['separator'] = '|';
  /* Field: Content: Essence */
  $handler->display->display_options['fields']['field_essence']['id'] = 'field_essence';
  $handler->display->display_options['fields']['field_essence']['table'] = 'field_data_field_essence';
  $handler->display->display_options['fields']['field_essence']['field'] = 'field_essence';
  $handler->display->display_options['fields']['field_essence']['label'] = 'essence';
  $handler->display->display_options['fields']['field_essence']['type'] = 'taxonomy_term_reference_plain';
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
  /* Field: Content: Life Habits/Behaviours */
  $handler->display->display_options['fields']['field_life_habits_behaviours']['id'] = 'field_life_habits_behaviours';
  $handler->display->display_options['fields']['field_life_habits_behaviours']['table'] = 'field_data_field_life_habits_behaviours';
  $handler->display->display_options['fields']['field_life_habits_behaviours']['field'] = 'field_life_habits_behaviours';
  $handler->display->display_options['fields']['field_life_habits_behaviours']['label'] = 'life_habits_behaviours';
  $handler->display->display_options['fields']['field_life_habits_behaviours']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_life_habits_behaviours']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_life_habits_behaviours']['separator'] = '|';
  /* Field: Content: Measure */
  $handler->display->display_options['fields']['field_measure']['id'] = 'field_measure';
  $handler->display->display_options['fields']['field_measure']['table'] = 'field_data_field_measure';
  $handler->display->display_options['fields']['field_measure']['field'] = 'field_measure';
  $handler->display->display_options['fields']['field_measure']['label'] = 'measure';
  $handler->display->display_options['fields']['field_measure']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_measure']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_measure']['separator'] = '|';
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
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = 'body';
  $handler->display->display_options['fields']['body']['type'] = 'text_plain';
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = 'nid';
  /* Field: Content: Unit */
  $handler->display->display_options['fields']['field_unit']['id'] = 'field_unit';
  $handler->display->display_options['fields']['field_unit']['table'] = 'field_data_field_unit';
  $handler->display->display_options['fields']['field_unit']['field'] = 'field_unit';
  $handler->display->display_options['fields']['field_unit']['label'] = 'unit';
  /* Field: Content: Value Type */
  $handler->display->display_options['fields']['field_value_type']['id'] = 'field_value_type';
  $handler->display->display_options['fields']['field_value_type']['table'] = 'field_data_field_value_type';
  $handler->display->display_options['fields']['field_value_type']['field'] = 'field_value_type';
  $handler->display->display_options['fields']['field_value_type']['label'] = 'value_type';
  $handler->display->display_options['fields']['field_value_type']['type'] = 'list_key';
  /* Field: Content: Categories */
  $handler->display->display_options['fields']['field_variable_categories']['id'] = 'field_variable_categories';
  $handler->display->display_options['fields']['field_variable_categories']['table'] = 'field_data_field_variable_categories';
  $handler->display->display_options['fields']['field_variable_categories']['field'] = 'field_variable_categories';
  $handler->display->display_options['fields']['field_variable_categories']['label'] = 'categories_name';
  $handler->display->display_options['fields']['field_variable_categories']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_variable_categories']['alter']['text'] = '[field_variable_categories-name]';
  $handler->display->display_options['fields']['field_variable_categories']['click_sort_column'] = 'name';
  $handler->display->display_options['fields']['field_variable_categories']['type'] = 'category_field_key_formatter';
  $handler->display->display_options['fields']['field_variable_categories']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_variable_categories']['separator'] = '|';
  /* Field: Content: Categories */
  $handler->display->display_options['fields']['field_variable_categories_1']['id'] = 'field_variable_categories_1';
  $handler->display->display_options['fields']['field_variable_categories_1']['table'] = 'field_data_field_variable_categories';
  $handler->display->display_options['fields']['field_variable_categories_1']['field'] = 'field_variable_categories';
  $handler->display->display_options['fields']['field_variable_categories_1']['label'] = 'categories_label';
  $handler->display->display_options['fields']['field_variable_categories_1']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_variable_categories_1']['alter']['text'] = '[field_variable_categories_1-label]';
  $handler->display->display_options['fields']['field_variable_categories_1']['click_sort_column'] = 'name';
  $handler->display->display_options['fields']['field_variable_categories_1']['type'] = 'category_field_key_formatter';
  $handler->display->display_options['fields']['field_variable_categories_1']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_variable_categories_1']['separator'] = '|';
  /* Field: Content: Categories */
  $handler->display->display_options['fields']['field_variable_categories_2']['id'] = 'field_variable_categories_2';
  $handler->display->display_options['fields']['field_variable_categories_2']['table'] = 'field_data_field_variable_categories';
  $handler->display->display_options['fields']['field_variable_categories_2']['field'] = 'field_variable_categories';
  $handler->display->display_options['fields']['field_variable_categories_2']['label'] = 'categories_missing';
  $handler->display->display_options['fields']['field_variable_categories_2']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_variable_categories_2']['alter']['text'] = '[field_variable_categories_2-missing]';
  $handler->display->display_options['fields']['field_variable_categories_2']['click_sort_column'] = 'name';
  $handler->display->display_options['fields']['field_variable_categories_2']['type'] = 'category_field_key_formatter';
  $handler->display->display_options['fields']['field_variable_categories_2']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_variable_categories_2']['separator'] = '|';
  $handler->display->display_options['path'] = 'export-variables-csv';
  $handler->display->display_options['displays'] = array(
    'default' => 0,
    'system_1' => 0,
  );
  $handler->display->display_options['use_batch'] = 'batch';

  /* Display: Data export CSV */
  $handler = $view->new_display('views_data_export', 'Data export CSV', 'views_data_export_2');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_data_export_csv';
  $handler->display->display_options['style_options']['provide_file'] = 1;
  $handler->display->display_options['style_options']['filename'] = 'dataset_variables.csv';
  $handler->display->display_options['style_options']['parent_sort'] = 0;
  $handler->display->display_options['style_options']['quote'] = 1;
  $handler->display->display_options['style_options']['trim'] = 0;
  $handler->display->display_options['style_options']['replace_newlines'] = 0;
  $handler->display->display_options['style_options']['header'] = 1;
  $handler->display->display_options['style_options']['keep_html'] = 0;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = 'nid';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title_field']['id'] = 'title_field';
  $handler->display->display_options['fields']['title_field']['table'] = 'field_data_title_field';
  $handler->display->display_options['fields']['title_field']['field'] = 'title_field';
  $handler->display->display_options['fields']['title_field']['label'] = 'title';
  $handler->display->display_options['fields']['title_field']['type'] = 'text_plain';
  $handler->display->display_options['fields']['title_field']['link_to_entity'] = 0;
  /* Field: Content: Label */
  $handler->display->display_options['fields']['field_label']['id'] = 'field_label';
  $handler->display->display_options['fields']['field_label']['table'] = 'field_data_field_label';
  $handler->display->display_options['fields']['field_label']['field'] = 'field_label';
  $handler->display->display_options['fields']['field_label']['label'] = 'label';
  $handler->display->display_options['fields']['field_label']['type'] = 'text_plain';
  /* Field: Content: Dataset */
  $handler->display->display_options['fields']['field_dataset']['id'] = 'field_dataset';
  $handler->display->display_options['fields']['field_dataset']['table'] = 'field_data_field_dataset';
  $handler->display->display_options['fields']['field_dataset']['field'] = 'field_dataset';
  $handler->display->display_options['fields']['field_dataset']['label'] = 'dataset';
  $handler->display->display_options['fields']['field_dataset']['type'] = 'node_reference_plain';
  /* Field: Content: Administrative Information */
  $handler->display->display_options['fields']['field_administrative_information']['id'] = 'field_administrative_information';
  $handler->display->display_options['fields']['field_administrative_information']['table'] = 'field_data_field_administrative_information';
  $handler->display->display_options['fields']['field_administrative_information']['field'] = 'field_administrative_information';
  $handler->display->display_options['fields']['field_administrative_information']['label'] = 'administrative_information';
  $handler->display->display_options['fields']['field_administrative_information']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Content: Anthropometric Structures */
  $handler->display->display_options['fields']['field_anthropometric_structures']['id'] = 'field_anthropometric_structures';
  $handler->display->display_options['fields']['field_anthropometric_structures']['table'] = 'field_data_field_anthropometric_structures';
  $handler->display->display_options['fields']['field_anthropometric_structures']['field'] = 'field_anthropometric_structures';
  $handler->display->display_options['fields']['field_anthropometric_structures']['label'] = 'anthropometric_structures';
  $handler->display->display_options['fields']['field_anthropometric_structures']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_anthropometric_structures']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_anthropometric_structures']['separator'] = '|';
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = 'body';
  $handler->display->display_options['fields']['body']['type'] = 'text_plain';
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
  /* Field: Content: Essence */
  $handler->display->display_options['fields']['field_essence']['id'] = 'field_essence';
  $handler->display->display_options['fields']['field_essence']['table'] = 'field_data_field_essence';
  $handler->display->display_options['fields']['field_essence']['field'] = 'field_essence';
  $handler->display->display_options['fields']['field_essence']['label'] = 'essence';
  $handler->display->display_options['fields']['field_essence']['type'] = 'taxonomy_term_reference_plain';
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
  /* Field: Content: Life Habits/Behaviours */
  $handler->display->display_options['fields']['field_life_habits_behaviours']['id'] = 'field_life_habits_behaviours';
  $handler->display->display_options['fields']['field_life_habits_behaviours']['table'] = 'field_data_field_life_habits_behaviours';
  $handler->display->display_options['fields']['field_life_habits_behaviours']['field'] = 'field_life_habits_behaviours';
  $handler->display->display_options['fields']['field_life_habits_behaviours']['label'] = 'life_habits_behaviours';
  $handler->display->display_options['fields']['field_life_habits_behaviours']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_life_habits_behaviours']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_life_habits_behaviours']['separator'] = '|';
  /* Field: Content: Measure */
  $handler->display->display_options['fields']['field_measure']['id'] = 'field_measure';
  $handler->display->display_options['fields']['field_measure']['table'] = 'field_data_field_measure';
  $handler->display->display_options['fields']['field_measure']['field'] = 'field_measure';
  $handler->display->display_options['fields']['field_measure']['label'] = 'measure';
  $handler->display->display_options['fields']['field_measure']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_measure']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_measure']['separator'] = '|';
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
  /* Field: Content: Unit */
  $handler->display->display_options['fields']['field_unit']['id'] = 'field_unit';
  $handler->display->display_options['fields']['field_unit']['table'] = 'field_data_field_unit';
  $handler->display->display_options['fields']['field_unit']['field'] = 'field_unit';
  $handler->display->display_options['fields']['field_unit']['label'] = 'unit';
  $handler->display->display_options['fields']['field_unit']['type'] = 'text_plain';
  /* Field: Content: Value Type */
  $handler->display->display_options['fields']['field_value_type']['id'] = 'field_value_type';
  $handler->display->display_options['fields']['field_value_type']['table'] = 'field_data_field_value_type';
  $handler->display->display_options['fields']['field_value_type']['field'] = 'field_value_type';
  $handler->display->display_options['fields']['field_value_type']['label'] = 'value_type';
  $handler->display->display_options['fields']['field_value_type']['type'] = 'list_key';
  /* Field: Content: Repeatable */
  $handler->display->display_options['fields']['field_repeatable']['id'] = 'field_repeatable';
  $handler->display->display_options['fields']['field_repeatable']['table'] = 'field_data_field_repeatable';
  $handler->display->display_options['fields']['field_repeatable']['field'] = 'field_repeatable';
  $handler->display->display_options['fields']['field_repeatable']['label'] = 'repeatable';
  $handler->display->display_options['fields']['field_repeatable']['type'] = 'list_key';
  /* Field: Content: Categories */
  $handler->display->display_options['fields']['field_variable_categories']['id'] = 'field_variable_categories';
  $handler->display->display_options['fields']['field_variable_categories']['table'] = 'field_data_field_variable_categories';
  $handler->display->display_options['fields']['field_variable_categories']['field'] = 'field_variable_categories';
  $handler->display->display_options['fields']['field_variable_categories']['label'] = 'categories_name';
  $handler->display->display_options['fields']['field_variable_categories']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_variable_categories']['alter']['text'] = '[field_variable_categories-name]';
  $handler->display->display_options['fields']['field_variable_categories']['click_sort_column'] = 'name';
  $handler->display->display_options['fields']['field_variable_categories']['type'] = 'category_field_key_formatter';
  $handler->display->display_options['fields']['field_variable_categories']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_variable_categories']['separator'] = '|';
  /* Field: Content: Categories */
  $handler->display->display_options['fields']['field_variable_categories_1']['id'] = 'field_variable_categories_1';
  $handler->display->display_options['fields']['field_variable_categories_1']['table'] = 'field_data_field_variable_categories';
  $handler->display->display_options['fields']['field_variable_categories_1']['field'] = 'field_variable_categories';
  $handler->display->display_options['fields']['field_variable_categories_1']['label'] = 'categories_label';
  $handler->display->display_options['fields']['field_variable_categories_1']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_variable_categories_1']['alter']['text'] = '[field_variable_categories_1-label]';
  $handler->display->display_options['fields']['field_variable_categories_1']['click_sort_column'] = 'name';
  $handler->display->display_options['fields']['field_variable_categories_1']['type'] = 'category_field_key_formatter';
  $handler->display->display_options['fields']['field_variable_categories_1']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_variable_categories_1']['separator'] = '|';
  /* Field: Content: Categories */
  $handler->display->display_options['fields']['field_variable_categories_2']['id'] = 'field_variable_categories_2';
  $handler->display->display_options['fields']['field_variable_categories_2']['table'] = 'field_data_field_variable_categories';
  $handler->display->display_options['fields']['field_variable_categories_2']['field'] = 'field_variable_categories';
  $handler->display->display_options['fields']['field_variable_categories_2']['label'] = 'categories_missing';
  $handler->display->display_options['fields']['field_variable_categories_2']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_variable_categories_2']['alter']['text'] = '[field_variable_categories_2-missing]';
  $handler->display->display_options['fields']['field_variable_categories_2']['click_sort_column'] = 'name';
  $handler->display->display_options['fields']['field_variable_categories_2']['type'] = 'category_field_key_formatter';
  $handler->display->display_options['fields']['field_variable_categories_2']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_variable_categories_2']['separator'] = '|';
  $handler->display->display_options['path'] = 'variables-export-csv';
  $handler->display->display_options['displays'] = array(
    'system_1' => 'system_1',
    'default' => 0,
    'system_2' => 0,
  );
  $handler->display->display_options['use_batch'] = 'batch';
  $export['clone_of_administration_nodes'] = $view;

  return $export;
}
