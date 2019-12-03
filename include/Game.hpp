#ifndef GAME_HPP_INCLUDED
#define GAME_HPP_INCLUDED

#include <chrono>
#include <vector>
#include <memory>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include "GameObject.hpp"
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
		void addObject(std::unique_ptr<GameObject>);

	private:
		sf::RenderWindow m_window;
		Event m_frameEvent;
		std::vector<std::unique_ptr<GameObject>> m_objects;
		std::chrono::time_point<std::chrono::system_clock> m_oldTime;
		
		//some sort of config file
		static const int m_frameDuration;	// in milliseconds
		static const int m_width, m_height;
};

#endif
