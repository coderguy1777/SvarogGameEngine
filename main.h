#include "EngineHeader.h"
#include "core/String.h"
namespace enginecore {

    int width, height;

    void initializeWindow(int w, int h, String title) {
        const char* name = "bhellol";
        width = w;
        height = h;
        glutInitDisplayMode(GLUT_DEPTH | GLUT_RGBA | GLUT_DOUBLE);
        glEnable(GL_DEPTH_TEST);
        glutInitWindowSize(width, height);
        glutMainLoop();

    }
}