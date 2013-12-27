(function ($) {

  Drupal.behaviors.mica_datasets_variables_modal_detail = {
    attach: function (context, settings) {

      $("a.modals").each(function (i) {
        var id_modal = this.getAttribute('id');
        console.log('here i m ');
        console.log(id_modal);

        $('#' + id_modal).click(function () {
          $('#event-' + id_modal).modal();
        });
      });
      /*
       function openModal(id_modal){
       console.log(id_modal);
       $('.'+id_modal).click(function (d, i, datum) {
       $('#event-' +id_modal).modal();
       });
       }
       */
    }
  };

  /*
   function openModal(id_modal){
   console.log(id_modal);
   $('.'+id_modal).click(function (d, i, datum) {
   $('#event-' +id_modal).modal();
   });
   }
   ###################################

   $("a#modal").each(function (i) {
   var id_modal = this.id;
   console.log(id_modal);
   this.click(function () {
   $('#event-' + id).modal();
   });
   });

   */

}(jQuery));