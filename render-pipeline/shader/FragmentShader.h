#pragma once
#ifndef FRAGMENTSHADER_H
#define FRAGMENTSHADER_H
#include "SvarogShader.h"

class FragmentShader : public SvarogShader {
    public: 
        virtual void set_use_state() override;
        virtual bool get_use_state() const override;
        virtual void init_state(unsigned int state) override;
        virtual unsigned int get_initstate() const override;
        virtual void set_code(const char* code) override;
        virtual const char* get_code() const override;
        virtual void compile_shader() override;
        virtual unsigned int get_shader_id() override;
        ~FragmentShader();
};
#endif