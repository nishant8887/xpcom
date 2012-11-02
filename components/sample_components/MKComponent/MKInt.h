/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM MKInt.idl
 */

#ifndef __gen_MKInt_h__
#define __gen_MKInt_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    IMKComponent */
#define IMKCOMPONENT_IID_STR "80160f04-f348-11e1-b712-fb5eb71742e1"

#define IMKCOMPONENT_IID \
  {0x80160f04, 0xf348, 0x11e1, \
    { 0xb7, 0x12, 0xfb, 0x5e, 0xb7, 0x17, 0x42, 0xe1 }}

class NS_NO_VTABLE NS_SCRIPTABLE IMKComponent : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(IMKCOMPONENT_IID)

  /* void Movemouse (in long delx, in long dely); */
  NS_SCRIPTABLE NS_IMETHOD Movemouse(PRInt32 delx, PRInt32 dely) = 0;

  /* void SetMousePosition (in long x, in long y); */
  NS_SCRIPTABLE NS_IMETHOD SetMousePosition(PRInt32 x, PRInt32 y) = 0;

  /* void KeyDownUp (in long keysym); */
  NS_SCRIPTABLE NS_IMETHOD KeyDownUp(PRInt32 keysym) = 0;

  /* void KeyDown (in long keysym); */
  NS_SCRIPTABLE NS_IMETHOD KeyDown(PRInt32 keysym) = 0;

  /* void KeyUp (); */
  NS_SCRIPTABLE NS_IMETHOD KeyUp(void) = 0;

  /* void MouseClick (in long button); */
  NS_SCRIPTABLE NS_IMETHOD MouseClick(PRInt32 button) = 0;

  /* void MouseDown (in long button); */
  NS_SCRIPTABLE NS_IMETHOD MouseDown(PRInt32 button) = 0;

  /* void MouseUp (); */
  NS_SCRIPTABLE NS_IMETHOD MouseUp(void) = 0;

  /* long GetMouseX (); */
  NS_SCRIPTABLE NS_IMETHOD GetMouseX(PRInt32 *_retval NS_OUTPARAM) = 0;

  /* long GetMouseY (); */
  NS_SCRIPTABLE NS_IMETHOD GetMouseY(PRInt32 *_retval NS_OUTPARAM) = 0;

  /* void StartWebsocketServer (in long port); */
  NS_SCRIPTABLE NS_IMETHOD StartWebsocketServer(PRInt32 port) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(IMKComponent, IMKCOMPONENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_IMKCOMPONENT \
  NS_SCRIPTABLE NS_IMETHOD Movemouse(PRInt32 delx, PRInt32 dely); \
  NS_SCRIPTABLE NS_IMETHOD SetMousePosition(PRInt32 x, PRInt32 y); \
  NS_SCRIPTABLE NS_IMETHOD KeyDownUp(PRInt32 keysym); \
  NS_SCRIPTABLE NS_IMETHOD KeyDown(PRInt32 keysym); \
  NS_SCRIPTABLE NS_IMETHOD KeyUp(void); \
  NS_SCRIPTABLE NS_IMETHOD MouseClick(PRInt32 button); \
  NS_SCRIPTABLE NS_IMETHOD MouseDown(PRInt32 button); \
  NS_SCRIPTABLE NS_IMETHOD MouseUp(void); \
  NS_SCRIPTABLE NS_IMETHOD GetMouseX(PRInt32 *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetMouseY(PRInt32 *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD StartWebsocketServer(PRInt32 port); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_IMKCOMPONENT(_to) \
  NS_SCRIPTABLE NS_IMETHOD Movemouse(PRInt32 delx, PRInt32 dely) { return _to Movemouse(delx, dely); } \
  NS_SCRIPTABLE NS_IMETHOD SetMousePosition(PRInt32 x, PRInt32 y) { return _to SetMousePosition(x, y); } \
  NS_SCRIPTABLE NS_IMETHOD KeyDownUp(PRInt32 keysym) { return _to KeyDownUp(keysym); } \
  NS_SCRIPTABLE NS_IMETHOD KeyDown(PRInt32 keysym) { return _to KeyDown(keysym); } \
  NS_SCRIPTABLE NS_IMETHOD KeyUp(void) { return _to KeyUp(); } \
  NS_SCRIPTABLE NS_IMETHOD MouseClick(PRInt32 button) { return _to MouseClick(button); } \
  NS_SCRIPTABLE NS_IMETHOD MouseDown(PRInt32 button) { return _to MouseDown(button); } \
  NS_SCRIPTABLE NS_IMETHOD MouseUp(void) { return _to MouseUp(); } \
  NS_SCRIPTABLE NS_IMETHOD GetMouseX(PRInt32 *_retval NS_OUTPARAM) { return _to GetMouseX(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetMouseY(PRInt32 *_retval NS_OUTPARAM) { return _to GetMouseY(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD StartWebsocketServer(PRInt32 port) { return _to StartWebsocketServer(port); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_IMKCOMPONENT(_to) \
  NS_SCRIPTABLE NS_IMETHOD Movemouse(PRInt32 delx, PRInt32 dely) { return !_to ? NS_ERROR_NULL_POINTER : _to->Movemouse(delx, dely); } \
  NS_SCRIPTABLE NS_IMETHOD SetMousePosition(PRInt32 x, PRInt32 y) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetMousePosition(x, y); } \
  NS_SCRIPTABLE NS_IMETHOD KeyDownUp(PRInt32 keysym) { return !_to ? NS_ERROR_NULL_POINTER : _to->KeyDownUp(keysym); } \
  NS_SCRIPTABLE NS_IMETHOD KeyDown(PRInt32 keysym) { return !_to ? NS_ERROR_NULL_POINTER : _to->KeyDown(keysym); } \
  NS_SCRIPTABLE NS_IMETHOD KeyUp(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->KeyUp(); } \
  NS_SCRIPTABLE NS_IMETHOD MouseClick(PRInt32 button) { return !_to ? NS_ERROR_NULL_POINTER : _to->MouseClick(button); } \
  NS_SCRIPTABLE NS_IMETHOD MouseDown(PRInt32 button) { return !_to ? NS_ERROR_NULL_POINTER : _to->MouseDown(button); } \
  NS_SCRIPTABLE NS_IMETHOD MouseUp(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->MouseUp(); } \
  NS_SCRIPTABLE NS_IMETHOD GetMouseX(PRInt32 *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMouseX(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetMouseY(PRInt32 *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMouseY(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD StartWebsocketServer(PRInt32 port) { return !_to ? NS_ERROR_NULL_POINTER : _to->StartWebsocketServer(port); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class _MYCLASS_ : public IMKComponent
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_IMKCOMPONENT

  _MYCLASS_();

private:
  ~_MYCLASS_();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(_MYCLASS_, IMKComponent)

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

/* void KeyDown (in long keysym); */
NS_IMETHODIMP _MYCLASS_::KeyDown(PRInt32 keysym)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void KeyUp (); */
NS_IMETHODIMP _MYCLASS_::KeyUp()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void MouseClick (in long button); */
NS_IMETHODIMP _MYCLASS_::MouseClick(PRInt32 button)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void MouseDown (in long button); */
NS_IMETHODIMP _MYCLASS_::MouseDown(PRInt32 button)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void MouseUp (); */
NS_IMETHODIMP _MYCLASS_::MouseUp()
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

/* void StartWebsocketServer (in long port); */
NS_IMETHODIMP _MYCLASS_::StartWebsocketServer(PRInt32 port)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_MKInt_h__ */
