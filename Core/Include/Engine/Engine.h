#pragma once

#include "Display\DisplayManager.h"
#include "Render\RenderManager.h"
#include "Input\InputManager.h"
#include "GameLoop.h"

namespace BRCore
{
    class Engine
    {
    public:
        Engine();
        ~Engine();

        int                 Start();
        void                Stop();

        DisplayManager&     Display();
        RenderManager&      Rendering();
        InputManager&       Input();
        void                Run();

    private:
        DisplayManager*     m_displayManager;
        RenderManager*      m_renderManger;
        InputManager*       m_inputManager;
        GameLoop*           m_gameLoop;
    };
}