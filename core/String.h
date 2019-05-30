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
        String() {};

        int length();
        vector<char>substring(int start, int end);
        vector<char>substring(int index);
        void del(char unwanted);
        bool equals(String i);
        bool isEmpty();
        bool contains(String sequence);
        bool startsWith(char check);
        bool endsWith(char check);
        void setstr(int index, char newstr);
        char* toCharArray(String i);
};