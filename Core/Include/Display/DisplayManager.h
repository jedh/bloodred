#pragma once

#include "Display\Window.h"
#include <memory>

namespace BRCore
{
    class DisplayManager
    {
    public:
        static DisplayManager&          Instance() { return m_instance; }

        bool                            StartUp(int screenWidth, int screenHeight);
        void                            ShutDown();

        Window&                         GetWindow() { return *m_window; }
    private:
        static DisplayManager           m_instance;      
        Window*                         m_window;
    };
}