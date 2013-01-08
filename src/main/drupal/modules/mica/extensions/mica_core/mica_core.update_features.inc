<?php

function mica_core_rebuild_features($module_name) {

  module_load_include('inc', 'features', 'features.export');
  module_load_include('inc', 'features_override', 'features_override.export');

  $review_url = url("admin/structure/features/$module_name/diff", array('absolute' => TRUE));
  $t = get_t();
  $feature = features_get_features($module_name);
  $states = features_get_component_states(array($feature->name), FALSE);
  foreach ($feature->info['features'] as $component => $items) {
    if (isset($states[$feature->name]) && isset($states[$feature->name][$component])) {
      $state = $states[$feature->name][$component];

      switch ($state) {
        case FEATURES_OVERRIDDEN:
          $overridden_items = array();
          $component_overrides = features_override_module_component_overrides('mica_studies', $component);
          foreach ($component_overrides as $item_name => $item_override) {
            if (!empty($item_override)) {
              $overridden_items[] = $item_name;
            }
          }

          dvm($component, '$component');
          dvm($items, '$items');
          dvm($component_overrides, '$component_overrides');

          $msg = 'Cannot update component %component for module %module: %items were locally overridden. See !link.';
          $args = array(
            '%component' => $component,
            '%module' => $module_name,
            '%items' => implode(', ', $overridden_items),
            '!link' => l(t('details'), $review_url)
          );
          drupal_set_message($t($msg, $args), 'warning');
          watchdog('mica', $msg, $args, WATCHDOG_WARNING, $review_url);
          break;

        case FEATURES_NEEDS_REVIEW:
          $msg = 'Cannot update component %component for module %module: needs review. See !link.';
          $args = array(
            '%component' => $component,
            '%module' => $module_name,
            '!link' => l(t('details'), $review_url)
          );
          drupal_set_message($t($msg, $args), 'warning');
          watchdog('mica', $msg, $args, WATCHDOG_WARNING, $review_url);
          break;

        case FEATURES_DEFAULT:
        case FEATURES_REBUILDABLE:

          $msg = 'Update component %component for module %module.';
          $args = array(
            '%component' => $component,
            '%module' => $module_name,
          );
          drupal_set_message($t($msg, $args));
          watchdog('mica', $msg, $args, WATCHDOG_INFO, url("admin/structure/features/$module_name", array('absolute' => TRUE)));
          features_rebuild(array($module_name => array($component)));
          break;

        default:
          $msg = 'Unsupported state for component %component for module %module: %state.';
          $args = array(
            '%component' => $component,
            '%module' => $module_name,
            '%state' => $state,
          );
          drupal_set_message($t($msg, $args));
          watchdog('mica', $msg, $args, WATCHDOG_DEBUG, url("admin/structure/features/$module_name", array('absolute' => TRUE)));
          break;
      }

    }
  }
}