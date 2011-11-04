<?php

/**
 * Add taxonomy term's parents to index.
 * Indexed field cardinality MUST BE 'unlimited', because if the associated term has parent 
 * the field will have several values.
 * If indexed field supports only one value and the associated term has parents, it will throw an exception.
 */
class SearchApiTaxonomyHierarchyProcessor extends SearchApiAbstractProcessor {

  public function preprocessIndexItems(array &$items) {
    foreach ($items as &$item) {
      foreach ($item as $name => &$field) {
        if (isset($field['entity_type']) && $field['entity_type'] === 'taxonomy_term' && isset($field['value'])) {
          $new_value = array();
          foreach ($field['value'] as $tid) {
            $parents = taxonomy_get_parents_all($tid);
            foreach ($parents as $parent) {
              $new_value[] = $parent->tid;
            }
          }
          $field['value'] = array_unique($new_value);
        }
      }
    }
    parent::preprocessIndexItems($items);
  }

}