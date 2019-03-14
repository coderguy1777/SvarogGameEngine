#include "GameEngineHeader.h"
#include "EngineCamera.h"
using namespace std;
float lz = 0.0f;
float ly = 0.0f;
float lx = 0.0f;
bool delta = true;

void keyboard(unsigned char key, int x, int y) {
	switch(key) {
		case 28:
			glRotatef(20.0, 0.9, 0.6, 0.5);
	}
}

void drawshittyobj() {
glBegin(GL_QUADS);
	{
		glColor3f(0.5, 0.0, 0.0);
		glVertex3f(-0.5, 0.0, 0.0);
		glVertex3f(0.5, 0.0, 0.5);
		glVertex3f(0.5, 0.5, 0.0);
		glVertex3f(-0.5, 0.5, 0.5);

		glColor3f(0.5, 0.9, 0.2);
		glVertex3f(0.5, -0.5, 0.0);
		glVertex3f(0.5, 0.0, 0.0);
		glVertex3f(-0.5, 0.0, 0.0);
		glVertex3f(-0.5, -0.5, 0.0);
		
		// More of cube top side
		glColor3f(0.1, 1.0, 0.627);
		glVertex3f(-0.5, 0.5, 0.0);
		glVertex3f(0.5, 0.5, 0.0);
		glVertex3f(0.5, 0.8, -0.5);

		glColor3f(0.1, 1.0, 0.627);
		glVertex3f(-0.5, 0.5, 0.5); // Left side of top
		glVertex3f(-0.3, 0.8, 0.0); // Corner 3 of top
		glVertex3f(0.7, 0.8, 0.5); // Corner 2 of top
		glVertex3f(0.5, 0.5, -0.5); // Right side of top.

		// Patches for the top side of cube
		glColor3f(0.1, 1.0, 0.627);
		glVertex3f(-0.5, 0.5, 0.5);
		glVertex3f(0.5, 0.5, 0.5); 
		glVertex3f(0.0, 0.5, 0.0);


	}
	glEnd();
	glBegin(GL_QUADS);
	{
		glColor3f(0.9, 0.2, 0.5);
		glVertex3f(0.5, 0.0, 0.5);
		glVertex3f(0.7, 0.8, 0.5);
		glVertex3f(0.5, 0.5, 0.0);
		glVertex3f(0.5, -0.5, 0.0);
	}
	glEnd();
}

void display(void) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	glMatrixMode(GL_MODELVIEW);
	GLfloat ambientLight[] = {0.3f, 0.3f, 0.3f, 1.0f};
  	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambientLight);
	gluLookAt(0.0f, 0.0f, 0.0f, lx, lx + lz,  lz, -1.0f, -1.0f,  -1.0f);
	drawshittyobj();
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
		lz = lz * 1.10;
		glutPostRedisplay();
	}

	if(key == 'a') {
		lz = lz - 5;
		glutPostRedisplay();
	}

	if(key == 'w') {
		ly = ly + 5;
		glutPostRedisplay();
	}

	if(key == 's') {
		ly = ly - 5;
		glutPostRedisplay();
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
	glutReshapeFunc(changeSize);
	glMatrixMode(GL_MODELVIEW);
	glEnable(GL_DEPTH_TEST | GL_LIGHT0 | GL_LIGHTING);
	glutMainLoop();
  	return 1;
}