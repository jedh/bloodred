#pragma once 

#include "Render\IRenderer.h"

namespace BRCore
{
    class RenderManager
    {
    public:                
        static RenderManager&   Instance() { return m_instance; }

        bool                    StartUp();
        void                    ShutDown();

        void                    Draw(); // Test function.
    private:
        static RenderManager    m_instance;
        IRenderer*              m_renderer;
    };
}