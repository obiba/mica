<?php
/**
 * @file
 * Mica Opal XML View generator
 */


class OpalXmlFormatView extends RESTServerView {

  const MAELSTROM_NS = 'maelstrom';

  private $doc;

  function render() {
    try {

      $dataset = $this->model;
      $dataset_wrapper = entity_metadata_wrapper('node', $dataset);
      $dataset_name = $dataset_wrapper->title_field->value();

      $filename = check_plain($dataset_name);

      if (isset($_GET['study'])) {
        $study = node_load($_GET['study']);
        $study_wrapper = entity_metadata_wrapper('node', $study);
        $study_acronym = $study_wrapper->field_acroym->value();
        $study_name = $study_wrapper->title_field->value();
        $filename .= ' - ' . check_plain(empty($study_acronym) ? $study_name : $study_acronym);
      }

      $this->doc = new DOMDocument();

      $element = $this->addHeaders($dataset_name, $study_name);

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
          $variable_wrapper = entity_metadata_wrapper('node', $variable);
          $found = FALSE;
          foreach ($variable_wrapper->field_variable_study_var_att->value() as $sva) {
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
    $date->appendChild($this->doc->createTextNode(date('Y-m-j\TH:i:s.000Z')));

    $element = $variables->appendChild($this->doc->createElement('variables'));
    $element->setAttribute('class', 'linked-hash-set');
    return $element;
  }

  private function render_variable($variable, &$element, $sva = NULL) {
    $wrapper = entity_metadata_wrapper('node', $variable);

//    watchdog('mica', 'variable: %nid - %name, sva: %sva_nid',
//      array(
//        '%nid' => $variable->nid,
//        '%name' => $wrapper->title->value(),
//        '%sva_nid' => empty($sva) ? NULL : $sva->nid,
//      ),
//      WATCHDOG_DEBUG);

    $v = $element->appendChild($this->doc->createElement('variable'));
    $v->setAttribute('name', $wrapper->title->value());
    $v->setAttribute('valueType', drupal_strtolower($wrapper->field_value_type->value()));
    $v->setAttribute('entityType', 'Participant');

    // repeatable
    if ($wrapper->field_repeatable->value() == '1') {
      $v->setAttribute('repeatable', 'true');
      $v->setAttribute('occurenceGroup', $wrapper->title->value());
    }
    $attributes = $v->appendChild($this->doc->createElement('attributes'));
    $this->addAttribute($attributes, 'label', 'text', 'en', $wrapper->field_label->value());

    $body = $wrapper->body->value();
    if (!empty($body)) {
      $this->addAttribute($attributes, 'description', 'text', 'en', $wrapper->body->value->value(array('decode' => TRUE)), self::MAELSTROM_NS);
    }

    $this->addTaxonomyAttribute($attributes, 'anthropometric_structures', 'text', 'en', $variable->field_anthropometric_structures);
    $this->addTaxonomyAttribute($attributes, 'body_functions', 'text', 'en', $variable->field_body_functions);
    $this->addTaxonomyAttribute($attributes, 'body_structures', 'text', 'en', $variable->field_body_structures);
    $this->addTaxonomyAttribute($attributes, 'data_source', 'text', 'en', $variable->field_data_source);
    $this->addTaxonomyAttribute($attributes, 'disease_history', 'text', 'en', $variable->field_disease_history);
    $this->addTaxonomyAttribute($attributes, 'early_life', 'text', 'en', $variable->field_early_life);
    $this->addTaxonomyAttribute($attributes, 'essence', 'text', 'en', $variable->field_essence);
    $this->addTaxonomyAttribute($attributes, 'life_habits_behaviours', 'text', 'en', $variable->field_life_habits_behaviours);
    $this->addTaxonomyAttribute($attributes, 'measure', 'text', 'en', $variable->field_measure);
    $this->addTaxonomyAttribute($attributes, 'medical_health_intervention', 'text', 'en', $variable->field_medical_health_interv);
    $this->addTaxonomyAttribute($attributes, 'medication', 'text', 'en', $variable->field_medication);
    $this->addTaxonomyAttribute($attributes, 'perception_of_health', 'text', 'en', $variable->field_perception_of_health);
    $this->addTaxonomyAttribute($attributes, 'period', 'text', 'en', $variable->field_period);
    $this->addTaxonomyAttribute($attributes, 'physical_environment', 'text', 'en', $variable->field_physical_environment);
    $this->addTaxonomyAttribute($attributes, 'reproductive_history', 'text', 'en', $variable->field_reproductive_history);
    $this->addTaxonomyAttribute($attributes, 'social_environment', 'text', 'en', $variable->field_social_environment);
    $this->addTaxonomyAttribute($attributes, 'sociodemographic_characteristics', 'text', 'en', $variable->field_sociodemographic_charact);
    $this->addTaxonomyAttribute($attributes, 'target', 'text', 'en', $variable->field_target);

    if (!empty($sva)) {
      $sva_wrapper = entity_metadata_wrapper('node', $sva);
      $this->addAttribute($attributes, 'script', 'text', 'en', $sva_wrapper->field_sva_script->value());
      $this->addAttribute($attributes, 'status', 'text', NULL, $sva_wrapper->field_sva_status->value(), self::MAELSTROM_NS);
      $this->addAttribute($attributes, 'comment', 'text', NULL, $sva_wrapper->field_sva_comment->value(), self::MAELSTROM_NS);
    }

    $nbCategories = count($wrapper->field_variable_categories->value());
    if ($nbCategories > 0) {
      $categories = $v->appendChild($this->doc->createElement('categories'));
      for ($i = 0; $i < $nbCategories; $i++) {
        $c = $categories->appendChild($this->doc->createElement('category'));
        $c->setAttribute('name', $wrapper->field_variable_categories[$i]->name->value());
        if ($wrapper->field_variable_categories[$i]->missing->value() == '1') {
          $c->setAttribute('missing', 'true');
        }
        $c_attributes = $c->appendChild($this->doc->createElement('attributes'));
        $this->addAttributeValue($c_attributes, 'label', 'text', 'en', $wrapper->field_variable_categories[$i]->label->value());
      }
    }
  }

  private function addAttribute($attributes, $name, $valueType, $lang, $value, $namespace = NULL) {
    if (is_null($value)) {
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
    $attribute->appendChild($this->doc->createTextNode($value));
  }

  private function addTaxonomyAttribute($attributes, $name, $valueType, $lang, $field) {
    if (!empty($field['und'][0]['tid'])) {

      $term = taxonomy_term_load($field['und'][0]['tid']);
//      watchdog('mica', $name . ' - tid: %tid, term: %term',
//        array('%tid' => $field['und'][0]['tid'], '%term' => $term ? $term->name : NULL));

      if (!empty($term)) {
        $attribute = $attributes->appendChild($this->doc->createElement('attribute'));
        $attribute->setAttribute('name', $name);
        $attribute->setAttribute('valueType', $valueType);
        $attribute->setAttribute('locale', $lang); // set to $lang to support multiple languages
        $attribute->setAttribute('namespace', self::MAELSTROM_NS);
        $attribute->appendChild($this->doc->createTextNode($term->name));
      }
    }
  }

  private function addAttributeValue($attributes, $name, $valueType, $lang, $value) {
    if (is_null($value)) {
      return;
    }
    $attribute = $attributes->appendChild($this->doc->createElement('attribute'));
    $attribute->setAttribute('name', $name);
    $attribute->setAttribute('valueType', $valueType);
    $attribute->setAttribute('locale', $lang); // set to $lang to support multiple languages
    $attribute->appendChild($this->doc->createTextNode($value));
  }

}
