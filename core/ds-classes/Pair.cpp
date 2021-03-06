#include "Pair.h"

template<class A, class B>
A Pair<A, B>::getitemA() {
    return itema;
}

template<class A, class B>
B Pair<A, B>::getitemB() {
    return itemb;
}

template<class A, class B>
void Pair<A,B>::setitemA(A const& newitema) {
    itema = newitema;
}

template<class A, class B>
void Pair<A,B>::setitemB(B const& newitemb) {
    itemb = newitemb;
}

template<class A, class B>
void * Pair<A,B>::operator new(size_t size) {
    void * newpair = new ::Pair<A, B>;
    return newpair;
}

MULT_TMP_TYPE(Pair, Queue<Event *>, int)

MULT_TMP_TYPE(Pair, int, int)
MULT_TMP_TYPE(Pair, int, double)
MULT_TMP_TYPE(Pair, int, float)
MULT_TMP_TYPE(Pair, int, char)
MULT_TMP_TYPE(Pair, int, String)