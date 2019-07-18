#include "Queue.h"
template<class T>
// adds item to queue
void EventQueue<T>::addToQueue(T const& event) {
    Node *temp = new Node;
    temp->data = event;
    temp->next = evtQueue.tail;
    if(evtQueue.head == NULL) {
        evtQueue.head = temp;
        evtQueue.tail = temp;
        temp = NULL;
    } else {
        temp->next = evtQueue.tail;
        tail = temp;
        evtQueue.addNode(temp);
    }
}

template<class T>
Node EventQueue<T>::getNextEvent() {
    return evtQueue.curr;
}