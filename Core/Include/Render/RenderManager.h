#pragma once 

#include "Render\IRenderer.h"
#include "Display/\DisplayManager.h"

namespace BRCore
{
    class RenderManager
    {
    public:                
        static RenderManager&   Instance() { return m_instance; }

        bool                    StartUp(DisplayManager& displayManager);
        void                    ShutDown();

        void                    Draw(); // Test function.
    private:
        static RenderManager    m_instance;
        IRenderer*              m_renderer;
    };
}