#include "Scene.hpp"

unsigned long Scene::m_nextId = 0;
Scene::Scene() : m_id(m_nextId++), m_isVisible(true) { }
Scene::~Scene() { }

unsigned long Scene::id() { return m_id; }
bool Scene::isVisible() { return m_isVisible; }
void Scene::setVisible(bool isVisible) { m_isVisible = isVisible; }

void Scene::add(std::shared_ptr<Scene> child)
{
	m_children.insert(child);
	child->setParent(weak_from_this());
	child->preload();
	child->load();
}

void Scene::remove(std::shared_ptr<Scene> child)
{
	if (m_children.find(child) != m_children.end())
	{
		child->unload();
		m_children.erase(child);
	}
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

std::weak_ptr<Scene> Scene::getParent() { return m_parent; }
void Scene::setParent(std::weak_ptr<Scene> parent) { m_parent = parent; }
