#pragma once 

#include "Render\IRenderer.h"
#include "Display/\DisplayManager.h"
#include "Foundation/BRShapes.h"
#include "Sprites/Sprite.h"
#include <list>
#include <memory>
#include <string>

namespace BRCore
{
	class RenderManager
	{
	public:
		bool StartUp(DisplayManager& displayManager);
		void ShutDown();
		void Draw(); // Test function.
		void AddFillRect(const std::shared_ptr<BRFillRect> fillRect);
		void AddSprite(const std::shared_ptr<Sprite> sprite);
		void RemoveSprite(const std::shared_ptr<Sprite> sprite);
		void ClearSprites();
		void RemoveFillRect(const std::shared_ptr<BRFillRect> fillRect);
		void ClearFillRects();
		SDL_Texture* GetTexture(std::string path) const;
	private:
		IRenderer* m_renderer;
		std::list<std::shared_ptr<BRFillRect>> m_rects;
		std::list<std::shared_ptr<Sprite>> m_sprites;
	};
}