#include "TestScene.h"
#include <Eigen/Dense>

namespace BRGame
{	
	Eigen::Vector2f direction = Eigen::Vector2f(1, 1);

	void TestScene::Init()
	{
		std::cout << "init test scene" << "\n";
		auto color = BRCore::BRColor(0, 255, 80, 255);
		m_position = BRCore::Vector2(0, 0);
		m_rect = std::make_shared<BRCore::BRFillRect>(m_position.x, m_position.y, 100, 100, color);
		m_rendering->AddFillRect(m_rect);

		auto texture = m_rendering->GetTexture("../Resources/ball.png");
		if (texture != NULL)
		{			
			m_sprite = std::make_shared<BRCore::Sprite>(BRCore::BRRect(100, 100, 100, 100), texture);
			m_rendering->AddSprite(m_sprite);
		}
	}

	void TestScene::Update(float deltaTime)
	{						
		m_position.x += 50 * deltaTime;
		m_position.y += 100 * deltaTime;

		auto inputEvent = m_input->GetEvent();
		/*if (std::get<0>(inputEvent) == SDL_KEYDOWN)
		{
			std::cout << "key down" << std::endl;
		}*/

		if (std::get<0>(inputEvent) == SDL_KEYDOWN)
		{
			std::cout << "KEY DOWN" << std::endl;
			BRCore::Vector2 camDirection = BRCore::Vector2(0, 0);
			auto key = std::get<1>(inputEvent);
			if (key == SDLK_UP)
			{
				camDirection.y = -1;
			}
			if (key == SDLK_DOWN)
			{
				camDirection.y = 1;
			}
			if (key == SDLK_LEFT)
			{
				camDirection.x = -1;
			}
			if (key == SDLK_RIGHT)
			{
				camDirection.x = 1;
			}

			m_camera->cameraRect.x += 100 * camDirection.x * deltaTime;
			m_camera->cameraRect.y += 100 * camDirection.y * deltaTime;
		}

		//m_camera->cameraRect.x += 30 * deltaTime;
		//m_camera->cameraRect.y += 30 * deltaTime;
		
		m_sprite->rect.x += direction.x() * 100 * deltaTime;
		m_sprite->rect.y += direction.y() * 80 * deltaTime;		
		
		auto cameraRect = m_camera->cameraRect;
		//auto worldBounds = m_rendering->GetLogicalDisplaySize();

		if ((m_sprite->rect.x + m_sprite->rect.w) > (cameraRect.x + cameraRect.w))
		{
			m_sprite->rect.x = (cameraRect.x + cameraRect.w) - m_sprite->rect.w;
			direction.x() = -1;
		}

		if (m_sprite->rect.x < cameraRect.x)
		{
			m_sprite->rect.x = cameraRect.x;
			direction.x() = 1;
		}

		if ((m_sprite->rect.y + m_sprite->rect.h) > (cameraRect.y + cameraRect.h))
		{
			m_sprite->rect.y = (cameraRect.y + cameraRect.h) - m_sprite->rect.h;
			direction.y() = -1;
		}

		if (m_sprite->rect.y < cameraRect.y)
		{
			m_sprite->rect.y = cameraRect.y;
			direction.y() = 1;
		}				
	}

	void TestScene::Shutdown()
	{
		std::cout << "shutdown test scene" << "\n";
	}
}
