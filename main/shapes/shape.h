#pragma once
#ifdef SHAPE_H
#define SHAPE_H
#endif
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "core/String.h"
class Shape {
    private:
        bool needEBO;
    public:
        float VertexData[9];
        int positions[6];

        Shape(float verts[9], int pos[6]) {
            for(int i = 0; i < 9; i++) {
                VertexData[i] = verts[i];
            }

            for(int j = 0; j < 6; j++) {
                positions[j] = pos[j];
            }
            createMesh();
        }
        
        Shape(){}
        void genVertexArrays();
        void draw();
        void useEBO();
        void noEBO();
        bool checkEBONEED();
    private: 
        GLuint VAO, VBO, EBO;

        void createMesh() {
            glGenVertexArrays(1, &VAO);
            glGenBuffers(1, &VBO);
            glBindVertexArray(VAO);
            glBindBuffer(GL_ARRAY_BUFFER, VBO);
            glBufferData(GL_ARRAY_BUFFER, sizeof(VertexData), VertexData, GL_STATIC_DRAW);
            glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
            glEnableVertexAttribArray(0);
            glBindBuffer(GL_ARRAY_BUFFER, 0);
            glBindVertexArray(0);
        }

};