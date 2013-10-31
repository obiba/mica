<?php

function mica_opal_fetch_harmonization_view($dataset_nid, $study_nid) {

  $connector = mica_connector_query($dataset_nid, $study_nid, TRUE);

  if ($connector) {
    $opal = new MicaDatasetOpalConnectionClass($connector);
    $post = new HttpClientRequest($connector->__call("getTableResourceURI", array("variables")), array(
      'method' => 'GET',
      'headers' => array('Accept' => array('application/json')),
      'data' => array(),
      'parameters' => array(),
    ));
    $raw = $opal->client()->execute($post);

    $array = json_decode($raw, TRUE);
    // Support JSON lines format.r
    if (!is_array($array)) {
      $raw = preg_replace('/}\s*{/', '},{', $raw);
      $raw = '[' . $raw . ']';
      $array = json_decode($raw, TRUE);
    }

    if (is_array($array)) {
      $harmonization = array();
      $harmonization['dataset_nid'] = $dataset_nid;
      $harmonization['study_nid'] = $study_nid;

      $all_items = mica_opal_jsonPath($array, '$.*');
      unset($array);

      foreach ($all_items as $item) {

        $variable_info = array();

        // Check if uuid is present
        $variable_info['uuid'] = _mica_opal_json_get_string($item, 'attributes[?(@[\'name\']==\'uuid\'), ?(@[\'namespace\']==\'maelstrom\')].value');
        $variable_info['title'] = _mica_opal_json_get_string($item, 'name');
        $variable_info['label'] = _mica_opal_parse_localized($item, 'attributes[?(@[\'name\']==\'label\')]');
        $variable_info['value_type'] = _mica_opal_json_get_string($item, 'valueType');
        $variable_info['unit'] = _mica_opal_json_get_string($item, 'unit');

        $repeatable = _mica_opal_json_get_string($item, 'isRepeatable');
        // Explicitly set to 0 to avoid the error when saving an empty field into the database
        $variable_info['repeatable'] = empty($repeatable) ? '0' : $repeatable;

        $script = _mica_opal_json_get_string($item, 'attributes[?(@[\'name\'==\'script\' and @namespace == \'opal\'].value');
        $variable_info['script'] = strlen($script) === 0
          ? _mica_opal_json_get_string($item, 'attributes[?(@[\'name\']==\'script\')].value')
          : $script;

        $status = _mica_opal_json_get_string($item, 'attributes[?(@[\'name\']==\'status\'), ?(@[\'namespace\']==\'maelstrom\')].value');
        $variable_info['status'] = empty($status) || !strpos(",complete,impossible", $status) ? 'undetermined' : strtolower($status);

        $variable_info['description'] = _mica_opal_parse_localized($item, 'attributes[?(@[\'name\']==\'description\'), ?(@[\'namespace\']==\'maelstrom\')]');
        $variable_info['comment'] = _mica_opal_parse_localized($item, 'attributes[?(@[\'name\']==\'comment\'), ?(@[\'namespace\']==\'maelstrom\')]');

        $variable_info['categories'] = _mica_opal_parse_categories($item);

        $harmonization['variables'][$variable_info['title']] = $variable_info;

      }
      return $harmonization;
    }
    throw new Exception(t('There was an error decoding the JSON document.'));
  }

  return FALSE;
}

function _mica_opal_parse_categories($item) {
  $categories = array();
  $json_categories = array_shift(mica_opal_jsonPath($item, 'categories'));
  if (is_array($json_categories)) {
    foreach ($json_categories as $json_cat) {
      $category = array(
        'name' => $json_cat['name'],
        'missing' => $json_cat['isMissing'] ? '1' : '0',
      );
      if (isset($json_cat['attributes'])) {
        foreach ($json_cat['attributes'] as $json_cat_att) {
          if (isset($json_cat_att['name']) && $json_cat_att['name'] === 'label') {
            $locale = isset($json_cat_att['locale']) ? $json_cat_att['locale'] : LANGUAGE_NONE;
            $category['label'][$locale] = $json_cat_att['value'];
          }
        }

        // Set default language to 'en'
        if (isset($category['label']['en']) && !isset($category['label'][LANGUAGE_NONE])) {
          $category['label'][LANGUAGE_NONE] = $category['label']['en'];
        }
      }
      $categories[] = $category;
    }
  }
  return $categories;
}

function _mica_opal_parse_localized($item, $expression) {
  $result = array();
  $localized_items = mica_opal_jsonPath($item, $expression);
  if (!empty($localized_items)) {
    foreach ($localized_items as $localized_item) {
      $locale = isset($localized_item['locale']) ? $localized_item['locale'] : LANGUAGE_NONE;
      $result[empty($locale) ? LANGUAGE_NONE : $locale] = $localized_item['value'];
    }
  }

  // Set default language to english if it exists
  if (isset($result['en']) && !isset($result[LANGUAGE_NONE])) {
    $result[LANGUAGE_NONE] = $result['en'];
  }
  return $result;
}

/**
 * Utilizes the jsonPath function from jsonpath-0.8.1.php
 *
 * jsonPath returns false if the expression returns zero results and that will
 * mess up our for loops, so return an empty array instead.
 *
 * TODO Figure out error handling.
 *
 * @param $array
 *   The input array to parse
 * @$expression
 *   The JSONPath expression.
 * @param $expression
 * @throws Exception
 * @return array
 *   Returns an array that is the output of jsonPath
 */
function mica_opal_jsonPath($array, $expression) {

  static $path = NULL;

  if (!isset($path)) {
    $path = FALSE;

    // If Libraries API is installed, we first use that to try and find the library.
    // Otherwise we manually check a few locations.
    $search_dirs = array();
    if (function_exists('libraries_get_path')) {
      $dir = libraries_get_path('jsonpath');
      // Confusingly, Libraries API 1.x will return sites/all/libraries/NAME on failure,
      // while Libraries API 2.x returns FALSE in that case.
      if ($dir) {
        $search_dirs[] = $dir;
      }
    }
    else {
      // Include libraries + current profile folders in searched directories.
      $search_dirs[] = 'sites/all/libraries/jsonpath';
      $search_dirs[] = 'profiles/' . drupal_get_profile() . '/libraries/jsonpath';
    }
    $search_dirs[] = drupal_get_path('module', 'mica_opal') . '/includes';
    foreach ($search_dirs as $dir) {
      $path = DRUPAL_ROOT . '/' . $dir . '/jsonpath-0.8.1.php';
      if (file_exists($path)) {
        include_once $path;
        break;
      }
    }
  }

  if ($path == FALSE) {
    throw new Exception('jsonpath-0.8.1.php library not found! Please follow the instructions in mica_opal/README.txt');
  }

  $result = jsonPath($array, $expression);
  return ($result === FALSE) ? array() : $result;
}

function _mica_opal_json_get_string($array, $expression) {
  return array_shift(mica_opal_jsonPath($array, $expression));
}