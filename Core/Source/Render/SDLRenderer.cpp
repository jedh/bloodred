#include "Display\DisplayManager.h"
#include "Render\SDLRenderer.h"
#include <SDL.h>
#include <SDL_image.h>
#include <string>

namespace BRCore
{    
    bool SDLRenderer::Init()
    {
        m_renderer = SDL_CreateRenderer( &m_window.GetWindow(), -1, SDL_RENDERER_ACCELERATED );
        if ( m_renderer == NULL )
        {
            printf("SDL_CreateRenderer could not initialize! SDL_image Error: %s\n", SDL_GetError());
            return false;
        }                

        int imgFlags = IMG_INIT_PNG;
        if (!(IMG_Init(imgFlags) & imgFlags))
        {                        
            printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
            return false;
        }

        // Comment this out if we don't want resolution scaling.
        SDL_RenderSetLogicalSize(m_renderer, 640, 480);       

        return true;
    }

    void SDLRenderer::Destroy()
    {        
        SDL_DestroyRenderer( m_renderer );
    }

    void SDLRenderer::Draw(const std::list<std::shared_ptr<BRFillRect>> rects, const std::list<std::shared_ptr<Sprite>> sprites) const
    {        
        SDL_SetRenderDrawColor(m_renderer, 100, 149, 237, 255);
        SDL_RenderClear( m_renderer );           

        for (auto fillRect : rects)
        {
            SDL_Rect rect;
            rect.x = fillRect->x;
            rect.y = fillRect->y;
            rect.w = fillRect->w;
            rect.h = fillRect->h;

            SDL_SetRenderDrawColor(m_renderer, fillRect->color.r, fillRect->color.g, fillRect->color.b, fillRect->color.a);
            SDL_RenderFillRect(m_renderer, &rect);
        }

        for (auto sprite : sprites)
        {
            SDL_Rect rect;
            rect.x = sprite->rect.x;
            rect.y = sprite->rect.y;
            rect.w = sprite->rect.w;
            rect.h = sprite->rect.h;

            SDL_RenderCopy(m_renderer, sprite->texture, NULL, &rect);
        }

        SDL_RenderPresent(m_renderer);
    }

    SDL_Texture* SDLRenderer::GetTexture(std::string path) const
    {
        SDL_Texture* loadedTexture = NULL;                
        SDL_Surface* loadedSurface = IMG_Load(path.c_str());        
        if (loadedSurface == NULL)
        {
            printf("Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError());
        }
        else
        {           
            loadedTexture = SDL_CreateTextureFromSurface(m_renderer, loadedSurface);
            SDL_FreeSurface(loadedSurface);            
        }

        return loadedTexture;
    }
}