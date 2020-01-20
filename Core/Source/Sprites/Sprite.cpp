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

		/*for (auto const &spriteSheetEntry : m_animationsMap)
		{
			if (spriteSheetEntry.second->texture) 
			{
				SDL_DestroyTexture(spriteSheetEntry.second->texture);
			}
		}*/
	}

	void Sprite::AddAnimation(std::unique_ptr<SpriteAnimation> spriteAnimation)
	{
		m_animationsMap[spriteAnimation->name] = std::move(spriteAnimation);
	}

	void Sprite::PlayAnimation(std::string animationName, bool isLooping, int speed)
	{
		m_currentAnimation = animationName;
		auto anim = m_animationsMap[animationName];
		if (anim)
		{
			anim->currentFrame = 0;
			anim->isLooping = isLooping;
			anim->speed = speed;
			anim->startTicks = SDL_GetTicks();
		}
	}
	
	const std::shared_ptr<BRCore::SpriteAnimation> Sprite::GetCurrentAnimation()
	{
		if (!m_currentAnimation.empty())
		{
			return m_animationsMap[m_currentAnimation];
		}

		return nullptr;
	}
}