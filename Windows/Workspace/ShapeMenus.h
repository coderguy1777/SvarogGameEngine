#pragma once
#ifdef SHAPEMENUS_H
#define SHAPEMENUS_H
#endif
#include "GameEngineHeader.h"
#include<GL/glfw3.h>
#include "PredefinedShapes.h"
#include<GL/glut.h>
using namespace std;

static int switchcase = 0;
static int submenuid;
static int menuid;
static int switchcase2 = 0;
static int submenuid2;
static int menuid2;

void menu(int num) {
    switchcase = num;
    glutPostRedisplay();
}

void menu2(int num) {
    switchcase2 = num;
    glutPostRedisplay();
}

void menuChoices(void) {
    submenuid = glutCreateMenu(menu);
    glutAddMenuEntry("Sphere", 2);
    glutAddMenuEntry("Wire Cube", 3);
    glutAddMenuEntry("Zoom in", 4);
    glutAddMenuEntry("Solid Cube", 5);
    glutAddMenuEntry("Solid Solid cube", 6);
    glutAddMenuEntry("Clear", 1);
    menuid = glutCreateMenu(menu);
    glutAddSubMenu("Draw", submenuid);
    glutAddMenuEntry("Quit", 0);
    glutAttachMenu(GLUT_RIGHT_BUTTON);
}

void secondMenuChoices(void) {
    submenuid2 = glutCreateMenu(menu);
    glutAddMenuEntry("Add another Sphere", 2);
    glutAddMenuEntry("Add another Wire Cube", 3);
    glutAddMenuEntry("Zoom in", 4);
    glutAddMenuEntry("Solid Cube", 5);
    menuid2 = glutCreateMenu(menu);
    glutAddSubMenu("Draw", submenuid2);
    glutAddMenuEntry("Quit", 0);
    glutAttachMenu(GLUT_LEFT_BUTTON);
}

void keyInput(void) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    if(switchcase == 1) {
        return;

    } else if(switchcase == 2) {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glPushMatrix();
        glColor3f(0.1, 0.5, 0.91);
        glutWireSphere(20.0, 30.0, 30.0);
        glPopMatrix();
        glFlush();
        glutSwapBuffers();

    } else if(switchcase == 3) {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glPushMatrix();
        glColor3f(0.0, 0.45, 1.0);
        glutWireCube(30.0);
        glPopMatrix();
        glutSwapBuffers();
        glFlush();

    } else if(switchcase == 5) {
        glClear(GLUT_RGB | GLUT_DEPTH | GLUT_DOUBLE);
        glTranslatef(0.0f, -100.0f, 0.0f);
        glPushMatrix();
        glPushMatrix();
        glColor3f(0.0, 0.45, 1.0);
        glutSolidCube(30.0);
        glTranslatef(-100.0f, 0.0f, 0.0f);
        glColor3f(0.2, 0.1, 1.0);
        glColor3f(0.9, 0.0, 0.1);
        glutSolidCube(20.0);
        glPopMatrix();
        glPopMatrix();
        glutSwapBuffers();
        glFlush();

    } else if(switchcase == 6) {
        Shapes obj;
        obj.cube();
        obj.changecubesize(20);
        glutPostRedisplay();
    }
}

void keyInput2(void) {
    if(switchcase2 == 1) {
        return;
    } else if(switchcase2 == 2) {
        glPushMatrix();
        glColor3f(1.0, 1.0, 0.0);
        glutWireSphere(20.0, 30.0, 30.0);
        glRotatef(90.0f, 1.0f, 20.0f, 0.0f);
        glTranslatef(-20.0f, 10.0f, 1.0f);
        glPopMatrix();
    }
}