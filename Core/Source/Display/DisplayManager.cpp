#include "Display\DisplayManager.h"

namespace BRCore
{
    DisplayManager DisplayManager::m_instance;

    bool DisplayManager::StartUp(int screenWidth, int screenHeight)
    {
        if ( SDL_Init( SDL_INIT_VIDEO < 0 ) )
        {
            return false;
        }
        else
        {
            m_window = new Window();
            m_window->CreateWindow( "My Game", screenWidth, screenHeight);
            if ( m_window == NULL )
            {
                return false;
            }
            else
            {
                return true;
            }
        }
    }

    void DisplayManager::ShutDown()
    {
        m_window->CloseWindow();
    }
}