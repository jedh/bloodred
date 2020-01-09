#pragma once

#include <SDL.h>
#include <memory>
#include <string>
#include "Display\Window.h"
#include "Render\IRenderer.h"

namespace BRCore
{
	class SDLRenderer : public IRenderer
	{
	public:
		SDLRenderer(Window& const window) : m_window(window) {}

		bool Init() override;
		void Destroy() override;
		void Draw(const std::list<std::shared_ptr<BRFillRect>> rects, const std::list<std::shared_ptr<Sprite>> sprites) const override;
		SDL_Texture* GetTexture(std::string path) const override;
	private:
		Window& m_window;
		SDL_Renderer* m_renderer;		
	};
}