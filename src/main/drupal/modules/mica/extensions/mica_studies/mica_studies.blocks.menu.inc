<?php

function _mica_studies_block_study_menu($study) {
  // $study can be the study nid
  if (is_numeric($study)) {
    $study = node_load($study);
  }

  // see http://snpeff.sourceforge.net/features.html

  //TODO add missing sections
  //TODO hide items for empty sections
  //TODO links to anchor don't work
  $items = array(
    l(t('General Information'), '#general-info'),
    l(t('General Design'), '#general-design'),
    l(t('Access'), '#access'),
    l(t('Marker Paper'), '#marker-paper'),
    l(t('Populations'), '#populations'),
    l(t('Timeline'), '#timeline'),
    l(t('Authorization'), '#authorization'),
  );
  return array(
    'subject' => t('Study Menu'),
    'content' => theme('item_list', array('items' => $items)),
  );
}