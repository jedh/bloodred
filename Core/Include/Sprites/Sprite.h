#pragma once

#include "SDL.h"
#include "Foundation/BRShapes.h"
#include <memory>
#include "SpriteAnimation.h"
#include <memory>
#include <string>
#include <map>

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

		void AddAnimation(std::unique_ptr<SpriteAnimation> spriteAnimation);
		void PlayAnimation(std::string animationName, bool isLooping = false, int speed = 100);
		const std::shared_ptr<BRCore::SpriteAnimation> GetCurrentAnimation();
		
	private:
		std::map<std::string, std::shared_ptr<BRCore::SpriteAnimation>> m_animationsMap;
		std::string m_currentAnimation;
	};
}