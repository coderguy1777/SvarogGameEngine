#pragma once
#ifndef SHADER_EDITOR_CACHE_H
#define SHADER_EDITOR_CACHE_H
#include <memory>
#include <stack>
#include "spdlog/spdlog.h"
#include <boost/thread.hpp>

class ShaderCache {
    private:
        static ShaderCache* cache_instance;
        ShaderCache() {};
        std::vector<float>m_values;
        float m_specular;
        float m_roughness;

    public: 
        static ShaderCache* getShaderCache();
        void updateRoughnessState(float m_r);
        void updateSpecularState(float m_s);
        void updateColorValues(std::vector<float>m_v);
        std::vector<float>get_m_values() const;
        float get_m_spec() const;
        float get_m_roughness() const;

};  

#endif