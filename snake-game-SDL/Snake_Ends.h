#pragma once
#include "SDL.h"
#include "SDL_image.h"
#include "Snake_Body.h" 

struct Image_assets_ends {
	SDL_Texture* north; 
	SDL_Texture* east;
	SDL_Texture* south;
	SDL_Texture* west;
};

class Snake_Ends : public Snake_Body
{
private: 
	static Image_assets_ends headTextures;
	static Image_assets_ends tailTextures;
public:

	Snake_Ends(int x, int y, int width, int height, const char* name);
	Snake_Ends(int x, int y, int width, int height);

	static void setTextures(); 
	void setCurTexture(SDL_Texture* tex) { curTexture = tex; };
	void moveHead(); 

	static Image_assets_ends getHeadTextures() { return headTextures; };
	static Image_assets_ends getTailTextures() { return tailTextures; };

	void setEndTexture(Image_assets_ends textureStruct); 

	void render(Image_assets_ends textureStruct); 

	~Snake_Ends(); 

};

