(function($) {

	Drupal.behaviors.fieldVariableSettings = {
		attach : function(context) {
			
			var variableCheckbox = $('form#field-ui-field-edit-form input#edit-field-settings-variable-infos-variable');
			
			var showHide = function() {
				var isVariable = variableCheckbox.attr('checked');
				$('form#field-ui-field-edit-form .form-item-field-settings-variable-infos-variable-value-type').toggle(isVariable);
				$('form#field-ui-field-edit-form .form-item-field-settings-variable-infos-variable-body').toggle(isVariable);
				
				// copy field description to variable description 
				var fieldDescription = $('form#field-ui-field-edit-form textarea#edit-instance-description');
				if(isVariable) {
					var variableDescription = $('form#field-ui-field-edit-form textarea#edit-field-settings-variable-infos-variable-body');
					if(!variableDescription.val()) {
						variableDescription.val(fieldDescription.val());
						fieldDescription.change(function() {
							variableDescription.val(fieldDescription.val());
						});
						variableDescription.change(function() {
							fieldDescription.unbind('change');
							variableDescription.unbind('change');
						});						
					}
				} else {
					fieldDescription.unbind('change');
				}
				
			};
			
			showHide();
			
			variableCheckbox.change(function() {
				showHide();
			});
			
		}
	};

})(jQuery);
