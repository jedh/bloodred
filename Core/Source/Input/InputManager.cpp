#include "Input\InputManager.h"
#include <iostream>

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
    
    int InputManager::ProcessInput()
    {
        int inputCode = SDL_PollEvent(&m_inputEvent);
        if ( inputCode != 0 )
        {
            // Do any special handling here.
        }

        return m_inputEvent.type;
    }
}