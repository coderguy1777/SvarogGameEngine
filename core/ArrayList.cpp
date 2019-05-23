#include<iostream>
#include<vector>
#include<string>
using namespace std;

template<class T>
class ArrayList {
        private:
                vector<T>items;
        public:
                void add(T const&);                       
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
};

template<class T>
void ArrayList<T>::add(T const& item) { 
    ArrayList::items.push_back(item);
}