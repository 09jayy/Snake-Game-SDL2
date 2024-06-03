#pragma once
#include "Snake_Body.h"
#include "Snake_Ends.h"
#include <vector> 
#include <iostream>
#include <SDL.h>
#include <SDL_image.h>

class Snake
{
private:
	Snake_Ends* head; 
	Snake_Ends* tail; 
	std::vector<Snake_Body*> body; 
public:
	Snake(SDL_Renderer* renderer);
	~Snake();
	void move();
	bool checkSelfCollision();
	bool checkAppleCollision(Entity* apple); 
	bool isOutOfBounds(); 
	void changeDirection(char change); 
	void grow();

	Snake_Body* getHead() { return this->head; }; 

	Snake_Body* getTail() { return this->tail; }; 

	std::vector<Snake_Body*> getBody() { return this->body; }; 
	
	void render(); 
};

