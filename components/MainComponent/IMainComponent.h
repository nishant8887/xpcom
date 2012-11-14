/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM IMainComponent.idl
 */

#ifndef __gen_IMainComponent_h__
#define __gen_IMainComponent_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    IMainComponent */
#define IMAINCOMPONENT_IID_STR "174a6694-2a7c-11e2-af3d-0026220fb69d"

#define IMAINCOMPONENT_IID \
  {0x174a6694, 0x2a7c, 0x11e2, \
    { 0xaf, 0x3d, 0x00, 0x26, 0x22, 0x0f, 0xb6, 0x9d }}

class NS_NO_VTABLE NS_SCRIPTABLE IMainComponent : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(IMAINCOMPONENT_IID)

  /* void Movemouse (in long delx, in long dely); */
  NS_SCRIPTABLE NS_IMETHOD Movemouse(PRInt32 delx, PRInt32 dely) = 0;

  /* void SetMousePosition (in long x, in long y); */
  NS_SCRIPTABLE NS_IMETHOD SetMousePosition(PRInt32 x, PRInt32 y) = 0;

  /* void KeyDownUp (in long keysym); */
  NS_SCRIPTABLE NS_IMETHOD KeyDownUp(PRInt32 keysym) = 0;

  /* void MouseClick (in long button); */
  NS_SCRIPTABLE NS_IMETHOD MouseClick(PRInt32 button) = 0;

  /* long GetMouseX (); */
  NS_SCRIPTABLE NS_IMETHOD GetMouseX(PRInt32 *_retval NS_OUTPARAM) = 0;

  /* long GetMouseY (); */
  NS_SCRIPTABLE NS_IMETHOD GetMouseY(PRInt32 *_retval NS_OUTPARAM) = 0;

  /* void SendNativeMessage (in string message); */
  NS_SCRIPTABLE NS_IMETHOD SendNativeMessage(const char * message) = 0;

  /* long SendClientMessage (in long clientid, in string message); */
  NS_SCRIPTABLE NS_IMETHOD SendClientMessage(PRInt32 clientid, const char * message, PRInt32 *_retval NS_OUTPARAM) = 0;

  /* void StartWebsocketServer (in long port); */
  NS_SCRIPTABLE NS_IMETHOD StartWebsocketServer(PRInt32 port) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(IMainComponent, IMAINCOMPONENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_IMAINCOMPONENT \
  NS_SCRIPTABLE NS_IMETHOD Movemouse(PRInt32 delx, PRInt32 dely); \
  NS_SCRIPTABLE NS_IMETHOD SetMousePosition(PRInt32 x, PRInt32 y); \
  NS_SCRIPTABLE NS_IMETHOD KeyDownUp(PRInt32 keysym); \
  NS_SCRIPTABLE NS_IMETHOD MouseClick(PRInt32 button); \
  NS_SCRIPTABLE NS_IMETHOD GetMouseX(PRInt32 *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetMouseY(PRInt32 *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD SendNativeMessage(const char * message); \
  NS_SCRIPTABLE NS_IMETHOD SendClientMessage(PRInt32 clientid, const char * message, PRInt32 *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD StartWebsocketServer(PRInt32 port); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_IMAINCOMPONENT(_to) \
  NS_SCRIPTABLE NS_IMETHOD Movemouse(PRInt32 delx, PRInt32 dely) { return _to Movemouse(delx, dely); } \
  NS_SCRIPTABLE NS_IMETHOD SetMousePosition(PRInt32 x, PRInt32 y) { return _to SetMousePosition(x, y); } \
  NS_SCRIPTABLE NS_IMETHOD KeyDownUp(PRInt32 keysym) { return _to KeyDownUp(keysym); } \
  NS_SCRIPTABLE NS_IMETHOD MouseClick(PRInt32 button) { return _to MouseClick(button); } \
  NS_SCRIPTABLE NS_IMETHOD GetMouseX(PRInt32 *_retval NS_OUTPARAM) { return _to GetMouseX(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetMouseY(PRInt32 *_retval NS_OUTPARAM) { return _to GetMouseY(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD SendNativeMessage(const char * message) { return _to SendNativeMessage(message); } \
  NS_SCRIPTABLE NS_IMETHOD SendClientMessage(PRInt32 clientid, const char * message, PRInt32 *_retval NS_OUTPARAM) { return _to SendClientMessage(clientid, message, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD StartWebsocketServer(PRInt32 port) { return _to StartWebsocketServer(port); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_IMAINCOMPONENT(_to) \
  NS_SCRIPTABLE NS_IMETHOD Movemouse(PRInt32 delx, PRInt32 dely) { return !_to ? NS_ERROR_NULL_POINTER : _to->Movemouse(delx, dely); } \
  NS_SCRIPTABLE NS_IMETHOD SetMousePosition(PRInt32 x, PRInt32 y) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetMousePosition(x, y); } \
  NS_SCRIPTABLE NS_IMETHOD KeyDownUp(PRInt32 keysym) { return !_to ? NS_ERROR_NULL_POINTER : _to->KeyDownUp(keysym); } \
  NS_SCRIPTABLE NS_IMETHOD MouseClick(PRInt32 button) { return !_to ? NS_ERROR_NULL_POINTER : _to->MouseClick(button); } \
  NS_SCRIPTABLE NS_IMETHOD GetMouseX(PRInt32 *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMouseX(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetMouseY(PRInt32 *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMouseY(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD SendNativeMessage(const char * message) { return !_to ? NS_ERROR_NULL_POINTER : _to->SendNativeMessage(message); } \
  NS_SCRIPTABLE NS_IMETHOD SendClientMessage(PRInt32 clientid, const char * message, PRInt32 *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->SendClientMessage(clientid, message, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD StartWebsocketServer(PRInt32 port) { return !_to ? NS_ERROR_NULL_POINTER : _to->StartWebsocketServer(port); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class _MYCLASS_ : public IMainComponent
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_IMAINCOMPONENT

  _MYCLASS_();

private:
  ~_MYCLASS_();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(_MYCLASS_, IMainComponent)

_MYCLASS_::_MYCLASS_()
{
  /* member initializers and constructor code */
}

_MYCLASS_::~_MYCLASS_()
{
  /* destructor code */
}

/* void Movemouse (in long delx, in long dely); */
NS_IMETHODIMP _MYCLASS_::Movemouse(PRInt32 delx, PRInt32 dely)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void SetMousePosition (in long x, in long y); */
NS_IMETHODIMP _MYCLASS_::SetMousePosition(PRInt32 x, PRInt32 y)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void KeyDownUp (in long keysym); */
NS_IMETHODIMP _MYCLASS_::KeyDownUp(PRInt32 keysym)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void MouseClick (in long button); */
NS_IMETHODIMP _MYCLASS_::MouseClick(PRInt32 button)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* long GetMouseX (); */
NS_IMETHODIMP _MYCLASS_::GetMouseX(PRInt32 *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* long GetMouseY (); */
NS_IMETHODIMP _MYCLASS_::GetMouseY(PRInt32 *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void SendNativeMessage (in string message); */
NS_IMETHODIMP _MYCLASS_::SendNativeMessage(const char * message)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* long SendClientMessage (in long clientid, in string message); */
NS_IMETHODIMP _MYCLASS_::SendClientMessage(PRInt32 clientid, const char * message, PRInt32 *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void StartWebsocketServer (in long port); */
NS_IMETHODIMP _MYCLASS_::StartWebsocketServer(PRInt32 port)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_IMainComponent_h__ */
