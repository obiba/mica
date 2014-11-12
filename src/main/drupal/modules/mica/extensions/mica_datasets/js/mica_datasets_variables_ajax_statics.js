(function ($) {

  Drupal.behaviors.mica_datasets_ajax_table = {
    attach: function (context, settings) {
      GetAjaxTable();
      /***********************************/
      function GetAjaxTable() {
        var message_div = $('#txtblnk');
        var param = $('#param-statistics');
        var id_variable = param.attr('variable-id');

        $.ajax({
          'url': Drupal.settings.basePath + 'opal-variable-detail-statistics/' + id_variable,
          'type': 'GET',
          'dataType': 'html',
          'data': '',
          'success': function (data) {
            message_div.empty();
            param.css({'padding-top': '0'});
            $(JSON.parse(data)).appendTo(param);
          },
          beforeSend: function () {
            blinkeffect('#txtblnk');
          },
          'error': function (data) {
            param.empty();
            $(Drupal.t('Error getting statistics')).appendTo(param);
          }
        });

      }

      function blinkeffect(selector) {
        $(selector).fadeOut('slow', function () {
          $(this).fadeIn('slow', function () {
            blinkeffect(this);
          });
        });
      }

      /******************************************/

    }
  };

}(jQuery));