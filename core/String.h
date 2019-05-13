#include<string>
#include<iostream>
#include<vector>
using namespace std;

class String {
     private:        
        string input;
     public:
        String(string str) {
            this->input = str;
        }

        char* parse(char parseit[8]);
        void *operator new(size_t size) {
           void *p = ::new String("");
        }
        int length();
        char findChar();
        bool equals(String i);
        String setStr(int index, char newChar);
        String setRangeStr(int start, int end, string change);
        bool emptyStr(string input2);
        String get();
        String set(vector<char>newstr);
        ~String();
        String add(String i);
        char get(int index);
        char add(int index);
        String concat(String i, String j);
        String substring(int start, int end);
        
};


