#pragma once 
#ifndef STACK_H
#define STACK_H
#include "Pair.h"
#include "Queue.h"
#include "core/String.h"
#include "ArrayList.h"
#include "core/events/Event.h"
#include "macrodefs.h"

template<class S>
class Stack {
    private: 
        ArrayList<S>stack;
        const int topPiece = stack.size() - 1;
        const int bottomPiece = 0;
    public:
        Stack() {}
        S top();
        bool isEmpty();
        void clear();
        void push(S const& item);
        S pop();
};

#endif