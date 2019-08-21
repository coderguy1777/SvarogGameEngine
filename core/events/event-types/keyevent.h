#pragma once
#ifndef KEYEVENT_H
#define KEYEVENT_H
#include "core/Input/keycodes.h"

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

};

#endif