function CloseBrowser()
{
  close();
}

function NavigationBarSettings()
{
  var prefs = Components.classes["@mozilla.org/preferences-service;1"].getService(Components.interfaces.nsIPrefBranch);
  //prefs.setBoolPref("browser.fullscreen.autoHide",0)
  prefs.setBoolPref("browser.tabs.drawInTitlebar", false);
  prefs.setBoolPref("browser.tabs.autoHide", false);
  prefs.setBoolPref("browser.tabs.warnOnClose", false);

  var navBoxElement = document.getElementById("navigator-toolbox");
  navBoxElement.setAttribute("tabsontop", "false");

  var navBarElement = document.getElementById("nav-bar");
  navBarElement.setAttribute("collapsed", "true");

  var menuBarElement = document.getElementById("toolbar-menubar");
  menuBarElement.setAttribute("hidden", "true");

  var customBarElement = document.getElementById("customToolbars");
  customBarElement.setAttribute("hidden", "true");

  var personalBarElement = document.getElementById("PersonalToolbar");
  personalBarElement.setAttribute("hidden", "true");

  gBrowser.tabContainer.addEventListener('dragstart', onDragStart, true);
  gBrowser.tabContainer.addEventListener('dblclick', onDblClick, true);
}

function SnapstickBrowserStartup()
{
  NavigationBarSettings();
  BrowserStartup();
  setTimeout(FullScreenStartup, 1);
}

function FullScreenStartup()
{
  window.fullScreen = true;
}

function Do_Nothing()
{
}

function onDragStart(event) {
    event.stopPropagation();
}

function onDblClick(event) {
    event.stopPropagation();
}
