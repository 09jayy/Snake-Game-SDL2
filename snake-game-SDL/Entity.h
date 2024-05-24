#pragma once
#include "SDL.h"
#include "SDL_image.h"
#include <iostream>
#include <string>

class Entity {
protected:
	std::string name;  
	int x, y; 
	int width, height;
	SDL_Texture* texture;
public:
	Entity(SDL_Renderer* renderer, const char* texturePath, int x, int y, int width, int height);

	Entity(SDL_Renderer* renderer, const char* texturePath, int x, int y, int width, int height, std::string objName);

	void render(SDL_Renderer* renderer);

	int getX() { return x; };

	int getY() { return y; };

	void setX(int x) { this->x = x; };
	void setY(int y) { this->y = y; }; 

	std::string getName() { return name; };

	~Entity(); 
};