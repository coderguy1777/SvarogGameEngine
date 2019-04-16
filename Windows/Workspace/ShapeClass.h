#pragma once
#ifdef SHAPECLAASS_H
#define SHAPECLAASS_H
#endif
#include "GameEngineHeader.h"
#include<GL/glut.h>
using namespace std;
class Shape {
    private:
        int width, height, glintslice, glheight;
    public:
        void *shape;
        float x, y, z;
        Shape drawShapes(int shapeamount);
        Shape(int width, int height, int glintslice, int glheight) {
            this->width = width;
            this->height = height;
            this->glintslice = glintslice;
            this->glheight = glheight;
        }        
        virtual void drawShape() {
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
            glPushMatrix();
            glTranslatef(0.0f, 0.0f, -10.0f);
            glutWireCone(width, height, glintslice, glheight);
            glPopMatrix();
            glutSwapBuffers();
            glFlush();
        }

        virtual void showShape() {
            exit;
        }
};

class ShapeStruct:public Shape {
    private:
        int width, height, glintslice, glheight;
    
    public:
        ShapeStruct(int width = 0, int height = 0, int glintslice = 0, int glheight = 0):Shape(width,  height, glintslice, glheight) {}
        void drawShape() {
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
            glEnable(GL_DEPTH);
            glPushMatrix();
            glColor3f(0.1, 0.5, 0.2);
            glutSolidCube(30);
            glPopMatrix();
        }

        void showShape() {
            glTranslatef(-5.0f, 0.0f, 0.0f);
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
            glEnable(GL_DEPTH);
            glPushMatrix();
            glColor3f(0.1, 0.5, 0.4);
            glutSolidCube(40);
            glPopMatrix();
        }
};