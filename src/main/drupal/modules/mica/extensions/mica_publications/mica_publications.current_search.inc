<?php
/**
 * @file
 * mica_publications.current_search.inc
 */

/**
 * Implements hook_current_search_default_items().
 */
function mica_publications_current_search_default_items() {
  $export = array();

  $item = new stdClass();
  $item->disabled = FALSE; /* Edit this to true to make a default item disabled initially */
  $item->api_version = 1;
  $item->name = 'publications_search';
  $item->label = 'Publications search';
  $item->settings = array(
    'items' => array(
      'results' => array(
        'id' => 'text',
        'label' => 'Results',
        'text' => 'Search found [facetapi_results:result-count] publication',
        'plural' => 1,
        'text_plural' => 'Search found [facetapi_results:result-count] publications',
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
        'field_pattern' => '[facetapi_facet:facet-label]:',
        'nofollow' => 1,
        'weight' => '0',
      ),
    ),
    'advanced' => array(
      'empty_searches' => '1',
    ),
  );
  $export['publications_search'] = $item;

  return $export;
}
