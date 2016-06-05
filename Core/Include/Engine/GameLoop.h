#pragma once
#include "Timer.h"
#include "Render\RenderManager.h"
#include "Input\InputManager.h"

namespace BRCore
{
    class GameLoop
    {
    public:
        GameLoop(RenderManager& renderManager, InputManager& inputManger) : 
            m_renderManager(renderManager), m_inputManager(inputManger) {}
        void                Run();

    private:
        Timer*              m_timer;
        RenderManager&      m_renderManager;        
        InputManager&       m_inputManager;
    };
}