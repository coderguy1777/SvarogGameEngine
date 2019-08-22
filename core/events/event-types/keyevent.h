#pragma once
#ifndef KEYEVENT_H
#define KEYEVENT_H
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

struct KeyBind {
    char key;
    unsigned int ascii_code;
} Key;

class KeyEvent {
    private:
    WindowInput* input = new WindowInput();

        String *log;
        KeyBind *keyBt;
    public:
        KeyEvent(unsigned int code, char keyChar) {
            keyBt->key = keyChar;
            keyBt->ascii_code = code;
        }

        char get_keybind_char() const {
            return keyBt->key;
        }

        unsigned int get_keybind_ascii_code() const {
            return keyBt->ascii_code;
        }

        void set_keybind_char(char newCharKey) {
            keyBt->key = newCharKey;
        }

        void set_keybind_ascii_code(unsigned int new_ascii_code) {
            keyBt->ascii_code = new_ascii_code;
        }

        inline int getKeyCode();
        String* logKeyPressEvent(Event e, int state);
        String* logKeyReleaseEvent(Event e, int state);
        String* logKeyHeldEvent(Event e, int state);
        String* logKeyRepeatEvent(Event e, int state);
};

#endif