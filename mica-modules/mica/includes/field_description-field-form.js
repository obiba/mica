(function($) {

	Drupal.behaviors.fieldDescriptionSettings = {
		attach : function(context) {
			
			var fd_checkbox = $('form#field-ui-field-edit-form input#edit-field-settings-field-description-infos-field-description');
			
			var showHide = function() {
				var has_fd = fd_checkbox.attr('checked');
				$('form#field-ui-field-edit-form .form-item-field-settings-field-description-infos-field-description-value-type').toggle(has_fd);
				$('form#field-ui-field-edit-form .form-item-field-settings-field-description-infos-field-description-body').toggle(has_fd);
				
				// copy field description to field_description description 
				var fieldDescription = $('form#field-ui-field-edit-form textarea#edit-instance-description');
				if(has_fd) {
					var fd_desc = $('form#field-ui-field-edit-form textarea#edit-field-settings-field-description-infos-field-description-body');
					if(!fd_desc.val()) {
						fd_desc.val(fieldDescription.val());
						fieldDescription.change(function() {
							fd_desc.val(fieldDescription.val());
						});
						fd_desc.change(function() {
							fieldDescription.unbind('change');
							fd_desc.unbind('change');
						});						
					}
				} else {
					fieldDescription.unbind('change');
				}
				
			};
			
			showHide();
			
			fd_checkbox.change(function() {
				showHide();
			});
			
		}
	};

})(jQuery);
