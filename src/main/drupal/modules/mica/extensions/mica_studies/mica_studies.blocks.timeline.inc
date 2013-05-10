<?php

function _mica_studies_block_study_timeline($study) {

  // see
  // https://github.com/jiahuang/d3-timeline

  $data = array();
  $study_wrapper = entity_metadata_wrapper('node', $study);
  foreach ($study_wrapper->field_study_populations->getIterator() as $pop_wrapper) {
    $pop_nid = $pop_wrapper->nid->value();
    $events = array();
    foreach ($pop_wrapper->field_pop_dce->getIterator() as $dce_wrapper) {
      $dce_nid = $dce_wrapper->nid->value();
      $start = $dce_wrapper->field_dce_start_date->value();
      $end = $dce_wrapper->field_dce_end_date->value();
      if (!empty($start) && !empty($end)) {
        $events[$start] = array(
          'nid' => $dce_nid,
          'title' => $dce_wrapper->title->value(),
          'start' => $start,
          'end' => $end,
          'start-label' => empty($start) ? '' : date("Y M", $start),
          'end-label' => empty($end) ? '' : date("Y M", $end),
        );
      }
    }

    _mica_studies_block_study_timeline_set_line_nb($events);

    $data[$pop_nid] = array(
      'nid' => $pop_nid,
      'title' => $pop_wrapper->title->value(),
      'events' => $events,
    );
  }

//  dvm($data);
//
//  array(
//    58 => array(
//      'nid' => '58',
//      'title' => 'Population 1',
//      'events' => array(
//        59 => array(
//          'nid' => '59',
//          'title' => 'Event 1',
//          'start' => '1367380800',
//          'end' => '1462075200',
//          'start-label' => '2013 May',
//          'end-label' => '2016 May',
//        ),
//        60 => array(
//          'nid' => '60',
//          'title' => 'Event 2',
//          'start' => NULL,
//          'end' => NULL,
//          'start-label' => '',
//          'end-label' => '',
//        ),
//        61 => array(
//          'nid' => '61',
//          'title' => 'Event 3',
//          'start' => '799300800',
//          'end' => NULL,
//          'start-label' => '1995 May',
//          'end-label' => '',
//        ),
//      ),
//    ),
//  )

  return array(
    'subject' => t('Study Timeline') . '<a name="timeline"> </a>',
    'content' => 'TODO',
  );
}

function _mica_studies_block_study_timeline_set_line_nb(&$events) {
  ksort($events); // sort by start date

  $lines = array();
  foreach ($events as $event) {
    if (empty($lines)) {
      $event['line'] = 0;
      $lines[0][] = $event;
    }
    else {
      foreach ($lines as $index => $line_events) {
        $last_event = end($line_events);
        if ($event['start'] > $last_event['end']) {
          $event['line'] = $index;
          $lines[$index][] = $event;
          break;
        }
      }
      if (empty($event['line'])) {
        $new_line = count($lines);
        $event['line'] = $new_line;
        $lines[$new_line][] = $event;
      }
    }
  }
}