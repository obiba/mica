<?php

function _mica_studies_population_view($node, $view_mode, $langcode) {
  _mica_studies_population_view_selection_criteria($node);
  _mica_studies_population_view_recruitment_sources($node);
  _mica_studies_population_view_nb_participants($node);
  $wrapper = entity_metadata_wrapper('node', $node);

  $show_draft = (strpos(current_path(), '/draft') > 0 || $node->status == NODE_NOT_PUBLISHED);
  $dce_rows = array();
  foreach ($wrapper->field_pop_dce->getIterator() as $dce_wrapper) {
    if (node_access('view', $dce_wrapper->value())) {
      $desc = NULL;
      if (!empty($dce_wrapper->value()->body)) {
        $desc = isset($dce_wrapper->value()->body{$langcode}[0]['summary'])?$dce_wrapper->value()->body{$langcode}[0]['summary']:$dce_wrapper->body->summary->value();
        if (empty($desc)) {
          $desc = $dce_wrapper->body->value->value();
        }
      }
      $dce_nid = $dce_wrapper->nid->value();
      // Hide DCE that are not published on study published page
      if ($wrapper->status->value() == $dce_wrapper->status->value() || $show_draft) {
        $dce_rows[$dce_nid] = array(
          'data' => array(
            'label' => l($dce_wrapper->title->value(), 'node/' . $dce_nid),
            'desc' => truncate_utf8($desc,50, TRUE, TRUE),
            'start_year' => $dce_wrapper->field_dce_start_year->value(),
            'start_month' => $dce_wrapper->field_dce_start_month->value(),
            'end_year' => $dce_wrapper->field_dce_end_year->value(),
            'end_month' => $dce_wrapper->field_dce_end_month->value(),
          )
        );

        if ($dce_wrapper->status->value() == NODE_NOT_PUBLISHED) {
          $dce_rows[$dce_nid]['class'] = array('node-unpublished');
        }
      }
    }
  }
  if (!empty($dce_rows)) {
    uasort($dce_rows, '_mica_studies_sort_dce');
    _mica_studies_population_normalize_rows($dce_rows);
    $node->content['data-collection-event'] = array(
      '#weight' => '100',
      '#theme' => 'table',
      '#caption' => t('Data Collection Events') . ': ',
      '#attributes' => array('class' => array('pop-dce')),
      '#header' => array(t('Name'), t('Description'), t('Start'), t('End')),
      '#rows' => $dce_rows,
    );
  }

  // Breadcrumbs
  $study_id = $wrapper->field_pop_study->nid->value();
  $breadcrumb = _mica_studies_menu_generate_breadcrumbs('node/' . $study_id);

  // generate specific breadcrumbs for population pages pages
  $current_breadcrumbs = menu_get_active_breadcrumb();
  if (!isset($current_breadcrumbs[1])) {
    $breadcrumbs = array();
    $breadcrumbs[] = l(t('Home'), '');
    for ($i = 0; $i < count($breadcrumb); $i++) {
      $breadcrumbs[] =l(truncate_utf8($breadcrumb[$i]['link_title'],45,true,true), $breadcrumb[$i]['link_path']);
    }
    drupal_set_breadcrumb($breadcrumbs);
  }
}

function _mica_studies_population_normalize_rows(&$dce_rows) {
  foreach ($dce_rows as &$dce_row) {
    $dce_row['data']['start'] = _mica_sudies_format_dce_year($dce_row['data']['start_year'], $dce_row['data']['start_month']);
    $dce_row['data']['end'] = _mica_sudies_format_dce_year($dce_row['data']['end_year'], $dce_row['data']['end_month']);
    unset($dce_row['data']['start_year']);
    unset($dce_row['data']['start_month']);
    unset($dce_row['data']['end_year']);
    unset($dce_row['data']['end_month']);
    unset($dce_row['data']['created']);
  }
}

