#pragma once
#include "Input/InputManager.h"
#include <SDL.h>

namespace BRCore
{
	class EventPoller
	{
	public:
		void ProcessEvents(InputManager& inputManager);
		const SDL_Event& GetLastEvent() const { return *m_lastEvent; }
	private:
		SDL_Event* m_lastEvent;
	};
}