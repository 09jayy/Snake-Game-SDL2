#pragma once
#include "SDL.h"
#include "SDL_image.h"

class Entity {
protected:
	int x, y; 
	int width, height;
	SDL_Texture* texture;
public:
	Entity(SDL_Renderer* renderer, const char* texturePath, int x, int y, int width, int height);

	void render(SDL_Renderer* renderer);

	~Entity(); 
};