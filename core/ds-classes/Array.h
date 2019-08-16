#pragma once
#ifdef ARRAY_H
#define ARRAY_H
#endif
#include "macrodefs.h"
template<typename T> FORWARD_DEC(Array);
template<typename T> class Array {
    public: 
        Array(size_t arrsize) {
            size = arrsize;
            initArray();
            setZeros();
        }

        void add(const T &data) {
            array[0] = data;
        }

        void add_pos(const T &data, int pos) {
            if(pos > size) {
                throw std::invalid_argument("Out of bounds");
            } else if(pos < size) {
                array[pos] = data;
            }
        }

        int length() const {
            return size;
        }

        T* returnArray() {
            return array;
        }

        bool isEmpty();
    private: 
        T *array;
        size_t size;
        void initArray() {
            array = new T[size];
        }

        void setZeros() {
            for(int i = 0; i < size; i++) {
                array[i] = 0;
            }
        }
};