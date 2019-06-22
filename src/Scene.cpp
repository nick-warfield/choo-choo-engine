#include "Scene.hpp"

unsigned long Scene::m_nextId = 0;
Scene::Scene() : m_id(m_nextId++) { }
Scene::~Scene() { }

unsigned long Scene::id() { return m_id; }

void Scene::init()
{
	preload();
}
void Scene::start()
{
	onStart();
}
void Scene::end()
{
	for (auto child : m_children) { child->end(); }
	onEnd();
}
void Scene::preload() { }
void Scene::postload() { }
void Scene::onStart() { }
void Scene::onUpdate() { }
void Scene::onEnd() { }

void Scene::add(std::shared_ptr<Scene> child)
{
	m_children.insert(child);
	child->setParent(weak_from_this());
	child->init();
	child->start();
}

void Scene::remove(std::shared_ptr<Scene> child)
{
	if (m_children.find(child) != m_children.end())
	{
		child->end();
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
