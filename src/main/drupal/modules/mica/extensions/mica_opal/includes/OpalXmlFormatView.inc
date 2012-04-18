<?php

class OpalXmlFormatView extends RESTServerView {
  const MICA_NS = 'MICA:';
  const MAELSTROM_NS = 'MAER:';
  
  function render() {
    $doc = new DomDocument('1.0', 'utf-8');

    $icalendar = $doc->appendChild($doc->createElement('iCalendar'));
    $icalendar->setAttribute('xmlns', 'http://www.ietf.org/rfc/rfc2445');

    $vc = $icalendar->appendChild($doc->createElement('vcalendar'));
    $this->value($doc, $vc, 'version', '2.0');
    $this->value($doc, $vc, 'prodid', 'Drupal');
    
    /*foreach ($this->model as $item) {
      debug($item);
      $vevent = $vc->appendChild($doc->createElement('variable'));
      $this->value($doc, $vevent, 'label', $item->getName());
      $this->value($doc, $vevent, 'body', $item->getBody());
    }*/

    $doc->formatOutput = TRUE;
    return $doc->saveXml();
  }

  private function value($doc, $p, $name, $value) {
    $elem = $p->appendChild($doc->createElement($name));
    $elem->appendChild($doc->createTextNode($value));
  }
}
