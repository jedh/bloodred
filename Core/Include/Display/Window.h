#pragma once

#include <SDL.h>

namespace BRCore
{
	class Window
	{
	public:
		Window();
		~Window();

		void CreateWindow(const char* name, int width, int height);
		void CloseWindow();

		SDL_Window& GetWindow() const { return *m_window; }
		int GetWidth() const { return m_width; };
		int GetHeight() const { return m_height; };

	private:
		SDL_Window* m_window;
		const char* m_name;
		int m_width;
		int m_height;
	};
}