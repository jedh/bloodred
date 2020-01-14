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
    
    void InputManager::AddKeyboardEvent(SDL_KeyboardEvent keyboardEvent)
    {
        m_KeyMap[keyboardEvent.keysym.sym] = keyboardEvent;
    }

    bool InputManager::GetKeyDown(SDL_Keycode keycode) const
    {       
        auto result = m_KeyMap.find(keycode);        
        if (result != m_KeyMap.end() && result->second.state == SDL_PRESSED)
        {
            return true;
        }

        return false;
    }

    bool InputManager::GetKeyUp(SDL_Keycode keycode) const
    {
        auto result = m_KeyMap.find(keycode);
        if (result != m_KeyMap.end() && result->second.state == SDL_RELEASED)
        {            
            return true;
        }

        return false;
    }       

    void InputManager::ClearEvents()
    {
        m_KeyMap.clear();
    }
}