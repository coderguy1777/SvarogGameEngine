#include "PredefinedShapes.h"
using namespace std; 

void Shapes::testerpolygon() {
  glBegin(GL_POLYGON);
		glColor3f(0.5, 0.0, 0.0);
		glVertex3f(-0.5, 0.0, 0.0);
		glVertex3f(0.5, 0.0, 0.5);
		glVertex3f(0.5, 0.5, 0.0);
		glVertex3f(-0.5, 0.5, 0.5);
	glEnd();
	glBegin(GL_POLYGON);
		glColor3f(0.5, 0.9, 0.2);
		glVertex3f(0.5, -0.5, 0.0);
		glVertex3f(0.5, 0.0, 0.0);
		glVertex3f(-0.5, 0.0, 0.0);
		glVertex3f(-0.5, -0.5, 0.0);
	glEnd();
	glBegin(GL_POLYGON);		
		glColor3f(0.1, 1.0, 0.627);
		glVertex3f(-0.5, 0.5, 0.0);
		glVertex3f(0.5, 0.5, 0.0);
		glVertex3f(0.5, 0.8, -0.5);
	glEnd();
}

void Shapes::planepolygon() {
	// Defintion of shape polygon for the plane of the scene in this case.
	glBegin(GL_QUADS);
	{
		glVertex3f(-1000.0f, -20.0f, -1000.0f);
		glVertex3f(-1000.0f, -20.0f, 1000.0f);
		glVertex3f(1000.0f, -20.0f, 1000.0f);
		glVertex3f(1000.0f, -20.0f, -1000.0f);
		glColor3f(0.1f, 0.6f, 0.4f);
	}
	glEnd();
}


void Shapes::cube() {
	glPushMatrix();
	glColor3f(0.5, 0.1, 1.0);
	glutWireCube(cubesize);
	glPopMatrix();
}

void Shapes::changecubesize(int val) {
	cubesize = val;
}