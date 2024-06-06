#pragma once
#include "Entity.h"
#include "SDL.h"
#include "SDL_image.h"
#include <iostream>
#include <string>
#include <cstdlib>


class Apple : public Entity {
public:
	Apple(int x, int y, int width, int height, std::string objName);
	Apple(int x, int y, int width, int height);
	~Apple();

	void setTexture(SDL_Renderer* renderer, const char* texturePath);
	void setRandPosition();

	static bool seedRandGen(); 
};

