#include "main/enginewindow/enginewindow.h"
using namespace std;
int main() {
	Application a;
	a.set_bool_state();
	a.VSYNC_on();
	a.SvarogAppLoop();
	return 0;
}