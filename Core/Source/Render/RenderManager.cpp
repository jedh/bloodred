#include "Render\RenderManager.h"
#include "Render\SDLRenderer.h"
#include "Display\DisplayManager.h"
#include <stdio.h>
#include <iostream>

namespace BRCore
{
	bool RenderManager::StartUp(DisplayManager& displayManager)
	{
		m_renderer = new SDLRenderer(displayManager.GetWindow());
		if (m_renderer->Init())
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	void RenderManager::ShutDown()
	{
		m_renderer->Destroy();
	}

	void RenderManager::UpdateAnimations(float deltaTime)
	{
		auto ticks = SDL_GetTicks();
		Uint32 seconds = ticks * 0.001;
		for (auto& sprite : m_sprites)
		{
			auto& anim = sprite->GetCurrentAnimation();
			if (anim->currentFrame < (anim->numFrames - 1) || anim->isLooping)
			{
				auto offsetTicks = ticks - anim->startTicks;
				Uint32 frame = (offsetTicks / anim->speed) % anim->numFrames;
				//frame = frame * anim->speed;
				/*int frame = anim->currentFrame + 1;
				if (frame >= anim->numFrames)
				{
					if (anim->isLooping)
					{
						frame = 0;
					}
					else
					{
						frame = anim->numFrames - 1;
					}
				}*/

				anim->currentFrame = frame;
			}
		}
	}

	void RenderManager::Draw(const Camera& camera)
	{
		m_renderer->Draw(camera, m_rects, m_sprites);
	}

	void RenderManager::AddFillRect(const std::shared_ptr<BRFillRect> fillRect)
	{
		m_rects.push_back(fillRect);
	}

	void RenderManager::RemoveFillRect(const std::shared_ptr<BRFillRect> fillRect)
	{
		m_rects.remove(fillRect);
	}

	void RenderManager::ClearFillRects()
	{
		m_rects.clear();
	}

	void RenderManager::AddSprite(const std::shared_ptr<Sprite> sprite)
	{
		m_sprites.push_back(sprite);
	}

	void RenderManager::RemoveSprite(const std::shared_ptr<Sprite> sprite)
	{
		m_sprites.remove(sprite);
	}

	void RenderManager::ClearSprites()
	{
		m_sprites.clear();
	}

	SDL_Texture* RenderManager::GetTexture(std::string path) const
	{
		return m_renderer->GetTexture(path);
	}

	BRCore::Vector2 RenderManager::GetLogicalDisplaySize() const
	{
		return m_renderer->GetLogicalRenderSize();
	}
}