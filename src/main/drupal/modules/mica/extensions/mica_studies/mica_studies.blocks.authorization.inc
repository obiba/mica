<?php

function _mica_studies_block_study_authorization($study) {
  // $study can be the study nid
  if (is_numeric($study)) {
    $study = node_load($study);
  }

  $wrapper = entity_metadata_wrapper('node', $study);
  $auth_specific = $wrapper->field_authorization_specific->value();
  $auth_maelstrom = $wrapper->field_authorization_maelstrom->value();

  if (empty($auth_specific) && empty($auth_maelstrom)) {
    return NULL;
  }

  $content = array();
  if ($auth_specific) {
    $site_name = variable_get('site_name', "[SPECIFIC NETWORK]");
    $person_name = $wrapper->field_authorising_person_name->value();
    $txt = empty($person_name)
      ? t("Contribution to @site authorised", array('@site' => $site_name))
      : t("@name authorised the contribution to @site", array('@name' => $person_name, '@site' => $site_name));
    $date = $wrapper->field_authorising_date->value();
    if (!empty($date)) {
      $date_view = field_view_field('node', $study, 'field_authorising_date');
      $txt .= ' ' . t('on') . ' ' . $date_view[0]['#markup'];
    }
    $content[] = array(
      '#type' => 'container',
      '#attributes' => array(
        'class' => array('field', 'field-name-field-authorization-specific', 'field-label-inline', 'clearfix'),
      ),
      'label' => array(
        '#type' => 'markup',
        '#markup' => '<div class="field-label">'
          . t("Authorization from contributors to the @site Catalogues:", array('@site' => $site_name)) . '&nbsp;</div>'
      ),
      'value' => array(
        '#type' => 'markup',
        '#markup' => '<div class="field-items"><div class="field-item even">' . $txt . '</div></div>',
      )
    );
  }
  if ($auth_maelstrom) {
    $person_name = $wrapper->field_authorising_person_name_m->value();
    $txt = empty($person_name)
      ? t("Contribution to Maelstrom Research authorised")
      : t("@name authorised the contribution to Maelstrom Research", array('@name' => $person_name));
    $date = $wrapper->field_authorising_date_m->value();
    if (!empty($date)) {
      $date_view = field_view_field('node', $study, 'field_authorising_date_m');
      $txt .= ' ' . t('on') . ' ' . $date_view[0]['#markup'];
    }
    $content[] = array(
      '#type' => 'container',
      '#attributes' => array(
        'class' => array('field', 'field-name-field-authorization-maelstrom', 'field-label-inline', 'clearfix'),
      ),
      'label' => array(
        '#type' => 'markup',
        '#markup' => '<div class="field-label">'
          . t("Authorization from contributors to the Maelstrom Catalogues:") . '&nbsp;</div>'
      ),
      'value' => array(
        '#type' => 'markup',
        '#markup' => '<div class="field-items"><div class="field-item even">' . $txt . '</div></div>',
      )
    );
  }
  return array(
    'subject' => t('Authorization') . '<a name="authorization"> </a>',
    'content' => $content,
  );
}