#include "EngineHeader.h"
#include <iostream>
#include<vector>
using namespace std;

template<class A, class B>
class Map {
    private:
        vector<A, B>items;
    public:
        void put(A const& itema, B const& itemb) {
            for(unsigned int i = 0; i < items.size(); i++) {
                items.push_back(itema, itemb);
            }
        }

        int size() {
            return items.size();
        }

        A getKey(A const&);
        void setKey(int keyAid, A const&);
        B getValue(int keyid, B const&);
        void setValue(int valueid, B const&);
        
};