#pragma once
#ifndef EVENTLAYER_H
#define EVENTLAYER_H
#include "Event.h"
#include "core/ds-classes/Stack.h"
#include "core/ds-classes/Pair.h"
#include "core/ds-classes/Queue.h"

class EventLayer {
    private: 
        Stack<Queue<Event*>>*eventstack;
    public:
        ~EventLayer();
        EventLayer(Queue<Event*>queue) {
            addQueue(queue, 10);
        }
        EventLayer(){};
        void addQueue(Queue<Event*>eventQueue, int QUEUE_ID);
        void removeQueue(int QUEUE_ID);

        void * operator new(size_t size) {
            void * p = ::new EventLayer();
            return p;
        }
};


#endif

