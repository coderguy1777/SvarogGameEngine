#pragma once 
#ifndef EVENTDISPATCH_H
#define EVENTDISPATCH_H
#include "Event.h"
#include "core/ds-classes/Queue.h"
#include "core/events/EventLayer.h"
class EventDispatcher {
    private:
        static EventDispatcher* dispatch;
        static EventLayer* layer;
    public:
        EventDispatcher(){};
        Queue<Event*>makeNewQueue(Event* event);
        ~EventDispatcher();
        void sendToEventLayer(Queue<Event*>evtQueue);
};

#endif