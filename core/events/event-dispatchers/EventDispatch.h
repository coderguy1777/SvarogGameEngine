#pragma once 
#ifndef EVENTDISPATCH_H
#define EVENTDISPATCH_H
#include "core/events/Event.h"
#include "core/ds-classes/Queue.h"
#include "core/events/event-layer/EventLayer.h"
class EventDispatcher {
    private: 
        struct EventFlags {
            Array<unsigned int, 4>flags;
            std::string evt_cause; 
            Event e;
        };
        EventFlags* flags;

    public:
        EventDispatcher() {
            flags = new EventFlags();
        }
        virtual void set_flags(Array<unsigned int, 4>evt_flag_vals) = 0;
        virtual void set_evt_cause(std::string cause) = 0;
        virtual void set_evt(Event evt_event) = 0;

        virtual Array<unsigned int, 4> get_flags() const = 0;
        virtual std::string get_evt_cause() const = 0;
        virtual Event get_evt() const = 0;
};

#endif