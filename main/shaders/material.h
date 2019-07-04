#pragma once
#ifdef MATERIAL_H
#define MATERIAL_H
#endif
#include<iostream>
#include<sstream>
#include<fstream>
#include<string>
#include<glad/glad.h>
#include "core/String.h"
#include "core/ArrayList.h"
#include "math/vec4.h"
using namespace std;

class Material {
    public:
        unsigned int shaderID;
        Material(String vertexShaderPath, String fragmentShaderPath) {
            // shader info
            string vertshader;
            string fragshader;
            ifstream vertexShader;
            ifstream fragmentShader;
            const char* vertShadercode;
            const char* fragShaderCode;
            vertexShader.exceptions(ifstream::failbit);
            fragmentShader.exceptions(ifstream::failbit);

            // reads file for shader info
            try {
                vertexShader.open(vertexShaderPath.str);
                fragmentShader.open(fragmentShaderPath.str);
                std::stringstream vertShaderStream, fragShaderStream;
                vertShaderStream << vertexShader.rdbuf();
                fragShaderStream << fragmentShader.rdbuf();
                vertexShader.close();
                fragmentShader.close();
                vertshader = vertShaderStream.str();
                fragshader = fragShaderStream.str();
                // file info read into str
            } catch (ifstream::failure e) {
                cout << "SHADER FAILURE TO COMPILE" << endl;
            }
            const char* vShaderCode = vertshader.c_str();
            const char* fShaderCode = fragshader.c_str();

            // vertex shader compile
            unsigned int vertexshader = glCreateShader(GL_VERTEX_SHADER);
            glShaderSource(vertexshader, 1, &vShaderCode, nullptr);
            glCompileShader(vertexshader);
            checkcomperrors(vertexshader, "VertexShader");

            // fragment shader compile
            unsigned int fragmentshader = glCreateShader(GL_FRAGMENT_SHADER);
            glShaderSource(fragmentshader, 1, &fShaderCode, NULL);
            glCompileShader(fragmentshader);
            checkcomperrors(fragmentshader, "FragmentShader");

            // shader program
            shaderID = glCreateProgram();
            glAttachShader(shaderID, vertexshader);
            glAttachShader(shaderID, fragmentshader);
            glLinkProgram(shaderID);
            checkcomperrors(shaderID, "Main");

            // deletes shaders from memory
            glDeleteShader(vertexshader);
            glDeleteShader(fragmentshader);

        }
        void use() {
            glUseProgram(shaderID);
        }

        void setBool(const string &name, bool val) const {
            glUniform1i(glGetUniformLocation(shaderID, name.c_str()), (int)val);
        }

        void setInt(const string &name, int val) const {
            glUniform1i(glGetUniformLocation(shaderID, name.c_str()), val);
        }

        void setFloat(const string &name, float val) const {
            glUniform1i(glGetUniformLocation(shaderID, name.c_str()), val);
        }

    private:
        // shader compile check
        void checkcomperrors(unsigned int fragment, string type) {
            int success;
            char info[1024];
            if(type != "Main") {
                glGetShaderiv(fragment, GL_COMPILE_STATUS, &success);
                if(!success) {
                    glGetShaderInfoLog(fragment, 1024, NULL, info);
                    cout << "Shader type: " << type << "had an error on compile" << endl;
                    cout << "Error info: " << info << endl;
                } 
            } else {
                glGetShaderiv(fragment, GL_LINK_STATUS, &success);
                if(!success) {
                    glGetProgramInfoLog(fragment, 1024, NULL, info);
                    cout << "Error! Shader program failed to compile" << endl;
                    cout << "Error info: " << info[0] << endl;
                }
            }
        }
};