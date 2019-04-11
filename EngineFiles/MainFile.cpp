#include "EngineCamera.h"
#include "Point.h"
#include "PredefinedShapes.h"
using namespace std;
float lx = 0.0f;
float ly = 0.0f;
float lz = 5.0f;
float camerax = 0.0f;
float cameray = 0.0f;
float cameraz = 0.0f;
float theta, phi = 0.0f;
float oldx, oldy = 0.0f;
float eyex, eyey, eyez = 0.0f;
bool rotate = false;

void OnMouseDown(int button, int state, int x, int y) {
	if(button = GLUT_LEFT_BUTTON) {
		if(state = GLUT_UP) {
			camerax = lx * cos(phi) * sin(theta);
		} else {
			camerax = camerax;
		}
	}
}

void OnMouseMove(int x, int y) {

	oldx = lx;
	oldy = ly;
}

void display(void) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	glMatrixMode(GL_MODELVIEW);
	GLfloat ambientLight[] = {0.3f, 0.3f, 0.3f, 1.0f};
  	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambientLight);
	Vertex camerapoint((double)lx, (double)ly, (double)lz);
	double normavg = camerapoint.MeanofPoints((double)lx, (double)ly, (double)lz);
	Vertex translatedpoint(camerapoint.up1(camerapoint));
	translatedpoint.printVertex(translatedpoint);
	// Setting up of the camera matrix.
	eyex = lx + 1.0f * cos(phi) * sin(theta);
	eyey = ly + 1.0f * sin(phi) * sin(theta);
	eyez = lz + 2 * 3.14 * sin(phi);
	gluLookAt(lx, ly, cameraz, eyex, eyey, eyez, 0.0f, 1.0f, 0.0f);
	Shapes ssss;
	// Test Shape
	ssss.testerpolygon();

	// for updating the scene with the polygons involved in this case.
	glPushMatrix();
	glutSwapBuffers();
	glFlush();
	glPopMatrix();
}

// Scales the window to fit the needed ibjects inside that window.
void changeSize(int w, int h) {
	if (h == 0) 
		h = 1;
	float ratio =  w * 1.0 / h;
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glViewport(0, 0, w, h);
	// Resizes the window for viewability by the camera.
	gluPerspective(45.0f, w/h, 1.0f, 100.0f);
	glMatrixMode(GL_MODELVIEW);
}

void processNormalKeys(unsigned char key, int x, int y) {
	// Process the esc key, and ends the program.
	unsigned char key2;
	Shapes sssss;
	if (key == 27) { 
		exit(0);
	}

  	if(key == 'd') {
		lx = lx - 1;
		camerax = camerax - 1.0f;
		glutPostRedisplay();
	}

	if(key == 'a') {
		lx = lx + 1;
		glutPostRedisplay();
		camerax = camerax + 1.0f;
	}

	if(key == 'w') {
		lz = lz + 1;
		cameraz = cameraz - 1;
		glutPostRedisplay();
	}

	if(key == 's') {
		lz = lz - 1;
		cameraz = cameraz + 1;
		glutPostRedisplay();
	}

	if(key == 'v') {
		ly = ly + 1;
		glutPostRedisplay();
	}

	if(key == 32) {
		ly = ly - 1;
		glutPostRedisplay();
	}
}

void idle() {
	glutPostRedisplay();
}

void specialkey(int key, int x, int y) {
	switch(key) {
	case GLUT_KEY_RIGHT:
		break;
	case GLUT_KEY_LEFT:
		glRotatef( -3, 0, 1, 0 );
		cout << "Works!" << endl;
		break;
	}
}

void mouseMove(int x, int y) {
	if(camerax >= 0) {
		lx = sin(camerax + theta);
		lz = -cos(cameraz + phi);
			theta += (lx - oldx)*0.01f;
	phi += (ly - oldy) * 0.01f;
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
	glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH); 
	glutInitWindowSize(800, 600);
	glutCreateWindow("Svarog Game Engine");
	glutDisplayFunc(display);
	glutKeyboardFunc(processNormalKeys);
	glutMouseFunc(OnMouseDown);
	glutMotionFunc(mouseMove);
	glutReshapeFunc(changeSize);
	glutIdleFunc(idle);
	glMatrixMode(GL_MODELVIEW);
	glEnable(GL_DEPTH_TEST | GL_LIGHT0 | GL_LIGHTING);
	glutMainLoop();
  	return 1;
}