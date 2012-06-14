<?php

/*
 * Menu for callback of refresh harmonization
 */

include_once('mica_datasets.utils.inc');

/**
 * Display queries.
 */
function mica_datasets_dataset_harmonization_page($dataset_node) {
  drupal_set_title(t('!title -- Harmonization', array('!title' => $dataset_node->title)));

  drupal_add_library('system', 'drupal.ajax');
  drupal_add_library('system', 'jquery.form');

  //prettify
  ctools_add_css('prettify', 'mica_datasets');
  ctools_add_js('prettify', 'mica_datasets');
  ctools_add_js('mica_datasets_harmonization', 'mica_datasets');

  // tooltips
  ctools_add_js('jquery.tooltip.min', 'mica_core');
  ctools_add_js('mica_core_tooltip', 'mica_core');
  ctools_add_css('jquery.tooltip', 'mica_core');
  ctools_add_css('mica_core_tooltip', 'mica_core');

  ctools_add_css('mica_datasets', 'mica_datasets');

  $header = array(
    'name' => t('Variable'),
  );

  $options = array();

  $wrapper = entity_metadata_wrapper('node', $dataset_node);
  $variables = $wrapper->field_dataset_variables->value();
  $studies = $wrapper->field_dataset_studies->value();

  $status_values = field_info_field('field_sva_status');
  $header_ids = array();
  foreach ($studies as $study) {
    if (node_access('view', $study)) {
      $study_wrapper = entity_metadata_wrapper('node', $study);
      $acronym = $study_wrapper->field_acroym->value();
      $name = !empty($acronym) ? $study_wrapper->field_acroym->value() : $study_wrapper->title->value();

      // See http://www.jide.fr/english/using-ajax-in-drupal-7-outside-of-form-api
      // show link only for studies that have an opal connection
      if (node_access('update', $dataset_node) && mica_dataset_connector_query($wrapper->nid->value(), $study_wrapper->nid->value())) {
        $ajax_link = l(
          "<img src='" . MICA_HARMONIZATION_REFRESH . "' class='harmonization-refresh-icon' title='Refresh harmonization of $name'/>",
          'mica_datasets_harmonization/ajax/' . $wrapper->nid->value() . '/' . $study_wrapper->nid->value(),
          array('html' => TRUE, 'attributes' => array('class' => array('use-ajax')))
        );
      }
      else {
        $ajax_link = '';
      }

      $header[] = "<div class='harmonization-study-title'>$name$ajax_link</div><br>";

      $header_ids[$study_wrapper->nid->value()] = $name;
    }
  }

  if (!empty($variables) && !empty($studies)) {

    uasort($variables, 'mica_datasets_sort_by_position');

    // sort variables based on their field_position
    // get the ids of all study_variable_attributes and load at once
    $svids = array();
    foreach ($variables as $variable) {
      if (isset($variable->field_variable_study_var_att[$variable->language])) {
        foreach ($variable->field_variable_study_var_att[$variable->language] as $study_variable_attributes) {
          $svids[] = $study_variable_attributes['nid'];
        }
      }
    }
    $svas = node_load_multiple($svids);

    // Add rows to the harmonization table
    foreach ($variables as $variable) {
      if (node_access('view', $variable)) {

        $variable_link = l($variable->title, 'node/' . $variable->nid, array(
            'attributes' => array(
              'id' => 'variable_' . $variable->nid,
              'class' => 'tooltip',
            )
          )
        );
        $variable_link .= '<div id="variable_' . $variable->nid . '_tooltip" class="tooltip-content">'
          . _mica_datasets_harmonization_variable_tooltip($variable)
          . '</div>';

        $option = array('name' => $variable_link);

        if (!empty($variable->field_variable_study_var_att[$variable->language])) {
          foreach (array_keys($header_ids) as $header_id) {
            foreach ($variable->field_variable_study_var_att[$variable->language] as $study_variable_attributes) {

              $sva_nid = $study_variable_attributes['nid'];

              if (!empty($svas[$sva_nid]->field_sva_study)) {
                $study_id = $svas[$sva_nid]->field_sva_study[LANGUAGE_NONE][0]['nid'];
                // get the sva that match the study id
                if ($study_id == $header_id) {
                  $sva_node = $svas[$sva_nid];
                  if (array_key_exists($study_id, $header_ids)) {
                    $sva_wrapper = entity_metadata_wrapper('node', $sva_node);

                    $script = $sva_wrapper->field_sva_script->value() ? $sva_wrapper->field_sva_script->value() : '';
                    $comment = $sva_wrapper->field_sva_comment->value() ? $sva_wrapper->field_sva_comment->value() : '';

                    if ($sva_wrapper->access('view') == FALSE) {
                      $status = 'forbidden';
                      $status_label = t('Access Denied');
                      $script = NULL;
                      $comment = NULL;
                    }
                    elseif (!empty($sva_node->field_sva_status)
                      && array_key_exists($sva_wrapper->field_sva_status->value(), $status_values['settings']['allowed_values'])
                    ) {
                      $status = $sva_wrapper->field_sva_status->value();
                      $status_label = $status_values['settings']['allowed_values'][$status];
                    }
                    else {
                      $status = 'undetermined';
                      $status_label = t('Undetermined');
                      $script = NULL;
                    }

                    $sva_link = '<a href="' . url('node/' . $sva_nid) . '" id="sva_' . $sva_nid
                      . '" class="tooltip"><img src="' . _mica_datasets_get_status_icon($status) . '" /></a>';
                    $sva_link .= '<div id="sva_' . $sva_nid . '_tooltip" class="tooltip-content">'
                      . _mica_datasets_harmonization_sva_tooltip($status_label, $comment, $script)
                      . '</div>';
                    $option[$header_ids[$study_id]]['data'][] = array(
                      '#type' => 'markup',
                      '#markup' => $sva_link,
                    );
                  }
                  break;
                }
              }
            }
          }
          $options[] = $option;
        }
      }
    }
  }
  unset($svas);

  $output = drupal_render(drupal_get_form('mica_datasets_harmonization_legend_form'));
  $output .= '<br/>';
  $output .= theme(
    'table',
    array(
      'header' => $header,
      'rows' => $options,
      'empty' => t('No harmonization found'),
      'sticky' => FALSE,
      'attributes' => array('id' => 'harmonization_overview')
    )
  );

  return '<div id=\'harmonization_overview_wrapper\'>' . $output . '</div>';
}


