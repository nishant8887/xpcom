MODULE		= MozillMK

# Change this to point at your Gecko SDK directory.
GECKO_SDK_PATH ?= $(HOME)/xulrunner-sdk-15

XPIDL	       ?= $(HOME)/xulrunner-sdk-3.6/sdk/bin/xpidl

CXX	       ?= c++

XPIDLSRCS	= \
		MKInt.idl \
		$(NULL)

CPPSRCS		= \
		MKComp.cpp \
		MKCompModule.cpp \
		websocket.cpp  \
		$(NULL)

CPPFLAGS +=     -fno-rtti		\
                -fno-exceptions		\
		-fshort-wchar		\
		-fPIC			\
		-std=c++0x  \
		$(NULL)

# GCC only define which allows us to not have to #include mozilla-config
# in every .cpp file.  If your not using GCC remove this line and add
# #include "mozilla-config.h" to each of your .cpp files.
GECKO_CONFIG_INCLUDE = -include mozilla-config.h

GECKO_DEFINES  = -DMOZILLA_STRICT_API

GECKO_INCLUDES = -I$(GECKO_SDK_PATH)                    \
                 -I$(GECKO_SDK_PATH)/idl                \
                 -I$(GECKO_SDK_PATH)/include            \
                 -I$(GECKO_SDK_PATH)/include/xpcom      \
                 -I$(GECKO_SDK_PATH)/include/nspr       \
                 -I$(GECKO_SDK_PATH)/include/string     \
                 -I$(GECKO_SDK_PATH)/include/embedstring

GECKO_LDFLAGS =  -L$(GECKO_SDK_PATH)/bin \
		 -L$(GECKO_SDK_PATH)/lib \
		 -lxpcomglue_s	\
                 -lnspr4	\
                 -lplds4	\
		 -lxul		\
		 -lX11      \
		 -lXtst     \
		 -lpthread  \
		 -lwebsockets   \
		 -ljsoncpp  \
		 -shared	\
		 $(NULL)

%.h: %.idl
	$(XPIDL) -m header $(GECKO_INCLUDES) $<

%.xpt: %.idl
	$(XPIDL) -m typelib $(GECKO_INCLUDES) $<

%.o: %.cpp Makefile
	$(CXX) -c $(CPPFLAGS) $(CXXFLAGS) $(GECKO_CONFIG_INCLUDE) $(GECKO_DEFINES) $(GECKO_INCLUDES) $<

$(MODULE).so: $(XPIDLSRCS:%.idl=%.h) $(XPIDLSRCS:%.idl=%.xpt) $(CPPSRCS:%.cpp=%.o)
	$(CXX) -o $@ -Wl,-soname=$(MODULE).so $(CPPSRCS:%.cpp=%.o) $(GECKO_LDFLAGS)
	chmod +x $@

build: $(MODULE).so

clean:
	rm $(MODULE).so
