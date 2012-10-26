GECKO_SDK_PATH ?= $(HOME)/xulrunner-sdk-15

XPIDL	       ?= $(HOME)/xulrunner-sdk-3.6/sdk/bin/xpidl

XPIDLSRCS	= \
		MKJSInt.idl \
		$(NULL)

GECKO_INCLUDES = -I$(GECKO_SDK_PATH)/idl                \

%.h: %.idl
	$(XPIDL) -m header $(GECKO_INCLUDES) $<
	
%.xpt: %.idl
	$(XPIDL) -m typelib $(GECKO_INCLUDES) $<

build: $(XPIDLSRCS:%.idl=%.h) $(XPIDLSRCS:%.idl=%.xpt)
