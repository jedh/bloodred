#pragma once

#include "SDL.h"
#include "Foundation/BRShapes.h"

class Sprite
{
public:
	Sprite(BRRect inRect, SDL_Texture* inTexture) : rect(inRect), texture(inTexture) {};
	~Sprite();

	BRRect rect;
	SDL_Texture* texture;	
};