Components.utils.import("resource://gre/modules/XPCOMUtils.jsm");
 
function JSubComponent()
{ 
    this.gconsole = Components.classes["@mozilla.org/consoleservice;1"].getService(Components.interfaces.nsIConsoleService);
    this.wm = Components.classes["@mozilla.org/appshell/window-mediator;1"].getService(Components.interfaces.nsIWindowMediator);
}
 
JSubComponent.prototype = {
  classDescription: "Gigatech Interface Javascript Component",
  classID:  Components.ID("{2688fa8a-2a7c-11e2-86f4-0026220fb69d}"),
  contractID:   "@gigatech.com/jsubcomponent;1",
  QueryInterface:   XPCOMUtils.generateQI([Components.interfaces.IJSubComponent]),
  
  Log: function(msg) {
    this.gconsole.logStringMessage(msg);
  },
  
  RaiseEvent: function(eventmsg) {
    this.Log(eventmsg);
    var recentWindow = this.wm.getMostRecentWindow("navigator:browser");
    var destdocument = recentWindow.content.document;
    
    var eventObj = JSON.parse(eventmsg);
    if(eventObj.type != "native") {
        var element = destdocument.createElement("gigatech_evt_data");
        element.setAttribute("msg", eventmsg);
        destdocument.documentElement.appendChild(element);
        
        var evt = destdocument.createEvent("Events");
        evt.initEvent("gigatech_evt", true, false);
        destdocument.dispatchEvent(evt);
    } else {
        var evt = destdocument.createEvent("Events");
        evt.initEvent("gigatech_nevt_"+eventObj.message, true, false);
        destdocument.dispatchEvent(evt);
    }
  }
};
var components = [JSubComponent];
if ("generateNSGetFactory" in XPCOMUtils)
  var NSGetFactory = XPCOMUtils.generateNSGetFactory(components);
else
  var NSGetModule = XPCOMUtils.generateNSGetModule(components);
