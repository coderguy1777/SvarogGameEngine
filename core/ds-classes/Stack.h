#pragma once 
#ifndef STACK_H
#define STACK_H
#include "Pair.h"
#include "Queue.h"
#include "core/String.h"
#include "ArrayList.h"
#include "core/events/Event.h"
#include "macrodefs.h"
#include <vector>
template<class S>
class Stack {
    private: 
        vector<S>stack;
    public:
        Stack() {}
        S top();
        bool isEmpty();
        void clear();
        void push(S const& item);
        S pop();
};

#endif