#include "Event.h"
void Event::setCause(const char* causee) {
    cause = causee;
}

void Event::setEventType(EVENT_TYPE typee) {
    evt_type=typee;
}

void Event::setPriority(int pri) {
    PRIORITY = pri;
}

EVENT_TYPE Event::get_typeof_event() const {
    return evt_type;
}

int Event::get_priority() const {
    return PRIORITY;
}

const char* Event::get_cause() const {
    return cause;
}

bool Event::findQueue() {
    // TODO: Make queue finding system
}

std::ostream& operator<<(std::ostream& os, const Event &event) {
    os << event.evt_type << '\"' << event.PRIORITY << '\"' << event.cause << '\"';
    return os;
}
