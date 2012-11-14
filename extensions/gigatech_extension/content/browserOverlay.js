  if ("undefined" == typeof(CommControl)) {
    var CommControl = {};
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
    mkjs.Log("Websocket server started...");
    mkService.StartWebsocketServer(8000);
  }, true, <strong>true</strong>);
  
  window.addEventListener("unload", function(event) {
    mkjs.Log("Unloading window...");
  }, true, <strong>true</strong>);
  