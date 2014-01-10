<h1><?php print $variable_detail['title']; ?></h1>
<?php //dpm($variable_detail); ?>
<div class="contextual-links-region">
<div class="panel-2col-stacked clearfix panel-display">

<?php /**************Main  Description variable ****/ ?>
<div class="panel-col-top panel-panel">
  <div class="inside">
    <div class="contextual-links-region panel-pane pane-node-content">
      <div class="pane-content">
        <article class="node node-variable clearfix">
          <header>
          </header>
          <div class="field field-name-body field-type-text-with-summary field-label-hidden">
            <div class="field-items">
              <div property="content:encoded" class="field-item even">
                <p><?php print (!empty($variable_detail['description'])) ? $variable_detail['description'] : NULL; ?></p>
              </div>
            </div>
          </div>
          <footer>
          </footer>

        </article>
        <!-- /.node -->
      </div>

    </div>
  </div>
</div>

<?php /**************END Main  Description variable ****/ ?>

<?php /**********Description Block *******************/ ?>
<div class="center-wrapper">
  <div class="panel-col-first panel-panel">
    <div class="inside">
      <div class="contextual-links-region panel-pane pane-node-content">
        <div class="pane-content">
          <article>
            <header>
            </header>
            <fieldset class=" form-wrapper" id="node_variable_left_area_group_description">
              <legend>
                <span class="fieldset-legend"><?php print t('Description'); ?></span>
              </legend>

              <div class="fieldset-wrapper">

                <div class="field field-name-field-dataset field-type-node-reference field-label-above">
                  <div class="field-label"><?php print t('Label'); ?> :</div>
                  <div class="field-items">
                    <div class="field-item even">
                      <?php print $variable_detail['label']; ?>
                    </div>
                  </div>
                </div>

                <div class="field field-name-field-dataset field-type-node-reference field-label-above">
                  <div class="field-label"><?php print t('Dataset'); ?> :</div>
                  <div class="field-items">
                    <div class="field-item even">
                      <a
                        href="/?q=<?php print $variable_detail['dataset-alias']; ?>"><?php print $variable_detail['dataset']; ?></a>
                    </div>
                  </div>
                </div>

                <?php if (!empty($variable_detail['unit'])) : ?>
                  <div class="field field-name-field-value-type field-type-list-text field-label-above">
                    <div class="field-label"><?php print t('Unit'); ?> :</div>
                    <div class="field-items">
                      <div class="field-item even"><?php print $variable_detail['unit']; ?></div>
                    </div>
                  </div>
                <?php endif; ?>
                <div class="field field-name-field-value-type field-type-list-text field-label-above">
                  <div class="field-label"><?php print t('Value Type'); ?> :</div>
                  <div class="field-items">
                    <div class="field-item even"><?php print $variable_detail['value_type']; ?></div>
                  </div>
                </div>

                <div class="field field-name-field-repeatable field-type-list-boolean field-label-above">
                  <div class="field-label"><?php print t('Repeatable'); ?> :</div>
                  <div class="field-items">
                    <div class="field-item even"><?php print $variable_detail['repeatable']; ?></div>
                  </div>
                </div>
              </div>
            </fieldset>
            <footer>
            </footer>
          </article>
          <!-- /.node -->
        </div>
      </div>
    </div>
  </div>

  <?php /**********End  Description Block *******************/ ?>


  <?php /**********Domains Block *******************/ ?>

  <div class="panel-col-last panel-panel">
    <div class="inside">
      <div class="contextual-links-region panel-pane pane-node-content">
        <div class="pane-content">
          <article>
            <header>
            </header>
            <fieldset class=" form-wrapper" id="node_variable_left_area_group_description">
              <legend>
                <span class="fieldset-legend"><?php print t('Domains'); ?></span>
              </legend>

              <div class="fieldset-wrapper">
                <?php if (!empty($variable_detail['attributes'])) : ?>
                  <?php foreach (getatribut() as $variable_name) : ?>

                    <?php foreach ($variable_detail['attributes'] as $variable_domaine) : ?>

                      <?php if ($variable_domaine['name'] == $variable_name) : ?>
                        <?php //dpm($variable_name); ?>
                        <div class="field field-name-field-dataset field-type-node-reference field-label-above">
                      <div class="field-label"><?php print t($variable_domaine['name']); ?> :</div>
                      <div class="field-items">
                        <div class="field-item even">
                          <?php print t($variable_domaine['value']); ?>
                        </div>
                      </div>
                    </div>
                        <?php break; ?>
                      <?php endif; ?>
                    <?php endforeach; ?>
                  <?php endforeach; ?>
                <?php else: ?>
                  <div class="field field-name-field-dataset field-type-node-reference field-label-above">
                    <div class="field-label"></div>
                    <div class="field-items">
                      <div class="field-item even">
                        <?php print t('No Domains attributes'); ?>
                      </div>
                    </div>
                  </div>
                <?php endif; ?>

            </fieldset>

            <footer>
            </footer>
          </article>
          <!-- /.node -->
        </div>
      </div>
    </div>
  </div>

  <?php /**********End Domains Block *******************/ ?>


  <?php /**********Categories Block *******************/ ?>

  <div class="panel-col-first panel-right panel-panel">
    <div class="inside">
      <div class="contextual-links-region panel-pane pane-node-content">
        <div class="pane-content">
          <article>
            <header>
            </header>
            <fieldset class="form-wrapper" id="node_variable_left_area_group_categories">
              <legend>
                <span class="fieldset-legend"><?php print t('Categories'); ?></span>
              </legend>
              <div class="fieldset-wrapper">
                <div class="field field-name-field-variable-categories field-type-category-field field-label-hidden">
                  <div class="field-items">
                    <div class="field-item even">
                      <?php print $variable_detail['categories']; ?>
                    </div>
                  </div>
                </div>
              </div>
            </fieldset>
            <footer>
            </footer>
          </article>
          <!-- /.node -->
        </div>

      </div>
    </div>
  </div>

  <?php /**********End Categories Block *******************/ ?>


  <?php /**********Statistics Block *******************/ ?>

  <div class="panel-col-last panel-panel">
    <div class="inside">
      <div class="contextual-links-region panel-pane pane-node-content">
        <div class="pane-content">
          <article>
            <header>
            </header>
            <fieldset class="form-wrapper">
              <legend>
                <span class="fieldset-legend"><?php print t('Statistics'); ?></span>
              </legend>
              <div class="fieldset-wrapper">
                <div id="param-statistics" dataset-id="<?php print  $variable_detail['dataset-id']; ?>"
                  study-id="<?php print  $variable_detail['study-id']; ?>"
                  var-name="<?php print  $variable_detail['title']; ?>">
                  <div id="txtblnk">         <?php print t('Please wait loading Statistics table....'); ?>       </div>
            </fieldset>
            <footer>
            </footer>
          </article>
          <!-- /.node -->
        </div>

      </div>
    </div>
  </div>
