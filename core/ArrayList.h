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
        T get(int index);

        void printli();

        int size();

        bool isEmpty();
};

