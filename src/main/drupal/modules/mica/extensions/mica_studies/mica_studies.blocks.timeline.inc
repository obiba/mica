<?php

function _mica_studies_block_study_timeline($study) {

  // see
  // https://github.com/jiahuang/d3-timeline

  $study_wrapper = entity_metadata_wrapper('node', $study);
  $events = array();
  foreach ($study_wrapper->field_study_populations->getIterator() as $pop_wrapper) {
    foreach ($pop_wrapper->field_pop_dce->getIterator() as $dce_wrapper) {
      $start = $dce_wrapper->field_dce_start_year->value();
      $end = $dce_wrapper->field_dce_end_year->value();
      if (!empty($start) && !empty($end)) {
        $events[] = array(
          'pop_nid' => $pop_wrapper->nid->value(),
          'pop_title' => $pop_wrapper->title->value(),
          'dce_nid' => $dce_wrapper->nid->value(),
          'dce_title' => $dce_wrapper->title->value(),
          'start' => $start,
          'end' => $end,
        );
      }
    }
  }
  if (empty($events)) {
    return NULL;
  }

  uasort($events, '_mica_studies_sort_dce'); // sort by start date
  // dpm($events, '$events');
  $lines = _mica_studies_block_study_timeline_prepare_lines($events);
  dpm($lines, '$lines');

  ctools_add_js('mica_studies.timeline', 'mica_studies');
  drupal_add_js(array('timeline_data' => $lines), array('type' => 'setting'));
  return array(
    'subject' => t('Study Timeline') . '<a name="timeline"> </a>',
    'content' => '<div id="timeline" />',
  );
}

function _mica_studies_block_study_timeline_prepare_lines($events) {
  $lines_by_pop = array();
  foreach ($events as &$event) {
    // dvm($event, 'Processing');
    if (isset($lines_by_pop[$event['pop_nid']])) {
      $done = FALSE;
      foreach ($lines_by_pop[$event['pop_nid']] as $index => &$line_events) {
        // dvm($index, '$index');
        $last_event = end($line_events);
        // // dvm($last_event, '$last_event for line ' . $index);
        // dvm($event['start'] > $last_event['end'], 'event_start[' . $event['start'] . '] > last_event_end[' . $last_event['end'] . ']');
        if ($event['start'] > $last_event['end']) {
          $line_events[] = $event;
          $done = TRUE;
          // dvm("Add it to line $index");
          break;
        }
      }
      if (!$done) {
        $new_line = count($lines_by_pop[$event['pop_nid']]);
        $lines_by_pop[$event['pop_nid']][$new_line][] = $event;
        // dvm("Create new line $new_line");
      }
    }
    else {
      $lines_by_pop[$event['pop_nid']][0][] = $event;
    }
    // dpm($lines_by_pop, '$lines_by_pop');
  }

  // http://color-harmony.edelweis-art.com/
  $colors = array(
    '#5199dc',
    '#a9ccee',
    '#294c6e',
    '#d4e5f6',
    '#3c72a5',
    '#7e99b2',
    '#1e3952',
    '#9fabb8',
    '#b2967e',
    '#eec9a9',
    '#dc9351',
    '#bfbfbf'
  );
  $color_index = 0;
  $lines = array();
  foreach ($lines_by_pop as $population_lines) {
    foreach ($population_lines as $line) {
      $color = $colors[$color_index++];
      foreach ($line as &$event) {
        $event['color'] = $color;
      }
      $lines[] = $line;
    }
  }
  return $lines;
}