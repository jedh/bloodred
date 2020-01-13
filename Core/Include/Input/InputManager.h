#pragma once

#include <SDL.h>
#include <memory>
#include <tuple>

namespace BRCore
{
	class InputManager
	{
	public:
		bool								StartUp();
		void								ShutDown();

		std::tuple<int, SDL_Keycode>		ProcessInput();
		const std::tuple<int, SDL_Keycode>&	GetEvent() const{ return m_lastInputEvent; }
	private:
		std::tuple<int, SDL_Keycode>		m_lastInputEvent;
		SDL_Event							m_inputEvent;
	};
}