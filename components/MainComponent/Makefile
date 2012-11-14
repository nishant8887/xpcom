MODULE		= MozillMK

VER		= 15
# Change this to point at your Gecko SDK directory.
GECKO_SDK_PATH ?= ../../../xulrunner-sdk-$(VER)

XPIDL	       ?= $(GECKO_SDK_PATH)/sdk/bin

CXX	       ?= c++

XPIDLSRCS	= \
		IMainComponent.idl \
		IJSubComponent.idl \
		$(NULL)

CPPSRCS		= \
		MainComponent.cpp \
		CommWebsocket.cpp \
		MainModule.cpp \
		$(NULL)

CPPFLAGS +=     -fno-rtti		\
                -fno-exceptions		\
		-fshort-wchar		\
		-fPIC			\
		-fvisibility=hidden	\
		-std=c++0x	\
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
	python $(XPIDL)/header.py $(GECKO_INCLUDES) -o $@ $<

%.xpt: %.idl
	python $(XPIDL)/typelib.py $(GECKO_INCLUDES) -o $@ $<

%.o: %.cpp Makefile
	$(CXX) -c $(CPPFLAGS) $(CXXFLAGS) $(GECKO_CONFIG_INCLUDE) $(GECKO_DEFINES) $(GECKO_INCLUDES) $<

$(MODULE).so: $(XPIDLSRCS:%.idl=%.h) $(XPIDLSRCS:%.idl=%.xpt) $(CPPSRCS:%.cpp=%.o)
	$(CXX) -o $@ -Wl,-soname=$(MODULE).so $(CPPSRCS:%.cpp=%.o) $(GECKO_LDFLAGS)
	chmod +x $@

build: $(MODULE).so

clean:
	rm *.xpt
	rm *.o
	rm $(MODULE).so
