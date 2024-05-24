#pragma once
#include "SDL.h"
#include "Entity.h"

class Snake_Body : public Entity {
private:
	char direction; 
public:
	Snake_Body(SDL_Renderer* renderer, const char* texturePath, int x, int y, int width, int height, const char* name);
	Snake_Body(SDL_Renderer* renderer, const char* texturePath, int x, int y, int width, int height);
	
	void move(); 

	~Snake_Body(); 
};