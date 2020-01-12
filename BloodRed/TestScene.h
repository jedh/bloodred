#pragma once

#include <BRCore.h>
#include <Display/DisplayManager.h>
#include <Input/InputManager.h>
#include <Render/RenderManager.h>
#include <Foundation/BRShapes.h>
#include <Sprites/Sprite.h>
#include "Camera/Camera.h"

namespace BRGame
{
	class TestScene : public BRCore::Scene
	{
	public:
		TestScene(
			std::string name,
			const std::shared_ptr<BRCore::DisplayManager> display,
			const std::shared_ptr<BRCore::InputManager> input,
			const std::shared_ptr<BRCore::RenderManager> rendering,
			std::shared_ptr<BRCore::Camera> camera) :
			Scene(name, display, input, rendering, camera) {};
		void Init() override;
		void Update(float deltaTime) override;
		void Shutdown() override;
	private:
		BRCore::Vector2 m_position;
		std::shared_ptr<BRCore::BRFillRect> m_rect;
		std::shared_ptr<BRCore::Sprite> m_sprite;
	};
}