#pragma once
#ifdef SHADERGEN_H
#define SHADERGEN_H
#endif 
#include "math/vec3.h"
#include "core/ds-classes/ArrayList.h"
#include "math/matrix2f.h"
#include "main/color/Color.h"
using namespace std;

// struct for layout locations
struct LayoutLoc {
    int locnum;
    Vector3 inputparam;
};
class Shader {
    public:
        // creates shader file 
        String shaderName;
        const char* shaderExtension;
        ArrayList<Rgb>colors;
        ArrayList<String>mat4s;
        ArrayList<String>layoutLocations;
        ArrayList<String>inParams;
        Shader(String sName, const char* fileType) {
            this->shaderName = sName;
            this->shaderExtension = fileType;
        }
        
        void addColors(Rgb Color);
        void createGLSLRGB();
        void addLocationParam(LayoutLoc location);
        void createGLSL_locationParams();

};