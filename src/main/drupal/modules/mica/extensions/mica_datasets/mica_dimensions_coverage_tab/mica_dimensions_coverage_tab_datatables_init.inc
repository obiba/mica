<?php

function mica_dimensions_coverage_tab_datasets() {
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

      foreach ($keys as $dataset_id) {
        // Check if the dataset has variable with dimensions
        // Filter permissions
        if (_mica_datasets_node_access($dataset_id, 'dataset', 'view')) {
          $node = node_load($dataset_id);
          // Add only if the datasets has variables
          if (!empty($node->field_dataset_variables)) {

            if (isset($node->field_dataset_studies['und'])) {
              $study = node_load($node->field_dataset_studies['und'][0]['nid']);
              $study_title = truncate_utf8($study->title, 35, TRUE, TRUE);
            }
            else {
              $study_title = '';
            }
            $title_dataset = $node->title . '-' . $study_title;
            $data['header'][$dataset_id][$study_title] = $node->title;
            // Execute search query once and build the facet count map
            $result = $index->query()->condition('field_dataset', $dataset_id)->execute();
            if (!empty($result['search_api_facets'])) {

              foreach ($result['search_api_facets'] as $facet => $facet_results) {

                // Exclude dataset fields that are not taxonomy
                if (in_array($facet, $taxonomy_fields)) {
                  foreach ($facet_results as $facet_result) {
                    $term_id = trim($facet_result['filter'], '\"');
                    $data[$dataset_id][$term_id]['count'] = $facet_result['count'];
                    $data[$dataset_id][$term_id]['facet'] = $facet;
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  return $data;
}