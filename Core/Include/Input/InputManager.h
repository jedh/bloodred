#pragma once

#include <SDL.h>

namespace BRCore
{
    class InputManager
    {
    public:        
        static InputManager&        Instance() { return m_instance; }

        bool                        StartUp();
        void                        ShutDown();

        int                         ProcessInput();
    private:
        static InputManager         m_instance;
        SDL_Event                   m_inputEvent;
    };
}