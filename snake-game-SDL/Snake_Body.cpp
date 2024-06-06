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
		this->setY(getY() - MOVE_RATE);
		break;
	case 'e':
		this->setX(getX() + MOVE_RATE);
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
}; 

void Snake_Body::setCurTexture(Snake_Body* frontBody) {
	direction = nextDirection; 
	nextDirection = frontBody->getDirection();

	std::cout << "Direction: " << direction << "\n";
	std::cout << "Next Direction: " << nextDirection << "\n";
	
	if (direction == nextDirection) {
		if (direction == 'n' || direction == 's') {
			curTexture = textures.vertical;
			std::cout << "Vertical" << "\n";
		}
		else {
			curTexture = textures.horizontal;
			std::cout << "Horizontal" << "\n";
		}; 
	}
	else {
		if (direction == 'n' && nextDirection == 'e') {
			curTexture = textures.bottomright;
			std::cout << "Top Left" << "\n";
		}
		else if (direction == 'n' && nextDirection == 'w') {
			curTexture = textures.bottomleft;
			std::cout << "Top Right" << "\n";
		}
		else if (direction == 's' && nextDirection == 'e') {
			curTexture = textures.topright;
			std::cout << "Bottom Left" << "\n";
		}
		else if (direction == 's' && nextDirection == 'w') {
			curTexture = textures.topleft;
			std::cout << "Bottom Right" << "\n";
		}
		else if (direction == 'e' && nextDirection == 'n') {
			curTexture = textures.topleft;
			std::cout << "Bottom Left" << "\n";
		}
		else if (direction == 'e' && nextDirection == 's') {
			curTexture = textures.bottomleft;
			std::cout << "Top Left" << "\n";
		}
		else if (direction == 'w' && nextDirection == 'n') {
			curTexture = textures.topright;
			std::cout << "Bottom Right" << "\n";
		}
		else if (direction == 'w' && nextDirection == 's') {
			curTexture = textures.bottomright;
			std::cout << "Top Right" << "\n";
		}
		else {
			std::cout << "INVALID DIRECTION" << "\n";
		}; 
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