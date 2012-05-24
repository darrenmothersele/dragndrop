(function ($) {

  Drupal.behaviors.dragndropExample = {
    attach: function (context, settings) {
      $('.draggable', context).draggable({
        revert: 'invalid',
      });
      $('.droppable', context).droppable({
        hoverClass: 'drop-hover',
        accept: '.draggable',  
        drop: function(event, ui) {
	        var callback1 = $('.callback', event.target).html();
	        var callback2 = $('.callback', ui.draggable).html();
	        var href = Drupal.settings.basePath + callback1 + callback2;
	
	        $(ui.draggable).hide();
	        $(event.target).fadeTo('fast', 0.5);
	
	        $.ajax({
		        url: href,
		        success: function(data) {
			        $('.droppable').html(data).fadeTo('fast', 1);
		        },
          });
        },
      });
    }
  };

})(jQuery);