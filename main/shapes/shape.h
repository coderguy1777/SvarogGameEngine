#pragma once
#ifndef SHAPE_H
#define SHAPE_H
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <vector>
#include "main/enginewindow/enginewindow.h"
#include "core/ds-classes/Array.h"
#include "core/String.h"
class Shape {
    public:
        // TODO: get pointers working for dynamic array size;
        Shape(std::vector<float>VertData, std::vector<unsigned int>PosData):
            VertexData(VertData), PositionData(PosData)
        {createMesh();}
        Shape(){}
        
        void genVertexArrays();
        void draw();
        void useEBO();
        void noEBO();
        bool checkEBONEED();
        void noEBOdraw();

        void drawFunc() {
            bool ebo = checkEBONEED();
            if(ebo) {
                draw();
            } else if(!ebo) {
                noEBOdraw();
            }
        }

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
                glBufferData(GL_ARRAY_BUFFER, VertexData.size() * sizeof(float), &VertexData.front(), GL_STATIC_DRAW);
                glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
                glBufferData(GL_ELEMENT_ARRAY_BUFFER, PositionData.size() * sizeof(unsigned int), &PositionData.front(), GL_STATIC_DRAW);
                glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
                glEnableVertexAttribArray(0);
                glBindBuffer(GL_ARRAY_BUFFER, 0);
                glBindVertexArray(0);
                draw();
            } else if(eboCheck == false) {
                std::cout << "NO EBO" << std::endl;
                glGenVertexArrays(1, &VAO);
                glGenBuffers(1, &VBO);
                glBindVertexArray(VAO);
                glBindBuffer(GL_ARRAY_BUFFER, VBO);
                glBufferData(GL_ARRAY_BUFFER, VertexData.size() * sizeof(float), &VertexData.front(), GL_STATIC_DRAW);
                glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
                glEnableVertexAttribArray(0);
                glBindBuffer(GL_ARRAY_BUFFER, 0);
                glBindVertexArray(0);
            }
        }
        bool needEBO;
        std::vector<float>VertexData;
        std::vector<unsigned int>PositionData;

};
#endif