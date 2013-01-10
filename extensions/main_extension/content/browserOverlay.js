  if ("undefined" == typeof(CommControl)) {
    var CommControl = {
      document_loaded: false,
      websocket_started: false,
      loadContent: function (status) {
        if(status) {
          gBrowser.loadURI("http://localhost:8000/");
        } else {
          //gBrowser.loadURI("http://localhost:8000/");
        }
      }
    };
  };
  
  try
  {
    var mkService = Components.classes["@gigatech.com/maincomponent;1"].getService(Components.interfaces.IMainComponent);
    var mkjs = Components.classes["@gigatech.com/jsubcomponent;1"].getService(Components.interfaces.IJSubComponent);
  }
  catch(err)
  {
    alert("Couldn't load remote control manager.");
  }

  document.addEventListener("gigatech_evt_send", function (event) {
    mkjs.Log("Gigatech event received...");
    var msg;
    var dataelement = event.target.getElementsByTagName("gigatech_evt_send_data");
    mkjs.Log(JSON.stringify(dataelement));
    for(var elem in dataelement) {
      msg = dataelement[elem].getAttribute("msg");
      var evt = JSON.parse(msg);
      switch(evt.type) {
        case "mouse_rel": {
          mkService.Movemouse(evt.x,evt.y);
          break;
        }
        case "mouse_abs": {
          mkService.SetMousePosition(evt.x,evt.y);
          break;
        }
        case "mouse_clk": {
          mkService.MouseClick(evt.button);
          break;
        }
        case "keyboard": {
          mkService.KeyDownUp(evt.keycode);
          break;
        }
        case "nativemsg": {
          mkService.SendNativeMessage(JSON.stringify(evt.message));
          break;
        }
        case "gamemsg": {
          mkService.SendClientMessage(evt.toclient,JSON.stringify(evt.message));
          break;
        }
        default:
      }
      dataelement[elem].parentNode.removeChild(dataelement[elem]);
    }
  }, true, <strong>true</strong>);

  window.addEventListener("load", function(event) {
    mkjs.Log("Starting websocket server...");
    mkService.StartWebsocketServer(8000);
    StartupObserver = new XULObserver();
  }, true, <strong>true</strong>);
  
  window.addEventListener("gigatech_nevt_websocket_opened", function (event) {
    mkjs.Log("Websocket server started...");
    CommControl.websocket_started = true;
    if(CommControl.document_loaded) {
      CommControl.loadContent(true);
    }
  }, true, <strong>true</strong>);
  
  function XULObserver()
  {
      this.EVENT_CONTENT_DOCUMENT_ELEMENT_INSERTED = 'document-element-inserted';
      this.register();
  }
  
  XULObserver.prototype = {
      observe: function(subject, topic, data) {
          if (topic == this.EVENT_CONTENT_DOCUMENT_ELEMENT_INSERTED) {
              CommControl.document_loaded = true;
              if(CommControl.websocket_started) {
                CommControl.loadContent(true);
              }
              this.unregister();
          }
      },
  
      register: function() {
          var observerService = Components.classes["@mozilla.org/observer-service;1"].getService(Components.interfaces.nsIObserverService);  
          observerService.addObserver(this, this.EVENT_CONTENT_DOCUMENT_ELEMENT_INSERTED, false);
      },  
      unregister: function() {  
          var observerService = Components.classes["@mozilla.org/observer-service;1"].getService(Components.interfaces.nsIObserverService);  
          observerService.removeObserver(this, this.EVENT_CONTENT_DOCUMENT_ELEMENT_INSERTED);  
      }
  }  