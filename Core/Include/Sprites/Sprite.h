#pragma once

#include "SDL.h"
#include "Foundation/BRShapes.h"
#include <memory>

class Sprite
{
public:
	Sprite(BRRect inRect, SDL_Texture* inTexture) : rect(inRect), texture(inTexture) {};
	~Sprite();

	//std::unique_ptr<BRRect> rect;
	BRRect rect;
	SDL_Texture* texture;	
};