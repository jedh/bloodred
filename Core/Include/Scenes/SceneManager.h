#pragma once
#include <list>
#include <Scenes/Scene.h>

namespace BRCore
{
	class SceneManager
	{
	public:	
		SceneManager() : m_scenes{} {};
		~SceneManager();

		void						AddScene(Scene& scene);
		void						RemoveScene(const Scene& scene);
		void						ClearScenes();
		const std::list<Scene*>&	GetScenes();		
	private:				
		std::list<Scene*>			m_scenes;
	};
}