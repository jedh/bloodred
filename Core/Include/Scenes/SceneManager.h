#pragma once
#include <list>
#include <memory>
#include <Scenes/Scene.h>

namespace BRCore
{
	class SceneManager
	{
	public:	
		SceneManager() : m_scenes{} {};
		~SceneManager();

		void										AddScene(const std::shared_ptr<Scene> scene);
		void										RemoveScene(const Scene& scene);
		void										ClearScenes();
		const std::list<std::shared_ptr<Scene>>		GetScenes() const;		
	private:				
		std::list<std::shared_ptr<Scene>>			m_scenes;
	};
}