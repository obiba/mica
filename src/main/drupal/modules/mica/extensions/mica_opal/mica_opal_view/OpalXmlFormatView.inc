<?php


class OpalXmlFormatView extends RESTServerView {
  
  const MICA_NS = 'mica';
  const MAELSTROM_NS = 'maelstrom';
  
  function render() {
    $doc = new DOMDocument();

    $opal = $doc->appendChild($doc->createElement('org.obiba.magma.views.View'));
    $select = $opal->appendChild($doc->createElement('select'));
    $select->setAttribute('class', 'org.obiba.magma.views.support.NoneClause');
    
    $where = $opal->appendChild($doc->createElement('where'));
    $where->setAttribute('class', 'org.obiba.magma.views.support.AllClause');
    
    $variables = $opal->appendChild($doc->createElement('variables'));
    $variables->setAttribute('class', 'org.obiba.magma.js.views.VariablesClause');
       
    $linked = $variables->appendChild($doc->createElement('variables'));
    $linked->setAttribute('class', 'linked-hash-set');

    $date = $opal->appendChild($doc->createElement('created'));
    $date->setAttribute('valueType', 'dateTime');
    $date->appendChild($doc->createTextNode(date('Y-m-j\TH:i:s.000Z')));
    
    $dataset = check_plain($this->model->title); 
    $nids = array();
    $lang = $this->model->language;
    if (isset($this->model->field_dataset_variables[$lang])){
      foreach ($this->model->field_dataset_variables[$lang] as $item) {
      	$nids[] = $item['nid'];
      }
      $vars = entity_load('node', $nids);
      uasort($vars, array($this, 'sort_by_position'));
      
      foreach($vars as $node){
        $v = $linked->appendChild($doc->createElement('variable'));
        $v->setAttribute('name', $node->title);
        $v->setAttribute('valueType', strtolower($node->field_value_type[$lang][0]['value']));
        $v->setAttribute('entityType', 'Participant');
        
        // repeatable
        if ($node->field_repeatable[$lang][0]['value'] === '1'){
          $v->setAttribute('repeatable', 'true');
          $v->setAttribute('occurenceGroup', $node->title);
        }
        $attributes = $v->appendChild($doc->createElement('attributes'));
        $this->addAttribute($doc, $attributes, 'label', 'text', 'en', $node->field_label);
        $this->addAttribute($doc, $attributes, 'body', 'text', 'en', $node->body);
				$this->addStatusAttribute($doc, $attributes, 'en');
				
        $this->addTaxonomyAttribute($doc, $attributes, 'anthropometric_structures', 'text', 'en', $node->field_anthropometric_structures);
        $this->addTaxonomyAttribute($doc, $attributes, 'body_functions', 'text', 'en', $node->field_body_functions);
        $this->addTaxonomyAttribute($doc, $attributes, 'body_structures', 'text', 'en', $node->field_body_structures);
        $this->addTaxonomyAttribute($doc, $attributes, 'data_source', 'text', 'en', $node->field_data_source);
        $this->addTaxonomyAttribute($doc, $attributes, 'disease_history', 'text', 'en', $node->field_disease_history);
        $this->addTaxonomyAttribute($doc, $attributes, 'early_life', 'text', 'en', $node->field_early_life);
        $this->addTaxonomyAttribute($doc, $attributes, 'essence', 'text', 'en', $node->field_essence);
        $this->addTaxonomyAttribute($doc, $attributes, 'life_habits_behaviours', 'text', 'en', $node->field_life_habits_behaviours);
        $this->addTaxonomyAttribute($doc, $attributes, 'measure', 'text', 'en', $node->field_measure);
        $this->addTaxonomyAttribute($doc, $attributes, 'medical_health_intervention', 'text', 'en', $node->field_medical_health_interv);
        $this->addTaxonomyAttribute($doc, $attributes, 'medication', 'text', 'en', $node->field_medication);
        $this->addTaxonomyAttribute($doc, $attributes, 'perception_of_health', 'text', 'en', $node->field_perception_of_health);
        $this->addTaxonomyAttribute($doc, $attributes, 'period', 'text', 'en', $node->field_period);
        $this->addTaxonomyAttribute($doc, $attributes, 'physical_environment', 'text', 'en', $node->field_physical_environment);
        $this->addTaxonomyAttribute($doc, $attributes, 'reproductive_history', 'text', 'en', $node->field_reproductive_history);
        $this->addTaxonomyAttribute($doc, $attributes, 'social_environment', 'text', 'en', $node->field_social_environment);
        $this->addTaxonomyAttribute($doc, $attributes, 'sociodemographic_characteristics', 'text', 'en', $node->field_sociodemographic_charact);
        $this->addTaxonomyAttribute($doc, $attributes, 'target', 'text', 'en', $node->field_target);
        
        if (!empty($node->field_variable_categories[$lang])){
          $categories = $v->appendChild($doc->createElement('categories'));
          
          foreach($node->field_variable_categories[$lang] as $node_cat){
            $c = $categories->appendChild($doc->createElement('category'));
            $c->setAttribute('name', $node_cat['name']);
            
            if ($node_cat['missing'] === '1'){
              $c->setAttribute('missing', 'true');
            }
            $c_attributes = $c->appendChild($doc->createElement('attributes'));
            $this->addAttributeValue($doc, $c_attributes, 'label', 'text', 'en', $node_cat['label']);
          }
        }
      }
    }
    drupal_add_http_header('Content-Disposition', "attachment; filename=$dataset.xml" );
    $doc->formatOutput = TRUE;
    return $doc->saveXml();
  }