function _mica_studies_population_view_selection_criteria($node) {

  $wrapper = entity_metadata_wrapper('node', $node->nid);

  if (!isset($node->content['field_pop_select_criteria'])) {
    // create empty field_pop_select_criteria if it has no values
    mica_core_create_empty_field($node, 'field_pop_select_criteria', 'above');
  }
    $_field_pop_select_criteria = field_view_field('node', $wrapper->value(), 'field_pop_select_criteria', array(
        'label' => 'inline',
        'weight' => 0,
        'type' => module_exists('i18n') ? 'i18n_list_default' : 'list_default',
    ));
$nbr_criteria = count($_field_pop_select_criteria['#items']);
    for($i=0 ; $i < $nbr_criteria ; $i++){
        $node->content['field_pop_select_criteria'][$i]['#markup'] = $_field_pop_select_criteria[$i]['#markup'];
    }

  _mica_studies_population_view_selection_criteria_item($node, $wrapper, 'field_pop_gender', t('Gender'));

  if (isset($node->content['field_pop_age_min']) || isset($node->content['field_pop_age_max'])) {
    $index = count($node->content['field_pop_select_criteria']['#items']);
    $age_min = $wrapper->field_pop_age_min->value();
    $age_max = $wrapper->field_pop_age_max->value();
    if (!empty($age_min) || !empty($age_max)) {
      $age_items = array();
      $age_markup = '';
      if (!empty($age_min)) {
        $age_items['age_min'] = $node->content['field_pop_age_min']['#items'][0];
        $age_markup .= t('minimum') . ' ' . $node->content['field_pop_age_min'][0]['#markup'];
      }
      if (!empty($age_max)) {
        if (!empty($age_min)) {
          $age_markup .= ', ';
        }
        $age_items['age_max'] = $node->content['field_pop_age_max']['#items'][0];
        $age_markup .= t('maximum') . ' ' . $node->content['field_pop_age_max'][0]['#markup'];
      }
      $node->content['field_pop_age_max']['#access'] = FALSE;
      $node->content['field_pop_age_min']['#access'] = FALSE;
      $node->content['field_pop_select_criteria']['#items'][$index] = $age_items;

      $label_value = t('Age');
      $markup = ucfirst($age_markup);
      $node->content['field_pop_select_criteria'][$index]['#markup'] = "<div class='inner-label'>$label_value:</div>"
        . "<div class='inner-value'>$markup</div>";
    }
  }

    ini_set('error_reporting', E_ALL ^ E_NOTICE);
  _mica_studies_population_view_selection_criteria_item($node, $wrapper, 'field_pop_country', t('Country'), t('Countries'));
  _mica_studies_population_view_selection_criteria_item($node, $wrapper, 'field_pop_territory', t('Territory'), t('Territories'));
  _mica_studies_population_view_selection_criteria_item($node, $wrapper, 'field_pop_ethnic_origin', t('Ethnic origin'), t('Ethnic origins'));
  _mica_studies_population_view_selection_criteria_item($node, $wrapper, 'field_pop_health_status', t('Health status'));
  _mica_studies_population_view_selection_criteria_item($node, $wrapper, 'field_pop_selection_others_sp', t('Other'));
  _mica_studies_population_view_selection_criteria_item($node, $wrapper, 'field_pop_partcipant_sel_supp_in', t('Supplementary information'));
    ini_set('error_reporting', E_ALL);
  if (strlen($node->content['field_pop_select_criteria'][0]['#markup']) === 0) {
    $node->content['field_pop_select_criteria']['#access'] = FALSE;
  }
}

function _mica_studies_population_view_selection_criteria_item(&$node, $wrapper, $field, $label, $label_plural = null) {
    if (!isset($node->content[$field])) {
        return;
    }
    $_value_field = $wrapper->$field->value();
    $field_value = field_view_field('node', $node, $field, array(
        'label' => 'inline',
        'weight' => 1,
      'type' => (module_exists('i18n')) ? 'i18n_list_default': 'list_default'
    ));

    if (!empty($_value_field)) {
        $nb_items = isset($_value_field['value']) ? 1 : count($field_value['#items']);
        $index = count($node->content['field_pop_select_criteria']['#items']);
        $node->content['field_pop_select_criteria']['#items'][$index] = $node->content[$field]['#items'];

        $markup = '<div class="inner-value">';
        for ($i = 0; $i < $nb_items; $i++) {
            $markup .= $field_value[$i]['#markup'];
            if ($i < $nb_items - 1) {
                $markup .= ', ';
            }
        }
        $markup .= '</div>';

        $node->content['field_pop_select_criteria'][$index]['#markup'] = '<div class="inner-label">'
            . t('@label', array('@label' => $nb_items > 1 && strlen($label_plural) > 0 ? $label_plural : $label)) . ':</div>'
            . $markup;
        $node->content[$field]['#access'] = FALSE;
    }

}




