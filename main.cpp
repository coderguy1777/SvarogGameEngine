#include "EngineHeader.h"
#include "Color.h"
#include "core/Vector.h"
#include <vector>
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
}


void init() {
	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glFrustum(-1, 1, -1.5, 1.5, 1, 2000);
}

void renderScene(void) {
	HSV test(19, 31, 211);
	test.createHSV();
	Color newColor(test.HSVtoRGB(test));
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
	glMatrixMode(GL_MODELVIEW);	
	newColor.newColor();
	init();
	glutSwapBuffers();
}


int main(int argc, char **argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glEnable(GL_DEPTH_TEST);
	glutInitWindowSize(800, 600); 
	glutCreateWindow("Svarog Game Engine");
	glutDisplayFunc(renderScene);
	glutKeyboardFunc(test);
	glutMainLoop();
}