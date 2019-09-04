#pragma once
#ifndef KEYLISTENER_H
#define KEYLISTENER_H
#include "core/String.h"
#include "core/ds-classes/ArrayList.h"
#include "core/events/event-types/keyevent.h"
#include "core/events/EventDispatchers/KeyEventDispatcher.h"
class KeyListener {
    private:
        const int evt_type = 1;
    public:
        KeyListener();
};

#endif