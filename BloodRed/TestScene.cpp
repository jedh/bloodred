#include "TestScene.h"

namespace BRGame
{
	void TestScene::Init()
	{
		std::cout << "init test scene" << "\n";
		auto color = BRColor(0, 255, 80, 255);
		m_position = BRCore::Vector2(0, 0);
		m_rect = std::make_shared<BRFillRect>(m_position.x, m_position.y, 100, 100, color);
		m_rendering->AddFillRect(m_rect);

		auto texture = m_rendering->GetTexture("../Resources/ball.png");
		if (texture != NULL)
		{			
			m_sprite = std::make_shared<Sprite>(BRRect(100, 100, 100, 100), texture);
			m_rendering->AddSprite(m_sprite);
		}
	}

	void TestScene::Update(float deltaTime)
	{
		m_position.x += 0.1 * deltaTime;
		m_position.y += 0.1 * deltaTime;
		m_rect->x = m_position.x;
		m_rect->y = m_position.y;

		m_sprite->rect.x = m_position.x * 0.5;
		m_sprite->rect.y = m_position.y * 0.5;
	}

	void TestScene::Shutdown()
	{
		std::cout << "shutdown test scene" << "\n";
	}
}
