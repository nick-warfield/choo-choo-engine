#ifndef TIMER_HPP_INCLUDED
#define TIMER_HPP_INCLUDED

#include <functional>
#include "GameObject.hpp"

class Timer : public GameObject
{
	public:
		Timer(const Timer&);
		Timer(float, std::function<void()> = std::function<void()>());
		void update(const float&);
		void draw(sf::RenderTarget&, sf::RenderStates) const;

		void start(void);
		void stop(void);
		void pause(void);
		void restart(void);
		bool isPlaying(void) const;
		bool timeout(void) const;

	private:
		const float m_duration;
		float m_time;
		bool m_isPlaying;
		const std::function<void()> m_func;
};

#endif
