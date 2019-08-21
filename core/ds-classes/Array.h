#pragma once
#ifndef ARRAY_H
#define ARRAY_H
#include<memory>
#include<memory.h>
#include<algorithm>
#include "macrodefs.h"
template<typename T> FORWARD_DEC(Array);
template<typename T> class Array {
    public: 
        T *array;
        Array(){}
        Array(int arrsize) {
            size = arrsize;
            array = new T[size * 2];
            setZeros();
        }

        void setSize(int newSize) {
            size = newSize;
        }

        void add(const T &data) {
            MIN_LEN = MIN_LEN + 1;
            array[MIN_LEN] = data;
            if(MIN_LEN > size) {
                throw std::invalid_argument("Pos too big");
            }
        }

        T get_pos(int pos) {
            return array[pos];
        }

        T get() {
            MAX_LEN = MAX_LEN - 1;
            if(MAX_LEN < 0) {
                throw std::invalid_argument("To small a spot");
            }
            return array[MAX_LEN];
        }

        void add_pos(const T &data, int pos) {
            if(pos > size || pos < MIN_LEN) {
                throw std::invalid_argument("Out of bounds");
            } else if(pos < size) {
                resize();
                array[pos] = data;
            }
        }

        int length() const {
            return size;
        }

        void resize() {
            size_t newSize = size + 1;
            T* newArr = new T[newSize];
            memcpy(newArr, array, size*sizeof(int));
            size=newSize;
            delete[]array;
            array = newArr;
        }

        T* returnArray() {
            return array;
        }

        bool isEmpty() {
            return length() == 0;
        }
        

        void copyarr();

    private: 
        int size;
        mutable int MAX_LEN = length() - 1;
        mutable int MIN_LEN = 0;
        void initArray() {
            array = new T[size];
        }

        void setZeros() {
            for(int i = 0; i < size; i++) {
                array[i] = 0;
            }
        }
};
#endif