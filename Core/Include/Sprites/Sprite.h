#pragma once

#include "SDL.h"
#include "Foundation/BRShapes.h"
#include <memory>

namespace BRCore
{
	class Sprite
	{
	public:
		Sprite(BRCore::BRRect inRect, SDL_Texture* inTexture) : rect(inRect), texture(inTexture) {};
		~Sprite();

		//std::unique_ptr<BRRect> rect;
		BRCore::BRRect rect;
		SDL_Texture* texture;
	};
}