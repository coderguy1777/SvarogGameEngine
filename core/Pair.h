#pragma once
#ifdef PAIR_HPP
#define PAIR_HPP
#endif
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
        Pair(){};
        A getitemA();
        B getitemB();
        void setitemA(A const& newitem);
        void setitemB(B const& newitem);
        void * operator new(size_t size);
        Pair<A,B>operator +(Pair<A,B>const& pair) {
            Pair<A,B>addingpair;
            addingpair.itema = pair.itema + this->itema;
            addingpair.itemb = pair.itemb + this->itemb;
            return addingpair;
        }

        Pair<A,B>operator -(Pair<A,B>const& pair) {
            Pair<A,B>subpair;
            subpair.itema = pair.itema - this->itema;
            subpair.itemb = pair.itemb - this->itemb;
            return subpair;
        }

        Pair<A,B>operator *(Pair<A,B>const& pair) {
            Pair<A,B>multpair;
            multpair.itema = pair.itema * this->itema;
            multpair.itemb = pair.itemb * this->itemb;
            return multpair;
        }

        Pair<A,B>operator /(Pair<A,B>const& pair) {
            Pair<A,B>divpair;
            divpair.itema = pair.itema / this->itema;
            divpair.itemb = pair.itemb / this->itemb;
            return divpair;
        }

};