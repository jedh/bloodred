#include "Input\InputManager.h"
#include <iostream>
#include <SDL.h>

namespace BRCore
{
    bool InputManager::StartUp()
    {
        return true;
    }

    void InputManager::ShutDown()
    {

    }
    
    std::tuple<int, SDL_Keycode> InputManager::ProcessInput()
    {                           
        m_lastInputEvent = std::make_tuple(NULL, NULL);
        while (SDL_PollEvent(&m_inputEvent) != 0 )
        {
            if (m_inputEvent.type == SDL_KEYDOWN)
            {
                std::cout << "key down" << std::endl;
                m_lastInputEvent = std::make_tuple(m_inputEvent.type, m_inputEvent.key.keysym.sym);                                                
                return m_lastInputEvent;
            }
            else if (m_inputEvent.type == SDL_KEYUP)
            {
                std::cout << "key up" << std::endl;
                m_lastInputEvent = std::make_tuple(m_inputEvent.type, m_inputEvent.key.keysym.sym);                
                return m_lastInputEvent;
            }
            else if (m_inputEvent.type == SDL_QUIT)
            {
                std::cout << "quit" << std::endl;
                m_lastInputEvent = std::make_tuple(m_inputEvent.type, m_inputEvent.key.keysym.sym);
                return m_lastInputEvent;                
            }
        }        
                        
        return m_lastInputEvent;
    }
}