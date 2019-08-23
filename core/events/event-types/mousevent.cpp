#include "mouseevent.h"
MouseEvent::MouseEvent() {
    mouseBt = new MouseBind();
}

MouseEvent::~MouseEvent() {
    exit(0);
}