function _mica_studies_population_view_recruitment_sources(&$node) {

  $wrapper = entity_metadata_wrapper('node', $node);

  if (!isset($node->content['field_pop_src_recruit'])) {
    // create empty field_pop_src_recruit if it has no values
   mica_core_create_empty_field($node, 'field_pop_src_recruit');
  }

  $src_recruit = $wrapper->field_pop_src_recruit->value();

    $field_view_src_recruit = field_view_field('node', $wrapper->value(), 'field_pop_src_recruit', array(
        'label' => 'inline',
        'weight' => 11,
        'type' => module_exists('i18n') ? 'i18n_list_default' : 'list_default',
    ));

    $node->content['field_pop_src_recruit'] = $field_view_src_recruit;

  $general_index = array_search('general', $src_recruit);
  if ($general_index !== FALSE) {
    $_pop_general_pop_recruit = $wrapper->field_pop_general_pop_recruit->value();

      $field_pop_general_pop_recruit = field_view_field('node', $wrapper->value(), 'field_pop_general_pop_recruit', array(
          'label' => 'inline',
          'weight' => 12,
          'type' => module_exists('i18n') ? 'i18n_list_default' : 'list_default',
      ));

    if (!empty($_pop_general_pop_recruit)) {
      $nb = count($_pop_general_pop_recruit);
      $content_pop_recuit_general = array();
      for ($i = 0; $i < $nb; $i++) {
          $content_pop_recuit_general[$i] = $field_pop_general_pop_recruit[$i]['#markup'];
      }
      $node->content['field_pop_src_recruit'][$general_index]['#markup'] = '<div class="inner-label">'
        . $node->content['field_pop_src_recruit'][$general_index]['#markup']
        . ':</div><div class="inner-value">'
        . implode(', ', $content_pop_recuit_general)
        . '</div>';

      $node->content['field_pop_general_pop_recruit']['#access'] = FALSE;
    }
  }

  $exist_studies_index = array_search('exist_studies', $src_recruit);
  if ($exist_studies_index !== FALSE) {
    $_pop_exist_study_part = $wrapper->field_pop_exist_study_part->value();
      $field_pop_exist_study_part = field_view_field('node', $node, 'field_pop_exist_study_part', array(
          'label' => 'inline',
          'weight' => 13,
      ));

    if (!empty($_pop_exist_study_part)) {
      $nb = count($_pop_exist_study_part);
      $content_exist_study = array();
      for ($i = 0; $i < $nb; $i++) {
          $content_exist_study[$i] = $field_pop_exist_study_part[$i]['#markup'];
      }
      $node->content['field_pop_src_recruit'][$exist_studies_index]['#markup'] = '<div class="inner-label">'
        . $node->content['field_pop_src_recruit'][$exist_studies_index]['#markup']
        . ':</div><div class="inner-value">'
        . implode(', ', $content_exist_study)
        . '</div>';
      $node->content['field_pop_exist_study_part']['#access'] = FALSE;
    }
  }


  $specific_population_index = array_search('specific_population', $src_recruit);
  if ($specific_population_index !== FALSE) {
    $_pop_specific_pop = $wrapper->field_pop_specific_pop->value();
      $field_pop_specific_pop = field_view_field('node', $wrapper->value(), 'field_pop_specific_pop', array(
          'label' => 'inline',
          'weight' => 12,
          'type' => module_exists('i18n') ? 'i18n_list_default' : 'list_default',
      ));

    if (!empty($_pop_specific_pop)) {

      $nb = count($_pop_specific_pop);
      $content_speci_pop = array();
      for ($i = 0; $i < $nb; $i++) {
          $content_speci_pop[$i] = $field_pop_specific_pop[$i]['#markup'];
      }
      $node->content['field_pop_specific_pop']['#access'] = FALSE;
        $other_index_spec_pop = array_search('other', $_pop_specific_pop);
        if ($other_index_spec_pop !== FALSE) {
            $field_pop_specific_pop_other_sp = $wrapper->field_pop_specific_pop_other_sp->value();
            if (!empty($field_pop_specific_pop_other_sp)) {
                $_labal_other = $content_speci_pop[$other_index_spec_pop];
                $content_speci_pop[$other_index_spec_pop] = NULL;
                $node->content['field_pop_src_recruit'][$specific_population_index]['#markup'] = '<div class="inner-label">'
                    . $node->content['field_pop_src_recruit'][$specific_population_index]['#markup']
                    . ':</div><div class="inner-value">'
                    . implode(', ', $content_speci_pop)
                    . '</div>'
                    .'<div class="inner-label"><br />'
                    .$_labal_other
                    . ':</div><div class="inner-value">'
                    .$node->content['field_pop_specific_pop_other_sp'][0]['#markup']
                    . '</div>';

                $node->content['field_pop_specific_pop_other_sp']['#access'] = FALSE;
            }
            else {
                $node->content['field_pop_src_recruit'][$specific_population_index]['#markup'] = '<div class="inner-label">'
                    . $node->content['field_pop_src_recruit'][$specific_population_index]['#markup']
                    . ':</div><div class="inner-value">'
                    . implode(', ', $content_speci_pop)
                    . '</div>';
            }
        }

    }
  }

  $other_index = array_search('other', $src_recruit);
  if ($other_index !== FALSE) {
    $field_pop_recruitment_other = $wrapper->field_pop_recruitment_other->value->value();
    if (!empty($field_pop_recruitment_other)) {

      $node->content['field_pop_src_recruit'][$other_index]['#markup'] = '<div class="inner-label">'
        . $node->content['field_pop_src_recruit'][$other_index]['#markup']
        . ':</div><div class="inner-value">'
        .  $node->content['field_pop_src_recruit'][$other_index]['#markup']
        . '</div>';

      $node->content['field_pop_recruitment_other']['#access'] = FALSE;
    }
  }

  $field_pop_recruit_supp_info = $wrapper->field_pop_recruit_supp_info->value();
  if (!empty($field_pop_recruit_supp_info)) {

    $index = count($node->content['field_pop_src_recruit']['#items']);
    $node->content['field_pop_src_recruit']['#items'][$index] = $node->content['field_pop_recruit_supp_info']['#items'];
    $node->content['field_pop_src_recruit'][$index]['#markup'] = '<div class="inner-label">' . t('Supplementary information') . ':</div>'
      . '<div class="inner-value">' . $node->content['field_pop_recruit_supp_info'][0]['#markup'] . '</div>';
    $node->content['field_pop_recruit_supp_info']['#access'] = FALSE;
  }

  if (strlen($node->content['field_pop_src_recruit'][0]['#markup']) === 0) {
    $node->content['field_pop_src_recruit']['#access'] = FALSE;
  }
}

