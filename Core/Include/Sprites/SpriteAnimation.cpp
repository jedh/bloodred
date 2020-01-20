#include "SpriteAnimation.h"

BRCore::SpriteAnimation::SpriteAnimation(SDL_Texture* inTexture, std::string inName, int inNumFrames)
{
	texture = inTexture;
	name = inName;
	numFrames = inNumFrames;
	speed = 1;
	isLooping = false;
	currentFrame = 0;
	
	int textureWidth;
	SDL_QueryTexture(texture, NULL, NULL, &textureWidth, &m_frameHeight);
	m_frameWidth = textureWidth / numFrames;
	
	// Generate animation rects.
	for (int i = 0; i < numFrames; ++i)
	{
		SDL_Rect rect = { i * m_frameWidth, 0, m_frameWidth, m_frameHeight };
		m_animationRects.push_back(rect);
	}
}

BRCore::SpriteAnimation::~SpriteAnimation()
{
	if (texture)
	{
		SDL_DestroyTexture(texture);
	}
}

const SDL_Rect& BRCore::SpriteAnimation::GetAnimationRect(int frame) const
{
	if (frame >= numFrames)
	{
		return m_animationRects[0];
	}
	else
	{
		return m_animationRects[frame];
	}
}
