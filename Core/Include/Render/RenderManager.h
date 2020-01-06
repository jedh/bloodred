#pragma once 

#include "Render\IRenderer.h"
#include "Display/\DisplayManager.h"
#include <list>
#include "BRShapes.h"
#include <memory>

namespace BRCore
{
	class RenderManager
	{
	public:
		bool StartUp(DisplayManager& displayManager);
		void ShutDown();
		void Draw(); // Test function.
		void AddFillRect(const std::shared_ptr<BRFillRect> fillRect);
		void RemoveFillRect(const std::shared_ptr<BRFillRect> fillRect);
		void ClearFillRects();
	private:
		IRenderer* m_renderer;
		std::list<std::shared_ptr<BRFillRect>> m_rects;
	};
}