#include "Entity.h"

Entity::Entity(SDL_Renderer* renderer, const char* texturePath, int x, int y, int width, int height) {
	this->x = x;
	this->y = y;
	this->width = width;
	this->height = height;

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
	SDL_DestroyTexture(texture);
}