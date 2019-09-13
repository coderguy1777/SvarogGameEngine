#pragma once
#ifndef KEYMAP_H
#define KEYMAP_H
#include<map>
#include<unordered_map>
#include "core/String.h"
#include <iostream>
#include "macrodefs.h"



typedef struct  {
    unsigned int key_code;
    bool state;
} key_pair;
class KeyMap {
    private:
        std::map<unsigned int, bool>key_states;
        static KeyMap* key_mp;
                KeyMap(){}
    public:
        static KeyMap* getMapInstance();

        void set_key_pair(key_pair* key);
        void change_key_pair(key_pair* new_pair);
        key_pair get_key_state(unsigned int key_id);
        void delete_key(unsigned int key_id);
        int map_size() const;
};

#endif