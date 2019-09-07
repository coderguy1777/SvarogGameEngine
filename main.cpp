#include "main/enginewindow/enginewindow.h"
#include "main/svarogengine/svarogengine.h"
int main() {
	SvarogEngine* engine = new SvarogEngine();
	engine->RunEngine();
	return 0;
}

// camera trans idea, for on key trans, for the camera to move
// in a game, from a keymap value