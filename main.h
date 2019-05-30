#include "EngineHeader.h"
#include "core/String.h"
namespace enginecore {

    int width, height = 0;

    void initializeWindow(int w, int h, String title) {
        width = w;
        height = h;
        glutInitDisplayMode(GLUT_DEPTH | GLUT_RGBA | GLUT_DOUBLE);
        glEnable(GL_DEPTH_TEST);
        glutInitWindowSize(width, height);
        glutCreateWindow(title.str);
        glutMainLoop();
    }
}