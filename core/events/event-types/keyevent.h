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
        }

        void set_keybind_ascii_code(unsigned int new_ascii_code) {
            keyBt->ascii_code = new_ascii_code;
            free(keyBt);
        }

        inline int getKeyCode();
        String logKeyPressEvent(Event e, int state);
        void logKeyReleaseEvent(Event e, int state);
        void logKeyHeldEvent(Event e, int state);
        void logKeyRepeatEvent(Event e, int state);
};
