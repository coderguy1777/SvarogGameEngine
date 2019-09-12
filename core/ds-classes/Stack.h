#pragma once 
#ifndef STACK_H
#define STACK_H
#include "Pair.h"
#include "Queue.h"
#include "core/String.h"
#include "ArrayList.h"
#include "core/events/Event.h"
#include "core/events/event-types/keyevent.h"
#include "macrodefs.h"
#include <stack>
template<class S>
class Stack {
    private: 
        std::stack<S>stack;
    public:
        Stack() {}
        S top();
        bool isEmpty();
        void clear();
        void push(S const& item);
        void pop();
        int size() const;
};
#endif