#pragma once
#ifndef KEYLISTENER_H
#define KEYLISTENER_H
#include "core/String.h"
#include "core/ds-classes/ArrayList.h"
#include "core/events/event-types/keyevent.h"
class KeyListener {
    private:
        Array<KeyEvent*, 10>input_evts;
    public:

        void size_check() {
            if(input_evts.length() > 0) {
                std::cout << "Events added" << std::endl;
            } else if(input_evts.length() == 0) {
                std::cout << "no new events added" << std::endl;
            }
        }
        void add_to_inputevts(KeyEvent* evt);
};

#endif