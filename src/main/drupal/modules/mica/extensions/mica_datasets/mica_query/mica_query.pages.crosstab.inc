<?php

require_once(drupal_get_path('module', 'mica_datasets') . '/mica_datasets.utils.inc');

function mica_query_crosstab_run_page($form, &$form_state, $dataset, $variable, $cross_variable) {
  ctools_add_css('mica_query', 'mica_query');

  drupal_set_breadcrumb();
  drupal_set_title(t('!title -- Crosstab', array('!title' => $dataset->title)));

  $categorical_variables = mica_datasets_find_categorical_variables($dataset->nid);
  $options = array();
  foreach ($categorical_variables as $v) {
    if (node_access('view', $v)) {
      $options[$v->nid] = $v->title;
    }
  }

  $form_state['mica']['dataset_node'] = $dataset;
  $form['variable'] = array(
    '#type' => 'select',
    '#title' => t('Select a dependent variable'),
    '#options' => $options,
    '#default_value' => empty($variable) ? NULL : $variable,
    '#empty_options' => -1,
    '#empty_value' => ' - ' . t('None') . ' - ',
  );

  $cross_options = array();
  foreach (mica_dataset_dataset_variables($dataset->nid, TRUE) as $v) {
    if (node_access('view', $v)) {
      $cross_options[$v->nid] = $v->title;
    }
  }

  $form['cross_variable'] = array(
    '#type' => 'select',
    '#multiple' => TRUE,
    '#size' => 6,
    '#title' => t('Cross with'),
    '#options' => $cross_options,
    '#default_value' => empty($cross_variable) ? NULL : $cross_variable,
    '#empty_options' => -1,
    '#empty_value' => ' - ' . t('None') . ' - ',
  );

  $form['submit'] = array(
    '#type' => 'button',
    '#value' => t('Submit'),
    //'#disabled' => TRUE,
    '#ajax' => array(
      'callback' => 'mica_query_crosstab_run_page_submit_callback',
    ),
  );

  $form['results'] = array(
    '#markup' => '', //$result_table,
    '#prefix' => '<div id="result-wrapper">',
    '#suffix' => '</div>',
  );
  return $form;
}

/**
 * Selects just the result table to be returned for re-rendering.
 */
function mica_query_crosstab_run_page_submit_callback($form, $form_state) {

  if (!empty($form_state['values']['cross_variable'])) {
    $dataset_node = $form_state['mica']['dataset_node'];

    $variable_node = node_load($form_state['values']['variable']);

    $values = array();
    $values['name'] = check_plain('ssas');
    $values['dataset_id'] = $dataset_node->nid;
    $values['cross_variable_id'] = NULL;
    $values['variable_id'] = $variable_node->nid;
    $values['module'] = 'mica_datasets';
    foreach (entity_metadata_wrapper('node', $variable_node)->field_variable_categories->value() as $category) {
      if ($category['missing'] === '0') {
        $values['options']['categories'][] = $category['name'];
      }
    }
    $query = MicaDatasetQueryManager::addQuery($values);
    $query->is_new = TRUE;
    MicaDatasetQueryManager::getCache($query)->addTerm($values);

    // Variable description
    $variable_wrapper = entity_metadata_wrapper('node', $variable_node->nid);
    $result_table = '<div class="dependent-variable-description"><span class="variable-title">' . $variable_wrapper->title->value() . '</span> ('
      . $variable_wrapper->field_label->value() . ')</div>';
    foreach ($variable_wrapper->field_variable_categories->value() as $category) {
      if ($category['missing'] == FALSE) {
        $result_table .= $category['name'] . ' : ' . $category['label'] . '<br>';
      }
    }

    foreach ($variable_wrapper->field_variable_categories->value() as $category) {
      if ($category['missing'] == FALSE) {
        $category_label_by_name[$category['name']] = $category['label'];
      }
    }

    foreach ($form_state['values']['cross_variable'] as $cross_variable_id) {
      $cross_variable = node_load($cross_variable_id);
      $cross_variable_wrapper = entity_metadata_wrapper('node', $cross_variable);
      $result_table .= '<div class="crosstab-result">Crosstabulation results with <span class="variable-title">' . $cross_variable_wrapper->title->value()
        . '</span> (' . $cross_variable_wrapper->field_label->value() . ')</div>';
      $result_table .= _mica_query_crosstab_result_table($dataset_node, $query, $cross_variable);
    }
  }
  else{
    $result_table = '<div class="no-results">No \'cross with\' variable(s) have been selected.</div>';
  }

  return array(
    '#type' => 'ajax',
    '#commands' => array(
      ajax_command_html("#result-wrapper", $result_table),
      //ajax_command_html("#cross-variable-detail", _mica_datasets_query_cross_variable_detail_link($cross_variable)),
    )
  );
}

