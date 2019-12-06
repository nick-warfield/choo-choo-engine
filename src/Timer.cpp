#include "Timer.hpp"

Timer::Timer(const Timer& other) :
	m_duration(other.m_duration),
	m_time(other.m_time),
	m_isPlaying(other.m_isPlaying),
	m_func(other.m_func) { }

Timer::Timer(float duration, std::function<void()> function) :
	m_duration(duration),
	m_time(duration),
	m_isPlaying(true),
	m_func(function) { }

void Timer::update(const float& delta)
{
	if (isPlaying())
	{
		m_time -= delta;
		if (timeout())
		{
			m_func();
			restart();
		}
	}
}

void Timer::draw(sf::RenderTarget&, sf::RenderStates) const { }

void Timer::start(void) { m_isPlaying = true; }
void Timer::pause(void) { m_isPlaying = false; }
void Timer::stop(void) { restart(); m_isPlaying = false; }
void Timer::restart(void) { m_time = m_duration; }
bool Timer::isPlaying(void) const { return m_isPlaying; }
bool Timer::timeout(void) const
{
	return m_time <= 0 && m_isPlaying;
}
