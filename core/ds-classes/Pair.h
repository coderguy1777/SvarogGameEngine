#pragma once
#ifdef PAIR_HPP
#define PAIR_HPP
#endif
#include "macrodefs.h"
#include <iostream>

template<class A, class B>
FORWARD_DEC(Pair);

template<class A, class B>
class Pair {
    public:
        A itema;
        B itemb;
        Pair(A const& b, B const& c):
            itema(b), itemb(c)
        {}
        
        Pair(){};
        A getitemA();
        B getitemB();
        void setitemA(A const& newitem);
        void setitemB(B const& newitem);
        void * operator new(size_t size);

};