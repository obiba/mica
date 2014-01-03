<?php
function mica_dimensions_coverage_tab_datasets($datasets = NULL) {
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
              $study_title = truncate_utf8($wrapper_study->title->value(), 35, TRUE, TRUE);
              $study_nid_ignore[] = $wrapper_study->nid->value();
              foreach ($wrapper_study->field_study_populations->getIterator() as $population) {
                foreach ($population->field_pop_dce->getIterator() as $dce) {
                  foreach ($dce->field_dce_dataset->getIterator() as $dce_dataset_filed) {
                    if ($dce_dataset_filed->nid->value() == $dataset_id && in_array($dce_dataset_filed->nid->value(), $keys)) {
                      $dce_title = truncate_utf8($dce->title->value(), 35, TRUE, TRUE);
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