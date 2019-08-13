#include "libs.h"
using namespace std;
int main() {
	String title("Svarog Game Engine");
	int w = 800;
	int h = 600;
	Window aa(w, h, title);
	Keyboard ab(aa);
	Application a(aa, true);
	a.SvarogAppLoop();
	return 0;
}