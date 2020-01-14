#pragma once

#include <SDL.h>
#include <memory>
#include <tuple>
#include <map>

namespace BRCore
{
	class InputManager
	{
	public:
		bool										StartUp();
		void										ShutDown();
		void										AddKeyboardEvent(SDL_KeyboardEvent keyboardEvent);
		bool										GetKeyDown(SDL_Keycode keycode) const;
		bool										GetKeyUp(SDL_Keycode keycode) const;		
		void										ClearEvents();
	private:		
		std::map<SDL_Keycode, SDL_KeyboardEvent>	m_KeyMap;
	};
}