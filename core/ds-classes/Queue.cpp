#include "Queue.h"
template<class Q>
bool Queue<Q>::isEmpty() {
    return (queue.size() == 0);
}

template<class Q>
void Queue<Q>::enqueue(Q const &item) {
    queue.add(item);
}

template<class Q>
Q Queue<Q>::dequeue() {
    return queue.get(front);
}

template<class Q>
Q Queue<Q>::getFront() {
    return queue.get(front);
}

template<class Q>
Q Queue<Q>::getRear() {
    return queue.get(rear);
}

template<class Q>
int Queue<Q>::size() {
    return queue.size();
}

template<class Q>
void Queue<Q>::printQueue() {
    for(unsigned int i = 0; i < queue.size(); i++) {
        std::cout << queue.get(i) << std::endl;
    }
}
TMP_TYPE(Queue, Event);