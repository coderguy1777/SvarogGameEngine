#pragma once
#ifndef EVENTLAYER_H
#define EVENTLAYER_H
#include "core/events/Event.h"
#include "core/ds-classes/Queue.h"
#include "LayerStack.h"
#include "core/ds-classes/Stack.h"
#include <memory>

struct LayerID {
    int evt_lyer_type;
    unsigned int layer_id;
};

class EventLayer {
    private:
        Stack<LayerStack<Event, int, float>>*evt_layer;
        std::unique_ptr<Event>et;
    public:
        EventLayer() {
            evt_layer = new Stack<LayerStack<Event, int, float>>();
        }
};
#endif