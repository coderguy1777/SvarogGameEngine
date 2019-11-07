#pragma once 
#ifndef QUEUE_H
#define QUEUE_H
#include "macrodefs.h"
#include<ostream>
#include <queue>

template<class Q>
class Queue {
    protected:
        std::queue<Q>item_queue;
    public: 
        bool isEmpty() {
            return (item_queue.size() == 0) ? true : false;
        }

        int size() const {
            return item_queue.size();
        }

        void enqueue_item(Q const& item) {
            item_queue.emplace(item);
        }

        void add_item(Q const &item) {
            item_queue.push(item);
        }   

        Q get_back() const {
            return item_queue.back();
        }

        Q get_front() const {
            return item_queue.front();
        }

        Q get_next() const {
            return item_queue.pop();
        }
};
#endif