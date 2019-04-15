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
float lfar = 100.0f;
float cameray = 0.0f;
float cameraz = 0.0f;
float test = 0.0f;

Shape shapeVar(20, 20, 20, 20);

// Scales the window to fit the needed ibjects inside that window.
void changeSize(int w, int h) {
	if (h == 0) {
		h = 1;
	}

	float ratio =  w * 1.0 / h;
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glViewport(0, 0, w, h);
	gluPerspective(45.0f, ratio, 1.0f, lfar + 900.0f);
	glMatrixMode(GL_MODELVIEW);
	cout << cameraz << endl;
}

void display(void) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
	glLoadIdentity();
	glMatrixMode(GL_MODELVIEW);
	gluLookAt(lx, ly, cameraz, lx, ly, lz, 0.0f, 1.0f, cameraz);
	glOrtho(0.0, 1.0, 1.0, 1.0, 2.0, 1.0);
	Shape *Shape;
	ShapeStruct shapeVar(20, 20, 20, 20);
	Shape = &shapeVar;

	glPushMatrix();
	keyInput();
	Shape->drawShape();
	keyInput2();
	glPopMatrix();
	glutSwapBuffers();
	glFlush();
}

void processNormalKeys(unsigned char key, int x, int y) {
	// Process the esc key, and ends the program.
	Shapes Shapesss;
	Shapesss.vertexgen(3, lx, ly, cameraz);
	if (key == 27) { 
		exit(0);
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
		cameray = cameray - 1.0f;
		glutPostRedisplay();
	}

	if(key == 32) {
		ly -= 1.0f;
		cameray = cameray - 1.0f;
		glutPostRedisplay();
	}
}

void idle() {
	Shapes ss;
	ss.cube();
	glutPostRedisplay();
}

void init() {
	glClearColor(0.0, 0.0, 0.0, 0.1);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_TEXTURE_3D);
	glDepthMask(GL_TRUE);
	glDepthFunc(GL_LEQUAL);
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