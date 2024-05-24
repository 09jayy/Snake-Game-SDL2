#include "Entity.h"
#include <iostream>
#include <string>

Entity::Entity(SDL_Renderer* renderer, const char* texturePath, int x, int y, int width, int height) {
	this->x = x;
	this->y = y;
	this->width = width;
	this->height = height;
	this->name = "";

	SDL_Surface* surface = IMG_Load(texturePath);
	texture = SDL_CreateTextureFromSurface(renderer, surface);
	SDL_FreeSurface(surface); 
}

Entity::Entity(SDL_Renderer* renderer, const char* texturePath, int x, int y, int width, int height, std::string objName) {
	this->x = x;
	this->y = y;
	this->width = width;
	this->height = height;
	this->name = objName;

	SDL_Surface* surface = IMG_Load(texturePath);
	texture = SDL_CreateTextureFromSurface(renderer, surface);
	SDL_FreeSurface(surface);
}

void Entity::render(SDL_Renderer* renderer) {
	SDL_Rect srcRect;
	srcRect.x = 0;
	srcRect.y = 0;
	srcRect.w = width;
	srcRect.h = height;

	SDL_Rect destRect;
	destRect.x = x;
	destRect.y = y;
	destRect.w = width;
	destRect.h = height;

	SDL_RenderCopy(renderer, texture, &srcRect, &destRect);
}

Entity::~Entity() {
	std::cout << "Entity destroyed: " << this->getName() << "\n";
	SDL_DestroyTexture(texture);
}