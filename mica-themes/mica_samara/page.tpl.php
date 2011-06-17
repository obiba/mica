<?php
// $Id:
?>
<div id="skip-link">
    <a href="#main-content">Skip to main content</a>
</div>
    
<?php if ($navigation): ?>
  <div id="navigation-wrapper">
    <div id="navigation" class="clear-block">
      <?php print $navigation; ?>
    </div> <!-- /#navigation -->
  </div>
<?php endif; ?>

<?php global $user;
  if ($user->uid){
    print "<div id=\"login-status\">";
    print t("<a id='user-name' href='?q=user'>@name</a> | <a href='?q=user/logout'>Quit</a>", array('@name' => $user->name));
    print "</div>";
  }
?>

<div id="header-wrapper">
  <div id="header" class="clearfix<?php if ($page['header']): ?> with-blocks<?php endif; ?>">

    <?php if ($logo || $site_name || $site_slogan): ?>
      <div id="branding-wrapper" class="clear-block">
        <div id="branding">

          <?php if ($logo): ?>
            <div id="logo">
              <a href="<?php print $front_page; ?>" title="<?php print t('Home'); ?>" rel="home">
                <img src="<?php print $logo; ?>" alt="<?php print t('Home'); ?>" />
              </a>
            </div>
          <?php endif; ?>

          <?php if ($site_name || $site_slogan): ?>
            <div id="name-and-slogan">
              <?php if ($site_name): ?>
                <div id="site-name">
                  <a href="<?php print $front_page; ?>" title="<?php print t('Home'); ?>" rel="home"><?php print $site_name; ?></a>
                </div>
              <?php else: /* Use h1 when the content title is empty */ ?>
                <h1 id="site-name">
                  <a href="<?php print $front_page; ?>" title="<?php print t('Home'); ?>" rel="home"><?php print $site_name; ?></a>
                </h1>
              <?php endif; ?>

            <?php if ($site_slogan): ?>
              <div id="site-slogan"><?php print $site_slogan; ?></div>
            <?php endif; ?>
            </div> <!-- /name-and-slogan -->
          <?php endif; ?>

        </div> <!-- /#branding -->
      </div> <!-- /#branding-wrapper -->
    <?php endif; ?>

    <?php if ($page['header']): ?>
      <div class="region region-header">
        <?php print render($page['header']); ?>
      </div>
    <?php endif; ?>

  </div> <!-- /#header -->
</div> <!-- /#header-wrapper -->

<div id="main-columns-wrapper">
  <div id="main-columns">


    <?php print $left_sidebars ?>


    <div id="main-wrapper" class="<?php //print $content_class ?>">
      <div id="main">
        <div id="page" class="clearfix">
          <?php if ($breadcrumb): ?><div id="breadcrumb"><?php print $breadcrumb; ?></div><?php endif; ?>
          <?php print $messages; ?>

          <?php if ($page['content_top']): ?>
            <div class="region region-content-top">
              <?php print render($page['content_top']); ?>
            </div>
          <?php endif; ?>

          <?php if ($tabs): ?><div class="tabs"><?php print render($tabs); ?></div><?php endif; ?>

          <?php if ($page['highlight']): ?>
            <div class="region region-highlight">
              <?php print render($page['highlight']) ?>
            </div>
          <?php endif; ?>

          <a id="main-content"></a>
          <?php if (!empty($title)): ?>
            <h1 class="page-title"><?php print $title ?></h1>
          <?php endif; ?>

          <?php if (!empty($help)): print $help; endif; ?>
          
          <?php if ($action_links): ?>
            <ul class="action-links">
              <?php print render($action_links); ?>
            </ul>
          <?php endif; ?>

          <?php if ($page['content']): ?>
            <div class="region region-content">
              <?php print render($page['content']) ?>
            </div>
          <?php endif; ?>

          <?php if ($page['content_bottom']): ?>
            <div class="region region-content-bottom">
              <?php print render($page['content_bottom']); ?>
            </div>
          <?php endif; ?>
          <?php print $feed_icons; ?>
        </div> <!-- /#page -->


        <div id="closure">
          <div id="info">
            <?php print $copyright_information ?>
          </div>


        </div> <!-- /#closure -->

      </div> <!-- /#main -->
    </div> <!-- /#main-wrapper -->

    <?php print $right_sidebars ?> 
    
    <div class="region region-footer">
      <?php print render($page['footer']); ?>
    </div>

  </div> <!-- /#main-columns -->
</div> <!-- /#main-columns-wrapper -->
