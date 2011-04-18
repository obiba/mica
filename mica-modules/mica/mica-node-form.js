(function ($) {

Drupal.behaviors.micaFieldsetSummaries = {
  attach: function (context) {
/*	  
    $('fieldset.relation-node-type-settings-form', context).drupalSetSummary(function (context) {
      return Drupal.checkPlain($('.form-item-mica_relation input:checked', context).next('label').text());
    });
*/
    // Provide the summary for the node type form.
    $('fieldset.relation-node-type-settings-form', context).drupalSetSummary(function(context) {
      var parentType = $(".form-item-parent-type select option:selected", context);
      if(parentType.val()) {
    	  return Drupal.checkPlain(parentType.text());
      }
      return Drupal.checkPlain('');
    });
  }
};

})(jQuery);
