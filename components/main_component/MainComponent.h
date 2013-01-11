#ifndef __gen_MainComponent_h__
#define __gen_MainComponent_h__

#include "IMainComponent.h"
#include "IJSubComponent.h"

#include "nsCOMPtr.h"
#include "nsServiceManagerUtils.h"
//#include "nsComponentManagerUtils.h"
#include "nsThreadUtils.h"
#include "nsStringAPI.h"

#include <X11/Xlib.h>
#include <X11/extensions/XTest.h>
#include <iostream>
#include <string>
#include <sstream>
#include <pthread.h>

#define GIGACOMP_CONTRACTID "@gigatech.com/maincomponent;1"
#define GIGACOMP_CLASSNAME "Gigatech Interface Component"
#define GIGACOMP_CID { 0x174a6694, 0x2a7c, 0x11e2, { 0xaf, 0x3d, 0x00, 0x26, 0x22, 0x0f, 0xb6, 0x9d } }

#define KEY_SHIFT 50
/* Use the code below as a template for the implementation class for this interface. */

using namespace std;

/* Header file */
class WebsocketServer;

class MainComponent : public IMainComponent
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_IMAINCOMPONENT

  MainComponent();
  bool serverstarted;
  
  nsCOMPtr<IJSubComponent> jsutils;

private:
  ~MainComponent();

protected:
  /* additional members */
    Display *display;
    WebsocketServer *wss;
    void GetKeys(KeyCode &, long &, KeySym);
};
#endif
