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

  $item = new stdClass;
  $item->disabled = FALSE; /* Edit this to true to make a default item disabled initially */
  $item->api_version = 1;
  $item->name = 'variable_current_search';
  $item->label = 'Variable current search';
  $item->settings = array(
    'items' => array(
      'results' => array(
        'id' => 'text',
        'label' => 'Results',
        'text' => 'Search found [facetapi_results:result-count] variable',
        'plural' => 1,
        'text_plural' => 'Search found [facetapi_results:result-count] variables',
        'plural_condition' => 'facetapi_results:result-count',
        'wrapper' => 1,
        'element' => 'h3',
        'css' => 0,
        'classes' => '',
        'weight' => '-50',
      ),
      'active_items' => array(
        'id' => 'active',
        'label' => 'Active items',
        'pattern' => '[facetapi_active:active-value]',
        'keys' => 1,
        'css' => 0,
        'classes' => '',
        'nofollow' => 1,
        'weight' => '-49',
      ),
    ),
    'advanced' => array(
      'empty_searches' => 1,
    ),
  );
  $export['variable_current_search'] = $item;

  return $export;
}
