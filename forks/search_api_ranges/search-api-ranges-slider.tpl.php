<?php
/**
 * @file custom Search API Page search form
 * @see mt_core.module's implementation of hook_theme()
 *
 * Variables contained in $form. What we need is:
 *
 * $form['form']['keys_1']    The textfield containing the search query
 * $form['form']['submit_1']  Submit button
 */
?>

<table class="range-box">
	<tr>
		<td class="range-box range-box-left"><?php print drupal_render($form['range-from']); ?></td>
		<td class="range-box range-box-right"><?php print drupal_render($form['range-to']); ?></td>
	</tr>
	
	<?php if (!$form['range-is-date']) { ?>
		
		<tr>
			<td colspan="2" class="range-slider-box"><?php print drupal_render($form['range-slider']); ?></td>
		</tr>
	
	<?php } ?>
	
	<tr>
		<td colspan="2"><?php print drupal_render($form['submit']); ?></td>
	</tr>
</table>

<?php print drupal_render_children($form); ?>
