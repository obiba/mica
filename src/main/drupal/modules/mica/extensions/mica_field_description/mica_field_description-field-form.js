(function ($) {

  Drupal.behaviors.fieldDescriptionSettings = {
    attach: function (context) {

      var fd_checkbox = $('form#field-ui-field-edit-form input#edit-field-settings-field-description-infos-field-description');

      var showHide = function () {
        var has_fd = fd_checkbox.attr('checked');
        $('form#field-ui-field-edit-form .form-item-field-settings-field-description-infos-field-description-value-type').toggle(has_fd);
        $('form#field-ui-field-edit-form .form-item-field-settings-field-description-infos-field-description-label').toggle(has_fd);
        $('form#field-ui-field-edit-form .form-item-field-settings-field-description-infos-field-description-body').toggle(has_fd);

        // copy label or display if present to field_original_field_label
        var fieldLabel = $('form#field-ui-field-edit-form input#edit-instance-label');
        var fieldDisplayLabel = $('form#field-ui-field-edit-form input#edit-instance-display-label');

        if (has_fd) {
          var fd_label = $('form#field-ui-field-edit-form input#edit-field-settings-field-description-infos-field-description-label');

          if (!fd_label.val()) {
            if (fieldDisplayLabel && fieldDisplayLabel.val().length) {
              // if display label exists we use it
              fd_label.val(fieldDisplayLabel.val());
              fieldDisplayLabel.change(function () {
                fd_label.val(fieldDisplayLabel.val());
              });
              fd_label.change(function () {
                fieldDisplayLabel.unbind('change');
                fd_label.unbind('change');
              });
            } else {
              // else we use regular label
              fd_label.val(fieldLabel.val());
              fieldLabel.change(function () {
                fd_label.val(fieldLabel.val());
              });
              fd_label.change(function () {
                fieldLabel.unbind('change');
                fd_label.unbind('change');
              });
            }
          }
        }

        // copy field description to field_description description
        var fieldDescription = $('form#field-ui-field-edit-form textarea#edit-instance-description');
        if (has_fd) {
          var fd_desc = $('form#field-ui-field-edit-form textarea#edit-field-settings-field-description-infos-field-description-body');
          if (!fd_desc.val()) {
            fd_desc.val(fieldDescription.val());
            fieldDescription.change(function () {
              fd_desc.val(fieldDescription.val());
            });
            fd_desc.change(function () {
              fieldDescription.unbind('change');
              fd_desc.unbind('change');
            });
          }
        } else {
          fieldDescription.unbind('change');
        }

      };

      showHide();

      fd_checkbox.change(function () {
        showHide();
      });

    }
  };

})(jQuery);
