<?php
/**
 * @file
 * mica_studies_export_contact.inc
 */

/**
 * Implements hook_field_group_info().
 */
function mica_studies_export_contact_fields_map($nid) {
function mica_studies_export_study_fields_map($nid){

  $wrapper = entity_metadata_wrapper('node', $nid);
  $fieldes=array();
/*
  foreach($wrapper->getPropertyInfo() as $k=>$v){
  //  $fieldes[$k]=$wrapper->{$k}->value();
    $fieldes[$k]=strtolower(str_replace(' ','-',$v['label']));
  }
*/
//  var_export($fieldes);
  $fields_convertion = array (
    'body' => 'summary',
    'title_field' => 'name',
    'field_access_biosamples' => 'biological-samples',
    'field_access_data' => 'data-access',
  //  'field_access_other' => 'other',
  //  'field_access_other_sp' => 'other-access',
  //  'field_acroym' => 'acronym',
 //   'field_authorising_date' => 'authorising-date',
//   'field_authorising_date_m' => 'authorising-date',
  //  'field_authorising_person_name' => 'authorising-name-person',
 //   'field_authorising_person_name_m' => 'maelstrom-authorising-name-person',
  //  'field_authorization_maelstrom' => 'authorization-maelstrom',
  //  'field_authorization_specific' => 'authorization-specific',
    'field_contacts_ref' => 'contacts',
    'field_design' => 'study-design',
 //   'field_design_other_sp' => 'other-design',
 //   'field_documents' => 'documents',
    'field_info_design_follow_up' => 'general-information-follow_up',
    'field_investigators' => 'investigators',
  //  'field_logo' => 'logo',
    'field_marker_paper' => 'marker-paper',
    'field_no_limits_participants' => 'no-limits-in-the-number-of-participants',
    'field_no_limits_samples' => 'no-limits-in-the-number-of-samples',
    'field_pubmedid' => 'pubmed-id',
    'field_recruitment' => 'recruitment-target',
    'field_recruitment_other_sp' => 'other-recruitment-target',
    'field_recruitment_supp_info' => 'supplementary-information-about-study-design',
    'field_study_end_year' => 'study-end-year',
    'field_study_populations' => 'populations',
    'field_study_start_year' => 'study-start-year',
  //  'field_study_study_variable_att' => 'study-variables-attributes',
    'field_supp_infos' => 'supplementary-information',
    'field_target_nb_supp_info' => 'other-target-number-participants',
    'field_target_number_biosamples' => 'target-number-of-participants-with-biological-samples',
    'field_target_number_participants' => 'target-number-of-participants',
    'field_website' => 'website',
//    'mica_dataset' => 'datasets',
   // 'mica_opal' => 'opal',
 //   'nid' => 'node-id',
  //  'vid' => 'revision-id',
  //  'is_new' => 'is-new',
    'type' => 'content-type',
    'title' => 'title',
 //   'language' => 'language',
 //   'url' => 'url',
 //   'edit_url' => 'edit-url',
 //   'status' => 'status',
 //   'promote' => 'promoted-to-frontpage',
 //   'sticky' => 'sticky-in-lists',
    'created' => 'date-created',
    'changed' => 'date-changed',
 //   'author' => 'author',
 //   'source' => 'translation-source-node',
  //  'log' => 'revision-log-message',
 //   'revision' => 'creates-revision',
 //   'comment' => 'comments-allowed',
  //  'comment_count' => 'comment-count',
 //   'comment_count_new' => 'new-comment-count',
 //   'feed_nid' => 'feed-nid',
    'uuid' => 'uuid',
 //   'vuuid' => 'revision-uuid',
  );

  foreach($fields_convertion as $k=>$v){


    $fieldes[$v]=$wrapper->field_investigators->value();
    // var_export($fieldes,false);
 print_r($fieldes);
 die;
    return $fieldes;
  }





}