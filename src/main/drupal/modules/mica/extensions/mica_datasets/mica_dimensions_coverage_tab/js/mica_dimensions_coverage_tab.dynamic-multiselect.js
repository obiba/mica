(function ($) {
  Drupal.behaviors.datatables_multislect = {
    attach: function (context, settings) {
      /*Multiselect event populate DCE Multiselect Field */
      $("#edit-studies").multiselectfilter("destroy");
      $("#edit-studies").multiselect({
        selectedText: function (numChecked, numTotal) {
          return Drupal.t('@numChecked of @numTotal checked', {'@numChecked': numChecked, '@numTotal': numTotal});
        },
        click: function (event, ui) {
          retrievestudiescheckbox(event, ui);

        },
        checkAll: function () {
          retrievestudiescheckbox();

        },
        uncheckAll: function () {

          retrievestudiescheckbox();

        },

        close: function(){
      perform_search();
   },


      });

      /*Multiselect event populate Dataset Multiselect Field */
      $("#edit-dce").multiselectfilter("destroy");
      $("#edit-dce").multiselect({
        selectedText: function (numChecked, numTotal) {
          return Drupal.t('@numChecked of @numTotal checked', {'@numChecked': numChecked, '@numTotal': numTotal});
        },
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


      $("#edit-dataset").multiselectfilter("destroy");
      $("#edit-dataset").multiselect({
        selectedText: function (numChecked, numTotal) {
          return Drupal.t('@numChecked of @numTotal checked', {'@numChecked': numChecked, '@numTotal': numTotal});
        }
      });
      /**********Ajax function to populate Multiselect Dataset options *****/
      function retrivecheckeddcebox(event, ui) {
        var dce = [];
        dce.push($("input[name=multiselect_edit-dce]:checked").map(function () {return this.value;}).get().join(","));
        var type = $("input[name=type]").val();
        var post = "&type=" + type + "&dce=" + dce;
        $.ajax({
          'url': '/content/datasets-domains-coverage-table-ajx-query',
          'type': 'POST',
          'dataType': 'json',
          'data': post,
          'success': function (data) {
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

          },
          beforeSend: function () {

          },
          'error': function (data) {
            $('select#edit-dataset').children().remove();
            var el = $("#edit-dataset").multiselect();
            el.multiselect('refresh');
          }
        });
      }

      /******************************************************/

      /**********Ajax function to populate Multiselect DCE options *****/
      function retrievestudiescheckbox() {
        var studies = [];
        studies.push($("input[name=multiselect_edit-studies]:checked").map(function () {return this.value;}).get().join(","));
        var post = "&studies=" + studies;
        $.ajax({
          'url': '/content/datasets-domains-coverage-table-ajx-query',
          'type': 'POST',
          'dataType': 'json',
          'data': post,
          'success': function (data) {
            $('select#edit-dce').children().remove();
            var el = $("#edit-dce").multiselect();
            el.multiselect('refresh');
            if (data) {
              $.each(data, function (o, item) {
                var optgroup = $('<optgroup>');
                optgroup.attr('label', o);

                $.each(item, function (i, dce) {
                  var opt = $('<option />', {
                    value: i,
                    text: dce
                  });
                  opt.attr('selected', 'selected');
                  opt.appendTo(el);
                  optgroup.append(opt);
                });
                el.append(optgroup);
              });
              el.multiselect('refresh');
            }

          },
          beforeSend: function () {

          },
          'error': function (data) {
            $('select#edit-dce').children().remove();
            var el = $("#edit-dce").multiselect();
            el.multiselect('refresh');
          }
        });
      }

      /************************************/

/*********************perform search action *************/

/**********Ajax function to populate Multiselect DCE options *****/
      function perform_search() {

        document.forms["mica-dimensions-coverage-tab-filter-form"].submit();

        console.log('hello word');
      }

/*****************************************************/
/********************action in select deselect checkbox*************/
 $('#edit-show-dce').on('change',function(){
            $('#mica-dimensions-coverage-tab-filter-form').submit();
            });
/********************************************************************/
    }
  }
})(jQuery);
