#pragma once
#include "SDL_ttf.h"
#include "SDL.h"
#include <iostream> 

class Text
{
private:
	const char* text; 
	TTF_Font* font;
public:
	Text(const char*, const char* fontPath, int fontSize); 
	Text(const char*, const char* fontPath, int fontSize, const char* position);
	~Text(); 

	void render(SDL_Renderer* renderer, int x, int y); 
	void render(SDL_Renderer* renderer, const char* position);
};

