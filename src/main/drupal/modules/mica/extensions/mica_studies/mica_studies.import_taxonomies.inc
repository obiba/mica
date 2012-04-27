<?php

/**
 * @file
 * Mica Datasets taxonomies importer
 */

function _mica_studies_taxonomies() {
	$base_path = drupal_get_path('module', 'mica_studies') . '/taxonomies/';
	return array(
	array('sources_of_recruitment.csv', $base_path, 'Source of Recruitment'),
	);
}

/**
 * Implements hook_taxonomies_operations_import()
 */
function mica_studies_taxonomies_operations_import() {
	$operations = array();
	foreach (_mica_studies_taxonomies() as $taxonomy) {
		$operations[] = array('mica_core_taxonomy_import', $taxonomy);
	}
	return $operations;
}