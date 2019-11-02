#ifndef GAME_HPP_INCLUDED
#define GAME_HPP_INCLUDED

#include <memory>
#include <SFML/Window.hpp>

#include "Event.hpp"
#include "Listener.hpp"

class Game
{
	public:
		Game(void);
		bool loop(void);
		void close(void);
		void addListener(Listener);

	private:
		sf::Window m_window;
		Event m_frameEvent;
		
		//some sort of config file
		static const int m_frameDuration;	// in milliseconds
};

#endif
