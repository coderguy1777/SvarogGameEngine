#pragma once
#ifdef STRING_H
#define STRING_H
#endif
#include<iostream>
#include<vector>
using namespace std;

class String {
    private:
        char* data;
        size_t data_length;
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
        String setstr(int index, char newstr, String a);
        char* toCharArray(String i);
        void * operator new(size_t size) {
            void * str = :: new String("");
            return str;
        }

        const char* c_str() const {
            return data;
        }
};