#include "Snake_Body.h"
#include "SDL.h"
#include "SDL_image.h"
#include "Entity.h"
#include <iostream>
#include "Game.h"

Image_assets_body Snake_Body::textures = { NULL, NULL, NULL, NULL, NULL, NULL };

Snake_Body::~Snake_Body() {};
Snake_Body::Snake_Body(int x, int y, int width, int height, const char* name) : Entity(x, y, width, height, name), directionChanged(false), direction('e'), curTexture(nullptr), nextDirection('e') {
	if (!textures.vertical) {
		setTextures(); 
	}
	curTexture = textures.vertical;
};
Snake_Body::Snake_Body(int x, int y, int width, int height): Entity(x, y, width, height), directionChanged(false), direction('e'), curTexture(nullptr), nextDirection('e') {
	if (!textures.vertical) {
		setTextures();
	}
	curTexture = textures.vertical;
};

void Snake_Body::setTextures() {
	SDL_Renderer* renderer = Game::getRenderer(); 
	textures.vertical = Entity::createTextureFromPath(renderer, "assets/body_vertical.png");
	textures.horizontal = Entity::createTextureFromPath(renderer, "assets/body_horizontal.png");
	textures.topleft = Entity::createTextureFromPath(renderer, "assets/body_topleft.png");
	textures.topright = Entity::createTextureFromPath(renderer, "assets/body_topright.png");
	textures.bottomleft = Entity::createTextureFromPath(renderer, "assets/body_bottomleft.png");
	textures.bottomright = Entity::createTextureFromPath(renderer, "assets/body_bottomright.png");
}; 

void Snake_Body::move(Snake_Body* frontBody) {
	setX(frontBody->getX());
	setY(frontBody->getY());
}; 

void Snake_Body::moveSwitchCase(Snake_Body* frontBody) {
	const int MOVE_RATE = 40;

	switch (direction) {
	case 'n':
		std::cout << "front y: " << frontBody->getY() << std::endl;
		this->setY(getY() - MOVE_RATE);
		std::cout << "back y: " << this->getY() << "\n";
		break;
	case 'e':
		std::cout << "front x: " << frontBody->getX() << std::endl;
		std::cout << "x before: " << this->getX() << "\n";
		this->setX(getX() + MOVE_RATE);
		std::cout << "x after: " << this->getX() << "\n";
		std::cout << "back x: " << this->getX() << "\n";
		break;
	case 's':
		this->setY(getY() + MOVE_RATE);
		break;
	case 'w':
		this->setX(getX() - MOVE_RATE);
		break;
	default:
		std::cout << "INVALID DIRECTION" << "\n";
		break;
	};

	std::cout << "COORDS FOR BODY: " << this->getX() << ", " << this->getY() << std::endl;
	std::cout << "COORDS FOR FRONT BODY: " << frontBody->getX() << ", " << frontBody->getY() << std::endl;
}; 

void Snake_Body::renderFirstBody(char headDirection) {
	if (this->direction == headDirection) {
		if (headDirection == 'n' || headDirection == 's') {
			curTexture = textures.vertical;
		}
		else {
			curTexture = textures.horizontal; 
		}; 

		render();
	}
	else {
		if ( (headDirection == 'n' && direction == 'e') || (headDirection == 'w' && direction == 's')) {
			curTexture = textures.topright; // body_topright.png
		}
		else if ((headDirection == 's' && direction == 'e') || (headDirection == 'w' && direction == 'n')) {
			curTexture = textures.bottomleft; // body_bottomleft.png
		} 
		else if ((headDirection == 's' && direction == 'w') || (headDirection == 'n' && direction == 'e')) {
			curTexture = textures.bottomright; // body_bottomright.png
		}
		else if ((headDirection == 'n' && direction == 'w') || (headDirection == 'w' && direction == 's')) {
			curTexture = textures.topleft; // body_topleft.png
		}
		render(); 
	};
}; 

void Snake_Body::render() {
	SDL_Rect srcRect;
	srcRect.x = 0;
	srcRect.y = 0;
	srcRect.w = width;
	srcRect.h = height;

	SDL_Rect destRect;
	destRect.x = x;
	destRect.y = y;
	destRect.w = width;
	destRect.h = height;

	std::cout << "RENDERING BODY" << "\n";
	std::cout << curTexture << "\n"; 

	SDL_RenderCopy(Game::getRenderer(), curTexture, &srcRect, &destRect);
}; 

void Snake_Body::render(SDL_Texture* previousTexture) {
	curTexture = previousTexture;
	render();
}; 

void Snake_Body::setDirection(char newDirection) {
	direction = newDirection;
	directionChanged = true; 
};

char Snake_Body::getOpposite(const char direction) {
	switch (direction) {
		case 'n': return 's';
		case 's': return 'n';
		case 'e': return'w';
		case 'w': return 'e';
		default: return NULL;
	}; 
}; 