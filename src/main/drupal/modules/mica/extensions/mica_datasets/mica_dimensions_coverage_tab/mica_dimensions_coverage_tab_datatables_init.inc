<?php

function mica_dimensions_coverage_tab_datasets2() {
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
              $study_title = truncate_utf8($study->title, 45, TRUE, TRUE);
            }
            else {
              $study_title = '';
            }
            $title_dataset = $node->title . '-' . $study_title;
            $data['header'][$dataset_id] = $title_dataset;

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

function _mica_dimensions_coverage_dimension_get_test_array() {

  $test_data['header'] = '[
            { "sTitle": "Engine" },
            { "sTitle": "Browser" },
            { "sTitle": "Platform" },
            { "sTitle": "Version", "sClass": "center" },
            { "sTitle": "Grade", "sClass": "center" }
        ]';
  $test_data['data'] = '[
    [
      "Trident",
      "Internet Explorer 4.0",
      "Win 95+",
      "4",
      "X"
    ],
    [
      "Trident",
      "Internet Explorer 5.0",
      "Win 95+",
      "5",
      "C"
    ],
    [
      "Trident",
      "Internet Explorer 5.5",
      "Win 95+",
      "5.5",
      "A"
    ],
    [
      "Trident",
      "Internet Explorer 6",
      "Win 98+",
      "6",
      "A"
    ],
    [
      "Trident",
      "Internet Explorer 7",
      "Win XP SP2+",
      "7",
      "A"
    ],
    [
      "Trident",
      "AOL browser (AOL desktop)",
      "Win XP",
      "6",
      "A"
    ],
    [
      "Gecko",
      "Firefox 1.0",
      "Win 98+ / OSX.2+",
      "1.7",
      "A"
    ],
    [
      "Gecko",
      "Firefox 1.5",
      "Win 98+ / OSX.2+",
      "1.8",
      "A"
    ],
    [
      "Gecko",
      "Firefox 2.0",
      "Win 98+ / OSX.2+",
      "1.8",
      "A"
    ],
    [
      "Gecko",
      "Firefox 3.0",
      "Win 2k+ / OSX.3+",
      "1.9",
      "A"
    ],
    [
      "Gecko",
      "Camino 1.0",
      "OSX.2+",
      "1.8",
      "A"
    ],
    [
      "Gecko",
      "Camino 1.5",
      "OSX.3+",
      "1.8",
      "A"
    ],
    [
      "Gecko",
      "Netscape 7.2",
      "Win 95+ / Mac OS 8.6-9.2",
      "1.7",
      "A"
    ],
    [
      "Gecko",
      "Netscape Browser 8",
      "Win 98SE+",
      "1.7",
      "A"
    ],
    [
      "Gecko",
      "Netscape Navigator 9",
      "Win 98+ / OSX.2+",
      "1.8",
      "A"
    ],
    [
      "Gecko",
      "Mozilla 1.0",
      "Win 95+ / OSX.1+",
      1,
      "A"
    ],
    [
      "Gecko",
      "Mozilla 1.1",
      "Win 95+ / OSX.1+",
      1.1,
      "A"
    ],
    [
      "Gecko",
      "Mozilla 1.2",
      "Win 95+ / OSX.1+",
      1.2,
      "A"
    ],
    [
      "Gecko",
      "Mozilla 1.3",
      "Win 95+ / OSX.1+",
      1.3,
      "A"
    ],
    [
      "Gecko",
      "Mozilla 1.4",
      "Win 95+ / OSX.1+",
      1.4,
      "A"
    ],
    [
      "Gecko",
      "Mozilla 1.5",
      "Win 95+ / OSX.1+",
      1.5,
      "A"
    ],
    [
      "Gecko",
      "Mozilla 1.6",
      "Win 95+ / OSX.1+",
      1.6,
      "A"
    ],
    [
      "Gecko",
      "Mozilla 1.7",
      "Win 98+ / OSX.1+",
      1.7,
      "A"
    ],
    [
      "Gecko",
      "Mozilla 1.8",
      "Win 98+ / OSX.1+",
      1.8,
      "A"
    ],
    [
      "Gecko",
      "Seamonkey 1.1",
      "Win 98+ / OSX.2+",
      "1.8",
      "A"
    ],
    [
      "Gecko",
      "Epiphany 2.20",
      "Gnome",
      "1.8",
      "A"
    ],
    [
      "Webkit",
      "Safari 1.2",
      "OSX.3",
      "125.5",
      "A"
    ],
    [
      "Webkit",
      "Safari 1.3",
      "OSX.3",
      "312.8",
      "A"
    ],
    [
      "Webkit",
      "Safari 2.0",
      "OSX.4+",
      "419.3",
      "A"
    ],
    [
      "Webkit",
      "Safari 3.0",
      "OSX.4+",
      "522.1",
      "A"
    ],
    [
      "Webkit",
      "OmniWeb 5.5",
      "OSX.4+",
      "420",
      "A"
    ],
    [
      "Webkit",
      "iPod Touch / iPhone",
      "iPod",
      "420.1",
      "A"
    ],
    [
      "Webkit",
      "S60",
      "S60",
      "413",
      "A"
    ],
    [
      "Presto",
      "Opera 7.0",
      "Win 95+ / OSX.1+",
      "-",
      "A"
    ],
    [
      "Presto",
      "Opera 7.5",
      "Win 95+ / OSX.2+",
      "-",
      "A"
    ],
    [
      "Presto",
      "Opera 8.0",
      "Win 95+ / OSX.2+",
      "-",
      "A"
    ],
    [
      "Presto",
      "Opera 8.5",
      "Win 95+ / OSX.2+",
      "-",
      "A"
    ],
    [
      "Presto",
      "Opera 9.0",
      "Win 95+ / OSX.3+",
      "-",
      "A"
    ],
    [
      "Presto",
      "Opera 9.2",
      "Win 88+ / OSX.3+",
      "-",
      "A"
    ],
    [
      "Presto",
      "Opera 9.5",
      "Win 88+ / OSX.3+",
      "-",
      "A"
    ],
    [
      "Presto",
      "Opera for Wii",
      "Wii",
      "-",
      "A"
    ],
    [
      "Presto",
      "Nokia N800",
      "N800",
      "-",
      "A"
    ],
    [
      "Presto",
      "Nintendo DS browser",
      "Nintendo DS",
      "8.5",
      "C/A<sup>1</sup>"
    ],
    [
      "KHTML",
      "Konqureror 3.1",
      "KDE 3.1",
      "3.1",
      "C"
    ],
    [
      "KHTML",
      "Konqureror 3.3",
      "KDE 3.3",
      "3.3",
      "A"
    ],
    [
      "KHTML",
      "Konqureror 3.5",
      "KDE 3.5",
      "3.5",
      "A"
    ],
    [
      "Tasman",
      "Internet Explorer 4.5",
      "Mac OS 8-9",
      "-",
      "X"
    ],
    [
      "Tasman",
      "Internet Explorer 5.1",
      "Mac OS 7.6-9",
      "1",
      "C"
    ],
    [
      "Tasman",
      "Internet Explorer 5.2",
      "Mac OS 8-X",
      "1",
      "C"
    ],
    [
      "Misc",
      "NetFront 3.1",
      "Embedded devices",
      "-",
      "C"
    ],
    [
      "Misc",
      "NetFront 3.4",
      "Embedded devices",
      "-",
      "A"
    ],
    [
      "Misc",
      "Dillo 0.8",
      "Embedded devices",
      "-",
      "X"
    ],
    [
      "Misc",
      "Links",
      "Text only",
      "-",
      "X"
    ],
    [
      "Misc",
      "Lynx",
      "Text only",
      "-",
      "X"
    ],
    [
      "Misc",
      "IE Mobile",
      "Windows Mobile 6",
      "-",
      "C"
    ],
    [
      "Misc",
      "PSP browser",
      "PSP",
      "-",
      "C"
    ],
    [
      "Other browsers",
      "All others",
      "-",
      "-",
      "U"
    ]
  ]';
  return $test_data;
}