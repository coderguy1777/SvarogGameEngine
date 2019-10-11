#include "shader_mg.h"
ShaderManager* ShaderManager::getShaderManager() {
    if(!shader_manager) {
        shader_manager = new ShaderManager;
    }
    return shader_manager;
}

void ShaderManager::compile_vertex() {

}

void ShaderManager::compile_fragment() {

}

void ShaderManager::test(SvarogMaterial a) {
    a.set_primary_color_model(COLOR_MODEL::RGB_MODEL);
    bool cmyk_tst = (a.get_primary_color_model() == COLOR_MODEL::ARGB_MODEL) ? true : false;
    bool rgb_tst = (a.get_primary_color_model() == COLOR_MODEL::RGB_MODEL) ? true : false;
    if(a.get_primary_color_model() == COLOR_MODEL::RGB_MODEL) {
        a.set_rgb(Rgb(1.0f, 1.0f, 1.0f));
        spdlog::warn(cmyk_tst);
        spdlog::warn(rgb_tst);
    }
}

ShaderManager *ShaderManager::shader_manager = 0;