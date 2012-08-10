<?php
/**
 * @file
 * mica_datasets.current_search.inc
 */

/**
 * Implements hook_current_search_default_items().
 */
function mica_datasets_current_search_default_items() {
  $export = array();

  $item = new stdClass();
  $item->disabled = FALSE; /* Edit this to true to make a default item disabled initially */
  $item->api_version = 1;
  $item->name = 'variable_current_search';
  $item->label = 'Variable current search';
  $item->settings = array(
    'items' => array(
      'results' => array(
        'id' => 'text',
        'label' => 'Results',
        'text' => t('Search found [facetapi_results:result-count] variable'),
        'plural' => 1,
        'text_plural' => t('Search found [facetapi_results:result-count] variables'),
        'plural_condition' => 'facetapi_results:result-count',
        'wrapper' => 1,
        'element' => 'h3',
        'css' => 1,
        'classes' => 'current-search-result',
        'weight' => '-50',
      ),
      'field_group' => array(
        'id' => 'group',
        'label' => 'Field group',
        'field_pattern' => t('[facetapi_facet:facet-label]:'),
        'nofollow' => 1,
        'weight' => '0',
      ),
    ),
    'advanced' => array(
      'empty_searches' => 1,
    ),
  );
  $export['variable_current_search'] = $item;

  return $export;
}
