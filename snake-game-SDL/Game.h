#pragma once
#include "Snake.h"
#include "SDL.h"
#include "SDL_image.h"
#include "Apple.h"

class Game {
private: 
	bool isRunning; 
	SDL_Window* window; 
	static SDL_Renderer* renderer; 
	bool hasFailed; 

	// sprites
	Snake* snake; 
	Apple* apple;
public:
	Game();
	~Game(); 

	void init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
	void handleEvents(); 
	void update(); 
	void render(); 
	void clean(); 
	
	bool running() { return isRunning; };
	void fail();

	static SDL_Renderer* getRenderer() { return renderer; }; 
};
