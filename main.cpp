#include "main/enginewindow/enginewindow.h"
#include "main/svarogengine/svarogengine.h"
int main() {
	/* Application a;
	a.set_bool_state();
	a.VSYNC_on();
	a.SvarogAppLoop();
	*/
	SvarogEngine* engine = new SvarogEngine();
	engine->RunEngine();
	return 0;
}