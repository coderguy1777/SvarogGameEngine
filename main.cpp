#include "main.h"
using namespace std;

void doCompare() {
	ArrayList<int>testLi;
	for(int i = 0; i < 4; i++) {
		testLi.add(i);
	}

	int temp1 = testLi.get(0);
	int temp2 = testLi.get(1);
	int temp3 = testLi.Max(temp1, temp2);
	cout << "Max is: " << temp3 << endl;
}

int main() {
	doCompare();
	String title("Svarog Game Engine");
	enginecore::initializeWindow(800, 600, title.str);
	return 0;
}