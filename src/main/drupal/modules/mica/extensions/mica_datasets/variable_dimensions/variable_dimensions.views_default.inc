<?php
/**
 * @file
 * admin.views_default.inc
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
  $handler->display->display_options['title'] = 'Manage Variable Dimensions';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '100';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'title_field' => 'title_field',
    'field_label' => 'field_label',
    'field_anthropometric_structures' => 'field_anthropometric_structures',
    'field_body_functions' => 'field_body_functions',
    'field_body_structures' => 'field_body_structures',
    'field_medical_health_interv' => 'field_medical_health_interv',
    'field_medication' => 'field_medication',
    'views_bulk_operations' => 'views_bulk_operations',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
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
    'views_bulk_operations' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 1,
    ),
  );
  /* Field: Indexed Node: Bulk operations */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'search_api_index_variable_index';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['label'] = 'Assign dimensions';
  $handler->display->display_options['fields']['views_bulk_operations']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '1';
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
      'override_label' => 1,
      'label' => 'Set dimensions',
      'settings' => array(
        'show_all_tokens' => 0,
        'display_values' => array(
          'variable::field_anthropometric_structures' => 'variable::field_anthropometric_structures',
          'variable::field_body_functions' => 'variable::field_body_functions',
          'variable::field_body_structures' => 'variable::field_body_structures',
          'variable::field_data_source' => 'variable::field_data_source',
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
  $handler->display->display_options['fields']['field_anthropometric_structures']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_anthropometric_structures']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_anthropometric_structures']['alter']['text'] = '[field_anthropometric_structures],';
  $handler->display->display_options['fields']['field_anthropometric_structures']['alter']['max_length'] = '100';
  $handler->display->display_options['fields']['field_anthropometric_structures']['link_to_entity'] = 1;
  $handler->display->display_options['fields']['field_anthropometric_structures']['view_mode'] = 'full';
  /* Field: Indexed Node: Body Functions */
  $handler->display->display_options['fields']['field_body_functions']['id'] = 'field_body_functions';
  $handler->display->display_options['fields']['field_body_functions']['table'] = 'search_api_index_variable_index';
  $handler->display->display_options['fields']['field_body_functions']['field'] = 'field_body_functions';
  $handler->display->display_options['fields']['field_body_functions']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_body_functions']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_body_functions']['alter']['text'] = '[field_body_functions],';
  $handler->display->display_options['fields']['field_body_functions']['link_to_entity'] = 1;
  $handler->display->display_options['fields']['field_body_functions']['view_mode'] = 'full';
  /* Field: Indexed Node: Body Structures */
  $handler->display->display_options['fields']['field_body_structures']['id'] = 'field_body_structures';
  $handler->display->display_options['fields']['field_body_structures']['table'] = 'search_api_index_variable_index';
  $handler->display->display_options['fields']['field_body_structures']['field'] = 'field_body_structures';
  $handler->display->display_options['fields']['field_body_structures']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_body_structures']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_body_structures']['alter']['text'] = '[field_body_structures],';
  $handler->display->display_options['fields']['field_body_structures']['link_to_entity'] = 1;
  $handler->display->display_options['fields']['field_body_structures']['view_mode'] = 'full';
  /* Field: Indexed Node: Data Source */
  $handler->display->display_options['fields']['field_data_source']['id'] = 'field_data_source';
  $handler->display->display_options['fields']['field_data_source']['table'] = 'search_api_index_variable_index';
  $handler->display->display_options['fields']['field_data_source']['field'] = 'field_data_source';
  $handler->display->display_options['fields']['field_data_source']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_data_source']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_data_source']['alter']['text'] = '[field_data_source],';
  $handler->display->display_options['fields']['field_data_source']['link_to_entity'] = 1;
  $handler->display->display_options['fields']['field_data_source']['view_mode'] = 'full';
  /* Field: Indexed Node: Diseases History and Related Health Problems */
  $handler->display->display_options['fields']['field_disease_history']['id'] = 'field_disease_history';
  $handler->display->display_options['fields']['field_disease_history']['table'] = 'search_api_index_variable_index';
  $handler->display->display_options['fields']['field_disease_history']['field'] = 'field_disease_history';
  $handler->display->display_options['fields']['field_disease_history']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_disease_history']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_disease_history']['alter']['text'] = '[field_disease_history],';
  $handler->display->display_options['fields']['field_disease_history']['link_to_entity'] = 1;
  $handler->display->display_options['fields']['field_disease_history']['view_mode'] = 'full';
  /* Field: Indexed Node: Essence */
  $handler->display->display_options['fields']['field_essence']['id'] = 'field_essence';
  $handler->display->display_options['fields']['field_essence']['table'] = 'search_api_index_variable_index';
  $handler->display->display_options['fields']['field_essence']['field'] = 'field_essence';
  $handler->display->display_options['fields']['field_essence']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_essence']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_essence']['alter']['text'] = '[field_essence],';
  $handler->display->display_options['fields']['field_essence']['link_to_entity'] = 1;
  $handler->display->display_options['fields']['field_essence']['view_mode'] = 'full';
  /* Field: Indexed Node: Individual Participant Measures */
  $handler->display->display_options['fields']['field_individual_participant_mea']['id'] = 'field_individual_participant_mea';
  $handler->display->display_options['fields']['field_individual_participant_mea']['table'] = 'search_api_index_variable_index';
  $handler->display->display_options['fields']['field_individual_participant_mea']['field'] = 'field_individual_participant_mea';
  $handler->display->display_options['fields']['field_individual_participant_mea']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_individual_participant_mea']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_individual_participant_mea']['alter']['text'] = '[field_individual_participant_mea],';
  $handler->display->display_options['fields']['field_individual_participant_mea']['link_to_entity'] = 1;
  $handler->display->display_options['fields']['field_individual_participant_mea']['view_mode'] = 'full';
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
  $handler->display->display_options['fields']['field_life_habits_behaviours']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_life_habits_behaviours']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_life_habits_behaviours']['alter']['text'] = '[field_life_habits_behaviours],';
  $handler->display->display_options['fields']['field_life_habits_behaviours']['link_to_entity'] = 1;
  $handler->display->display_options['fields']['field_life_habits_behaviours']['view_mode'] = 'full';
  /* Field: Indexed Node: Measure */
  $handler->display->display_options['fields']['field_measure']['id'] = 'field_measure';
  $handler->display->display_options['fields']['field_measure']['table'] = 'search_api_index_variable_index';
  $handler->display->display_options['fields']['field_measure']['field'] = 'field_measure';
  $handler->display->display_options['fields']['field_measure']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_measure']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_measure']['alter']['text'] = '[field_measure],';
  $handler->display->display_options['fields']['field_measure']['link_to_entity'] = 1;
  $handler->display->display_options['fields']['field_measure']['view_mode'] = 'full';
  /* Field: Indexed Node: Medical Health Interventions/Health Services Utilization */
  $handler->display->display_options['fields']['field_medical_health_interv']['id'] = 'field_medical_health_interv';
  $handler->display->display_options['fields']['field_medical_health_interv']['table'] = 'search_api_index_variable_index';
  $handler->display->display_options['fields']['field_medical_health_interv']['field'] = 'field_medical_health_interv';
  $handler->display->display_options['fields']['field_medical_health_interv']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_medical_health_interv']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_medical_health_interv']['alter']['text'] = '[field_medical_health_interv],';
  $handler->display->display_options['fields']['field_medical_health_interv']['link_to_entity'] = 1;
  $handler->display->display_options['fields']['field_medical_health_interv']['view_mode'] = 'full';
  /* Field: Indexed Node: Medication */
  $handler->display->display_options['fields']['field_medication']['id'] = 'field_medication';
  $handler->display->display_options['fields']['field_medication']['table'] = 'search_api_index_variable_index';
  $handler->display->display_options['fields']['field_medication']['field'] = 'field_medication';
  $handler->display->display_options['fields']['field_medication']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_medication']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_medication']['alter']['text'] = '[field_medication],';
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
  $handler->display->display_options['fields']['field_perception_of_health']['alter']['text'] = '[field_perception_of_health],';
  $handler->display->display_options['fields']['field_perception_of_health']['link_to_entity'] = 1;
  $handler->display->display_options['fields']['field_perception_of_health']['view_mode'] = 'full';
  /* Field: Indexed Node: Period */
  $handler->display->display_options['fields']['field_period']['id'] = 'field_period';
  $handler->display->display_options['fields']['field_period']['table'] = 'search_api_index_variable_index';
  $handler->display->display_options['fields']['field_period']['field'] = 'field_period';
  $handler->display->display_options['fields']['field_period']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_period']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_period']['alter']['text'] = '[field_period],';
  $handler->display->display_options['fields']['field_period']['link_to_entity'] = 1;
  $handler->display->display_options['fields']['field_period']['view_mode'] = 'full';
  /* Field: Indexed Node: Physical Environment */
  $handler->display->display_options['fields']['field_physical_environment']['id'] = 'field_physical_environment';
  $handler->display->display_options['fields']['field_physical_environment']['table'] = 'search_api_index_variable_index';
  $handler->display->display_options['fields']['field_physical_environment']['field'] = 'field_physical_environment';
  $handler->display->display_options['fields']['field_physical_environment']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_physical_environment']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_physical_environment']['alter']['text'] = '[field_physical_environment],';
  $handler->display->display_options['fields']['field_physical_environment']['link_to_entity'] = 1;
  $handler->display->display_options['fields']['field_physical_environment']['view_mode'] = 'full';
  /* Field: Indexed Node: Reproductive Health and History */
  $handler->display->display_options['fields']['field_reproductive_history']['id'] = 'field_reproductive_history';
  $handler->display->display_options['fields']['field_reproductive_history']['table'] = 'search_api_index_variable_index';
  $handler->display->display_options['fields']['field_reproductive_history']['field'] = 'field_reproductive_history';
  $handler->display->display_options['fields']['field_reproductive_history']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_reproductive_history']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_reproductive_history']['alter']['text'] = '[field_reproductive_history],';
  $handler->display->display_options['fields']['field_reproductive_history']['link_to_entity'] = 1;
  $handler->display->display_options['fields']['field_reproductive_history']['view_mode'] = 'full';
  /* Field: Indexed Node: Social Environment */
  $handler->display->display_options['fields']['field_social_environment']['id'] = 'field_social_environment';
  $handler->display->display_options['fields']['field_social_environment']['table'] = 'search_api_index_variable_index';
  $handler->display->display_options['fields']['field_social_environment']['field'] = 'field_social_environment';
  $handler->display->display_options['fields']['field_social_environment']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_social_environment']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_social_environment']['alter']['text'] = '[field_social_environment],';
  $handler->display->display_options['fields']['field_social_environment']['link_to_entity'] = 1;
  $handler->display->display_options['fields']['field_social_environment']['view_mode'] = 'full';
  /* Field: Indexed Node: Sociodemographic/Socioeconomic Characteristics */
  $handler->display->display_options['fields']['field_sociodemographic_charact']['id'] = 'field_sociodemographic_charact';
  $handler->display->display_options['fields']['field_sociodemographic_charact']['table'] = 'search_api_index_variable_index';
  $handler->display->display_options['fields']['field_sociodemographic_charact']['field'] = 'field_sociodemographic_charact';
  $handler->display->display_options['fields']['field_sociodemographic_charact']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_sociodemographic_charact']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_sociodemographic_charact']['alter']['text'] = '[field_sociodemographic_charact],';
  $handler->display->display_options['fields']['field_sociodemographic_charact']['link_to_entity'] = 1;
  $handler->display->display_options['fields']['field_sociodemographic_charact']['view_mode'] = 'full';
  /* Field: Indexed Node: Target */
  $handler->display->display_options['fields']['field_target']['id'] = 'field_target';
  $handler->display->display_options['fields']['field_target']['table'] = 'search_api_index_variable_index';
  $handler->display->display_options['fields']['field_target']['field'] = 'field_target';
  $handler->display->display_options['fields']['field_target']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_target']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_target']['alter']['text'] = '[field_target],';
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
  $handler->display->display_options['fields']['nothing']['label'] = 'Dimensions';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '[field_anthropometric_structures][field_body_functions][field_body_structures][field_medical_health_interv][field_medication][field_data_source][field_disease_history][field_individual_participant_mea][field_laboratory_measures][field_life_habits_behaviours][field_early_life][field_perception_of_health][field_period][field_physical_environment][field_reproductive_history][field_social_environment][field_sociodemographic_charact][field_measure][field_essence][field_target]';
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
  $translatables['variables_dimensions'] = array(
    t('Master'),
    t('Manage Variable Dimensions'),
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
    t('Assign dimensions'),
    t('Title'),
    t('Label'),
    t('Anthropometric Structures'),
    t('[field_anthropometric_structures],'),
    t('Body Functions'),
    t('[field_body_functions],'),
    t('Body Structures'),
    t('[field_body_structures],'),
    t('Data Source'),
    t('[field_data_source],'),
    t('Diseases History and Related Health Problems'),
    t('[field_disease_history],'),
    t('Essence'),
    t('[field_essence],'),
    t('Individual Participant Measures'),
    t('[field_individual_participant_mea],'),
    t('Laboratory Measures'),
    t('[field_laboratory_measures],'),
    t('Life Habits/Behaviours'),
    t('[field_life_habits_behaviours],'),
    t('Measure'),
    t('[field_measure],'),
    t('Medical Health Interventions/Health Services Utilization'),
    t('[field_medical_health_interv],'),
    t('Medication'),
    t('[field_medication],'),
    t('Participant\'s Early Life/Childhood'),
    t('[field_early_life],'),
    t('Perception of Health/Quality of life'),
    t('[field_perception_of_health],'),
    t('Period'),
    t('[field_period],'),
    t('Physical Environment'),
    t('[field_physical_environment],'),
    t('Reproductive Health and History'),
    t('[field_reproductive_history],'),
    t('Social Environment'),
    t('[field_social_environment],'),
    t('Sociodemographic/Socioeconomic Characteristics'),
    t('[field_sociodemographic_charact],'),
    t('Target'),
    t('[field_target],'),
    t('Description'),
    t('Dimensions'),
    t('[field_anthropometric_structures][field_body_functions][field_body_structures][field_medical_health_interv][field_medication][field_data_source][field_disease_history][field_individual_participant_mea][field_laboratory_measures][field_life_habits_behaviours][field_early_life][field_perception_of_health][field_period][field_physical_environment][field_reproductive_history][field_social_environment][field_sociodemographic_charact][field_measure][field_essence][field_target]'),
    t('Edit'),
    t('All'),
    t('Fulltext search'),
    t('Page'),
  );
  $export['variables_dimensions'] = $view;

  return $export;
}