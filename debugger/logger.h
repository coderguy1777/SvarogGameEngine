#pragma once
#ifdef LOGGER_H
#define LOGGER_H
#endif
#include<ostream>
#include<fstream>
#include<sstream>
#include<string>
#include<iostream>
#include<vector>
using namespace std;

class Debugger {
    public:
        string filename;
        vector<float>floatarrdebug;
        vector<double>doublearrdebug;
        vector<int>intarrdebug;
        Debugger(string classfilename) {
            this->filename = classfilename;
        }

        void streamFloatArr(float val) {
            floatarrdebug.push_back(val);
        }

        void streamDoubleArr(double val) {
            doublearrdebug.push_back(val);
        }

        void streamIntArr(int val) {
            intarrdebug.push_back(val);
        }

        void writeFloatArr(const char* arrTitle) {
            ofstream floatArrdata;
            floatArrdata.open(this->filename);
            floatArrdata << arrTitle << endl;
            for(unsigned int i = 0; i < floatarrdebug.size(); i++) {
                floatArrdata << floatarrdebug[i] << endl;
            }
            floatArrdata.close();
        }

        void writeDoubleArr(const char* arrTitle) {
            ofstream doubleArrdata;
            doubleArrdata.open(this->filename);
            doubleArrdata << arrTitle << endl;
            for(unsigned int i = 0; i < doublearrdebug.size(); i++) {
                doubleArrdata << doublearrdebug[i] << endl;
            }
            doubleArrdata.close();
        }

        void writeIntArr(const char* arrTitle) {
            ofstream intArrdata;
            intArrdata.open(this->filename);
            intArrdata << arrTitle << endl;
            for(unsigned int i = 0; i < intarrdebug.size(); i++) {
                intArrdata << intarrdebug[i] << endl;
            }
            intArrdata.close();

        }
};