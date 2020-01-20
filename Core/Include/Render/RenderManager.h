#pragma once 

#include "Render\IRenderer.h"
#include "Display/\DisplayManager.h"
#include "Foundation/BRShapes.h"
#include "Sprites/Sprite.h"
#include <list>
#include <memory>
#include <string>
#include "Foundation/Vector2.h"
#include "Camera/Camera.h"

namespace BRCore
{
	//class Camera;

	class RenderManager
	{
	public:
		bool StartUp(DisplayManager& displayManager);
		void ShutDown();
		//void Draw(const std::shared_ptr<Camera> camera);
		void Draw(const Camera& camera);
		void UpdateAnimations(float deltaTime);
		void AddFillRect(const std::shared_ptr<BRFillRect> fillRect);
		void AddSprite(const std::shared_ptr<Sprite> sprite);
		void RemoveSprite(const std::shared_ptr<Sprite> sprite);
		void ClearSprites();
		void RemoveFillRect(const std::shared_ptr<BRFillRect> fillRect);
		void ClearFillRects();
		SDL_Texture* GetTexture(std::string path) const;
		BRCore::Vector2 GetLogicalDisplaySize() const;
	private:
		IRenderer* m_renderer;
		std::list<std::shared_ptr<BRFillRect>> m_rects;
		std::list<std::shared_ptr<Sprite>> m_sprites;	
	};
}