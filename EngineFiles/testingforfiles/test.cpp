#include<iostream>
#include<vector>
#include<map>
using namespace std;


struct test {
    double x, y, z;
};

int main() {
    vector<double>test1;
    vector<double>test2;
    vector<double>test3;
    test1.push_back(1.23);
    test1.push_back(1.23);
    test1.push_back(1.23);
    test2.push_back(1.232);
    test2.push_back(1.232);
    test2.push_back(1.232);
    test3.push_back(1.223);
    test3.push_back(1.223);
    test3.push_back(1.223);



    vector<test>pointsli; 
    for(unsigned int i = 0; i < test1.size(); i++) {
        double i2 = test1[i];
        for(unsigned int j = 0; j < test2.size(); j++) {
            double j2 = test2[j];
            for(unsigned int k2 = 0; k2 < test3.size(); k2++) {
                double k = test3[k2];
                pointsli.push_back({i2, j2, k});
            }
        }
    }

    for(unsigned int i = 0; i < pointsli.size(); i++) {
        cout << "(" << pointsli[i].x << " : " << pointsli[i].y << " : " << pointsli[i].z << ")" << '\n' << endl;
        
    }
}