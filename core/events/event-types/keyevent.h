#pragma once
#ifdef KEYEVENT_H
#define KEYEVENT_H
#endif
#include <string>
#include "core/String.h"
#include "core/Input/keycodes.h"
#include "core/events/Event.h"
#include "core/Input/WindowInput.h"
enum class KeyEventTypes {
    KEY_PRESS_EVT,
    KEY_HELD_EVT,
    KEY_RELEASED_EVT,
    KEY_DOUBLE_PRESS_EVT,
};

class KeyEvent {
    private: 
        struct KeyBind {
            char key;
            unsigned int ascii_code;
        } Keybt;

        struct KeyEventInfo {
            Event keyevt;
            unsigned int key_State;
        } KeyLog;

    private:
        WindowInput* input;
        KeyEventInfo* log;
        KeyBind* keyBt;
    public:
        KeyEvent(){}
        KeyEvent(unsigned int code) {
            keyBt = new KeyBind();
            log = new KeyEventInfo();
            input = new WindowInput();
            keyBt->key = get_keycode_char(code);
            keyBt->ascii_code = code;
        }

        void spacer() {
            std::cout << '\n' << std::endl;
        }
        
        char get_keybind_char() const {
            return keyBt->key;
        }

        unsigned int get_keybind_ascii_code() const {
            return keyBt->ascii_code;
        }

        Event get_key_evt() const {
            return log->keyevt;
        }

        unsigned int get_key_evt_state() const {
            return log->key_State;
        }

        void set_keybind_char(char newCharKey) {
            keyBt->key = newCharKey;
            free(keyBt);
        }

        void set_keybind_ascii_code(unsigned int new_ascii_code) {
            keyBt->ascii_code = new_ascii_code;
            free(keyBt);
        }

        void set_key_evt_event(Event evt) {
            log->keyevt.setEventType(evt.get_typeof_event());
            log->keyevt.setPriority(evt.get_priority());
            log->keyevt.setCause(evt.get_cause());
        }

        void set_key_evt_state(unsigned int new_state) {
            log->key_State = new_state;
        }

        // TODO: make these methods not cause seg faults,
        // and log in the form of the keyeventlog struct.
        void logKeyPressEvent();
        void logKeyReleaseEvent();
        void logKeyHeldEvent();
        void logKeyRepeatEvent();
        std::string get_state();
        char get_keycode_char(unsigned int code);
};

/*
Finished: 
Setters and getters for the class, mostly, may have to configure some kind of 
way to gen KeyEventLogs.

WIP:
logger methods, which will be switched over to key event log structs 

TODO:
    - Make a method to do generate event logs, also make these events added to
      an event dispatcher, which will make the key event known throughout the engine.
    - Also to add a way to add it to an application event layer, to process it in the engine
      itself when running.
    - bind it together with some kind of keymap class, tbd to the design of it.
    - clean up the logging methods to be more clean.
*/