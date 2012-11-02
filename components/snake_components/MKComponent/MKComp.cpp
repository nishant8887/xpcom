/* Implementation file */
#include "MKComp.h"
#include "websocket.h"

#define LOG(X) jsutils->Log(NS_LITERAL_CSTRING(X));
/* Implementation file */
NS_IMPL_ISUPPORTS1(MKComponent, IMKComponent)

MKComponent::MKComponent()
{
  /* member initializers and constructor code */
  display = XOpenDisplay(0);
  jsutils = do_GetService("@snapstick.com/mkjscomponent;1");
}

MKComponent::~MKComponent()
{
  /* destructor code */
  XCloseDisplay(display);
}

/* void Movemouse (in long delx, in long dely); */
NS_IMETHODIMP MKComponent::Movemouse(PRInt32 delx, PRInt32 dely)
{
    XTestFakeRelativeMotionEvent(display, delx, dely, CurrentTime);
    XSync(display,0);
    return NS_OK;
}

/* void SetMousePosition (in long x, in long y); */
NS_IMETHODIMP MKComponent::SetMousePosition(PRInt32 x, PRInt32 y)
{
	XTestFakeMotionEvent(display, 0, x, y, CurrentTime);
	XSync(display,0);
    return NS_OK;
}

/* void KeyDownUp (in long keysym); */
NS_IMETHODIMP MKComponent::KeyDownUp(PRInt32 keysym)
{
    KeyCode keycode;
    long is_shift;
    getkeys(keycode, is_shift, keysym);
    
    if(is_shift) XTestFakeKeyEvent(display, KEY_SHIFT, True, 0);
    XTestFakeKeyEvent(display, keycode, True, 0);
    XTestFakeKeyEvent(display, keycode, False, 0);
    if(is_shift) XTestFakeKeyEvent(display, KEY_SHIFT, False, 0);
    
	XSync(display,0);
    return NS_OK;
}

/* void KeyDown (in long keycode); */
NS_IMETHODIMP MKComponent::KeyDown(PRInt32 keysym)
{
    KeyCode keycode = XKeysymToKeycode(display, keysym);
	XTestFakeKeyEvent(display, keycode, True, 0);
	pressedkey = keycode;
    return NS_OK;
}

/* void KeyUp (); */
NS_IMETHODIMP MKComponent::KeyUp()
{
	XTestFakeKeyEvent(display, pressedkey, False, 0);
    return NS_OK;
}

/* void MouseClick (in long button); */
NS_IMETHODIMP MKComponent::MouseClick(PRInt32 button)
{   
    XTestFakeButtonEvent(display, button, True, CurrentTime);
    XTestFakeButtonEvent(display, button, False, CurrentTime);
   	XSync(display,0);
    return NS_OK;
}

/* void MouseDown (in long button); */
NS_IMETHODIMP MKComponent::MouseDown(PRInt32 button)
{
    XTestFakeButtonEvent(display, button, True, CurrentTime);
    clickedbutton = button;
    return NS_OK;
}

/* void MouseUp (); */
NS_IMETHODIMP MKComponent::MouseUp()
{
    XTestFakeButtonEvent(display, clickedbutton, False, CurrentTime);
    return NS_OK;
}

/* long GetMouseX (); */
NS_IMETHODIMP MKComponent::GetMouseX(PRInt32 *_retval NS_OUTPARAM)
{
    XEvent event;
    XQueryPointer(display, RootWindow(display, DefaultScreen(display)),&event.xbutton.root, &event.xbutton.window, &event.xbutton.x_root, &event.xbutton.y_root, &event.xbutton.x, &event.xbutton.y, &event.xbutton.state);
    *_retval = event.xbutton.x_root;
    return NS_OK;
}

/* long GetMouseY (); */
NS_IMETHODIMP MKComponent::GetMouseY(PRInt32 *_retval NS_OUTPARAM)
{
    XEvent event;
    XQueryPointer(display, RootWindow(display, DefaultScreen(display)),&event.xbutton.root, &event.xbutton.window, &event.xbutton.x_root, &event.xbutton.y_root, &event.xbutton.x, &event.xbutton.y, &event.xbutton.state);
    *_retval = event.xbutton.y_root;
    return NS_OK;
}

/* Local functions */
void MKComponent::getkeys(KeyCode &keycode, long &is_shift, KeySym keysym)
{
    if((keysym >= 65) && (keysym <= 90))
    {
        is_shift = 1;
    }
    else
    {
        switch(keysym)
        {
            case 33:    case 64:    case 35:    case 36:    case 37:    case 94:    case 38:
            case 42:    case 40:    case 41:    case 60:    case 58:    case 43:    case 95:
            case 62:    case 63:    case 126:    case 123:    case 124:    case 125:    case 34:
                is_shift = 1;
                break;
            default:
                is_shift = 0;
        }
    }
    
    if (keysym == 60) {
        keysym = 44;
    } else if (keysym == 13) {
        keysym = 65293;
    } else if (keysym == 8) {
        keysym = 65288;
    } else if (keysym == 163) {
        keysym = 32;
    } else if (keysym == 165) {
        keysym = 32;
    } else if (keysym == 8226) {
        keysym = 32;
    } else if (keysym == 8364) {
        keysym = 32;
    }
    
    keycode = XKeysymToKeycode(display, keysym);
}

/* void StartWebsocketServer (in long port); */
NS_IMETHODIMP MKComponent::StartWebsocketServer(PRInt32 port)
{
    wss = new WebsocketServer(this);
    wss->port = port;
    wss->start();
    
    LOG("Webserver has started...");
    return NS_OK;
}

void MKComponent::SendEventToDOM(std::string evtstr, int client)
{
    this->eventmessage.str(std::string());
    this->eventmessage << "{ \"type\": \"" << evtstr << "\", \"clientid\": " << client << " }\0";

    //nsresult rv;
    //nsCOMPtr<IMKJSComponent>
    //localjsutils = do_CreateInstance("@snapstick.com/mkjscomponent;1", &rv);
    //if (NS_FAILED(rv))
    //return;    
}

void MKComponent::ExecuteEvent()
{
    nsCString eventdata(eventmessage.str().c_str(), eventmessage.str().length());
    jsutils->RaiseEvent(eventdata);
}

/* End of implementation class template. */
