#include <vector>
#include <memory>
#include "Scene.hpp"

uint Scene::m_nextId = 0;
Scene::Scene() : m_id(++m_nextId), m_isVisible(true) { }
Scene::~Scene() { }

uint Scene::id() { return m_id; }

void Scene::add(std::shared_ptr<Scene> child)
{
	m_children.emplace_back(child);
	child->setParent(weak_from_this());
}

std::vector<std::weak_ptr<Scene>> Scene::getChildren()
{
	std::vector<std::weak_ptr<Scene>> copies;
	for (auto child : m_children)
	{
		copies.emplace_back(child);
	}
	return copies;
}

std::weak_ptr<Scene> Scene::getParent()
{
	return m_parent;
}

void Scene::setParent(std::weak_ptr<Scene> parent)
{
	m_parent = parent;
}
