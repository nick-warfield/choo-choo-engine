#include "GameObject.hpp"

GameObject::GameObject(std::string Name,
		const std::function<void()>& Func)
	: m_name(Name), m_listeners()
{
	m_listeners.push_back(Listener(std::bind(&GameObject::onTurn, this)));
	m_listeners.push_back(Listener(Func));
}
GameObject::GameObject(std::string Name,
		const std::vector<std::function<void()>>& Listeners)
	: m_name(Name), m_listeners()
{
	m_listeners.push_back(Listener(std::bind(&GameObject::onTurn, this)));
	for (auto l : Listeners) { m_listeners.push_back(Listener(l)); }
}

std::vector<Listener> GameObject::GetListeners(void)
{
	return m_listeners;
}
std::string GameObject::GetName(void) { return m_name; }

void GameObject::onTurn(void) { }
