#pragma once
#include "Timer.h"
#include "Render\RenderManager.h"
#include "Input\InputManager.h"
#include "Scenes\SceneManager.h"
#include "Camera\Camera.h"
#include "Events/EventPoller.h"

namespace BRCore
{	
	class GameLoop
	{
	public:
		const float MS_PER_UPDATE = 16;		

		GameLoop(
			RenderManager& renderManager,
			InputManager& inputManger,
			SceneManager& sceneManager,
			Camera& camera) :
			m_renderManager(renderManager),
			m_inputManager(inputManger),
			m_SceneManager(sceneManager),
			m_camera(camera),
			m_lag(0),
			m_timeStep(MS_PER_UPDATE * 0.001) {}

		void Run();

	private:
		std::unique_ptr<Timer> m_timer;
		std::unique_ptr<EventPoller> m_eventPoller;
		RenderManager& m_renderManager;
		InputManager& m_inputManager;
		SceneManager& m_SceneManager;
		Camera& m_camera;
		float m_lag;
		float m_timeStep;		
	};
}