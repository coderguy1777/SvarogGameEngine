#pragma once
#ifdef STRING_H
#define STRING_H
#endif
#include "core/ds-classes/Array.h"
#include<iostream>
#include<vector>
#include<sstream>
#include<string>
using namespace std;

class String {
    private:
        char* data;
        size_t data_length;
    public:
        const char* str;
        String(const char* strn): 
            str(strn)
        {}

        String(string strn):
            str(static_cast<const char*>(strn.c_str()))
        {}

        String(String*str):
            str(static_cast<const char*>(str->str))
        {}

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
        String* concat(Array<string>list);
        char* toCharArray(String i);
        String int_toString(int a);
        String char_toString(char a);
        String double_toString(double a);
        String float_toString(float a);
        String short_toString(short a);
        String long_toString(long a);
        
        void * operator new(size_t size) {
            void * str = :: new String();
            return str;
        }

        const char* c_str() const {
            return data;
        }
};