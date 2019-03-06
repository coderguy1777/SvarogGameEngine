#include "GameEngineHeader.h"
#include "EngineCamera.h"
#include "Polygon.h"
using namespace std;

class VerticiesDefinition {
public:
	// Defines the verticies of the shape in x, y, z format.
	// vertset1 being for x.
	// vertset2 being for y.
	// vertset3 being for z.
	vector<double>vertset1;
	vector<double>vertset2;
	vector<double>vertset3;
	float timevector;

	void spacevectors() {
		for (unsigned int i = 0; i < vertset1.size(); i++) {
			cout << "Verticies for X: " << vertset1[i] << endl;
		}
		cout << '\n' << endl;
		for (unsigned int j = 0; j < vertset2.size(); j++) {
			cout << "Verticies for Y: " << vertset2[j] << endl;
		}
		cout << '\n' << endl;
		for (unsigned int k = 0; k < vertset3.size(); k++) {
			cout << "Verticies for Z: " << vertset3[k] << endl;
		}
	}

};

namespace vectorshit {
	vector<double>test1;
	vector<double>test2;
	vector<double>test3;
	double doubleRand() {
		// 1.0 defined as max of the interval, with the for loop
		// looping variable being defined as the low value of the interval,
		// or can just be 0 in this case.
		return double(rand()) / (double(RAND_MAX) + 20.0);
	}

	void testrun() {
		for (unsigned int i = 0; i < 10; i++) {
			double ii = doubleRand();
			test1.push_back(ii);
		}
		for (unsigned int j = 0; j < 10; j++) {
			double jj = doubleRand();
			test2.push_back(jj);
		}
		for (unsigned int k = 0; k < 10; k++) {
			double kk = doubleRand();
			test3.push_back(kk);
		}
	}
}

void display(void)
{
	double i;
	double j;
	double k;
	vector<veccoordinates>points;
	VerticiesDefinition vectret;
	for(unsigned int x = 0; x < vectret.vertset1.size(); x++) {
		i = vectret.vertset1[x];
		for(unsigned int y = 0; y < vectret.vertset2.size(); y++) {
			j = vectret.vertset2[y];
			for(unsigned int z = 0; z < vectret.vertset3.size(); z++) {
				k = vectret.vertset3[z];
			}
		}
	}
}


void VectorPopulation() {
	VerticiesDefinition vertDef;
	double i;
	double j;
	double k;
	vector<veccoordinates>points;
	vectorshit::testrun();
	for (unsigned int i2 = 0; i2 < vectorshit::test1.size(); i2++) {
		i = vectorshit::test1[i2];
		vertDef.vertset1.push_back(i);
	}
	for (unsigned int j2 = 0; j2 < vectorshit::test2.size(); j2++) {
		j = vectorshit::test2[j2];
		vertDef.vertset2.push_back(j);
	}
	for (unsigned int k2 = 0; k2 < vectorshit::test3.size(); k2++) {
		k = vectorshit::test3[k2];
		vertDef.vertset3.push_back(k);
	}
	vertDef.spacevectors();
}

int main(int nargin, char* varargin[]) {
	SvarogEngineCamera camobj;
	Polygon testpily;
	testpily.x = 1.2f;
	testpily.y = 1.3f;
	testpily.z = 1.34f;
	testpily.getPolygon(testpily);
	VectorPopulation();
  	return 0;
}