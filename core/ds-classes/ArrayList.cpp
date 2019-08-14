#include "ArrayList.h"

template<class T>
void ArrayList<T>::set(int index, T const& item) {
    ArrayList::items[index] = item;
}

template<class T>
void ArrayList<T>::add(T const& item) { 
    items.push_back(item);
}

template<class T>
void ArrayList<T>::clear() {
    for(int i = 0; i < ArrayList::items.size(); i++) {
        items.pop_back();
    }
}

template<class T>
void ArrayList<T>::remove(int index) {
    for(unsigned int i = index; i < ArrayList::items.size(); i++) {
        items.pop_back();
    }
}

template<class T>
T ArrayList<T>::get(int index) {
    T item = items[index];
    return item;
}

template<class T>
int ArrayList<T>::size() {
    return items.size();
}

template<class T>
bool ArrayList<T>::isEmpty() {
    return (items.size() == 0) ? true : false;
}


// class types
ARRAYLIST_TYPE(int);
ARRAYLIST_TYPE(float);
ARRAYLIST_TYPE(char);
ARRAYLIST_TYPE(short);
ARRAYLIST_TYPE(long);
ARRAYLIST_TYPE(uint8_t);
ARRAYLIST_TYPE(uint16_t);
ARRAYLIST_TYPE(uint32_t);