<?php
function mica_dimensions_coverage_tab_datasets($dce_id = NULL) {
  $data = & drupal_static(__FUNCTION__);
  if (!isset($data)) {
    //************************------------------
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
    ///*******************Taxonomy_term---------------

    $query_dce = new EntityFieldQuery();
    $query_dce->entityCondition('entity_type', 'node')
      ->entityCondition('bundle', 'data_collection_event');

    if (!empty($dce_id)) {
      $query_dce->propertyCondition('nid', $dce_id);
    }
    $entities_dce = $query_dce->execute();
    $keys_dce = array_keys($entities_dce['node']);

    foreach ($keys_dce as $keys_dce_id) {
      if (_mica_datasets_node_access($keys_dce_id, 'data_collection_event', 'view')) {
        $wrapper_dce = entity_metadata_wrapper('node', $keys_dce_id);
        $dce_title = $wrapper_dce->title->value();
        $has_var = FALSE;
        foreach ($wrapper_dce->field_dce_dataset->getIterator() as $wraper_dataset) {
          foreach ($wraper_dataset->field_dataset_variables->getIterator() as $warper_var) {
            if (!empty($warper_var)) {
              $has_var = TRUE;
              break;
            }
          }
          $dataset_nid = $wraper_dataset->getIdentifier();
          if (_mica_datasets_node_access($dataset_nid, 'dataset', 'view') && $has_var === TRUE) {
            if ((isset($_REQUEST['type']) && ($_REQUEST['type'] === 'harmonization' || $_REQUEST['type'] === 'study'))
              && $wraper_dataset->field_dataset_type->value() == $_REQUEST['type']
            ) {
              $study_nid = 0;
              $study_title = '';
              foreach ($wraper_dataset->field_dataset_studies->getIterator() as $wrapper_study) {
                foreach ($wrapper_study->field_study_populations->getIterator() as $wrapper_population) {
                  foreach ($wrapper_population->field_pop_dce->getIterator() as $wrapper_dce_population) {
                    if ($wrapper_dce_population->getIdentifier() == $keys_dce_id) {
                      $study_nid = $wrapper_study->getIdentifier();
                      $study_title = $wrapper_study->title->value();
                      break;
                    }
                  }
                }
              }

              $data['header'][$study_nid][$keys_dce_id][$study_title][$keys_dce_id] = $dce_title;
              ////////////////

              // Execute search query once and build the facet count map

              $conditions = $index->query();
              $conditions->condition('field_dataset:field_dataset_type', $_REQUEST['type']);
              $conditions->condition('field_dataset:field_dataset_dces', $keys_dce_id);
              $result = $conditions->execute();
              if (!empty($result['search_api_facets'])) {
                $term_id = 0;
                foreach ($result['search_api_facets'] as $facet => $facet_results) {
                  // Exclude dataset fields that are not taxonomy
                  if (in_array($facet, $taxonomy_fields)) {
                    foreach ($facet_results as $facet_result) {
                      $term_id = trim($facet_result['filter'], '\"');
                      $data[$study_nid][$keys_dce_id][$study_title][$keys_dce_id][$term_id]['facet'] = $facet;
                      $data[$study_nid][$keys_dce_id][$study_title][$keys_dce_id][$term_id]['count'] = $facet_result['count'];

                    }

                  }

                }

              }

            }

          }

        }

      }
    }

  }
  //rearrange $data array to mach header with rows and group datasets  by Studies->DCE-DATASETS
  if (!empty($data['header'])) {
    ksort($data['header']);
    ksort($data);
    $data_header = array();
    $data_data = array();
    $data_title = array();

    $index_dce = 0;
    foreach ($data as $key => $value) {
      if (isset($key) && $key == 'header') {
        foreach ($value as $value_study) {
          foreach ($value_study as $value_dce) {
            foreach ($value_dce as $title_dce) {
              $data_header['header'][][key($title_dce)][key($value_dce)] = $title_dce[key($title_dce)];
            }
          }
        }
      }
      elseif ($key != 'header') {
        if ($key != 'field_by_title') {
          foreach ($value as $value_study) {
            foreach ($value_study as $value_dce) {
              $data_data[$index_dce][key($value_dce)] = $value_dce[key($value_dce)];
              $index_dce++;
            }
          }
        }
      }
    }
    $data_title['field_by_title'] = $data['field_by_title'];
    unset($data);
    $data = $data_title + $data_header + $data_data;
  }
  return $data;

}

