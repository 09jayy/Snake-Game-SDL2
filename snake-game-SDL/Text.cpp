#include "Text.h"

Text::~Text() {
	if (font) {
		TTF_CloseFont(font);
	}; 
}; 
Text::Text(const char* text, const char* fontPath, int fontSize) : text(text){
	font = TTF_OpenFont(fontPath, fontSize); 
}; 

Text::Text(const char*, const char* fontPath, int fontSize, const char* position) : text(text) {
	font = TTF_OpenFont(fontPath, fontSize);
}

void Text::render(SDL_Renderer* renderer,int x, int y) {
	//create texture
	SDL_Surface* sur = TTF_RenderText_Solid(font, text, SDL_Color{ 255,255,255 });
	SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, sur);
	SDL_Rect rect = { x,y,sur->w, sur->h };
	SDL_FreeSurface(sur);

	//render
	SDL_RenderCopy(renderer, texture, NULL, &rect);

	SDL_DestroyTexture(texture);
}

void Text::render(SDL_Renderer* renderer, const char* position) {
	int x = 0; 
	int y = 0; 
	
	//create texture
	SDL_Surface* sur = TTF_RenderText_Solid(font, text, SDL_Color{ 255,255,255 });
	SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, sur);

	if (position == "CENTER") {
		x = 400 - sur->w / 2; 
		y = 400 - sur->h / 2; 
	} 

	SDL_Rect rect = { x,y,sur->w, sur->h };
	SDL_FreeSurface(sur);

	//render
	SDL_RenderCopy(renderer, texture, NULL, &rect);

	SDL_DestroyTexture(texture);
}