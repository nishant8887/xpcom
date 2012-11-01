VER		= 15
GECKO_SDK_PATH ?= ../../../xulrunner-sdk-$(VER)

XPIDL	       ?= $(GECKO_SDK_PATH)/sdk/bin

XPIDLSRCS	= \
		MKJSInt.idl \
		$(NULL)

GECKO_INCLUDES = -I$(GECKO_SDK_PATH)/idl                \

%.h: %.idl
	python $(XPIDL)/header.py $(GECKO_INCLUDES) -o $@ $<
	
%.xpt: %.idl
	python $(XPIDL)/typelib.py $(GECKO_INCLUDES) -o $@ $<

build: $(XPIDLSRCS:%.idl=%.h) $(XPIDLSRCS:%.idl=%.xpt)

clean:
	rm *.xpt
