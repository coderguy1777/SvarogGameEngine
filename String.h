#include<string>
#include<iostream>
#include<vector>
using namespace std;

char* parse(char parseit[8]) {
        string x = "";
        vector<char>test;
        int length = 0;
        for(int i= 0; i < 8;  i++) {
                x += parseit[i];
                test.push_back(parseit[i]);
        }

        for(unsigned int j = 0; j < test.size(); j++) {
            length++;
            std::cout << length << std::endl;
            if(test[j] == ' ') {
                length -= 1;
                std::cout << "Null found" << std::endl;
                break;
            }
        }

        cout << x << endl;
        cout << length << endl;
}

int main() {
        
        char x[8] = {'e', 'l', 'o', 'w', 'o', 'd', ' '};
        parse(x);
        return 0;
}


