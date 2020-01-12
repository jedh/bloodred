
#include "Engine\Engine.h"

namespace BRCore
{
	Engine::Engine()
	{
		m_displayManager = std::make_shared<DisplayManager>();
		m_renderManger = std::make_shared<RenderManager>();
		m_inputManager = std::make_shared<InputManager>();
		m_sceneManager = std::make_shared<SceneManager>();
		
	}

	Engine::~Engine()
	{
		m_displayManager = nullptr;
		m_renderManger = nullptr;
	}

	int Engine::Start(int screenWidth, int screenHeight)
	{
		// Order matters!
		if (!m_displayManager->StartUp(screenWidth, screenHeight) ||
			!m_renderManger->StartUp(*m_displayManager) ||
			!m_inputManager->StartUp())
		{
			return 1;
		}

		m_camera = std::make_shared<Camera>(m_renderManger->GetLogicalDisplaySize());
		return 0;
	}


	void Engine::Stop()
	{
		// Always shutdown in the reverse order of startup!
		m_inputManager->ShutDown();
		m_renderManger->ShutDown();
		m_displayManager->ShutDown();
		SDL_Quit();
	}

	const std::shared_ptr<DisplayManager> Engine::Display()
	{
		return m_displayManager;
	}

	const std::shared_ptr<RenderManager> Engine::Rendering()
	{
		return m_renderManger;
	}

	const std::shared_ptr<InputManager> Engine::Input()
	{
		return m_inputManager;
	}

	const std::shared_ptr<SceneManager> Engine::Scenes()
	{
		return m_sceneManager;
	}

	std::shared_ptr<Camera> Engine::CameraMain()
	{
		return m_camera;
	}

	void Engine::Run()
	{
		m_gameLoop = std::make_unique<GameLoop>(*m_renderManger, *m_inputManager, *m_sceneManager, *m_camera);
		m_gameLoop->Run();
		Stop();
	}
}