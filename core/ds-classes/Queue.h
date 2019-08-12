#pragma once 
#ifndef QUEUE_H
#define QUEUE_H
#include "LinkedList.h"
#include "macrodefs.h"
#include "ArrayList.h"

template<class Q>
FORWARD_DEC(Queue);

template<class Q>
class Queue {
    private:
        ArrayList<Q>queue;
        const int rear = 0;
        const int front = queue.size() - 1;
    public: 
        void enqueue(Q const &item);
        Q getRear();
        Q getFront();
        ArrayList<Q>createNewQueue(Q const &datatype, ArrayList<Q>items);
        Q dequeue();
        bool isEmpty();

};
#endif