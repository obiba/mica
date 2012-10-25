<?php

/**
 * @file
 * Mica Dataset Harmonization page
 */

/*
 * Menu for callback of refresh harmonization
 */

//include_once('mica_datasets.utils.inc');

/**
 * Display queries.
 */
/*
function mica_datasets_crosstab_page() {
  ctools_add_css('mica_datasets_crosstab', 'mica_datasets_crosstab');

//  drupal_set_title(t('Dimensions Comparison Table'));
//
  $output = drupal_render(drupal_get_form('mica_datasets_crosstab_legend_form'));

  // Study datasets with at least one variable
  $header = array();

  $query = new EntityFieldQuery();
  $entities = $query->entityCondition('entity_type', 'node')
    ->entityCondition('bundle', 'dataset')
    ->fieldCondition('field_dataset_type', 'value', 'study')
    ->execute();

  $header[] = '';
  if (!empty($entities['node'])){
    $index = search_api_index_load('variable_index');

    // Get a list of taxonomy_term that are indexed for this index
    $taxonomy_fields = $index->getFields();
    foreach($taxonomy_fields as $field => $config){
      if (!isset($config['entity_type']) || $config['entity_type'] !== 'taxonomy_term'){
        unset($taxonomy_fields[$field]);
      }
    }

    $map_field_by_title = array();
    foreach($taxonomy_fields as $taxonomy_field => $info){
      $map_field_by_title[strtolower($info['name'])] = $taxonomy_field;
    }
    $taxonomy_fields = array_keys($taxonomy_fields);

    $keys = array_keys($entities['node']);
    foreach ($keys as $dataset_id) {
      // Filter permissions
      if (_mica_datasets_node_access($dataset_id, 'dataset', 'view')){
        $node = node_load($dataset_id);
        $header[$dataset_id] = array(
          'data' => array(
            '#markup' => $node->title,
          ),
          'class' => array('dataset-title')
        );

        $datasets[$dataset_id]['title'] =$node->title;
        // Execute search query once and build the facet count map
        $result = $index->query()->condition('field_dataset', $dataset_id)->execute();
        if (!empty($result['search_api_facets'])){

          foreach($result['search_api_facets'] as $facet => $facet_results){

            // Exclude dataset fields that are not taxonomy
            if (in_array($facet, $taxonomy_fields)){
              foreach($facet_results as $facet_result){
                $term_id = trim($facet_result['filter'], '\"');
                $datasets[$dataset_id][$term_id]['count'] = $facet_result['count'];
                $datasets[$dataset_id][$term_id]['facet'] = $facet;
              }
            }
          }
        }
      }
    }
  }

  $taxonomies = _mica_datasets_taxonomies();
  foreach($taxonomies as $taxonomy){
    $output .= _mica_datasets_crosstab_dimension_table($header, $datasets, $taxonomy, $map_field_by_title);
  }

  return '<div id=\'harmonization_overview_wrapper\'>' . $output . '</div>';
}

function _mica_datasets_crosstab_dimension_table($header, $datasets, $taxonomy, $map_field_by_title){
  $rows = array();

  // Fetch all terms
  $machine_name = substr($taxonomy[0], 0, drupal_strlen($taxonomy[0]) - 4);
  $vocabulary = taxonomy_vocabulary_machine_name_load($machine_name);

  $tree = taxonomy_get_tree($vocabulary->vid);
  if (!empty($tree)) {
    $options = array();
    foreach ($tree as $term) {
      // Initializes variables passed to theme hook.
      $variables = array(
        'text' => $term->name,
        'path' => '',
        //'count' => 0,
        'options' => array(
          'attributes' => array('class' => 'facetapi-inactive'),
          'html' => FALSE,
          'query' => array(
            'f[0]' => $map_field_by_title[strtolower($taxonomy[1])] . ':' . $term->tid,
          ),
        ),
      );

      // Themes the link, adds row to facets.
      $row[0] = array(
        'class' => array('leaf'),
        'data' => (isset($term->depth) && $term->depth > 0 ? theme('indentation', array('size' => $term->depth)) : '') .
          theme('facetapi_link_inactive', $variables),
      );

      // Fill facet count in the same order as the header
      foreach($header as $dataset_id => $title){

        if ($dataset_id > 0){
          if (isset($datasets[$dataset_id]) && isset($datasets[$dataset_id][$term->tid])){
            $url = l($datasets[$dataset_id][$term->tid]['count'], 'variable-search',
              array(
                'query' => array(
                  'f[0]' => 'field_dataset:' . $dataset_id,
                  'f[1]' => $datasets[$dataset_id][$term->tid]['facet'] . ':' . $term->tid,
                ),
              )
            );
            $row[$dataset_id] = array(
              'data' => array(
                '#markup' => $url,
              ),
              'class' => array('center')
            );
          }
          else{
            $row[$dataset_id] = array(
              'data' => array(
                '#markup' => '-',
              ),
              'class' => array('center')
            );
          }
        }
      }
      $rows[] = $row;
    }
  }

  $header[0] = t("@title", array('@title' => $taxonomy[1]));
  $output = theme(
    'table',
    array(
      'header' => $header,
      'rows' => $rows,
      'empty' => t('No information found'),
      'sticky' => FALSE,
      'attributes' => array('class' => 'dataset_crosstab'),
    )
  );

  //$output .= '<br />';

  return $output;
}

function mica_datasets_crosstab_legend_form($form, $form_state) {
  $form['legend'] = array(
    '#type' => 'container',
  );
  $form['legend']['intro'] = array(
    '#type' => 'markup',
    '#markup' => "View dimensions comparison table by dataset",
  );

  return $form;
}
*/
function _mica_datasets_harmonization_variable_tooltip($variable) {
  $wrapper = entity_metadata_wrapper('node', $variable);
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