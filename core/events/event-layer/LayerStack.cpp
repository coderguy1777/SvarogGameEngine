#include "LayerStack.h"
// bool reimplementations since 
// queues are private.
template<class E, class U, class V>
bool LayerStack<E, U, V>::queue_1_isEmpty() const {
    return queue_group->evt_one->queue_1->isEmpty();
}

template<class E, class U, class V>
bool LayerStack<E, U, V>::queue_2_isEmpty() const {
    return queue_group->evt_two->queue_2->isEmpty();
}

template<class E, class U, class V>
bool LayerStack<E, U, V>::queue_3_isEmpty() const {
    return queue_group->evt_three->queue_3->isEmpty();
}
// queue stack length
template<class E, class U, class V>
int LayerStack<E, U, V>::queue_1_len() const {
    return queue_group->evt_one->queue_1->size();    
}

template<class E, class U, class V>
int LayerStack<E, U, V>::queue_2_len() const {
    return queue_group->evt_two->queue_2->size();
}

template<class E, class U, class V>
int LayerStack<E, U, V>::queue_3_len() const {
    return queue_group->evt_three->queue_3->size();
}

template<class E, class U, class V>
E * LayerStack<E, U, V>::get_event_name_queue1() {
    return evt_type_1;
}

template<class E, class U, class V>
U * LayerStack<E, U, V>::get_event_name_queue2() {
    return evt_type_2;
}

template<class E, class U, class V>
V * LayerStack<E, U, V>::get_event_name_queue3() {
    return evt_type_3;
}

template<class E, class U, class V>
void LayerStack<E, U, V>::enqueue_evtqueue_1(E const& item) {
    if(queue_1_len() == 0) {
        queue_group->evt_one->queue_1->enqueue_item(item);
    } else {
        queue_group->evt_one->queue_1->add_item(item);
    }
}

template<class E, class U, class V>
void LayerStack<E, U, V>::enqueue_evtqueue_2(U const& item) {
    if(queue_2_len() == 0) {
        queue_group->evt_two->queue_2->enqueue_item(item);
    } else {
        queue_group->evt_two->queue_2->add_item(item);
    }
}

template<class E, class U, class V>
void LayerStack<E, U, V>::enqueue_evtqueue_3(V const& item) {
    if(queue_3_len() == 0) {
        queue_group->evt_three->queue_3->enqueue_item(item);
    } else {
        queue_group->evt_three->queue_3->add_item(item);
    }
}

template<class E, class U, class V>
void LayerStack<E, U, V>::set_queue_ids(unsigned int id_1, unsigned int id_2, unsigned int id_3) {
    queue_group->evt_one->queue_id = id_1;
    queue_group->evt_two->queue_id = id_2;
    queue_group->evt_three->queue_id = id_3;
}

// declared classes allowed
// for template cases and uses
// of the template.
LAYERSTACK_DEP(int, char, float);
LAYERSTACK_DEP(int, float, char);
LAYERSTACK_DEP(int, double, long);
LAYERSTACK_DEP(int, float, long);
LAYERSTACK_DEP(double, char, int);
LAYERSTACK_DEP(int, float, double);