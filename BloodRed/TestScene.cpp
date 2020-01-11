#include "TestScene.h"
#include <Eigen/Dense>

namespace BRGame
{	
	Eigen::Vector2f direction = Eigen::Vector2f(1, 1);

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
		m_position.x += 50 * deltaTime;
		m_position.y += 100 * deltaTime;
		m_rect->x = m_position.x;
		m_rect->y = m_position.y;

		//m_sprite->rect.x = m_position.x;
		m_sprite->rect.x += direction.x() * 100 * deltaTime;
		m_sprite->rect.y += direction.y() * 80 * deltaTime;			

		//Get bounds:
		if ((m_sprite->rect.x + m_sprite->rect.w) > m_rendering->GetLogicalDisplaySize().x)
		{
			m_sprite->rect.x = m_rendering->GetLogicalDisplaySize().x - m_sprite->rect.w;
			direction.x() = -1;
		}

		if (m_sprite->rect.x < 0)
		{
			m_sprite->rect.x = 0;
			direction.x() = 1;
		}

		if ((m_sprite->rect.y + m_sprite->rect.h) > m_rendering->GetLogicalDisplaySize().y)
		{
			m_sprite->rect.y = m_rendering->GetLogicalDisplaySize().y - m_sprite->rect.h;
			direction.y() = -1;
		}

		if (m_sprite->rect.y < 0)
		{
			m_sprite->rect.y = 0;
			direction.y() = 1;
		}		
	}

	void TestScene::Shutdown()
	{
		std::cout << "shutdown test scene" << "\n";
	}
}
