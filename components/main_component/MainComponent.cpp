#include "MainComponent.h"
#include "CommWebsocket.h"
#include "nsThreadUtils.h"

/* Implementation file */
NS_IMPL_ISUPPORTS1(MainComponent, IMainComponent)

MainComponent::MainComponent()
{
  /* member initializers and constructor code */
    display = XOpenDisplay(0);
    serverstarted = false;
    jsutils = do_GetService("@gigatech.com/jsubcomponent;1");
}

MainComponent::~MainComponent()
{
  /* destructor code */
    XCloseDisplay(display);
}

/* void Movemouse (in long delx, in long dely); */
NS_IMETHODIMP MainComponent::Movemouse(PRInt32 delx, PRInt32 dely)
{
    XTestFakeRelativeMotionEvent(display, delx, dely, CurrentTime);
    XSync(display,0);
    return NS_OK;
}

/* void SetMousePosition (in long x, in long y); */
NS_IMETHODIMP MainComponent::SetMousePosition(PRInt32 x, PRInt32 y)
{
    XTestFakeMotionEvent(display, 0, x, y, CurrentTime);
    XSync(display,0);
    return NS_OK;
}

/* void KeyDownUp (in long keysym); */
NS_IMETHODIMP MainComponent::KeyDownUp(PRInt32 keysym)
{
    KeyCode keycode;
    long is_shift;
    GetKeys(keycode, is_shift, keysym);
    
    if(is_shift) XTestFakeKeyEvent(display, KEY_SHIFT, True, 0);
    XTestFakeKeyEvent(display, keycode, True, 0);
    XTestFakeKeyEvent(display, keycode, False, 0);
    if(is_shift) XTestFakeKeyEvent(display, KEY_SHIFT, False, 0);
    
    XSync(display,0);
    return NS_OK;
}

/* void MouseClick (in long button); */
NS_IMETHODIMP MainComponent::MouseClick(PRInt32 button)
{
    XTestFakeButtonEvent(display, button, True, CurrentTime);
    XTestFakeButtonEvent(display, button, False, CurrentTime);
    XSync(display,0);
    return NS_OK;
}

/* long GetMouseX (); */
NS_IMETHODIMP MainComponent::GetMouseX(PRInt32 *_retval)
{
    XEvent event;
    XQueryPointer(display, RootWindow(display, DefaultScreen(display)),&event.xbutton.root, &event.xbutton.window, &event.xbutton.x_root, &event.xbutton.y_root, &event.xbutton.x, &event.xbutton.y, &event.xbutton.state);
    *_retval = event.xbutton.x_root;
    return NS_OK;
}

/* long GetMouseY (); */
NS_IMETHODIMP MainComponent::GetMouseY(PRInt32 *_retval)
{
    XEvent event;
    XQueryPointer(display, RootWindow(display, DefaultScreen(display)),&event.xbutton.root, &event.xbutton.window, &event.xbutton.x_root, &event.xbutton.y_root, &event.xbutton.x, &event.xbutton.y, &event.xbutton.state);
    *_retval = event.xbutton.y_root;
    return NS_OK;
}

/* void SendNativeMessage (in string message); */
NS_IMETHODIMP MainComponent::SendNativeMessage(const char * message)
{
    cout << "Native message received. -> " << message << endl;
    return NS_OK;
}

/* long SendClientMessage (in long clientid, in string message); */
NS_IMETHODIMP MainComponent::SendClientMessage(PRInt32 clientid, const char * message, PRInt32 *_retval)
{
    if(!serverstarted) return NS_OK;

    ostringstream jsonmsg;
    jsonmsg << "{ \"message\": " << message << ", \"client\": \"" << clientid << "\" }";
    wss->SendMessage(jsonmsg.str());
    return NS_OK;
}

/* void StartWebsocketServer (in long port); */
NS_IMETHODIMP MainComponent::StartWebsocketServer(PRInt32 port)
{
    if(serverstarted) return NS_OK;
    
    wss = new WebsocketServer(this, port);
    wss->start();
    return NS_OK;
}

/* Local functions */
void MainComponent::GetKeys(KeyCode &keycode, long &is_shift, KeySym keysym)
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

void MainComponent::SendServerMessage()
{
    //nsCString msgdata(gtservermessage.str().c_str(), gtservermessage.str().length());
    //jsutils->RaiseEvent(msgdata);
}

/* End of implementation class template. */