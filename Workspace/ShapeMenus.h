#pragma once
#ifdef SHAPEMENUS_H
#define SHAPEMENUS_H
#endif
#include "GameEngineHeader.h"
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
    if(switchcase == 1) {
        return;
    } else if(switchcase == 2) {
        glPushMatrix();
        glColor3f(1.0, 0.0, 1.0);
        glutWireSphere(20.0, 30.0, 30.0);
        glPopMatrix();
    } else if(switchcase == 3) {
        glPushMatrix();
        glColor3f(0.0, 0.45, 1.0);
        glutWireCube(30.0);
        glPopMatrix();
    } else if(switchcase == 4) {
        glTranslatef(0.0f, 0.0f, 5.0f);
    } else if(switchcase == 5) {
        glPushMatrix();
        glColor3f(0.0, 0.45, 1.0);
        glutSolidCube(30.0);
        glPopMatrix();
    }
}

void keyInput2(void) {
    if(switchcase2 == 1) {
        return;
    } else if(switchcase2 == 2) {
        glPushMatrix();
        glColor3f(1.0, 1.0, 0.0);
        glutWireSphere(20.0, 30.0, 30.0);
        glPopMatrix();
    }
}