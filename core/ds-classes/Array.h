#pragma once
#ifndef ARRAY_H
#define ARRAY_H
#include<memory>
#include<algorithm>
#include<vector>
#include "core/events/event-types/mouseevent.h"
#include "macrodefs.h"
template<typename T, int N> FORWARD_DEC(Array);
template<typename T, int N> class Array {
    private: 
        int size;
        int MAX_LEN = length() - 1;
        int MIN_LEN = 0;
        int curr_len = 0;

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
            if(get_curr_element_len() == 0) {
                array[0] = data;
                curr_len++;
            } else {
                array[get_curr_element_len() - 1] = data;
                curr_len++;
            }
        }

        void set(const T &data, unsigned int pos) {
            if(pos > length()) {
                throw std::invalid_argument("POS TO BIG, TRY AGAIN");
            } else {
                array[pos] = data;
            }
        }

        T get(int id) {
            return array[id];
        }
        
        Array & operator=(const Array& arr) {
            if(this == &arr) {
                T *temp = new T[N];
                for(int i = 0; i < N; i++) {
                    temp[i] = arr[i];
                }
                arr = new T[length() * 2];
                delete [] arr;
                arr = temp;
            }
            return *this;
        }

        int length() const {
            return N;
        }

        int get_curr_element_len() {
            return curr_len;
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