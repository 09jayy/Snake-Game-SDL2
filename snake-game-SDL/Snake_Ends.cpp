#include "Snake_Ends.h"
#include "Game.h" 

Image_assets_ends Snake_Ends::headTextures = {};
Image_assets_ends Snake_Ends::tailTextures = {}; 

Snake_Ends::Snake_Ends(int x, int y, int width, int height, const char* name) : Snake_Body(x, y, width, height, name) {
	setTextures();
	curTexture = headTextures.north;
}; 
Snake_Ends::Snake_Ends(int x, int y, int width, int height) : Snake_Body(x, y, width, height) {
	setTextures();
	curTexture = headTextures.north;
};
Snake_Ends::~Snake_Ends() {};

void Snake_Ends::setTextures() {
	SDL_Renderer* renderer = Game::getRenderer();

	if (!headTextures.north) {
		// STATIC HEAD TEXTURES
		headTextures.north = Entity::createTextureFromPath("assets/head_up.png");
		headTextures.east = Entity::createTextureFromPath("assets/head_right.png");
		headTextures.south = Entity::createTextureFromPath("assets/head_down.png");
		headTextures.west = Entity::createTextureFromPath("assets/head_left.png");

		// STATIC TAIL TEXTURES
		tailTextures.north = Entity::createTextureFromPath("assets/tail_down.png");
		tailTextures.east = Entity::createTextureFromPath("assets/tail_left.png");
		tailTextures.south = Entity::createTextureFromPath("assets/tail_up.png");
		tailTextures.west = Entity::createTextureFromPath("assets/tail_right.png");
	}; 

	std::cout << "check head textures" << std::endl;
	if (headTextures.north == nullptr || headTextures.east == nullptr || headTextures.south == nullptr || headTextures.west == nullptr) {
		std::cout << "Error loading head textures" << std::endl;
	};

	std::cout << "check tail textures" << std::endl;
	if (tailTextures.north == nullptr || tailTextures.east == nullptr || tailTextures.south == nullptr || tailTextures.west == nullptr) {
		std::cout << "Error loading tail textures" << std::endl;
	};
}; 

void Snake_Ends::setEndTexture(Image_assets_ends textureStruct) {
	switch (this->getDirection()) {
	case 'n':
		curTexture = textureStruct.north;
		break;
	case 'e':
		curTexture = textureStruct.east;
		break;
	case 's':
		curTexture = textureStruct.south;
		break;
	case 'w':
		curTexture = textureStruct.west;
		break;
	default:
		break;
	};
}; 

void Snake_Ends::moveHead() {
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
		curTexture = nullptr; 
		break;
	}
};

void Snake_Ends::render() {
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
}
