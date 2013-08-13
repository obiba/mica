<?php
/**
 * @file
 * Mica Opal XML View generator
 */

class ServicesDatasetsFormatter implements ServicesFormatterInterface {

  const MAELSTROM_NS = 'maelstrom';

  protected $doc;
  protected $languages;

  function render($data) {
    try {

      $this->languages = array_keys(language_list());

      $dataset_wrapper = entity_metadata_wrapper('node', $data);
      $dataset_name = $dataset_wrapper->title_field->value();

      $filename = check_plain($dataset_name);

      $study_name = NULL;
      if (isset($_GET['study'])) {
        $study = node_load($_GET['study']);
        $study_wrapper = entity_metadata_wrapper('node', $study);
        $study_acronym = $study_wrapper->field_acroym->value();
        $study_name = $study_wrapper->title_field->value();
        $filename .= ' - ' . check_plain(empty($study_acronym) ? $study_name : $study_acronym);
      }

      $this->doc = new DOMDocument();

      $element = $this->addHeaders($dataset_wrapper, $study_name);

      $variables = $dataset_wrapper->field_dataset_variables->value();

      module_load_include('inc', 'mica_datasets', 'mica_datasets.utils');
      uasort($variables, 'mica_datasets_sort_by_position');

      if (empty($study) || !node_access('view', $study)) {
        foreach ($variables as $variable) {
          $this->render_variable($variable, $element, NULL);
        }
      }
      else {
        foreach ($variables as $variable) {

          $sva_query = new EntityFieldQuery();
          $sva_results = $sva_query->entityCondition('entity_type', 'node')
            ->entityCondition('bundle', 'study_variable_attributes')
            ->fieldCondition('field_sva_variable', 'nid', $variable->nid)
            ->execute();
          $svas = empty($sva_results['node']) ? array() : node_load_multiple(array_keys($sva_results['node']));
          $found = FALSE;
          foreach ($svas as $sva) {

            $sva_wrapper = entity_metadata_wrapper('node', $sva);
            if ($study->nid == $sva_wrapper->field_sva_study->nid->value()) {
              $this->render_variable($variable, $element, $sva);
              $found = TRUE;
              break;
            }
          }
          if (!$found) {
            $this->render_variable($variable, $element, NULL);
          }
        }
      }

      drupal_add_http_header('Content-Disposition', "attachment; filename=$filename.xml");
      $this->doc->formatOutput = TRUE;
      return $this->doc->saveXml();
    } catch (Exception $e) {
      watchdog_exception('mica', $e);
      throw $e;
    }
  }

  private function addHeaders($dataset, $study_name = NULL) {
    $dataset_name = check_plain($dataset->title_field->value());
    $type = $dataset->field_dataset_type->value();
    $remote_url = $dataset->field_remote_url->value();
    $desc = $dataset->body->value->value();

    $comment = 'XML Dataset View for dataset \'' . $dataset_name . '\'';
    if (!empty($study_name)) {
      $comment .= ' and study \'' . check_plain($study_name) . '\'';
    }
    $this->doc->appendChild($this->doc->createComment($comment));

    $dataset = $this->doc->appendChild($this->doc->createElement('dataset'));
    $dataset->setAttribute('name', $dataset_name);
    $dataset->setAttribute('dataset_type', $type);
    $dataset->setAttribute('remote_url', $remote_url);

    $body = $dataset->appendChild($this->doc->createElement('body'));
    $body->appendChild($this->doc->createCDATASection($desc));

    $element = $dataset->appendChild($this->doc->createElement('variables'));

    $date = $this->doc->appendChild($this->doc->createElement('created'));
    $date->setAttribute('valueType', 'dateTime');
    $date->appendChild($this->doc->createTextNode(date('Y-m-j H:i')));

    return $element;
  }

  private function render_variable($variable, &$element, $sva = NULL) {
    $wrapper = entity_metadata_wrapper('node', $variable);

    $variable_element = $element->appendChild($this->doc->createElement('variable'));
    $variable_element->setAttribute('name', $wrapper->title->value());
    $variable_element->setAttribute('valueType', drupal_strtolower($wrapper->field_value_type->value()));

    if ($wrapper->field_unit->value() != NULL) {
      $variable_element->setAttribute('unit', $wrapper->field_unit->value());
    }
    $remote_url = $wrapper->field_remote_url->value();
    $variable_element->setAttribute('remote_url', $remote_url['url']);

// repeatable
    if ($wrapper->field_repeatable->value() == '1') {
      $variable_element->setAttribute('repeatable', 'true');
      $variable_element->setAttribute('occurenceGroup', $wrapper->title->value());
    }
    else {
      $variable_element->setAttribute('repeatable', 'false');
    }
    $attributes = $variable_element->appendChild($this->doc->createElement('attributes'));

    foreach ($this->languages as $language) {
      $this->addAttribute($attributes, 'label', $language, $wrapper->language($language)->field_label->value());
    }

    foreach ($this->languages as $language) {
      $body = $wrapper->language($language)->body->value();
      if (!empty($body)) {
        $b = $variable_element->appendChild($this->doc->createElement('body'));
        $b->setAttribute('language', $language);
        $b->appendChild($this->doc->createCDATASection($wrapper->language($language)->body->value->value()));
      }
    }

    $this->addDimensions($attributes, $wrapper);

    $this->addStudyVariableAttributes($attributes, $sva);

    $this->addCategories($variable_element, $wrapper);
  }

