(function($) {

	Drupal.behaviors.fieldVariableSettings = {
		attach : function(context) {
			var variableCheckbox = $('form#field-ui-field-edit-form input#edit-field-settings-variable-infos-variable');
			var showHide = function() {
				var isVariable = variableCheckbox.attr('checked');
				$('form#field-ui-field-edit-form .form-item-field-settings-variable-infos-variable-value-type').toggle(isVariable);
				$('form#field-ui-field-edit-form .form-item-field-settings-variable-infos-variable-body').toggle(isVariable);
			};
			showHide();
			variableCheckbox.change(function() {
				showHide();
			});
		}
	};

})(jQuery);
