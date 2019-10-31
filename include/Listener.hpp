#ifndef LISTENER_HPP_INCLUDED
#define LISTENER_HPP_INCLUDED

#include <functional>

class Listener
{
	public:
		Listener(void);
		Listener(const std::function<void()>&);

		void operator()(void);
		void operator=(const Listener&);
		bool operator==(const Listener&);
		bool operator!=(nullptr_t);

	private:
		std::function<void()> m_function;
		int m_id;
		static int m_counter;
};

#endif
