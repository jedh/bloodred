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
        if (keyboardEvent.repeat == 0)
        {
            m_KeyMap[keyboardEvent.keysym.sym] = keyboardEvent;
            m_HeldKeyMap[keyboardEvent.keysym.sym] = keyboardEvent.state;

            std::cout << "key press " << keyboardEvent.state << std::endl;
        }
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

    bool InputManager::GetKeyHeld(SDL_Keycode keycode) const
    {
        auto result = m_HeldKeyMap.find(keycode);
        if (result != m_HeldKeyMap.end() && result->second == SDL_PRESSED)
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