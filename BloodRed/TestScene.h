#pragma once

#include <BRCore.h>

namespace BRGame
{
	class TestScene : public BRCore::Scene
	{
	public:
		TestScene(std::string name) : Scene(name) {};
		void Init() override;
		void Update(float deltaTime) override;
		void Shutdown() override;
	};
}