  private function addStudyVariableAttributes($attributes, $sva) {
    if (!empty($sva)) {
      $sva_wrapper = entity_metadata_wrapper('node', $sva);
      $this->addAttribute($attributes, 'script', NULL, $sva_wrapper->field_sva_script->value(), NULL, TRUE);
      $this->addAttribute($attributes, 'status', NULL, $sva_wrapper->field_sva_status->value());
      foreach ($this->languages as $language) {
        $this->addAttribute($attributes, 'comment', $language,
          $sva_wrapper->language($language)->field_sva_comment->value());
      }
    }
  }

  private function addDimensions($attributes, $wrapper) {
    $this->addTaxonomyAttribute($attributes, 'anthropometric_structures', $wrapper);
    $this->addTaxonomyAttribute($attributes, 'body_functions', $wrapper);
    $this->addTaxonomyAttribute($attributes, 'body_structures', $wrapper);
    $this->addTaxonomyAttribute($attributes, 'data_source', $wrapper);
    $this->addTaxonomyAttribute($attributes, 'disease_history', $wrapper);
    $this->addTaxonomyAttribute($attributes, 'early_life', $wrapper);
    $this->addTaxonomyAttribute($attributes, 'essence', $wrapper);
    $this->addTaxonomyAttribute($attributes, 'life_habits_behaviours', $wrapper);
    $this->addTaxonomyAttribute($attributes, 'measure', $wrapper);
    $this->addTaxonomyAttribute($attributes, 'medical_health_intervention', $wrapper, 'field_medical_health_interv');
    $this->addTaxonomyAttribute($attributes, 'medication', $wrapper);
    $this->addTaxonomyAttribute($attributes, 'perception_of_health', $wrapper);
    $this->addTaxonomyAttribute($attributes, 'period', $wrapper);
    $this->addTaxonomyAttribute($attributes, 'physical_environment', $wrapper);
    $this->addTaxonomyAttribute($attributes, 'reproductive_history', $wrapper);
    $this->addTaxonomyAttribute($attributes, 'social_environment', $wrapper);
    $this->addTaxonomyAttribute($attributes, 'sociodemographic_characteristics', $wrapper, 'field_sociodemographic_charact');
    $this->addTaxonomyAttribute($attributes, 'target', $wrapper);
  }

  private function addCategories($variable_element, $wrapper) {
    $nbCategories = count($wrapper->field_variable_categories->value());
    if ($nbCategories > 0) {
      $categories = $variable_element->appendChild($this->doc->createElement('categories'));
      for ($i = 0; $i < $nbCategories; $i++) {
        $cat_element = $categories->appendChild($this->doc->createElement('category'));
        $cat_element->setAttribute('name', $wrapper->field_variable_categories[$i]->name->value());
        $cat_element->setAttribute('label', $wrapper->field_variable_categories[$i]->label->value());
        if ($wrapper->field_variable_categories[$i]->missing->value() == '1') {
          $cat_element->setAttribute('missing', 'true');
        }
      }
    }
  }

  private function addTaxonomyAttribute($attributes, $name, $variable_wrapper, $field = NULL) {
    $terms = $variable_wrapper->{empty($field) ? 'field_' . $name : $field}->value();
    if (!empty($terms)) {
      if (is_array($terms)) {
        foreach ($terms as $term) {
          $this->addTermAttribute($attributes, $name, $term);
        }
      }
      else {
        $this->addTermAttribute($attributes, $name, $terms);
      }
    }
  }

  private function addTermAttribute($attributes, $name, $term) {
    foreach ($this->languages as $language) {
      if (function_exists('i18n_taxonomy_term_name')) {
        $this->addAttribute($attributes, $name, $language, i18n_taxonomy_term_name($term, $language));
      }
      else {
        $this->addAttribute($attributes, $name, $language, $term->name);
      }
    }
  }

  private function addAttribute($attributes, $name, $lang, $value, $namespace = NULL, $use_cdata = FALSE) {
    if (empty($value)) {
      return;
    }
    $attribute = $attributes->appendChild($this->doc->createElement('attribute'));
    $attribute->setAttribute('name', $name);
    if (!empty($lang)) {
      $attribute->setAttribute('locale', $lang);
    }

    $attribute->appendChild($use_cdata ? $this->doc->createCDATASection($value) : $this->doc->createTextNode($value));
  }

}