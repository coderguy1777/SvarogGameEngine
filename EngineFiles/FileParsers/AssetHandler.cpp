#include "GameEngineHeader.h"
#include "AssetHandler.h"
using namespace std;


void AssetImports::fileinputter(string filename) {
    if(filename.find('.stl') == string::npos) {
        exit;
    } else {
        stlfiles.push_back(filename);
    }

    if(filename.find('.obj') == string::npos) {
        exit;
    } else {
        objfiles.push_back(filename);
    }

    if(filename.find('.fbx') == string::npos) {
        exit;
    } else {
        fbxfiles.push_back(filename);
    }

}