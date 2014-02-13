(function ($) {

  Drupal.behaviors.mica_datasets_variables_ajax_table = {
    attach: function (context, settings) {
      GetAjaxTable();
      /***********************************/
      function GetAjaxTable() {
        var message_div = $('#txtblnk');
        var param = $('#param-statistics');
        var id_dataset = param.attr('dataset-id');
        var id_study = param.attr('study-id');
        var var_name = param.attr('var-name');

        $.ajax({
          'url': '?q=opal-varaible-detail-statistics/' + var_name + "/dataset/" + id_dataset + "/study/" + id_study,
          'type': 'GET',
          'dataType': 'html',
          'data': '',
          'success': function (data) {
            message_div.empty();

            param.css({'padding-top': '0'});
            $(data).appendTo(param);
          },
          beforeSend: function () {
            blinkeffect('#txtblnk');
          },
          'error': function (data) {
            param.empty();
            $(Drupal.t('Error!')).appendTo(param);
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