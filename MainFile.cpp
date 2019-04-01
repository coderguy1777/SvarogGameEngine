#include "Camera/EngineCamera.h"
#include "PredefinedObjects/PredefinedShapes.h"
using namespace std;
float lz = 0.0f;
float x  = 0.0f;
float y = 0.0f;
float z = 5.0f;
float ly = 0.0f;
float lx = 0.0f;
float cameraz = 30.0f;
float angle = 0.0f;
int xOrgin = -1;
float deltaAngle = 1.0f;
bool delta = true;
bool test = false;
bool test2 = false;
int a = 0;

static int menuid;
static int submenu_id;
static int value = 0;
static int windowvar;

void menu(int num) {
	if(num == 0) {
		glutDestroyWindow(0);
		exit(0);
	} else {
		value = num;
	}

}


void display(void) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	glMatrixMode(GL_MODELVIEW);
	GLfloat ambientLight[] = {0.3f, 0.3f, 0.3f, 1.0f};
  	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambientLight);
	gluLookAt(lx, ly / 360, cameraz, lx, sin(ly), lz, lx, 12.0f, lz);
	Shapes ssss;


	// Intiates the tester polygon for this scene
	int jumpcount = 0;
	if(test == true) {
		ssss.testerpolygon();
	
	}
	if(test2 == true && test == true) {
		glPushMatrix();
		glRotatef(5, 0, 1, 0);
		gluLookAt(cos(lx), ly / z, cameraz, lx, sin(ly), lz, cos(lx), 12.0f, lz);
		glPopMatrix();
	}
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
	}

	if(key == 'a') {
		lx = lx + 1;
		glutPostRedisplay();
	}

	if(key == 'w') {
		lz = lz + 1;
		z = sin(lz);
		glutPostRedisplay();
		cameraz = cameraz -1;
	}

	if(key == 's') {
		lz = lz - 1;
		a = 1;
		glutPostRedisplay();
		cameraz = cameraz + 1;
	}
	if(key == 32) {
		cout << "Space has been pressed!" << endl;
		test = true;
		ly = ly - 1;
		cout << ly << endl;
	}
	if(key ==  'r') {
		ly = ly + 1;
	}
	if(key == 'v') {
		test = false;
		test2 = false;
		lx = 0.0f;
		ly = 0.0f;
		lz = 0.0f;
		cout << "Ctrl has been pressed" << endl;
	}
}

void processSpecialKeys(int key, int xx, int yy) {

	float fraction = 0.1f;

	switch (key) {
		case GLUT_KEY_LEFT :
			angle -= 0.001f;
			lx = (angle);
			lz = -(angle);
			break;
		case GLUT_KEY_RIGHT :
			angle += 0.001f;
			lx = -angle;
			lz = angle;
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

void mouseMove(int x, int y) {

	// this will only be true when the left button is down
	if (xOrgin >= 0) {
		deltaAngle = (x + xOrgin) * 0.001f;
		lx = -(angle + deltaAngle);
		lz = (angle- deltaAngle);
	}
	if(xOrgin <= 0) {
		deltaAngle = (x + xOrgin) * 0.001f;
		lx = -(angle + deltaAngle);
		lz = (angle + deltaAngle);
	}
}

void mouseButton(int button, int state, int x, int y) {

	// only start motion if the left button is pressed
	if (button == GLUT_LEFT_BUTTON) {

		// when the button is released
		if (state == GLUT_UP) {
			angle += deltaAngle * 2;
			xOrgin = -1;
		}
		else  {// state = GLUT_DOWN
			xOrgin = -x;
		}
	}

	if(button == GLUT_RIGHT_BUTTON) {
		if(state == GLUT_UP) {
			angle += deltaAngle / 2;
			xOrgin = -1;
		}
		else {
			xOrgin = -x;
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
	glutDisplayFunc(display);
	glutKeyboardFunc(processNormalKeys);
	glutSpecialFunc(processSpecialKeys);
	glutReshapeFunc(changeSize);
	glutMouseFunc(mouseButton);
	glutMotionFunc(mouseMove);
	glutIdleFunc(display);
	glutSpaceballRotateFunc(processSpecialKeys);
	glutSpaceballMotionFunc(processSpecialKeys);
	glMatrixMode(GL_MODELVIEW);
	glEnable(GL_DEPTH_TEST | GL_LIGHT0 | GL_LIGHTING);
	glutMainLoop();
  	return 1;
}