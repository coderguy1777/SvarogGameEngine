#pragma once
#ifdef STLPARSER_H
#define STLPARSER_H
#endif
#include "GameEngineHeader.h"
using namespace std;

class StlFileParser {
    private:

    public:
        void stlreader(string fname, vector<double>xyzvecs);
        vector<string>filesuccesses;
        vector<string>filerrors;
        void debugmethod();
        string success = "Parsed";
        string failure = "Error in File Parsing.";
};