function mica_dimensions_coverage_tab_datasets_studies($id_studies = NULL) {
  $data = & drupal_static(__FUNCTION__);
  if (!isset($data)) {
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
    ///*******************Taxonomy_term---------------

    $query_study = new EntityFieldQuery();
    $query_study->entityCondition('entity_type', 'node')
      ->entityCondition('bundle', 'study');
    if (!empty($id_studies)) {
      $query_study->propertyCondition('nid', $id_studies);
    }
    $entities_dstudy = $query_study->execute();
    $keys_study = array_keys($entities_dstudy['node']);
    foreach ($keys_study as $keys_study_id) {

      //    if (_mica_datasets_node_access($keys_study, 'study', 'view')) {
      ///////////////////
      $wrapper_study = entity_metadata_wrapper('node', $keys_study_id);
      $study_title = $wrapper_study->title->value();

      // Execute search query once and build the facet count map

      $conditions = $index->query();
      $conditions->condition('field_dataset:field_dataset_type', 'study');
      $conditions->condition('search_api_combined_1', $keys_study_id);
      $result = $conditions->execute();
      if (!empty($result['results'])) {
        $data['header'][$keys_study_id][$study_title] = $study_title;
      }
      if (!empty($result['search_api_facets'])) {
        foreach ($result['search_api_facets'] as $facet => $facet_results) {
          // Exclude dataset fields that are not taxonomy
          if (in_array($facet, $taxonomy_fields)) {
            foreach ($facet_results as $facet_result) {
              $term_id = trim($facet_result['filter'], '\"');
              $data[$keys_study_id][$term_id]['have-var'] = $facet_result['count'];
              $data[$keys_study_id][$term_id]['facet'] = $facet;

            }

          }

        }

      }
//      }

    }

  }
  return $data;
}

/*
 * Construction Rows and of the table  the table with correct data
 * */
function _mica_dimensions_coverage_tab_dimension_table($data, $taxonomies) {
//  $rows = array();
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

          foreach ($data['header'] as $key_header => $title) {

            if ($key_header >= 0) {
              if (isset($data[$key_header][key($data[$key_header])][$term->tid]['count'])) {
                $url = l($data[$key_header][key($data[$key_header])][$term->tid]['count'], 'variable-search',
                  array(
                    'query' => array(

                      'f[0]' => $data[$key_header][key($data[$key_header])][$term->tid]['facet'] . ':' . $term->tid,
                      'f[1]' => 'field_dataset%3Afield_dataset_dces' . ':' . key($data[$key_header]),
                      'f[2]' => 'field_dataset%3Afield_dataset_type' . ':' . 'study'

                    ),
                  )
                );
                $row[$key_header + 2] = array(
                  'data' => array(
                    '#markup' => $url,
                  ),
                  'class' => array('center')
                );
              }
              else {
                $row[$key_header + 2] = array(
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

/*
 * Construction Rows and of the table  the table with correct data
 * */
function _mica_dimensions_coverage_tab_dimension_table_study($data, $taxonomies) {
//  $rows = array();
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

          foreach ($data['header'] as $key_header => $title) {

            if ($key_header >= 0) {
              if (isset($data[$key_header][$term->tid]['have-var'])) {
                //  $url = l($data[$key_header][$term->tid]['have-var'], 'variable-search',
                $url = l('<img src="/profiles/mica_distribution/modules/mica/extensions/mica_datasets/images/bullet_green.png" title="' . $data[$key_header][$term->tid]['have-var'] . '" style="vertical-align: middle">', 'variable-search',
                  array(
                    'query' => array(

                      'f[0]' => $data[$key_header][$term->tid]['facet'] . ':' . $term->tid,
                      'f[1]' => 'search_api_combined_1' . ':' . $key_header,
                      'f[2]' => 'field_dataset%3Afield_dataset_type' . ':' . 'study'

                    ),
                    'html' => TRUE
                  )
                );
                $row[$key_header + 2] = array(
                  'data' => array(
                    '#markup' => $url,
                  ),
                  'class' => array('center')
                );
              }
              else {
                $row[$key_header + 2] = array(
                  'data' => array(
                    '#markup' => '<img src="/profiles/mica_distribution/modules/mica/extensions/mica_datasets/images/bullet_red.png" title="' . t('No Variables') . '" style="vertical-align: middle">',
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
