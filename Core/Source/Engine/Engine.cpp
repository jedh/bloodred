
#include "Engine\Engine.h"

namespace BRCore
{
	Engine::Engine()
	{
		//m_displayManager = &DisplayManager::Instance();
		//m_renderManger = &RenderManager::Instance();
		//m_inputManager = &InputManager::Instance();
		m_displayManager = std::make_shared<DisplayManager>(DisplayManager::Instance());
		m_renderManger = std::make_shared<RenderManager>(RenderManager::Instance());
		m_inputManager = std::make_shared<InputManager>(InputManager::Instance());
	}

	Engine::~Engine()
	{
		m_displayManager = nullptr;
		m_renderManger = nullptr;
	}

	int Engine::Start()
	{
		// Order matters!
		if (!m_displayManager->StartUp() ||
			!m_renderManger->StartUp(*m_displayManager) ||
			!m_inputManager->StartUp())
		{
			return 1;
		}

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

	DisplayManager& Engine::Display()
	{
		return *m_displayManager;
	}

	RenderManager& Engine::Rendering()
	{
		return *m_renderManger;
	}

	InputManager& Engine::Input()
	{
		return *m_inputManager;
	}

	void Engine::Run()
	{
		m_gameLoop = new GameLoop(*m_renderManger, *m_inputManager);
		m_gameLoop->Run();
		Stop();
	}
}