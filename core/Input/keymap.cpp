#include "keymap.h"

KeyMap* KeyMap::getMapInstance() {
    if(!key_mp) key_mp = new KeyMap; return key_mp;
}

void KeyMap::set_key_pair(key_pair* key) {
    key_states.insert(make_pair(key->key_code, key->state));
}

void KeyMap::change_key_pair(key_pair* new_pair) {
    auto id = key_states.find(new_pair->key_code);
    key_states.erase(id);
    key_states.insert(make_pair(new_pair->key_code, new_pair->state));    
}

key_pair KeyMap::get_key_state(unsigned int key_id) {
    key_pair pair;
    std::unordered_map<unsigned int, bool>::iterator itr;
    for(itr = key_states.begin(); itr!=key_states.end(); itr++) {
        if(key_states.find(key_id)->first == key_id) {
            pair = {static_cast<unsigned int>(key_id), key_states.find(key_id)->second};
            break;
        }
    }
    return pair;
}

void KeyMap::delete_key(unsigned int key_id) {
    key_states.erase(key_id);
}

int KeyMap::map_size() const {
    return key_states.size();
}
KeyMap* KeyMap::key_mp = 0;