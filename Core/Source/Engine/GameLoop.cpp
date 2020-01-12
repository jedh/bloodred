#include "Engine\GameLoop.h"
#include <SDL.h>
#include <iostream>

using namespace std::chrono;

namespace BRCore
{
	void GameLoop::Run()
	{
		bool isRunning = true;
		//m_timer = new Timer();
		m_timer = std::make_unique<Timer>();

		SDL_Event eventHandler;

		while (isRunning)
		{
			m_timer->Update();				
			m_lag += m_timer->GetDelta();			

			auto input = m_inputManager.ProcessInput();

			// Process input.            
			if (std::get<0>(input) == SDL_QUIT)
			{
				isRunning = false;
				return;
			}
			else if (std::get<0>(input) == SDL_KEYUP &&
				std::get<1>(input) == SDLK_ESCAPE)
			{
				// This is just temporary for now.
				isRunning = false;
				return;
			}

			while (m_lag >= MS_PER_UPDATE)
			{
				// Update game/scene/physics.
				for (auto scene : m_SceneManager.GetScenes())
				{
					// Send delta time in seconds.
					scene->Update(m_timeStep);
				}

				m_lag -= MS_PER_UPDATE;
			}

			m_renderManager.Draw(m_camera);
		}
	}
}