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
		float deltaTime = 0;

		SDL_Event eventHandler;

		while (isRunning)
		{
			deltaTime = m_timer->GetDelta();

			auto input = m_inputManager.ProcessInput();

			// Process input.            
			if (std::get<0>(input) == SDL_QUIT)
			{
				isRunning = false;
			}
			else if (std::get<0>(input) == SDL_KEYUP &&
				std::get<1>(input) == SDLK_ESCAPE)
			{
				// This is just temporary for now.
				isRunning = false;
			}

			// Update game/scene/physics.


			m_renderManager.Draw();
		}
	}
}