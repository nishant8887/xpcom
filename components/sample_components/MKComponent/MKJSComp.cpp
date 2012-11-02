/* Implementation file */
#include "MKJSComp.h"
NS_IMPL_ISUPPORTS1(MKJSComponent, IMKJSComponent)

MKJSComponent::MKJSComponent()
{
  /* member initializers and constructor code */
}

MKJSComponent::~MKJSComponent()
{
  /* destructor code */
}

/* void Log (in ACString msg); */
NS_IMETHODIMP MKJSComponent::Log(const nsACString & msg)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void RaiseEvent (in ACString eventmsg); */
NS_IMETHODIMP _MYCLASS_::RaiseEvent(const nsACString & eventmsg)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
