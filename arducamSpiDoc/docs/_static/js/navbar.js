function adjustNavbarPosition() {
    var navbar = document.getElementsByClassName("wy-nav-side")[0];
    var offset = 50 - window.pageYOffset;
    if (offset >= 0) {
      navbar.style.top = offset + "px";
    } else {
      navbar.style.top = 0 + "px";
    }
  }
  
window.onscroll = adjustNavbarPosition;

function addNavBar() {
    var navbarHtml = "<div id='arheader'></div>"
    document.body.insertAdjacentHTML( 'afterbegin', navbarHtml );
}

document.onreadystatechange = function(e) {
    if (document.readyState === 'interactive') {
        addNavBar();
        adjustNavbarPosition();
        document.getElementsByClassName("wy-side-scroll")[0].scrollTop = 0;
    }
}