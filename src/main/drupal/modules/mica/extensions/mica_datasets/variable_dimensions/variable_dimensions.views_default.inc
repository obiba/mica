<?php
/**
 * @file
 * variable_dimensions.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function variable_dimensions_views_default_views() {
  $export = array();

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
  $handler->display->display_options['title'] = 'variables-dimensions';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'table';
  /* Field: Indexed Node: Label */
  $handler->display->display_options['fields']['field_label']['id'] = 'field_label';
  $handler->display->display_options['fields']['field_label']['table'] = 'search_api_index_variable_index';
  $handler->display->display_options['fields']['field_label']['field'] = 'field_label';
  /* Field: Indexed Node: Anthropometric Structures */
  $handler->display->display_options['fields']['field_anthropometric_structures']['id'] = 'field_anthropometric_structures';
  $handler->display->display_options['fields']['field_anthropometric_structures']['table'] = 'search_api_index_variable_index';
  $handler->display->display_options['fields']['field_anthropometric_structures']['field'] = 'field_anthropometric_structures';
  $handler->display->display_options['fields']['field_anthropometric_structures']['alter']['max_length'] = '100';
  $handler->display->display_options['fields']['field_anthropometric_structures']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['field_anthropometric_structures']['link_to_entity'] = 1;
  $handler->display->display_options['fields']['field_anthropometric_structures']['view_mode'] = 'full';
  /* Field: Indexed Node: Body Functions */
  $handler->display->display_options['fields']['field_body_functions']['id'] = 'field_body_functions';
  $handler->display->display_options['fields']['field_body_functions']['table'] = 'search_api_index_variable_index';
  $handler->display->display_options['fields']['field_body_functions']['field'] = 'field_body_functions';
  $handler->display->display_options['fields']['field_body_functions']['link_to_entity'] = 1;
  $handler->display->display_options['fields']['field_body_functions']['view_mode'] = 'full';
  /* Field: Indexed Node: Body Structures */
  $handler->display->display_options['fields']['field_body_structures']['id'] = 'field_body_structures';
  $handler->display->display_options['fields']['field_body_structures']['table'] = 'search_api_index_variable_index';
  $handler->display->display_options['fields']['field_body_structures']['field'] = 'field_body_structures';
  $handler->display->display_options['fields']['field_body_structures']['link_to_entity'] = 1;
  $handler->display->display_options['fields']['field_body_structures']['view_mode'] = 'full';
  /* Field: Indexed Node: Medical Health Interventions/Health Services Utilization */
  $handler->display->display_options['fields']['field_medical_health_interv']['id'] = 'field_medical_health_interv';
  $handler->display->display_options['fields']['field_medical_health_interv']['table'] = 'search_api_index_variable_index';
  $handler->display->display_options['fields']['field_medical_health_interv']['field'] = 'field_medical_health_interv';
  $handler->display->display_options['fields']['field_medical_health_interv']['link_to_entity'] = 1;
  $handler->display->display_options['fields']['field_medical_health_interv']['view_mode'] = 'full';
  /* Field: Indexed Node: Medication */
  $handler->display->display_options['fields']['field_medication']['id'] = 'field_medication';
  $handler->display->display_options['fields']['field_medication']['table'] = 'search_api_index_variable_index';
  $handler->display->display_options['fields']['field_medication']['field'] = 'field_medication';
  $handler->display->display_options['fields']['field_medication']['link_to_entity'] = 1;
  $handler->display->display_options['fields']['field_medication']['view_mode'] = 'full';
  /* Field: Indexed Node: Bulk operations */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'search_api_index_variable_index';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['label'] = 'Assign dimensions';
  $handler->display->display_options['fields']['views_bulk_operations']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '0';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['enable_select_all_pages'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['force_single'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_result'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['entity_load_capacity'] = '10';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_operations'] = array(
    'action::node_assign_owner_action' => array(
      'selected' => 0,
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::views_bulk_operations_delete_item' => array(
      'selected' => 0,
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::system_message_action' => array(
      'selected' => 0,
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::views_bulk_operations_script_action' => array(
      'selected' => 0,
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_make_sticky_action' => array(
      'selected' => 0,
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_make_unsticky_action' => array(
      'selected' => 0,
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::views_bulk_operations_modify_action' => array(
      'selected' => 1,
      'use_queue' => 0,
      'skip_confirmation' => 1,
      'override_label' => 0,
      'label' => '',
      'settings' => array(
        'show_all_tokens' => 1,
        'display_values' => array(
          'variable::field_anthropometric_structures' => 'variable::field_anthropometric_structures',
          'variable::field_body_functions' => 'variable::field_body_functions',
          'variable::field_body_structures' => 'variable::field_body_structures',
          'variable::field_data_source' => 'variable::field_data_source',
          'variable::field_dataset' => 'variable::field_dataset',
          'variable::field_disease_history' => 'variable::field_disease_history',
          'variable::field_early_life' => 'variable::field_early_life',
          'variable::field_essence' => 'variable::field_essence',
          'variable::field_individual_participant_mea' => 'variable::field_individual_participant_mea',
          'variable::field_laboratory_measures' => 'variable::field_laboratory_measures',
          'variable::field_life_habits_behaviours' => 'variable::field_life_habits_behaviours',
          'variable::field_measure' => 'variable::field_measure',
          'variable::field_medical_health_interv' => 'variable::field_medical_health_interv',
          'variable::field_medication' => 'variable::field_medication',
          'variable::field_perception_of_health' => 'variable::field_perception_of_health',
          'variable::field_period' => 'variable::field_period',
          'variable::field_physical_environment' => 'variable::field_physical_environment',
          'variable::field_reproductive_history' => 'variable::field_reproductive_history',
          'variable::field_social_environment' => 'variable::field_social_environment',
          'variable::field_sociodemographic_charact' => 'variable::field_sociodemographic_charact',
          'variable::field_target' => 'variable::field_target',
          'variable::field_unit' => 'variable::field_unit',
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
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_publish_action' => array(
      'selected' => 0,
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::system_goto_action' => array(
      'selected' => 0,
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_unpromote_action' => array(
      'selected' => 0,
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_save_action' => array(
      'selected' => 0,
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::system_send_email_action' => array(
      'selected' => 0,
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::workbench_moderation_set_state_action' => array(
      'selected' => 0,
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_unpublish_action' => array(
      'selected' => 0,
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_unpublish_by_keyword_action' => array(
      'selected' => 0,
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::pathauto_node_update_action' => array(
      'selected' => 0,
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
  );
  /* Sort criterion: Indexed Node: Position index */
  $handler->display->display_options['sorts']['field_position']['id'] = 'field_position';
  $handler->display->display_options['sorts']['field_position']['table'] = 'search_api_index_variable_index';
  $handler->display->display_options['sorts']['field_position']['field'] = 'field_position';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['path'] = 'variables-dimensions';
  $translatables['variables_dimensions'] = array(
    t('Master'),
    t('variables-dimensions'),
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
    t('Label'),
    t('Anthropometric Structures'),
    t('Body Functions'),
    t('Body Structures'),
    t('Medical Health Interventions/Health Services Utilization'),
    t('Medication'),
    t('Assign dimensions'),
    t('Page'),
  );
  $export['variables_dimensions'] = $view;

  return $export;
}
