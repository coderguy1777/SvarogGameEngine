#include "EngineHeader.h"
#include "COLORS.h"
#include "Vector.h"
#include <vector>

std::vector<rgba>colors;
void shapetest(int verts) {
	glBegin(GL_POLYGON);
	for (int i = 0; i <= verts; i++) {
		glColor3f(i / 3, i / 2, i / 3);
		for (int j = 0; j <= verts; j++) {
			glVertex3f(i, j, i + j);
			glVertex3f(-i, -j, -(i + j));

		}
	}

	glEnd();
}

void COlor() {
	HSV bg(121 * -1, 77, 121);
	bg.createHSV();
}

void renderScene(void) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
	glMatrixMode(GL_MODELVIEW);
	COlor();
	glutSwapBuffers();
}


int main(int argc, char **argv) {
	colors.push_back({ 0.1, 0.2, 0.4 });
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glEnable(GL_DEPTH_TEST);
	glutInitWindowSize(800, 600); //optional
	glutCreateWindow("OpenGL First Window");
	glutDisplayFunc(renderScene);
	glutMainLoop();
}