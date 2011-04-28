(function ($) {

	Drupal.behaviors.micaFieldsetSummaries = {
	  attach: function (context) {
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
