#include "main/svarogengine/svarogengine.h"


void loop() {
	
}

int main() {
	// SvarogEngine* engine = new SvarogEngine();
	SvarogEngine::getInstanceEngine()->RunEngine(loop);

	return 0;
}
// camera trans idea, for on key trans, for the camera to move
// in a game, from a keymap value