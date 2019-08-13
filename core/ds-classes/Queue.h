#pragma once 
#ifndef QUEUE_H
#define QUEUE_H
#include "core/ds-classes/LinkedList.h"
#include "macrodefs.h"
#include "ArrayList.h"
#include<ostream>

template<class Q>
FORWARD_DEC(Queue);

template<class Q>
class Queue {
    private:
        ArrayList<Q>queue;
        const int rear = 0;
        const int front = queue.size() - 1;
    public: 
        void enqueue(Q const &);
        Q getRear();
        Q getFront();
        Queue<Q>createNewQueue(ArrayList<Q>items) {
            Queue<Q>newQueue;
            for(unsigned int i = 0; i < items.size(); i++) {
                newQueue.enqueue(items.get(i));
            }
            return newQueue;
        }
        Q dequeue();
        int size();
        void printQueue();
        bool isEmpty();

};
#endif