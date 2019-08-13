#include "EventDispatch.h"

Queue<Event*> EventDispatcher::makeNewQueue(Event* event) {
    Queue<Event*>EVTQUEUE;
    EVTQUEUE.enqueue(event);
    return EVTQUEUE;
}

void EventDispatcher::sendToEventLayer(Queue<Event*>queue) {
    layer->addQueue(queue, 10);   
}