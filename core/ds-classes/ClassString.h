#pragma once
#ifndef CLASSSTRING_H
#define CLASSSTRING_H
#include<string>

class ClassString {
    private: 
        struct ClassString_Info {
            unsigned int class_id;
            std::string class_name;
        } class_info;
        
    public: 
        ClassString();
        ClassString(unsigned int class_id, std::string class_name);
        void bind_class_string(unsigned int class_id, std::string class_name);
        std::string get_class_str() const;
        unsigned int get_class_id() const;
};

#endif