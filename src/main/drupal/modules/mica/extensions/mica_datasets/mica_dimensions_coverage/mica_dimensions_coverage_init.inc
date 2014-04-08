<?php

function mica_dimensions_coverage_datasets_harmonization($dataset_id = NULL) {
  $data = & drupal_static(__FUNCTION__);
  if (!isset($data)) {
    $index = search_api_index_load('variable_index');

    $taxonomy_fields = mica_dimensions_coverage_get_list_taxonomy_term($data, $index);

    $query_dataset = new SearchApiQuery($index);
    $query_dataset->condition('field_dataset:field_dataset_type', 'harmonization', '=');
    $result_dataset = $query_dataset->execute();

    foreach ($result_dataset['search_api_facets']['field_dataset'] as $dataset_facet) {
      $key_dataset_id = trim($dataset_facet['filter'], '\"');
      if (in_array($key_dataset_id, $dataset_id)) {
        // get header
        _mica_dimensions_coverage_get_header($data, 'dataset', $key_dataset_id);
        //get data
        _mica_dimensions_coverage_get_data($data, $index, 'field_dataset', $taxonomy_fields, $key_dataset_id);
      }
    }
  }

  return $data;
}

function mica_dimensions_coverage_dce($studies_id = NULL) {
  $data = & drupal_static(__FUNCTION__);
  $dce_id =array();
  if (!isset($data)) {
    $index = search_api_index_load('variable_index');
    $taxonomy_fields = mica_dimensions_coverage_get_list_taxonomy_term($data, $index);
    $query_dce = new SearchApiQuery($index);
    $query_dce->condition('field_dataset:field_dataset_type', 'study', '=');
    $result_dce = $query_dce->execute();
    foreach($studies_id as $study_id){
      $study_wrapper = entity_metadata_wrapper('node',$study_id);
      foreach($study_wrapper ->field_study_populations->getIterator() as $population_wrapper){
        foreach($population_wrapper->field_pop_dce->getIterator() as $dce_wrapper){
          $dce_id [] = $dce_wrapper->getIdentifier();
        }
      }
    }
    foreach ($result_dce['search_api_facets']['field_dataset:field_dataset_dces'] as $dce_facet) {
      $key_dce_id = trim($dce_facet['filter'], '\"');
      if (in_array($key_dce_id, $dce_id)) {
        // get header
        _mica_dimensions_coverage_get_header($data, 'dce', $key_dce_id);
        //get data
        _mica_dimensions_coverage_get_data($data, $index, 'field_dataset:field_dataset_dces', $taxonomy_fields, $key_dce_id);
      }
    }
  }
  return $data;
}

function mica_dimensions_coverage_studies($id_studies = NULL) {
  $data = & drupal_static(__FUNCTION__);
  if (!isset($data)) {
    $index = search_api_index_load('variable_index');

    $taxonomy_fields = mica_dimensions_coverage_get_list_taxonomy_term($data, $index);

    $query_study = new SearchApiQuery($index);
    $query_study->condition('field_dataset:field_dataset_type', 'study', '=');
    $query_study = $query_study->execute();
    foreach ($query_study['search_api_facets']['search_api_combined_1'] as $study_facet) {
      $key_study_id = trim($study_facet['filter'], '\"');
      if (in_array($key_study_id, $id_studies)) {
        // get header
        _mica_dimensions_coverage_get_header($data, 'study', $key_study_id);
        //get data
        _mica_dimensions_coverage_get_data($data, $index, 'search_api_combined_1', $taxonomy_fields, $key_study_id);
      }
    }
  }
  return $data;
}

function _mica_dimensions_coverage_get_header(&$data, $type, $nid) {
  switch ($type) {
    case 'dataset':
      $wrapper_dataset = entity_metadata_wrapper('node', $nid);
      $dataset_title = $wrapper_dataset->title->value();
      $data['header'][$nid][$dataset_title] = $dataset_title;
      break;

    case 'study':
      $wrapper_study = entity_metadata_wrapper('node', $nid);
      $study_title = $wrapper_study->title->value();
      $data['header'][$nid][$study_title] = $study_title;
      break;

    case 'dce';
      $wrapper_dce = entity_metadata_wrapper('node', $nid);
      $dce_title = $wrapper_dce->title_field->value();
      $study_nid = _mica_studies_get_dce_study_nid($nid);
      $study_wrapper = entity_metadata_wrapper('node', $study_nid);
      $study_title = $study_wrapper->title->value();
      $data['header'][$study_nid][$study_title][$nid] = $dce_title;
      break;

  }
}

