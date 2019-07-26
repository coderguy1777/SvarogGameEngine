#pragma once 
#ifndef QUEUE_H
#define QUEUE_H
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
        // adds item to queue
        void addToQueue(T const& event) {
            Node *temp = new Node;
            temp->data = event;
            temp->next = evtQueue.tail;
            if(evtQueue.head == NULL) {
                evtQueue.head = temp;
                evtQueue.tail = temp;
                temp = NULL;
            } else {
                temp->next = evtQueue.tail;
                evtQueue.tail = temp;
                evtQueue.addNode(temp);
            }
        }
        int checkOpenQueueSlots();
        Node getNextEvent() {
            return evtQueue.curr;
        }
};
#endif