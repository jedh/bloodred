#pragma once

#include <string>
#include <SDL.h>
#include <vector>

namespace BRCore
{
	struct SpriteAnimation
	{
	public:
		SpriteAnimation(SDL_Texture* inTexture, std::string inName, int inNumFrames);
		~SpriteAnimation();

		SDL_Texture* texture;
		std::string name;
		int numFrames;
		int speed;
		bool isLooping;
		int currentFrame;
		Uint32 startTicks;

		int GetFrameWidth() const { return m_frameWidth; }
		int GetFrameHeight() const { return m_frameHeight; }
		const SDL_Rect& GetAnimationRect(int frame) const;
	private:
		bool m_isAnimating;
		int m_frameWidth;
		int m_frameHeight;
		std::vector<SDL_Rect> m_animationRects;
	};
}