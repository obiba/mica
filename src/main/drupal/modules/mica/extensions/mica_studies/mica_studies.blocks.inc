<?php



function _mica_studies_block_study_general_info($study)
{
    // $study can be the study nid
    if (is_numeric($study)) {
        $study = node_load($study);
    }
    $weight = 0;
    $content = array(
        field_view_field('node', $study, 'field_acroym', array('label' => 'inline', 'weight' => ++$weight)),
        field_view_field('node', $study, 'field_website', array('label' => 'inline', 'weight' => ++$weight)),
        field_view_field('node', $study, 'field_investigators', array('label' => 'inline', 'weight' => ++$weight)),
        field_view_field('node', $study, 'field_contacts_ref', array('label' => 'inline', 'weight' => ++$weight)),
        field_view_field('node', $study, 'field_study_start_year', array(
                'label' => 'inline',
                'weight' => ++$weight,
                'settings' => array('thousand_separator' => '')
            )
        ),
        field_view_field('node', $study, 'field_study_end_year', array(
                'label' => 'inline',
                'weight' => ++$weight,
                'settings' => array('thousand_separator' => '')
            )
        ),
        field_view_field('node', $study, 'field_networks', array('label' => 'inline', 'weight' => ++$weight)),
    );
    return array(
        'subject' => t('General Information') . '<a name="general-info"> </a>',
        'content' => array_filter($content),
    );
}

function _mica_studies_block_study_access($study)
{
    // $study can be the study nid
    if (is_numeric($study)) {
        $study = node_load($study);
    }
    $weight = 0;
    $content = array(
        field_view_field('node', $study, 'field_access_data', array(
            'label' => 'inline',
            'weight' => ++$weight,
            'type' => module_exists('i18n') ? 'i18n_list_default' : 'list_default',
        )),
        field_view_field('node', $study, 'field_access_biosamples', array(
            'label' => 'inline',
            'weight' => ++$weight,
            'type' => module_exists('i18n') ? 'i18n_list_default' : 'list_default',
        )),
    );
    $other = _mica_studies_simulate_other_specify_field($study, 'field_access_other', 'field_access_other_sp', ++$weight);
    if (!empty($other)) {
        $content[] = $other;
    }
    $content = array_filter($content);
    if (empty($content)) {
        return NULL;
    }
    return array(
        'subject' => t('Access') . '<a name="access"> </a>',
        'content' => t('Access to external researchers or third parties provided or foreseen for') . drupal_render($content),
    );
}

function _mica_studies_block_study_marker_paper($study)
{
    // $study can be the study nid
    if (is_numeric($study)) {
        $study = node_load($study);
    }

    $weight = 0;
    $content = array(
        field_view_field('node', $study, 'field_marker_paper', array('label' => 'inline', 'weight' => ++$weight)),
        field_view_field('node', $study, 'field_pubmedid', array(
                'label' => 'inline',
                'type' => 'mica_pubmed_url',
                'weight' => ++$weight
            )
        ),
    );
    return array(
        'subject' => t('Marker Paper') . '<a name="marker-paper"> </a>',
        'content' => array_filter($content),
    );
}

function _mica_studies_block_study_documents($study)
{
    // $study can be the study nid
    if (is_numeric($study)) {
        $study = node_load($study);
    }

    $content = array(field_view_field('node', $study, 'field_documents', array('label' => 'hidden')));
    return array(
        'subject' => t('Documents') . '<a name="documents"> </a>',
        'content' => array_filter($content),
    );
}

function _mica_studies_block_study_supp_infos($study)
{
    // $study can be the study nid
    if (is_numeric($study)) {
        $study = node_load($study);
    }
    $content = array(field_view_field('node', $study, 'field_supp_infos', array('label' => 'hidden','type' => module_exists('i18n') ? 'i18n_text' : 'text')));
    return array(
        'subject' => t('Supplementary Information') . '<a name="supplementary-info"> </a>',
        'content' => array_filter($content),
    );
}

function _mica_studies_simulate_other_specify_field($node, $field_other, $field_specify, $weight)
{
    $wrapper = entity_metadata_wrapper('node', $node->nid);
    $other = $wrapper->{$field_other}->value();
    if (empty($other)) {
        return NULL;
    }

    $field = field_view_field('node', $node, $field_other, array(
        'label' => 'inline',
        'weight' => $weight,
        'type' => module_exists('i18n') ? 'i18n_list_default' : 'list_default',
    ));
    $other_sp = $wrapper->{$field_specify}->value();
    if (!empty($other_sp)) {
        $field_specify_view = field_view_field('node', $node, $field_specify);
        $field[0]['#markup'] .= ' - ' . $field_specify_view[0]['#markup'];
    }
    return $field;
}

function _mica_studies_block_study_datasets($study)
{
    $wrapper = entity_metadata_wrapper('node', $study);
    $rows = array();
    foreach ($wrapper->mica_dataset->getIterator() as $dataset_wrapper) {
        if (node_access('view', $dataset_wrapper->value())) {
            $desc = NULL;
            if (!empty($dataset_wrapper->value()->body)) {
                $desc = $dataset_wrapper->body->summary->value();
                if (empty($desc)) {
                    $desc = truncate_utf8($dataset_wrapper->body->value->value(), 50, TRUE, TRUE);
                }
            }

            // Adding an extra column that will be used to sort and then be removed
            $rows[] = array(
                l($dataset_wrapper->title->value(), 'node/' . $dataset_wrapper->nid->value()), //
                $desc, //
                $dataset_wrapper->title->value()
            );
        }
    }

    if (empty($rows)) {
        return NULL;
    }

    // Sort by last column and remove this column
    uasort($rows, '_mica_studies_sort_dce_by_title');
    foreach ($rows as $i => $row) {
        unset($rows[$i][2]);
    }

    return array(
        'subject' => t('Datasets') . '<a name="datasets"> </a>',
        'content' => array(
            '#theme' => 'table',
            '#attributes' => array('class' => array('study-datasets')),
            '#header' => array(t('Name'), t('Description')),
            '#rows' => $rows,
        )
    );
}

function _mica_studies_block_study_populations($study, $show_draft)
{
    $content = array();
    global $language;

    // Load the populations that are attached to PUBLISHED version of study
    if ($show_draft) {
        $study = node_load($study->nid);
    }

    foreach (_mica_studies_sort_populations($study) as $index_pop => $population_nid) {


        $pop = node_load($population_nid);
        if (node_access('view', $pop)) {

            if ($show_draft) {
                $latest = key(node_revision_list($pop));
                $pop = node_load($population_nid, $latest);

                if (!isset($pop->workbench_moderation['published']) || $pop->vid !== $pop->workbench_moderation['published']->vid) {
                    $content[$index_pop]['body']['#markup'] = "<div class='node-unpublished'>";
                    $content[$index_pop] = node_view($pop, 'full', $language->language);
                    $content[$index_pop]['body']['#markup'] = "</div>";
                } else {
                    $content[$index_pop] = node_view($pop, 'full');
                }
            } else if ($show_draft || (isset($pop->workbench_moderation['published']) && $pop->vid == $pop->workbench_moderation['published']->vid)) {
                $content[$index_pop] = node_view($pop, 'full');
            }
        }
    }
    return array(
        'subject' => t('Populations') . '<a name="populations"> </a>',
        'content' => array_filter($content),
    );
}

function _mica_studies_sort_dce_by_title($x, $y)
{
    if (isset($x['data'])) {
        return strcasecmp($x['data'][2], $y['data'][2]);
    } else {
        return strcasecmp($x[2], $y[2]);
    }
}