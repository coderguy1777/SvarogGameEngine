#pragma once
#ifndef MOUSEEVENT_H
#define MOUSEEVENT_H
#include "core/Input/mousecodes.h"
#include "core/events/Event.h"
#include "core/ds-classes/Array.h"
#include "core/Input/WindowMouseInput.h"

class MouseEvent {
    private:
        struct MouseBind {
            unsigned int mouse_code;
            int state;
        } MouseBT;
        MouseBind* mouseBt;
    public:
        MouseEvent();
        ~MouseEvent();
};
#endif

/*
TODO:
    - design this class to have the same functionallity as the key event class.
    - Evaluate the need for the structs inputted into the mouse event class, key
      event class as well.
    - redesign both keyevent & mouseevent to be functional to the requirements I 
      wrote for both classes.


*/