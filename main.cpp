#include "main/window/window.h"
Window win(1280, 720, "Svarog Engine");
void loop() {
	win.run_window();
}

int main() {
	// SvarogEngine* engine = new SvarogEngine();
	loop();
	return 0;
}
// camera trans idea, for on key trans, for the camera to move
// in a game, from a keymap value