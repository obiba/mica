<?php

class SearchApiProcessorStudyFields extends SearchApiAbstractProcessor {

	public function preprocessIndexItems(array &$items) {
		debug("pouet");
	}
	
    private function alterItems(array &$items) {
		$relations_inversed = array();

		foreach ($items as $id => &$item) {
			$relations = _mica_find_relations_by_parent($item->type);
			if (!empty($relations)) {
				foreach ($relations as $relation) {
					$child_type = $relation->child_type[$relation->language][0]['value'];
					$field_ref = "field_" . $relation->node_reference_name[$relation->language][0]['value'];
					 
					$field_value = $item->$field_ref;
					$relations_inversed[$field_value[$relation->language][0]['nid']] = $item;
				}
			}
		}
		//debug($relations_inversed);
		foreach($relations_inversed as $child_nid => $parent_item) {
			$child_item = $this->getItem($items, $child_nid);
			foreach($child_item as $field => $value) {
				if ($this->isVariable($field)) {
					//debug($field);
					//debug($value);
					$parent_item->$field = $value;
				}
			}
		}
		//debug($items);
	}

	private function isVariable($field) {
		$needle = 'field_';
		return strcmp(substr($field, 0, strlen($needle)), $needle)===0;
	}

	private function getItem(array &$items, $nid) {
		foreach ($items as $id => &$item) {
			if ($item->nid == $nid) {
				return $item;
			}
		}
	}

}
