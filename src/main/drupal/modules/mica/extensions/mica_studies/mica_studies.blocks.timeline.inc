<?php

function _mica_studies_block_study_timeline($study, $show_draft = TRUE) {

  // http://color-harmony.edelweis-art.com/
  $color_index = 0;
  $colors = array(
    '#9a3034', // Dark red
    '#886e6a', // Brownish-violet
    '#dc9351', // Tan
    '#0078ad', // Dark blue
    '#8db173', // Light green
    '#bca68e', // Light grey
    '#707175', // Dark grey
    '#ff7901', // Orange
    '#88697b', // Violet
    '#99c1c3', // Light blue
  );

  $nb_colors = count($colors);
  $event_view = array();
  $pop_svg = array();
  $legend_items = array();
  $events = array();

  foreach (_mica_studies_sort_populations($study) as $population_nid) {
    $pop_wrapper = entity_metadata_wrapper('node', $population_nid);
    if (($show_draft && $pop_wrapper->status->value() == NODE_NOT_PUBLISHED) || $pop_wrapper->status->value() == NODE_PUBLISHED && node_access('view', $pop_wrapper->value())) {

      $pop_nid = $pop_wrapper->nid->value();
      $pop_title = $pop_wrapper->title->value();

      // See https://drupal.org/project/color_field for more color choices...
      $color = _mica_studies_color_darken($colors[$color_index % $nb_colors], intval($color_index / $nb_colors) * 50);
      $color_index++;

      $svg = "<svg width='25' height='25'><rect width='20' height='20' x='2' y='2' rx='5' ry='5' style='fill:$color;'/></svg>";

      $legend_items[] = $svg . ' ' . $pop_title;
      $pop_svg[] = array('pop_nid' => $pop_nid, 'svg' => $svg);
      foreach ($pop_wrapper->field_pop_dce->getIterator() as $dce_wrapper) {
        if (($show_draft && $dce_wrapper->status->value() == 0) || $dce_wrapper->status->value() == 1 && node_access('view', $dce_wrapper->value())) {
          $start_year = $dce_wrapper->field_dce_start_year->value();
          $end_year = $dce_wrapper->field_dce_end_year->value();
          $dce_nid = $dce_wrapper->nid->value();

          if (!empty($start_year) && !empty($end_year)) {
            $start_month = $dce_wrapper->field_dce_start_month->value();
            $end_month = $dce_wrapper->field_dce_end_month->value();
            $created = $dce_wrapper->created->value();

            $events[] = array(
              'color' => $color,
              'pop_nid' => $pop_wrapper->nid->value(),
              'pop_title' => $pop_wrapper->title->value(),
              'dce_nid' => $dce_nid,
              'dce_title' => $dce_wrapper->title->value(),
              'start_year' => $start_year,
              'end_year' => $end_year,
              'start_month' => empty($start_month) ? 0 : $start_month - 1,
              'end_month' => empty($end_month) ? 12 : $end_month,
              'created' => empty($created) ? 0 : intval($created)
            );
            $event_view[] = _mica_studies_block_study_timeline_prepare_modal($dce_nid);
          }
        }
      }
    }
  }
  if (empty($events)) {
    return NULL;
  }

  uasort($events, '_mica_studies_sort_dce'); // sort by start date
  $lines = _mica_studies_block_study_timeline_prepare_lines($events);

  $legend = '<ul class="timeline-legend">';
  foreach ($legend_items as $item) {
    $legend .= "<li>$item</li>";
  }
  $legend .= '</ul>';

  $events_details = '<div>' . implode(' ', $event_view) . '</div>';

  if (preg_match('/(?i)msie [1-8]/', $_SERVER['HTTP_USER_AGENT'])) {
    $errorMsg = t('In order to view the timeline you must have Internet Explorer 9 or higher.');

    return array(
      'subject' => t('Study Timeline') . '<a name="timeline"> </a>',
      'content' => '<div class="timeline-error">' . $errorMsg . '</div>'
    );
  }

  ctools_add_js('d3.v3.min', 'mica_studies');
  ctools_add_js('d3-timeline', 'mica_studies');
  ctools_add_js('mica_studies.timeline', 'mica_studies');
  drupal_add_js(array('timeline_data' => $lines), array('type' => 'setting'));

  ctools_add_js('mica_studies.timeline.legend', 'mica_studies');
  drupal_add_js(array('timeline_legend_data' => $pop_svg), array('type' => 'setting'));

  $label = t('Each colour in the timeline graph below represents a separate Study Population, '
  . 'while each segment in the graph represents a separate Data Collection Event. '
  . 'Clicking on a segment gives more detailed information on a Data Collection Event.');

  return array(
    'subject' => t('Study Timeline') . '<a name="timeline"> </a>',
    'content' => '<div class="timeline-help">' . $label . '</div><div id="timeline"> </div>' . $legend . $events_details,
  );
}

function _mica_studies_block_study_timeline_prepare_lines($events) {

  $lines_by_pop = array();
  foreach ($events as &$event) {
//     dvm($event, 'Processing');
    if (isset($lines_by_pop[$event['pop_nid']])) {
      $done = FALSE;
      foreach ($lines_by_pop[$event['pop_nid']] as $index => &$line_events) {
//         dvm($line_events, "index: $index");
        $last_event = end($line_events['events']);
        // dvm($last_event, '$last_event for line ' . $index);
        // dvm($event['start'] > $last_event['end'], 'event_start[' . $event['start'] . '] > last_event_end[' . $last_event['end'] . ']');
        if ($event['start_year'] >= $last_event['end_year'] &&
          _mica_studies_convert_to_months($event['start_year'], $event['start_month']) >=
          _mica_studies_convert_to_months($last_event['end_year'], $last_event['end_month'])
        ) {
          $line_events['events'][] = $event;
          $done = TRUE;
//           dvm("Add it to line $index");
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

function _mica_studies_convert_to_months($year, $month) {
  return 12 * $year + $month;
}

function _mica_studies_block_study_timeline_prepare_modal($dce_nid) {
  $dce = node_load($dce_nid);
  return '<div id="event-' . $dce_nid . '" class="modal hide fade">'
  . '<div class="modal-header"><h3>' . $dce->title . '</h3></div>'
  . '<div class="modal-body">' . drupal_render(node_view($dce)) . '</div>'
  . '<div class="modal-footer"><button class="btn" data-dismiss="modal" aria-hidden="true">' . t('Close') . '</button></div>'
  . '</div>';
}

function _mica_studies_color_darken($color, $dif = 20) {

  $color = str_replace('#', '', $color);
  if (strlen($color) != 6) {
    return '000000';
  }
  $rgb = '';

  for ($x = 0; $x < 3; $x++) {
    $c = hexdec(substr($color, (2 * $x), 2)) - $dif;
    $c = ($c < 0) ? 0 : dechex($c);
    $rgb .= (strlen($c) < 2) ? '0' . $c : $c;
  }

  return '#' . $rgb;
}
