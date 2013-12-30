/**
 * Created by root on 13/12/13.
 */

(function ($) {
  Drupal.behaviors.datatables_gen = {
    attach: function (context, settings) {
      var oTable = $('#example').dataTable({
        "bAutoWidth": false,
        "aaSorting": [],
        "sScrollY": "450px",
        "sScrollX": "100%",
        "sScrollXInner": "110%",
        "bScrollCollapse": true,
        "bLengthChange": false,
        "bPaginate": false,
        "bSort": false,
        "aaSortingFixed": [
          [1, 'asc']
        ],
        "aoColumnDefs": [
          {"sWidth": "20%", "bVisible": false, "aTargets": [1] }
        ],
        "sDom": 'T<"clear">lrf<"left"C>tip',
        "oTableTools": {
          "sSwfPath": "../profiles/mica_distribution/libraries/datatables/swf/copy_csv_xls_pdf.swf",
          "aButtons": ["xls", "csv", "pdf" ]
        }
      });
      new FixedColumns(oTable, {
        "fnDrawCallback": function (left, right) {
          var oSettings = oTable.fnSettings();
          if (oSettings.aiDisplay.length == 0) {
            return;
          }

          var nGroup, nCell, iIndex, sGroup;
          var sLastGroup = "", iCorrector = 0;
          var nTrs = $('#example tbody tr');
          var iColspan = nTrs[0].getElementsByTagName('td').length;

          for (var i = 0; i < nTrs.length; i++) {
            iIndex = oSettings._iDisplayStart + i;
            sGroup = oSettings.aoData[ oSettings.aiDisplay[iIndex] ]._aData[1];

            if (sGroup != sLastGroup) {
              /* Cell to insert into main table */
              nGroup = document.createElement('tr');
              nCell = document.createElement('td');
              nCell.colSpan = iColspan;
              nCell.className = "group";
              nCell.innerHTML = "&nbsp;";
              nGroup.appendChild(nCell);
              nTrs[i].parentNode.insertBefore(nGroup, nTrs[i]);

              /* Cell to insert into the frozen columns */
              nGroup = document.createElement('tr');
              nCell = document.createElement('td');
              nCell.className = "group";
              nCell.innerHTML = sGroup;
              nGroup.appendChild(nCell);
              $(nGroup).insertBefore($('tbody tr:eq(' + (i + iCorrector) + ')', left.body)[0]);

              iCorrector++;
              sLastGroup = sGroup;
            }
          }
        },
        iLeftWidth: 350
      });

      /*Multiselect event */

      $("#edit-studies").multiselect({
        click: function (event, ui) {
          retrievestudiescheckbox(event, ui);
        },
        checkAll: function () {
          retrievestudiescheckbox();
        },
        uncheckAll: function () {
          retrievestudiescheckbox();
        }
      });

      $("#edit-dce").multiselect({
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

      $("#edit-dataset").multiselect({
        click: function (event, ui) {
          var datasets = [];
          datasets.push($("input[name=multiselect_edit-dataset]:checked").map(function () {return this.value;}).get().join(","));
          //console.log(datasets);
        }
      });


      function retrivecheckeddcebox(event, ui) {
        var dce = [];
        dce.push($("input[name=multiselect_edit-dce]:checked").map(function () {return this.value;}).get().join(","));
        /****************/
        var post = "&dce=" + dce;
        $.ajax({
          'url': 'content/datasets-domains-coverage-table-ajx-query',
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
            /*
             $(document).ready(function () {
             $(#status).attr("innerHTML","Loading....");
             });
             */
          },
          'error': function (data) {
          }
        });
        /****************/
      }

      function retrievestudiescheckbox() {
        var studies = [];
        studies.push($("input[name=multiselect_edit-studies]:checked").map(function () {return this.value;}).get().join(","));

        /****************/
        var post = "&studies=" + studies;
        $.ajax({
          'url': 'content/datasets-domains-coverage-table-ajx-query',
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
            /*
             $(document).ready(function () {
             $(#status).attr("innerHTML","Loading....");
             });
             */
          },
          'error': function (data) {
          }
        });
        /****************/
      }
    }
  }

})(jQuery);