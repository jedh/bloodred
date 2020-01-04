#include <Scenes/SceneManager.h>

namespace BRCore
{	
	SceneManager::~SceneManager() {}

	void SceneManager::AddScene(Scene& scene)
	{	
		scene.Init();
		m_scenes.push_back(&scene);		
	}

	void SceneManager::RemoveScene(const Scene& scene)
	{
	}

	void SceneManager::ClearScenes()
	{
		m_scenes.clear();
	}

	const std::list<Scene*>& SceneManager::GetScenes()
	{
		return m_scenes;
	}
}