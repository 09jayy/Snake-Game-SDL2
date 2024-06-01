#include "Entity.h"
#include <iostream>
#include <string>

Entity::Entity(int x, int y, int width, int height) {
	this->x = x;
	this->y = y;
	this->width = width;
	this->height = height;
	this->name = "";
	this->texture = {}; 
}

Entity::Entity(int x, int y, int width, int height, std::string objName) {
	this->x = x;
	this->y = y;
	this->width = width;
	this->height = height;
	this->name = objName;
	this->texture = {}; 
}

void Entity::setTexture(SDL_Renderer* renderer, const char* texturePath) {
	SDL_Surface* surface = IMG_Load(texturePath);
	texture = SDL_CreateTextureFromSurface(renderer, surface);
	SDL_FreeSurface(surface);
}

SDL_Texture* Entity::createTextureFromPath(SDL_Renderer* renderer, const char* path) {
	SDL_Surface* sur = IMG_Load(path);
	SDL_Texture* tex = SDL_CreateTextureFromSurface(renderer, sur);
	SDL_FreeSurface(sur);
	return tex;
}; 

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