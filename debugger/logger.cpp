#include "logger.h"

void Debugger::streamVector3(Vector3 x) {
    vec3debug.push_back(x.initx);
    vec3debug.push_back(x.inity);
    vec3debug.push_back(x.initz);
    vec3debug.push_back(x.vec3Mag());
}

void Debugger::writeVector3(const char* vec3title) {
    ofstream floatVec3data;
    floatVec3data.open("/home/jordan/Documents/SvarogGameEngine/debugger/debuglogs/"  +this->filename);
    floatVec3data << vec3title << endl;
    char coordid[4] = {'X' , 'Y', 'Z', 'M'};
    for(unsigned int i = 0; i < vec3debug.size(); i++) {
        floatVec3data << coordid[i] << vec3debug[i] << endl;
    }
    floatVec3data.close();
}