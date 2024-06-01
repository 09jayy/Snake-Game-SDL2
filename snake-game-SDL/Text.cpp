#include "Text.h"

Text::~Text() {
	if (font) {
		TTF_CloseFont(font);
	}; 
}; 
Text::Text(const char* text, const char* fontPath, int fontSize) : text(text), x(0), y(0), sur(nullptr){
	font = TTF_OpenFont(fontPath, fontSize); 
}; 

void Text::setPosition(int x, int y) {
	sur = TTF_RenderText_Solid(font, text, SDL_Color{ 255,255,255 });
	this->x = x;
	this->y = y;
}

void Text::setPosition(const char* position) {
	sur = TTF_RenderText_Solid(font, text, SDL_Color{ 255,255,255 });
	if (position == "CENTER") {
		x = 400 - sur->w / 2;
		y = 400 - sur->h / 2;
	}
}

void Text::render(SDL_Renderer* renderer) {
	//create texture
	SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, sur);
	SDL_Rect rect = { x,y,sur->w, sur->h };
	SDL_FreeSurface(sur);

	//render
	SDL_RenderCopy(renderer, texture, NULL, &rect);

	SDL_DestroyTexture(texture);
}