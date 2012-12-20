// Using the closure to map jQuery to $.
(function ($) {

  Drupal.behaviors.mica_bootstrap_views_export = {
    attach: function (context, settings) {
      $('.feed-icon a img').each(function (index) {
        var format = $(this).attr('title');
        var anchor = $(this).parent();
        anchor.before('<i class="icon-download-alt"></i> ');
        anchor.html(settings.downloadLabel + ' ' + format);
        anchor.attr('class', 'download-link');
      });
    }
  };

}(jQuery));