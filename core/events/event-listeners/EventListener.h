#pragma once 
#ifndef EVENTLISTENER_H
#define EVENTLISTENER_H
#include "core/ds-classes/Array.h"
#include "core/ds-classes/ArrayList.h"
#include "core/events/event-types/mouseevent.h"
#include "core/events/event-types/keyevent.h"
#include <iostream>
#include <cmath>
#include <functional>
#include <algorithm>
#include "KeyListener.h"
#define RECEIVED_EVT 1
#define NOT_RECEIVED_EVT 0

class EventListener {
    private: 
        struct Listener {
            unsigned int evt_get_state;
            bool is_evt;
        } evt_listener;
        KeyListener* listener_evt;
        Listener* event_listener;

    public: 
        EventListener() {
            listener_evt = new KeyListener();
            event_listener = new Listener();
        }
        void set_event_check(bool check);
        void set_event_state(int evt_state);

        bool get_event_check() const;
        int get_event_state() const;
};
#endif
 