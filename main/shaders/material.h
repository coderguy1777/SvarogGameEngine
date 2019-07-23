#pragma once
#ifdef MATERIAL_H
#define MATERIAL_H
#endif
#include<iostream>
#include<sstream>
#include<fstream>
#include<string>
#include<glad/glad.h>
#include "libs.h"
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

        void setVec2f(const string &name, float x, float y) {
            glUniform2f(glGetUniformLocation(shaderID, name.c_str()), x, y);
        }

        void setVec2f(const string &name, const Vector2 &vec2) const {
            glUniform2fv(glGetUniformLocation(shaderID, name.c_str()), GL_FALSE, &vec2.initx);
        }
        
        void setVec3f(const string &name, const Vector3 &vec3) const {
            glUniform3fv(glGetUniformLocation(shaderID, name.c_str()), GL_FALSE, &vec3.initx);
        }

        void setVec3f(const string &name, float x, float y, float z) const {
            glUniform3f(glGetUniformLocation(shaderID, name.c_str()), x, y, z);
        }

        void setVec4f(const string &name, const Vector3 &vec4) const {
            glUniform4fv(glGetUniformLocation(shaderID, name.c_str()), GL_FALSE, &vec4.initx);
        }

        void setVec4f(const string &name, float x, float y, float z, float w) const {
            glUniform4f(glGetUniformLocation(shaderID, name.c_str()), x, y, z, w);
        }

        void setMatrix2f(const string &name, const Matrix2f &matrix2) const {
            glUniformMatrix2fv(glGetUniformLocation(shaderID, name.c_str()), GL_FALSE, 1, &matrix2.matrix[0][0]);
        }

        void setMatrix3f(const string &name, const Matrix3f &matrix3) const {
            glUniformMatrix3fv(glGetUniformLocation(shaderID, name.c_str()), GL_FALSE, 1, &matrix3.matrix[0][0]);
        }

        void setMatrix4f(const string &name, const Matrix4f &matrix4) const {
            glUniformMatrix4fv(glGetUniformLocation(shaderID, name.c_str()), 1, GL_TRUE, &matrix4.mat[0][0]);
        }

    private:
        // shader compile check
        void checkcomperrors(unsigned int fragment, string type) {
            int success;
            char info[512];
            if(type != "Main") {
                glGetShaderiv(fragment, GL_COMPILE_STATUS, &success);
                if(!success) {
                    glGetShaderInfoLog(fragment, 512, NULL, info);
                    cout << "Shader type: " << type << "had an error on compile" << endl;
                    cout << "Error info: " << info << endl;
                } 
            } else {
                glGetShaderiv(fragment, GL_LINK_STATUS, &success);
                if(!success) {
                    glGetProgramInfoLog(fragment, 512, NULL, info);
                    cout << "Error! Shader program failed to compile" << endl;
                    cout << "Error info: " << info[0] << endl;
                }
            }
        }
};