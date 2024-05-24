#include "Snake_Body.h"
#include "SDL.h"
#include "SDL_image.h"
#include "Entity.h"
#include <iostream>

Snake_Body::~Snake_Body() {};
Snake_Body::Snake_Body(SDL_Renderer* renderer, const char* texturePath, int x, int y, int width, int height, const char* name) : Entity(renderer, texturePath, x, y, width, height, name) {
	this->direction = 'e'; 
};
Snake_Body::Snake_Body(SDL_Renderer* renderer, const char* texturePath, int x, int y, int width, int height): Entity(renderer, texturePath, x, y, width, height) {
	this->direction = 'e'; 
};

void Snake_Body::move() {
	const int MOVE_RATE = 40; 

	switch (direction) {
		case 'n':
			this->setY(getY() + MOVE_RATE);
			break; 
		case 'e':
			this->setX(getX() + MOVE_RATE);
			break; 
		case 's':
			this->setY(getY() - MOVE_RATE);
			break; 
		case 'w':
			this->setX(getX() - MOVE_RATE);
			break; 
		default:
			break; 
	}
}; 