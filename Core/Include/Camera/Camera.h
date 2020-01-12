#pragma once

#include "Foundation/BRShapes.h"
#include "Foundation/Vector2.h"
//#include "Render/RenderManager.h"
#include <memory>

namespace BRCore
{
	class Camera
	{
	public:
		//Camera(const std::shared_ptr<RenderManager> renderManager);
		Camera(const BRCore::Vector2& logicalDisplaySize);
		~Camera();

		BRCore::BRRect cameraRect;

		BRCore::Vector2 GetOffset() const;
	private:
		BRCore::BRRect m_startingRect;
	};
}