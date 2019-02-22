#include <SDL2/SDL.h>

class EngineRunner {
	public: 
		// Running Boolean
		bool running;
		// Takes input for events in the game engine window
		SDL_Event events;
		// Handling Input
		void InputManager();
		// Renders shit in the engine in this case
		void renderingManager();
};

void EngineRunner::InputManager() {
    while(SDL_PollEvent(&events)) {
		// If a quit occurs and closes it.
        if(events.type == SDL_QUIT)
            running = false;
    }
}

void EngineRunner::renderingManager() {
	// Tets
}

int main(int argc, char **) {
	SDL_Init(SDL_INIT_VIDEO);
	SDL_Window *window = SDL_CreateWindow("Svarog Game Engine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 600, 400, SDL_WINDOW_SHOWN);
	SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, 0);
	SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
	SDL_RenderClear(renderer);
	SDL_RenderPresent(renderer);
	SDL_ShowWindow(window);
	return 0;
}