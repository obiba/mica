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
      $start = $dce_wrapper->field_dce_start_year->value();
      $end = $dce_wrapper->field_dce_end_year->value();
      if (!empty($start) && !empty($end)) {
        $events[$start] = array(
          'nid' => $dce_nid,
          'title' => $dce_wrapper->title->value(),
          'start' => $start,
          'end' => $end,
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

  dvm($data);
  return array(
    'subject' => t('Study Timeline') . '<a name="timeline"> </a>',
    'content' => 'TODO',
  );
}

function _mica_studies_block_study_timeline_set_line_nb(&$events) {
  ksort($events); // sort by start date

  $lines = array();
  foreach ($events as &$event) {
    dvm($event, 'Processing');
    if (empty($lines)) {
      $event['line'] = 0;
      $lines[0][] = $event;
    }
    else {
      foreach ($lines as $index => $line_events) {
        $last_event = end($line_events);
        dvm($last_event, '$last_event');
        if ($event['start'] > $last_event['end']) {
          $event['line'] = $index;
          $lines[$index][] = $event;
          dvm("Add it to line $index");
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

  dvm($lines, '$lines');
  dvm($events, '$event');

}