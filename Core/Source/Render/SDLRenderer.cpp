#include "Display\DisplayManager.h"
#include "Render\SDLRenderer.h"
#include <SDL.h>
#include <SDL_image.h>
#include <string>
#include <stdexcept>
#include <iostream>

namespace BRCore
{    
    bool SDLRenderer::Init()
    {
        try
        {
            m_renderer = SDL_CreateRenderer(&m_window.GetWindow(), -1, SDL_RENDERER_ACCELERATED);
            if (!m_renderer) throw std::runtime_error(SDL_GetError());

            int imgFlags = IMG_INIT_PNG;
            if (!(IMG_Init(imgFlags) & imgFlags)) throw std::runtime_error(IMG_GetError());

            // Comment this out if we don't want resolution scaling.            
            SDL_RenderSetLogicalSize(m_renderer, 640, 480);
            int x, y;
            SDL_RenderGetLogicalSize(m_renderer, &x, &y);
            m_logicalRenderSize = BRCore::Vector2(x, y);

            return true;
        }
        catch (const std::runtime_error ex)
        {
            std::cout << "Failed to initialize SDLRenderer! Internal error: " << ex.what() << std::endl;            
        }

        return false;
    }

    void SDLRenderer::Destroy()
    {        
        SDL_DestroyRenderer( m_renderer );
    }

    void SDLRenderer::Draw(const Camera& camera, const std::list<std::shared_ptr<BRFillRect>>& rects, const std::list<std::shared_ptr<Sprite>>& sprites) const
    {        
        SDL_SetRenderDrawColor(m_renderer, 100, 149, 237, 255);
        SDL_RenderClear( m_renderer );           
        auto offset = camera.GetOffset();

        for (auto fillRect : rects)
        {
            SDL_Rect rect;
            rect.x = fillRect->x - offset.x;
            rect.y = fillRect->y - offset.y;
            rect.w = fillRect->w;
            rect.h = fillRect->h;

            SDL_SetRenderDrawColor(m_renderer, fillRect->color.r, fillRect->color.g, fillRect->color.b, fillRect->color.a);
            SDL_RenderFillRect(m_renderer, &rect);
        }

        for (auto sprite : sprites)
        {
            SDL_Rect rect;
            rect.x = sprite->rect.x - offset.x;
            rect.y = sprite->rect.y - offset.y;
            rect.w = sprite->rect.w;
            rect.h = sprite->rect.h;

            SDL_RenderCopy(m_renderer, sprite->texture, NULL, &rect);
        }

        SDL_RenderPresent(m_renderer);
    }

    SDL_Texture* SDLRenderer::GetTexture(std::string path) const
    {
        try
        {            
            SDL_Surface* loadedSurface = IMG_Load(path.c_str());
            if (!loadedSurface) throw std::runtime_error(IMG_GetError());

            SDL_Texture* loadedTexture = SDL_CreateTextureFromSurface(m_renderer, loadedSurface);
            SDL_FreeSurface(loadedSurface);
            if (!loadedSurface) throw std::runtime_error(SDL_GetError());

            return loadedTexture;
        }
        catch (const std::runtime_error ex)
        {
            std::cout << "Failed to load image " << path << "! Internal error: " << ex.what() << std::endl;
        }

        return nullptr;        
    }

    BRCore::Vector2 SDLRenderer::GetLogicalRenderSize() const
    {
        return m_logicalRenderSize;
    }
}