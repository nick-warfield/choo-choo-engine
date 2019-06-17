#include "Log.hpp"
#include "Scene.hpp"

unsigned long Scene::m_nextId = 0;
Scene::Scene() : m_id(m_nextId++), m_isVisible(true) { }
Scene::~Scene() { Log::eh()->info("Scene Destroyed"); }

unsigned long Scene::id() { return m_id; }
bool Scene::isVisible() { return m_isVisible; }
void Scene::setVisible(bool isVisible) { m_isVisible = isVisible; }

void Scene::init()
{
	Log::eh()->info("Scene with id: {0} began load", id());
	preload();
	for (auto child : m_children) { child->init(); }
	postload();
	Log::eh()->info("Scene with id: {0} finish load", id());
}
void Scene::start()
{
	onStart();
	Log::eh()->info("Scene with id: {0} started", id());
}
void Scene::end()
{
	for (auto child : m_children) { child->end(); }
	onEnd();
	Log::eh()->info("Scene with id: {0} ended", id());
}
void Scene::preload() { }
void Scene::postload() { }
void Scene::onStart() { }
void Scene::onUpdate() { }
void Scene::onEnd() { }

void Scene::render() { }

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
