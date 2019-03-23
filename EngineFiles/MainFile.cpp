#include "Camera/EngineCamera.h"
#include "PredefinedObjects/PredefinedShapes.h"
using namespace std;
float lz = 0.0f;
float x  = 0.0f;
float z = 5.0f;
float ly = 0.0f;
float lx = -1.0f;
float angle = 0.0f;
int xOrgin = -1;
float deltaAngle = 0.0f;
bool delta = true;


void display(void) {
	Sleep(1);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	glMatrixMode(GL_MODELVIEW);
	GLfloat ambientLight[] = {0.3f, 0.3f, 0.3f, 1.0f};
  	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambientLight);
	gluLookAt(0.0f + lx, 1.0f, 30.0f + lz, lx, 0.0f, lz, 0.0f, 1.0f,  lz);
	Shapes ssss;
	// Intiates the tester polygon for this scene
	ssss.testerpolygon();
	// for updating the scene with the polygons involved in this case.
	glPushMatrix();
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
	// Resizes the window for viewability by the camera.
	gluPerspective(45.0f, w/h, 1.0f, 100.0f);
	glMatrixMode(GL_MODELVIEW);
}

void processNormalKeys(unsigned char key, int x, int y) {
	// Process the esc key, and ends the program.
	if (key == 27) { 
		exit(0);
	}
	// Processes the D Key
  	if(key == 'd') {
		lx = lx - 1;
		glutPostRedisplay();
	}
	// Processes the A Key
	if(key == 'a') {
		lx = lx + 1;
		glutPostRedisplay();
	}
	// Processes the W Key
	if(key == 'w') {
		lz = lz + 1;
		glutPostRedisplay();
	}
	// Processes the S key
	if(key == 's') {
		lz = lz - 1;
		glutPostRedisplay();
	}
}


void mouseMove(int x, int y) {
	// this will only be true when the left button is down
	if (xOrgin >= 0) {
		deltaAngle = (x - xOrgin) * 0.001f;
		lx = -sin(angle + deltaAngle);
		lz = cos(angle + deltaAngle);
		cout << lx << endl;		
		cout << lz << endl;
	}
}

void mouseButton(int button, int state, int x, int y) {
	// only start motion if the left button is pressed
	if (button == GLUT_LEFT_BUTTON) {
		// when the button is released
		if (state == GLUT_UP) {
			angle += deltaAngle;
			xOrgin = -1;
		}
		else  {
			xOrgin = x;
		}
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
	glutWarpPointer(3, 3);
	glutDisplayFunc(display);
	glutKeyboardFunc(processNormalKeys);
	glutReshapeFunc(changeSize);
	// Processes mouse movement
	glutMouseFunc(mouseButton);
	glutMotionFunc(mouseMove);
	// Sets up the idle function
	glutIdleFunc(display);
	glMatrixMode(GL_MODELVIEW);
	glEnable(GL_DEPTH_TEST | GL_LIGHT0 | GL_LIGHTING);
	glutMainLoop();
  	return 1;
}