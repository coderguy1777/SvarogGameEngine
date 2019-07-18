#pragma once 
#ifdef EVENTLISTENER_H
#define EVENTLISTENER_H
#endif
using namespace std;
#include "libs.h"

class EventListener {
    public: 
        EventListener(){};
        void * operator new(size_t size) {
            EventListener * listener = new EventListener;
            return listener;
        }
        inline void getEvent(Event e);
};