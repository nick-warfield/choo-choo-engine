#ifndef GAME_HPP_INCLUDED
#define GAME_HPP_INCLUDED

#include <vector>
#include <memory>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include "Event.hpp"
#include "Listener.hpp"

class Game
{
	public:
		Game(void);
		bool loop(void);
		void close(void);
		void addListener(Listener);
		void addListener(std::vector<Listener>);
		sf::RenderWindow* window(void);

	private:
		sf::RenderWindow m_window;
		Event m_frameEvent;
		
		//some sort of config file
		static const int m_frameDuration;	// in milliseconds
		static const int m_width, m_height;
};

#endif
