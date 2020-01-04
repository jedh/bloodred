#include <Scenes/Scene.h>

namespace BRCore
{
	Scene::~Scene() {}

	void Scene::Update(float deltaTime) { std::cout << "update base scene" << "\n"; };

	void Scene::Init() { std::cout << "init base scene" << "\n"; };

	void Scene::Shutdown() {};
}