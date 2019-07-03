#include "material.h"
template<typename T>
ArrayList<T>Material::createShader() {
    ArrayList<String>fileparams = new ArrayList<>();
    fileparams.add(versionNum + '\n');
    fileparams.add(locationVar + '\n');
    fileparams.add()
}

void Material::writeShader(ArrayList<String>file, String filepath, String filename) {
    ofstream shader;
    shader.open(filename.str);
    for(unsigned int i = 0; i < file.size(); i++) {
        shader << file.get(i).str;
    }
    shader.close();
}