#pragma once
#ifdef ASSETHANDLER_H
#define ASSETHANDLER_H
#endif
#include "GameEngineHeader.h"
using namespace std;

class AssetImports {
    private:
        double maxsize = 2000000.0;
        double minsize = 0.00000000000039;
    public:
        vector<string>stlfiles;
        vector<string>objfiles;
        vector<string>fbxfiles;
        void fileinputter(string filename);
        void fileparser(string filevar);
        void fileoutputter();
        void datahandler();
};