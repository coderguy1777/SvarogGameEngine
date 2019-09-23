#pragma once
#ifndef ARRAYLIST_H
#define ARRAYLIST_H
#include "core/String.h"
#include "core/events/Event.h"
#include<iostream>
#include<vector>
#include<string>
#include "macrodefs.h"
#define ARRAYLIST_TYPE(X)template class ArrayList<X>

template<class T>
class ArrayList {
    private:
        std::vector<T>items;
    public:
        void set(int index, T const& item);
        void add(T const& item);
        void clear();
        void remove(int index);
        T get(int index);
        int size();
        bool isEmpty();
        T Max (const T& a, const T& b);
        T Min (const T& a, const T& b);
        T lessThanEqual(const T& a, const T& b);
        T greaterThanEqual(const T& a, const T& b);
        T front();
        void * operator new(size_t size) {
            void * p = :: new ArrayList<T>();
            return p;
        }
};

template<class T>
void ArrayList<T>::set(int index, T const& item) {
    ArrayList::items[index] = item;
}

template<class T>
void ArrayList<T>::add(T const& item) { 
    items.push_back(item);
}

template<class T>
T ArrayList<T>::front() {
    return items.front();
}

template<class T>
void ArrayList<T>::clear() {
    for(int i = 0; i < ArrayList::items.size(); i++) {
        items.pop_back();
    }
}

template<class T>
void ArrayList<T>::remove(int index) {
    for(unsigned int i = index; i < ArrayList::items.size(); i++) {
        items.pop_back();
    }
}

template<class T>
T ArrayList<T>::get(int index) {
    return items[index];
}

template<class T>
int ArrayList<T>::size() {
    return items.size();
}

template<class T>
bool ArrayList<T>::isEmpty() {
    return (items.size() == 0) ? true : false;
}
// class types
ARRAYLIST_TYPE(int);
ARRAYLIST_TYPE(float);
ARRAYLIST_TYPE(char);
ARRAYLIST_TYPE(short);
ARRAYLIST_TYPE(long);
ARRAYLIST_TYPE(uint8_t);
ARRAYLIST_TYPE(uint16_t);
ARRAYLIST_TYPE(uint32_t);
ARRAYLIST_TYPE(String);
ARRAYLIST_TYPE(ArrayList<float>*);
ARRAYLIST_TYPE(Event);
#endif