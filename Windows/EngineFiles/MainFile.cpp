#include "EngineCamera.h"
#include "Point.h"
#include "PredefinedShapes.h"
using namespace std;
float lz = 5.0f;
float x  = 0.0f;
float y = 0.0f;
float z = 5.0f;
float ly = 0.0f;
float lx = 0.0f;
float cameraz = 30.0f;
float camerax = 0.0f;
float angle = 0.0f;
int xOrgin = -1;
float deltaAngle = 1.0f;
bool delta = true;
bool test = false;
bool test2 = false;



void display(void) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	glMatrixMode(GL_MODELVIEW);
	GLfloat ambientLight[] = {0.3f, 0.3f, 0.3f, 1.0f};
  	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambientLight);
	Vertex camerapoint((double)lx, (double)ly, (double)lz);
	double normavg = camerapoint.MeanofPoints((double)lx, (double)ly, (double)lz);
	Vertex translatedpoint(camerapoint.ScalarMove(camerapoint, normavg));
	gluLookAt(lx, 1.0f , cameraz, translatedpoint.x, translatedpoint.y, translatedpoint.z, 0.0f, 1.0f, 0.0f);
	cout << translatedpoint.x << " " << translatedpoint.y << " " << translatedpoint.z << endl;
	Shapes ssss;
	Sleep(1);
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
	Shapes sssss;
	if (key == 27) { 
		exit(0);
	}
  	if(key == 'd') {
		lx = lx - 1;
		glutPostRedisplay();
		camerax = camerax - 1.0f;
	}

	if(key == 'a') {
		lx = lx + 1;
		glutPostRedisplay();
		camerax = camerax + 1.0f;
	}

	if(key == 'w') {
		lz = lz + 1;
		glutPostRedisplay();
		cameraz = cameraz -1;
	}

	if(key == 's') {
		lz = lz - 1;
		glutPostRedisplay();
		cameraz = cameraz + 1;
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
	glutIdleFunc(display);
	glMatrixMode(GL_MODELVIEW);
	glEnable(GL_DEPTH_TEST | GL_LIGHT0 | GL_LIGHTING);
	glutMainLoop();
  	return 1;
}