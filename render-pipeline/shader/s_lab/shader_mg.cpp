#include "shader_mg.h"
ShaderManager* ShaderManager::getShaderManager() {
    if(!shader_manager) shader_manager = new ShaderManager; return shader_manager;
}


void ShaderManager::compile_vertex() {

}

void ShaderManager::compile_fragment() {

}



ShaderManager *ShaderManager::shader_manager = 0;