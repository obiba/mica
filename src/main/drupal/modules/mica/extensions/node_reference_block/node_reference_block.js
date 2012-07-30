(function ($) {

  Drupal.behaviors.fieldDescriptionSettings = {
    attach: function (context) {

      // The drupalSetSummary method required for this behavior is not available
      // on the Blocks administration page, so we need to make sure this
      // behavior is processed only if drupalSetSummary is defined.
      if (typeof jQuery.fn.drupalSetSummary == 'undefined') {
        return;
      }

      $('fieldset#edit-exclude-related-type', context).drupalSetSummary(function (context) {
        var vals = [];
        $('input[type="checkbox"]:checked', context).each(function () {
          vals.push($.trim($(this).next('label').text()));
        });
        if (!vals.length) {
          vals.push(Drupal.t('No exclusions'));
        }
        return vals.join(', ');
      });

    }
  };

})(jQuery);
