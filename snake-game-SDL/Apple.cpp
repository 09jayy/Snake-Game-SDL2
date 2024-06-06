#include "Apple.h"
#include "Entity.h"
#include "Game.h"
#include "SDL.h"
#include "SDL_image.h"
#include <iostream>
#include <string> 
#include <cstdlib> 
#include <ctime>

Apple::Apple(int x, int y, int width, int height, std::string name) : Entity(x, y, width, height, name) {
	setTexture("assets/apple.png");
};

Apple::Apple(int x, int y, int width, int height) : Entity(x, y, width, height) {
	setTexture("assets/apple.png");
};

Apple::~Apple() {};

bool Apple::seedRandGen() {
	std::srand(static_cast<unsigned int>(std::time(nullptr)));
	return true;
};

void Apple::setRandPosition() {
	static bool seeded = seedRandGen();

	int x = rand() % 21;
	int y = rand() % 21;
	this->setX(x * 40);
	this->setY(y * 40);

	std::cout << "Apple position: " << x << ", " << y << "\n";
};