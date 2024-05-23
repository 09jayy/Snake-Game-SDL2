#include "Snake_Body.h"
#include "SDL.h"
#include "SDL_image.h"
#include "Entity.h"
#include <iostream>

Snake_Body::~Snake_Body() {};
Snake_Body::Snake_Body(SDL_Renderer* renderer, const char* texturePath, int x, int y, int width, int height, const char* name) : Entity(renderer, texturePath, x, y, width, height, name) {
}; 