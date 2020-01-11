#pragma once

#include "Display\Window.h"
#include <memory>

namespace BRCore
{
    class DisplayManager
    {
    public:
        bool                            StartUp(int screenWidth, int screenHeight);
        void                            ShutDown();

        Window&                         GetWindow() { return *m_window; }        
    private:      
        Window*                         m_window;        
    };
}