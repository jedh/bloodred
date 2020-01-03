#include <Scenes/SceneManager.h>

namespace BRCore
{
	SceneManager SceneManager::m_instance;

	void SceneManager::AddScene(const Scene& scene)
	{
		m_Scenes.push_back(scene);
	}

	void SceneManager::RemoveScene(const Scene& scene)
	{
	}

	void SceneManager::ClearScenes()
	{
		m_Scenes.clear();
	}

	std::list<Scene&> SceneManager::GetScenes() const
	{
		return std::list<Scene&>();
	}

}