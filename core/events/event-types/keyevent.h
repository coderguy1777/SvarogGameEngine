#pragma once
#ifdef KEYEVENT_H
#define KEYEVENT_H
#endif
#include <string>
#include <functional>
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include "core/String.h"
#include "core/Input/keycodes.h"
#include "core/events/Event.h"
enum class KeyEventTypes {
    KEY_PRESS_EVT,
    KEY_HELD_EVT,
    KEY_RELEASED_EVT,
    KEY_DOUBLE_PRESS_EVT,
};

class KeyEvent {
    private: 
        struct KeyBind {
            std::string key;
            unsigned int ascii_code;
        } Keybt;

        struct KeyEventInfo {
            Event keyevt;
            unsigned int key_State;
            KeyBind key_id;
        } KeyLog;

        struct KeyPressedEvent {
            KeyBind key_loc;
            const unsigned int key_state = 1;
            KeyEventInfo info;
        } key_press;

        struct KeyHeldEvent {
            KeyBind key_loc;
            const unsigned int key_state = 2;
            KeyEventInfo info;
        } key_held;

        struct KeyReleaseEvent {
            KeyBind key_loc;
            const unsigned int key_state = 3;
            KeyEventInfo info;
        } key_release;

    private:
        KeyEventInfo* log;
        KeyBind* keyBt;
    public:
        KeyEvent(){}
        KeyEvent(unsigned int code) {
            keyBt = new KeyBind();
            log = new KeyEventInfo();
            keyBt->key = get_keycode_char(code);
            keyBt->ascii_code = code;
        }
        
        KeyBind get_keybind() const {
            return log->key_id;
        }
        
        std::string get_keybind_char() const {
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

        void set_key_evt_bind(KeyBind bind) {
            log->key_id.ascii_code = bind.ascii_code;
            log->key_id.key = bind.key;
        }

        // TODO: make these methods not cause seg faults,
        // and log in the form of the keyeventlog struct.
        void logKeyPressEvent();
        void logKeyReleaseEvent();
        void logKeyHeldEvent();
        void logKeyRepeatEvent();
        std::string get_state();
        std::string get_keycode_char(unsigned int code);
};

/*
Finished: 
Setters and getters for the class, mostly, may have to configure some kind of 
way to gen KeyEventLogs.
logger methods, which will be switched over to key event log structs (now done).

TODO:
    - Make a method to do generate event logs, also make these events added to
      an event dispatcher, which will make the key event known throughout the engine.
    - Also to add a way to add it to an EngineWindow event layer, to process it in the engine
      itself when running.
    - bind it together with some kind of keymap class, tbd to the design of it.
    - clean up the logging methods to be more clean.
*/