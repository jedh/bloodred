#include "Engine\GameLoop.h"
#include <SDL.h>
#include <iostream>

using namespace std::chrono;

namespace BRCore
{        
    void GameLoop::Run()
    {
        bool isRunning = true;                
        m_timer = new Timer();
        float deltaTime = 0;

        SDL_Event eventHandler;

        while ( isRunning )
        {
            deltaTime = m_timer->GetDelta();

            // Process input.            
            if ( m_inputManager.ProcessInput() == SDL_QUIT )
            {
                isRunning = false;
            }

            // Update game/scene/physics.

            m_renderManager.Draw();
        }
    }
}