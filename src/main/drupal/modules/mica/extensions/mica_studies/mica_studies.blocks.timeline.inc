<?php

function _mica_studies_block_study_timeline($study) {

  // http://color-harmony.edelweis-art.com/
  $color_index = 0;
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

  $pop_svg = array();
  $legend_items = array();
  $study_wrapper = entity_metadata_wrapper('node', $study);
  $events = array();
  foreach ($study_wrapper->field_study_populations->getIterator() as $pop_wrapper) {
    $pop_nid = $pop_wrapper->nid->value();
    $color = $colors[$color_index++];
    $svg = "<svg width='25' height='25'><rect width='20' height='20' x='2' y='2' rx='5' ry='5' style='fill:$color;'/></svg>";
    $legend_items[] = $svg . ' ' . $pop_wrapper->title->value();
    $pop_svg[] = array('pop_nid' => $pop_nid, 'svg' => $svg);
    foreach ($pop_wrapper->field_pop_dce->getIterator() as $dce_wrapper) {
      $start = $dce_wrapper->field_dce_start_year->value();
      $end = $dce_wrapper->field_dce_end_year->value();
      if (!empty($start) && !empty($end)) {
        $events[] = array(
          'color' => $color,
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

  $legend = '<ul class="timeline-legend">';
  foreach ($legend_items as $item) {
    $legend .= "<li>$item</li>";
  }
  $legend .= '</ul>';

  ctools_add_js('d3.v3.min', 'mica_studies');
  ctools_add_js('d3-timeline', 'mica_studies');
  ctools_add_js('mica_studies.timeline', 'mica_studies');
  drupal_add_js(array('timeline_data' => $lines), array('type' => 'setting'));

  ctools_add_js('mica_studies.timeline.legend', 'mica_studies');
  drupal_add_js(array('timeline_legend_data' => $pop_svg), array('type' => 'setting'));

  return array(
    'subject' => t('Study Timeline') . '<a name="timeline"> </a>',
    'content' => '<div id="timeline"> </div>' . $legend,
  );
}

function _mica_studies_block_study_timeline_prepare_lines($events) {

  $lines_by_pop = array();
  foreach ($events as &$event) {
    // dvm($event, 'Processing');
    if (isset($lines_by_pop[$event['pop_nid']])) {
      $done = FALSE;
      foreach ($lines_by_pop[$event['pop_nid']] as $index => &$line_events) {
        // dvm($line_events, "index: $index");
        $last_event = end($line_events['events']);
        // dvm($last_event, '$last_event for line ' . $index);
        // dvm($event['start'] > $last_event['end'], 'event_start[' . $event['start'] . '] > last_event_end[' . $last_event['end'] . ']');
        if ($event['start'] >= $last_event['end'] && $event['start'] > $last_event['start']) {
          $line_events['events'][] = $event;
          $done = TRUE;
          // dvm("Add it to line $index");
          break;
        }
      }
      if (!$done) {
        $new_line = count($lines_by_pop[$event['pop_nid']]);
        $lines_by_pop[$event['pop_nid']][$new_line] = array(
          'pop_nid' => $event['pop_nid'],
          'pop_title' => $event['pop_title'],
          'color' => $event['color'],
          'events' => array($event),
        );
        // dvm("Create new line $new_line");
      }
    }
    else {
      $lines_by_pop[$event['pop_nid']][] = array(
        'pop_nid' => $event['pop_nid'],
        'pop_title' => $event['pop_title'],
        'color' => $event['color'],
        'events' => array($event),
      );
    }
    // dpm($lines_by_pop, '$lines_by_pop');
  }

  $lines = array();
  foreach ($lines_by_pop as $population_lines) {
    foreach ($population_lines as $line) {
      $lines[] = $line;
    }
  }
  return $lines;
}

