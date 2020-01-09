#include "Sprites/Sprite.h"

Sprite::~Sprite()
{
	if (texture != NULL)
	{
		SDL_DestroyTexture(texture);
		texture == NULL;
	}
}