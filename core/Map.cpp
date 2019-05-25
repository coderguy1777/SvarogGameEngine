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

        void getKey(A const&, B const&);
};