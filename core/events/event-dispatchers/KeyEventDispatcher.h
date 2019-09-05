#pragma once 
#ifndef KEYEVENTDISPATCHER_H
#define KEYEVENTDISPATCHER_H
#include "core/ds-classes/Array.h"
#include "core/events/event-types/keyevent.h"
#include "EventDispatch.h"
#include <iostream>

class KeyEventDispatch : public EventDispatcher {
    private: 
        struct KeyEvtMSG {
            unsigned int KEY_EVT_TYPE;
            KeyEvent event;
        };
        KeyEvtMSG* msg;

    public:
        virtual void set_flags(Array<unsigned int, 4>flag_vals) override;
        virtual void set_evt_cause(std::string cause) override;
        virtual void set_evt(Event evet_event) override;
        void set_key_evt(KeyEvent evt);
        void set_key_evt_type(unsigned int key_evt_type);

        virtual Array<unsigned int, 4>get_flags() const override;
        virtual std::string get_evt_cause() const override;
        virtual Event get_evt() const override;
};


#endif