</div>
<?php /**********Categories Block *******************/ ?>
<?php /************Footer harmonization***********************/ ?>
<?php if (!empty($variable_detail['harmonization'])) : ?>
  <div class="panel-col-bottom panel-panel">
    <div class="inside">
      <div class="contextual-links-region panel-pane pane-node-content">
        <div class="pane-content">
          <article typeof="sioc:Item foaf:Document" class="node node-variable clearfix">
            <header>
            </header>

            <fieldset class="form-wrapper">
              <legend>
                <span class="fieldset-legend">Harmonization</span>
              </legend>
              <div class="fieldset-wrapper">
                <?php print $variable_detail['legend-harmonization']; ?>
                <?php print $variable_detail['harmonization']; ?>




                <!--    <p><a href="/node/5991/dataset-harmonization"><b>View Healthy Obese Project DataSchema Harmonization</b></a></p></div></fieldset> -->

                <footer>
                </footer>


          </article>
          <!-- /.node -->
        </div>


      </div>
    </div>
  </div>
<?php endif; ?>
<?php /*************End footer harmonization*******************************/ ?>
<?php //dpm($variable_detail);
function getatribut() {
  return array(
    'Data source',
    'Diseases history and related health problems',
    'Medical health interventions/health services utilization',
    'Medication',
    'Reproductive health and history',
    'Participant\'s early life/childhood',
    'Life habits/behaviours',
    'Sociodemographic/socioeconomic characteristics',
    'Physical environment',
    'Social environment',
    'Perception of health/quality of life',
    'Anthropometric structures',
    'Body structures',
    'Body functions',
    'Laboratory measures',
    'Administrative information',
    'Target',
  );
}

?>
</div>
</div>