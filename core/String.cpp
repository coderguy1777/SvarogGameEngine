#include "String.h"
String* String::concat(Array<string, 10>strings) {
    String *result = nullptr;
    for(int i = 0; i < strings.length() + 1; i++) {
        result = new String(strings.get_pos(i) + strings.get_pos(i + 1));
    }
    return result;
}
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

void String::del(char unwanted) {
    int unwantedid = 0;
    for(int i = 0; i < String::length(); i++) {
        if(str[i] == unwanted) {
            unwantedid = i;
        } else {
            continue;
        }
    }
    String a;
    setstr(unwantedid, '\0',a);
}

String String::setstr(int index, char stringval, String val) {
    val.str[index] == stringval;
    return val;
}

char* String::toCharArray(String i) {
    char * strarr = new char[i.length()];
    for(int j = 0; j < i.length(); j++) {
        strarr[j] = i.str[j];
    }
    return strarr;
}

String String::int_toString(int a) {
    stringstream ss;
    ss << a;
    string temp = ss.str();
    return String(static_cast<const char*>(temp.c_str()));
}

String String::char_toString(char a) {
    stringstream ss;
    string temp;
    ss << a;
    temp = ss.str();
    return String(static_cast<const char*>(temp.c_str()));
}

String String::float_toString(float a) {
    stringstream ss;
    string temp;
    ss << a;
    temp = ss.str();
    return String(static_cast<const char*>(temp.c_str()));
}

String String::double_toString(double a) {
    stringstream ss;
    string temp;
    ss << a;
    temp = ss.str();
    return String(static_cast<const char*>(temp.c_str()));
}

String String::long_toString(long a) {
    stringstream ss;
    string temp;
    ss << a;
    temp = ss.str();
    return String(static_cast<const char*>(temp.c_str()));
}

String String::short_toString(short a) {
    stringstream ss;
    string temp;
    ss << a;
    temp = ss.str();
    return String(static_cast<const char*>(temp.c_str()));
}

std::ostream& operator<<(std::ostream& os, const String& strex) {
    os << strex.str << std::endl;
    return os;
}