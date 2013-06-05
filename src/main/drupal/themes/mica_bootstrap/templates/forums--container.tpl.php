<?php
$breadcrumb[] = l(t('Home'), '');
$breadcrumb[] = l(t('Community'), 'community');
drupal_set_breadcrumb($breadcrumb);
?>

<?php if ($forums_defined): ?>
  <div id="forum">
    <?php print $forums; ?>
    <?php print $topics; ?>
  </div>
<?php endif; ?>


