#include "libs.h"
using namespace std;
int main() {
	String title("Svarog Game Engine");
	int w = 800;
	int h = 600;
	Application a(Window(w, h, title), true);
	a.SvarogAppLoop();
	return 0;
}