  if ("undefined" == typeof(XULSchoolChrome)) {
    var XULSchoolChrome = {};
  };

  //var observerService = Components.classes["@mozilla.org/observer-service;1"].getService(Components.interfaces.nsIObserverService);
  var prefService = Components.classes["@mozilla.org/preferences-service;1"].getService(Components.interfaces.nsIPrefBranch);

  try
  {
    //var mkService = Components.classes["@snapstick.com/mkcomponent;1"].getService(Components.interfaces.IMKComponent);
    var mkjs = Components.classes["@snapstick.com/mkjscomponent;1"].getService(Components.interfaces.IMKJSComponent);
  }
  catch(err)
  {
    alert("Couldn't load remote control manager.");
  }

  //var Firebug = window.QueryInterface(Components.interfaces.nsIInterfaceRequestor).getInterface(Components.interfaces.nsIWebNavigation).QueryInterface(Components.interfaces.nsIDocShellTreeItem).rootTreeItem.QueryInterface(Components.interfaces.nsIInterfaceRequestor).getInterface(Components.interfaces.nsIDOMWindow).Firebug;

  XULSchoolChrome.socketstat = 0;
  XULSchoolChrome.wsUri = "ws://localhost/";
  XULSchoolChrome.scalefactor = 1;
  
  XULSchoolChrome.Handler = 
  {
      Move: function(delx, dely) {
          /// Mousemove code
          delx = XULSchoolChrome.scalefactor * Math.round(delx * Math.sqrt(Math.abs(delx)));
          dely = XULSchoolChrome.scalefactor * Math.round(dely * Math.sqrt(Math.abs(dely)));        
          //mkService.Movemouse(delx,dely);       
      },
      Click: function() {
          //mkService.MouseClick(1);
      },
      KeyPress: function(keycode) {
          //mkService.KeyDownUp(keycode);
      }
  }

  function displayWebSocket()
  {
    if(XULSchoolChrome.socketstat == 0) {
        XULSchoolChrome.wsUri = prefService.getCharPref("extensions.mouse_keyboard_extension.wsUri");
        //Firebug.Console.log(XULSchoolChrome.wsUri);
        try
        {
          websocket = new WebSocket(XULSchoolChrome.wsUri,"mkmouse");
          websocket.onopen = function(evt) { onOpen(evt) };
          websocket.onclose = function(evt) { onClose(evt) };
          websocket.onmessage = function(evt) { onMessage(evt) };
          websocket.onerror = function(evt) { onError(evt) };
        }
        catch(error)
        {
            //Firebug.Console.log("Error occured...");
        }
    }
  }

  function onOpen(evt)
  {
    //Firebug.Console.log("Websocket opened...");
    websocket.send("1");
    XULSchoolChrome.socketstat = 1;
  }

  function onClose(evt)
  {
    //Firebug.Console.log("Websocket disconnected...");
    XULSchoolChrome.socketstat = 0;
  }

  function onMessage(evt)
  {
    var remoteevent = JSON.parse(evt.data);
    if(remoteevent.type == "mouse") {
        XULSchoolChrome.Handler.Move(remoteevent.x, remoteevent.y);
        if(remoteevent.button) XULSchoolChrome.Handler.Click();
    } else if (remoteevent.type == "keyboard") {
        XULSchoolChrome.Handler.KeyPress(remoteevent.keycode);
    }
  }

  function onError(evt)
  {
    //Firebug.Console.log("Error occured...");
  }

  XULSchoolChrome.PrefObs =
  {
    observe: function(aSubject, aTopic, aData) {
      if ("nsPref:changed" != aTopic) return;
        if(aData == "extensions.mouse_keyboard_extension.scalefactor") {
          var newValue = prefService.getIntPref(aData);
          XULSchoolChrome.scalefactor = newValue;
        }
    }
  }

  window.addEventListener("keydown", function(event) {
    //displayWebSocket();
    mkjs.Log("Hi.... This is JS component bugging");
  }, true, <strong>true</strong>);
  
  window.addEventListener("load", function(event) {
    prefService.addObserver("extensions.mouse_keyboard_extension.", XULSchoolChrome.PrefObs, false);
    //mkService.StartWebsocketServer(8000);
  }, true, <strong>true</strong>);
  
  window.addEventListener("unload", function(event) {
    prefService.removeObserver("", XULSchoolChrome.PrefObs);
  }, true, <strong>true</strong>);
  
  window.addEventListener("mkclickevent", function(event) {
    mkjs.Log("This is mkclickevent from browseroverlay");
  }, true, <strong>true</strong>);
  
  //document.addEventListener("DisableOpeningInTabs", function(event) {XULSchoolChrome.TabHandler.DisableOpeningInTabs();}, false, <strong>true</strong>);
