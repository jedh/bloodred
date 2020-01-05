#pragma once

#include <SDL.h>
#include <memory>

namespace BRCore
{
    class InputManager
    {
    public:        
        bool                            StartUp();
        void                            ShutDown();

        std::tuple<int, SDL_Keycode>    ProcessInput();
    private:
        SDL_Event                       m_inputEvent;
    };
}