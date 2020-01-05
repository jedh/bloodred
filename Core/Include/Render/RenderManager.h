#pragma once 

#include "Render\IRenderer.h"
#include "Display/\DisplayManager.h"

namespace BRCore
{
    class RenderManager
    {
    public:                
        bool                    StartUp(DisplayManager& displayManager);
        void                    ShutDown();

        void                    Draw(); // Test function.
    private:
        IRenderer*              m_renderer;
    };
}