function _mica_studies_population_view_nb_participants(&$node) {
  _mica_studies_population_view_nb($node, 'field_pop_participants_nb', 'field_pop_no_limits_participants');
  _mica_studies_population_view_nb($node, 'field_pop_participants_nb_s', 'field_pop_no_lim_participants_s');

}

function _mica_studies_population_view_nb(&$node, $field_nb, $field_no_limit) {
  $wrapper = entity_metadata_wrapper('node', $node->nid);
  if (!isset($node->content[$field_nb])) {
    mica_core_create_empty_field($node, $field_nb);
  }

  $index = count($node->content[$field_nb]['#items']);

  $no_limit = $wrapper->{$field_no_limit}->value();
  if ($no_limit) {
    $node->content[$field_nb]['#items'][$index] = t('No limit');
    $node->content[$field_nb][$index]['#markup'] = t('No limit');
  }
  $node->content[$field_no_limit]['#access'] = FALSE;

  if (strlen($node->content[$field_nb][0]['#markup']) === 0) {
    $node->content[$field_nb]['#access'] = FALSE;
  }
}

/**
 * Delete all populations and DCE associated with the study
 */
function _mica_studies_population_delete($population) {
  $population_wrapper = entity_metadata_wrapper('node', $population->nid);
  watchdog('mica', 'Delete cascade for %population', array('%population' => $population_wrapper->title->value()), WATCHDOG_DEBUG);
  foreach ($population_wrapper->field_pop_dce->getIterator() as $dce_wrapper) {
    $nb_dce_pops = count($dce_wrapper->field_dce_population->value());
    // population is already deleted
    if ($nb_dce_pops === 0) {
      watchdog('mica', 'Delete cascade DCE %dce', array('%dce' => $dce_wrapper->title->value()), WATCHDOG_DEBUG);
      $dce_wrapper->delete();
    }
  }
}