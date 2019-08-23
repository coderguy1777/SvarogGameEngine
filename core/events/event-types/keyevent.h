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

        struct KeyEventLog {
            Array<string>keyinfo;
            Array<const char*>eventinfo;
            KeyEventTypes keyevt_type;
        } KeyLog;

    private:
        WindowInput* input;
        String log;
        KeyBind *keyBt;
    public:
        KeyEvent(){}
        KeyEvent(unsigned int code, char keyChar) {
            keyBt = new KeyBind();
            keyBt->key = keyChar;
            keyBt->ascii_code = code;
            input = new WindowInput();
        }

        char findKeyChar(unsigned int code);
        char get_keybind_char() const {
            return keyBt->key;
        }

        String get_log() {
            return log;
        }
        unsigned int get_keybind_ascii_code() const {
            return keyBt->ascii_code;
        }

        void set_keybind_char(char newCharKey) {
            keyBt->key = newCharKey;
            free(keyBt);
        }

        void set_keybind_ascii_code(unsigned int new_ascii_code) {
            keyBt->ascii_code = new_ascii_code;
            free(keyBt);
        }

        // TODO: make these methods not cause seg faults,
        // and log in the form of the keyeventlog struct.
        String logKeyPressEvent(Event e, int state);
        void logKeyReleaseEvent(Event e, int state);
        void logKeyHeldEvent(Event e, int state);
        void logKeyRepeatEvent(Event e, int state);
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
    - bind it together with some


*/