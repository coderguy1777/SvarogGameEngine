#include "EngineCamera.h"
#include "PredefinedShapes.h"
#include "ShapeMenus.h"
using namespace std;
float lx = 0.0f;
float ly = 0.0f;
float lz = 0.0f;
float camerax = 0.0f;
float cameray = 0.0f;
float cameraz = 0.0f;

void display(void) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	glMatrixMode(GL_MODELVIEW);
	gluLookAt(lx, ly, lz, camerax, cameray, cameraz, 0.0f, 1.0f, 0.0f);
	keyInput();
	keyInput2();
	glutSwapBuffers();
	glFlush();
}

// Scales the window to fit the needed ibjects inside that window.
void changeSize(int w, int h) {
	if (h == 0) {
		h = 1;
	}

	float ratio =  w * 1.0 / h;
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glViewport(0, 0, w, h);
	gluPerspective(45.0f, ratio, 1.0f, 100.0f);
	glMatrixMode(GL_MODELVIEW);
}

void processNormalKeys(unsigned char key, int x, int y) {
	// Process the esc key, and ends the program.
	if (key == 27) { 
		exit(0);
	}

  	if(key == 'd') {
		lx = lx + 1.0f;
		camerax = camerax - 1.0f;
		glutPostRedisplay();
	}

	if(key == 'a') {
		lx = lx - 1.0f;
		camerax = camerax + 1.0f;
		glRotatef(90.0, 1.0, 0.0, 0.0);
		glutPostRedisplay();
	}

	if(key == 'w') {
		lz = lz - 1.0f;
		cameraz = cameraz + 1.0f;
		glutPostRedisplay();
	}

	if(key == 's') {
		lz = lz + 1.0f;
		cameraz = cameraz - 1.0f;
		glutPostRedisplay();
	}

	if(key == 'v') {
		ly = ly - 1.0f;
		cameray = cameray - 1.0f;
		glutPostRedisplay();
	}

	if(key == 32) {
		ly = ly + 1.0f;
		cameray = cameray + 1.0f;
		glutPostRedisplay();
	}
}

void idle() {
	glutPostRedisplay();
}

void init() {
	glClearColor(1.0, 1.0, 1.0, 0.0);
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
	glEnable(GL_DEPTH_TEST | GL_LIGHT0 | GL_LIGHTING);
	glutMainLoop();
  	return 1;
}