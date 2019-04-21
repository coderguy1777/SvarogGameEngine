#define GLEW_STATIC
#define GLFW_DLL
#include<GL/glew.h>
#include<GLFW/glfw3.h>
#include "EngineCamera.h"
#include "PredefinedShapes.h"
#include "FontClass.h"
#include "ShapeMenus.h"
#include "ShapeClass.h"
using namespace std;
float lx = 0.0f;
float ly = 0.0f;
float lz = 0.0f;
float camerax = 0.0f;
float cameraz = 0.0f;
Shape shapeVar(20, 20, 20, 20);

// Scales the window to fit the needed ibjects inside that window.
void changeSize(int w, int h) {
	if (h == 0) {
		cout << clock() << endl;
		h = 1;
	}

	float ratio =  w * 1.0 / h;
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glViewport(0, 0, w, h);
	gluPerspective(45.0f, ratio, 1, 1000);
	glMatrixMode(GL_MODELVIEW);
	glScalef(0.5, 1.5, 0.5);

	cout << cameraz << endl;
}

void display(void) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
	glLoadIdentity();
	gluLookAt(0.0, 0.0, cameraz, lx, ly, -lz, 0.0f, 1.0f, 0.0f);
	Sleep(1);

	// Shape test
	Shapes shaepe;
	Shape *Shape;
	ShapeStruct shapeVar(20, 20, 20, 20);
	Shape = &shapeVar;
	glPushMatrix();
	keyInput();
	keyInput2();
	for(int i = -3; i < 60; i++) {
		for(int j = -3; j < 60; j++) {
			glPushMatrix();
			glTranslatef(i * 10, 0.0f, j * 10);
			shaepe.cube();
			glPopMatrix();
		}
	}
	glPopMatrix();
	glutSwapBuffers();
	glFlush();
}

void idle() {
	Shapes ss;
    ss.cube();
	ss.cube();
	glutPostRedisplay();
}

void processNormalKeys(unsigned char key, int x, int y) {
	// Process the esc key, and ends the program.
	Shapes Shapesss;
	if (key == 27) { 
		exit(0);
	}

	if(key == 'o') {
		cameraz -= 100.0f;
	}

  	if(key == 'd') {
		lx -= 1.0f;
		camerax = camerax - 1.0f;
		Shapesss.xsize += 1.0f;
		glutPostRedisplay();
	}

	if(key == 'a') {
		lx += 1.0f;
		camerax = camerax + 1.0f;
		glutPostRedisplay();
	}

	if(key == 'w') {
		lz -= 1.0f;
		cameraz += 1.0f;
		glutPostRedisplay();
	}

	if(key == 's') {
		lz += 1.0f;
		cameraz -= 1.0f;
		glutPostRedisplay();
	}

	if(key == 'v') {
		ly += 1.0f;
		glutPostRedisplay();
	}

	if(key == 32) {
		ly -= 1.0f;
		glutPostRedisplay();
	}
}

void init() {
	glColor3f(0.0, 0.5, 0.0);
	glTranslatef(0.0f, -1000.0f, 0.0f);
	glutSolidCube(1000.0);
	glClearColor(0.0, 0.0, 0.0, 0.1);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_TEXTURE_2D);
	glDepthMask(GL_TRUE);
	glDepthRange(100.0, 1000.0);
	glDepthFunc(GL_LEQUAL);
	glEnable (GL_CULL_FACE);
	glCullFace (GL_BACK);
	glFrontFace (GL_CW);
	glClearDepth(1.0f);
}

// Main method of the engine that launches 
// the main window that will be displayed in the game
// engine itself when opened by the user in this case
// mainly due to the arguments being present, in 
// this case argc, and argv, which allow for the game
// engine to function as normal in this case.
int main(int argc, char **argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH); 
	glutInitWindowSize(800, 600);
	glutCreateWindow("Svarog Game Engine");
	glutDisplayFunc(display);
	glutKeyboardFunc(processNormalKeys);
	glutReshapeFunc(changeSize);
	glutIdleFunc(idle);
	glMatrixMode(GL_MODELVIEW);
	menuChoices();
	secondMenuChoices();
	init();
	glEnable(GL_DEPTH_TEST | GL_LIGHT0 | GL_LIGHTING | GL_DOUBLE);
	glutMainLoop();
  	return 1;
}