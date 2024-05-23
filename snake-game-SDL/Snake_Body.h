#pragma once
#include "SDL.h"
#include "Entity.h"

class Snake_Body : public Entity {
public:
	Snake_Body(SDL_Renderer* renderer, const char* texturePath, int x, int y, int width, int height, const char* name);
	~Snake_Body(); 
};