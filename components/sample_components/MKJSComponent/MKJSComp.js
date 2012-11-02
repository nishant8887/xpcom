Components.utils.import("resource://gre/modules/XPCOMUtils.jsm");
 
function MKJSComponent()
{ 
    this.gconsole = Components.classes["@mozilla.org/consoleservice;1"].getService(Components.interfaces.nsIConsoleService);
}
 
MKJSComponent.prototype = {
  classDescription: "Snapstick Mouse Keyboard Javascript XPCOM Component",
  classID:  Components.ID("{3ef9d0d6-0e1a-11e2-9f83-770cf8d9c752}"),
  contractID:   "@snapstick.com/mkjscomponent;1",
  QueryInterface:   XPCOMUtils.generateQI([Components.interfaces.IMKJSComponent]),
  
  Log: function(msg) {
    this.gconsole.logStringMessage(msg);
  },
  RaiseEvent: function(eventmsg)
  {
    var natevent = JSON.parse(eventmsg);
    var wm = Components.classes["@mozilla.org/appshell/window-mediator;1"].getService(Components.interfaces.nsIWindowMediator);
    var recentWindow = wm.getMostRecentWindow("navigator:browser");
    var destdocument = recentWindow.content.document;
    
    var eventstr;
    switch(natevent.type) {
        case "regclient":
            var element = destdocument.createElement("snakeelemdata");
            element.setAttribute("clientid", natevent.clientid);
            destdocument.documentElement.appendChild(element);
            eventstr = "regclient";
            break;
        case "unregclient":
            var element = destdocument.createElement("snakeelemdata");
            element.setAttribute("clientid", natevent.clientid);
            destdocument.documentElement.appendChild(element);
            eventstr = "unregclient";
            break;
        case "left":
        case "right":
        case "up":
        case "down":
            eventstr = "snake"+(natevent.clientid+1)+natevent.type;
            break;
        default:
            eventstr = "";
    }
    
    if(eventstr !== "") {
        var evt = destdocument.createEvent("Events");
        evt.initEvent(eventstr, true, false);
        destdocument.dispatchEvent(evt);
    }
  }
};
var components = [MKJSComponent];
if ("generateNSGetFactory" in XPCOMUtils)
  var NSGetFactory = XPCOMUtils.generateNSGetFactory(components);
else
  var NSGetModule = XPCOMUtils.generateNSGetModule(components);
