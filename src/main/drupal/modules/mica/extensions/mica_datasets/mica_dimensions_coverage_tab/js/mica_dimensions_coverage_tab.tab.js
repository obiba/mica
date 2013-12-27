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
          var studies = [];
          studies.push($("input[name=multiselect_edit-studies]:checked").map(function () {return this.value;}).get().join(","));
          console.log(studies);
          /****************/
          var post = "&studies=" + studies;
          $.ajax({
            'url': 'datasets-domains-coverage-table-ajx-query',
            'type': 'POST',
            'dataType': 'json',
            'data': post,
            'success': function (data) {
              /*Todo reconstruire les multi select dce et dataset*/
              console.log(data);


              //  selected = $('#selected');
              var delselect = $('select#edit-studies');
              var new_emptuselect = $('<select multiple="multiple" name="studies[]" id="edit-studies" class="form-select"><option><option /></select>');
              delselect.replaceWith(new_emptuselect);
              var el = $("#edit-dce").multiselect();
              el.multiselect('refresh');
              /*
               $.each(data, function(i, item) {
               console.log(i);
               console.log(item);

               var   opt = $('<option />', {
               value:i,
               text: item
               });

               opt.attr('selected','selected');

               opt.appendTo( el );

               el.multiselect('refresh');

               });
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


          /****************/
        }
      });

      $("#edit-dce").multiselect({
        click: function (event, ui) {
          var dce = [];
          dce.push($("input[name=multiselect_edit-dce]:checked").map(function () {return this.value;}).get().join(","));
          console.log(dce);
        }
      });

      $("#edit-dataset").multiselect({
        click: function (event, ui) {
          var datasets = [];
          datasets.push($("input[name=multiselect_edit-dataset]:checked").map(function () {return this.value;}).get().join(","));
          console.log(datasets);
        }
      });

    }
  }

})(jQuery);