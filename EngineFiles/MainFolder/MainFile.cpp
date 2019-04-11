#include "EngineCamera.h"
#include "PredefinedShapes.h"
using namespace std;
float lx = 0.0f;
float ly = 0.0f;
float lz = 0.0f;
float cameraz = 0.0f;

// Display method.
void display(void) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	glMatrixMode(GL_MODELVIEW);
	GLfloat ambientLight[] = {0.3f, 0.3f, 0.3f, 1.0f};
  	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambientLight);
	gluLookAt(lx, ly, cameraz, lx, ly, lz, 0.0f, 1.0f, 0.0f);
	Sleep(1);
	Shapes ssss;
	ssss.testerpolygon();
	glPushMatrix();
	glutSwapBuffers();
	glFlush();
	glPopMatrix();
}

// Window Scaling Method
void changeSize(int w, int h) {
	if (h == 0) 
		h = 1;
	float ratio =  w * 1.0 / h;
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glViewport(0, 0, w, h);
	gluPerspective(45.0f, w/h, 1.0f, 100.0f);
	glMatrixMode(GL_MODELVIEW);
}

// Key function for movement linearally.
void processNormalKeys(unsigned char key, int x, int y) {
	// Process the esc key, and ends the program.
	if (key == 27) { 
		exit(0);
	}

	// Processes D Key
  	if(key == 'd') {
		lx = lx + 1.0f;
		glutPostRedisplay();
	}

	// Processes the A Key
	if(key == 'a') {
		lx = lx - 1.0f;
		glutPostRedisplay();
	}

	// Processes the W Key
	if(key == 'w') {
		lz = lz + 1.0f;
		cameraz = cameraz - 1;
		glutPostRedisplay();
	}

	// Processes the S Key
	if(key == 's') {
		lz = lz - 1.0f;
		cameraz = cameraz + 1;
		glutPostRedisplay();
	}

	// Processes the V Key
	if(key == 'v') {
		ly = ly + 1.0f;
		glutPostRedisplay();
	}

	// Processes Space
	if(key == 32) {
		ly = ly - 1.0f;
		glutPostRedisplay();
	}
}

// Idle Function
void idle() {
	glutPostRedisplay();
}

// Main method of the engine.
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
	glEnable(GL_DEPTH_TEST | GL_LIGHT0 | GL_LIGHTING);
	glutMainLoop();
  	return 1;
}