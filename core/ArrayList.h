#pragma once
#ifndef ARRAYLIST_H
#define ARRAYLIST_H
#include<iostream>
#include<vector>
#include<string>
using namespace std;

template<class T>
class ArrayList {
    private:
        vector<T>items;
    public:
        void set(int index, T const& item) {
            ArrayList::items[index] = item;
        }

        void add(T const& item) { 
            items.push_back(item);
        }

        void clear() {
            for(int i = 0; i < ArrayList::items.size(); i++) {
                items.pop_back();
            }
        }

        void remove(int index) {
            for(unsigned int i = index; i < ArrayList::items.size(); i++) {
                items.pop_back();
            }
        }
        
        T get(int index) {
            T item = ArrayList<T>::items[index];
            return item;
        }

        void print() {
            for(unsigned int i = 0; i < items.size(); i++) {
                cout << ArrayList::items[i] << endl;
            }
        }

        int size() {
            return items.size();
        }

        bool isEmpty() {
            return (items.size() == 0) ? true : false;
        }
        
        T Max (const T& a, const T& b) {
            return (b > a) ? b : a;
        }

        T min (const T& a, const T& b) {
            return (b < a) ? b : a;
        }

        T lessThanEqual(const T& a, const T& b) {
            return (b <= a) ? b : a;
        }

        T greaterThanEqual(const T& a, const T& b) {
            return (b >= a) ? b : a;
        }

        bool isEqual(const T& a, const T& b) {
            return (b==a) ? true : false;
        }

};
#endif

