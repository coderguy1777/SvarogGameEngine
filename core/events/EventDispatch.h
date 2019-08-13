#pragma once 
#ifndef EVENTDISPATCH_H
#define EVENTDISPATCH_H
#include "Event.h"
#include "core/ds-classes/Queue.h"
class EventDispatcher {
    private:
        static EventDispatcher* dispatch;
    public:
        EventDispatcher(){};
        Queue<Event>makeNewQueue(Event event);

};

#endif