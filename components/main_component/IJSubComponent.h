/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM IJSubComponent.idl
 */

#ifndef __gen_IJSubComponent_h__
#define __gen_IJSubComponent_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    IJSubComponent */
#define IJSUBCOMPONENT_IID_STR "2688fa8a-2a7c-11e2-86f4-0026220fb69d"

#define IJSUBCOMPONENT_IID \
  {0x2688fa8a, 0x2a7c, 0x11e2, \
    { 0x86, 0xf4, 0x00, 0x26, 0x22, 0x0f, 0xb6, 0x9d }}

class NS_NO_VTABLE NS_SCRIPTABLE IJSubComponent : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(IJSUBCOMPONENT_IID)

  /* void Log (in ACString logmsg); */
  NS_SCRIPTABLE NS_IMETHOD Log(const nsACString & logmsg) = 0;

  /* void RaiseEvent (in ACString evtmsg); */
  NS_SCRIPTABLE NS_IMETHOD RaiseEvent(const nsACString & evtmsg) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(IJSubComponent, IJSUBCOMPONENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_IJSUBCOMPONENT \
  NS_SCRIPTABLE NS_IMETHOD Log(const nsACString & logmsg); \
  NS_SCRIPTABLE NS_IMETHOD RaiseEvent(const nsACString & evtmsg); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_IJSUBCOMPONENT(_to) \
  NS_SCRIPTABLE NS_IMETHOD Log(const nsACString & logmsg) { return _to Log(logmsg); } \
  NS_SCRIPTABLE NS_IMETHOD RaiseEvent(const nsACString & evtmsg) { return _to RaiseEvent(evtmsg); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_IJSUBCOMPONENT(_to) \
  NS_SCRIPTABLE NS_IMETHOD Log(const nsACString & logmsg) { return !_to ? NS_ERROR_NULL_POINTER : _to->Log(logmsg); } \
  NS_SCRIPTABLE NS_IMETHOD RaiseEvent(const nsACString & evtmsg) { return !_to ? NS_ERROR_NULL_POINTER : _to->RaiseEvent(evtmsg); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class _MYCLASS_ : public IJSubComponent
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_IJSUBCOMPONENT

  _MYCLASS_();

private:
  ~_MYCLASS_();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(_MYCLASS_, IJSubComponent)

_MYCLASS_::_MYCLASS_()
{
  /* member initializers and constructor code */
}

_MYCLASS_::~_MYCLASS_()
{
  /* destructor code */
}

/* void Log (in ACString logmsg); */
NS_IMETHODIMP _MYCLASS_::Log(const nsACString & logmsg)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void RaiseEvent (in ACString evtmsg); */
NS_IMETHODIMP _MYCLASS_::RaiseEvent(const nsACString & evtmsg)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_IJSubComponent_h__ */
