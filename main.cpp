#include "main/enginewindow/enginewindow.h"
#include "main/svarogengine/svarogengine.h"
int main() {
	SvarogEngine* engine = new SvarogEngine();
	engine->RunEngine();
	return 0;
}