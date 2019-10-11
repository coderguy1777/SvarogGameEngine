#pragma once 
#ifndef STACK_H
#define STACK_H
#include "Pair.h"
#include "Queue.h"
#include "core/String.h"
#include "ArrayList.h"
#include "core/events/Event.h"
#include "render-pipeline/shader/s_lab/svarog_material.h"
#include "core/events/event-types/keyevent.h"
#include "macrodefs.h"
#include <stack>
class SvarogMaterial;
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

template<class S>
S Stack<S>::top() {
    return stack.top();
}

template<class S>
bool Stack<S>::isEmpty() {
    return (stack.size() == 0) ? true : false;
}

template<class S>
void Stack<S>::clear() {
    for(unsigned int i = 0; i < stack.size(); i++) {
        stack.pop();
    }
}

template<class S>
void Stack<S>::push(S const& item) {
    stack.push(item);
}

template<class S>
void Stack<S>::pop() {
    stack.pop();
}

template<class S>
int Stack<S>::size() const {
    return stack.size();
}

TMP_TYPE(Stack, SvarogMaterial);
#endif