#pragma once 
#include "Entity.h"
#include <iostream>
#include <vector>

struct Image_assets_body {
	SDL_Texture* vertical;
	SDL_Texture* horizontal;
	SDL_Texture* topleft;
	SDL_Texture* topright;
	SDL_Texture* bottomleft;
	SDL_Texture* bottomright;
};

class Snake_Body : public Entity {
protected:
	char direction; 
	bool directionChanged; 
	SDL_Texture* curTexture;
private: 
	 static Image_assets_body textures; 
	 char nextDirection; 
public:
	Snake_Body(int x, int y, int width, int height, const char* name);
	Snake_Body(int x, int y, int width, int height);

	static void setTextures(); 
	void move(Snake_Body* frontBody); 
	void moveSwitchCase(Snake_Body* frontBody); 

	void setDirection(char newDirection); 
	char getDirection() { return direction; }; 
	SDL_Texture* getCurTexture() { return curTexture; }; 
	bool getDirectionChanged() { return directionChanged; };
	void setDirectionChanged(bool newDirectionChanged) { directionChanged = newDirectionChanged; };
	void setNextDirection(char newNextDirection) { nextDirection = newNextDirection; };


	static char getOpposite(char direction);
	void renderFirstBody(char headDirection); 
	void render(SDL_Texture* previousTexture);
	void render(); 

	~Snake_Body(); 
};