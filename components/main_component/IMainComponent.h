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

class NS_NO_VTABLE IMainComponent : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(IMAINCOMPONENT_IID)

  /* void Movemouse (in long delx, in long dely); */
  NS_IMETHOD Movemouse(int32_t delx, int32_t dely) = 0;

  /* void SetMousePosition (in long x, in long y); */
  NS_IMETHOD SetMousePosition(int32_t x, int32_t y) = 0;

  /* void KeyDownUp (in long keysym); */
  NS_IMETHOD KeyDownUp(int32_t keysym) = 0;

  /* void MouseClick (in long button); */
  NS_IMETHOD MouseClick(int32_t button) = 0;

  /* long GetMouseX (); */
  NS_IMETHOD GetMouseX(int32_t *_retval) = 0;

  /* long GetMouseY (); */
  NS_IMETHOD GetMouseY(int32_t *_retval) = 0;

  /* void SendNativeMessage (in string message); */
  NS_IMETHOD SendNativeMessage(const char * message) = 0;

  /* long SendClientMessage (in long clientid, in string message); */
  NS_IMETHOD SendClientMessage(int32_t clientid, const char * message, int32_t *_retval) = 0;

  /* void StartWebsocketServer (in long port); */
  NS_IMETHOD StartWebsocketServer(int32_t port) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(IMainComponent, IMAINCOMPONENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_IMAINCOMPONENT \
  NS_IMETHOD Movemouse(int32_t delx, int32_t dely); \
  NS_IMETHOD SetMousePosition(int32_t x, int32_t y); \
  NS_IMETHOD KeyDownUp(int32_t keysym); \
  NS_IMETHOD MouseClick(int32_t button); \
  NS_IMETHOD GetMouseX(int32_t *_retval); \
  NS_IMETHOD GetMouseY(int32_t *_retval); \
  NS_IMETHOD SendNativeMessage(const char * message); \
  NS_IMETHOD SendClientMessage(int32_t clientid, const char * message, int32_t *_retval); \
  NS_IMETHOD StartWebsocketServer(int32_t port); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_IMAINCOMPONENT(_to) \
  NS_IMETHOD Movemouse(int32_t delx, int32_t dely) { return _to Movemouse(delx, dely); } \
  NS_IMETHOD SetMousePosition(int32_t x, int32_t y) { return _to SetMousePosition(x, y); } \
  NS_IMETHOD KeyDownUp(int32_t keysym) { return _to KeyDownUp(keysym); } \
  NS_IMETHOD MouseClick(int32_t button) { return _to MouseClick(button); } \
  NS_IMETHOD GetMouseX(int32_t *_retval) { return _to GetMouseX(_retval); } \
  NS_IMETHOD GetMouseY(int32_t *_retval) { return _to GetMouseY(_retval); } \
  NS_IMETHOD SendNativeMessage(const char * message) { return _to SendNativeMessage(message); } \
  NS_IMETHOD SendClientMessage(int32_t clientid, const char * message, int32_t *_retval) { return _to SendClientMessage(clientid, message, _retval); } \
  NS_IMETHOD StartWebsocketServer(int32_t port) { return _to StartWebsocketServer(port); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_IMAINCOMPONENT(_to) \
  NS_IMETHOD Movemouse(int32_t delx, int32_t dely) { return !_to ? NS_ERROR_NULL_POINTER : _to->Movemouse(delx, dely); } \
  NS_IMETHOD SetMousePosition(int32_t x, int32_t y) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetMousePosition(x, y); } \
  NS_IMETHOD KeyDownUp(int32_t keysym) { return !_to ? NS_ERROR_NULL_POINTER : _to->KeyDownUp(keysym); } \
  NS_IMETHOD MouseClick(int32_t button) { return !_to ? NS_ERROR_NULL_POINTER : _to->MouseClick(button); } \
  NS_IMETHOD GetMouseX(int32_t *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMouseX(_retval); } \
  NS_IMETHOD GetMouseY(int32_t *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMouseY(_retval); } \
  NS_IMETHOD SendNativeMessage(const char * message) { return !_to ? NS_ERROR_NULL_POINTER : _to->SendNativeMessage(message); } \
  NS_IMETHOD SendClientMessage(int32_t clientid, const char * message, int32_t *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->SendClientMessage(clientid, message, _retval); } \
  NS_IMETHOD StartWebsocketServer(int32_t port) { return !_to ? NS_ERROR_NULL_POINTER : _to->StartWebsocketServer(port); } 

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
NS_IMETHODIMP _MYCLASS_::Movemouse(int32_t delx, int32_t dely)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void SetMousePosition (in long x, in long y); */
NS_IMETHODIMP _MYCLASS_::SetMousePosition(int32_t x, int32_t y)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void KeyDownUp (in long keysym); */
NS_IMETHODIMP _MYCLASS_::KeyDownUp(int32_t keysym)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void MouseClick (in long button); */
NS_IMETHODIMP _MYCLASS_::MouseClick(int32_t button)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* long GetMouseX (); */
NS_IMETHODIMP _MYCLASS_::GetMouseX(int32_t *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* long GetMouseY (); */
NS_IMETHODIMP _MYCLASS_::GetMouseY(int32_t *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void SendNativeMessage (in string message); */
NS_IMETHODIMP _MYCLASS_::SendNativeMessage(const char * message)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* long SendClientMessage (in long clientid, in string message); */
NS_IMETHODIMP _MYCLASS_::SendClientMessage(int32_t clientid, const char * message, int32_t *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void StartWebsocketServer (in long port); */
NS_IMETHODIMP _MYCLASS_::StartWebsocketServer(int32_t port)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_IMainComponent_h__ */
