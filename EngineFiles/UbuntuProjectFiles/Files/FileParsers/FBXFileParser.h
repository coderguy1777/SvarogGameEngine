#pragma once 
#ifdef FBXFILEPARSER_H
#define FBXFILEPARSER_H
#endif
#include "GameEngineHeader.h"
using namespace std;

class FBXFileParser {
    private:

    public: 
        void fbxparser(string fname, vector<double>xyzcoords);
        void debugmethod();
        vector<string>successfulparses;
        vector<string>errorsduringparse;
        string successfulparse = "Successfully Parsed";
        string failedparse = "Error during Parsing.";
};