/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM MKJSInt.idl
 */

#ifndef __gen_MKJSInt_h__
#define __gen_MKJSInt_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    IMKJSComponent */
#define IMKJSCOMPONENT_IID_STR "3ef9d0d6-0e1a-11e2-9f83-770cf8d9c752"

#define IMKJSCOMPONENT_IID \
  {0x3ef9d0d6, 0x0e1a, 0x11e2, \
    { 0x9f, 0x83, 0x77, 0x0c, 0xf8, 0xd9, 0xc7, 0x52 }}

class NS_NO_VTABLE NS_SCRIPTABLE IMKJSComponent : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(IMKJSCOMPONENT_IID)

  /* void Log (in ACString msg); */
  NS_SCRIPTABLE NS_IMETHOD Log(const nsACString & msg) = 0;

  /* void RaiseEvent (in ACString eventmsg); */
  NS_SCRIPTABLE NS_IMETHOD RaiseEvent(const nsACString & eventmsg) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(IMKJSComponent, IMKJSCOMPONENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_IMKJSCOMPONENT \
  NS_SCRIPTABLE NS_IMETHOD Log(const nsACString & msg); \
  NS_SCRIPTABLE NS_IMETHOD RaiseEvent(const nsACString & eventmsg); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_IMKJSCOMPONENT(_to) \
  NS_SCRIPTABLE NS_IMETHOD Log(const nsACString & msg) { return _to Log(msg); } \
  NS_SCRIPTABLE NS_IMETHOD RaiseEvent(const nsACString & eventmsg) { return _to RaiseEvent(eventmsg); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_IMKJSCOMPONENT(_to) \
  NS_SCRIPTABLE NS_IMETHOD Log(const nsACString & msg) { return !_to ? NS_ERROR_NULL_POINTER : _to->Log(msg); } \
  NS_SCRIPTABLE NS_IMETHOD RaiseEvent(const nsACString & eventmsg) { return !_to ? NS_ERROR_NULL_POINTER : _to->RaiseEvent(eventmsg); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class _MYCLASS_ : public IMKJSComponent
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_IMKJSCOMPONENT

  _MYCLASS_();

private:
  ~_MYCLASS_();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(_MYCLASS_, IMKJSComponent)

_MYCLASS_::_MYCLASS_()
{
  /* member initializers and constructor code */
}

_MYCLASS_::~_MYCLASS_()
{
  /* destructor code */
}

/* void Log (in ACString msg); */
NS_IMETHODIMP _MYCLASS_::Log(const nsACString & msg)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void RaiseEvent (in ACString eventmsg); */
NS_IMETHODIMP _MYCLASS_::RaiseEvent(const nsACString & eventmsg)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_MKJSInt_h__ */
