#pragma once
#ifdef STRING_H
#define STRING_H
#endif
#include<iostream>
#include<vector>
using namespace std;

class String {
    public:
        const char* str;
        String(const char* strn) {
            this->str = strn;
        }

        int length();
        vector<char>substring(int start, int end);
        vector<char>substring(int index);
        bool equals(String i);
        bool isEmpty();
        bool contains(String sequence);
        char* toCharArray(String i);
};