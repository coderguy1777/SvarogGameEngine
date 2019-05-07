#include "EngineHeader.h"
#include "COLORS.h"
#include "Vector.h"
#include <vector>
#include <glm/glm.hpp>
using namespace std;

int fac = 0;
std::vector<rgba>colors;

Vector vec(0, 0, 0);
void test(unsigned char key, int x, int y) {
	Vector vec(0, 0, 0);
	if (key == 'w') {
		fac += 1;
		vec.setX(fac);
		vec.x += 1;
		glTranslatef(vec.x, 0.0f, 0.0f);
		glutPostRedisplay();
	}

	if (key == 's') {
		fac -= sin(1);
		vec.z -= sin(1);
		vec.setX(fac);
		glutPostRedisplay();
	}


	vec.printX();
}

void init() {
	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glFrustum(-1, 1, -1.5, 1.5, 1, 2000);
}

void renderScene(void) {
	HSV wanted(255, 20, 1);
	wanted.findHue();
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
	glMatrixMode(GL_MODELVIEW);	
	wanted.createHSV();
	init();
	glutSwapBuffers();
}


int main(int argc, char **argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glEnable(GL_DEPTH_TEST);
	glutInitWindowSize(800, 600); //optional
	glutCreateWindow("OpenGL First Window");
	glutDisplayFunc(renderScene);
	glutKeyboardFunc(test);
	glutMainLoop();
}