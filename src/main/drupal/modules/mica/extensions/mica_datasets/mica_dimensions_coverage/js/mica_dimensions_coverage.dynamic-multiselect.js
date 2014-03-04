(function ($) {
  Drupal.behaviors.datatables_multislect = {
    attach: function (context, settings) {
      $(window).load(function () {
        $(".loader").fadeOut("slow");
      });

      /*Multiselect event populate DCE Multiselect Field */
      $("#edit-studies").multiselectfilter("destroy");
      $("#edit-studies").multiselect({
        minWidth: 350,
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
        close: function () {
          perform_search();
        }


      });
      $("#edit-studies").multiselect().multiselectfilter({
        label: Drupal.t('Search:'),
        width: 250, /* override default width set in css file (px). null will inherit */
        placeholder: Drupal.t('Studies filter by title'),
        autoReset: true
      });

      /*Multiselect event populate Dataset Multiselect Field */
      $("#edit-dce").multiselectfilter("destroy");
      $("#edit-dce").multiselect({
        selectedText: function (numChecked, numTotal) {
          return Drupal.t('@numChecked of @numTotal checked', {'@numChecked': numChecked, '@numTotal': numTotal});
        },
        click: function (event, ui) {
          //   retrivecheckeddcebox(event, ui);
        },
        optgrouptoggle: function (event, ui) {
          //     retrivecheckeddcebox(event, ui);
        },
        checkAll: function () {
          //     retrivecheckeddcebox();
        },
        uncheckAll: function () {
          //     retrivecheckeddcebox();
        }
      });


      $("#edit-dataset").multiselectfilter("destroy");
      $("#edit-dataset").multiselect({
        selectedText: function (numChecked, numTotal) {
          return Drupal.t('@numChecked of @numTotal checked', {'@numChecked': numChecked, '@numTotal': numTotal});
        },
        close: function () {
          perform_search();
        }
      });

      /******************************************************/

      /**********Ajax function to populate Multiselect DCE options *****/
      function retrievestudiescheckbox() {
        var studies = [];
        studies.push($("input[name=multiselect_edit-studies]:checked").map(function () {return this.value;}).get().join(","));
        var post = "&studies=" + studies;
        $.ajax({
          'url': '?q=content/datasets-domains-coverage-table-ajx-query',
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
        $(".loader").fadeIn("slow");
        var dce = [];
        dce.push($("input[name=multiselect_edit-dce]:checked").map(function () {return this.value;}).get().join(","));
        var studies = [];
        studies.push($("input[name=multiselect_edit-studies]:checked").map(function () {return this.value;}).get().join(","));
        var dataset = studies.push($("input[name=multiselect_edit-dataset]:checked").map(function () {return this.value;}).get().join(","));
        if (studies == "") {
          $('select#edit-dce').children().remove();
          var el = $("#edit-dce").multiselect();
          el.multiselect('refresh');
          document.forms["mica-dimensions-coverage-filter-form"].submit();
        }
        if (dce != "") {
          document.forms["mica-dimensions-coverage-filter-form"].submit();
        }
        if (dataset != "") {
          document.forms["mica-dimensions-coverage-filter-form"].submit();
        }
      }

      /*****************************************************/
      /********************action in select deselect checkbox*************/
      $('#edit-show-dce').on('change', function () {
        perform_search()
      });
      /********************************************************************/
    }
  }
})(jQuery);
