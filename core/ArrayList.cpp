#include "ArrayList.h"

template<class T>
void ArrayList<T>::add(T const& item) { 
    ArrayList::items.push_back(item);
}

template<class T>
void ArrayList<T>::set(int index, T const& item) {
    ArrayList::items[index] = item;
}

template<class T>
void ArrayList<T>::remove(int index) {
    for(unsigned int i = index; i < ArrayList::items.size(); i++) {
        items.pop_back();
    }
}

template<class T>
void ArrayList<T>::clear() {
    for(int i = 0; i < ArrayList::items.size(); i++) {
        items.pop_back();
    }
}

template<class T>
bool ArrayList<T>::isEmpty() {
    return (items.size() == 0) ? true : false;
}

template<class T>
int ArrayList<T>::size() {
    return items.size();
}

template<class T>
void ArrayList<T>::printli() {
    for(unsigned int i = 0; i < items.size(); i++) {
        cout << ArrayList::items[i] << endl;
    } 
}

template<class T>
T get(int index) {
    return ArrayList::items[index];
}