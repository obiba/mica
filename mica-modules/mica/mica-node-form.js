(function ($) {

Drupal.behaviors.micaFieldsetSummaries = {
  attach: function (context) {
    $('fieldset.relation-node-type-settings-form', context).drupalSetSummary(function (context) {
      return Drupal.checkPlain($('.form-item-mica_relation input:checked', context).next('label').text());
    });

    // Provide the summary for the node type form.
    $('fieldset.relation-node-type-settings-form', context).drupalSetSummary(function(context) {
      var vals = [];

      
      var parentType = $(".form-item-parent-type select option:selected", context);
      if(parentType.val()) {
    	  vals.push(parentType.text());
    	  $(".form-item-node-reference-name", context).show();
//    	  if(!$(".form-item-node-reference-name input", context).val()) {
//    		  $(".form-item-node-reference-name input", context).val($(".machine-name-value", context).text() + '_ref');
//    	  }
      } else {
    	  $(".form-item-node-reference-name", context).hide();
    	  $(".form-item-node-reference-name input", context).val('');
      }

      return Drupal.checkPlain(vals.join(', '));
    });
  }
};

})(jQuery);
