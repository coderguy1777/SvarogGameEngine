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
        int vertSize, posSize;
        float VertexData[12];
        unsigned int positions[6];

        // TODO: get pointers working for dynamic array size;
        Shape(float verts[], unsigned int pos[]) {
            for(int i = 0; i < 12; i++) {
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
            bool eboCheck = checkEBONEED();
            if(eboCheck == true) {
                glGenVertexArrays(1, &VAO);
                glGenBuffers(1, &VBO);
                glGenBuffers(1, &EBO);
                glBindVertexArray(VAO);
                glBindBuffer(GL_ARRAY_BUFFER, VBO);
                glBufferData(GL_ARRAY_BUFFER, sizeof(VertexData), VertexData, GL_STATIC_DRAW);
                glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
                glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(positions), positions, GL_STATIC_DRAW);
                glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
                glEnableVertexAttribArray(0);
                glBindBuffer(GL_ARRAY_BUFFER, 0);
                glBindVertexArray(0);
            } else if(eboCheck == false) {
                std::cout << "NO EBO" << std::endl;
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
        }

};