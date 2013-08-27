<?php
/**
 * @file
 * Mica Opal XML View generator
 */

class ServicesOpalFormatter implements ServicesFormatterInterface {

  const MAELSTROM_NS = 'maelstrom';

  protected $doc;
  protected $languages;

  function render($data) {
    try {

      $this->languages = array_keys(language_list());

      $dataset_wrapper = entity_metadata_wrapper('node', $data->nid);
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

      $element = $this->addHeaders($dataset_name, $study_name);

      // Sort variables
      module_load_include('inc', 'mica_datasets', 'mica_datasets.utils');
      $variables = array();
      foreach ($dataset_wrapper->field_dataset_variables->getIterator() as $v) {
        $variables[] = $v->nid->value();
      }
      uasort($variables, 'mica_datasets_sort_by_position');

      if (empty($study) || !node_access('view', $study)) {
        foreach ($variables as $vid) {
          $this->render_variable($vid, $element, NULL);
        }
      }
      else {
        foreach ($variables as $variable) {

          $sva_query = new EntityFieldQuery();
          $sva_results = $sva_query->entityCondition('entity_type', 'node')
            ->entityCondition('bundle', 'study_variable_attributes')
            ->fieldCondition('field_sva_variable', 'nid', $variable)
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

  private function addHeaders($dataset_name, $study_name = NULL) {
    $comment = 'XML Opal View for dataset \'' . check_plain($dataset_name) . '\'';
    if (!empty($study_name)) {
      $comment .= ' and study \'' . check_plain($study_name) . '\'';
    }
    $this->doc->appendChild($this->doc->createComment($comment));

    $opal = $this->doc->appendChild($this->doc->createElement('org.obiba.magma.views.View'));
    $select = $opal->appendChild($this->doc->createElement('select'));
    $select->setAttribute('class', 'org.obiba.magma.views.support.NoneClause');

    $where = $opal->appendChild($this->doc->createElement('where'));
    $where->setAttribute('class', 'org.obiba.magma.views.support.AllClause');

    $variables = $opal->appendChild($this->doc->createElement('variables'));
    $variables->setAttribute('class', 'org.obiba.magma.js.views.VariablesClause');

    $date = $opal->appendChild($this->doc->createElement('created'));
    $date->setAttribute('valueType', 'dateTime');
    $date->appendChild($this->doc->createTextNode(date('Y-m-j H:i')));

    $element = $variables->appendChild($this->doc->createElement('variables'));
    $element->setAttribute('class', 'linked-hash-set');
    return $element;
  }

  private function render_variable($variable, &$element, $sva = NULL) {
    $wrapper = entity_metadata_wrapper('node', $variable);
    //debug($variable);

    $variable_element = $element->appendChild($this->doc->createElement('variable'));
    $variable_element->setAttribute('name', $wrapper->title->value());
    $variable_element->setAttribute('valueType', drupal_strtolower($wrapper->field_value_type->value()));
    $variable_element->setAttribute('entityType', 'Participant');

    if (isset($wrapper->unit)) {
      $variable_element->setAttribute('unit', $wrapper->unit->value());
    }

    // repeatable
    if ($wrapper->field_repeatable->value() == '1') {
      $variable_element->setAttribute('repeatable', 'true');
      $variable_element->setAttribute('occurenceGroup', $wrapper->title->value());
    }
    else {
      $variable_element->setAttribute('repeatable', 'false');
    }
    $attributes = $variable_element->appendChild($this->doc->createElement('attributes'));
    $this->addAttribute($attributes, 'uuid', 'text', '', $wrapper->uuid->value(), self::MAELSTROM_NS);

    foreach ($this->languages as $language) {
      $this->addAttribute($attributes, 'label', 'text', $language, $wrapper->language($language)->field_label->value());
    }

    foreach ($this->languages as $language) {
      $body = $wrapper->language($language)->body->value();
      if (!empty($body)) {
        $this->addAttribute($attributes, 'description', 'text', $language,
          $wrapper->language($language)->body->value->value(array('decode' => TRUE)), self::MAELSTROM_NS);
      }
    }

    $this->addDimensions($attributes, $wrapper);
    $this->addStudyVariableAttributes($attributes, $sva);
    $this->addCategories($variable_element, $wrapper);
  }

  private function addStudyVariableAttributes($attributes, $sva) {
    if (!empty($sva)) {
      $sva_wrapper = entity_metadata_wrapper('node', $sva);
      $this->addAttribute($attributes, 'script', 'text', NULL, $sva_wrapper->field_sva_script->value(), NULL, TRUE);
      $this->addAttribute($attributes, 'status', 'text', NULL, $sva_wrapper->field_sva_status->value(), self::MAELSTROM_NS);
      foreach ($this->languages as $language) {
        $this->addAttribute($attributes, 'comment', 'text', $language,
          $sva_wrapper->language($language)->field_sva_comment->value(), self::MAELSTROM_NS);
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
    $this->addTaxonomyAttribute($attributes, 'life_habits_behaviours', $wrapper);
    $this->addTaxonomyAttribute($attributes, 'medical_health_intervention', $wrapper, 'field_medical_health_interv');
    $this->addTaxonomyAttribute($attributes, 'medication', $wrapper);
    $this->addTaxonomyAttribute($attributes, 'perception_of_health', $wrapper);
    $this->addTaxonomyAttribute($attributes, 'physical_environment', $wrapper);
    $this->addTaxonomyAttribute($attributes, 'reproductive_history', $wrapper);
    $this->addTaxonomyAttribute($attributes, 'social_environment', $wrapper);
    $this->addTaxonomyAttribute($attributes, 'sociodemographic_characteristics', $wrapper, 'field_sociodemographic_charact');
    $this->addTaxonomyAttribute($attributes, 'target', $wrapper);
    $this->addTaxonomyAttribute($attributes, 'administrative_information', $wrapper);
  }

  private function addCategories($variable_element, $wrapper) {
    $nbCategories = count($wrapper->field_variable_categories->value());
    if ($nbCategories > 0) {
      $categories = $variable_element->appendChild($this->doc->createElement('categories'));
      for ($i = 0; $i < $nbCategories; $i++) {
        $cat_element = $categories->appendChild($this->doc->createElement('category'));
        $cat_element->setAttribute('name', $wrapper->field_variable_categories[$i]->name->value());
        if ($wrapper->field_variable_categories[$i]->missing->value() == '1') {
          $cat_element->setAttribute('missing', 'true');
        }
        $category_element_att = $cat_element->appendChild($this->doc->createElement('attributes'));
        foreach ($this->languages as $language) {
          $label = $wrapper->language($language)->field_variable_categories[$i]->label->value();
          if (!empty($label)) {
            $attribute = $category_element_att->appendChild($this->doc->createElement('attribute'));
            $attribute->setAttribute('name', 'label');
            $attribute->setAttribute('valueType', 'text');
            $attribute->setAttribute('locale', $language);
            $attribute->appendChild($this->doc->createTextNode($label));
          }
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
        $this->addAttribute($attributes, $name, 'text', $language, i18n_taxonomy_term_name($term, $language), self::MAELSTROM_NS);
      }
      else {
        $this->addAttribute($attributes, $name, 'text', $language, $term->name, self::MAELSTROM_NS);
      }
    }
  }

  private function addAttribute($attributes, $name, $valueType, $lang, $value, $namespace = NULL, $use_cdata = FALSE) {
    if (empty($value)) {
      return;
    }
    $attribute = $attributes->appendChild($this->doc->createElement('attribute'));
    $attribute->setAttribute('name', $name);
    $attribute->setAttribute('valueType', $valueType);
    if (!empty($lang)) {
      $attribute->setAttribute('locale', $lang);
    }
    if (!empty($namespace)) {
      $attribute->setAttribute('namespace', $namespace);
    }
    $attribute->appendChild($use_cdata ? $this->doc->createCDATASection($value) : $this->doc->createTextNode($value));
  }

}
