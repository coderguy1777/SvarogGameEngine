#include "shader_editor_cache.h"
ShaderCache* ShaderCache::getShaderCache() {
    if(!cache_instance) {
        cache_instance = new ShaderCache;
    }
    return cache_instance;
}

void ShaderCache::updateRoughnessState(float m_r) {
    m_roughness = m_r;
}

void ShaderCache::updateSpecularState(float m_s) {
    m_specular = m_s;
}

void ShaderCache::updateColorValues(std::vector<float>m_v) {
    m_values = m_v;
    spdlog::info(sizeof(m_values));
}

std::vector<float>ShaderCache::get_m_values() const {
    return m_values;
}

float ShaderCache::get_m_spec() const {
    return m_specular;
}
ShaderCache* ShaderCache::cache_instance = 0;