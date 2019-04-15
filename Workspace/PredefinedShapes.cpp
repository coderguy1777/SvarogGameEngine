#include "PredefinedShapes.h"
#include "GameEngineHeader.h"
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
	glColor3f(0.5, 0.1, 0.3);
	glutWireCube(cubesize);
	glPopMatrix();
}

void Shapes::changecubesize(int val) {
	cubesize = val;
}

void Shapes::vertexgen(int size, float a, float b, float c) {
	vector<GLfloat>test;
	for(unsigned int i = 0; i < size; i++) {
		test.push_back((float)i * 0.0f);
	}

	for(unsigned int j = 0; j < test.size(); j++) {
		cout << test[j] << endl;
	}

	float v1, v2, v3 = 0.0f;
	for(unsigned int k = 0; k < test.size(); k++) {
		v1 = (float)k + a;
		for(unsigned int l = 1; l < k; l = l + 1) {
			v2 = (float)l + b;
			for(unsigned int m = 2; m < l; m = m + 2) {
				v3 = (float)m + c;
			}
			cout << v1 << endl;
			cout << v2 << endl;
			cout << v3 << endl;
		}
	}
}
 
