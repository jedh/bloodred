#include "Render\RenderManager.h"
#include "Render\SDLRenderer.h"
#include "Display\DisplayManager.h"
#include <stdio.h>

namespace BRCore
{
    RenderManager RenderManager::m_instance;

    bool RenderManager::StartUp()
    {
        m_renderer = new SDLRenderer( BRCore::DisplayManager::Instance().GetWindow());
        if ( m_renderer->Init() )
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