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
        std::shared_ptr<DisplayManager>     m_displayManager;
        std::shared_ptr<RenderManager>      m_renderManger;
        std::shared_ptr<InputManager>       m_inputManager;
        GameLoop*           m_gameLoop;
    };
}