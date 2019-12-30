#include "Input\InputManager.h"
#include <iostream>
#include <SDL.h>

namespace BRCore
{
    InputManager InputManager::m_instance;

    bool InputManager::StartUp()
    {
        return true;
    }

    void InputManager::ShutDown()
    {

    }
    
    std::tuple<int, SDL_Keycode> InputManager::ProcessInput()
    {
        int inputCode = SDL_PollEvent(&m_inputEvent);
        
        if ( inputCode != 0 )
        {
            // Do any special handling here.
            if (m_inputEvent.type == SDL_KEYUP && m_inputEvent.key.keysym.sym == SDLK_ESCAPE)
            {
                printf("quit\n");
            }
        }

        return std::make_tuple(m_inputEvent.type, m_inputEvent.key.keysym.sym);
    }
}