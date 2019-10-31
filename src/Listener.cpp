#include <iostream>
#include "Listener.hpp"

int Listener::m_counter = 0;

Listener::Listener() : m_function(nullptr), m_id(0) { }
Listener::Listener(const std::function<void()>& Function) :
	m_function(Function), m_id(++m_counter) { }

void Listener::operator()(void)
{
	if (m_function != nullptr && m_id != 0) { m_function(); }
	else
	{
		std::cerr << "Cannot call function; listener not initialized\n";
	}
}
void Listener::operator=(const Listener& Function)
{
	if (m_function == nullptr)
	{
		m_function = Function;
		m_id = ++m_counter;
	}
	else
	{
		std::cerr << "Listener " << m_id << " is already initialized\n";
	}
}
bool Listener::operator==(const Listener& other) { return m_id == other.m_id; }
bool Listener::operator!=(nullptr_t) { return m_function == nullptr; }
