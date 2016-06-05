#include "Display\DisplayManager.h"

namespace BRCore
{
    DisplayManager DisplayManager::m_instance;

    bool DisplayManager::StartUp()
    {
        if ( SDL_Init( SDL_INIT_VIDEO < 0 ) )
        {
            return false;
        }
        else
        {
            m_window = new Window();
            m_window->CreateWindow( "My Game", 640, 480 );
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