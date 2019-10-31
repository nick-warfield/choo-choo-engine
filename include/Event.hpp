#ifndef EVENT_INCLUDED_HPP
#define EVENT_INCLUDED_HPP

#include <vector>
#include <memory>

#include "Listener.hpp"

class Event
{
	public:
		void operator()(void);
		Event &operator+=(const Listener&);
		Event &operator-=(const Listener&);

		void AddListener(const Listener&);
		void RemoveListener(const Listener&);

	private:
		std::vector<std::unique_ptr<Listener>> m_listeners;
};

#endif
