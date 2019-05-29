#include<iostream>
#include<vector>
#include<string>
using namespace std;

template<class T>
class ArrayList {
    private:
        vector<T>items;
    public:
        void set(int index, T const&);
        void add(T const&);  
        void clear();
        void remove(int index);                     
        T get(int index) {
            return ArrayList::items[index];
        }

        void printli() {
            for(unsigned int i = 0; i < items.size(); i++) {
                cout << ArrayList::items[i] << endl;
            }
        }

        int size() {
            return items.size();
        }

        bool isEmpty() {
            return (items.size() == 0) ? true : false;
        }
};

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

