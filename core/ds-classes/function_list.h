#pragma once
#ifndef FUNCTION_LIST_H
#define FUNCTION_LIST_H
#include <iostream>
#include "Array.h"
#include "spdlog/spdlog.h"

template<typename C>
class FunctionList {
    private:
        std::vector<C>function_stack;
        size_t list_id;
    public:
        void run_functions();
        void remove_function();
        void add_new_function(const C& args);
};

template<typename C>
void FunctionList<C>::run_functions() {
    for(auto func: function_stack) {
        func();
    }
}

template<typename C>
void FunctionList<C>::add_new_function(const C& args) {
    function_stack.push_back(args);
}

#endif