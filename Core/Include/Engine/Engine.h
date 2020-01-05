#pragma once

#include "Display\DisplayManager.h"
#include "Render\RenderManager.h"
#include "Input\InputManager.h"
#include "Scenes\SceneManager.h"
#include "GameLoop.h"

namespace BRCore
{
	class Engine
	{
	public:
		Engine();
		~Engine();

		int Start(int screenWidth = 640, int screenHeight = 480);
		void Stop();

		const std::shared_ptr<DisplayManager> Display();
		const std::shared_ptr<RenderManager> Rendering();
		const std::shared_ptr<InputManager> Input();
		const std::shared_ptr<SceneManager> Scenes();
		void Run();

	private:
		std::shared_ptr<DisplayManager> m_displayManager;
		std::shared_ptr<RenderManager> m_renderManger;
		std::shared_ptr<InputManager> m_inputManager;
		std::shared_ptr<SceneManager> m_sceneManager;
		GameLoop* m_gameLoop;
	};
}