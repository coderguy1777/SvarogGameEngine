#include "Queue.h"
template<class Q>
bool Queue<Q>::isEmpty() {
    return (queue.size() == 0) ? true : false;
}


