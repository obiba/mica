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
      $this->doc = new DOMDocument();

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

      $dataset = check_plain($this->model->title);
      $lang = $this->model->language;
      if (isset($this->model->field_dataset_variables[$lang])) {
        $nids = array();
        foreach ($this->model->field_dataset_variables[$lang] as $item) {
          $nids[] = $item['nid'];
        }
        $vars = entity_load('node', $nids);

        // TODO use mica_datasets.utils.inc --> mica_datasets_sort_by_position
        uasort($vars, array($this, 'sort_by_position'));
        foreach ($vars as $node) {
          $this->render_node($node, $element);
        }
      }
      drupal_add_http_header('Content-Disposition', "attachment; filename=$dataset.xml");
      $this->doc->formatOutput = TRUE;
      return $this->doc->saveXml();
    }
    catch (Exception $e) {
      watchdog_exception('mica', $e);
      throw $e;
    }
    return NULL;
  }

  function render_node($node, &$element) {
    $wrapper = entity_metadata_wrapper('node', $node);

//    watchdog('mica', 'node: %nid - %name', array('%nid' => $node->nid, '%name' => $wrapper->title->value()), WATCHDOG_DEBUG);

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

    // do not export status & comment because Opal will overwrite these values on import as it does not support merge yet,

    $this->addTaxonomyAttribute($attributes, 'anthropometric_structures', 'text', 'en', $node->field_anthropometric_structures);
    $this->addTaxonomyAttribute($attributes, 'body_functions', 'text', 'en', $node->field_body_functions);
    $this->addTaxonomyAttribute($attributes, 'body_structures', 'text', 'en', $node->field_body_structures);
    $this->addTaxonomyAttribute($attributes, 'data_source', 'text', 'en', $node->field_data_source);
    $this->addTaxonomyAttribute($attributes, 'disease_history', 'text', 'en', $node->field_disease_history);
    $this->addTaxonomyAttribute($attributes, 'early_life', 'text', 'en', $node->field_early_life);
    $this->addTaxonomyAttribute($attributes, 'essence', 'text', 'en', $node->field_essence);
    $this->addTaxonomyAttribute($attributes, 'life_habits_behaviours', 'text', 'en', $node->field_life_habits_behaviours);
    $this->addTaxonomyAttribute($attributes, 'measure', 'text', 'en', $node->field_measure);
    $this->addTaxonomyAttribute($attributes, 'medical_health_intervention', 'text', 'en', $node->field_medical_health_interv);
    $this->addTaxonomyAttribute($attributes, 'medication', 'text', 'en', $node->field_medication);
    $this->addTaxonomyAttribute($attributes, 'perception_of_health', 'text', 'en', $node->field_perception_of_health);
    $this->addTaxonomyAttribute($attributes, 'period', 'text', 'en', $node->field_period);
    $this->addTaxonomyAttribute($attributes, 'physical_environment', 'text', 'en', $node->field_physical_environment);
    $this->addTaxonomyAttribute($attributes, 'reproductive_history', 'text', 'en', $node->field_reproductive_history);
    $this->addTaxonomyAttribute($attributes, 'social_environment', 'text', 'en', $node->field_social_environment);
    $this->addTaxonomyAttribute($attributes, 'sociodemographic_characteristics', 'text', 'en', $node->field_sociodemographic_charact);
    $this->addTaxonomyAttribute($attributes, 'target', 'text', 'en', $node->field_target);

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
    if (is_null($value)) return;
    $attribute = $attributes->appendChild($this->doc->createElement('attribute'));
    $attribute->setAttribute('name', $name);
    $attribute->setAttribute('valueType', $valueType);
    if (!empty($lang)) $attribute->setAttribute('locale', $lang); // set to $lang to support multiple languages
    if (!empty($namespace)) $attribute->setAttribute('namespace', $namespace);
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
    if (is_null($value)) return;
    $attribute = $attributes->appendChild($this->doc->createElement('attribute'));
    $attribute->setAttribute('name', $name);
    $attribute->setAttribute('valueType', $valueType);
    $attribute->setAttribute('locale', $lang); // set to $lang to support multiple languages
    $attribute->appendChild($this->doc->createTextNode($value));
  }

  function sort_by_position($x, $y) {
    $x_pos = entity_metadata_wrapper('node', $x)->field_position->value();
    $y_pos = entity_metadata_wrapper('node', $y)->field_position->value();
    if ($x_pos === $y_pos) return 0;
    return $x_pos < $y_pos ? -1 : 1;
  }
}
