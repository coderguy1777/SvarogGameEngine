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
#include "math/vec3.h"
#include "math/vec2.h"
using namespace std;
struct Vector3Debug {
    string vector;
};

class Debugger {
    public:
        string filename;
        vector<float>floatarrdebug;
        vector<double>doublearrdebug;
        vector<int>intarrdebug;
        vector<float>vec3debug;
        vector<float>vec2debug;
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
            floatArrdata.open("~Documents/SvarogGameEngine/debugger/debuglogs/"  + this->filename);
            floatArrdata << arrTitle << endl;
            for(unsigned int i = 0; i < floatarrdebug.size(); i++) {
                floatArrdata << floatarrdebug[i] << endl;
            }
            floatArrdata.close();
        }

        void writeDoubleArr(const char* arrTitle) {
            ofstream doubleArrdata;
            doubleArrdata.open("~Documents/SvarogGameEngine/debugger/debuglogs/" + this->filename);
            doubleArrdata << arrTitle << endl;
            for(unsigned int i = 0; i < doublearrdebug.size(); i++) {
                doubleArrdata << doublearrdebug[i] << endl;
            }
            doubleArrdata.close();
        }

        void writeIntArr(const char* arrTitle) {
            ofstream intArrdata;
            intArrdata.open("~Documents/SvarogGameEngine/debugger/debuglogs/"  + this->filename);
            intArrdata << arrTitle << endl;
            for(unsigned int i = 0; i < intarrdebug.size(); i++) {
                intArrdata << intarrdebug[i] << endl;
            }
            intArrdata.close();
        }

        void streamVector3(Vector3 x);
        void writeVector3(const char* vec3Title);
        void streamVector2(Vector2 x);
        void writeVector2(const char* vec2Title);
};