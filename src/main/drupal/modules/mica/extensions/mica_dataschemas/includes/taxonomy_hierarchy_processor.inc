<?php

class SearchApiTaxonomyHierarchyProcessor extends SearchApiAbstractProcessor {
  
  public function preprocessIndexItems(array &$items) {
  	foreach ($items as &$item) {
      foreach ($item as $name => &$field) {
        if (isset($field['entity_type']) && $field['entity_type'] === 'taxonomy_term' && isset($field['value'])) {
          $new_value = array();
          if (is_array($field['value'])) {
            foreach ($field['value'] as $tid) {
              $parents = taxonomy_get_parents_all($tid);
              foreach ($parents as $parent) {
                $new_value[] = $parent->tid;
              }
            }
           } else {
            $parents = taxonomy_get_parents_all($field['value']);
            foreach ($parents as $parent) {
            	$new_value[] = $parent->tid;
            }            
          }
          $new_value = array_unique($new_value);
          if (count($new_value) > 1) {
            if (!is_array($field['value'])) {
              $field['type'] = 'list<integer>';
              $field['original_type'] = 'list<taxonomy_term>';
            }
            $field['value'] = $new_value;
          } else {
            $field['value'] = $new_value[0];
          }
        }
      }
  	}
  	parent::preprocessIndexItems($items);
  }
  
}