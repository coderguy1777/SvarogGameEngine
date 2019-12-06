#pragma once
#ifndef MOUSEEVENT_H
#define MOUSEEVENT_H
#include "spdlog/spdlog.h"
#include "core/Input/mousecodes.h"
#include "core/events/Event.h"

enum class mouse_evt_types {
    MOUSE_PRESS_EVT = 1, 
    MOUSE_RELEASE_EVT = 2,
    MOUSE_HELD_EVT = 3
};
class MouseEvent {
    private:
        struct MouseBind {
            unsigned int mouse_code;
            int state;
        } MouseBT;

        struct MouseEventLog {
            Event e;
            unsigned int mouse_sub_evt_type;
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

        MouseEvent() {
            mouseBt = new MouseBind();
            log = new MouseEventLog();
        }

        // getters for mouse bind sturct.
        unsigned int get_mse_code() const;
        int get_mse_state() const;
        unsigned int get_mse_evt_type() const;
        Event get_mouse_event() const;

        // setters for mouse struct.
        void set_mse_code(unsigned int new_code);
        void set_mse_state(int new_state);
        void set_mse_event(Event e);
        void set_mse_sub_evt_type(unsigned int evt_type);

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