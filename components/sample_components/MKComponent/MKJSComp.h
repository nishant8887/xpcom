#ifndef __gen_MKJSComp_h__
#define __gen_MKJSComp_h__

#include "MKJSInt.h"
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class MKJSComponent : public IMKJSComponent
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_IMKJSCOMPONENT

  MKJSComponent();

private:
  ~MKJSComponent();

protected:
  /* additional members */
};
#endif
