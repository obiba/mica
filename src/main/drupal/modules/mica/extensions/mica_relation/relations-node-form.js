(function ($) {

  Drupal.behaviors.micaFieldsetSummaries = {
    attach: function (context) {

      var showHideRelationDetails = function () {
        var hasParent = $(".form-item-parent-bundle select option:selected", context).val() != '';
        var isIndexed = $("form#node-type-form input#edit-indexed").attr('checked');
        $('.form-item-cascaded').toggle(hasParent);
        $('.form-item-indexed').toggle(hasParent);
        $('.form-item-child-indexes').toggle(hasParent && isIndexed);
      };

      showHideRelationDetails();

      // Provide the summary for the node type form.
      $('fieldset.relation-node-type-settings-form', context).drupalSetSummary(function (context) {
        showHideRelationDetails();
        var vals = [];
        var parentBundle = $(".form-item-parent-bundle select option:selected", context);
        if (parentBundle.val()) {
          vals.push(Drupal.checkPlain(parentBundle.text()));

          var cascaded = $("form#node-type-form input#edit-cascaded");
          if (cascaded.attr('checked')) {
            vals.push(Drupal.checkPlain(cascaded.siblings("label").text()));
          }

          var indexed = $("form#node-type-form input#edit-indexed");
          if (indexed.attr('checked')) {
            vals.push(Drupal.checkPlain(indexed.siblings("label").text()));
          }
        }
        return Drupal.checkPlain(vals.join(', '));
      });

      $("form#node-type-form input#edit-indexed").change(function () {
        showHideRelationDetails();
      });

      $("form#node-type-form select#edit-parent-bundle").change(function () {
        $("form#node-type-form input#edit-cascaded").attr('checked', false);
        $("form#node-type-form input#edit-indexed").attr('checked', false);
        showHideRelationDetails();
      });

    }
  };

})(jQuery);
