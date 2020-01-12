#include "Camera/Camera.h"

namespace BRCore
{
	//Camera::Camera(const std::shared_ptr<RenderManager> renderManager)
	Camera::Camera(const BRCore::Vector2& logicalDisplaySize)
	{
		//auto size = renderManager->GetLogicalDisplaySize();
		cameraRect = BRCore::BRRect(0, 0, logicalDisplaySize.x, logicalDisplaySize.y);
		m_startingRect = cameraRect;
	}
	
	Camera::~Camera()
	{
	}

	BRCore::Vector2 Camera::GetOffset() const
	{
		auto offset = Vector2(0, 0);
		offset.x = cameraRect.x - m_startingRect.x;
		offset.y = cameraRect.y - m_startingRect.y;

		return offset;
	}
}