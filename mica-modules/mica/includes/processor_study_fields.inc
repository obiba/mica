<?php

class SearchApiProcessorStudyFields extends SearchApiAbstractProcessor {

	public function preprocessIndexItems(array &$items) {
		//debug($items);
		$relations_map = array();

		foreach ($items as $nid => &$item) {
			$type = $item['type']['value'];
			if (!array_key_exists($type, $relations_map)) {
				$relations = _mica_find_relations_by_parent($type);
				if (!empty($relations)) {
					foreach ($relations as $relation) {
						$child_type = $relation['child'];
						$node_reference_name = $relation['node_reference'];
						if (array_key_exists($node_reference_name, $item)) {
							$child_nid = $item[$node_reference_name]['value'];
							$relations_map[$child_nid] = $nid;
						}
						else {
							// error message about node_reference_name not indexed
							throw new MicaException(t("Mica: Couldn't index values for '!name' index: '!field' is not selected for indexing.", array('!name' => $this->index->name, '!field' => $node_reference_name)));
						}
					}
				}
			}
		}

		//debug($relations_map);

		foreach($relations_map as $child_nid => &$parent_id) {
			$child_item = $this->getItem($items, $child_nid);
			$parent_item = $this->getItem($items, $parent_id);
			foreach($child_item as $field => $value) {
				if ($this->isVariable($field)) {
					$parent_item[$field]['value'] = $value['value'];
				}
			}
			$items[$parent_id] = $parent_item;
		}

		//debug($items);

	}

	private function isVariable($field) {
		$needle = 'field_';
		return strcmp(substr($field, 0, strlen($needle)), $needle)===0;
	}

	private function getItem(array &$items, $nid) {
		foreach ($items as $id => &$item) {
			if ($id == $nid) {
				return $item;
			}
		}
	}

}
