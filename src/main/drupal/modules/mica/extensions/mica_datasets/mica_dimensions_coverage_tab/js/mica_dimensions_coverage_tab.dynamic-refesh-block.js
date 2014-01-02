(function ($) {
  Drupal.behaviors.datatables_multislect = {
    attach: function (context, settings) {
      /*Multiselect event populate DCE Multiselect Field */


      /*Multiselect event populate Dataset Multiselect Field */
      $("#edit-dataset").multiselect({
        click: function (event, ui) {
          retrivecheckeddcebox(event, ui);
        },
        optgrouptoggle: function (event, ui) {
          retrivecheckeddcebox(event, ui);
        },
        checkAll: function () {
          retrivecheckeddcebox();
        },
        uncheckAll: function () {
          retrivecheckeddcebox();
        }
      });

      //Todo my be to use to dynamically populate Datatabale with ajax request
      /*
       $("#edit-dataset").multiselect({
       click: function (event, ui) {
       var datasets = [];
       datasets.push($("input[name=multiselect_edit-dataset]:checked").map(function () {return this.value;}).get().join(","));
       //console.log(datasets);
       }
       });
       */

      /**********Ajax function to populate Multiselect Dataset options *****/
      function retrivecheckeddcebox(event, ui) {
        var dataset = [];
        dataset.push($("input[name=multiselect_edit-dataset]:checked").map(function () {return this.value;}).get().join(","));
        var post = "&dataset=" + dataset;
        $.ajax({
          'url': 'content/datasets-domains-coverage-table-refrech-table-block',
          'type': 'POST',
          'dataType': 'json',
          'data': post,
          'success': function (data) {
            console.log(data);
            $("#table-refresh").html(data);
            /*
             $('select#edit-dataset').children().remove();
             var el = $("#edit-dataset").multiselect();
             el.multiselect('refresh');
             if (data) {
             $.each(data, function (o, item) {
             var optgroup = $('<optgroup>');
             optgroup.attr('label', o);
             $.each(item, function (i, datcet) {
             var opt = $('<option />', {
             value: i,
             text: datcet
             });
             opt.attr('selected', 'selected');
             opt.appendTo(el);
             optgroup.append(opt);
             });
             el.append(optgroup);
             });
             el.multiselect('refresh');
             }
             */
          },
          beforeSend: function () {
            /*
             $(document).ready(function () {
             $(#status).attr("innerHTML","Loading....");
             });
             */
          },
          'error': function (data) {
          }
        });
      }

      /******************************************************/


    }
  }
})(jQuery);