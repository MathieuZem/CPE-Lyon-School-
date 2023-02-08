jQuery(function(){
    $(function () {
        $(window).scroll(function () {
            if ($(this).scrollTop() > 200 ) { 
                $("#remonter").css("right","10px");
            } else { 
                $("#remonter").removeAttr( "style" );
            }

        });
    });
});