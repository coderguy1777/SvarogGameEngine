#include "shader_mg.h"
ShaderManager* ShaderManager::getShaderManager() {
    if(!shader_mg) shader_mg = new ShaderManager; return shader_mg;
}

void ShaderManager::insert_mat(SvarogMaterial material) {
    vert_li.add(VertShaderPair{material.get_vert(), static_cast<unsigned int>(vert_li.size() + 1)});
    frag_li.add(FragShaderPair{material.get_frag(), static_cast<unsigned int>(frag_li.size() + 1)});
}



ShaderManager *ShaderManager::shader_mg = 0;