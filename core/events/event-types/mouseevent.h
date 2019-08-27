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
        MouseEvent(unsigned int mse_code, int btn_state) {
            mouseBt = new MouseBind();
            mouseBt->mouse_code = mse_code;
            mouseBt->state = btn_state; 
        }
        ~MouseEvent();
        void spacer() {
            std::cout << '\n' << std::endl;
        }

        // getters for mouse bind sturct.
        unsigned int get_mse_code() const;
        int get_mse_state() const;

        // setters for mouse struct.
        void set_mse_code(unsigned int new_code);
        void set_mse_state(int new_state);


        // loggers, getters, setters, etc.
        void logMousePressEvent();
        void logMouseReleaseEvent();
        void logMouseHeldEvent();
        std::string get_state();
        std::string get_curr_button();
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