#pragma once
#ifndef ARRAY_H
#define ARRAY_H
#include<memory>
#include<algorithm>
#include<vector>
#include "macrodefs.h"
template<typename T, int N> FORWARD_DEC(Array);
template<typename T, int N> class Array {
    private: 
        int size;
        int MAX_LEN = length() - 1;
        int MIN_LEN = 0;
        int curr_len = 0;
        void initArray() {
            array = new T[size];
        }

        void setZeros() {
            for(int i = 0; i < size; i++) {
                array[i] = 0;
            }
        }

    public: 
        T *array;
        Array(){ 
            array = new T[N];
        }
        void setSize(int newSize) {
            size = newSize;
        }

        void add(const T &data) {
            T* temp;
            temp = new T[length() * 2];
            for(int i = 0; i < length(); i++) {
                temp[i] = array[i];
            }
            size *= 2;
            delete [] array;
            array = temp;
            array[curr_len] = data;
            curr_len++;
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
            array[pos] = data;
        }

        int length() const {
            return N;
        }

        void add_list(const std::vector<T>&list) {
            if(list.size() > length()) {
                throw std::invalid_argument("Size of list is too big for array size set.");
            } else if(list.size() <= length()) {
                for(unsigned int i = 0; i < list.size() && i < length(); i++) {
                    add(list[i]);
                }
            }
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

        void setSize(unsigned int new_size) {
            N = new_size;
        }
};
#endif