#pragma once
#include "SDL_ttf.h"
#include "SDL.h"
#include <iostream> 

class Text
{
private:
	const char* text;
	TTF_Font* font;
	SDL_Surface* sur;
	int x, y;
public:
	Text(const char*, const char* fontPath, int fontSize);
	~Text();

	void setPosition(int x, int y);
	void setPosition(const char* position);
	void render(SDL_Renderer* renderer);
}; 

