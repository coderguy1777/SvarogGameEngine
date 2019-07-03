#pragma once
#ifdef MATERIAL_H
#define MATERIAL_H
#endif
#include<iostream>
#include<fstream>
#include "color/Color.h"
#include "core/String.h"
#include "core/ArrayList.h"
#include "math/vec2.h"
#include "math/vec3.h"
#include "math/vec4.h"
using namespace std;

class Material {
    private:
        String versionNum;
        String locationVar;
    public:
        unsigned int ID;
        Material(){}
        String inputVarLoc;
        String outputVar;
        String attribpos;
        int shaderType;
        Material(String inputVarLoc, String outputVar, String attribpos, int shaderType) {
            this->inputVarLoc = inputVarLoc;
            this->outputVar = outputVar;
            this->attribpos = attribpos;
            this->shaderType = shaderType;
            versionNum.str = "#version 330 core";
            if(shaderType == -1) {
                ID = 1; // means a vertex shader
            } else if(shaderType == 1) {
                ID = 2; // means fragment shader
            }
        }
        template<typename T>
        ArrayList<T>createShader();
        void writeShader(ArrayList<String>file, String filepath, String filename);
};