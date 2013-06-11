<?php
$breadcrumb[] = l(t('Home'), '');
$breadcrumb[] = l(t('Community'), 'community');
$breadcrumb[] = l(t('Forums'), 'forum');
drupal_set_breadcrumb($breadcrumb);
?>
<table id="forum-topic-<?php print $topic_id; ?>">
  <thead>
  <tr><?php print $header; ?></tr>
  </thead>
  <tbody>
  <?php foreach ($topics as $topic): ?>
    <tr class="<?php print $topic->zebra; ?>">
      <td class="icon"><?php print $topic->icon; ?></td>
      <td class="title">
        <div>
          <?php print $topic->title; ?>
        </div>
        <div>
          <?php print $topic->created; ?>
        </div>
      </td>
      <?php if ($topic->moved): ?>
        <td colspan="3"><?php print $topic->message; ?></td>
      <?php else: ?>
        <td class="replies">
          <?php print $topic->comment_count; ?>
          <?php if ($topic->new_replies): ?>
            <br/>
            <a href="<?php print $topic->new_url; ?>"><?php print $topic->new_text; ?></a>
          <?php endif; ?>
        </td>
        <td class="last-reply"><?php print $topic->last_reply; ?></td>
      <?php endif; ?>
    </tr>
  <?php endforeach; ?>
  </tbody>
</table>
<?php print $pager; ?>

