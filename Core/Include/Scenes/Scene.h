#pragma once

#include "stdafx.h"
#include <Display/DisplayManager.h>
#include <Input/InputManager.h>
#include <Render/RenderManager.h>

namespace BRCore
{
	class Scene
	{
	public:
		Scene(
			std::string name, 
			const std::shared_ptr<DisplayManager> display, 
			const std::shared_ptr<InputManager> input, 
			const std::shared_ptr<RenderManager> rendering) : 
			m_name(name), m_display(display), m_input(input), m_rendering(rendering) {};
		~Scene();

		virtual void Init();
		virtual void Update(float deltaTime);
		virtual void Shutdown();
		const std::string& GetName() { return m_name; }
	protected:
		const std::shared_ptr<DisplayManager> m_display;
		const std::shared_ptr<InputManager> m_input;
		const std::shared_ptr<RenderManager> m_rendering;
	private:
		std::string	m_name;
	};
}