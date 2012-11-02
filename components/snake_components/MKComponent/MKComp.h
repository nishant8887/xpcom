#ifndef __gen_MKComp_h__
#define __gen_MKComp_h__

#include "MKInt.h"
#include "MKJSComp.h"
#include "nsCOMPtr.h"
#include "nsComponentManagerUtils.h"
#include "nsServiceManagerUtils.h"
#include "nsThreadUtils.h"
#include <X11/Xlib.h>
#include <X11/extensions/XTest.h>
#include <string>
#include <sstream>
#include "nsStringAPI.h"

#define MKCOMP_CONTRACTID "@snapstick.com/mkcomponent;1"
#define MKCOMP_CLASSNAME "Mouse_Keyboard_Component"
#define MKCOMP_CID { 0xe9093e2e, 0xf351, 0x11e1, { 0xa8, 0xa5, 0xfb, 0xd2, 0x2f, 0xf0, 0x1f, 0x0f } }

#define KEY_SHIFT 50
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class WebsocketServer;

class MKComponent : public IMKComponent
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_IMKCOMPONENT

  MKComponent();

  void SendEventToDOM(std::string, int);
  void ExecuteEvent();
  
private:
  ~MKComponent();

protected:
  /* additional members */
  Display *display;
  long clickedbutton;
  KeyCode pressedkey;
  WebsocketServer *wss;
  nsCOMPtr<IMKJSComponent> jsutils;

  std::ostringstream eventmessage;
  void getkeys(KeyCode &, long &, KeySym);
};
#endif
