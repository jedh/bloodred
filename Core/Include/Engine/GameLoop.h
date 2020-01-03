#pragma once
#include "Timer.h"
#include "Render\RenderManager.h"
#include "Input\InputManager.h"
#include "Scenes\SceneManager.h"

namespace BRCore
{
    class GameLoop
    {
    public:
        GameLoop(
            RenderManager& renderManager, 
            InputManager& inputManger,
            SceneManager& sceneManager): 
            m_renderManager(renderManager), 
            m_inputManager(inputManger),
            m_SceneManager(sceneManager) {}
        void                Run();

    private:
        std::unique_ptr<Timer>          m_timer;
        RenderManager&                  m_renderManager;        
        InputManager&                   m_inputManager;
        SceneManager&                   m_SceneManager;
    };
}