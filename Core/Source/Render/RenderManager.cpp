#include "Render\RenderManager.h"
#include "Render\SDLRenderer.h"
#include "Display\DisplayManager.h"
#include <stdio.h>

namespace BRCore
{
    bool RenderManager::StartUp(DisplayManager& displayManager)
    {
        m_renderer = new SDLRenderer(displayManager.GetWindow());
        if (m_renderer->Init())
        {
            return true;
        }
        else
        {
            false;
        }
    }

    void RenderManager::ShutDown()
    {
        m_renderer->Destroy();
    }

    void RenderManager::Draw()
    {
        m_renderer->Draw();
    }
}