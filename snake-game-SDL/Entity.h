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
	Entity(int x, int y, int width, int height);

	Entity(int x, int y, int width, int height, std::string objName);

	void setTexture(const char* texturePath); 
	static SDL_Texture* createTextureFromPath(const char* path); 

	void render();

	int getX() { return x; }; 
	int getY() { return y; };
	int getWidth() { return width; };
	int getHeight() { return height; };

	void setX(int x) { this->x = x; };
	void setY(int y) { this->y = y; }; 

	std::string getName() { return name; };

	~Entity(); 
};