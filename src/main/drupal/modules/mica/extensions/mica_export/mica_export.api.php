<?php

/**
 * @file
 * Documentation of Mica_export hooks.
 */

/**
 * Find related node to export
 * @param $node
 * @return array of nid to export with specified node
 */
function hook_mica_export_find_related_nids($node) {
  $nids = array();
  $nids[] = $node->nid;
  $node_wrapper = entity_metadata_wrapper('node', $node->nid);
  foreach ($node_wrapper->field_contacts_ref->getIterator() as $contact_wrapper) {
    $nids[] = $contact_wrapper->nid->value();
  }
  return $nids;
}

/**
 * Export node to XML
 * @param $node node to serialize
 * @param $temp_folder_path folder where to copy attachments
 * @return XML as a string
 */
function hook_mica_export_to_xml($node, $temp_folder_path) {
  $wrapper = entity_metadata_wrapper('node', $node);
  if ($node->type === 'study') {
    mica_export_copy_attachment_file($wrapper->field_files->value(), $temp_folder_path);
    $dom = new DomDocument('1.0', 'utf-8');
    $root = $dom->createElement($node->type);
    $root->setAttribute('uuid', $wrapper->uuid->value());
    $dom->appendChild($root);
    return $dom->saveXML();
  }
  return NULL;
}