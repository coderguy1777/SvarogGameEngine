#include "EventLayer.h"
void EventLayer::addQueue(Queue<Event*>evtQueue, int ID) {
    eventstack->push(evtQueue);
    if(!eventstack->isEmpty()) {
        std::cout << "IS NOT NULL TOP OF EVT STACK" << std::endl;
    }
}