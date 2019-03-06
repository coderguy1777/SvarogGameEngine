#include "GameEngineHeader.h"
#include "STLParser.h"
using namespace std;

void StlFileParser::stlreader(string fname, vector<double>xyzvecs) {
    ifstream myFile(fname.c_str(), ios::in | ios::binary);
    char header_info[80] = "";
    char nTri[4];
    unsigned long nTriLong;
    if(myFile) {
        myFile.read(header_info, 80);
        cout << "Header info: " << header_info << endl;
    } else {
        cout  << "An Error has occurred in parsing the file, try again later." << endl;
    }
}