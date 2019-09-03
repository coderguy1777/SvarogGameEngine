#include "EventListener.h"
int EventListener::get_event_state() const {
    return event_listener->evt_get_state;
}

bool EventListener::get_event_check() const {
    return event_listener->is_evt;
}

void EventListener::set_event_check(bool check) {
    event_listener->is_evt = check;
}

void EventListener::set_event_state(int state) {
    event_listener->evt_get_state = state;
}