	private function addStatusAttribute($doc, $attributes, $lang){
    $attribute = $attributes->appendChild($doc->createElement('attribute'));
    $attribute->setAttribute('name', 'status');
    $attribute->setAttribute('valueType', 'text');
    $attribute->setAttribute('locale', $lang);
    $attribute->setAttribute('namespace', self::MICA_NS);
  }
	
  private function addAttribute($doc, $attributes, $name, $valueType, $lang, $field, $namespace = NULL){
    if (!empty($field['und'][0]['value'])){
      $attribute = $attributes->appendChild($doc->createElement('attribute'));
      $attribute->setAttribute('name', $name);
      $attribute->setAttribute('valueType', $valueType);
      $attribute->setAttribute('locale', $lang); // set to $lang to support multiple languages
      $attribute->appendChild($doc->createTextNode($field['und'][0]['value'])); //$doc->createTextNode()
    }
  }
  
  private function addTaxonomyAttribute($doc, $attributes, $name, $valueType, $lang, $field){
  	if (!empty($field['und'][0]['tid'])){
  		$attribute = $attributes->appendChild($doc->createElement('attribute'));
  		$attribute->setAttribute('name', $name);
  		$attribute->setAttribute('valueType', $valueType);
  		$attribute->setAttribute('locale', $lang); // set to $lang to support multiple languages
  		$attribute->setAttribute('namespace', self::MAELSTROM_NS);
  		
  		$term = taxonomy_term_load($field['und'][0]['tid']);
  		$attribute->appendChild($doc->createTextNode($term->name)); 
  	}
  }
  
  private function addAttributeValue($doc, $attributes, $name, $valueType, $lang, $value){
  	if (!empty($value) || $value === '0'){
  		$attribute = $attributes->appendChild($doc->createElement('attribute'));
  		$attribute->setAttribute('name', $name);
  		$attribute->setAttribute('valueType', $valueType);
  		$attribute->setAttribute('locale', $lang); // set to $lang to support multiple languages
  		$attribute->appendChild($doc->createTextNode($value)); //$doc->createTextNode()
  	}
  }
  
  function sort_by_position($x, $y){
    if ( $x->field_position['und'][0]['value'] === $y->field_position['und'][0]['value'] ) 
      return 0; 
    else if ( $x->field_position['und'][0]['value'] < $y->field_position['und'][0]['value'] ) 
      return -1; 
    else 
      return 1; 
  } 
}
