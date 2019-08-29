#pragma once
#ifdef MOUSEEVENT_H
#define MOUSEEVENT_H
#endif
#include "spdlog/spdlog.h"
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

        struct MouseEventLog {
            Event e;
        } Mouselog;
        
        MouseEventLog* log;
        MouseBind* mouseBt;
    public:
        MouseEvent(unsigned int mse_code, int btn_state) {
            mouseBt = new MouseBind();
            log = new MouseEventLog();
            mouseBt->mouse_code = mse_code;
            mouseBt->state = btn_state; 
        }
        
        void spacer() {
            std::cout << '\n' << std::endl;
        }

        // getters for mouse bind sturct.
        unsigned int get_mse_code() const;
        int get_mse_state() const;
        Event get_mouse_event() const;

        // setters for mouse struct.
        void set_mse_code(unsigned int new_code);
        void set_mse_state(int new_state);
        void set_mse_event(Event e);

        // loggers, getters, setters, etc.
        void logMousePressEvent();
        void logMouseReleaseEvent();
        void logMouseHeldEvent();
        std::string get_state();
        std::string get_curr_button();
};

/*
TODO:
    - design this class to have the same functionallity as the key event class.
    - Evaluate the need for the structs inputted into the mouse event class, key
      event class as well.
    - redesign both keyevent & mouseevent to be functional to the requirements I 
      wrote for both classes.


*/