function _mica_dimensions_coverage_get_data(&$data, $index, $condition, $taxonomy_fields, $nid) {
  //    Execute search query once and build the facet count map
  $query_data = new SearchApiQuery($index);
  $query_data->condition($condition, $nid);
  $result_data = $query_data->execute();
  if (!empty($result_data['search_api_facets'])) {
    foreach ($result_data['search_api_facets'] as $facet => $facet_results) {
      // Exclude dataset fields that are not taxonomy
      if (in_array($facet, $taxonomy_fields)) {
        foreach ($facet_results as $facet_result) {
          $term_id = trim($facet_result['filter'], '\"');
          $data[$nid][$term_id]['facet'] = $facet;
          $data[$nid][$term_id]['count'] = $facet_result['count'];
        }
      }
    }
  }
}

/*
 * Construction Rows and of the table  the table with correct data
 * */
function _mica_dimensions_coverage_dimension_table($data, $taxonomies, $type) {
  $rows = array();
  foreach ($taxonomies as $taxonomy) {
    $machine_name = substr($taxonomy[0], 0, drupal_strlen($taxonomy[0]) - 4);
    $vocabularies = taxonomy_vocabulary_machine_name_load($machine_name);
    if (!empty($vocabularies->vid)) {
      // Fetch all terms
      $vocabulary = taxonomy_vocabulary_load($vocabularies->vid);
      $tree = taxonomy_get_tree($vocabulary->vid);
      if (!empty($tree)) {
        foreach ($tree as $term) {
          $row = _mica_dimensions_coverage_construct_domains_column($term, $vocabulary, $taxonomy, $data['field_by_title']);

          // Fill facet count in the same order as the header
          if (isset($data['header'])) {
            $i = 0;
            foreach ($data['header'] as $key_header => $title) {
              if ($key_header >= 0) {
                if (isset($data[$key_header][$term->tid]['count'])) {
                  //  $url = l($data[$key_header][$term->tid]['have-var'], 'variable-search',
                  switch ($type) {
                    case 'study':
                      $url = l('<img src="' . $GLOBALS['base_url'] . '/profiles/mica_distribution/modules/mica/extensions/mica_datasets/images/bullet_green.png" title="' . $data[$key_header][$term->tid]['count'] . '" style="vertical-align: middle">', 'variable-search',
                        array(
                          'query' => array(
                            'f[0]' => $data[$key_header][$term->tid]['facet'] . ':' . $term->tid,
                            'f[1]' => 'search_api_combined_1' . ':' . $key_header,
                            'f[2]' => 'field_dataset%3Afield_dataset_type' . ':' . 'study'

                          ),
                          'html' => TRUE
                        )
                      );
                      break;
                    case 'dce':
                      $url = l($data[$key_header][$term->tid]['count'], 'variable-search',
                        array(
                          'query' => array(
                            'f[0]' => $data[$key_header][$term->tid]['facet'] . ':' . $term->tid,
                            'f[1]' => 'field_dataset%3Afield_dataset_dces' . ':' . $key_header,
                            'f[2]' => 'field_dataset%3Afield_dataset_type' . ':' . 'study'
                          ),
                        )
                      );
                      break;

                    case 'dataset':
                      $url = l($data[$key_header][$term->tid]['count'], 'variable-search',
                        array(
                          'query' => array(
                            'f[0]' => 'field_dataset:' . $key_header,
                            'f[1]' => $data[$key_header][$term->tid]['facet'] . ':' . $term->tid,

                          ),
                        )
                      );
                      break;
                  }

                  $row[$key_header + 2] = array(
                    'data' => array(
                      '#markup' => $url,
                    ),
                    'class' => array('center')
                  );
                }
                else {
                  switch ($type) {
                    case 'study':
                      $no_data = '<img src="' . $GLOBALS['base_url'] . '/profiles/mica_distribution/modules/mica/extensions/mica_datasets/images/bullet_red.png" title="' . t('No Variables') . '" style="vertical-align: middle">';
                      break;
                    default :
                      $no_data = '-';
                  }

                  $row[$key_header + 2] = array(
                    'data' => array(
                      '#markup' => $no_data,
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
  }
  return $rows;
}

function _mica_dimensions_coverage_construct_domains_column($term, $vocabulary, $taxonomy, $field_by_title) {
// Initializes variables passed to theme hook.
  $variables = array(
    'text' => $term->name,
    'path' => 'variable-search',
    //'count' => 0,
    'options' => array(
      'attributes' => array('class' => 'facetapi-inactive'),
      'html' => FALSE,
      'query' => array(
        'f[0]' => !empty($field_by_title[strtolower($vocabulary->name)]) ? $field_by_title[strtolower($vocabulary->name)] : NULL . ':' . $term->tid,

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
  return $row;
}

function mica_dimensions_coverage_get_list_taxonomy_term(&$data, $index) {
  // Get a list of taxonomy_term that are indexed for this index
  $taxonomy_fields = $index->getFields();
  foreach ($taxonomy_fields as $field => $config) {
    if (!isset($config['entity_type']) || $config['entity_type'] !== 'taxonomy_term') {
      unset($taxonomy_fields[$field]);
    }
    $data['field_by_title'][strtolower($config['name'])] = $field;
  }

  $taxonomy_fields = array_keys($taxonomy_fields);
  return $taxonomy_fields;
}