#include <Scenes/SceneManager.h>

namespace BRCore
{	
	SceneManager::~SceneManager() {}

	void SceneManager::AddScene(const std::shared_ptr<Scene> scene)
	{	
		scene->Init();
		m_scenes.push_back(scene);		
	}

	void SceneManager::RemoveScene(const Scene& scene)
	{
	}

	void SceneManager::ClearScenes()
	{
		m_scenes.clear();
	}

	const std::list<std::shared_ptr<Scene>> SceneManager::GetScenes() const
	{
		return m_scenes;
	}
}