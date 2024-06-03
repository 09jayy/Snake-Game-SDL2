#include "Apple.h"
#include "Entity.h"
#include "Game.h"
#include "SDL.h"
#include "SDL_image.h"
#include <iostream>
#include <string> 
#include <cstdlib> 

Apple::Apple(int x, int y, int width, int height, std::string name) : Entity(x, y, width, height, name) {
	setTexture(Game::getRenderer(), "assets/apple.png");
};

Apple::Apple(int x, int y, int width, int height) : Entity(x, y, width, height) {
	setTexture(Game::getRenderer(), "assets/apple.png");
};

Apple::~Apple() {};

void Apple::setTexture(SDL_Renderer* renderer, const char* texturePath) {
	SDL_Surface* surface = IMG_Load(texturePath);
	texture = SDL_CreateTextureFromSurface(renderer, surface);
	SDL_FreeSurface(surface);
};

void Apple::setRandPosition() {
	int x = rand() % 20 * 40;
	int y = rand() % 20 * 40;
	this->setX(x);
	this->setY(y);

	std::cout << "Apple position: " << x << ", " << y << "\n";
};