function _mica_query_crosstab_result_table($dataset_node, $query, $cross_variable) {
  $output = '';

  $category_label_by_name = array();

  $variable_wrapper = entity_metadata_wrapper('node', $query->variable_id);
  foreach ($variable_wrapper->field_variable_categories->value() as $category) {
    if ($category['missing'] == FALSE) {
      $category_label_by_name[$category['name']] = $category['label'];
    }
  }

  $cross_variable_wrapper = entity_metadata_wrapper('node', $cross_variable);
  $is_continuous = TRUE;
  $cross_category_label_by_name = array();
  foreach ($cross_variable_wrapper->field_variable_categories->value() as $category) {
    if ($category['missing'] == FALSE) {
      $cross_category_label_by_name[$category['name']] = $category['label'];
      $is_continuous = FALSE;
    }
  }

  $mica_dataset_connectors = mica_dataset_connector_query_multiple($dataset_node->nid);
  $terms = mica_dataset_query_term_query($query);

  $rows = array();

  // Process header
  if (count($mica_dataset_connectors) > 0) {
    $headers = _mica_query_process_header($category_label_by_name, $terms);
    $sub_header = _mica_query_process_subheader($cross_variable_wrapper, $category_label_by_name);
    $rows[] = array('data' => $sub_header);
  }

  $study_rowspan = $is_continuous ? 1 : count($cross_category_label_by_name) + 1; // account for N
  $totals = array();
  foreach ($mica_dataset_connectors as $connector) {
    $row = array();

    $study = node_load($connector->study_id);
    $study_wrapper = entity_metadata_wrapper('node', $study);
    $acronym = $study_wrapper->field_acroym->value();
    $name = !empty($acronym) ? $study_wrapper->field_acroym->value() : $study_wrapper->title->value();

    $row[] = array(
      'data' => filter_xss($name),
      'class' => array('border-right', 'border-bottom'),
      'rowspan' => $study_rowspan,
    );

    try {
      $result = $connector->crossQueryBy($terms, array($cross_variable->title, $is_continuous));

      foreach ($terms as $term) {

        if (!$is_continuous) {
          // Cross categories
          // N
          $row[] = array(
            'data' => t('N'),
            'class' => array('border-right'),
          );
          $N_total = 0;
          foreach ($category_label_by_name as $name => $label) {
            $value = isset($result['_matched'][$name]) ? $result['_matched'][$name] : 0;
            $row[] = array(
              'data' => $value,
              'title' => $value,
            );
            $N_total += $value;
            if (isset($totals[$name]['N'])) {
              $totals[$name]['N'] += $value;
            }
            else {
              $totals[$name]['N'] = $value;
            }
          }
          $row[] = array(
            'data' => $N_total,
            'title' => $N_total,
          );
          $rows[] = array('data' => $row);
          $row = array();
          $i = 2; // account for N
          foreach ($cross_category_label_by_name as $cross_name => $cross_label) {
            $class = ($i == $study_rowspan ? array('border-bottom') : array(''));
            $row[] = array(
              'data' => $cross_label . ' (' . $cross_name . ')',
              'class' => array_merge(array('border-right'), $class),
            );

            $total_per_line = 0;
            foreach ($category_label_by_name as $name => $label) {
              $value = isset($result[$name][$cross_name]) ? $result[$name][$cross_name] : 0;
              $total = isset($result[$name]['_all']) ? $result[$name]['_all'] : 0;
              $pct = _mica_query_crosstab_get_percentage($value, $total);
              $row[] = array(
                'data' => $value . ' (' . $pct . ')',
                'title' => $value,
                'class' => $class,
              );

              $total_per_line += $value;
              if (isset($totals[$name][$cross_name])) {
                $totals[$name][$cross_name] = $totals[$name][$cross_name] + $value;
              }
              else {
                $totals[$name][$cross_name] = $value;
              }
            }
            $row[] = array(
              'data' => $total_per_line,
              'title' => $total_per_line,
              'class' => $class,
            );

            $rows[] = array('data' => $row);
            $row = array();
            $i++;
          }
        }
        else {
          $row[] = array(
            'data' => t('Mean (std. deviation)'),
            'class' => array('border-right', 'border-bottom'),
          );
          foreach ($category_label_by_name as $name => $label) {
            $value = isset($result[$name]['mean']) ? $result[$name]['mean'] : 0;
            $std_dev = isset($result[$name]['std_deviation']) ? $result[$name]['std_deviation'] : 0;
            $row[] = array(
              'data' => round($value, 2) . ' (' . round($std_dev, 2) . ')',
              //_mica_datasets_query_count_str($value, $total),
              'title' => $value . ' (' . $std_dev . ')',
              'class' => array('border-right', 'border-bottom'),
            );
          }
          $rows[] = array('data' => $row);
        }
      }
    } catch (Exception $e) {
      $connector->displayError($e);
    }

  }

  // Add a summary row if there's more than one connector
  if (count($mica_dataset_connectors) > 1 && !$is_continuous) {
    $row[] = array(
      'data' => t('Study Totals'),
      'class' => array('border-right', 'border-bottom'),
      'rowspan' => $study_rowspan,
    );
    // Cross categories
    // N
    $row[] = array(
      'data' => t('N'),
      'class' => 'border-right',
    );

    $N_total = 0;
    foreach ($category_label_by_name as $name => $label) {
      $row[] = array(
        'data' => $totals[$name]['N'],
        'title' => $totals[$name]['N'],
      );
      $N_total += $totals[$name]['N'];
    }
    $row[] = array(
      'data' => $N_total,
      'title' => $N_total,
    );

    $rows[] = array('data' => $row);
    $row = array();
    $i = 2;
    foreach ($cross_category_label_by_name as $cross_name => $cross_label) {
      $class = ($i == $study_rowspan ? array('border-bottom') : array(''));
      $row[] = array(
        'data' => $cross_label . ' (' . $cross_name . ')',
        'class' => array_merge(array('border-right'), $class),
      );

      $total = 0;
      foreach ($category_label_by_name as $name => $label) {
        $row[] = array(
          'data' => $totals[$name][$cross_name],
          'class' => $class,
        );
        $total += $totals[$name][$cross_name];
      }
      // summary total
      $row[] = array(
        'data' => $total,
        'title' => $total,
        'class' => $class,
      );
      $rows[] = array('data' => $row);
      $row = array();
      $i++;
    }
  }

  $output .= theme(
    'table',
    array(
      'header' => $headers,
      'rows' => $rows,
      'attributes' => array('class' => array('query-table', "continuous_$is_continuous")),
      'empty' => t('No connectors available')
    )
  );

  $xls_url = url('variable-crosstab/' . $query->variable_id . '/' . $cross_variable->nid . '/xlsx');
  $xls_img_path = drupal_get_path('module', 'views_data_export') . '/images/xls.png';
  $xls_img_alt = t('Download as Excel');
  $xls_img = "<img typeof='foaf:Image' class='image-style-none' src='$xls_img_path' alt='$xls_img_alt' title='$xls_img_alt' />";
  $xls_link = "<div class='feed-icon'><a href='$xls_url'>$xls_img</a></div>";
  $output .= $xls_link;

  return $output;
}

