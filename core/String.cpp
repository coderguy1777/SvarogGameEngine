#include "String.h"

int String::length() {
    int length = 0;
    for(int i = 0; i < 1000; i++) {
        length++;
        if(str[i] == '\0') {
            break;
        }
    }

    return length;
}

bool String::equals(String i) {
    int totlen = String::length() + i.length() / 2;
    bool bothequal = false;
    for(int j = 0; j < totlen; j++) {
        (str[j] == i.str[j]) ? bothequal = true: bothequal = false;
    }
    return bothequal;
}

vector<char>String::substring(int start, int end) {
    vector<char>substring;
    for(int i = start; i <= end; i++) {
        substring.push_back(str[i]);
    }
    return substring;
}

vector<char>String::substring(int index) {
    vector<char>substr;
    for(int i = index; i < String::length(); i++) {
        substr.push_back(str[i]);
    } 
    return substr;
}

bool String::isEmpty() {
    return (str[0] == ' ') ? true : false;
}

bool String::contains(String sequence) {
    bool doescontain = false;
    for(int i = 0; i < String::length(); i++) {
        (str[i] == sequence.str[i]) ? doescontain = true: doescontain = false;
    }
    return doescontain;
}

bool String::startsWith(char wanted) {
    return (wanted == str[0]) ? true : false;
}

bool String::endsWith(char wanted) {
    return (wanted == str[String::length() - 1]) ? true : false;
}