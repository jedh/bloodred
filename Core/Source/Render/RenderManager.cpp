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
        m_renderer->Draw(m_rects, m_sprites);
    }
    void RenderManager::AddFillRect(const std::shared_ptr<BRFillRect> fillRect)
    {
        m_rects.push_back(fillRect);
    }

    void RenderManager::RemoveFillRect(const std::shared_ptr<BRFillRect> fillRect)
    {
        m_rects.remove(fillRect);
    }

    void RenderManager::ClearFillRects()
    {
        m_rects.clear();
    }

    void RenderManager::AddSprite(const std::shared_ptr<Sprite> sprite)
    {
        m_sprites.push_back(sprite);
    }

    void RenderManager::RemoveSprite(const std::shared_ptr<Sprite> sprite)
    {
        m_sprites.remove(sprite);
    }

    void RenderManager::ClearSprites()
    {
        m_sprites.clear();
    }

    SDL_Texture* RenderManager::GetTexture(std::string path) const
    {
        return m_renderer->GetTexture(path);
    }
}