function _mica_query_crosstab_process_header($category_label_by_name, $terms, $is_continuous) {
  $header_colspan = count($category_label_by_name);

  // There should always be only one term
  $term = $terms[0];
  // cannot use rowspan for cross queries because of use of <thead> and <tbody>
  $headers = array();
  $headers[] = array(
    'data' => t('Study'),
  );
  // Empty
  $headers[] = array(
    'data' => '', //$cross_variable_wrapper->title->value(),
    'class' => array('border-left', 'border-right')
  );
  // Variable name
  $headers[] = array(
    'data' => $term->termImpl()->getFieldName(),
    'colspan' => $header_colspan,
    'class' => array('border-left', 'border-right'),
  );
  // Add a total column if its not a categorical variable
  if (!$is_continuous){
    $headers[] = array(
      'data' => t('Total'),
      'colspan' => 2,
      'class' => array('border-left', 'border-right'),
    );
  }

  return $headers;
}

function _mica_query_crosstab_process_subheader($cross_variable_wrapper, $category_label_by_name, $is_continuous) {
  // empty sub-header
  $sub_header[] = array(
    'data' => ' ',
    'header' => TRUE,
    'class' => 'border-right',
  );
  // sub-header cross-variable name
  $sub_header[] = array(
    'header' => TRUE,
    'class' => array('border-left', 'border-right'),
    'data' => $cross_variable_wrapper->title->value(),
  );
  foreach ($category_label_by_name as $name => $label) {
    $sub_header[] = array(
      'data' => $name,
      'header' => TRUE,
      'title' => $label,
    );
  }
  // Add a total column if its not a categorical variable: empty
  if (!$is_continuous){
    $sub_header[] = array(
      'data' => '',
      'header' => TRUE,
      'class' => array('border-left', 'border-right'),
    );
  }
  return $sub_header;
}

function _mica_query_crosstab_get_percentage($value, $total) {
  if ($value > 0 && $total > 0) {
    return round(($value / $total) * 100, 2) . '%';
  }
  return "0%";
}

function mica_query_run_xlsx($var1, $var2) {

  $html = NULL;
//  $html = _mica_datasets_query_result_table($dataset_node, $query, $cross_variable, FALSE);

  $filename = $var1->title . ' - ' . $var2->title;
  drupal_add_http_header('Content-Type', 'application/vnd.ms-excel');
  drupal_add_http_header('Content-Disposition', "attachment; filename=$filename.xlsx");

  print $html;
  drupal_exit();
}