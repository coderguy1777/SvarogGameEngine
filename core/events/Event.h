#pragma once 
#ifdef EVENT_H
#define EVENT_H
#endif
#include<ostream>
#include<iostream>
enum EVENT_TYPE {
    nullevt = 0,
    KeyEvt,
    MouseEvent,
    WindowEvent, 
    AudioEvent,
    TextureEvent, 
    InputEvent,
    ErrorEvent, 
};

class Event {
    private:  
        EVENT_TYPE evt_type;
        int PRIORITY;
        const char* cause; 
    public: 
        // constructor
        Event(EVENT_TYPE event_type, int prty, const char* cse) {
            evt_type = event_type;
            PRIORITY = prty;
            cause = cse;   
        }
        Event(){}

        // getters
        bool findQueue();
        EVENT_TYPE get_typeof_event() const;
        int get_priority() const;
        const char* get_cause() const;
        void setEventType(EVENT_TYPE type);
        void setPriority(int pri);
        void setCause(const char* cause);
        friend std::ostream& operator<<(std::ostream& os, const Event &event);
};