#pragma once
#include <list>
#include <Scenes/Scene.h>

namespace BRCore
{
	class SceneManager
	{
	public:
		static SceneManager&		Instance() { return m_instance; }
		void						AddScene(const Scene& scene);
		void						RemoveScene(const Scene& scene);
		void						ClearScenes();
		std::list<Scene&>			GetScenes() const;
	private:
		SceneManager() : m_Scenes{} {};

		static SceneManager			m_instance;
		std::list<Scene>			m_Scenes;
	};
}