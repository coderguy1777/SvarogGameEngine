#pragma once
#ifndef LAYERSTACK_H
#define LAYERSTACK_H
#include "core/ds-classes/Stack.h"
#include "core/ds-classes/Queue.h"
#include "macrodefs.h"
#define LAYERSTACK_DEP(X, X1, X2) template class LayerStack<X, X1, X2>
template<class E, class U, class V>
FORWARD_DEC(LayerStack);

template<class E, class U, class V>
class LayerStack {
    private: 
        struct evt_queue_1 {
            Queue<E>*queue_1 = new Queue<E>();
            unsigned int queue_id;
        };

        struct evt_queue_2 {
            Queue<U>*queue_2 = new Queue<U>();
            unsigned int queue_id;
        };

        struct evt_queue_3 {
            Queue<V>*queue_3 = new Queue<V>();
            unsigned int queue_id;
        };

        struct QueueInput {
            evt_queue_1* evt_one = new evt_queue_1();
            evt_queue_2* evt_two = new evt_queue_2();
            evt_queue_3* evt_three = new evt_queue_3();
        };
        QueueInput* queue_group;

        E * evt_type_1 = new E();
        U * evt_type_2 = new U();
        V * evt_type_3 = new V();
        
    public:
        LayerStack(E * event_1, U * event_2, V * event_3) {
            queue_group = new QueueInput();
            evt_type_1 = event_1;
            evt_type_2 = event_2;
            evt_type_3 = event_3;
        }

        void set_queue_ids(unsigned int id_1, unsigned int id_2, unsigned int id_3);
        void enqueue_evtqueue_1(E const&);
        void enqueue_evtqueue_2(U const&);
        void enqueue_evtqueue_3(V const&);

        bool queue_1_isEmpty() const;
        bool queue_2_isEmpty() const;
        bool queue_3_isEmpty() const;
        int queue_1_len() const;
        int queue_2_len() const;
        int queue_3_len() const;

        QueueInput* return_queuegrp() const {
            return queue_group;
        }

        E find_event_queue1(unsigned int evt_id);
        U find_event_queue2(unsigned int evt_id);
        V find_event_queue3(unsigned int evt_id);

        E * get_event_name_queue1();
        U * get_event_name_queue2();
        V * get_event_name_queue3();

        static void pri_sort_evt1();
        static void pri_sort_evt2();
        static void pri_sort_evt3();

};
#endif
