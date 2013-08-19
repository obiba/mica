<?php

/**
 * @file
 * Mica Dataset Harmonization page
 */

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

  $is_bootstrap = mica_core_is_bootstrap_based_theme();
  if (!$is_bootstrap) {
    mica_core_include_bootstrap_css();
    mica_core_prepare_tooltip();
  }

  $icon_bkg = $is_bootstrap ? '' : 'icon-white';

  ctools_add_css('mica_datasets', 'mica_datasets');

  $popovers = array();
  $rows = array();

  $wrapper = entity_metadata_wrapper('node', $dataset_node);
  $variables = $wrapper->field_dataset_variables->value();
  $studies = $wrapper->field_dataset_studies->value();

  $status_values = field_info_field('field_sva_status');
  $studies_by_id = array();

  $count_variables = 0;
  $header[] = '';
  foreach ($studies as $study) {

    if (node_access('view', $study)) {
      $study_wrapper = entity_metadata_wrapper('node', $study);
      $acronym = $study_wrapper->field_acroym->value();
      $name = empty($acronym) ? $study_wrapper->title->value() : $study_wrapper->field_acroym->value();

      $studies_by_id[$study_wrapper->nid->value()] = $name;

      // See http://www.jide.fr/english/using-ajax-in-drupal-7-outside-of-form-api
      // show link only for studies that have an opal connection
      if (node_access('update', $dataset_node)
        && mica_connector_query($wrapper->nid->value(), $study_wrapper->nid->value(), TRUE)
      ) {
        $refresh_link = l(
          "<i class='icon-refresh $icon_bkg'></i>",
          'node/' . $wrapper->nid->value() . '/import-variables/' . $study_wrapper->nid->value(),
          array(
            'html' => TRUE,
            'attributes' => array(
              'title' => t('Refresh harmonization of %study', array('%study' => $name))
            )
          )
        );
      }
      else {
        $refresh_link = '';
      }

      $opal_xml = l(
        "<i class='icon-download-alt $icon_bkg'></i>",
        'opal-export/node/' . $wrapper->uuid->value(),
        array(
          'html' => TRUE,
          'attributes' => array(
            'title' => t('Export an Opal View for %study', array('%study' => $name))
          ),
          'query' => array(
            'study' => $study_wrapper->nid->value(),
          ),
        )
      );

      $header[] = "<div class='study-title'>$name</div><div class='study-actions'>$refresh_link $opal_xml</div>";
    }
  }

  if (!empty($variables) && !empty($studies)) {

    // sort variables based on their field_position
    uasort($variables, 'mica_datasets_sort_by_position');

    // Add rows to the harmonization table
    foreach ($variables as $variable) {
      if (node_access('view', $variable)) {

        $count_variables++;
        $link_id = 'variable_' . $variable->nid;
        $variable_wrapper = entity_metadata_wrapper('node', $variable);
        $variable_link = l($variable->title, 'node/' . $variable->nid, array(
            'attributes' => array(
              'id' => $link_id,
              'class' => $is_bootstrap ? '' : 'tooltip',
              'data-original-title' => $variable_wrapper->field_label->value(),
              'data-content' => $variable_wrapper->body->value() ? $variable_wrapper->body->value->value() : '',
            )
          )
        );
        if ($is_bootstrap) {
          $popovers[] = $link_id;
        }
        else {
          $variable_link .= '<div id="variable_' . $variable->nid . '_tooltip" class="tooltip-content">'
            . _mica_datasets_harmonization_variable_tooltip($variable_wrapper)
            . '</div>';
        }

        $row = array('name' => $variable_link);

        $sva_query = new EntityFieldQuery();
        $sva_results = $sva_query->entityCondition('entity_type', 'node')
          ->entityCondition('bundle', 'study_variable_attributes')
          ->fieldCondition('field_sva_variable', 'nid', $variable->nid)
          ->execute();
        $svas = empty($sva_results['node']) ? array() : node_load_multiple(array_keys($sva_results['node']));

        if (!empty($svas)) {
          foreach ($studies_by_id as $study_id => $study_name) {
            foreach ($svas as $study_variable_attributes) {

              $sva_wrapper = entity_metadata_wrapper('node', $study_variable_attributes);

              $sva_nid = $study_variable_attributes->nid;

              $sva_study = $sva_wrapper->field_sva_study->value();
              if (!empty($sva_study)) {
                $sva_study_id = $sva_wrapper->field_sva_study->nid->value();
                // get the sva that match the study id
                if ($sva_study_id == $study_id) {

                  $script = $sva_wrapper->field_sva_script->value() ? $sva_wrapper->field_sva_script->value() : '';
                  $comment = $sva_wrapper->field_sva_comment->value() ? $sva_wrapper->field_sva_comment->value() : '';
                  $status = $sva_wrapper->field_sva_status->value();

                  if ($sva_wrapper->access('view') == FALSE) {
                    $status = 'forbidden';
                    $status_label = t('Access Denied');
                    $script = NULL;
                    $comment = NULL;
                  }
                  elseif (!empty($status) && array_key_exists($status, $status_values['settings']['allowed_values'])) {
                    $status_label = $status_values['settings']['allowed_values'][$status];
                  }
                  else {
                    $status = 'undetermined';
                    $status_label = t('Undetermined');
                    $script = NULL;
                  }

                  $sva_link_id = "sva_$sva_nid";
                  $sva_url = url('node/' . $sva_nid);
                  $sva_css_class = $is_bootstrap ? '' : 'tooltip';
                  $sva_img = _mica_datasets_get_status_icon($status);
                  $sva_tooltip_title = t('Status: %status', array('%status' => $status_label));
                  $sva_tooltip_content = '';
                  if (!empty($comment)) {
                    $sva_tooltip_content .= t('Comment: %comment', array(
                      '%comment' => _mica_datasets_html_truncated($comment, t('Comment'))
                    ));
                  }
                  if (!empty($script)) {
                    $sva_tooltip_content .= t('Script: %script', array(
                      '%script' => _mica_datasets_html_truncated($script, t('Script'), 200, TRUE)
                    ));
                  }

                  $sva_link = "<a href='$sva_url' id='$sva_link_id' class='$sva_css_class' "
                    . "data-original-title='$sva_tooltip_title' data-content='$sva_tooltip_content'><img src='$sva_img' /></a>";

                  if ($is_bootstrap) {
                    $popovers[] = $sva_link_id;
                  }
                  else {
                    $sva_link .= '<div id="sva_' . $sva_nid . '_tooltip" class="tooltip-content">'
                      . _mica_datasets_harmonization_sva_tooltip($status_label, $comment, $script)
                      . '</div>';
                  }

                  $row[$studies_by_id[$study_id]] = array(
                    'data' => array(
                      '#type' => 'markup',
                      '#markup' => $sva_link,
                    ),
                    'class' => array('center sva-status')
                  );

                  break;
                }
              }
            }
          }
          $rows[] = $row;
        }
      }
    }
  }

  $header[0] = t('Variables (%nb)', array('%nb' => $count_variables));

  $output = drupal_render(drupal_get_form('mica_datasets_harmonization_legend_form'));
  $output .= '<br/>';
  $output .= theme(
    'table',
    array(
      'header' => $header,
      'rows' => $rows,
      'empty' => t('No harmonization found'),
      'sticky' => FALSE,
      'attributes' => array('id' => 'harmonization_overview')
    )
  );

  mica_datasets_prepare_prettify();

  $jquery_popover = '';
  foreach ($popovers as $popover) {
    $jquery_popover .= "jQuery('#$popover').popover({ html: true, placement: 'top', trigger: 'hover' }); ";
  }
  drupal_add_js("jQuery(function () { $jquery_popover });", 'inline');

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
    . t("the study assessment item(s) (e.g. survey question, physical measure, biochemical measure) allow construction of the variable as defined in the dataset.")
    . "</i><br />",
  );
  $form['legend']['impossible'] = array(
    '#type' => 'markup',
    '#markup' => "<img src=\"" . MICA_HARMONIZATION_IMPOSSIBLE . "\" style=\"vertical-align: middle\">&nbsp;<b>"
    . t("Impossible") . "</b> - <i>"
    . t("there is no information or insufficient information collected by this study to allow the construction of the variable as defined in the dataset.")
    . "</i>",
  );

  return $form;
}

function _mica_datasets_harmonization_variable_tooltip($wrapper) {
  $tooltip = '<h4>' . $wrapper->field_label->value() . '</h4>';
  $body = $wrapper->body->value() ? $wrapper->body->value->value() : '';
  if (!empty($body)) {
    $tooltip .= $body;
  }
  return $tooltip;
}

function _mica_datasets_harmonization_sva_tooltip($status_label, $comment, $script) {
  $tooltip = '<table class="sva-tooltip"><tr><th>' . t('Status') . '</th><td>' . $status_label . '</td></tr>';

  if (!empty($comment)) {
    $tooltip .= '<tr><th>' . t('Comment') . '</th><td>'
      . _mica_datasets_html_truncated($comment, t('Comment'))
      . '</td></tr>';
  }

  if (!empty($script)) {
    $tooltip .= '<tr><th>' . t('Script') . '</th><td>'
      . _mica_datasets_html_truncated($script, t('Script'), 200, TRUE)
      . '</td></tr>';
  }
  $tooltip .= '</table>';

  return $tooltip;
}