<?php
function mica_dimensions_coverage_tab_datasets_harmonization($datasets = NULL) {
  $data = & drupal_static(__FUNCTION__);
  if (!isset($data)) {
    $query = new EntityFieldQuery();
    $query->entityCondition('entity_type', 'node')
      ->entityCondition('bundle', 'dataset');

    // Filter by dataset type
    if (isset($_REQUEST['type']) && ($_REQUEST['type'] === 'harmonization' || $_REQUEST['type'] === 'study')) {
      $query->fieldCondition('field_dataset_type', 'value', $_REQUEST['type']);

    }
    $entities = $query->execute();
    if (!empty($entities['node'])) {
      $index = search_api_index_load('variable_index');

      // Get a list of taxonomy_term that are indexed for this index
      $taxonomy_fields = $index->getFields();
      foreach ($taxonomy_fields as $field => $config) {
        if (!isset($config['entity_type']) || $config['entity_type'] !== 'taxonomy_term') {
          unset($taxonomy_fields[$field]);
        }
      }

      foreach ($taxonomy_fields as $taxonomy_field => $info) {
        $data['field_by_title'][strtolower($info['name'])] = $taxonomy_field;
      }
      $taxonomy_fields = array_keys($taxonomy_fields);
      $keys = array_keys($entities['node']);
      if (!empty($datasets)) {
        $keys = $datasets;
      }

      $idenx_dataset = 0;
      $study_nid_ignore = array();
      foreach ($keys as $dataset_id) {
        // Check if the dataset has variable with dimensions
        // Filter permissions
        if (_mica_datasets_node_access($dataset_id, 'dataset', 'view')) {
          $node = node_load($dataset_id);
          // Add only if the datasets has variables
          if (!empty($node->field_dataset_variables)) {
            if (isset($node->field_dataset_studies['und'])) {
              $wrapper_study = entity_metadata_wrapper('node', $node->field_dataset_studies['und'][0]['nid']);
              $study_title = $wrapper_study->title->value();
              $study_nid_ignore[] = $wrapper_study->nid->value();
              foreach ($wrapper_study->field_study_populations->getIterator() as $population) {
                foreach ($population->field_pop_dce->getIterator() as $dce) {
                  foreach ($dce->field_dce_dataset->getIterator() as $dce_dataset_filed) {
                    $dce_title = $dce->title->value();
                    if ($dce_dataset_filed->nid->value() == $dataset_id) {

                      $data['header'][$study_title][$dce_title][$idenx_dataset][$dce_dataset_filed->nid->value()][$study_title][$dce_title] = $node->title;
                    }

                  }
                }
              }
            }
            else {
              $study_title = '';
              $dce_title = '';
              $data['header'][$study_title][$dce_title][$idenx_dataset][$dataset_id][$study_title][$dce_title] = $node->title;
            }

            // Execute search query once and build the facet count map
            $result = $index->query()->condition('field_dataset', $dataset_id)->execute();
            if (!empty($result['search_api_facets'])) {
              foreach ($result['search_api_facets'] as $facet => $facet_results) {
                // Exclude dataset fields that are not taxonomy
                if (in_array($facet, $taxonomy_fields)) {
                  foreach ($facet_results as $facet_result) {
                    $term_id = trim($facet_result['filter'], '\"');
                    $data[$study_title][$dce_title][$idenx_dataset][$dataset_id][$term_id]['count'] = $facet_result['count'];
                    $data[$study_title][$dce_title][$idenx_dataset][$dataset_id][$term_id]['facet'] = $facet;
                  }
                }
              }
            }
            $idenx_dataset++;
          }
        }
      }
    }
  }
  //rearrange $data array to mach header with rows and group datasets  by Studies->DCE-DATASETS
  ksort($data['header']);
  ksort($data);
  $data_header = array();
  $data_data = array();
  $data_title = array();
  $index_dataset = 0;
  $index_dce = 0;
  foreach ($data as $key => $value) {
    if (isset($key) && $key == 'header') {
      foreach ($value as $value_study) {
        foreach ($value_study as $value_dce) {
          foreach ($value_dce as $value_datest) {
            $data_header['header'][][] = $value_datest;
          }
        }
      }
    }
    elseif ($key != 'header') {
      if ($key != 'field_by_title') {
        foreach ($value as $value_study) {
          foreach ($value_study as $value_dce) {
            foreach ($value_dce as $value_dataset) {
              $data_data[$index_dce][$index_dataset] = $value_dataset;
              $index_dataset++;
            }
            $index_dce++;
          }
        }
      }
    }
  }
  $data_title['field_by_title'] = $data['field_by_title'];
  unset($data);
  $data = $data_title + $data_header + $data_data;
  return $data;
}

/*
 * Construction Rows and of the table  the table with correct data
 * */
function _mica_dimensions_coverage_tab_dimension_table_harmonization($data, $taxonomies) {
  $rows = array();

  foreach ($taxonomies as $taxonomy) {
    $machine_name = substr($taxonomy[0], 0, drupal_strlen($taxonomy[0]) - 4);
    $vocabularies = taxonomy_vocabulary_machine_name_load($machine_name);
    // Fetch all terms
    $vocabulary = taxonomy_vocabulary_load($vocabularies->vid);
    $tree = taxonomy_get_tree($vocabulary->vid);
    if (!empty($tree)) {
      foreach ($tree as $term) {
        // Initializes variables passed to theme hook.

        $variables = array(
          'text' => $term->name,
          'path' => 'variable-search',
          //'count' => 0,
          'options' => array(
            'attributes' => array('class' => 'facetapi-inactive'),
            'html' => FALSE,
            'query' => array(
              'f[0]' => $data['field_by_title'][strtolower($vocabulary->name)] . ':' . $term->tid,
            ),
          ),
        );

        // Themes the link, adds row to facets.
        $row[0] = array(
          'class' => array('leaf'),
          'data' => (isset($term->depth) && $term->depth > 0 ? theme('indentation', array('size' => $term->depth)) : '') .
            theme('facetapi_link_inactive', $variables),
        );

        // Themes the link, adds row to facets.
        $row[1] = array(
          'width' => '10',
          'class' => array('taxo'),
          'data' => array(
            '#markup' => $taxonomy[1]
          ),
        );
        // Fill facet count in the same order as the header
        if (isset($data['header'])) {
          $i = 0;

          foreach ($data['header'] as $dataset_id => $title) {

            if ($dataset_id > 0) {
              if (isset($dataset_id) && isset($data[$i][$i][$term->tid]['count'])) {
                $url = l($data[$i][$i][$term->tid]['count'], 'variable-search',
                  array(
                    'query' => array(
                      'f[0]' => 'field_dataset:' . $dataset_id,
                      'f[1]' => $data[$i][$i][$term->tid]['facet'] . ':' . $term->tid,

                    ),
                  )
                );
                $row[$i + 2] = array(
                  'data' => array(
                    '#markup' => $url,
                  ),
                  'class' => array('center')
                );
              }
              else {
                $row[$i + 2] = array(
                  'data' => array(
                    '#markup' => '-',
                  ),
                  'class' => array('center')
                );
              }
            }
            $i++;

          }
          $rows [] = $row;
        }
      }
    }
  }
  return $rows;
}