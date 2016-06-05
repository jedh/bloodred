#include "Display\Window.h"

namespace BRCore
{
    Window::Window()
    {
        m_window = nullptr;          
    }

    Window::~Window() 
    {

    }

    void Window::CreateWindow( const char* name, int width, int height )
    {
        m_name = name;
        m_width = width;
        m_height = height;
        m_window = SDL_CreateWindow( name, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_SHOWN);
        SDL_UpdateWindowSurface( m_window );
    }

    void Window::CloseWindow()
    {
        SDL_DestroyWindow( m_window );
        SDL_Quit();
    }
}