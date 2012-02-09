<?php


/**
* Returns an array of search index with bundle name as keys.
*/
function mica_core_find_indexes_by_bundle() {
	$indexes = array();
	foreach (entity_load('search_api_index') as $index) {
		$options = $index->options;
		if (!empty($options['data_alter_callbacks'])
  		&& !empty($options['data_alter_callbacks']['search_api_alter_bundle_filter'])
  		&& !empty($options['data_alter_callbacks']['search_api_alter_bundle_filter']['settings'])
  		&& !empty($options['data_alter_callbacks']['search_api_alter_bundle_filter']['settings']['bundles']))
		foreach ($options['data_alter_callbacks']['search_api_alter_bundle_filter']['settings']['bundles'] as $bundle) {
			$indexes[$bundle] = array($index->machine_name => $index->name);
		}
	}
	return $indexes;
}