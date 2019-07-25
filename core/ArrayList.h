#pragma once
#ifdef ARRAYLIST_H
#define ARRAYLIST_H
#endif
#include<iostream>
#include<iostream>
#include<vector>
#include<string>
#include "libs.h"
using namespace std;

template<class T>
class ArrayList {
    private:
        vector<T>items;
    public:
        void set(int index, T const&);
        void add(T const&);  
        void clear();
        void remove(int index);                     
        T get(int index);
        void printli();
        int size();
        bool isEmpty();
        T Max (const T& a, const T& b);
        T min (const T& a, const T& b);
        T lessThan(const T& a, const T& b);
        T greaterThan(const T& a, const T& b);

};

