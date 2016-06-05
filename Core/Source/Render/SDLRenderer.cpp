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

        SDL_RenderSetLogicalSize( m_renderer, 640, 480 );        

        return true;
    }

    void SDLRenderer::Destroy()
    {
        SDL_DestroyRenderer( m_renderer );
    }

    void SDLRenderer::Draw() const
    {
        SDL_SetRenderDrawColor( m_renderer, 255, 255, 0, 255 );
        SDL_RenderClear( m_renderer );        

        // Just draw some shapes and what not.
        SDL_Rect rect;
        rect.x = 100;
        rect.y = 100;
        rect.w = 120;
        rect.h = 120;

        SDL_SetRenderDrawColor( m_renderer, 0, 255, 80, 255 );

        SDL_RenderFillRect ( m_renderer, &rect );

        SDL_RenderPresent( m_renderer );
    }
}