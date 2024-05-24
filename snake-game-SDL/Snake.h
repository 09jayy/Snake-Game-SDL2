#pragma once
#include "Snake_Body.h"
#include <vector> 
#include <iostream>
#include <SDL.h>
#include <SDL_image.h>

class Snake
{
private:
	Snake_Body* head; 
	Snake_Body* tail;
	std::vector<Snake_Body*> body;

public:
	Snake(SDL_Renderer* renderer);
	~Snake();
	void move();
	bool checkCollision(); 
	bool isOutOfBounds(); 

	Snake_Body* getHead() { return this->head; }; 

	Snake_Body* getTail() { return this->tail; }; 

	std::vector<Snake_Body*> getBody() { return this->body; }; 

	void render(SDL_Renderer* renderer); 
};

