#pragma once
#ifndef SHAPE_H
#define SHAPE_H
#include "core/ds-classes/Array.h"
#include "core/String.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>
class Shape {
    private:
        bool needEBO;
        void setSize() {
            posdata.setSize(6);
            vertdata.setSize(12);
        }
        Array<float>vertdata;
        Array<unsigned int>posdata;
    public:
        // TODO: get pointers working for dynamic array size;
        Shape(Array<float>VertData, Array<unsigned int>PosData):
            vertdata(VertData), posdata(PosData)
        {setSize();}
        Shape();
        
        void genVertexArrays();
        void draw();
        void useEBO();
        void mesh() {
            createMesh();
        }
        void noEBO();
        bool checkEBONEED();

    private: 
        GLuint VAO, VBO, EBO;
        void createMesh() {
            bool eboCheck = checkEBONEED();
           // float arr[vertdata.length()];
           // for(int i = 0; i < vertdata.length(); i++) {
            //    arr[i] = vertdata.get_pos(i);
            //}
            //if(arr[0] > -1.0) {
                //std::cout << "Array works" << std::endl;
            //}
            if(eboCheck == true) {
                glGenVertexArrays(1, &VAO);
                glGenBuffers(1, &VBO);
                glGenBuffers(1, &EBO);
                glBindVertexArray(VAO);
                glBindBuffer(GL_ARRAY_BUFFER, VBO);
                glBufferData(GL_ARRAY_BUFFER, sizeof(vertdata.array), vertdata.array, GL_STATIC_DRAW);
                glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
                glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(posdata.array), posdata.array, GL_STATIC_DRAW);
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
                glBufferData(GL_ARRAY_BUFFER, vertdata.length() * sizeof(Array<float>), &vertdata.array[0], GL_STATIC_DRAW);
                glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
                glEnableVertexAttribArray(0);
                glBindBuffer(GL_ARRAY_BUFFER, 0);
                glBindVertexArray(0);
            }
        }


};
#endif