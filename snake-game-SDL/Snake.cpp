#include "Snake.h"

Snake::Snake(SDL_Renderer* renderer) {
	const int WIDTH_HEIGHT = 40; // width of 1 snake body part
	
	head = new Snake_Body(renderer, "assets/head_right.png", 120, 400, WIDTH_HEIGHT, WIDTH_HEIGHT, "head");
	tail = new Snake_Body(renderer, "assets/tail_left.png", 80, 400, WIDTH_HEIGHT, WIDTH_HEIGHT,"tail"); 
	body.push_back(head); 
}

void Snake::render(SDL_Renderer* renderer) {
	head->render(renderer);
	for (int i = 0; i < body.size(); i++) {
		body[i]->render(renderer);
	};
	tail->render(renderer);
}

void Snake::move() {
	// move head
	getHead()->move(); 

	//move body
	//std::cout << body.size() << "\n"; 
	for (int i = 1; i < body.size(); i++) {
		body[i]->move();
	};  

	//move tail
	getTail()->move(); 
}

bool Snake::checkCollision() {
	return true; 
}

bool Snake::isOutOfBounds(){
	if (head->getX() > 800 || head->getX() < 0 || head->getY() > 800 || head->getY() < 0 ) {
		return true;
	}
	else {
		return false; 
	}
}
 

Snake::~Snake() {
	delete head;
	delete tail;
	for (int i = 1; i < body.size(); i++) {
		delete body[i];
	} 
}