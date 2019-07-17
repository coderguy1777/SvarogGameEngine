#pragma once 
#ifdef QUEUE_H
#define QUEUE_H
#endif
#include "Message.h"
#include "LinkedList.h"
template<class T> 
class EventQueue {
    private: 
        LinkedList<T>evtQueue;
    public:  
        void * operator new(size_t size) {
            EventQueue<T>*queue = new EventQueue<T>();
            return queue;
        }
        EventQueue(T const& headEvent) {
            evtQueue.head = new Node;
            evtQueue.head.data = headEvent;
            evtQueue.head.next = NULL;
        }
        EventQueue(){};
        void addToQueue(T const& event);
        int checkOpenQueueSlots();
        Node getNextEvent();
};