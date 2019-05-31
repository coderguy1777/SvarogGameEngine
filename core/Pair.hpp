#pragma once
#ifdef PAIR_HPP
#define PAIR_HPP
#endif
#include "EngineHeader.h"
#include <iostream>

template<class A, class B>
class Pair {
    public:
        A itema;
        B itemb;
        Pair(A const& b, B const& c) {
            this->itema = b;
            this->itemb = c;
        }

        A getitemA() {
            return itema;
        }

        B getitemB() {
            return itemb;
        }

        void setitemA(A const& newitem) {
            itema = newitem;
        }

        void setitemB(B const& newitem) {
            itemb = newitem;
        }
};