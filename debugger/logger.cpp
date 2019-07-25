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

/*
Vector2 Debug stream
 */


//void Debugger::streamVector2(Vector2 vec2) {
  //  vec2debug.push_back(vec2.initx);
  //  vec2debug.push_back(vec2.inity);
  //  vec2debug.push_back(vec2.vec2Mag());
//}

//void Debugger::writeVector2(const char* vec2Title) {
  //  ofstream floatVec2data;
   // floatVec2data.open("/home/jordan/Documents/SvarogGameEngine/debugger/debuglogs/" + this->filename);
    //floatVec2data << vec2Title << endl;
    //char coordid[3] = {'X', 'Y', 'M'};
   // for(unsigned int i = 0; i < vec2debug.size(); i++) {
   //     floatVec2data << coordid[i] << vec2debug[i] << endl;
  //  }
   // floatVec2data.close();
//}