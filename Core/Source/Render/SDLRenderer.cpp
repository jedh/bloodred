#include "Display\DisplayManager.h"
#include "Render\SDLRenderer.h"
#include <SDL.h>

namespace BRCore
{
    bool SDLRenderer::Init()
    {
        m_renderer = SDL_CreateRenderer( &m_window.GetWindow(), -1, SDL_RENDERER_ACCELERATED );
        if ( m_renderer == NULL )
        {
            return false;
        }

        // Comment this out if we don't want resolution scaling.
        SDL_RenderSetLogicalSize( m_renderer, 640, 480 );        

        return true;
    }

    void SDLRenderer::Destroy()
    {
        SDL_DestroyRenderer( m_renderer );
    }

    void SDLRenderer::Draw(const std::list<std::shared_ptr<BRFillRect>> rects) const
    {
        SDL_SetRenderDrawColor( m_renderer, 100, 149, 237, 255 );
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

        //// Just draw some shapes and what not.
        //SDL_Rect rect;
        //rect.x = 100;
        //rect.y = 100;
        //rect.w = 120;
        //rect.h = 120;

        //SDL_SetRenderDrawColor( m_renderer, 0, 255, 80, 255 );

        //SDL_RenderFillRect ( m_renderer, &rect );

        //SDL_Rect rect2;
        //rect2.x = 150;
        //rect2.y = 150;
        //rect2.w = 120;
        //rect2.h = 120;

        //SDL_SetRenderDrawColor(m_renderer, 255, 255, 80, 255);

        //SDL_RenderFillRect(m_renderer, &rect2);

        SDL_RenderPresent(m_renderer);
    }
}