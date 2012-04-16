<?php
/**
 * @file
 * Studies module pages
 */

/**
 * Render a page of available exporters.
 */
function mica_studies_export_page() {
  $rows = array();

  // data exporters are views with a display of type 'views_data_export'
  $views = views_get_all_views();
  foreach ($views as $view) {
    // Skip disabled views and broken views
    if (!empty($view->disabled) || empty($view->display)) {
      continue;
    }

    foreach (array_keys($view->display) as $id) {
      // filter by display type
      if (strpos($id, 'views_data_export', 0) !== FALSE) {
        if (array_key_exists('path', $view->display[$id]->display_options)) {
          $path = $view->display[$id]->display_options['path'];
          $item = menu_get_item($path);
          // filter by access right
          if ($item && $item['access']) {
            $rows[] = array(
              l($view->human_name, $path),
              check_plain($view->description),
            );
          }
        }
      }
    }
  }

  $header = array(
    t('Export'),
    t('Description'),
  );
  return theme('table', array('header' => $header, 'rows' => $rows, 'empty' => t('There are no data exporters.')));
}

