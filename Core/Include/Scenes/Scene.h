#pragma once

#include "stdafx.h"

namespace BRCore
{
	class Scene
	{
	public:
		Scene(std::string name) : m_name(name) {};
		~Scene();

		virtual void			Init();
		virtual void			Update(float deltaTime);
		virtual void			Shutdown();
		const std::string&		GetName() { return m_name; }
	private:
		std::string				m_name;
	};
}