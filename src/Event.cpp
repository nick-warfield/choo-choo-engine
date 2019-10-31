#include "Event.hpp"

void Event::operator()(void)
{
	for (auto& listener : m_listeners) { (*listener)(); }
}
Event &Event::operator+=(const Listener& List)
{
	AddListener(List);
	return *this;
}
Event &Event::operator-=(const Listener& List)
{
	RemoveListener(List);
	return *this;
}

void Event::AddListener(const Listener& List)
{
	m_listeners.push_back(std::make_unique<Listener>(List));
}
void Event::RemoveListener(const Listener& List)
{
	for (auto itt = m_listeners.begin(); itt != m_listeners.end(); ++itt)
	{
		if (**itt == List) { m_listeners.erase(itt); }
	}
}
