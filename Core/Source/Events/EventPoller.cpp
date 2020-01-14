#include "Events/EventPoller.h"
#include <iostream>

void BRCore::EventPoller::ProcessEvents(InputManager& inputManager)
{		
	m_lastEvent = &SDL_Event();
	SDL_Event ev;	
	while (SDL_PollEvent(&ev) != 0)
	{		
		m_lastEvent = &ev;
		switch (m_lastEvent->type)
		{
		case SDL_KEYDOWN:
		case SDL_KEYUP:				
			//std::cout << "input" << std::endl;
			inputManager.AddKeyboardEvent(ev.key);
			break;
		case SDL_QUIT:
			return;
		default:
			break;
		}
	}
}
