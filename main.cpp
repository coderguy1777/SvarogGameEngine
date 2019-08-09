#include "main.h"
using namespace std;
int main() {
	String title("Svarog Game Engine");
	enginecore::initializeWindow(800, 600, title.str);
	return 0;
}