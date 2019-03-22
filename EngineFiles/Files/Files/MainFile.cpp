#include "GameEngineHeader.h"
#include "EngineCamera.h"
#include "PredefinedShapes.h"
using namespace std;
float lz = 0.0f;
float x  = 0.0f;
float z = 5.0f;
float ly = 0.0f;
float lx = -1.0f;
float angle = 0.0f;
bool delta = true;

void keyboard(unsigned char key, int x, int y) {
	switch(key) {
		case 28:
			glRotatef(20.0, 0.9, 0.6, 0.5);
	}
}

void display(void) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	glMatrixMode(GL_MODELVIEW);
	GLfloat ambientLight[] = {0.3f, 0.3f, 0.3f, 1.0f};
  	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambientLight);
	gluLookAt(0.0f + lx, 1.0f, 30.0f + lz, lx, 0.0f, lz, 0.0f, 1.0f,  lz);

	Shapes ssss;
	ssss.testerpolygon();
	ssss.planepolygon();
	glTranslatef(-30.0f, 0.0f, -30.0f);
	glPushMatrix();
	glutSwapBuffers();
	glFlush();
}

// Scales the window to fit the needed ibjects inside that window.
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

void idlefunc() {
	if(delta) {
		
	}
}

void processNormalKeys(unsigned char key, int x, int y) {
	int mod;
	cout << lx << endl;
	cout << lz << endl;
	if (key == 27) { 
		exit(0);
	}
  	if(key == 'd') {
		lx = lx - 1;
		glutPostRedisplay();
	}

	if(key == 'a') {
		lx = lx + 1;
		glutPostRedisplay();
	}

	if(key == 'w') {
		lz = lz + 1;
		glutPostRedisplay();
	}

	if(key == 's') {
		lz = lz - 1;
		glutPostRedisplay();
	}
}

void processSpecialKeys(int key, int xx, int yy) {

	float fraction = 0.1f;

	switch (key) {
		case GLUT_KEY_LEFT :
			angle -= 0.01f;
			lx = sin(angle);
			lz = -cos(angle);
			break;
		case GLUT_KEY_RIGHT :
			angle += 0.01f;
			lx = sin(angle);
			lz = -cos(angle);
			break;
		case GLUT_KEY_UP :
			x += lx * fraction;
			z += lz * fraction;
			break;
		case GLUT_KEY_DOWN :
			x -= lx * fraction;
			z -= lz * fraction;
			break;
	}
}


// Main method of the engine that launches 
// the main window that will be displayed in the game
// engine itself when opened by the user in this case
// mainly due to the arguments being present, in 
// this case argc, and argv, which allow for the game
// engine to function as normal in this case.
int main(int argc, char **argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode ( GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH); 
	glutInitWindowSize(800, 600);
	glutCreateWindow("Svarog Game Engine");
	glutDisplayFunc(display);
	glutKeyboardFunc(processNormalKeys);
	glutSpecialFunc(processSpecialKeys);
	glutReshapeFunc(changeSize);
	glutIdleFunc(display);
	glMatrixMode(GL_MODELVIEW);
	glEnable(GL_DEPTH_TEST | GL_LIGHT0 | GL_LIGHTING);
	glutMainLoop();
  	return 1;
}