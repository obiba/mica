<?php

class SearchApiTaxonomyHierarchyProcessor extends SearchApiAbstractProcessor {
  
  public function preprocessIndexItems(array &$items) {
  	
  	foreach ($items as &$item) {
      foreach ($item as $name => &$field) {
        if(isset($field['entity_type']) && $field['entity_type'] === 'taxonomy_term' && isset($field['value'])) {
          $new_value = array();
          if(is_array($field['value'])) {
            foreach ($field['value'] as $tid) {
              $parents = taxonomy_get_parents_all($tid);
              foreach ($parents as &$parent) {
                $new_value[] = $parent->tid;
              }
            }
          } else {
            $parents = taxonomy_get_parents_all($field['value']);
            foreach ($parents as &$parent) {
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