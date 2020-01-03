#pragma once

#include "stdafx.h"

namespace BRCore
{
	class Scene
	{
	public:
		Scene();
		~Scene();

		virtual	void			Update(float deltaTime) = 0;
	private:
	};
}