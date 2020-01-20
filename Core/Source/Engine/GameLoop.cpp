#include "Engine\GameLoop.h"
#include <SDL.h>
#include <iostream>

using namespace std::chrono;

namespace BRCore
{
	void GameLoop::Run()
	{
		bool isRunning = true;		
		m_timer = std::make_unique<Timer>();
		m_eventPoller = std::make_unique<EventPoller>();

		SDL_Event eventHandler;

		while (isRunning)
		{
			m_timer->Update();				
			m_lag += m_timer->GetDelta();						

			while (m_lag >= MS_PER_UPDATE)
			{				
				//std::cout << "update" << std::endl;
				m_eventPoller->ProcessEvents(m_inputManager);
				auto ev = m_eventPoller->GetLastEvent();

				if (ev.type && ev.type == SDL_QUIT)
				{					
					std::cout << "QUIT" << std::endl;
					isRunning = false;
					return;
				}
				else if (m_inputManager.GetKeyDown(SDLK_ESCAPE))
				{
					// This is just temporary for now.
					isRunning = false;
					return;
				}

				// Update game/scene/physics.
				for (auto scene : m_SceneManager.GetScenes())
				{
					// Send delta time in seconds.
					scene->Update(m_timeStep);
				}

				m_inputManager.ClearEvents();

				m_renderManager.UpdateAnimations(m_timeStep);

				m_lag -= MS_PER_UPDATE;
			}

			m_renderManager.Draw(m_camera);
		}
	}
}