function mica_datasets_harmonization_legend_form($form, $form_state) {
  $form['legend'] = array(
    '#type' => 'container',
  );
  $form['legend']['undetermined'] = array(
    '#type' => 'markup',
    '#markup' => "<img src=\"" . MICA_HARMONIZATION_UNDETERMINED . "\" style=\"vertical-align: middle\">&nbsp;<b>"
      . t("Undetermined") . "</b> - <i>"
      . t("the harmonization potential of this variable has not yet been evaluated.")
      . "</i><br />",
  );
  $form['legend']['complete'] = array(
    '#type' => 'markup',
    '#markup' => "<img src=\"" . MICA_HARMONIZATION_COMPLETE . "\" style=\"vertical-align: middle\">&nbsp;<b>"
      . t("Complete") . "</b> - <i>"
      . t(
        "the study assessment item(s) (e.g. survey question, physical measure, biochemical measure) allow construction of the variable as defined in the dataset."
      )
      . "</i><br />",
  );
  $form['legend']['impossible'] = array(
    '#type' => 'markup',
    '#markup' => "<img src=\"" . MICA_HARMONIZATION_IMPOSSIBLE . "\" style=\"vertical-align: middle\">&nbsp;<b>"
      . t("Impossible") . "</b> - <i>"
      . t(
        "there is no information or insufficient information collected by this study to allow the construction of the variable as defined in the dataset."
      )
      . "</i>",
  );

  return $form;
}

function _mica_datasets_harmonization_variable_tooltip($variable) {
  $wrapper = entity_metadata_wrapper('node', $variable);
  $tooltip = '<h4>' . $wrapper->field_label->value() . '</h4>';
  $body = $wrapper->body->value->value();
  if (!empty($body)) $tooltip .= $body;
  return $tooltip;
}

function _mica_datasets_harmonization_sva_tooltip($status_label, $comment, $script) {
  $tooltip = '<table class="sva-tooltip"><tr><th>' . t('Status') . '</th><td>' . $status_label . '</td></tr>';

  if (!empty($comment)) {
    $tooltip .= '<tr><th>' . t('Comment') . '</th><td>'
      . _mica_datasets_toHtmlTruncate($comment, t('Comment'))
      . '</td></tr>';
  }

  if (!empty($script)) {
    $tooltip .= '<tr><th>' . t('Script') . '</th><td>'
      . _mica_datasets_toHtmlTruncate($script, t('Script'), 200, TRUE)
      . '</td></tr>';
  }
  $tooltip .= '</table>';

  return $tooltip;
}