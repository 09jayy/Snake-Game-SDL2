#include "Game.h"
#include "Snake.h"
#include "Entity.h"
#include "Apple.h"
#include "SDL_image.h"
#include <iostream>
#include <string>
#include "SDL_ttf.h"
#include "Text.h"

SDL_Renderer* Game::renderer = nullptr; 

// default methods for constructor and destructure
Game::Game() : isRunning(false), window(nullptr), hasFailed(false), snake(nullptr), apple(nullptr) {};
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
	Game::apple = new Apple(240, 240, 40, 40, "apple");

	// create snake
	Game::snake = new Snake(renderer); 

	std::cout << "APPLE COORDS: " << apple->getX() << ", " << apple->getY() << "\n";
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
				snake->changeDirection('n'); 
				break; 
			case SDL_SCANCODE_DOWN:
				std::cout << "down" << "\n";
				snake->changeDirection('s'); 
				break; 
			case SDL_SCANCODE_LEFT:
				std::cout << "left" << "\n";
				snake->changeDirection('w'); 
				break; 
			case SDL_SCANCODE_RIGHT:
				std::cout << "right" << "\n";
				snake->changeDirection('e'); 
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
	if (!hasFailed) {
		snake->move();
	}

	//check if the snake is out of bounds
	if (snake->isOutOfBounds() || snake->checkSelfCollision()) {
		this->fail();
	}

	// check if snake has eaten apple

	if (snake->checkAppleCollision(apple)) {
		snake->grow();
		apple->setRandPosition();
	}; 
}

void Game::render() {
	//clear renderer buffer
	SDL_RenderClear(renderer);  

	// render apple
	apple->render(renderer);

	// render snake
	snake->render();
	//std::cout << "SNAKE COORDS: " << snake->getHead()->getX() << ", " << snake->getHead()->getY() << "\n";

	if (hasFailed) {
		Text gameOver("GAME OVER", "Minecraft.ttf", 48);
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
