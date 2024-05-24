#include "Game.h" 
#include "Snake.h" 
#include "Entity.h"
#include "SDL_image.h"
#include <iostream>
#include <string>
#include "SDL_ttf.h"
#include "Text.h"

// default methods for constructor and destructure
Game::Game() : isRunning(false), renderer(nullptr), window(nullptr), hasFailed(false), snake(nullptr), apple(nullptr) {};
Game::~Game() {};

void Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen) {
	int flags = 0;

	if (fullscreen) {
		flags = SDL_WINDOW_FULLSCREEN;
	}

	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
		std::cout << "GAME INITIALISED" << "\n";

		TTF_Init(); 

		window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
		if (window) {
			std::cout << "Window Created" << "\n";
		}

		renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
		if (renderer) {
			SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
			std::cout << "Renderer created" << "\n";
		}

		isRunning = true;
	}
	else {
		isRunning = false;
	}

	// create apple
	Game::apple = new Entity(renderer, "assets/apple.png", 100, 100, 40, 40, "apple");

	// create snake
	Game::snake = new Snake(renderer); 
};

void Game::fail() {
	hasFailed = true; 
}

void Game::handleEvents() {
	SDL_Event event;
	SDL_PollEvent(&event);

	switch (event.type) {
	case SDL_QUIT:
		isRunning = false;
		break;
	case SDL_KEYDOWN:
		switch (event.key.keysym.scancode) {
			case SDL_SCANCODE_UP:
				std::cout << "up" << "\n";
				break; 
			case SDL_SCANCODE_DOWN:
				std::cout << "down" << "\n";
				break; 
			case SDL_SCANCODE_LEFT:
				std::cout << "left" << "\n";
				break; 
			case SDL_SCANCODE_RIGHT:
				std::cout << "right" << "\n";
				break; 
			default:
				break; 
		}
	break; 
	default:
		break;
	} 
}

void Game::update() {
	// move snake
	snake->move(); 

	//check if the snake is out of bounds
	if (snake->isOutOfBounds()) {
		this->fail(); 
	}
}

void Game::render() {
	//clear renderer buffer
	SDL_RenderClear(renderer);  

	if (!hasFailed) {
		// render apple
		apple->render(renderer);

		// render snake
		snake->render(renderer);
	}
	else {
		Text gameOver("GAME OVER", "Minecraft.ttf",48);
		gameOver.setPosition("CENTER");
		gameOver.render(renderer);
	}

	// present renderer buffer
	SDL_RenderPresent(renderer);
}

void Game::clean() {
	delete apple; 
	delete snake; 
	SDL_DestroyWindow(window); 
	SDL_DestroyRenderer(renderer); 
	TTF_Quit(); 
	SDL_Quit(); 
	std::cout << "Game Closed" << "\n"; 
}
