#pragma once
#ifndef EVENT_QUEUE_H
#define EVENT_QUEUE_H
#include <iostream>
#include "core/ds-classes/Queue.h"

template<typename E>
class EventQueue {
    private:
        Queue<E>*evt_queue;
    public:
        EventQueue() {
            evt_queue = new Queue<E>();
        }

        void add_new_evt(E const& event) {
            if(evt_queue->isEmpty()) {
                evt_queue->enqueue_item(event);
            } else {
                evt_queue->add_item(event);
            }
        }

        int evt_queue_size() const {
            return evt_queue->size();
        }

        E get_front_event() const {
            return evt_queue->get_front();
        }

        E get_back_event() const {
            return evt_queue->get_back();
        }

        E get_event() const {
            return evt_queue->get_next();
        }

        bool evt_queueIsEmpty() {
            return (evt_queue->isEmpty()) || (evt_queue->size() == 0) ? true : false;
        }

        void to_dispatch();
        void clear_evt_queue();
};

#endif