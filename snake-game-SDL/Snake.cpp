#include "Snake.h"
#include "SDL.h"
#include <iostream>
#include <vector>
#include "Game.h" 
#include "Snake_Ends.h"
#include "Snake_Body.h"

Snake::Snake(SDL_Renderer* renderer) {
	int WIDTH_HEIGHT = 40; // width of 1 snake body part
	
	head = new Snake_Ends(120, 400, WIDTH_HEIGHT, WIDTH_HEIGHT, "head");

	std::cout << "head created" << "\n"; 

	tail = new Snake_Ends(0, 400, WIDTH_HEIGHT, WIDTH_HEIGHT,"tail");  

	body.push_back(head); 
	body.push_back(new Snake_Body(80, 400, WIDTH_HEIGHT, WIDTH_HEIGHT, "body"));
	body.push_back(new Snake_Body(40, 400, WIDTH_HEIGHT, WIDTH_HEIGHT, "body"));
	body.push_back(new Snake_Body(0, 400, WIDTH_HEIGHT, WIDTH_HEIGHT, "body"));

	std::cout << "tail created" << "\n"; 
}

void Snake::render(bool hasFailed) {

	if (!hasFailed) { head->setEndTexture(Snake_Ends::getHeadTextures()); }; 
	head->render();

	for (int i = 1; i < body.size(); i++) {
		if (!hasFailed) { body[i]->syncDirectionTexture(body[i - 1]); };
		body[i]->render(); 
	}

	tail->setDirection(body[body.size() - 1]->getDirection()); 
	if (!hasFailed) { tail->setEndTexture(Snake_Ends::getTailTextures()); }; 
	tail->render();
}

void Snake::move() {
	tail->move( (body.size() == 1) ? head : body[body.size() - 1] );

	if (body.size() >= 1) {
		for (int i = body.size() - 1; i >= 1; i--) {
			body[i]->move(body[i - 1]); 
		}
	}
	head->moveHead(); 
}

bool Snake::checkSelfCollision() {
	if (body.size() >= 1) {
		for (int i = 1; i < body.size(); i++) {
			if (head->getX() == body[i]->getX() && head->getY() == body[i]->getY()) {
				std::cout << "COLLISION DETECTED FAIL" << "\n";
				return true; 
			}
		}
		if (head->getX() == tail->getX() && head->getY() == tail->getY()) {
			std::cout << "COLLISION DETECTED FAIL" << "\n";
			return true; 
		}
	}
	return false;
}

bool Snake::checkAppleCollision(Entity* apple) {
	if (head->getX() == apple->getX() && head->getY() == apple->getY()) {
		std::cout << "COLLISION DETECTED" << "\n";
		return true; 
	}
	return false;
}

bool Snake::isOutOfBounds(){
	if (head->getX() > 800 || head->getX() < 0 || head->getY() > 800 || head->getY() < 0 ) {
		return true;
	}
	else {
		std::cout << head->getX() << ", " << head->getY() << "\n";
		return false; 
	}
}

void Snake::changeDirection(char change) {
	if (Snake_Body::getOpposite(change) != head->getDirection()) {
		head->setDirection(change); 
	}
}
 
void Snake::grow() {
	Snake_Body* newBody = new Snake_Body(tail->getX(), tail->getY(), 40, 40, "body");
	newBody->setDirection(body[body.size() - 1]->getDirection());
	newBody->setNextDirection(body[body.size() - 1]->getNextDirection()); 
	body.push_back(newBody);
}

Snake::~Snake() {
	delete head;
	delete tail;
	for (int i = 1; i < body.size(); i++) {
		delete body[i];
	} 
}