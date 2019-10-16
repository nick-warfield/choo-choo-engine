#ifndef GAME_HPP_INCLUDED
#define GAME_HPP_INCLUDED

#include <memory>
#include <SFML/Window.hpp>

class Game
{
	public:
		Game(void);
		bool loop(void);
		void close(void);

	private:
		sf::Window m_window;
		
		//some sort of config file
		static const int m_frameDuration;	// in milliseconds
};

#endif
