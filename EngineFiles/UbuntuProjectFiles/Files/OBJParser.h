#pragma once
#ifdef OBJPARSER_H
#define OBJPARSER_H
#endif
#include "GameEngineHeader.h"
using namespace std;

class ObjFileParser {
    private:

    public:
        void objparser(string fname, vector<double>xyzcoordinates);
        void debugmethod();
        vector<string>successfulparse;
        vector<string>errorsduringparse;
        string error = "Failure";
        string success = "Successfully Parsed!";
};