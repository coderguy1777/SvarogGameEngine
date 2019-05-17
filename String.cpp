#include "String.h"
char* String::parse(char parseit[8]) {
    string x = "";
    vector<char>test;
    int length = 0;
    for(int i= 0; i < 8;  i++) {
        x += parseit[i];
        test.push_back(parseit[i]);
    }

    for(unsigned int j = 0; j < test.size(); j++) {
        length++;
        if(test[j] == ' ') {
            length -= 1;
            std::cout << "Null found" << std::endl;
            break;
        }
    }

    cout << x << endl;
    cout << length << endl;
}

int String::length() {
    vector<char>STR;
    for(int i = 0; i < input.size(); i++) {
        STR.push_back(input[i]);
    }
    int strsize = 0;
    strsize = STR.size();
    return strsize;
}

String String::setStr(int index, char newChar) {
    input[index] = newChar;
    return input;
}

bool String::emptyStr(string input2) {
    bool empty = false;
    if(input2.length == 0) {
        empty = true;
    } else {
        empty = false;
    }
    return empty;
}


String String::setRangeStr(int start, int end, string wanted) {
    if(end > input.length()) {
        cout << "End index too big, make it smaller." << endl;
    }
    if(start < 0) {
        cout << "Start is negative, cannot be less than 0." << endl;
    }
    if(start > end || end < start) {
        cout << "End is less than start or start greater then end, fix either of the two" << endl;
    }
    if(String::emptyStr(wanted) == true) {
        cout << "The inputted string size is 0, add something to the string" << endl;
    }
    for(int i = start; i < end; i++) {
        input[i] = wanted[i];
    }
    return input;
}

String String::get() {
    return String(input);
}

String String::set(vector<char>newstr) {
    string str = "";
    for(unsigned int i = 0; i < newstr.size(); i++) {
        str[i] += newstr[i];
    }
    return str;
}

String::~String() {
    cout << "String deleted" << endl;
}

String String::add(String i) {
    if(String::emptyStr(i.input) == true) {
        cout << "String size is 0, add something to the string." << endl;
    } else {
        for(int j = 0; j < i.input.length(); j++) {
            input[j] = i.input[j];
        }
    }
    return input;
}

char String::get(int index) {
    return input[index];
}

char String::add(int index) {
    return input[index];
}

String String::concat(String i, String j) {
    for(int k = 0; k < i.length() + j.length(); k++) {
        input[k] += i.get(k) + j.get(k);
    }
    return input;
}

String String::substring(int start, int end) {
    String substr("");
    for(int i = start; i < end; i++) {
        substr.add(input[i]);
    }
    return substr;
}

bool String::equals(String i) {
    bool isequal = false;
    if(i.input == input) {
        isequal = true;
    } else if(i.input != input) {
        isequal = false;
    }
    return isequal;
}

