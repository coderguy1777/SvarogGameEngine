#include "Event.h"
template<class E>
EVENT_TYPE Event<E>::get_typeof_event() const {
    return evt_type;
}

template<class E>
int Event<E>::get_priority() const {
    return PRIORITY;
}

template<class E>
const char* Event<E>::get_cause() const {
    return cause;
}