#include "Sprites/Sprite.h"

namespace BRCore
{
	Sprite::~Sprite()
	{
		if (texture != NULL)
		{
			SDL_DestroyTexture(texture);
			texture == NULL;
		}
	}
}