#pragma once

#include <SDL.h>
#include <memory>

namespace BRCore
{
    class InputManager
    {
    public:        
        static InputManager&            Instance() { return m_instance; }

        bool                            StartUp();
        void                            ShutDown();

        std::tuple<int, SDL_Keycode>    ProcessInput();
    private:
        static InputManager             m_instance;
        SDL_Event                       m_inputEvent;
    };
}